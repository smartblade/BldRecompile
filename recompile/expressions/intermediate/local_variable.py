import data_types


class Local:
    def __init__(self, offset):
        self._offset = offset
        self._ptr32 = data_types.Pointer32()

    @property
    def data_type(self):
        return self._ptr32

    @property
    def offset(self):
        return self._offset

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_local(self, **kwargs)
        if e is not None:
            return e
        return self

    def emit_code(self):
        return "LOCAL({})".format(self._offset)
