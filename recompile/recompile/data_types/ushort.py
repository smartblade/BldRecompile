from data_types.data_type import DataType


class UShort(DataType):
    def get_type_name(self, is_metafile):
        return "unsigned short"

    @property
    def size(self):
        return 2

    @property
    def is_any_int(self):
        return True

    @property
    def is_unsigned_int(self):
        return True
