import re

from cast import Cast
import code_parser as parser
import data_types
from exceptions import UnknownTypeException
from field_access import FieldAccess
from identifier import Identifier
from procedure_call import ProcedureCall
from unparsed_token import UnparsedToken
from variable_declaration import VariableDeclaration, loc_var_regexp


class UnparsedTokens:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "UnparsedTokens({})".format(self._tokens)

    def as_assignment(self):
        eq_pos = self._find_token("=")
        if eq_pos < 0:
            return (None, None)
        dst = UnparsedTokens(self._tokens[:eq_pos])
        src = UnparsedTokens(self._tokens[eq_pos + 1:])
        return (dst, src)

    def as_variable_declaration(self, declared_identifiers):
        if len(self._tokens) < 2:
            return None
        var_name = self._tokens[-1]
        if not isinstance(var_name, UnparsedToken):
            return None
        var_name = var_name.emit_code()
        if not re.search(loc_var_regexp, var_name):
            return None
        var_type = " ".join(
            map(lambda token: token.emit_code(), self._tokens[:-1])
        )
        try:
            var_type = parser.parse_data_type(var_type, [])
        except UnknownTypeException:
            var_type = data_types.UnknownClass(var_type)
        identifier = Identifier(var_type, var_name)
        if var_name in declared_identifiers:
            raise Exception("Redeclarated identifier: {}.".format(var_name))
        declared_identifiers[var_name] = identifier
        return identifier

    def as_field_access(self):
        if len(self._tokens) != 1:
            return (None, None)
        field_access = self._tokens[0]
        if not isinstance(field_access, FieldAccess):
            return (None, None)
        return (field_access.expression.emit_code(), field_access.field_name)

    def as_identifier(self):
        if len(self._tokens) != 1:
            return (None, None)
        if not isinstance(self._tokens[0], Identifier):
            return None
        return self._tokens[0]

    def as_return(self):
        if len(self._tokens) != 2:
            return None
        if not isinstance(self._tokens[0], UnparsedToken):
            return None
        if self._tokens[0].emit_code() != "return":
            return None
        return self._tokens[1]

    def as_seq(self):
        if len(self._tokens) != 1:
            return (None, None)
        if not isinstance(self._tokens[0], ProcedureCall):
            return (None, None)
        if self._tokens[0].name != "SEQ":
            return (None, None)
        return self._tokens[0].arguments

    def as_type(self, data_type):
        if len(self._tokens) != 1:
            return None
        if not isinstance(self._tokens[0], data_type):
            return None
        return self._tokens[0]

    def as_one_token(self):
        if len(self._tokens) != 1:
            return None
        if not isinstance(self._tokens[0], UnparsedToken):
            return None
        return self._tokens[0].emit_code()

    def strip_real64(self):
        if len(self._tokens) != 1:
            return None
        if not isinstance(self._tokens[0], Cast):
            return None
        if not isinstance(self._tokens[0].data_type, data_types.Double):
            return None
        return self._tokens[0].expression

    def transform_expression(self, **kwargs):
        tokens = list(
            map(
                lambda token: token.transform_expression(**kwargs),
                self._tokens,
            )
        )
        return UnparsedTokens(tokens)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        for token in self._tokens:
            token.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return " ".join(map(lambda token: token.emit_code(), self._tokens))

    def _find_token(self, s):
        for i in range(len(self._tokens)):
             token = self._tokens[i]
             if isinstance(token, UnparsedToken) and token.emit_code() == s:
                 return i
        return -1
