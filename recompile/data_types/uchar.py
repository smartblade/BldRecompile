from data_types.data_type import DataType


class UChar(DataType):
    def get_type_name(self):
        return "unsigned char"

    @property
    def size(self):
        return 1

    @property
    def is_any_int(self):
        return True

    @property
    def is_unsigned_int(self):
        return True
