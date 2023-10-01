class Unknown32:
    def get_type_name(self, is_metafile):
        if is_metafile:
            return "word32"
        return "unknown32"

    @property
    def size(self):
        return 4
