import data_types


class ArrayAccess:
    def __init__(self, array, index):
        self._array = array
        self._index = index

    @property
    def data_type(self):
        if isinstance(self._array.data_type, data_types.Pointer32):
            return self._array.data_type.pointee
        return self._array.data_type.element_type

    def transform_expression(self, **kwargs):
        array = self._array.transform_expression(**kwargs)
        index = self._index.transform_expression(**kwargs)
        return ArrayAccess(array, index)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._array.visit(on_expression_visited, **kwargs)
        self._index.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        array = self._array.transform(transform_callback, **kwargs)
        index = self._index.transform(transform_callback, **kwargs)
        array_access = self.__class__(array, index)
        return transform_callback(array_access, **kwargs)

    def emit_code(self):
        return "{}[{}]".format(self._array.emit_code(), self._index.emit_code())
