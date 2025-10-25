import data_types
import expressions
from expressions.operator import Operator

from .call_characteristics import get_call_characteristics
from .transform_access import do_pointer_dereference


def transform_binary(operator, left, right, analysis, **kwargs):
    analysis.process_binary(operator, left, right)
    if _is_integer_operation(left, right):
        if operator == Operator.ADD:
            return _transform_int_sum(left, right)
        if operator == Operator.MUL:
            return _transform_int_mul(left, right)
        if operator == Operator.BIT_AND:
            return _transform_bit_and(left, right)
    if operator == Operator.EQ or operator == Operator.NE:
        return _transform_eq_ne(operator, left, right, **kwargs)
    return None


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
    e = do_pointer_dereference(left.expression, right.value, None)
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


def _transform_eq_ne(operator, left, right, **kwargs):
    result = _try_cast_to_bool(operator, left, right, **kwargs)
    if result is not None:
        return result
    if (
        isinstance(left.data_type, (data_types.Float, data_types.Double)) and
        isinstance(right.data_type, (data_types.Float, data_types.Double))
    ):
        return None
    right = expressions.do_reinterpret(left.data_type, right)
    if not isinstance(right, expressions.ConstantTypes):
        left = expressions.do_reinterpret(right.data_type, left)
    return expressions.Bin(operator, left, right)


def _try_cast_to_bool(operator, left, right, declarations, **kwargs):
    if not isinstance(left, expressions.ProcedureCall):
        return None
    if not left.data_type.is_any_int:
        return None
    if not isinstance(right, expressions.Constant):
        return None
    if not right.data_type.is_any_int:
        return None
    if right.value != 0:
        return None
    characteristics = get_call_characteristics(declarations, left)
    if characteristics.is_boolean_return:
        if operator == Operator.NE:
            return left
        elif operator == Operator.EQ:
            return expressions.LogicalNot(left)
    return None


def _transform_bit_and(left, right):
    if not isinstance(right, expressions.Constant):
        return None
    if right.value != 0xFF:
        return None
    src_type = data_types.UChar()
    if not isinstance(left, expressions.ReinterpretCast):
        return None
    trash_extend = left.expression
    if not isinstance(trash_extend, expressions.intermediate.TrashExtend):
        return None
    expression = trash_extend.expression
    if not expression.data_type.is_any_int:
        return None
    if expression.data_type.size != src_type.size:
        return None
    return expressions.do_static_cast(
        left.data_type,
        expressions.do_reinterpret(src_type, expression),
    )
