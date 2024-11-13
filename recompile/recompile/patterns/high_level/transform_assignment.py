import instructions

from .convert_expression_to_type import convert_expression_to_type


def transform_assignment(ass, **kwargs):
    src = convert_expression_to_type(ass.src, ass.dst.data_type)
    return instructions.Assignment(ass.dst, src)
