class CodeInstruction:
    def __init__(self, instr_str):
        self._instr = instr_str

    def __repr__(self):
        return "CodeInstruction({})".format(self._instr)

    def transform_instruction(self):
        (dst, src) = self.as_assignment()
        if src is None:
            return self
        if src == "0x00":
            src = "0"
        return self.__class__("{} = {}".format(dst, src))

    def as_assignment(self):
        tokens = self._instr.split(" = ")
        if len(tokens) < 2:
            return (None, None)
        (dst, src) = tokens
        return (dst.strip(), src.strip())

    def emit_code(self):
        instr = self._instr
        comment = ""
        if "memcpy" in instr:
            comment = " // TODO improve emitting of memcpy instructions"
        return "{}{};{}".format(" " * 4, instr, comment)
