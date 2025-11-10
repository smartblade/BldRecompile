import data_types
import expressions
from expressions.operator import Operator
import instructions

from .eliminate_unused_label import eliminate_unused_label


def transform_switch_statements(instrs, label_uses, stack_vars, **kwargs):
    if len(instrs) <= 1:
        return instrs
    if not isinstance(instrs[-1], instructions.LabeledBlock):
        return instrs
    if not isinstance(instrs[-2], instructions.Switch):
        return instrs
    instrs = _apply_range_guard(instrs, 2, label_uses) or instrs
    instrs = _eliminate_switch_index_assignment(instrs, stack_vars)
    labeled_block = instrs[-1]
    assert isinstance(labeled_block, instructions.LabeledBlock)
    switch = instrs[-2]
    assert isinstance(switch, instructions.Switch)
    following_label_status = _FollowingLabelStatus()
    while switch.has_label(labeled_block.label):
        labeled_instrs = labeled_block.instructions
        last_instr = labeled_instrs[-1]
        if not isinstance(last_instr, instructions.LabeledBlock):
            break
        labeled_instrs.pop()
        following_label_status.add_last_instruction(labeled_instrs[-1])
        switch_block = [
            instructions.LabeledBlock(labeled_block.label, labeled_instrs)]
        old_block = switch.set_block(labeled_block.label, switch_block)
        assert len(old_block) == 1
        goto_instr = old_block[0]
        assert isinstance(goto_instr, instructions.Goto)
        label_uses[goto_instr.label].remove(goto_instr)
        eliminate_unused_label(switch_block, label_uses)
        labeled_block = last_instr
        assert labeled_block.label is not None
        if labeled_block.label == following_label_status.label:
            break
    instrs = instrs[:-1]
    instrs.append(labeled_block)
    return _replace_goto_to_break(instrs, following_label_status, label_uses)


def _as_if_single_goto_instr(if_instruction):
    if not isinstance(if_instruction, instructions.IfInstruction):
        return None
    if if_instruction.else_block is not None:
        return None
    if len(if_instruction.if_block) != 1:
        return None
    goto_instr = if_instruction.if_block[-1]
    if not isinstance(goto_instr, instructions.Goto):
        return None
    return goto_instr


def _apply_range_guard(instrs, switch_index, label_uses):
    switch = instrs[-switch_index]
    assert isinstance(switch, instructions.Switch)
    if switch.default_label is not None:
        return None
    index = switch_index + 1
    if len(instrs) < index:
        return None
    range_guard = instrs[-index]
    default_goto = _as_if_single_goto_instr(range_guard)
    if default_goto is None:
        return None
    range_diff = _extract_switch_range_diff(
        range_guard.if_clause, switch.index)
    if range_diff is None:
        return None
    index += 1
    if len(instrs) < index:
        return None
    ass = instrs[-index]
    if not isinstance(ass, instructions.Assignment):
        return None
    cases_offset = _extract_cases_offset(ass, switch.index)
    if cases_offset is not None:
        index += 1
    new_instrs = instrs[:-index + 1]
    new_switch = switch.copy(
        default_label=default_goto.label,
        cases_offset=cases_offset,
    )
    new_switch.validate_cases(cases_offset, range_diff)
    label_uses[default_goto.label].remove(default_goto)
    if not switch.has_label(default_goto.label):
        new_default_block = new_switch.blocks_dict[default_goto.label]
        assert len(new_default_block) == 1
        new_default_goto = new_default_block[0]
        assert isinstance(new_default_goto, instructions.Goto)
        label_uses[new_default_goto.label].add(new_default_goto)
    new_instrs.append(new_switch)
    new_instrs.extend(instrs[-switch_index + 1:])
    return new_instrs


def _is_switch_index(e, switch_index):
    if not isinstance(e, expressions.intermediate.Stackvar):
        return False
    if e.offset != switch_index.offset:
        return False
    if e.size != switch_index.size:
        return False
    return True


def _extract_switch_range_diff(if_clause, switch_index):
    if not isinstance(if_clause, expressions.Bin):
        return None
    if if_clause.operator != Operator.GT:
        return None
    left = if_clause.left
    if not isinstance(left, expressions.ReinterpretCast):
        return None
    if not isinstance(left.data_type, data_types.UInt32):
        return None
    if not _is_switch_index(left.expression, switch_index):
        return None
    const = if_clause.right
    if not isinstance(const, expressions.Constant):
        return None
    if not isinstance(const.data_type, data_types.UInt32):
        return None
    assert isinstance(const.value, int)
    return const.value


