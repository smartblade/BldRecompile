import data_types
import expressions


def apply_parameter_characteristics(
    argument, file_declarations, characteristics
):
    if not isinstance(argument, expressions.Constant):
        return None
    if not argument.data_type.is_any_int:
        return None
    if isinstance(argument.data_type, data_types.Char):
        return None
    if characteristics.constant_set is None:
        return None
    constant_name = file_declarations.constants.find_name(
        argument.value,
        characteristics.constant_set,
    )
    if constant_name is None:
        return None
    return expressions.NamedConstant(argument.data_type.size, constant_name)
