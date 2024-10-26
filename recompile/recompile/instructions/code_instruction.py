class CodeInstruction:
    def __init__(self, tokens):
        self._tokens = tokens

    @property
    def expression(self):
        return self._tokens

    def __repr__(self):
        return "CodeInstruction({})".format(self._tokens)

    def transform_instruction(
        self, **kwargs
    ):
        tokens = self._tokens.transform_expression(**kwargs)
        return CodeInstruction(tokens)

    def visit(self, on_expression_visited, **kwargs):
        self._tokens.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        expression = self._tokens.transform(transform_callback, **kwargs)
        instruction = CodeInstruction(expression)
        return transform_callback(instruction, **kwargs)

    def emit_code(self, writer):
        instr = self._tokens.emit_code()
        comment = ""
        if "memcpy" in instr:
            comment += " // TODO improve emitting of memcpy instructions"
        writer.write_line("{};{}".format(instr, comment))
