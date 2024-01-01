import data_types


def merge_types(data_type, new_data_type):
    if (
        isinstance(data_type, data_types.Pointer32) and
        isinstance(new_data_type, data_types.Pointer32)
    ):
        return data_type
    if (
        isinstance(data_type, data_types.Unknown32) and
        isinstance(new_data_type, data_types.Unknown32)
    ):
        return data_type
    if isinstance(new_data_type, data_types.UnknownClass):
        return data_type
    if not isinstance(data_type, data_types.Unknown32):
        raise Exception(
            "Can't merge {} with {}.".format(
                data_type, new_data_type
            )
        )
    if not isinstance(new_data_type, data_types.Int32):
        raise Exception(
            "Can't merge {} with {}.".format(
                data_type, new_data_type
            )
        )
    return new_data_type
