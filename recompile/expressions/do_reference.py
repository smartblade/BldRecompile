import data_types
import expressions


def do_reference(expression):
    if isinstance(expression, expressions.ImplicitDereference):
        reference = expression.expression
        assert isinstance(reference.data_type, data_types.Reference)
        assert data_types.are_same(
            reference.data_type.referent, expression.data_type)
        return reference
    return expressions.MakeReference(expression)
