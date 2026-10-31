from custom_block_transformer import transform_block
from block_visitor import visit_block


class ForInstruction:
    def __init__(self, init, clause, increment, block):
        self._init = init
        self._clause = clause
        self._increment = increment
        self._block = block

    def __repr__(self):
        return "ForInstruction({})".format(self._block)

    @property
    def init(self):
        return self._init

    @property
    def clause(self):
        return self._clause

    @property
    def increment(self):
        return self._increment

    @property
    def block(self):
        return self._block

    def copy(self, init=None, block=None):
        return self.__class__(
            init or self._init, self._clause, self._increment,
            self._block if block is None else block)

    def visit(self, on_expression_visited, **kwargs):
        if self._init is not None:
            self._init.visit(on_expression_visited, **kwargs)
        self._clause.visit(on_expression_visited, **kwargs)
        self._increment.visit(on_expression_visited, **kwargs)
        visit_block(self._block, on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        init = self._init
        # Variable declaration in init is not transformed
        if init is not None and hasattr(init, "transform"):
            init = init.transform(transformer, **kwargs)
        clause = self._clause.transform(transformer, **kwargs)
        increment = self._increment.transform(transformer, **kwargs)
        block = transform_block(self._block, transformer, **kwargs)
        instr = transformer.transform_for(
            init, clause, increment, block, **kwargs)
        if instr is not None:
            return instr
        return self.__class__(init, clause, increment, block)

    def emit_code(self, writer):
        init = _emit_inline(self._init) if self._init is not None else ""
        writer.write_line("for ({}; {}; {})".format(
            init, self._clause.emit_code(), _emit_inline(self._increment)))
        writer.write_line("{")
        with writer.indent():
            for instr in self._block:
                instr.emit_code(writer)
        writer.write_line("}")


def _emit_inline(instr):
    from writer import Writer
    writer = Writer()
    instr.emit_code(writer)
    code = writer.get_string().strip()
    assert "\n" not in code
    assert code.endswith(";")
    return code[:-1]
