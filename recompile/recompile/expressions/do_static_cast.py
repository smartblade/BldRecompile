import data_types
import expressions
from expressions.operator import Operator


def do_static_cast(data_type, e):
    if data_types.are_same(e.data_type, data_type):
        return e
    if (
        data_types.are_compatible(e.data_type, data_type) and
        e.data_type.is_any_int and data_type.is_any_int
    ):
        return e
    result = _cast_bin(data_type, e)
    if result is not None:
        return result
    result = _cast_cast(data_type, e)
    if result is not None:
        return result
    return expressions.StaticCast(data_type, e)


def _cast_cast(data_type, c):
    if not isinstance(c, expressions.StaticCast):
        return None
    if not data_type.is_any_int:
        return None
    if not c.data_type.is_any_int:
        return None
    if not c.expression.data_type.is_any_int:
        return None
    if data_type.size > c.data_type.size:
        return None
    return do_static_cast(data_type, c.expression)


def _cast_bin(data_type, b):
    if not isinstance(b, expressions.Bin):
        return None
    if not data_type.is_any_int:
        return None
    if not b.left.data_type.is_any_int:
        return None
    if not b.right.data_type.is_any_int:
        return None
    if data_type.size > b.data_type.size:
        return None
    if (
        b.operator != Operator.ADD and
        b.operator != Operator.SUB and
        b.operator != Operator.MUL
    ):
        return None
    left = b.left
    right = b.right
    if (
        isinstance(left, expressions.StaticCast) and
        isinstance(right, expressions.StaticCast)
    ):
        left = do_static_cast(data_type, left)
        right = do_static_cast(data_type, right)
        return expressions.Bin(b.operator, left, right)
    return None
