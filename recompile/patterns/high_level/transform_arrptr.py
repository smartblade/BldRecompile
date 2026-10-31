import data_types
import expressions
from expressions.do_pointer_dereference import do_pointer_dereference
from expressions.operator import Operator


def transform_arrptr(base, scale, index, offset, **kwargs):
    e = _transform_field_array_element(base, scale, index, offset)
    if e is not None:
        return e
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


def _transform_field_array_element(base, scale, index, offset):
    """Transform address of element of array field: &base->field[index]."""
    data_type = base.data_type
    if isinstance(data_type, data_types.Pointer32):
        pointee = data_type.pointee
    elif isinstance(data_type, data_types.Reference):
        pointee = data_type.referent
    else:
        return None
    if not isinstance(pointee, data_types.ClassType) or offset < 0:
        return None
    field = do_pointer_dereference(base, offset, None)
    if field is None or not isinstance(field.data_type, data_types.Array):
        return None
    if field.data_type.element_type.size != scale:
        return None
    return expressions.AddressOf(expressions.ArrayAccess(field, index))
