import expressions
from expressions.operator import Operator


def get_writeable_expression(e):
    if isinstance(e, expressions.ImplicitCast):
        return get_writeable_expression(e.expression)
    if isinstance(e, expressions.ConditionalOperator):
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
