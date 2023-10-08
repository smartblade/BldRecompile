from block_transformer import transform_block

class IfInstruction:
    def __init__(self, if_clause, if_block, else_block=None):
        self._if_clause = if_clause
        self._if_block = if_block
        self._else_block = else_block

    def __repr__(self):
        return "IfInstruction({})".format(self._if_block)

    def add_else_block(self, else_block):
        self._else_block = else_block

    def transform_instruction(self, **kwargs):
        if_block = transform_block(self._if_block, **kwargs)
        else_block = None
        if self._else_block is not None:
            else_block = transform_block(self._else_block, **kwargs)
        return self.__class__(self._if_clause, if_block, else_block)

    def emit_code(self):
        lines = []
        lines.append(" " * 4 + "if ({})".format(self._if_clause))
        lines.append(" " * 4 + "{")
        for instr in self._if_block:
            lines.append(" " * 4 + instr.emit_code())
        lines.append(" " * 4 + "}")
        if self._else_block is not None:
            lines.append(" " * 4 + "else")
            lines.append(" " * 4 + "{")
            for instr in self._else_block:
                lines.append(" " * 4 + instr.emit_code())
            lines.append(" " * 4 + "}")
        return "\n".join(lines)
