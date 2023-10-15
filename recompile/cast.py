class Cast:
    def __init__(self, data_type, expression):
        self._data_type = data_type
        self._expression = expression

    def emit_code(self):
        type_name = self._data_type.get_type_name(is_metafile=False)
        return "({}) {}".format(type_name, self._expression.emit_code())
