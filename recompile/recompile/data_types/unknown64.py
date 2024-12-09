from data_types.data_type import DataType


class Unknown64(DataType):
    def get_type_name(self, is_metafile):
        return "unknown64"

    @property
    def size(self):
        return 8
