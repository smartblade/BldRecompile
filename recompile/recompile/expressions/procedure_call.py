import data_types
import expressions


class ProcedureCall:
    def __init__(self, name, arguments, callee_addr, is_method):
        self._name = name
        self._arguments = arguments
        self._callee_addr = callee_addr
        self._is_method = is_method

    def __repr__(self):
        return "{}({})".format(
            self._name, ", ".join(map(repr, self._arguments))
        )

    @property
    def name(self):
        return self._name

    @property
    def arguments(self):
        return self._arguments

    @property
    def callee_address(self):
        return self._callee_addr

    def transform_expression(self, **kwargs):
        recompiled_decls = kwargs['recompiled_decls']
        arguments = list(
            map(
                lambda a: a.transform_expression(**kwargs),
                self._arguments,
            )
        )
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
        name = self._name
        if name == "_CIcos":
            name = "cos"
        if name == "_CIsin":
            name = "sin"
        if name == "_CIsqrt":
            name = "sqrt"
        return ProcedureCall(
            name, arguments, self._callee_addr, self._is_method
        )

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        for arg in self._arguments:
            arg.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        if self._is_method:
            call = expressions.FieldAccess(
                self._arguments[0], self._name
            ).emit_code()
            arguments = self._arguments[1:]
        else:
            call = self._name
            arguments = self._arguments
        return "{}({})".format(
            call, ", ".join(map(lambda a: a.emit_code(), arguments))
        )
