from assignment import Assignment
from exceptions import NextRunException
from identifier import Identifier
from merge_types import merge_types
from unparsed_token import UnparsedToken

class CodeInstruction:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "CodeInstruction({})".format(self._tokens)

    def transform_instruction(
        self, declared_identifiers, id_suffixes, proc_decl, **kwargs
    ):
        self._tokens = self._tokens.transform_expression(
            declared_identifiers=declared_identifiers,
            **kwargs,
        )
        decl, eliminate = self._tokens.as_variable_declaration(
            declared_identifiers, id_suffixes
        )
        if decl is not None:
            return decl
        return_expression = self._tokens.as_return()
        if isinstance(return_expression, Identifier):
            new_data_type = merge_types(
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

    def visit(self, on_expression_visited, **kwargs):
        self._tokens.visit(on_expression_visited, **kwargs)

    def as_return(self):
        return self._tokens.as_return()

    def as_two_tokens(self):
        return self._tokens.as_two_tokens()

    def emit_code(self, writer):
        instr = self._tokens.emit_code()
        comment = ""
        if "memcpy" in instr:
            comment += " // TODO improve emitting of memcpy instructions"
        writer.write_line("{};{}".format(instr, comment))
