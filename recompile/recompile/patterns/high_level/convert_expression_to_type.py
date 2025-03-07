import data_types
import expressions


def convert_expression_to_type(e, target_type):
    src_type = e.data_type
    if src_type.size != target_type.size:
        raise Exception("Can't convert {}(size: {}) to {}(size: {}).".format(
            src_type, src_type.size, target_type, target_type.size))
    if data_types.are_compatible(src_type, target_type):
        return e
    converted = _try_convert_pointers_or_references(e, src_type, target_type)
    if converted is not None:
        return converted
    if (
        isinstance(src_type, data_types.UnknownTypes) and
        not isinstance(target_type, data_types.UnknownTypes)
    ):
        return expressions.do_reinterpret(target_type, e)
    if (
        isinstance(src_type, data_types.AnyInt) and
        not isinstance(target_type, data_types.AnyInt)
    ):
        return expressions.do_reinterpret(target_type, e)
    if (
        src_type.is_any_int and
        target_type.is_any_int
    ):
        return expressions.do_reinterpret(target_type, e)
    raise Exception("Can't convert {} to {}.".format(src_type, target_type))


def _try_convert_pointers_or_references(e, src_type, target_type):
    ptr_or_ref = (data_types.Pointer32, data_types.Reference)
    if not isinstance(src_type, ptr_or_ref):
        return None
    if not isinstance(target_type, ptr_or_ref):
        return None
    if isinstance(src_type, data_types.Pointer32):
        src_type_pointee = src_type.pointee
    else:
        src_type_pointee = src_type.referent
        e = expressions.AddressOf(e)
    if isinstance(target_type, data_types.Pointer32):
        target_type_pointee = target_type.pointee
    else:
        target_type_pointee = target_type.referent
    converted = _convert_pointees(e, src_type_pointee, target_type_pointee)
    if isinstance(target_type, data_types.Reference):
        converted = expressions.do_dereference(converted)
        if not isinstance(converted.data_type, data_types.Reference):
            converted = expressions.ImplicitCast(
                data_types.Reference(converted.data_type), converted)
    return converted


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
    if (
        src_type.is_any_int and
        target_type.is_any_int
    ):
        return expressions.do_reinterpret(data_types.Pointer32(target_type), e)
    raise Exception("Can't convert {} to {}".format(src_type, target_type))
