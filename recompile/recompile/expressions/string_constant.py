import data_types


class StringConstant:
    def __init__(self, s):
        self._string = s

    @property
    def data_type(self):
        return data_types.Pointer32(data_types.Char())

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        return self

    def emit_code(self):
        return '"{}"'.format(self._string)
