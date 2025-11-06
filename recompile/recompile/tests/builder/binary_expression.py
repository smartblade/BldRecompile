import expressions
from expressions.operator import Operator


def _make_binary_expression(operator, *operands):
    result = None
    for operand in operands:
        if result is None:
            result = operand
        else:
            result = expressions.Bin(operator, result, operand)
    return result


def _make_binary_expression_maker(operator):
    return lambda *operands: _make_binary_expression(operator, *operands)


add = _make_binary_expression_maker(Operator.ADD)
mul = _make_binary_expression_maker(Operator.MUL)
and_op = _make_binary_expression_maker(Operator.AND)
lt = _make_binary_expression_maker(Operator.LT)
gt = _make_binary_expression_maker(Operator.GT)
