import instructions


def collect_label_uses(instrs):
    uses = {}
    for instr in instrs:
        instr.visit(_visit, uses=uses)
    return uses


def _visit(e, uses):
    if isinstance(e, instructions.Goto):
        label_uses = uses.get(e.label, set())
        label_uses.add(e)
        uses[e.label] = label_uses
