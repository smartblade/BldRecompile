import expressions
import data_types
from hex_conversion import from_hex


def transform_reinterpret(data_type, expression, **kwargs):
    result = _transform_string_constant(data_type, expression, **kwargs)
    if result is not None:
        return result
    return expressions.do_reinterpret(data_type, expression)


def _transform_string_constant(data_type, expression, declarations, **kwargs):
    if not isinstance(data_type, data_types.Pointer32):
        return None
    if not isinstance(data_type.pointee, data_types.Char):
        return None
    global_variable = expression
    if not isinstance(global_variable, expressions.ProcedureCall):
        return None
    if not global_variable.is_predefined:
        return None
    if global_variable.name != 'GLOBAL':
        return None
    assert len(global_variable.arguments) == 1
    global_address_expression = global_variable.arguments[0]
    assert isinstance(global_address_expression, expressions.Constant)
    global_address = global_address_expression.value
    string_const = declarations.string_constants.get(global_address)
    if string_const is None:
        return None
    return expressions.StringConstant(string_const)
