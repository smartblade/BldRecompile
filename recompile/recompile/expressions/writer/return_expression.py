from .strip_implicit_conversion import strip_implicit_conversion


def write_return_expression(expression):
    expression = strip_implicit_conversion(expression) or expression
    return expression.emit_code()
