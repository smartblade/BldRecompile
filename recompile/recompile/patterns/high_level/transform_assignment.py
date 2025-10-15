import expressions
from expressions.operator import Operator
import instructions
import patterns.high_level.inline_functions as inline_functions

from .convert_expression_to_type import convert_expression_to_type


def transform_assignment(dst, src, analysis, **kwargs):
    new_src = convert_expression_to_type(src, dst.data_type)
    result = _try_make_increment(dst, new_src)
    if result is not None:
        return result
    analysis.process_assignment(dst, new_src)
    result = inline_functions.transform_assignment(dst, new_src)
    if result is not None:
        return result
    if new_src == src:
        return None
    return instructions.Assignment(dst, new_src)


def _try_make_increment(dst, src):
    if not isinstance(dst, (expressions.Identifier, expressions.FieldAccess)):
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
    if dst.emit_code() != left.emit_code():
        return None
    return _make_inc_or_dec(dst, right, negative)


def _make_inc_or_dec(dst, offset, is_negative):
    if isinstance(offset, expressions.Constant) and offset.value == 1:
        if is_negative:
            inc_or_dec = expressions.Decrement
        else:
            inc_or_dec = expressions.Increment
        expression = inc_or_dec(dst)
    else:
        if is_negative:
            expression = expressions.Bin(Operator.SUB_ASS, dst, offset)
        else:
            expression = expressions.Bin(Operator.ADD_ASS, dst, offset)
    return instructions.CodeInstruction(expression)
