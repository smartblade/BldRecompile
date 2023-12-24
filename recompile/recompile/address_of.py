import data_types

class AddressOf:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "AddrOf({})".format(self._expression)

    @property
    def expression(self):
        return self._expression

    @property
    def data_type(self):
        return data_types.Pointer32(self._expression.data_type)

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        return AddressOf(expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return "&{}".format(self._expression.emit_code())
