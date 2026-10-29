from data_types.data_type import DataType

class Unknown32(DataType):
    def get_type_name(self):
        return "unknown32"

    @property
    def size(self):
        return 4
