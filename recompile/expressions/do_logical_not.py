import expressions
from expressions.operator import Operator

_inv_operators = {
    Operator.EQ: Operator.NE,
    Operator.NE: Operator.EQ,
    Operator.GT: Operator.LE,
    Operator.LE: Operator.GT,
    Operator.LT: Operator.GE,
    Operator.GE: Operator.LT,
}

_inv_logical = {
    Operator.AND: Operator.OR,
    Operator.OR: Operator.AND,
}


def do_logical_not(e):
    if isinstance(e, expressions.Bin):
        if e.operator in _inv_logical:
            return expressions.Bin(
                _inv_logical[e.operator],
                do_logical_not(e.left),
                do_logical_not(e.right),
            )
        return expressions.Bin(_inv_operators[e.operator], e.left, e.right)
    raise Exception("Can't do logical not for {}".format(e))
