import data_types
import expressions

from .transform_access import transform_access


def transform_arrptr(base, scale, index, offset, **kwargs):
    assert scale == 1
    assert offset == 0
    e = transform_access(base, 0, None)
    if e is None:
        return None
    if not isinstance(e.data_type, data_types.Array):
        return None
    assert e.data_type.element_type.size == 1
    return expressions.AddressOf(expressions.ArrayAccess(e, index))
