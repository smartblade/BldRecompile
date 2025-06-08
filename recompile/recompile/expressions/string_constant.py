import data_types


class StringConstant:
    def __init__(self, s):
        self._string = s

    @property
    def data_type(self):
        return data_types.Pointer32(data_types.Char())

    def transform(self, transformer, **kwargs):
        return self

    def emit_code(self):
        return '"{}"'.format(self._string)
