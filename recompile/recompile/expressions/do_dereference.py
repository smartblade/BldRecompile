import data_types
import expressions


def do_dereference(e):
    if isinstance(e, expressions.AddressOf):
        if isinstance(e.expression.data_type, data_types.Reference):
            return expressions.ImplicitDereference(e.expression)
        return e.expression
    if isinstance(e, expressions.Bin):
        e = expressions.BracketsExpression(e)
    return expressions.Dereference(e)
