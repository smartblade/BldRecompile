import re

from brackets_expression import BracketsExpression
from cast import Cast
import code_parser as parser
from double import Double
from exceptions import UnknownTypeException
from field_access import FieldAccess
from identifier import Identifier
from unknown32 import Unknown32
from unparsed_token import UnparsedToken
from variable_declaration import VariableDeclaration

loc_var_regexp = re.compile('^((?P<prefix>dw|r)Loc(?P<offset>[\dABCDEF]{2}))|(?P<reg>eax|ecx|edx)|(?P<fpu>rLoc1)|(?P<seq>rSeq\w+)_\d+')

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

    def as_variable_declaration(
        self, declared_identifiers, id_suffixes, initial_expression=None
    ):
        if len(self._tokens) < 2:
            return (None, None)
        var_name = self._tokens[-1]
        if not isinstance(var_name, UnparsedToken):
            return (None, None)
        var_name = var_name.emit_code()
        if not re.search(loc_var_regexp, var_name):
            return (None, None)
        var_type = " ".join(
            map(lambda token: token.emit_code(), self._tokens[:-1])
        )
        var_type = parser.parse_data_type(var_type, [])
        new_var_name = self._define_variable_name(var_type, var_name)
        identifier = Identifier(var_type, new_var_name)
        self._ensure_unique_id(identifier, id_suffixes)
        eliminate = False
        if initial_expression is not None:
            first, second = initial_expression.as_seq()
            if first is not None:
                seq_id_name = "rSeq_{}_{}".format(first, second)
                declared_identifiers[seq_id_name].rename(identifier.name)
                identifier = declared_identifiers[seq_id_name]
                eliminate = True
        declared_identifiers[var_name] = identifier
        return (VariableDeclaration(identifier, initial_expression), eliminate)

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
        if not isinstance(self._tokens[0], BracketsExpression):
            return (None, None)
        if self._tokens[0].prefix != "SEQ":
            return (None, None)
        return self._tokens[0].expression.emit_code().split(", ")

    def as_one_token(self):
        if len(self._tokens) != 1:
            return None
        if not isinstance(self._tokens[0], UnparsedToken):
            return None
        return self._tokens[0].emit_code()

    def as_two_tokens(self):
        if len(self._tokens) != 2:
            return (None, None)
        if not isinstance(self._tokens[0], UnparsedToken):
            return (None, None)
        if not isinstance(self._tokens[1], UnparsedToken):
            return (None, None)
        return (self._tokens[0].emit_code(), self._tokens[1].emit_code())

    def strip_real64(self):
        if not isinstance(self._tokens[0], BracketsExpression):
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
        new_tokens = []
        i = 0
        while i < len(tokens):
            if (
                i + 1 < len(tokens) and
                isinstance(tokens[i], BracketsExpression)
            ):
                brackets_expression = tokens[i].expression.as_one_token()
                if brackets_expression is not None:
                    try:
                        data_type = parser.parse_data_type(brackets_expression, [])
                    except UnknownTypeException:
                        data_type = None
                    if data_type is not None:
                        new_tokens.append(Cast(data_type, tokens[i + 1]))
                        i += 2
                        continue
            new_tokens.append(tokens[i])
            i += 1
        return UnparsedTokens(new_tokens)

    def emit_code(self):
        return " ".join(map(lambda token: token.emit_code(), self._tokens))

    def _define_variable_name(self, var_type, var_name):
        match = re.search(loc_var_regexp, var_name)
        if match:
            offset = match.group('offset')
            if offset is not None:
                prefix = match.group('prefix')
                if prefix =="dw" and isinstance(var_type, Unknown32):
                    return "unknown_loc_{}".format(offset)
                if prefix =="r" and isinstance(var_type, Double):
                    return "unknown_double_loc_{}".format(offset)
            reg = match.group('reg')
            if reg is not None and isinstance(var_type, Unknown32):
                return "unknown_{}".format(reg)
            if match.group('fpu') is not None:
                if isinstance(var_type, Double):
                    return "unknown_fpu"
            if match.group('seq') is not None:
                return var_name
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
