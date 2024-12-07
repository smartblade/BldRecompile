import expressions
from expressions.operator import Operator

_inv_operators = {
    Operator.EQ: Operator.NE,
    Operator.NE: Operator.EQ,
    Operator.GT: Operator.LE,
    Operator.LE: Operator.GT,
    Operator.LT: Operator.GE,
    Operator.GE: Operator.GT,
}


def do_logical_not(e):
    if isinstance(e, expressions.Bin):
        return expressions.Bin(_inv_operators[e.operator], e.left, e.right)
    raise Exception("Can't do logical not for {}".format(e))
