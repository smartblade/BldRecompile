from block_transformer import transform_block
from block_visitor import visit_block

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
        if_clause = self._if_clause.transform_expression(**kwargs)
        return self.__class__(if_clause, if_block, else_block)

    def visit(self, on_expression_visited, **kwargs):
        self._if_clause.visit(on_expression_visited, **kwargs)
        visit_block(self._if_block, on_expression_visited, **kwargs)
        if self._else_block is not None:
            visit_block(self._else_block, on_expression_visited, **kwargs)

    def emit_code(self, writer):
        if_clause = self._if_clause.emit_code()
        if if_clause.endswith("this->unknown_double_0028) <= 0.0)"):
            writer.write_line("// TODO avoid emitting unnecessary brackets")
        writer.write_line("if ({})".format(if_clause))
        writer.write_line("{")
        with writer.indent():
            for instr in self._if_block:
                instr.emit_code(writer)
        writer.write_line("}")
        if self._else_block is not None:
            writer.write_line("else")
            writer.write_line("{")
            with writer.indent():
                for instr in self._else_block:
                    instr.emit_code(writer)
            writer.write_line("}")
