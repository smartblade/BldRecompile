class CodeInstruction:
    def __init__(self, instr_str):
        instr_str = instr_str.replace("0x00;", "0;")
        self._instr = instr_str

    def __repr__(self):
        return "CodeInstruction({})".format(self._instr)

    def emit_code(self):
        instr = self._instr
        if "memcpy" in instr:
            instr += " // TODO improve emitting of memcpy instructions"
        return "{}{}".format(" " * 4, instr)
