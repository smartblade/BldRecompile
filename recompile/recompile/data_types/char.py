from data_types.data_type import DataType


class Char(DataType):
    def get_type_name(self, is_metafile):
        return "char"

    @property
    def size(self):
        return 1
