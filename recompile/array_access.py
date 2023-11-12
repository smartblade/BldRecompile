class ArrayAccess:
    def __init__(self, array, index):
        self._array = array
        self._index = index

    def transform_expression(self, **kwargs):
        array = self._array.transform_expression(**kwargs)
        index = self._index.transform_expression(**kwargs)
        return ArrayAccess(array, index)

    def emit_code(self):
        return "{}[{}]".format(self._array.emit_code(), self._index.emit_code())
