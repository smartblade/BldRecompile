import re

import code_parser as parser
from identifier import Identifier
from int32 import Int32
from unknown32 import Unknown32
from variable_declaration import VariableDeclaration

loc_var_regexp = re.compile('^dwLoc(?P<offset>[\dABCDEF]+)_\d+')

class CodeInstruction:
    def __init__(self, instr_str):
        self._tokens = instr_str.split(" ")

    def __repr__(self):
        return "CodeInstruction({})".format(self._instr)

    def transform_instruction(self, declared_identifiers, proc_decl):
        self._replace_declared_identifiers(declared_identifiers)
        (dst, src) = self.as_assignment()
        if src is None:
            decl = self.as_variable_declaration(declared_identifiers)
            if decl is not None:
                return decl
            if (
                len(self._tokens) == 2 and
                self._tokens[0] == "return" and
                isinstance(self._tokens[1], Identifier)
            ):
                identifier = self._tokens[1]
                new_data_type = self._merge_types(
                    proc_decl.return_type, identifier.data_type
                )
                proc_decl.change_return_type(new_data_type)
            return self
        if len(src) == 1 and src[0] == "0x00":
            src[0] = "0"
        if len(src) == 1 and src[0] == "0x01":
            # 0x01 can not be pointer and it's unlikely float, so make it
            # integer
            if (
                len(dst) == 1 and
                isinstance(dst[0], Identifier)
            ):
                identifier = dst[0]
                new_data_type = self._merge_types(identifier.data_type, Int32())
                identifier.change_data_type(new_data_type)
                new_var_name = identifier.name.replace(
                    "unknown_loc_", "unknown_int_loc_"
                )
                identifier.rename(new_var_name)
                src[0] = "1"
        return self.__class__("{} = {}".format(" ".join(map(str, dst)), " ".join(src)))

    def as_assignment(self):
        if not "=" in self._tokens:
            return (None, None)
        eq_pos = self._tokens.index("=")
        (dst, src) = self._tokens[:eq_pos], self._tokens[eq_pos + 1:]
        return (dst, src)

    def as_variable_declaration(self, declared_identifiers):
        if len(self._tokens) < 2:
            return None
        var_name = self._tokens[-1]
        if not isinstance(var_name, str):
            return None
        if not var_name.startswith("dwLoc"):
            return None
        if self._tokens[0] == "return":
            return None
        var_type = " ".join(self._tokens[:-1])
        var_type = parser.parse_data_type(var_type, [])
        new_var_name = self._define_variable_name(var_type, var_name)
        declared_identifiers[var_name] = Identifier(var_type, new_var_name)
        return VariableDeclaration(declared_identifiers[var_name])

    def _define_variable_name(self, var_type, var_name):
        match = re.search(loc_var_regexp, var_name)
        if match:
            offset = match.group('offset')
            if isinstance(var_type, Unknown32):
                return "unknown_loc_{}".format(offset)
        raise Exception("Unparsed variable name: {}.".format(var_name))

    def _replace_declared_identifiers(self, declared_identifiers):
        self._tokens = list(
            map(
                lambda token: declared_identifiers.get(token, token),
                self._tokens,
            )
        )

    def _merge_types(self, data_type, new_data_type):
        if not isinstance(data_type, Unknown32):
            raise Exception(
                "Can't merge {} with {}.".format(
                    data_type, new_data_type
                )
            )
        if not isinstance(new_data_type, Int32):
            raise Exception(
                "Can't merge {} with {}.".format(
                    data_type, new_data_type
                )
            )
        return new_data_type

    def emit_code(self):
        instr = " ".join(map(str, self._tokens))
        comment = ""
        if "memcpy" in instr:
            comment = " // TODO improve emitting of memcpy instructions"
        return "{}{};{}".format(" " * 4, instr, comment)
