from block_transformer import transform_block
from block_visitor import visit_block

class ForInstruction:
    def __init__(self, clause, block):
        self._clause = clause
        self._block = block

    def __repr__(self):
        return "ForInstruction({})".format(self._block)

    def transform_instruction(self, **kwargs):
        block = transform_block(self._block, **kwargs)
        clause = self._clause.transform_expression(**kwargs)
        return self.__class__(clause, block)

    def visit(self, on_expression_visited, **kwargs):
        self._clause.visit(on_expression_visited, **kwargs)
        visit_block(self._block, on_expression_visited, **kwargs)

    def emit_code(self, writer):
        clause = self._clause.emit_code()
        writer.write_line("for ({})".format(clause))
        writer.write_line("{")
        with writer.indent():
            for instr in self._block:
                instr.emit_code(writer)
        writer.write_line("}")
