import data_types
import expressions
from hex_conversion import from_hex


_data_type_by_len = {
    1: data_types.UnknownByte(),
    2: data_types.UnknownByte(),
    4: data_types.AnyInt16(),
    8: data_types.Unknown32(),
}


class HexMatch:
    def __init__(self, hex_str):
        self._hex_str = hex_str

    def __str__(self):
        return "0x{}".format(self._hex_str)

    def __int__(self):
        return from_hex(self._hex_str)

    def __eq__(self, other):
        assert isinstance(other, HexMatch)
        return self._hex_str == other._hex_str

    def make_expression(self, transformer):
        return expressions.Constant(
            _data_type_by_len[len(self._hex_str)], from_hex(self._hex_str))
