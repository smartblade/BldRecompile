import data_types
import expressions


def strip_implicit_conversion(e):
    result = _make_array_decay(e)
    if result is not None:
        return result
    result = _strip_make_reference(e)
    if result is not None:
        return result
    return None


def _make_array_decay(e):
    if not isinstance(e, expressions.AddressOf):
        return None
    array_access = e.expression
    if not isinstance(array_access, expressions.ArrayAccess):
        return None
    index = array_access.index
    if not isinstance(index, expressions.Constant):
        return None
    assert isinstance(index.value, int)
    if index.value != 0:
        return None
    array = array_access.array
    array_type = array.data_type
    if not isinstance(array_type, data_types.Array):
        return None
    if not data_types.are_same(array_type.element_type, e.data_type.pointee):
        return None
    return array


def _strip_make_reference(e):
    if not isinstance(e, expressions.MakeReference):
        return None
    if not data_types.are_same(e.expression.data_type, e.data_type.referent):
        return None
    return e.expression
