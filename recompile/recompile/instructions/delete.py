class Delete:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Delete({})".format(self._expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self, writer):
        writer.write_line("delete {};".format(self._expression.emit_code()))
