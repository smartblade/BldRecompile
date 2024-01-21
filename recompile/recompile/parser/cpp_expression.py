from collections import namedtuple
import re

import data_types
from exceptions import UnknownTypeException
import expressions
from expressions.operator import Operator, operators, priorities
import parser

const_regexp = re.compile(
    r'^((?P<float>\d+\.\d+F?)|(?P<hex>0x[\dABCDEF]+)|(?P<int>\d+)|'
    r'(?P<null>null))$'
)
field_access_regexp = re.compile(
    r'^(?P<expression>.+)(?P<sep>->|\.)(?P<field>\w+)$'
)


def parse_cpp_expression(line, declared_identifiers):
    brackets_dict = {"(": ")", "[": "]"}
    closing_brackets = set(brackets_dict.values())
    states = []
    state = _new_state(
        bracket=None, cur_token=[], tokens=[],
        declared_identifiers=declared_identifiers,
    )
    for c in line + " ":
        if c == " ":
            if len(state.cur_token) > 0:
                cur_token = "".join(state.cur_token)
                _append_token(state.tokens, _new_token(state, cur_token))
                state.cur_token.clear()
        elif c == ",":
            if len(state.cur_token) > 0:
                cur_token = "".join(state.cur_token)
                _append_token(state.tokens, _new_token(state, cur_token))
                state.cur_token.clear()
            _append_token(state.tokens, _new_token(state, ","))
        elif c in brackets_dict:
            state = _opening_bracket(states, state, c)
        elif c in closing_brackets:
            if len(state.cur_token) > 0:
                cur_token = "".join(state.cur_token)
                _append_token(state.tokens, _new_token(state, cur_token))
                state.cur_token.clear()
            brackets_tokens = state.tokens
            (bracket, prefix, state) = _closing_bracket(states, state)
            if brackets_dict[bracket] != c:
                raise Exception(
                    "Mismatched brackets: {} and {}".format(bracket, c)
                )
            if c == "]":
                array = _new_array_access(state, prefix, brackets_tokens)
                _append_token(state.tokens, array)
            else:
                brackets = _new_brackets_expression(
                    state, prefix, brackets_tokens
                )
                _append_token(state.tokens, brackets)
        else:
            state.cur_token.append(c)
    return _make_expression_from_tokens(state.tokens)


def _append_token(tokens, token):
    if (
        len(tokens) > 0 and
        isinstance(tokens[-1], expressions.BracketsExpression)
    ):
        if isinstance(tokens[-1].expression, expressions.UnparsedToken):
            brackets_expression = tokens[-1].expression.emit_code()
        else:
            brackets_expression = None
        if brackets_expression is not None:
            try:
                data_type = parser.parse_data_type(brackets_expression, [])
            except UnknownTypeException:
                data_type = None
            if data_type is not None:
                tokens.pop()
                tokens.append(expressions.Cast(data_type, token))
                return
    tokens.append(token)


def _new_token(state, s):
    match = re.search(const_regexp, s)
    if match:
        if s.startswith("0x"):
            if len(s) == 4:
                data_type = data_types.UnknownByte()
            elif len(s) == 6 or len(s) == 10:
                data_type = data_types.Unknown32()
            else:
                raise Exception("Can't define type for '{}'".format(s))
            value = s
        elif match.group('int') is not None:
            data_type = data_types.Int32()
            value = s
        elif match.group('null') is not None:
            return expressions.Null
        elif s.endswith("F"):
            data_type = data_types.Float()
            value = float(s[:-1])
        else:
            data_type = data_types.Double()
            value = float(s)
        return expressions.Constant(data_type, value)
    if s.startswith("&") and s != Operator.AND.value:
        return expressions.AddressOf(_new_token(state, s[1:]))
    match = re.search(field_access_regexp, s)
    if match:
        expression = match.group('expression')
        field_name = match.group('field')
        sep = match.group('sep')
        return _new_field_access(_new_token(state, expression), sep, field_name)
    if s.startswith("++"):
        return expressions.Increment(_new_token(state, s[2:]))
    if s.startswith("->"):
        prev = state.tokens.pop()
        return _new_field_access(prev, "->", s[2:])
    if s in state.declared_identifiers:
        return state.declared_identifiers[s]
    return expressions.UnparsedToken(s)


