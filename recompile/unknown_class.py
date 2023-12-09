from data_type import DataType

class UnknownClass(DataType):
    def __init__(self, class_name,):
        self._class_name = class_name

    def __repr__(self):
        return "UnknownClass({})".format(self._class_name)

    @property
    def class_name(self):
        return self._class_name

    def get_type_name(self, is_metafile):
        return self._class_name
