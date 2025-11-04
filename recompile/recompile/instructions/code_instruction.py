class CodeInstruction:
    def __init__(self, expression):
        self._expression = expression

    @property
    def expression(self):
        return self._expression

    def __repr__(self):
        return "CodeInstruction({})".format(self._expression)

    def transform_instruction(
        self, **kwargs
    ):
        tokens = self._expression.transform_expression(**kwargs)
        return CodeInstruction(tokens)

    def visit(self, on_expression_visited, **kwargs):
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_code_instruction(expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self, writer):
        writer.write_line("{};".format(self._expression.emit_code()))
