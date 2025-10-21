import data_types
import expressions
import instructions

from .apply_parameter_characteristics import apply_parameter_characteristics


def transform_switch(
    index, case_set_dict, blocks_dict, default_label, constant_dict, procedure,
    characteristics, file_declarations, **kwargs
):
    if constant_dict:
        return None
    if not isinstance(index, expressions.Identifier):
        return None
    if procedure.proc_decl is None:
        return None
    parameters = list(
        procedure.proc_decl.get_parameters_ids().values())
    parameter_index = None
    for i, parameter in enumerate(parameters):
        if index.name == parameter.name:
            parameter_index = i
            break
    if parameter_index is None:
        return None
    constant_dict = {}
    for case_set in case_set_dict.values():
        for case in case_set:
            case_constant = apply_parameter_characteristics(
                expressions.Constant(data_types.Int32(), case),
                file_declarations,
                characteristics.parameters[parameter_index],
            )
            if case_constant is not None:
                constant_dict[case] = case_constant.emit_code()
    if not constant_dict:
        return None
    return instructions.Switch(
        index, case_set_dict, blocks_dict, default_label, constant_dict)
