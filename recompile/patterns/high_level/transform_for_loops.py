import expressions
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

    or, if the block ends with a jump, to

        ...
    cond_label:
        if (!clause)
        {
            goto end_label;
        }
        block
    continue_label:
        goto inc_label;
    end_label:
        ...

    Arrays of objects are constructed with 'while (--count >= 0)' loops:

    label:
        count--;
        if (count >= 0)
        {
            block
            goto label;
        }
        ...
    """
    label_uses = collect_label_uses(instrs)
    return _transform_block(instrs, label_uses)


def _transform_block(instrs, label_uses):
    instrs = [_transform_nested(instr, label_uses) for instr in instrs]
    for transform in (_transform_for, _transform_decrement_while):
        new_instrs = transform(instrs, label_uses)
        if new_instrs is not None:
            return new_instrs
    return instrs


def _transform_for(instrs, label_uses):
    if len(instrs) < 2:
        return None
    goto_cond = instrs[-2]
    inc_block = instrs[-1]
    if not isinstance(goto_cond, instructions.Goto):
        return None
    if not isinstance(inc_block, instructions.LabeledBlock):
        return None
    inc_instrs = inc_block.instructions
    if len(inc_instrs) != 2:
        return None
    increment, cond_block = inc_instrs
    if not isinstance(increment, (
        instructions.CodeInstruction, instructions.Assignment
    )):
        return None
    if not isinstance(cond_block, instructions.LabeledBlock):
        return None
    if cond_block.label != goto_cond.label:
        return None
    if label_uses.get(cond_block.label) != {goto_cond}:
        return None
    loop = (
        _match_loop_with_jump_back(cond_block, inc_block.label, label_uses) or
        _match_loop_with_exit(cond_block, inc_block.label, label_uses)
    )
    if loop is None:
        return None
    clause, block, rest = loop
    label_uses[cond_block.label].discard(goto_cond)
    prefix = instrs[:-2]
    init = None
    if prefix and _is_init(prefix[-1], increment):
        init = prefix.pop()
    for_instr = instructions.ForInstruction(init, clause, increment, block)
    return prefix + [for_instr] + rest


def _match_loop_with_jump_back(cond_block, inc_label, label_uses):
    """Match 'if (clause) { block; goto inc_label; } rest'."""
    if_instr = cond_block.instructions[0]
    if not isinstance(if_instr, instructions.IfInstruction):
        return None
    if if_instr.else_block is not None or not if_instr.if_block:
        return None
    goto_inc = if_instr.if_block[-1]
    if not isinstance(goto_inc, instructions.Goto):
        return None
    if goto_inc.label != inc_label:
        return None
    if label_uses.get(inc_label) != {goto_inc}:
        return None
    label_uses[inc_label].discard(goto_inc)
    return (
        if_instr.if_clause,
        if_instr.if_block[:-1],
        cond_block.instructions[1:],
    )


def _match_loop_with_exit(cond_block, inc_label, label_uses):
    """Match 'if (!clause) goto end; block; goto inc_label; end: rest'."""
    exit_if = cond_block.instructions[0]
    if not isinstance(exit_if, instructions.IfInstruction):
        return None
    if exit_if.else_block is not None or len(exit_if.if_block) != 1:
        return None
    goto_end = exit_if.if_block[0]
    if not isinstance(goto_end, instructions.Goto):
        return None
    tail = _cut_tail(cond_block.instructions[1:], inc_label, goto_end.label)
    if tail is None:
        return None
    block, goto_inc, end_block = tail
    if label_uses.get(inc_label) != {goto_inc}:
        return None
    label_uses[inc_label].discard(goto_inc)
    label_uses[goto_end.label].discard(goto_end)
    block = _replace_continue_label(block, label_uses)
    block = _replace_gotos(
        block, end_block.label, instructions.Break, label_uses)
    if label_uses[end_block.label]:
        rest = [end_block]
    else:
        rest = end_block.instructions
    return expressions.do_logical_not(exit_if.if_clause), block, rest


def _cut_tail(block, inc_label, end_label):
    """Cut 'goto inc_label; end_label: ...' from the end of the block.

    The tail can be inside nested labeled blocks at the end of the block.
    """
    if len(block) >= 2:
        goto_inc, end_block = block[-2:]
        if (
            isinstance(goto_inc, instructions.Goto) and
            goto_inc.label == inc_label and
            isinstance(end_block, instructions.LabeledBlock) and
            end_block.label == end_label
        ):
            return block[:-2], goto_inc, end_block
    if block and isinstance(block[-1], instructions.LabeledBlock):
        tail = _cut_tail(block[-1].instructions, inc_label, end_label)
        if tail is None:
            return None
        inner_block, goto_inc, end_block = tail
        labeled_block = instructions.LabeledBlock(
            block[-1].label, inner_block)
        return block[:-1] + [labeled_block], goto_inc, end_block
    return None


def _replace_continue_label(block, label_uses):
    """Replace jumps to the end of the block with 'continue'.

    The end of the block is the empty labeled block at the end of nested
    labeled blocks at the end of the block.
    """
    label = _find_end_label(block)
    if label is None:
        return block
    block = _remove_end_label(block)
    block = _replace_gotos(block, label, instructions.Continue, label_uses)
    if label_uses.get(label):
        block = block + [
            instructions.LabeledBlock(label, [instructions.empty])]
    return block


def _find_end_label(block):
    if not block or not isinstance(block[-1], instructions.LabeledBlock):
        return None
    inner_block = block[-1].instructions
    if not inner_block:
        return block[-1].label
    return _find_end_label(inner_block)


def _remove_end_label(block):
    labeled_block = block[-1]
    inner_block = labeled_block.instructions
    if not inner_block:
        return block[:-1]
    return block[:-1] + [instructions.LabeledBlock(
        labeled_block.label, _remove_end_label(inner_block))]


def _replace_gotos(block, label, make_instr, label_uses):
    """Replace jumps to the label out of nested loops and switches."""
    new_block = []
    for instr in block:
        if isinstance(instr, instructions.Goto) and instr.label == label:
            label_uses[label].discard(instr)
            new_block.append(make_instr())
        elif isinstance(instr, instructions.IfInstruction):
            else_block = instr.else_block
            if else_block is not None:
                else_block = _replace_gotos(
                    else_block, label, make_instr, label_uses)
            new_block.append(instructions.IfInstruction(
                instr.if_clause,
                _replace_gotos(instr.if_block, label, make_instr, label_uses),
                else_block,
            ))
        elif isinstance(instr, instructions.LabeledBlock):
            new_block.append(instructions.LabeledBlock(
                instr.label,
                _replace_gotos(
                    instr.instructions, label, make_instr, label_uses),
            ))
        else:
            new_block.append(instr)
    return new_block


def _transform_decrement_while(instrs, label_uses):
    """Transform 'label: count--; if (count >= 0) { ...; goto label; }'."""
    if not instrs or not isinstance(instrs[-1], instructions.LabeledBlock):
        return None
    labeled_block = instrs[-1]
    labeled_instrs = labeled_block.instructions
    if len(labeled_instrs) < 2:
        return None
    decrement, if_instr = labeled_instrs[:2]
    if not isinstance(decrement, instructions.CodeInstruction):
        return None
    if not isinstance(decrement.expression, expressions.Decrement):
        return None
    if not isinstance(if_instr, instructions.IfInstruction):
        return None
    if if_instr.else_block is not None or not if_instr.if_block:
        return None
    goto_label = if_instr.if_block[-1]
    if not isinstance(goto_label, instructions.Goto):
        return None
    if goto_label.label != labeled_block.label:
        return None
    if label_uses.get(labeled_block.label) != {goto_label}:
        return None
    clause = if_instr.if_clause
    variable = decrement.expression.expression
    if not isinstance(clause, expressions.Bin):
        return None
    if clause.left.emit_code() != variable.emit_code():
        return None
    label_uses[labeled_block.label].discard(goto_label)
    clause = expressions.Bin(
        clause.operator, expressions.PreDecrement(clause.left), clause.right)
    while_instr = instructions.WhileInstruction(
        clause, if_instr.if_block[:-1])
    return instrs[:-1] + [while_instr] + labeled_instrs[2:]


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
