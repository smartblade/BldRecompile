import data_types
import expressions


def transform_constant(c, file_declarations, **kwargs):
    if not c.data_type.is_any_int:
        return None
    if isinstance(c.data_type, data_types.Char):
        return None
    if c.value <= 256:
        return None
    constant_name = file_declarations.constants.single_name(c.value)
    if constant_name is None:
        if c.data_type.size != 4:
            return None
        negated_value = (1 << 32) - c.value
        constant_name = file_declarations.constants.single_name(negated_value)
        if constant_name is None:
            return None
        constant_name = "-{}".format(constant_name)
    return expressions.NamedConstant(c.data_type.size, constant_name)
