import data_types


class Stackvar:
    def __init__(self, offset, size):
        self._offset = offset
        self._size = size

    @property
    def data_type(self):
        return data_types.unknown_types[self._size]

    @property
    def offset(self):
        return self._offset

    @property
    def size(self):
        return self._size

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_stackvar(self._offset, self._size, **kwargs)
        if e is not None:
            return e
        return self

    def emit_code(self):
        return "STACKVAR({}, {})".format(self._offset, self._size)
