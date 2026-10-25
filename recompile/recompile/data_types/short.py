from data_types.data_type import DataType


class Short(DataType):
    def get_type_name(self):
        return "short"

    @property
    def size(self):
        return 2

    @property
    def is_any_int(self):
        return True
