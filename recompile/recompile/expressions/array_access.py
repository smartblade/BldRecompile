import data_types


class ArrayAccess:
    def __init__(self, array, index):
        self._array = array
        self._index = index

    @property
    def array(self):
        return self._array

    @property
    def index(self):
        return self._index

    @property
    def data_type(self):
        if isinstance(self._array.data_type, data_types.Pointer32):
            return self._array.data_type.pointee
        return self._array.data_type.element_type

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._array.visit(on_expression_visited, **kwargs)
        self._index.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        array = self._array.transform(transformer, **kwargs)
        index = self._index.transform(transformer, **kwargs)
        e = transformer.transform_array_access(array, index, **kwargs)
        if e is not None:
            return e
        if array == self._array and index == self._index:
            return self
        return self.__class__(array, index)

    def emit_code(self):
        return "{}[{}]".format(self._array.emit_code(), self._index.emit_code())
