from collections import namedtuple
import re

from array_access import ArrayAccess
from brackets_expression import BracketsExpression
from array_type import Array
from class_type import ClassType
from constant import Constant
from exceptions import UnknownTypeException
from increment import Increment
from field_access import FieldAccess
from float_type import Float
from int32 import Int32
from double import Double
from pointer32 import Pointer32
from procedure_call import ProcedureCall
from unknown_byte import UnknownByte
from unknown32 import Unknown32
from unparsed_token import UnparsedToken
from unparsed_tokens import UnparsedTokens

const_regexp = re.compile('^(?P<float>\d+\.\d+F?)$')
field_access_regexp = re.compile('^(?P<expression>.+)->(?P<field>\w+)$')

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
    if not class_name.startswith("Eq_"):
        raise Exception(
            "Class name '{}' should be started with 'Eq_'.".format(class_name)
        )
    return class_name

def parse_data_type(s, classes):
    if s == "byte":
        return UnknownByte()
    if s == "word32":
        return Unknown32()
    if s == "ptr32":
        return Pointer32()
    if s == "int32":
        return Int32()
    if s == "real64":
        return Double()
    if s == "real32":
        return Float()
    if s == "void":
        return None
    if s == "<unknown>*":
        return Pointer32()
    class_name = extract_class_name(s)
    if class_name is not None:
        return Pointer32(classes[class_name])
    if s in classes:
        return classes[s]
    if s.endswith("*"):
        return Pointer32(parse_data_type(s[:-1].strip(), classes))
    raise UnknownTypeException("Not implemented type: {}.".format(s))

def parse_data_types_declarations(lines):
    parsed_classes = {}
    unions = {}
    classes = {}
    class_sizes = {}
    cur_class = None
    union_types = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("typedef struct Eq_"):
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
                var_type = Array(var_type.pointee, size)
            new_fields[offset] = (var_type, var_name)
        parsed_classes[class_name] = ClassType(class_name, new_fields)
    return parsed_classes

def define_field_name(field_type, field_name):
    if isinstance(field_type, Unknown32):
        field_name = field_name.replace("dw", "unknown_field_")
    elif isinstance(field_type, Double):
        if field_name[0] == "t" or field_name[0] == "r":
            field_name = "unknown_double_{}".format(field_name[1:])
    elif isinstance(field_type, Float):
        field_name = field_name.replace("r", "unknown_float_")
    elif isinstance(field_type, UnknownByte):
        field_name = field_name.replace("b", "unknown_byte_")
    elif field_name[0] == "a":
        field_name = field_name.replace("a", "unknown_array_")
    return field_name

def parse_cpp_expression(line):
    brackets_dict = {"(": ")", "[": "]"}
    closing_brackets = set(brackets_dict.values())
    state = []
    tokens = []
    cur_token = ""
    for c in line + " ":
        if c == " ":
            if len(cur_token) > 0:
                tokens.append(_new_token(tokens, cur_token))
                cur_token = ""
        elif c in brackets_dict:
            state.append((c, cur_token, tokens))
            cur_token = ""
            tokens = []
        elif c in closing_brackets:
            if len(cur_token) > 0:
                tokens.append(_new_token(tokens, cur_token))
                cur_token = ""
            brackets_tokens = tokens
            (bracket, prefix, tokens) = state.pop()
            if brackets_dict[bracket] != c:
                raise Exception(
                    "Mismatched brackets: {} and {}".format(bracket, c)
                )
            if c == "]":
                array = _new_array_access(tokens, prefix, brackets_tokens)
                tokens.append(array)
            else:
                brackets = _new_brackets_expression(prefix, brackets_tokens)
                tokens.append(brackets)

        else:
            cur_token += c
    return UnparsedTokens(tokens)

def _new_token(tokens, s):
    match = re.search(const_regexp, s)
    if match:
        if s.endswith("F"):
            data_type = Float()
            value = float(s[:-1])
        else:
            data_type = Double()
            value = float(s)
        return Constant(data_type, value)
    match = re.search(field_access_regexp, s)
    if match:
        expression = match.group('expression')
        field_name = match.group('field')
        return FieldAccess(_new_token(tokens, expression), field_name)
    if s.startswith("++"):
        return Increment(_new_token(tokens, s[2:]))
    if s.startswith("->"):
        prev = tokens.pop()
        return FieldAccess(prev, s[2:])
    return UnparsedToken(s)

def _new_brackets_expression(prefix, tokens):
    if prefix.startswith("unknown_method_"):
        if len(tokens) != 1:
            raise Exception(
                "Should be 1 token inside brackets but was: {}".format(tokens)
            )
        callee_addr = prefix[15:]
        return ProcedureCall(prefix, tokens, callee_addr, is_method=True)
    return BracketsExpression(prefix, UnparsedTokens(tokens))

def _new_array_access(tokens, prefix, brackets_tokens):
    if prefix == "":
        array = tokens.pop()
    else:
        array = _new_token(tokens, prefix)
    return ArrayAccess(array, UnparsedTokens(brackets_tokens))
