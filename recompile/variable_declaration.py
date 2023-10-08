class VariableDeclaration:
    def __init__(self, var_type, var_name):
        self._var_type = var_type
        self._var_name = var_name

    def transform_instruction(self):
        raise

    def emit_code(self):
        type_name = self._var_type.get_type_name(is_metafile=False)
        sep = "" if type_name.endswith("*") else " "
        return "{}{}{}{};".format(" " * 4, type_name, sep, self._var_name)
