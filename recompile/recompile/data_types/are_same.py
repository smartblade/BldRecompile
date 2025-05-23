import data_types


def are_same(first, second):
    if (
        isinstance(first, data_types.NamedType) and
        isinstance(second, data_types.NamedType)
    ):
        return (
            first.get_type_name(is_metafile=False) ==
            second.get_type_name(is_metafile=False)
        )
    if isinstance(first, data_types.NamedType):
        return are_same(first.referenced_type, second)
    if isinstance(second, data_types.NamedType):
        return are_same(first, second.referenced_type)
    if type(first) is not type(second):
        return False
    if first is None and second is None:
        return True
    standard_types = [
        data_types.UnknownByte,
        data_types.Char,
        data_types.UChar,
        data_types.Short,
        data_types.UShort,
        data_types.Unknown32,
        data_types.Int32,
        data_types.UInt32,
        data_types.Float,
        data_types.Double,
        data_types.Unknown64,
    ]
    for standard_type in standard_types:
        if (
            isinstance(first, standard_type) and
            isinstance(second, standard_type)
        ):
            return True
    if (
        isinstance(first, data_types.AnyInt) and
        isinstance(second, data_types.AnyInt)
    ):
        return first.size == second.size
    if (
        isinstance(first, data_types.Pointer32) and
        isinstance(second, data_types.Pointer32)
    ):
        return are_same(first.pointee, second.pointee)
    if (
        isinstance(first, data_types.Reference) and
        isinstance(second, data_types.Reference)
    ):
        return are_same(first.referent, second.referent)
    if (
        isinstance(first, data_types.ClassType) and
        isinstance(second, data_types.ClassType)
    ):
        return first.class_name == second.class_name
    raise Exception(
        "Unimplemented comparison for {} and {}.".format(first, second))
