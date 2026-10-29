import expressions
from expressions.operator import Operator
import expressions.writer.macros as macros


def get_writeable_expression(e):
    if isinstance(e, expressions.ImplicitCast):
        return get_writeable_expression(e.expression)
    if isinstance(e, expressions.ConditionalOperator):
        result = macros.try_convert_to_min_max(e)
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
