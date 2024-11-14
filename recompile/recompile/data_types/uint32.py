from data_types.data_type import DataType


class UInt32(DataType):
    def get_type_name(self, is_metafile):
        return "unsigned int"

    @property
    def size(self):
        return 4

    @property
    def is_any_int(self):
        return True
