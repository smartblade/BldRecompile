import data_types
import expressions


def convert_expression_to_type(e, target_type):
    src_type = e.data_type
    if src_type.size != target_type.size:
        raise Exception("Can't convert {}(size: {}) to {}(size: {}).".format(
            src_type, src_type.size, target_type, target_type.size))
    if data_types.are_compatible(src_type, target_type):
        return e
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Pointer32)
    ):
        converted = _convert_pointees(e, src_type.pointee, target_type.pointee)
        if converted is not None:
            return converted
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Reference)
    ):
        converted = _convert_pointees(e, src_type.pointee, target_type.referent)
        if converted is not None:
            return expressions.do_dereference(converted)
    if (
        isinstance(src_type, data_types.Reference) and
        isinstance(target_type, data_types.Pointer32)
    ):
        converted = _convert_pointees(e, src_type.referent, target_type.pointee)
        if converted is not None:
            return expressions.AddressOf(converted)
    if (
        isinstance(src_type, data_types.Unknown32) and
        not isinstance(target_type, data_types.Unknown32)
    ):
        return expressions.do_reinterpret(target_type, e)
    if (
        isinstance(src_type, data_types.AnyInt) and
        not isinstance(target_type, data_types.AnyInt)
    ):
        return expressions.do_reinterpret(target_type, e)
    raise Exception("Can't convert {} to {}.".format(src_type, target_type))


def _convert_pointees(e, src_type, target_type):
    if (
        data_types.are_compatible(
            data_types.Pointer32(src_type),
            data_types.Pointer32(target_type),
        )
    ):
        return e
    if src_type is None:
        return expressions.do_reinterpret(data_types.Pointer32(target_type), e)
    raise Exception("Can't convert {} to {}".format(src_type, target_type))
