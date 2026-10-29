import expressions
from expressions.operator import Operator


def try_convert_unary_to_macro(operator, expression):
    if operator != Operator.DEREF:
        return None
    if not isinstance(expression, expressions.ProcedureCall):
        return None
    if expression.name != "_errno":
        return None
    if expression.emit_code() != "_errno()":
        return None
    return "errno"


def try_convert_to_min_max(cond):
    bin_clause = cond.if_clause
    if not isinstance(bin_clause, expressions.Bin):
        return None
    if (
        bin_clause.operator != Operator.GT and
        bin_clause.operator != Operator.LT
    ):
        return None
    result = _try_convert_to_macro(
        _macro_names[bin_clause.operator],
        bin_clause.left,
        bin_clause.right,
        cond.then_expression,
        cond.else_expression)
    if result is not None:
        return result
    if isinstance(
        bin_clause.right, (expressions.Constant, expressions.NamedConstant)
    ):
        result = _try_convert_to_macro(
            _macro_names[_inv_op[bin_clause.operator]],
            bin_clause.right,
            bin_clause.left,
            cond.then_expression,
            cond.else_expression)
        if result is not None:
            return result
    return None


def _try_convert_to_macro(name, left, right, then_expression, else_expression):
    if left.emit_code() != then_expression.emit_code():
        return None
    if right.emit_code() != else_expression.emit_code():
        return None
    return expressions.ProcedureCall(name=name, arguments=[left, right])


_macro_names = {
    Operator.LT: "min",
    Operator.GT: "max",
}

_inv_op = {
    Operator.LT: Operator.GT,
    Operator.GT: Operator.LT,
}
