class TemporaryRegisterDefinition:
    def __init__(self):
        self._reg_values = {}
        self._fpu_stack = []

    def __repr__(self):
        return "REGDEF({})".format(
            ", ".join(
                "{}={}".format(name, repr(value))
                for (name, value) in self._values.items())
        )

    @property
    def _values(self):
        values = dict(self._reg_values)
        values.update(
            ("ST({})".format(i), value)
            for i, value in enumerate(reversed(self._fpu_stack))
        )
        return values

    def define_reg_value(self, reg, value):
        if reg in self._reg_values:
            raise Exception("Redeclaration of {}".format(reg))
        self._reg_values[reg] = value

    def pop_reg_value(self, reg):
        if reg == "fpu":
            return self.pop_fpu()
        return self._reg_values.pop(reg)

    def push_fpu(self, value):
        self._fpu_stack.append(value)

    def pop_fpu(self):
        return self._fpu_stack.pop()

    def is_empty(self):
        return not self._reg_values and not self._fpu_stack

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        for value in self._values.values():
            value.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        regdef = TemporaryRegisterDefinition()
        for reg, value in self._reg_values.items():
            regdef.define_reg_value(
                reg, value.transform(transform_callback, **kwargs))
        for value in self._fpu_stack:
            regdef.push_fpu(value.transform(transform_callback, **kwargs))
        return transform_callback(regdef, **kwargs)

    def emit_code(self, writer):
        code = "REGDEF({})".format(
            ", ".join(
                "{}={}".format(name, value.emit_code())
                for (name, value) in self._values.items())
        )
        writer.write_line(code)
