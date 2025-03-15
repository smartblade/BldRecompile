import expressions


def strip_implicit_cast(e):
    if isinstance(e, expressions.ImplicitCast):
        return e.expression
    return e
