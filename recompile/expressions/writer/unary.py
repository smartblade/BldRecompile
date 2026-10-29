import expressions
import expressions.writer.macros as macros

from .get_writeable_expression import get_writeable_expression


def write_unary(operator, expression):
    expression = get_writeable_expression(expression)
    result = macros.try_convert_unary_to_macro(operator, expression)
    if result is not None:
        return result
    return "{}{}".format(operator.value, _emit_brackets(expression).emit_code())


def _emit_brackets(expression):
    if not isinstance(expression, expressions.Bin):
        return expression
    return expressions.BracketsExpression(expression)
