import data_types
import expressions
from expressions.operator import Operator

from .transform_access import transform_access


def transform_binary(bin_exp, **kwargs):
    if bin_exp.operator == Operator.ADD:
        return _transform_sum(bin_exp.left, bin_exp.right) or bin_exp
    return bin_exp


def _transform_sum(left, right):
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
