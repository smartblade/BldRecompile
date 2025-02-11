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
    while switch.has_label(labeled_block.label):
        labeled_instrs = labeled_block.instructions
        last_instr = labeled_instrs[-1]
        if not isinstance(last_instr, instructions.LabeledBlock):
            break
        labeled_instrs.pop()
        switch_block = [
            instructions.LabeledBlock(labeled_block.label, labeled_instrs)]
        old_block = switch.set_block(labeled_block.label, switch_block)
        assert len(old_block) == 1
        goto_instr = old_block[0]
        assert isinstance(goto_instr, instructions.Goto)
        label_uses[goto_instr.label].remove(goto_instr)
        eliminate_unused_label(switch_block, label_uses)
        labeled_block = last_instr
    instrs = instrs[:-1]
    instrs.append(labeled_block)
    return instrs
