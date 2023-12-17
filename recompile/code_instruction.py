class CodeInstruction:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "CodeInstruction({})".format(self._tokens)

    def transform_instruction(
        self, declared_identifiers, id_suffixes, **kwargs
    ):
        self._tokens = self._tokens.transform_expression(
            declared_identifiers=declared_identifiers,
            **kwargs,
        )
        decl, eliminate = self._tokens.as_variable_declaration(
            declared_identifiers, id_suffixes
        )
        if decl is not None:
            return decl
        return self

    def visit(self, on_expression_visited, **kwargs):
        self._tokens.visit(on_expression_visited, **kwargs)

    def as_two_tokens(self):
        return self._tokens.as_two_tokens()

    def emit_code(self, writer):
        instr = self._tokens.emit_code()
        comment = ""
        if "memcpy" in instr:
            comment += " // TODO improve emitting of memcpy instructions"
        writer.write_line("{};{}".format(instr, comment))
