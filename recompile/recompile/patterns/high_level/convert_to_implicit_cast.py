import data_types
import expressions


def convert_to_implicit_cast(e, target_type):
    if not isinstance(e, expressions.StaticCast):
        return e
    if not data_types.are_same(e.data_type, target_type):
        return e
    if not _can_do_implicit_cast(e.expression.data_type, e.data_type):
        return e
    return expressions.ImplicitCast(e.data_type, e.expression)


def _can_do_implicit_cast(source_type, target_type):
    if (
        isinstance(source_type, data_types.Bool) and
        isinstance(target_type, (data_types.Int32, data_types.UInt32))
    ):
        return True
    return False
