import instructions


def find_return_label(instrs):
    if not isinstance(instrs[-1], instructions.LabeledBlock):
        return
    cur_block = instrs[-1]
    while isinstance(cur_block.last_instruction, instructions.LabeledBlock):
        cur_block = cur_block.last_instruction
    if not isinstance(
        cur_block.last_instruction, instructions.ReturnInstruction
    ):
        return None
    if len(cur_block.instructions) != 1:
        return None
    return cur_block.label
