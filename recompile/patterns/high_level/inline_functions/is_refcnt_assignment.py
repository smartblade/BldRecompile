import expressions
import instructions

from .is_int_constant import is_int_constant
from .obj_from_field_access import try_extract_obj_from_field_access


def is_refcnt_assignment(instr, obj, int_const, operator):
    if not isinstance(instr, instructions.CodeInstruction):
        return False
    e = instr.expression
    if isinstance(e, expressions.Increment):
        inc_operator = operator.ADD
    elif isinstance(e, expressions.Decrement):
        inc_operator = operator.SUB
    else:
        return False
    incremented_expression = e.expression
    if inc_operator != operator:
        return False
    if int_const != 1:
        return False
    expression_obj = try_extract_obj_from_field_access(
        incremented_expression, "ob_refcnt")
    if expression_obj is None:
        return False
    if obj.emit_code() != expression_obj.emit_code():
        return False
    return True
