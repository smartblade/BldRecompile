import data_types


class NamedConstant:
    def __init__(self, type_size, name):
        self._data_type = data_types.AnyInt(type_size)
        self._name = name

    def __repr__(self):
        return "Const({})".format(self._name)

    @property
    def data_type(self):
        return self._data_type

    def transform(self, transformer, **kwargs):
        return self

    def emit_code(self):
        return self._name
