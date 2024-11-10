from data_types.data_type import DataType


class AnyInt(DataType):
    """Signed or unsigned integer or pointer"""

    def __init__(self, size):
        super().__init__()
        self._size = size

    def __repr__(self):
        return "AnyInt{}".format(self._size * 8)

    @property
    def size(self):
        return self._size


class AnyInt16(AnyInt):
    def __init__(self):
        super().__init__(2)
