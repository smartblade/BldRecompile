class UInt32:
    def get_type_name(self, is_metafile):
        return "unsigned int"

    @property
    def size(self):
        return 4
