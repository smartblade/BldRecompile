import data_types
import expressions
from expressions.operator import Operator


def evaluate_expression(e):
    result = _evaluate_constant(e)
    if result is not None:
        return result
    result = _evaluate_binary(e)
    if result is not None:
        return result
    raise Exception("Can't evaluate {}".format(e))


def _evaluate_constant(c):
    if not isinstance(c, expressions.Constant):
        return None
    if (
        c.data_type.is_any_int or
        isinstance(c.data_type, data_types.UnknownTypes)
    ):
        return c
    return None


def _evaluate_binary(b):
    if not isinstance(b, expressions.Bin):
        return None
    left = evaluate_expression(b.left)
    right = evaluate_expression(b.right)
    max_size = max(left.data_type.size, right.data_type.size)
    data_type = data_types.AnyInt(max_size)
    if b.operator == Operator.MUL:
        return expressions.Constant(data_type, left.value * right.value)
    if b.operator == Operator.SUB:
        return expressions.Constant(data_type, left.value - right.value)
    if b.operator == Operator.SHL:
        return expressions.Constant(data_type, left.value << right.value)
    return None
