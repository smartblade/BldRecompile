from data_types.data_type import DataType

class Float(DataType):
    def get_type_name(self, is_metafile):
        return "float"

    @property
    def size(self):
        return 4
