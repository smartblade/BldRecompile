class Reference:
    def __init__(self, referent=None):
        self._referent = referent

    def __repr__(self):
        return "ref({})".format(self._referent)

    @property
    def referent(self):
        return self._referent

    def get_type_name(self, is_metafile):
        referent_type = self._referent.get_type_name(is_metafile)
        return "{} &".format(referent_type)
