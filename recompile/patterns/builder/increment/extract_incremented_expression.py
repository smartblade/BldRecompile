import expressions
from expressions.operator import Operator


def extract_incremented_expression(ass):
    b = ass.src
    if not isinstance(b, expressions.Bin):
        return None
    increment_operator = b.operator
    if (
        increment_operator != Operator.ADD and
        increment_operator != Operator.SUB
    ):
        return None
    if not b.left.data_type.is_any_int:
        return None
    if not b.right.data_type.is_any_int:
        return None
    right_const = b.right
    if not isinstance(right_const, expressions.Constant):
        return None
    left_cast = b.left
    if not isinstance(left_cast, expressions.ReinterpretCast):
        return None
    dst = ass.dst
    if not isinstance(dst, expressions.intermediate.Stackvar):
        return None
    left = left_cast.expression
    if not isinstance(left, expressions.intermediate.Stackvar):
        return None
    if dst.emit_code() != left.emit_code():
        return None
    if increment_operator == Operator.ADD:
        step = right_const.value
    else:
        step = -right_const.value
    return dst, step
