import data_types
import expressions
import instructions

from .apply_parameter_characteristics import apply_parameter_characteristics
from .expression_characteristics import get_expression_characteristics


def transform_switch(
    index, case_set_dict, blocks_dict, default_label, constant_dict,
    file_declarations, **kwargs
):
    if constant_dict:
        return None
    index_characteristics = get_expression_characteristics(index, **kwargs)
    if index_characteristics is None:
        return None
    constant_dict = {}
    for case_set in case_set_dict.values():
        for case in case_set:
            case_constant = apply_parameter_characteristics(
                expressions.Constant(data_types.Int32(), case),
                file_declarations,
                index_characteristics,
            )
            if case_constant is not None:
                constant_dict[case] = case_constant.emit_code()
    if not constant_dict:
        return None
    return instructions.Switch(
        index, case_set_dict, blocks_dict, default_label, constant_dict)
