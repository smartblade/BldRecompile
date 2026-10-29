from data_types.data_type import DataType

class Double(DataType):
    def get_type_name(self):
        return "double"

    @property
    def size(self):
        return 8
