class DataType:
    def __init__(self):
        self._qualifiers = []
        self._right_qualifiers = []
        self._namespace_type = None

    @property
    def is_any_int(self):
        return False

    @property
    def is_unsigned_int(self):
        return False

    @property
    def qualifiers(self):
        return self._qualifiers

    def make_variable_declaration(
        self, var_name, current_namespace_type=None
    ):
        qualifiers = ""
        for qualifier in self._qualifiers:
            qualifiers += qualifier + " "
        right_qualifiers = ""
        for qualifier in self._right_qualifiers:
            right_qualifiers += " " + qualifier
        type_name = self.get_type_name()
        if (
            type_name[-1] in {"*", "&"} and not right_qualifiers or
            var_name is None
        ):
            sep = ""
        else:
            sep = " "
        if var_name is None:
            var_name = ""
        if (
            self._namespace_type is not None and
            self._namespace_type != current_namespace_type
        ):
            namespace_name = self._namespace_type.get_type_name()
            type_name = "{}::{}".format(namespace_name, type_name)
        return "{}{}{}{}{}".format(
            qualifiers, type_name, right_qualifiers, sep, var_name
        )

    def add_qualifier(self, qualifier):
        self._qualifiers.append(qualifier)

    def add_right_qualifier(self, qualifier):
        self._right_qualifiers.append(qualifier)

    def set_qualifiers(self, qualifiers):
        self._qualifiers = qualifiers

    def set_namespace(self, namespace_type):
        assert (
            self._namespace_type is None or
            self._namespace_type == namespace_type
        )
        self._namespace_type = namespace_type
