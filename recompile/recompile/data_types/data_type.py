class DataType:
    def __init__(self):
        self._qualifiers = []

    @property
    def is_any_int(self):
        return False

    @property
    def qualifiers(self):
        return self._qualifiers

    def make_variable_declaration(self, var_name, is_metafile):
        qualifiers = ""
        for qualifier in self._qualifiers:
            qualifiers += qualifier + " "
        type_name = self.get_type_name(is_metafile)
        sep = "" if type_name[-1] in {"*", "&"} else " "
        return "{}{}{}{}".format(
            qualifiers, type_name, sep, var_name
        )

    def add_qualifier(self, qualifier):
        self._qualifiers.append(qualifier)

    def set_qualifiers(self, qualifiers):
        self._qualifiers = qualifiers
