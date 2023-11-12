class Increment:
    def __init__(self, expression):
        self._expression = expression

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        return Increment(expression)

    def emit_code(self):
        return "{}++".format(self._expression.emit_code())
