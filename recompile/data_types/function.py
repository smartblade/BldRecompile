from data_types.data_type import DataType


class Function(DataType):
    def __init__(self, proc_decl):
        super().__init__()
        self._proc_decl = proc_decl

    def __repr__(self):
        return "fn({})".format(self._proc_decl)

    @property
    def size(self):
        return 4

    @property
    def proc_decl(self):
        return self._proc_decl
