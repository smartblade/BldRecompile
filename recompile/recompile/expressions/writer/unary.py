import expressions

from .strip_implicit_cast import strip_implicit_cast


def write_unary(operator, expression):
    expression = strip_implicit_cast(expression)
    return "{}{}".format(operator.value, _emit_brackets(expression).emit_code())


def _emit_brackets(expression):
    if not isinstance(expression, expressions.Bin):
        return expression
    return expressions.BracketsExpression(expression)
