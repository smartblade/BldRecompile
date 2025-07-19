import expressions
from expressions.operator import priorities, is_associative

from .get_writeable_expression import get_writeable_expression


def write_binary(operator, left, right):
    left = get_writeable_expression(left)
    right = get_writeable_expression(right)
    return "{} {} {}".format(
        _emit_left(operator, left).emit_code(),
        operator.value,
        _emit_right(operator, right).emit_code(),
    )


def _emit_left(operator, left):
    if not isinstance(left, expressions.Bin):
        return left
    if priorities[operator] >= priorities[left.operator]:
        return left
    return expressions.BracketsExpression(left)


def _emit_right(operator, right):
    if not isinstance(right, expressions.Bin):
        return right
    if priorities[operator] > priorities[right.operator]:
        return right
    if priorities[operator] < priorities[right.operator]:
        return expressions.BracketsExpression(right)
    if is_associative[operator]:
        return right
    else:
        return expressions.BracketsExpression(right)
