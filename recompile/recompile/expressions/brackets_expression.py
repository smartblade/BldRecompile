class BracketsExpression:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Brackets({})".format(self._expression)

    @property
    def data_type(self):
        return self._expression.data_type

    @property
    def expression(self):
        return self._expression

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        return BracketsExpression(expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        expression = self._expression.transform(transform_callback, **kwargs)
        cast = BracketsExpression(expression)
        return transform_callback(cast, **kwargs)

    def emit_code(self):
        return "({})".format(self._expression.emit_code())
