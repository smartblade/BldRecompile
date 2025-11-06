import expressions
import instructions


def call_instr(*args, **kwargs):
    call = expressions.ProcedureCall(*args, **kwargs)
    return instructions.CodeInstruction(call)


def ass(*args, **kwargs):
    return instructions.Assignment(*args, **kwargs)


def if_instr(*args, **kwargs):
    return instructions.IfInstruction(*args, **kwargs)