def _extract_cases_offset(ass, switch_index):
    if not _is_switch_index(ass.dst, switch_index):
        return None
    src = ass.src
    if not isinstance(src, expressions.Bin):
        return None
    if src.operator == Operator.SUB:
        negate = False
    elif src.operator == Operator.ADD:
        negate = True
    else:
        return None
    left = src.left
    if not isinstance(left, expressions.ReinterpretCast):
        return None
    if not isinstance(left.data_type, data_types.AnyInt):
        return None
    if not _is_switch_index(left.expression, switch_index):
        return None
    const = src.right
    if not isinstance(const, expressions.Constant):
        return None
    if not const.data_type.is_any_int:
        return None
    assert isinstance(const.value, int)
    value = const.value
    if negate:
        value = -value
    return value


def _eliminate_switch_index_assignment(instrs, stack_vars):
    labeled_block = instrs[-1]
    switch = instrs[-2]
    switch_index_ass = instrs[-3]
    assert isinstance(switch, instructions.Switch)
    assert isinstance(switch_index_ass, instructions.Assignment)
    switch_index_ass_dst = switch_index_ass.dst
    assert isinstance(
        switch_index_ass_dst, expressions.intermediate.Stackvar)
    switch_index = switch.index
    assert isinstance(switch_index, expressions.intermediate.Stackvar)
    assert switch_index.offset == switch_index_ass_dst.offset
    assert switch_index.size == switch_index_ass_dst.size
    assert switch_index.offset not in stack_vars
    stack_vars[switch_index.offset] = expressions.Identifier(
        switch_index.data_type, "__switch_index")
    new_instrs = instrs[:-3]
    new_instrs.append(switch.copy(switch_index_ass.src))
    new_instrs.append(labeled_block)
    return new_instrs


def _replace_goto_to_break(instrs, following_label_status, label_uses):
    if following_label_status.label is None:
        return instrs
    labeled_block = instrs[-1]
    if not isinstance(labeled_block, instructions.LabeledBlock):
        return instrs
    switch = instrs[-2]
    if not isinstance(switch, instructions.Switch):
        return instrs
    if labeled_block.label != following_label_status.label:
        return instrs
    for label, block in list(switch.blocks_dict.items()):
        new_block = _replace_goto_to_break_at_block(
            block, label_uses, following_label_status.label)
        switch.set_block(label, new_block)
    _add_break_to_last_block(next(reversed(switch.blocks_dict.values())))
    _eliminate_empty_default_block(switch, following_label_status.label)
    eliminate_unused_label(instrs, label_uses)
    return instrs


def _add_break_to_last_block(last_block):
    last_instr = last_block[-1]
    if isinstance(last_instr, instructions.Goto):
        return
    if isinstance(last_instr, instructions.Break):
        return
    if isinstance(last_instr, instructions.ReturnInstruction):
        return
    last_block.append(instructions.Break())


def _eliminate_empty_default_block(switch, following_label):
    if switch.default_label is None:
        return
    if switch.default_label != following_label:
        return
    switch.eliminate_empty_default_block()


def _replace_goto_to_break_at_block(block, label_uses, following_label):
    new_instructions = []
    for instr in block:
        if isinstance(instr, instructions.IfInstruction):
            if_block = _replace_goto_to_break_at_block(
                instr.if_block, label_uses, following_label)
            else_block = None
            if instr.else_block is not None:
                else_block = _replace_goto_to_break_at_block(
                    instr.else_block, label_uses, following_label)
            new_instructions.append(
                instructions.IfInstruction(
                    instr.if_clause, if_block, else_block))
        elif (
            isinstance(instr, instructions.Goto) and
            instr.label == following_label
        ):
            label_uses[instr.label].remove(instr)
            new_instructions.append(instructions.Break())
        else:
            new_instructions.append(instr)
    return new_instructions


class _FollowingLabelStatus:
    def __init__(self):
        self._following_label = None
        self._valid_following_label = True

    @property
    def label(self):
        if not self._valid_following_label:
            return None
        return self._following_label

    def add_last_instruction(self, last_instr):
        if not isinstance(last_instr, instructions.Goto):
            return
        if (
            self._following_label is not None and
            last_instr.label != self._following_label
        ):
            self._valid_following_label = False
        self._following_label = last_instr.label
