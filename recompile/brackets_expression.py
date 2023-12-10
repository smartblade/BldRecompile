class BracketsExpression:
    def __init__(self, prefix, expression):
        self._prefix = prefix
        self._expression = expression

    def __repr__(self):
        return "{}Brackets({})".format(self._prefix, self._expression)

    @property
    def prefix(self):
        return self._prefix

    @property
    def expression(self):
        return self._expression

    def transform_expression(self, **kwargs):
        prefix = self._prefix
        if prefix == "_CIcos":
            prefix = "cos"
        if prefix == "_CIsin":
            prefix = "sin"
        if prefix == "_CIsqrt":
            prefix = "sqrt"
        expression = self._expression.transform_expression(**kwargs)
        return BracketsExpression(prefix, expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return "{}({})".format(
            self._prefix, self._expression.emit_code()
        )
