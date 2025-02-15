class Negate:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Neg({})".format(self._expression)

    @property
    def data_type(self):
        return self._expression.data_type

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        expression = self._expression.transform(transform_callback, **kwargs)
        return transform_callback(self.__class__(expression), **kwargs)

    def emit_code(self):
        return "-{}".format(self._expression.emit_code())
