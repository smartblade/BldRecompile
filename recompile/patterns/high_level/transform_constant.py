import data_types
import expressions


def transform_constant(c, file_declarations, **kwargs):
    result = _make_named_const_from_characteristics(c, **kwargs)
    if result is not None:
        return result
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


def _make_named_const_from_characteristics(
    c, stack_vars, characteristics, **kwargs
):
    if not c.data_type.is_any_int:
        return None
    if isinstance(c.data_type, data_types.Char):
        return None
    const_characteristics = characteristics.constants.by_value(c.value)
    if const_characteristics is None:
        return None
    if const_characteristics.sizeof_variable_offset is None:
        return None
    if const_characteristics.sizeof_variable_offset not in stack_vars:
        return None
    var = stack_vars[const_characteristics.sizeof_variable_offset]
    sizeof_expression = "sizeof({})".format(var.data_type.get_type_name())
    result = expressions.NamedConstant(c.data_type.size, sizeof_expression)
    if c.value == -var.data_type.size:
        result = expressions.Negate(expressions.StaticCast(c.data_type, result))
    else:
        return None
    return result
