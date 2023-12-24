class Increment:
    def __init__(self, expression):
        self._expression = expression

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        return Increment(expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return "{}++".format(self._expression.emit_code())
