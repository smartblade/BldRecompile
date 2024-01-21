from data_types.data_type import DataType


class Int32(DataType):
    def get_type_name(self, is_metafile):
        return "int"

    @property
    def size(self):
        return 4
