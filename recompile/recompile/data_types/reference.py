from data_types.data_type import DataType


class Reference(DataType):
    def __init__(self, referent=None):
        super().__init__()
        self._referent = referent

    def __repr__(self):
        return "ref({})".format(self._referent)

    @property
    def size(self):
        return 4

    @property
    def referent(self):
        return self._referent

    def get_type_name(self):
        referent_type = self._referent.get_type_name()
        return "{} &".format(referent_type)
