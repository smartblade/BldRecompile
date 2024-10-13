import data_types


class Constant:
    def __init__(self, data_type, value):
        self._data_type = data_type
        self._value = value

    def __repr__(self):
        return "Const({})".format(self._value)

    @property
    def data_type(self):
        return self._data_type

    @property
    def value(self):
        return self._value

    def transform_expression(self, **kwargs):
        return self

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transform_callback, **kwargs):
        return transform_callback(self, **kwargs)

    def emit_code(self):
        if isinstance(self._data_type, data_types.Float):
            return "{}F".format(self._value)
        if isinstance(self._data_type, data_types.UnknownByte):
            if self._value == 0:
                return "0"
            return "0x{:02X}".format(self._value)
        if isinstance(self._data_type, data_types.Unknown32):
            return "0x{:08X}".format(self._value)
        return "{}".format(self._value)
