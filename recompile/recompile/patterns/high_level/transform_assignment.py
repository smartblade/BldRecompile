import instructions

from .convert_expression_to_type import convert_expression_to_type


def transform_assignment(dst, src, **kwargs):
    new_src = convert_expression_to_type(src, dst.data_type)
    if new_src == src:
        return None
    return instructions.Assignment(dst, new_src)
