class Assignment:
    def __init__(self, dst, src):
        self._dst = dst
        self._src = src

    def __repr__(self):
        return "Assign({}={})".format(self._dst, self._src)

    @property
    def dst(self):
        return self._dst

    @property
    def src(self):
        return self._src

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._src.visit(on_expression_visited, **kwargs)
        self._dst.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        src = self._src.transform(transformer, **kwargs)
        dst = self._dst.transform(transformer, **kwargs)
        instr = transformer.transform_assignment(dst, src, **kwargs)
        if instr is not None:
            return instr
        if src == self._src and dst == self._dst:
            return self
        return self.__class__(dst, src)

    def emit_code(self, writer):
        dst = self._dst.emit_code()
        src = self._src.emit_code()
        comment = ""
        if (
            src.endswith("unknown_fpu_2") and
            dst.startswith("unknown_ptr_0C")
        ):
            comment += " // TODO inconsitent coalescing"
        writer.write_line("{} = {};{}".format(dst, src, comment))
