class TemporaryRegisterDefinition:
    def __init__(self):
        self._values = {}

    def __repr__(self):
        return "REGDEF({})".format(
            ", ".join(
                "{}={}".format(name, repr(value))
                for (name, value) in self._values.items())
        )

    def define_reg_value(self, reg, value):
        if reg in self._values:
            raise Exception("Redeclaration of {}".format(reg))
        self._values[reg] = value

    def pop_reg_value(self, reg):
        return self._values.pop(reg)

    def is_empty(self):
        return not bool(self._values)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        for value in self._values.values():
            value.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        regdef = TemporaryRegisterDefinition()
        for reg, value in self._values.items():
            regdef.define_reg_value(
                reg, value.transform(transform_callback, **kwargs))
        return transform_callback(regdef, **kwargs)

    def emit_code(self, writer):
        code = "REGDEF({})".format(
            ", ".join(
                "{}={}".format(name, value.emit_code())
                for (name, value) in self._values.items())
        )
        writer.write_line(code)
