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
            data_type.pointee.add_method(recompiled_decls[self._callee_addr])
        return ProcedureCall(
            self._name, arguments, self._callee_addr, self._is_method
        )

    def emit_code(self):
        if self._is_method:
            call = "{}->{}".format(self._arguments[0].emit_code(), self._name)
            arguments = self._arguments[1:]
        else:
            call = self._name
            arguments = self._arguments
        return "{}({})".format(
            call, ", ".join(map(lambda a: a.emit_code(), arguments))
        )
