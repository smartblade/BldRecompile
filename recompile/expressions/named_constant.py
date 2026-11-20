import data_types


class NamedConstant:
    def __init__(self, data_type, name, value):
        self._data_type = data_type
        self._name = name
        self._value = value

    def __repr__(self):
        return "Const({})".format(self._name)

    @property
    def data_type(self):
        return self._data_type

    @property
    def name(self):
        return self._name

    @property
    def value(self):
        return self._value

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        return self

    def emit_code(self):
        return self._name
