import data_types
import expressions


def convert_return_value_to_bool(characteristics, return_value):
    if not characteristics.ret.is_boolean:
        return return_value
    if not isinstance(return_value, expressions.Constant):
        return return_value
    if not return_value.data_type.is_any_int:
        return return_value
    assert return_value.value == 0 or return_value.value == 1
    return expressions.Constant(data_types.Bool(), return_value.value)
