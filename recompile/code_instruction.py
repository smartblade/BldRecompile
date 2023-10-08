import re

import code_parser as parser
from unknown32 import Unknown32
from variable_declaration import VariableDeclaration

loc_var_regexp = re.compile('^dwLoc(?P<offset>[\dABCDEF]+)_\d+')

class CodeInstruction:
    def __init__(self, instr_str):
        self._instr = instr_str

    def __repr__(self):
        return "CodeInstruction({})".format(self._instr)

    def transform_instruction(self, renamed_identifiers):
        self._rename_identifiers(renamed_identifiers)
        (dst, src) = self.as_assignment()
        if src is None:
            decl = self.as_variable_declaration(renamed_identifiers)
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

    def as_variable_declaration(self, renamed_identifiers):
        last_space = self._instr.rfind(' ')
        if last_space < 0:
            return None
        var_type = self._instr[:last_space]
        var_name = self._instr[last_space + 1:]
        if not var_name.startswith("dwLoc"):
            return None
        if var_type.startswith("return"):
            return None
        var_type = parser.parse_data_type(var_type, [])
        new_var_name = self._define_variable_name(var_type, var_name)
        renamed_identifiers[var_name] = new_var_name
        return VariableDeclaration(var_type, new_var_name)

    def _define_variable_name(self, var_type, var_name):
        match = re.search(loc_var_regexp, var_name)
        if match:
            offset = match.group('offset')
            if isinstance(var_type, Unknown32):
                return "unknown_loc_{}".format(offset)
        raise Exception("Unparsed variable name: {}.".format(var_name))

    def _rename_identifiers(self, renamed_identifiers):
        for old_id, new_id in renamed_identifiers.items():
            self._instr = self._instr.replace(old_id, new_id)

    def emit_code(self):
        instr = self._instr
        comment = ""
        if "memcpy" in instr:
            comment = " // TODO improve emitting of memcpy instructions"
        return "{}{};{}".format(" " * 4, instr, comment)
