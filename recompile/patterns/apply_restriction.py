import expressions
from expressions.operator import Operator


def apply_restriction(restriction):
    if not isinstance(restriction, expressions.Bin):
        raise Exception(
            "Unknown restriction expression kind: {}.".format(restriction))
    if restriction.operator != Operator.NE:
        raise Exception(
            "Unknown restriction operator: {}.".format(restriction))
    left = restriction.left.emit_code()
    _find_unknown_variables(left)
    right = restriction.right.emit_code()
    _find_unknown_variables(right)
    if left == right:
        raise Exception(
            "Restriction failed: {}.".format(restriction))


def _find_unknown_variables(s):
    if "%" in s:
        raise Exception(
            "There are unknown variables in '{}' expression.".format(s))
