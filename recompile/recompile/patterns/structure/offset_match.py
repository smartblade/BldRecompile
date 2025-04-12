import data_types
import expressions


class OffsetMatch:
    _data_type = data_types.Int32()

    def __init__(self, offset):
        self._offset = offset

    def __eq__(self, other):
        assert isinstance(other, OffsetMatch)
        return self._offset == other._offset

    def invalidate(self):
        self._offset = None

    def make_expression(self, transformer):
        return expressions.Constant(self._data_type, self._offset)
