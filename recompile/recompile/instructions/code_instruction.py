class CodeInstruction:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "CodeInstruction({})".format(self._tokens)

    def transform_instruction(
        self, **kwargs
    ):
        tokens = self._tokens.transform_expression(**kwargs)
        return CodeInstruction(tokens)

    def visit(self, on_expression_visited, **kwargs):
        self._tokens.visit(on_expression_visited, **kwargs)

    def emit_code(self, writer):
        instr = self._tokens.emit_code()
        comment = ""
        if "memcpy" in instr:
            comment += " // TODO improve emitting of memcpy instructions"
        writer.write_line("{};{}".format(instr, comment))
