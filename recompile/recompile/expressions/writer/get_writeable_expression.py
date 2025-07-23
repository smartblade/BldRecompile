import expressions
from expressions.operator import Operator


def get_writeable_expression(e):
    if isinstance(e, expressions.ImplicitCast):
        return get_writeable_expression(e.expression)
    if isinstance(e, expressions.ConditionalOperator):
        result = _try_convert_to_min_max(e)
        if result is not None:
            return result
        return expressions.Bin(
            Operator.COND_SEP,
            expressions.Bin(
                Operator.COND,
                get_writeable_expression(e.if_clause),
                get_writeable_expression(e.then_expression),
            ),
            get_writeable_expression(e.else_expression),
        )
    return e


def _try_convert_to_min_max(cond):
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
