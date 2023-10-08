from variable_declaration import VariableDeclaration

class CodeInstruction:
    def __init__(self, instr_str):
        self._instr = instr_str

    def __repr__(self):
        return "CodeInstruction({})".format(self._instr)

    def transform_instruction(self):
        (dst, src) = self.as_assignment()
        if src is None:
            decl = self.as_variable_declaration()
            if decl is not None:
                return decl
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

    def as_variable_declaration(self):
        last_space = self._instr.rfind(' ')
        if last_space < 0:
            return None
        var_type = self._instr[:last_space]
        var_name = self._instr[last_space + 1:]
        if not var_name.startswith("dwLoc"):
            return None
        if var_type.startswith("return"):
            return None
        from recompile import parse_data_type #TODO move parse function to separate module
        var_type = parse_data_type(var_type, [])
        return VariableDeclaration(var_type, var_name)

    def emit_code(self):
        instr = self._instr
        comment = ""
        if "memcpy" in instr:
            comment = " // TODO improve emitting of memcpy instructions"
        return "{}{};{}".format(" " * 4, instr, comment)
