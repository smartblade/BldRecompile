import code_parser as parser
from assignment import Assignment
from exceptions import NextRunException
from identifier import Identifier
from int32 import Int32
from pointer32 import Pointer32
from unknown32 import Unknown32
from unparsed_token import UnparsedToken

class CodeInstruction:
    def __init__(self, instr_str):
        self._tokens = parser.parse_cpp_expression(instr_str)

    def __repr__(self):
        return "CodeInstruction({})".format(self._tokens)

    def transform_instruction(
        self, declared_identifiers, id_suffixes, proc_decl, **kwargs
    ):
        self._tokens = self._tokens.transform_expression(
            declared_identifiers=declared_identifiers,
            **kwargs,
        )
        (dst, src) = self.as_assignment()
        if src is None:
            decl, eliminate = self._tokens.as_variable_declaration(
                declared_identifiers, id_suffixes
            )
            if decl is not None:
                return decl
            return_expression = self._tokens.as_return()
            if isinstance(return_expression, Identifier):
                new_data_type = self._merge_types(
                    proc_decl.return_type, return_expression.data_type
                )
                proc_decl.change_return_type(new_data_type)
            if (
                isinstance(return_expression, UnparsedToken) and
                return_expression.emit_code() == "<invalid>"
            ):
                proc_decl.change_return_type(None)
                raise NextRunException()
            return self
        decl, eliminate = dst.as_variable_declaration(
            declared_identifiers, id_suffixes, src
        )
        if eliminate:
            return None
        if decl is not None:
            return decl
        if src.as_one_token() == "0x00":
            src = UnparsedToken("0")
        elif src.as_one_token() == "0x01":
            # 0x01 can not be pointer and it's unlikely float, so make it
            # integer
            identifier = dst.as_identifier()
            if identifier is not None:
                new_data_type = self._merge_types(identifier.data_type, Int32())
                identifier.change_data_type(new_data_type)
                new_var_name = identifier.name.replace(
                    "unknown_loc_", "unknown_int_loc_"
                )
                identifier.rename(new_var_name)
                src = UnparsedToken("1")
        return Assignment(dst, src)

    def as_assignment(self):
        return self._tokens.as_assignment()

    def as_return(self):
        return self._tokens.as_return()

    def as_two_tokens(self):
        return self._tokens.as_two_tokens()

    def _merge_types(self, data_type, new_data_type):
        if (
            isinstance(data_type, Pointer32) and
            isinstance(new_data_type, Pointer32)
        ):
            return data_type
        if (
            isinstance(data_type, Unknown32) and
            isinstance(new_data_type, Unknown32)
        ):
            return data_type
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

    def emit_code(self, writer):
        instr = self._tokens.emit_code()
        comment = ""
        if "memcpy" in instr:
            comment += " // TODO improve emitting of memcpy instructions"
        writer.write_line("{};{}".format(instr, comment))
