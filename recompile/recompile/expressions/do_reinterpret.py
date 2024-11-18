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
    if not data_type.is_any_int:
        return None
    if not b.left.data_type.is_any_int:
        return None
    if not b.right.data_type.is_any_int:
        return None
    if b.operator != Operator.ADD and b.operator != Operator.SUB:
        return None
    if isinstance(b.right, expressions.Constant):
        left = do_reinterpret(data_type, b.left)
        return expressions.Bin(b.operator, left, b.right)
    if (
        isinstance(b.left, expressions.ReinterpretCast) and
        isinstance(b.right, expressions.ReinterpretCast)
    ):
        left = do_reinterpret(data_type, b.left)
        right = do_reinterpret(data_type, b.right)
        return expressions.Bin(b.operator, left, right)
    return None
