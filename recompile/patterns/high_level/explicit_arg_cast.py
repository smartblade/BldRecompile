import data_types
import expressions


def explicit_arg_cast(proc_decl, arg, target_type):
    if proc_decl.operator is None:
        return None
    src_type = arg.data_type
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Pointer32)
    ):
        src_type_pointee = src_type.pointee
        target_type_pointee = target_type.pointee
        make_ptr_or_ref = data_types.Pointer32
    elif (
        isinstance(src_type, data_types.Reference) and
        isinstance(target_type, data_types.Reference)
    ):
        src_type_pointee = src_type.referent
        target_type_pointee = target_type.referent
        make_ptr_or_ref = data_types.Reference
    else:
        return None
    if not isinstance(src_type_pointee, data_types.ClassType):
        return None
    if not isinstance(target_type_pointee, data_types.ClassType):
        return None
    if not data_types.are_compatible(
        data_types.Pointer32(src_type_pointee),
        data_types.Pointer32(target_type_pointee)
    ):
        return None
    if data_types.are_same(src_type_pointee, target_type_pointee):
        return None
    return expressions.StaticCast(make_ptr_or_ref(target_type_pointee), arg)
