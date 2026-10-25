import data_types


class Constant:
    def __init__(self, data_type, value):
        if isinstance(data_type, (data_types.UnknownTypes, data_types.AnyInt)):
            assert value >= 0
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

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_constant(self, **kwargs)
        if e is not None:
            return e
        return self


    def emit_code(self):
        if isinstance(self._data_type, data_types.Float):
            return "{}F".format(self._value)
        if isinstance(self._data_type, data_types.UnknownByte):
            if self._value == 0:
                return "0"
            return "0x{:02X}".format(self._value)
        if isinstance(self._data_type, data_types.Unknown32):
            return "0x{:08X}".format(self._value)
        if isinstance(self._data_type, data_types.AnyInt):
            return "0x{:0{}X}".format(
                self._value, self._data_type.size * 2)
        if isinstance(self._data_type, data_types.Bool):
            assert self._value == 0 or self._value == 1
            return "true" if self._value else "false"
        return "{}".format(self._value)
