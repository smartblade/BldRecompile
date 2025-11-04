from data_types.data_type import DataType


class SizeT(DataType):
    @staticmethod
    def get_type_name(is_metafile):
        return "size_t"

    @property
    def size(self):
        return 4

    @property
    def is_any_int(self):
        return True

    @property
    def is_unsigned_int(self):
        return True
