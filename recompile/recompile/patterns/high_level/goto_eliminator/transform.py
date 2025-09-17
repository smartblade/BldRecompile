import instructions

from .eliminate_unused_label import eliminate_unused_label
from .find_return_label import find_return_label
from .collect_label_uses import collect_label_uses
from .transform_if import transform_if_statements
from .transform_switch import transform_switch_statements
from .transform_while import transform_while


def transform(instrs, stack_vars):
    return_label = find_return_label(instrs)
    label_uses = collect_label_uses(instrs)
    new_instructions = []
    for instr in instrs:
        instr = _transform_instruction(
            instr, return_label=return_label, label_uses=label_uses,
            stack_vars=stack_vars)
        new_instructions.append(instr)
    eliminate_unused_label(new_instructions, label_uses=label_uses)
    new_instructions = transform_switch_statements(
        new_instructions, label_uses=label_uses)
    new_instructions = transform_if_statements(
        new_instructions, label_uses=label_uses, stack_vars=stack_vars)
    return new_instructions


def _transform_instruction(instr, return_label, label_uses, stack_vars):
    if isinstance(instr, instructions.Goto):
        if instr.label == return_label:
            label_uses[return_label].remove(instr)
            return instructions.ReturnInstruction(None)
    if isinstance(instr, instructions.LabeledBlock):
        return _transform_labeled_block(
            instr, return_label=return_label, label_uses=label_uses,
            stack_vars=stack_vars)
    return instr


def _transform_labeled_block(labeled_block, **kwargs):
    new_instructions = []
    for instr in labeled_block.instructions:
        new_instructions.append(_transform_instruction(instr, **kwargs))
    eliminate_unused_label(new_instructions, **kwargs)
    new_instructions = transform_switch_statements(new_instructions, **kwargs)
    new_instructions = transform_if_statements(new_instructions, **kwargs)
    transform_while(labeled_block.label, new_instructions, **kwargs)
    return instructions.LabeledBlock(labeled_block.label, new_instructions)