def _new_field_access(e, sep, field_name):
    if sep == '.':
        e = expressions.AddressOf(e)
    return expressions.FieldAccess(e, field_name)


def _new_brackets_expression(state, prefix, brackets_tokens):
    if (prefix != ""):
        operator = None
        if (
            prefix in operators and
            len(state.tokens) > 0 and
            isinstance(state.tokens[-1], expressions.UnparsedToken) and
            state.tokens[-1].emit_code() == "operator"
        ):
            operator_token = state.tokens.pop()
            operator = operators[prefix]
            prefix = operator_token.emit_code() + " " + prefix
        arguments = []

        def append_arg(arg):
            if len(arg) == 1:
                arguments.append(arg[0])
            else:
                arguments.append(_make_expression_from_tokens(arg))
        cur_arg = []
        for token in brackets_tokens:
            if (
                isinstance(token, expressions.UnparsedToken) and
                token.emit_code() == ","
            ):
                append_arg(cur_arg)
                cur_arg = []
            else:
                cur_arg.append(token)
        if len(cur_arg) > 0:
            append_arg(cur_arg)
        if (
            prefix.startswith("unknown_procedure_") or
            prefix.startswith("unknown_method_")
        ):
            callee_addr = prefix[-8:]
            is_method = True
        else:
            callee_addr = None
            is_method = False
        return expressions.ProcedureCall(
            prefix, operator, arguments, callee_addr, is_method
        )
    return expressions.BracketsExpression(
        _make_expression_from_tokens(brackets_tokens)
    )


def _new_array_access(state, prefix, brackets_tokens):
    if len(brackets_tokens) == 0:
        return expressions.UnparsedToken("{}[]".format(prefix))
    if prefix == "":
        array = state.tokens.pop()
    else:
        array = _new_token(state, prefix)
    return expressions.ArrayAccess(
        array, _make_expression_from_tokens(brackets_tokens)
    )


def _new_state(**kwargs):
    return namedtuple('State', kwargs.keys())(**kwargs)


def _opening_bracket(states, state, bracket):
    states.append(state)
    return _new_state(
        bracket=bracket, cur_token=[], tokens=[],
        declared_identifiers=state.declared_identifiers,
    )


def _closing_bracket(states, state):
    bracket = state.bracket
    state = states.pop()
    prefix = "".join(state.cur_token)
    state.cur_token.clear()
    return (bracket, prefix, state)


def _make_expression_from_tokens(tokens):
    prev_tokens = None
    prev_op = None
    cur_tokens = []
    cur_op = None
    states = []
    for token in tokens:
        if (
            isinstance(token, expressions.UnparsedToken) and
            token.emit_code() in operators
        ):
            cur_op = operators[token.emit_code()]
            if prev_tokens is None:
                prev_tokens = cur_tokens
                prev_op = cur_op
            else:
                while True:
                    if priorities[prev_op] <= priorities[cur_op]:
                        cur_tokens = [
                            expressions.Bin(
                                prev_op,
                                _make_operand(prev_tokens),
                                _make_operand(cur_tokens),
                            )
                        ]
                        if len(states) > 0:
                            (prev_tokens, prev_op) = states.pop()
                        else:
                            prev_tokens = cur_tokens
                            prev_op = cur_op
                            break
                    else:
                        states.append((prev_tokens, prev_op))
                        prev_tokens = cur_tokens
                        prev_op = cur_op
                        break
            cur_tokens = []
        else:
            cur_tokens.append(token)
    if len(cur_tokens) > 0 and prev_tokens is not None:
        bin = expressions.Bin(
            prev_op,
            _make_operand(prev_tokens),
            _make_operand(cur_tokens),
        )
        while len(states) > 0:
            (prev_tokens, prev_op) = states.pop()
            bin = expressions.Bin(
                prev_op,
                _make_operand(prev_tokens),
                bin,
            )
        return bin
    return _make_operand(tokens)


def _make_operand(tokens):
    assert len(tokens) > 0
    if len(tokens) == 1:
        return tokens[0]
    return expressions.UnparsedTokens(tokens)
