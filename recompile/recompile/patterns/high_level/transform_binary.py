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
        if bin_exp.operator == Operator.BIT_AND:
            return _transform_bit_and(bin_exp.left, bin_exp.right) or bin_exp
    if bin_exp.operator == Operator.EQ or bin_exp.operator == Operator.NE:
        return _transform_eq_ne(
            bin_exp.operator, bin_exp.left, bin_exp.right) or bin_exp
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
    if not isinstance(
        left.expression.data_type, (data_types.Pointer32, data_types.Reference)
    ):
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


def _transform_eq_ne(operator, left, right):
    if (
        isinstance(left.data_type, (data_types.Float, data_types.Double)) and
        isinstance(right.data_type, (data_types.Float, data_types.Double))
    ):
        return None
    right = expressions.do_reinterpret(left.data_type, right)
    if not isinstance(right, expressions.ConstantTypes):
        left = expressions.do_reinterpret(right.data_type, left)
    return expressions.Bin(operator, left, right)


def _transform_bit_and(left, right):
    if not isinstance(right, expressions.Constant):
        return None
    if right.value != 0xFF:
        return None
    src_type = data_types.UChar()
    if not isinstance(left, expressions.ReinterpretCast):
        return None
    pc = left.expression
    if not isinstance(pc, expressions.ProcedureCall):
        return None
    if not pc.is_predefined or pc.name != "TRASHEXTEND":
        return None
    assert len(pc.arguments) == 1
    expression = pc.arguments[0]
    if not expression.data_type.is_any_int:
        return None
    if expression.data_type.size != src_type.size:
        return None
    return expressions.do_static_cast(
        left.data_type,
        expressions.do_reinterpret(src_type, expression),
    )
