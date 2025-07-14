class DataType:
    def __init__(self):
        self._qualifiers = []
        self._right_qualifiers = []

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
        right_qualifiers = ""
        for qualifier in self._right_qualifiers:
            right_qualifiers += " " + qualifier
        type_name = self.get_type_name(is_metafile)
        if type_name[-1] in {"*", "&"} and not right_qualifiers:
            sep = ""
        else:
            sep = " "
        return "{}{}{}{}{}".format(
            qualifiers, type_name, right_qualifiers, sep, var_name
        )

    def add_qualifier(self, qualifier):
        self._qualifiers.append(qualifier)

    def add_right_qualifier(self, qualifier):
        self._right_qualifiers.append(qualifier)

    def set_qualifiers(self, qualifiers):
        self._qualifiers = qualifiers
