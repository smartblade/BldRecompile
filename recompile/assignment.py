class Assignment:
    def __init__(self, dst, src):
        self._dst = dst
        self._src = src

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
