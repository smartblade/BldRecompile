import expressions
import instructions

from .eliminate_unused_label import eliminate_unused_label


def transform_if_statements(instrs, label_uses, **kwargs):
    labeled_block = instrs[-1]
    if not isinstance(labeled_block, instructions.LabeledBlock):
        return instrs
    instrs = list(instrs)
    new_instructions = []
    i = 0
    while len(instrs) - i > 0:
        i += 1
        instr = instrs[-i]
        if i > 1:
            new_instructions.append(instr)
        goto_instr = _as_if_goto_instr(instr)
        if goto_instr is None:
            continue
        if goto_instr.label != labeled_block.label:
            break
        del instrs[-i:]
        new_instructions.pop()
        new_instructions.reverse()
        instrs.append(_add_block_to_if_instruction(instr, new_instructions))
        instrs.append(labeled_block)
        label_uses[goto_instr.label].remove(goto_instr)
        eliminate_unused_label(instrs, label_uses)
        labeled_block = instrs[-1]
        if not isinstance(labeled_block, instructions.LabeledBlock):
            break
        new_instructions = []
        i = 0
    return instrs


def _as_if_goto_instr(if_instruction):
    if not isinstance(if_instruction, instructions.IfInstruction):
        return None
    if if_instruction.else_block() is not None:
        return None
    goto_instr = if_instruction.if_block()[-1]
    if not isinstance(goto_instr, instructions.Goto):
        return None
    return goto_instr


def _add_block_to_if_instruction(if_instruction, instrs):
    assert if_instruction.else_block() is None
    assert isinstance(if_instruction.if_block()[-1], instructions.Goto)
    if len(if_instruction.if_block()) == 1:
        return instructions.IfInstruction(
            expressions.do_logical_not(if_instruction.if_clause),
            instrs
        )
    return instructions.IfInstruction(
        if_instruction.if_clause,
        if_instruction.if_block()[:-1],
        instrs,
    )
