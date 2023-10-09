from code_instruction import CodeInstruction

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
    (first_var, first_field) = as_field_access(first)
    (second_var, second_field) = as_field_access(second)
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
        if len(first) != 1:
            return
        return first[0]
    if not first[0] == "(real64)":
        return
    first_num = first[1:]
    second_num = second
    if len(first_num) != 1 or not first_num[0].startswith("0x"):
        return
    if len(second_num) != 1 or not second_num[0].startswith("0x"):
        return
    return make_double(first_num[0], second_num[0])

def make_double(first_num, second_num):
    if first_num == "0x00" and second_num == "0x00":
        return "0.0"
    raise Exception(
        "Not implemented merging double: {} and {}.".format(
            first_num, second_num
        )
    )

def as_field_access(tokens):
    if len(tokens) != 1:
        return (None, None)
    expression = tokens[0]
    tokens = expression.split("->")
    if len(tokens) < 2:
        return (None, None)
    (var_name, field_name) = tokens
    return (var_name, field_name)
