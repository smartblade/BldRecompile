from data_types.data_type import DataType


class Long32(DataType):
    @staticmethod
    def get_type_name():
        return "long"

    @property
    def size(self):
        return 4

    @property
    def is_any_int(self):
        return True
