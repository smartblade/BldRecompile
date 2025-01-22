import instructions


def transform_while(label, instrs, label_uses, **kwargs):
    first = instrs[0]
    if not isinstance(first, instructions.IfInstruction):
        return
    if first.else_block is not None:
        return
    goto_instr = first.if_block[-1]
    if not isinstance(goto_instr, instructions.Goto):
        return
    if goto_instr.label != label:
        return
    label_uses[goto_instr.label].remove(goto_instr)
    instrs[0] = instructions.WhileInstruction(
        first.if_clause,
        first.if_block[:-1],
    )
