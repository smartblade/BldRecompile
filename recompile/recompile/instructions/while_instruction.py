from block_transformer import transform_block as transform_block_instructions
from custom_block_transformer import transform_block


class WhileInstruction:
    def __init__(self, clause, block):
        self._clause = clause
        self._block = block

    def __repr__(self):
        return "WhileInstruction({})".format(self._block)

    def transform_instruction(self, **kwargs):
        block = transform_block_instructions(self._block, **kwargs)
        clause = self._clause.transform_expression(**kwargs)
        return self.__class__(clause, block)

    def transform(self, transform_callback, **kwargs):
        clause = self._clause.transform(transform_callback, **kwargs)
        block = transform_block(self._block, transform_callback, **kwargs)
        while_instr = WhileInstruction(clause, block)
        return transform_callback(while_instr, **kwargs)

    def emit_code(self, writer):
        clause = self._clause.emit_code()
        writer.write_line("while ({})".format(clause))
        writer.write_line("{")
        with writer.indent():
            for instr in self._block:
                instr.emit_code(writer)
        writer.write_line("}")
