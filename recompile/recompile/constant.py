from float_type import Float

class Constant:
    def __init__(self, data_type, value):
        self._data_type = data_type
        self._value = value

    @property
    def data_type(self):
        return self._data_type

    def transform_expression(self, **kwargs):
        return self

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def emit_code(self):
        if isinstance(self._data_type, Float):
            return "{}F".format(self._value)
        return "{}".format(self._value)
