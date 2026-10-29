from data_types.data_type import DataType


class _NullptrType(DataType):
    @property
    def size(self):
        return 4


NullptrType = _NullptrType()
