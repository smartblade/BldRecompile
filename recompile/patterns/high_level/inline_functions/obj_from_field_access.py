import expressions


def try_extract_obj_from_field_access(e, field_name):
    if not isinstance(e, expressions.FieldAccess):
        return None
    if e.field_name != field_name:
        return None
    return e.expression
