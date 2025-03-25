import data_types
import expressions
from expressions.operator import Operator


def evaluate_expression(e, **kwargs):
    result = _evaluate_constant(e)
    if result is not None:
        return result
    result = _evaluate_binary(e, **kwargs)
    if result is not None:
        return result
    result = _evaluate_strlen(e, **kwargs)
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


def _evaluate_binary(b, **kwargs):
    if not isinstance(b, expressions.Bin):
        return None
    left = evaluate_expression(b.left, **kwargs)
    right = evaluate_expression(b.right, **kwargs)
    max_size = max(left.data_type.size, right.data_type.size)
    if b.operator == Operator.MUL:
        return _make_constant(max_size, left.value * right.value)
    if b.operator == Operator.ADD:
        return _make_constant(max_size, left.value + right.value)
    if b.operator == Operator.SUB:
        return _make_constant(max_size, left.value - right.value)
    if b.operator == Operator.SHL:
        return _make_constant(max_size, left.value << right.value)
    if b.operator == Operator.BIT_AND:
        return _make_constant(max_size, left.value & right.value)
    return None


def _make_constant(data_size, value):
    data_type = data_types.AnyInt(data_size)
    if value < 0:
        if data_size == 4:
            data_type = data_types.Int32()
    return expressions.Constant(data_type, value)


def _evaluate_strlen(pc, string_constants, **kwargs):
    if not isinstance(pc, expressions.ProcedureCall):
        return None
    if pc.name != "strlen":
        return None
    assert len(pc.arguments) == 1
    addr = pc.arguments[0]
    assert isinstance(addr, expressions.Constant)
    s = string_constants[addr.value]
    return expressions.Constant(data_types.Int32(), len(s))
