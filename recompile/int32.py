class Int32:
    def get_type_name(self, is_metafile):
        return "int"

    @property
    def size(self):
        return 4
