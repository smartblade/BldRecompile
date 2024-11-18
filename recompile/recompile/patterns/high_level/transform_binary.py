import data_types
import expressions
from expressions.operator import Operator

from .transform_access import transform_access


def transform_binary(bin_exp, **kwargs):
    if _is_integer_operation(bin_exp.left, bin_exp.right):
        if bin_exp.operator == Operator.ADD:
            return _transform_int_sum(bin_exp.left, bin_exp.right) or bin_exp
        if bin_exp.operator == Operator.MUL:
            return _transform_int_mul(bin_exp.left, bin_exp.right) or bin_exp
        if bin_exp.operator == Operator.NE:
            return _transform_int_ne(bin_exp.left, bin_exp.right) or bin_exp
    return bin_exp


def _is_integer_operation(left, right):
    return left.data_type.is_any_int and right.data_type.is_any_int


def _transform_int_sum(left, right):
    if not isinstance(left.data_type, data_types.AnyInt):
        return None
    if not isinstance(right.data_type, data_types.AnyInt):
        return None
    if not isinstance(left, expressions.ReinterpretCast):
        return None
    if not isinstance(right, expressions.Constant):
        return None
    e = transform_access(left.expression, right.value, None)
    if e is None:
        return None
    return expressions.AddressOf(e)


def _transform_int_mul(left, right):
    if not isinstance(left, expressions.Constant):
        return None
    if (
        not data_types.are_same(left.data_type, right.data_type) and
        left.data_type.size == right.data_type.size
    ):
        left = expressions.do_reinterpret(right.data_type, left)
        return expressions.Bin(Operator.MUL, left, right)
    return None


def _transform_int_ne(left, right):
    if not isinstance(right, expressions.Constant):
        return None
    right = expressions.do_reinterpret(left.data_type, right)
    return expressions.Bin(Operator.NE, left, right)
