import re

import code_parser as parser
from double import Double
from identifier import Identifier
from unknown32 import Unknown32
from unparsed_token import UnparsedToken
from variable_declaration import VariableDeclaration

loc_var_regexp = re.compile('^(dwLoc(?P<offset>[\dABCDEF]+))|(?P<reg>eax)|(?P<fpu>rLoc1)_\d+')

class UnparsedTokens:
    def __init__(self, tokens):
        self._tokens = tokens

    def as_assignment(self):
        eq_pos = self._find_token("=")
        if eq_pos < 0:
            return (None, None)
        dst = UnparsedTokens(self._tokens[:eq_pos])
        src = UnparsedTokens(self._tokens[eq_pos + 1:])
        return (dst, src)

    def as_variable_declaration(
        self, declared_identifiers, id_suffixes, initial_expression=None
    ):
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
        var_type = parser.parse_data_type(var_type, [])
        new_var_name = self._define_variable_name(var_type, var_name)
        identifier = Identifier(var_type, new_var_name)
        self._ensure_unique_id(identifier, id_suffixes)
        declared_identifiers[var_name] = identifier
        return VariableDeclaration(identifier, initial_expression)

    def as_field_access(self):
        if len(self._tokens) != 1:
            return (None, None)
        expression = self._tokens[0]
        if not isinstance(expression, UnparsedToken):
            return (None, None)
        tokens = expression.emit_code().split("->")
        if len(tokens) < 2:
            return (None, None)
        (var_name, field_name) = tokens
        return (var_name, field_name)

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

    def as_one_token(self):
        if len(self._tokens) != 1:
            return None
        if not isinstance(self._tokens[0], UnparsedToken):
            return None
        return self._tokens[0].emit_code()

    def strip_real64(self):
        if not isinstance(self._tokens[0], UnparsedToken):
            return None
        if not self._tokens[0].emit_code() == "(real64)":
            return None
        return UnparsedTokens(self._tokens[1:])

    def transform_expression(self, **kwargs):
        tokens = list(
            map(
                lambda token: token.transform_expression(**kwargs),
                self._tokens,
            )
        )
        return UnparsedTokens(tokens)

    def emit_code(self):
        return " ".join(map(lambda token: token.emit_code(), self._tokens))

    def _define_variable_name(self, var_type, var_name):
        match = re.search(loc_var_regexp, var_name)
        if match:
            offset = match.group('offset')
            if offset is not None and isinstance(var_type, Unknown32):
                return "unknown_loc_{}".format(offset)
            reg = match.group('reg')
            if reg is not None and isinstance(var_type, Unknown32):
                return "unknown_{}".format(reg)
            if match.group('fpu') is not None:
                if isinstance(var_type, Double):
                    return "unknown_fpu"
        raise Exception("Unparsed variable name: {}.".format(var_name))

    def _ensure_unique_id(self, identifier, id_suffixes):
        if not identifier.name in id_suffixes:
            id_suffixes[identifier.name] = identifier
        else:
            if isinstance(id_suffixes[identifier.name], Identifier):
                self._add_suffix_to_id(
                    id_suffixes[identifier.name], 1, id_suffixes
                )
            self._add_suffix_to_id(
                identifier, id_suffixes[identifier.name] + 1, id_suffixes
            )

    def _add_suffix_to_id(self, identifier, suffix, id_suffixes):
        name = identifier.name
        identifier.rename("{}_{}".format(name, suffix))
        id_suffixes[name] = suffix

    def _find_token(self, s):
        for i in range(len(self._tokens)):
             token = self._tokens[i]
             if isinstance(token, UnparsedToken) and token.emit_code() == s:
                 return i
        return -1
