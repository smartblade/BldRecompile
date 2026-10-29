import data_types
import expressions
import expressions.writer
from hex_conversion import to_hex


class ProcedureCall:
    def __init__(
        self, name=None, operator=None, arguments=None, callee_addr=None,
        is_method=False, proc_decl=None, callee=None,
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
        if self._proc_decl is not None:
            return self._proc_decl.return_type
        if self._name == "sqrt":
            return data_types.Double()
        if self._name == "strlen":
            return data_types.UInt32()
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
    def callee_expression(self):
        return self._callee

    @property
    def callee_address(self):
        return self._callee_addr

    @property
    def is_method(self):
        return self._is_method

    @property
    def proc_decl(self):
        return self._proc_decl

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        if self._callee is not None:
            self._callee.visit(on_expression_visited, **kwargs)
        for arg in self._arguments:
            arg.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        def transform_arg(a):
            nonlocal changed
            new_a = a.transform(transformer, **kwargs)
            if new_a != a:
                changed = True
            return new_a

        def copy_pc(**pc_kwargs):
            return self.copy(callee=callee, arguments=arguments, **pc_kwargs)
        changed = False
        arguments = list(map(transform_arg, self._arguments))
        if self._callee is not None:
            callee = self._callee.transform(transformer, **kwargs)
            if callee != self._callee:
                changed = True
        else:
            callee = None
        e = transformer.transform_procedure_call(
            copy_pc=copy_pc, proc_name=self._name, arguments=arguments,
            **kwargs)
        if e is not None:
            return e
        if not changed:
            return self
        return copy_pc()

    def emit_code(self):
        return expressions.writer.write_procedure_call(
            self._proc_decl,
            self._is_method,
            self.name,
            self._callee,
            self._arguments,
        )
