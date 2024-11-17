import data_types
import expressions


def transform_access(expression, offset, size, **kwargs):
    if isinstance(expression.data_type, data_types.Unknown32):
        return None
    if isinstance(expression.data_type, data_types.Reference):
        expression = expressions.AddressOf(expression)
    if not isinstance(expression.data_type, data_types.Pointer32):
        raise Exception(
            "Data type of {} expected to be pointer but was: {}.".format(
                expression, expression.data_type))
    pointee = expression.data_type.pointee
    if isinstance(pointee, data_types.ClassType):
        try:
            data_type, field_name = pointee.get_field_by_offset(offset)
        except KeyError:
            return None
        if size is not None and data_type.size != size:
            raise Exception(
                "Data type size expected to be {} but was: {}.".format(
                    size, data_type.size))
        return expressions.FieldAccess(expression, field_name)
    if isinstance(
        pointee, (data_types.UnknownByte, data_types.Int32, data_types.UInt32)
    ):
        if pointee.size != size:
            raise Exception(
                "Data type size expected to be {} but was: {}.".format(
                    size, pointee.size))
        if offset != 0:
            raise Exception(
                "Data access offset expected to be {} but was: {}.".format(
                    0, offset))
        return expressions.do_dereference(expression)
    return None
