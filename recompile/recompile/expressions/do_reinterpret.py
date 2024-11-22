import data_types
import expressions
from expressions.operator import Operator


def do_reinterpret(data_type, e):
    if data_types.are_compatible(e.data_type, data_type):
        return e
    if isinstance(e, expressions.Constant):
        return _reinterpret_const(data_type, e)
    if isinstance(e, expressions.ReinterpretCast):
        return _eliminate_reinterpret(data_type, e)
    result = _reinterpret_bin(data_type, e)
    if result is not None:
        return result
    return expressions.ReinterpretCast(data_type, e)


def _reinterpret_const(data_type, c):
    if (
        isinstance(data_type, data_types.Int32) and
        isinstance(c.data_type, (data_types.AnyInt, data_types.Unknown32)) and
        data_type.size == c.data_type.size
    ):
        if c.value < 0x80000000:
            return expressions.Constant(data_type, c.value)
        else:
            return expressions.Constant(data_type, c.value - 0x100000000)
    if (
        isinstance(data_type, (data_types.UInt32, data_types.UChar)) and
        isinstance(
            c.data_type, (data_types.AnyInt, data_types.UnknownTypes)) and
        data_type.size == c.data_type.size
    ):
        return expressions.Constant(data_type, c.value)
    if (
        isinstance(data_type, data_types.AnyInt) and
        isinstance(c.data_type, data_types.Unknown32) and
        data_type.size == c.data_type.size
    ):
        return expressions.Constant(data_type, c.value)
    if (
        isinstance(data_type, data_types.Pointer32) and
        isinstance(c.data_type, data_types.Unknown32) and
        c.value == 0
    ):
        return expressions.Null
    raise Exception(
        "Unimplemented reinterpret cast from {} to {}".format(
            c.data_type, data_type))


def _eliminate_reinterpret(data_type, cast):
    return do_reinterpret(data_type, cast.expression)


def _reinterpret_bin(data_type, b):
    if not isinstance(b, expressions.Bin):
        return None
    if data_types.are_compatible(b.data_type, data_type):
        return b
    if not data_type.is_any_int:
        return None
    if not b.left.data_type.is_any_int:
        return None
    if not b.right.data_type.is_any_int:
        return None
    if (
        b.operator != Operator.ADD and
        b.operator != Operator.SUB and
        b.operator != Operator.MUL
    ):
        return None
    left = b.left
    right = b.right
    if isinstance(right, expressions.Constant):
        left = do_reinterpret(data_type, left)
        return expressions.Bin(b.operator, left, right)
    if isinstance(left, expressions.Constant):
        right = do_reinterpret(data_type, right)
        return expressions.Bin(b.operator, left, right)
    if isinstance(left, expressions.Bin):
        left = _reinterpret_bin(data_type, left)
        if left is None:
            return None
    if isinstance(right, expressions.Bin):
        right = _reinterpret_bin(data_type, right)
        if right is None:
            return None
    if (
        isinstance(left, (expressions.Bin, expressions.ReinterpretCast)) and
        isinstance(right, (expressions.Bin, expressions.ReinterpretCast))
    ):
        left = do_reinterpret(data_type, left)
        right = do_reinterpret(data_type, right)
        return expressions.Bin(b.operator, left, right)
    return None
