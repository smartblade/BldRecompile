from data_types.data_type import DataType


class Pointer32(DataType):
    def __init__(self, pointee=None):
        super().__init__()
        self._pointee = pointee

    def __repr__(self):
        return "ptr32({})".format(self._pointee)

    @property
    def size(self):
        return 4

    @property
    def pointee(self):
        return self._pointee

    def get_type_name(self, is_metafile):
        if self._pointee is None:
            if is_metafile:
                return "ptr32"
            return _make_ptr_type("void")
        pointee_type = self._pointee.get_type_name(is_metafile)
        return _make_ptr_type(pointee_type)


def _make_ptr_type(pointee_str):
    sep = "" if pointee_str[-1] == "*" else " "
    return "{}{}*".format(pointee_str, sep)
