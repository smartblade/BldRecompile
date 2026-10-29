import expressions
import expressions.writer


class ReturnInstruction:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Return({})".format(self._expression)

    @property
    def expression(self):
        return self._expression

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        if self._expression is not None:
            self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = None
        if self._expression is not None:
            expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_return(expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self, writer):
        if self._expression is None:
            writer.write_line("return;")
            return
        writer.write_line(
            "return {};".format(
                expressions.writer.write_return_expression(self._expression)
            )
        )
