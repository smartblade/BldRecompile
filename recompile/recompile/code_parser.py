from collections import namedtuple
import re

import data_types
from exceptions import UnknownTypeException
import expressions
from expressions.operator import Operator, operators, priorities

const_regexp = re.compile('^(?P<float>\d+\.\d+F?)|(?P<hex>0x[\dABCDEF]+)$')
field_access_regexp = re.compile('^(?P<expression>.+)(?P<sep>->|\.)(?P<field>\w+)$')
typedef_regexp = re.compile('^typedef\s(?P<type_name>\w+)\s(?P<new_type_name>Eq_\d+);$')

def _make_tuple(name, **kwargs):
    return namedtuple(name, kwargs.keys())(**kwargs)

def parse_variable_declaration(s):
    last_space = s.rfind(' ')
    if last_space < 0:
        raise Exception("Failed to parse variable declaration: ' ' was not found.")
    var_type = s[:last_space]
    var_name = s[last_space + 1:]
    if var_name.endswith("[]"):
        var_type = "{} *".format(var_type)
        if var_type.startswith("Eq_"):
            var_type = "struct {}".format(var_type)
        var_name = var_name[:-2]
    return (var_type, var_name)

def parse_procedure_declaration(s):
    start_brackets_pos = s.find("(")
    if start_brackets_pos < 0:
        raise Exception("Failed to parse declaration: '(' was not found.")
    end_brackets_pos = s.find(")")
    if end_brackets_pos < 0:
        raise Exception("Failed to parse declaration: ')' was not found.")
    parameters = s[start_brackets_pos + 1:end_brackets_pos].split(',')
    parsed_parameters = []
    for p in parameters:
        parsed_parameters.append(parse_variable_declaration(p.strip()))
    var_type, var_name = parsed_parameters[0]
    # Check if it is 'thiscall' convention
    if var_name == "ecx":
        class_type=var_type
        parameters=parsed_parameters[1:]
    else:
        class_type=None
        parameters=parsed_parameters
    return _make_tuple(
        'ProcedureDeclation',
         class_type=class_type,
         parameters=parameters
    )

def extract_class_name(class_type):
    if class_type is None:
        return None
    type_tokens = class_type.split(" ")
    if type_tokens[0] != "struct":
        return None
    if type_tokens[-1] != "*":
        raise Exception("Only pointers is supported for thiscall parameter.")
    class_name = type_tokens[1]
    if len(type_tokens) != 3:
        raise Exception("Failed to extract class name from '{}'.".format(class_type))
    return class_name

def parse_data_type(s, classes):
    if s == "byte":
        return data_types.UnknownByte()
    if s == "word32":
        return data_types.Unknown32()
    if s == "ptr32":
        return data_types.Pointer32()
    if s == "int32":
        return data_types.Int32()
    if s == "real64":
        return data_types.Double()
    if s == "real32":
        return data_types.Float()
    if s == "void":
        return None
    if s == "<unknown>*":
        return data_types.Pointer32()
    class_name = extract_class_name(s)
    if class_name is not None:
        if class_name not in classes:
            raise UnknownTypeException("Unknown class: {}.".format(class_name))
        return data_types.Pointer32(classes[class_name])
    if s in classes:
        return classes[s]
    if s.endswith("*"):
        return data_types.Pointer32(parse_data_type(s[:-1].strip(), classes))
    raise UnknownTypeException("Not implemented type: {}.".format(s))

def parse_data_types_declarations(lines, defined_types):
    parsed_classes = {}
    unions = {}
    classes = {}
    class_sizes = {}
    cur_class = None
    union_types = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("typedef struct "):
            class_name = line.split(" ")[2]
            cur_class = {}
            tokens = line.split("// size: ")
            if len(tokens) > 1:
                class_sizes[class_name] = int(tokens[1].split(" ")[0])
        elif cur_class is not None:
            if line.startswith("}"):
                classes[class_name] = cur_class
                cur_class = None
                continue
            tokens = line.split("//")
            offset = int(tokens[1], 16)
            decl = tokens[0].strip().strip(";")
            var_type, var_name = parse_variable_declaration(decl)
            cur_class[offset] = (var_type, var_name)
        elif line.startswith("typedef union Eq_"):
            union_name = line.split(" ")[2]
            union_types = {}
        elif union_types is not None:
            if line.startswith("}"):
                unions[union_name] = union_types
                union_types = None
                continue
            decl = line.strip().strip(";")
            var_type, var_name = parse_variable_declaration(decl)
            union_types[var_type] = var_name
        else:
            match = re.search(typedef_regexp, line)
            if match:
                type_name = match.group('type_name')
                new_type_name = match.group('new_type_name')
                parsed_classes[new_type_name] = defined_types[type_name]
    for class_name in classes.keys():
        skip_offset_if_word32 = None
        new_fields = {}
        for offset, (var_type, var_name) in classes[class_name].items():
            if offset == skip_offset_if_word32 and var_type == "word32":
                continue
            if (
                var_type in unions and
                "real64" in unions[var_type] and
                "word32" in unions[var_type]
            ):
                # Merge 2 'word32' fields into 1 'double'
                var_type = "real64"
                skip_offset_if_word32 = offset + 4
            var_type = parse_data_type(var_type, {})
            var_name = define_field_name(var_type, var_name)
            if (
                class_name in class_sizes and
                len(classes[class_name]) == 1 and
                offset == 0 and
                class_sizes[class_name] % var_type.pointee.size == 0
            ):
                size = class_sizes[class_name] // var_type.pointee.size
                var_type = data_types.Array(var_type.pointee, size)
            new_fields[offset] = (var_type, var_name)
        parsed_classes[class_name] = data_types.ClassType(
            class_name, new_fields
        )
    return parsed_classes

def define_field_name(field_type, field_name):
    if isinstance(field_type, data_types.Unknown32):
        field_name = field_name.replace("dw", "unknown_field_")
    elif isinstance(field_type, data_types.Double):
        if field_name[0] == "t" or field_name[0] == "r":
            field_name = "unknown_double_{}".format(field_name[1:])
    elif isinstance(field_type, data_types.Float):
        field_name = field_name.replace("r", "unknown_float_")
    elif isinstance(field_type, data_types.UnknownByte):
        field_name = field_name.replace("b", "unknown_byte_")
    elif field_name[0] == "a":
        field_name = field_name.replace("a", "unknown_array_")
    return field_name

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
        if tokens[-1].prefix == "" and brackets_expression is not None:
            try:
                data_type = parse_data_type(brackets_expression, [])
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
            prefix, arguments, callee_addr, is_method
        )
    return expressions.BracketsExpression(
        prefix, _make_expression_from_tokens(brackets_tokens)
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
