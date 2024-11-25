import data_types


class Dereference:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Deref({})".format(self._expression)

    @property
    def data_type(self):
        data_type = self._expression.data_type
        assert isinstance(data_type, data_types.Pointer32)
        return data_type.pointee

    def emit_code(self):
        return "*{}".format(self._expression.emit_code())
