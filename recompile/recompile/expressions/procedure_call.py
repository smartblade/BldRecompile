import data_types
import expressions
from hex_conversion import to_hex


class ProcedureCall:
    def __init__(
        self, name=None, operator=None, arguments=None, callee_addr=None,
        is_method=False, proc_decl=None, callee=None
    ):
        if arguments is None:
            arguments = []
        self._name = name
        self._operator = operator
        self._arguments = arguments
        self._callee = callee
        self._callee_addr = callee_addr
        self._is_method = is_method
        self._proc_decl = proc_decl
        self._define_operator()

    def copy(self, **kwargs):
        default_map = dict(
            name=self._name,
            operator=self._operator,
            arguments=self._arguments,
            callee=self._callee,
            callee_addr=self._callee_addr,
            is_method=self._is_method,
            proc_decl=self._proc_decl,
        )
        for key, value in default_map.items():
            if key not in kwargs:
                kwargs[key] = value
        return ProcedureCall(**kwargs)

    def _define_operator(self):
        if self._operator is not None:
            return
        if self._proc_decl is None:
            return
        self._operator = self._proc_decl.operator

    def __repr__(self):
        return "{}({})".format(
            self.callee_code, ", ".join(map(repr, self._arguments))
        )

    @property
    def data_type(self):
        if self._name == "sqrt":
            return data_types.Double()
        if self._proc_decl is not None:
            return self._proc_decl.return_type
        raise Exception("Can't deduce data type for: {}".format(self))

    @property
    def name(self):
        if self._name is None and self._callee_addr is not None:
            if self._is_method:
                return "unknown_method_{}".format(to_hex(self._callee_addr))
            return "unknown_function_{}".format(to_hex(self._callee_addr))
        return self._name

    @property
    def callee_code(self):
        if self._callee is not None:
            return self._callee.emit_code()
        return self.name

    @property
    def arguments(self):
        return self._arguments

    @property
    def callee_address(self):
        return self._callee_addr

    @property
    def proc_decl(self):
        return self._proc_decl

    def set_declaration(self, proc_decl):
        self._proc_decl = proc_decl

    def transform_expression(self, **kwargs):
        declarations = kwargs['declarations']
        recompiled_decls = declarations.recompiled_decls
        arguments = list(
            map(
                lambda a: a.transform_expression(**kwargs),
                self._arguments,
            )
        )
        proc_decl = None
        if self._is_method:
            data_type = arguments[0].data_type
            proc_decl = recompiled_decls[self._callee_addr]
            if (
                isinstance(arguments[0], expressions.AddressOf) and
                isinstance(arguments[0].expression, expressions.Identifier) and
                isinstance(
                    arguments[0].expression.data_type, data_types.UnknownClass
                )
            ):
                arguments[0].expression.change_data_type(proc_decl.method_class)
            if not isinstance(data_type.pointee, data_types.UnknownClass):
                data_type.pointee.add_method(proc_decl)
        if (
            not self._is_method and
            self._callee_addr is None
        ):
            proc_decl = declarations.external_procedure_by_name(self._name)
            if proc_decl is not None:
                if proc_decl.method_class is not None:
                    self._is_method = True
                arguments = _make_compatible_arguments(proc_decl, arguments)
                arguments = _transform_ptrs_to_references(proc_decl, arguments)
        name = self._name
        if name == "_CIcos":
            name = "cos"
        if name == "_CIsin":
            name = "sin"
        if name == "_CIsqrt":
            name = "sqrt"
        return ProcedureCall(
            name, self._operator, arguments, self._callee_addr, self._is_method,
            proc_decl
        )

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        if self._callee is not None:
            self._callee.visit(on_expression_visited, **kwargs)
        for arg in self._arguments:
            arg.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        arguments = list(
            map(
                lambda a: a.transform(transform_callback, **kwargs),
                self._arguments,
            )
        )
        if self._callee is not None:
            callee = self._callee.transform(transform_callback, **kwargs)
        else:
            callee = None
        pc = self.copy(
            callee=callee,
            arguments=arguments,
        )
        return transform_callback(pc, **kwargs)

    def emit_code(self):
        if self._operator is not None and len(self._arguments) == 2:
            return "{} {} {}".format(
                self._arguments[0].emit_code(),
                self._operator.value,
                self._arguments[1].emit_code(),
            )
        if self._is_method:
            call = self._method_access_code(self._arguments[0])
            arguments = self._arguments[1:]
        else:
            if self._proc_decl is not None and self._proc_decl.is_static:
                call = "{}::{}".format(
                    self._proc_decl.method_class.class_name, self.name)
            else:
                call = self.callee_code
            arguments = self._arguments
        return "{}({})".format(
            call, ", ".join(map(lambda a: a.emit_code(), arguments))
        )

    def _method_access_code(self, obj):
        if self._callee is not None:
            method_code = "({})".format(self.callee_code)
        else:
            method_code = self.name
        return expressions.FieldAccess(obj, method_code).emit_code()


def _make_compatible_arguments(proc_decl, arguments):
    new_arguments = []
    i = 0
    for parameter in proc_decl.get_parameters_ids().values():
        argument = _make_compatible_argument(arguments[i], parameter.data_type)
        new_arguments.append(argument)
        i += 1
    return new_arguments


def _make_compatible_argument(argument, parameter_type):
    if not isinstance(parameter_type, data_types.Reference):
        return argument
    parameter_type = parameter_type.referent
    if not isinstance(argument.data_type, data_types.Pointer32):
        return argument
    argument_type = argument.data_type.pointee
    if isinstance(parameter_type, data_types.ClassType):
        return argument
    if not isinstance(argument_type, data_types.ClassType):
        return argument
    while isinstance(argument_type, data_types.ClassType):
        field_type, field_name = argument_type.get_field_by_offset(0)
        argument = expressions.FieldAccess(argument, field_name)
        argument_type = field_type
    return expressions.AddressOf(argument)


def _transform_ptrs_to_references(proc_decl, arguments):
    new_arguments = []
    i = 0
    for parameter in proc_decl.get_parameters_ids().values():
        if (
            isinstance(parameter.data_type, data_types.Reference) and
            isinstance(arguments[i].data_type, data_types.Pointer32)
        ):
            argument = expressions.do_dereference(arguments[i])
        else:
            argument = arguments[i]
        new_arguments.append(argument)
        i += 1
    return new_arguments
