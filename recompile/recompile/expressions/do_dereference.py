import expressions


def do_dereference(e):
    if isinstance(e, expressions.AddressOf):
        return e.expression
    if isinstance(e, expressions.Bin):
        e = expressions.BracketsExpression(e)
    return expressions.Dereference(e)
