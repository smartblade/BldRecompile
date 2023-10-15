class VariableDeclaration:
    def __init__(self, identifier, initial_expression):
        self._id = identifier
        self._initial_expression = initial_expression

    def emit_code(self, writer):
        type_name = self._id.data_type.get_type_name(is_metafile=False)
        sep = "" if type_name.endswith("*") else " "
        initial_expression = ""
        if self._initial_expression is not None:
            initial_expression = " = " + self._initial_expression.emit_code()
        writer.write_line("{}{}{}{};".format(
                type_name, sep, self._id.name, initial_expression
            )
        )
