import expressions
from expressions.operator import Operator
import instructions

from .convert_expression_to_type import convert_expression_to_type


def transform_assignment(dst, src, **kwargs):
    new_src = convert_expression_to_type(src, dst.data_type)
    result = _try_make_increment(dst, new_src)
    if result is not None:
        return result
    if new_src == src:
        return None
    return instructions.Assignment(dst, new_src)


def _try_make_increment(dst, src):
    if not isinstance(dst, expressions.Identifier):
        return None
    if not isinstance(src, expressions.Bin):
        return None
    if src.operator == Operator.ADD:
        negative = False
    elif src.operator == Operator.SUB:
        negative = True
    else:
        return None
    left = src.left
    if not left.data_type.is_any_int:
        return None
    right = src.right
    if not right.data_type.is_any_int:
        return None
    if not isinstance(right, expressions.Constant):
        return None
    if right.value != 1:
        return None
    if dst.emit_code() != left.emit_code():
        return None
    if negative:
        inc_or_dec = expressions.Decrement
    else:
        inc_or_dec = expressions.Increment
    return instructions.CodeInstruction(inc_or_dec(dst))
