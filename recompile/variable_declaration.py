class VariableDeclaration:
    def __init__(self, identifier):
        self._id = identifier

    def emit_code(self):
        type_name = self._id.data_type.get_type_name(is_metafile=False)
        sep = "" if type_name.endswith("*") else " "
        return "{}{}{}{};".format(" " * 4, type_name, sep, self._id.name)
