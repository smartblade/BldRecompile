import instructions
from patterns.high_level.goto_eliminator.collect_label_uses import (
    collect_label_uses)


def transform_for_loops(instrs):
    """Transform loops compiled from 'for' statements.

    Visual C++ compiles 'for (init; clause; increment) block' to

        init
        goto cond_label;
    inc_label:
        increment
    cond_label:
        if (clause)
        {
            block
            goto inc_label;
        }
        ...
    """
    label_uses = collect_label_uses(instrs)
    return _transform_block(instrs, label_uses)


def _transform_block(instrs, label_uses):
    instrs = [_transform_nested(instr, label_uses) for instr in instrs]
    if len(instrs) < 2:
        return instrs
    goto_cond = instrs[-2]
    inc_block = instrs[-1]
    if not isinstance(goto_cond, instructions.Goto):
        return instrs
    if not isinstance(inc_block, instructions.LabeledBlock):
        return instrs
    inc_instrs = inc_block.instructions
    if len(inc_instrs) != 2:
        return instrs
    increment, cond_block = inc_instrs
    if not isinstance(increment, (
        instructions.CodeInstruction, instructions.Assignment
    )):
        return instrs
    if not isinstance(cond_block, instructions.LabeledBlock):
        return instrs
    if cond_block.label != goto_cond.label:
        return instrs
    if_instr = cond_block.instructions[0]
    if not isinstance(if_instr, instructions.IfInstruction):
        return instrs
    if if_instr.else_block is not None or not if_instr.if_block:
        return instrs
    goto_inc = if_instr.if_block[-1]
    if not isinstance(goto_inc, instructions.Goto):
        return instrs
    if goto_inc.label != inc_block.label:
        return instrs
    if label_uses.get(cond_block.label) != {goto_cond}:
        return instrs
    if label_uses.get(inc_block.label) != {goto_inc}:
        return instrs
    prefix = instrs[:-2]
    init = None
    if prefix and _is_init(prefix[-1], increment):
        init = prefix.pop()
    for_instr = instructions.ForInstruction(
        init, if_instr.if_clause, increment, if_instr.if_block[:-1])
    return prefix + [for_instr] + cond_block.instructions[1:]


def _is_init(instr, increment):
    """Check if instruction assigns a variable used in increment."""
    if not isinstance(instr, instructions.Assignment):
        return False
    variable = instr.dst.emit_code()
    used = []
    increment.visit(lambda e, **kwargs: used.append(e))
    return any(
        not isinstance(e, instructions.Assignment) and
        e.emit_code() == variable
        for e in used
    )


def _transform_nested(instr, label_uses):
    if isinstance(instr, instructions.IfInstruction):
        else_block = instr.else_block
        if else_block is not None:
            else_block = _transform_block(else_block, label_uses)
        return instructions.IfInstruction(
            instr.if_clause,
            _transform_block(instr.if_block, label_uses),
            else_block,
        )
    if isinstance(instr, instructions.WhileInstruction):
        return instructions.WhileInstruction(
            instr.clause, _transform_block(instr.block, label_uses))
    if isinstance(instr, instructions.ForInstruction):
        return instr.copy(block=_transform_block(instr.block, label_uses))
    if isinstance(instr, instructions.LabeledBlock):
        return instructions.LabeledBlock(
            instr.label, _transform_block(instr.instructions, label_uses))
    if isinstance(instr, instructions.Switch):
        for label, block in instr.blocks_dict.items():
            instr.blocks_dict[label] = _transform_block(block, label_uses)
    return instr
