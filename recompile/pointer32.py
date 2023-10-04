class Pointer32:
    def __init__(self, pointee=None):
        self._pointee = pointee

    @property
    def pointee(self):
        return self._pointee

    def get_type_name(self, is_metafile):
        if self._pointee is None:
            if is_metafile:
                return "ptr32"
            return "void *"
        raise Exception("Pointee is not implemented.")
