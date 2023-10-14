import struct

from code_instruction import CodeInstruction
from hex_conversion import from_hex, to_hex

def transform_block(instructions, **kwargs):
    new_instructions = []
    i = 0
    while i < len(instructions):
        cur_instr = instructions[i]
        if i < len(instructions) - 1:
            next_instr = instructions[i + 1]
            new_instr = merge_instructions(cur_instr, next_instr)
            if new_instr is not None:
                new_instructions.append(new_instr)
                i += 2
                continue
        cur_instr = cur_instr.transform_instruction(**kwargs)
        new_instructions.append(cur_instr)
        i += 1
    return new_instructions

def merge_instructions(first_instr, second_instr):
    if not isinstance(first_instr, CodeInstruction):
        return
    if not isinstance(second_instr, CodeInstruction):
        return
    (first_dst, first_src) = first_instr.as_assignment()
    if first_dst is None:
        return
    (second_dst, second_src) = second_instr.as_assignment()
    if second_dst is None:
        return
    src = merge_word32_into_double(first_src, second_src)
    if src is None:
        return
    dst = merge_word32_into_double(first_dst, second_dst)
    if dst is None:
        return
    return CodeInstruction("{} = {}".format(dst, src))

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
        first = first.as_one_token()
        if first is None:
            return
        return first
    first_num = first.strip_real64()
    if first_num is None:
        return
    second_num = second
    first_num = first_num.as_one_token()
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
