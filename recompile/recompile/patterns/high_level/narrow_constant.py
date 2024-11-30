import data_types
import expressions


def narrow_constant(c, target_type):
    if not isinstance(c, expressions.Constant):
        return None
    if not target_type.is_any_int:
        return None
    if c.data_type.size <= target_type.size:
        return None
    if isinstance(c.data_type, data_types.UnknownTypes):
        if c.value < (1 << (8 * target_type.size)):
            return expressions.Constant(target_type, c.value)
    return None
