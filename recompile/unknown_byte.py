from data_type import DataType

class UnknownByte(DataType):
    def get_type_name(self, is_metafile):
        if is_metafile:
            return "byte"
        return "unknown_byte"

    @property
    def size(self):
        return 1
