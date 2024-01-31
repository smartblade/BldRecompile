import struct

import data_types
from exceptions import NextRunException
import expressions
from hex_conversion import from_hex, to_hex
import instructions
import parser


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
    if not isinstance(first_instr, instructions.VariableDeclaration):
        return
    if not isinstance(second_instr, instructions.Assignment):
        return
    if not isinstance(first_instr.id.data_type, data_types.UnknownClass):
        return
    if not first_instr.id.data_type.class_name.startswith("Eq_"):
        return
    if second_instr.dst.emit_code() != "{}.u0".format(first_instr.id.name):
        return
    return instructions.VariableDeclaration(first_instr.id, second_instr.src)

def merge_instructions(first_instr, second_instr):
    if (
        isinstance(first_instr, instructions.VariableDeclaration) and
        first_instr.initial_expression is not None and
        isinstance(second_instr, instructions.VariableDeclaration) and
        second_instr.initial_expression is not None
    ):
        initial_expression = merge_word32_into_double(
            first_instr.initial_expression, second_instr.initial_expression
        )
        if initial_expression is None:
            return
        if (
            isinstance(first_instr.id.data_type, data_types.UnknownClass) and
            first_instr.id.data_type.class_name.startswith("Eq_") and
            isinstance(second_instr.id.data_type, data_types.Unknown32)
        ):
            initial_expression = parser.parse_cpp_expression(
                "{}".format(initial_expression), {}
            )
            identifier = expressions.Identifier(
                data_types.Double(),
                "rSeq_{}_{}".format(second_instr.id.name, first_instr.id.name),
            )
            return instructions.VariableDeclaration(identifier, initial_expression)
        return
    if not isinstance(first_instr, instructions.Assignment):
        return
    if not isinstance(second_instr, instructions.Assignment):
        return
    src = merge_word32_into_double(first_instr.src, second_instr.src)
    if src is None:
        return
    dst = merge_word32_into_double(first_instr.dst, second_instr.dst)
    if dst is None:
        return
    dst = parser.parse_cpp_expression("{}".format(dst), {})
    src = parser.parse_cpp_expression("{}".format(src), {})
    return instructions.Assignment(dst, src)


def _as_field_access(e):
    if not isinstance(e, expressions.FieldAccess):
        return None, None
    return e.expression.emit_code(), e.field_name


def _strip_real64(e):
    if not isinstance(e, expressions.Cast):
        return None
    if not isinstance(e.data_type, data_types.Double):
        return None
    return e.expression


def merge_word32_into_double(first, second):
    (first_var, first_field) = _as_field_access(first)
    (second_var, second_field) = _as_field_access(second)
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
    first_num = _strip_real64(first)
    if not isinstance(first_num, expressions.Constant):
        return
    second_num = second
    if not isinstance(
        first_num.data_type, (data_types.UnknownByte, data_types.Unknown32)
    ):
        return
    if not isinstance(second_num, expressions.Constant):
        return
    if not isinstance(
        second_num.data_type, (data_types.UnknownByte, data_types.Unknown32)
    ):
        return
    return make_double(first_num.value, second_num.value)


def make_double(first_num, second_num):
    (double, ) = struct.unpack(
        '>d',
        bytes.fromhex(
            to_hex(second_num) + to_hex(first_num)
        ),
    )
    return double


def _validate_return_instruction(code_instructions, proc_decl, **kwargs):
    if len(code_instructions) < 3:
        return
    if not isinstance(code_instructions[-1], instructions.ReturnInstruction):
        return
    return_expression = code_instructions[-1].expression
    if not isinstance(return_expression, expressions.Identifier):
        return
    if not isinstance(code_instructions[-3], instructions.VariableDeclaration):
        return
    if code_instructions[-3].id != return_expression:
        return
    if not _is_one_use_of_id(code_instructions[-2], return_expression):
        return
    proc_decl.change_return_type(None)
    raise NextRunException()


def _is_one_use_of_id(instr, identifier):
    if isinstance(instr, instructions.IfInstruction):
        if _is_one_use_of_id(instr.if_block()[-1], identifier):
            return True
        if _is_one_use_of_id(instr.else_block()[-1], identifier):
            return True
        return False
    uses = {}

    def on_expression_visited(e, uses):
        if isinstance(e, expressions.Identifier):
            uses[e] = uses.get(e, 0) + 1
        if (
            isinstance(e, instructions.Assignment) and
            isinstance(e.dst, expressions.Identifier)
        ):
            uses[e.dst] = uses.get(e.dst, 0) - 1
    instr.visit(on_expression_visited, uses=uses)
    return uses.get(identifier, 0) == 1
