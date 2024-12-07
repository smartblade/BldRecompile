from block_transformer import transform_block as transform_block_instructions
from custom_block_transformer import transform_block
from block_visitor import visit_block


class IfInstruction:
    def __init__(self, if_clause, if_block, else_block=None):
        assert if_block is not None
        self._if_clause = if_clause
        self._if_block = if_block
        self._else_block = else_block

    def __repr__(self):
        return "IfInstruction({})".format(self._if_block)

    @property
    def if_clause(self):
        return self._if_clause

    def if_block(self):
        return self._if_block

    def else_block(self):
        return self._else_block

    def add_else_block(self, else_block):
        if self._else_block is None:
            self._else_block = else_block
        else:
            assert len(self._else_block) == 1
            self._else_block[-1].add_else_block(else_block)

    def transform_instruction(self, **kwargs):
        if_block = transform_block_instructions(self._if_block, **kwargs)
        else_block = None
        if self._else_block is not None:
            else_block = transform_block_instructions(
                self._else_block, **kwargs)
        if_clause = self._if_clause.transform_expression(**kwargs)
        return self.__class__(if_clause, if_block, else_block)

    def visit(self, on_expression_visited, **kwargs):
        self._if_clause.visit(on_expression_visited, **kwargs)
        visit_block(self._if_block, on_expression_visited, **kwargs)
        if self._else_block is not None:
            visit_block(self._else_block, on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        if_clause = self._if_clause.transform(transform_callback, **kwargs)
        if_block = transform_block(self._if_block, transform_callback, **kwargs)
        else_block = None
        if self._else_block is not None:
            else_block = transform_block(
                self._else_block, transform_callback, **kwargs)
        if_instr = IfInstruction(if_clause, if_block, else_block)
        return transform_callback(if_instr, **kwargs)

    def emit_code(self, writer, is_elif=False):
        if_clause = self._if_clause.emit_code()
        if if_clause.endswith("this->unknown_double_0028) <= 0.0)"):
            writer.write_line("// TODO avoid emitting unnecessary brackets")
        if is_elif:
            operator = "else if"
        else:
            operator = "if"
        writer.write_line("{} ({})".format(operator, if_clause))
        writer.write_line("{")
        with writer.indent():
            for instr in self._if_block:
                instr.emit_code(writer)
        writer.write_line("}")
        if self._else_block is not None:
            self._write_else_block(self._else_block, writer)

    def _write_else_block(self, else_block, writer):
        if len(else_block) == 1 and isinstance(else_block[0], IfInstruction):
            else_block[0].emit_code(writer, is_elif=True)
            return
        writer.write_line("else")
        writer.write_line("{")
        with writer.indent():
            for instr in else_block:
                instr.emit_code(writer)
        writer.write_line("}")
