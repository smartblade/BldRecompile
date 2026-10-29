from data_types.data_type import DataType


class Char(DataType):
    def get_type_name(self):
        return "char"

    @property
    def size(self):
        return 1

    @property
    def is_any_int(self):
        return True
