from data_types.data_type import DataType

class UnknownByte(DataType):
    def get_type_name(self):
        return "unknown_byte"

    @property
    def size(self):
        return 1
