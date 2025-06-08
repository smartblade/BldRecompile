import expressions
import data_types


def transform_reinterpret(data_type, expression, analysis, **kwargs):
    result = _transform_string_constant(data_type, expression, **kwargs)
    if result is not None:
        return result
    analysis.process_reinterpret(data_type, expression)
    return expressions.do_reinterpret(data_type, expression)


def _transform_string_constant(data_type, expression, declarations, **kwargs):
    if not isinstance(data_type, data_types.Pointer32):
        return None
    if not isinstance(data_type.pointee, data_types.Char):
        return None
    global_variable = expression
    if not isinstance(global_variable, expressions.intermediate.Global):
        return None
    string_const = declarations.string_constants.get(global_variable.address)
    if string_const is None:
        return None
    return expressions.StringConstant(string_const)
