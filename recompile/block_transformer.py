import struct

from assignment import Assignment
import code_parser as parser
from double import Double
from exceptions import NextRunException
from variable_declaration import VariableDeclaration
from hex_conversion import from_hex, to_hex
from identifier import Identifier
from return_instruction import ReturnInstruction
from unknown_class import UnknownClass
from unknown32 import Unknown32
from variable_declaration import VariableDeclaration

def transform_block(instructions, **kwargs):
    new_instructions = []
    i = 0
    while i < len(instructions):
        cur_instr = instructions[i]
        if i < len(instructions) - 1:
            next_instr = instructions[i + 1]
            new_instr = merge_union_declaration(cur_instr, next_instr)
            if new_instr is not None:
                i += 1
                cur_instr = new_instr
                next_instr = instructions[i + 1]
            new_instr = merge_instructions(cur_instr, next_instr)
            if new_instr is not None:
                transform_instruction(new_instr, new_instructions, **kwargs)
                i += 2
                continue
        transform_instruction(cur_instr, new_instructions, **kwargs)
        i += 1
    _validate_return_instruction(new_instructions, **kwargs)
    return new_instructions

def transform_instruction(instr, instructions, **kwargs):
    instr = instr.transform_instruction(**kwargs)
    if instr is not None:
        instructions.append(instr)

def merge_union_declaration(first_instr, second_instr):
    if not isinstance(first_instr, VariableDeclaration):
        return
    if not isinstance(second_instr, Assignment):
        return
    if not isinstance(first_instr.id.data_type, UnknownClass):
        return
    if not first_instr.id.data_type.class_name.startswith("Eq_"):
        return
    if second_instr.dst.emit_code() != "{}.u0".format(first_instr.id.name):
        return
    return VariableDeclaration(first_instr.id, second_instr.src)

def merge_instructions(first_instr, second_instr):
    if (
        isinstance(first_instr, VariableDeclaration) and
        first_instr.initial_expression is not None and
        isinstance(second_instr, VariableDeclaration) and
        second_instr.initial_expression is not None
    ):
        initial_expression = merge_word32_into_double(
            first_instr.initial_expression, second_instr.initial_expression
        )
        if initial_expression is None:
            return
        if (
            isinstance(first_instr.id.data_type, UnknownClass) and
            first_instr.id.data_type.class_name.startswith("Eq_") and
            isinstance(second_instr.id.data_type, Unknown32)
        ):
            initial_expression = parser.parse_cpp_expression(
                "{}".format(initial_expression), {}
            )
            identifier = Identifier(
                Double(),
                "rSeq_{}_{}".format(second_instr.id.name, first_instr.id.name),
            )
            return VariableDeclaration(identifier, initial_expression)
        return
    if not isinstance(first_instr, Assignment):
        return
    if not isinstance(second_instr, Assignment):
        return
    src = merge_word32_into_double(first_instr.src, second_instr.src)
    if src is None:
        return
    dst = merge_word32_into_double(first_instr.dst, second_instr.dst)
    if dst is None:
        return
    dst = parser.parse_cpp_expression("{}".format(dst), {})
    src = parser.parse_cpp_expression("{}".format(src), {})
    return Assignment(dst, src)

def merge_word32_into_double(first, second):
    (first_var, first_field) = first.as_field_access()
    (second_var, second_field) = second.as_field_access()
    if (first_var is not None and second_var is not None):
        if first_var != second_var:
            return
        if not first_field.startswith("unknown_double_"):
            return
        first_offset = int(first_field[-4:], 16)
        if not second_field.startswith("dw"):
            return
        second_offset = int(second_field[-4:], 16)
        if second_offset != first_offset + 4:
            return
        return first.emit_code()
    first_num = first.strip_real64()
    if first_num is None:
        return
    second_num = second
    first_num = first_num.emit_code()
    if first_num is None or not first_num.startswith("0x"):
        return
    second_num = second_num.as_one_token()
    if second_num is None or not second_num.startswith("0x"):
        return
    return make_double(first_num, second_num)

def make_double(first_num, second_num):
    (double, ) = struct.unpack(
        '>d',
        bytes.fromhex(
            to_hex(from_hex(second_num)) + to_hex(from_hex(first_num))
        ),
    )
    return double

def _validate_return_instruction(instructions, proc_decl, **kwargs):
    if len(instructions) < 3:
        return
    if not isinstance(instructions[-1], ReturnInstruction):
        return
    return_expression = instructions[-1].expression
    if not isinstance(return_expression, Identifier):
        return
    if not isinstance(instructions[-3], VariableDeclaration):
        return
    if instructions[-3].id != return_expression:
        return
    if not isinstance(instructions[-2], Assignment):
        return
    if instructions[-2].src.as_identifier() != return_expression:
        return
    proc_decl.change_return_type(None)
    raise NextRunException()
