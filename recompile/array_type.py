class Array:
    def __init__(self, element_type, size):
        self._element_type = element_type
        self._size = size

    def __repr__(self):
        return "{}[{}]".format(self._element_type, self._size)

    @property
    def size(self):
        return self._size * self._element_type.size

    def make_variable_declaration(self, var_name, is_metafile):
        element_decl = self._element_type.make_variable_declaration(
            var_name, is_metafile
        )
        return "{}[{}]".format(element_decl, self._size)
