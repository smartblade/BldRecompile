import data_types
import expressions
from expressions.operator import Operator

from .transform_access import do_pointer_dereference


def transform_arrptr(base, scale, index, offset, **kwargs):
    if scale != 1:
        return None
    if offset < 0:
        return None
    e = do_pointer_dereference(base, 0, None)
    if e is None:
        return None
    if isinstance(e.data_type, data_types.Array):
        element_type = e.data_type.element_type
    else:
        e = base
        element_type = e.data_type.pointee
    if element_type.size != 1:
        return None
    if offset > 0:
        index = expressions.Bin(
            Operator.ADD, index, expressions.Constant(index.data_type, offset))
    return expressions.AddressOf(expressions.ArrayAccess(e, index))
