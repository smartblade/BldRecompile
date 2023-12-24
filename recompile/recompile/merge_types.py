from int32 import Int32
from pointer32 import Pointer32
from unknown32 import Unknown32

def merge_types(data_type, new_data_type):
    if (
        isinstance(data_type, Pointer32) and
        isinstance(new_data_type, Pointer32)
    ):
        return data_type
    if (
        isinstance(data_type, Unknown32) and
        isinstance(new_data_type, Unknown32)
    ):
        return data_type
    if not isinstance(data_type, Unknown32):
        raise Exception(
            "Can't merge {} with {}.".format(
                data_type, new_data_type
            )
        )
    if not isinstance(new_data_type, Int32):
        raise Exception(
            "Can't merge {} with {}.".format(
                data_type, new_data_type
            )
        )
    return new_data_type
