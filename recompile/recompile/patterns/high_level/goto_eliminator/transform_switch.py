import instructions

from .eliminate_unused_label import eliminate_unused_label


def transform_switch_statements(instrs, label_uses, **kwargs):
    if len(instrs) <= 1:
        return instrs
    labeled_block = instrs[-1]
    if not isinstance(labeled_block, instructions.LabeledBlock):
        return instrs
    switch = instrs[-2]
    if not isinstance(switch, instructions.Switch):
        return instrs
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
