import expressions


def is_int_constant(e, int_value):
    if not isinstance(e, expressions.Constant):
        return False
    if not e.data_type.is_any_int:
        return False
    if e.value != int_value:
        return False
    return True
