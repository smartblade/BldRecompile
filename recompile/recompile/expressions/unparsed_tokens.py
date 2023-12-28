import re

import code_parser as parser
import data_types
from exceptions import UnknownTypeException
import expressions
from instructions.variable_declaration import loc_var_regexp


class UnparsedTokens:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "UnparsedTokens({})".format(self._tokens)

    def as_variable_declaration(self, declared_identifiers):
        if len(self._tokens) < 2:
            return None
        var_name = self._tokens[-1]
        if not isinstance(var_name, expressions.UnparsedToken):
            return None
        var_name = var_name.emit_code()
        if not re.search(loc_var_regexp, var_name):
            return None
        var_type = " ".join(
            map(lambda token: token.emit_code(), self._tokens[:-1])
        )
        try:
            var_type = parser.parse_data_type(var_type, {})
        except UnknownTypeException:
            var_type = data_types.UnknownClass(var_type)
        identifier = expressions.Identifier(var_type, var_name)
        if var_name in declared_identifiers:
            raise Exception("Redeclarated identifier: {}.".format(var_name))
        declared_identifiers[var_name] = identifier
        return identifier

    def as_return(self):
        if len(self._tokens) != 2:
            return None
        if not isinstance(self._tokens[0], expressions.UnparsedToken):
            return None
        if self._tokens[0].emit_code() != "return":
            return None
        return self._tokens[1]

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
