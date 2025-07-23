from .get_writeable_expression import get_writeable_expression


def write_conditional_operator(cond):
    return get_writeable_expression(cond).emit_code()
