import data_types
import expressions
from expressions.operator import Operator


def apply_parameter_characteristics(
    argument, file_declarations, characteristics
):
    if characteristics.constant_set is not None:
        return _apply_constant_set(
            argument, file_declarations, characteristics.constant_set)
    return None


def _apply_constant_set(e, file_declarations, constant_set):
    if isinstance(e, expressions.Bin) and e.operator == Operator.BIT_OR:
        right = _apply_constant_set(e.right, file_declarations, constant_set)
        if right is not None:
            return expressions.Bin(e.operator, e.left, right)
        return None
    if not isinstance(e, expressions.Constant):
        return None
    if (
        not e.data_type.is_any_int and
        not isinstance(e.data_type, data_types.Unknown32)
    ):
        return None
    if isinstance(e.data_type, data_types.Char):
        return None
    constant_name = file_declarations.constants.find_name(e.value, constant_set)
    if constant_name is None:
        return None
    return expressions.NamedConstant(e.data_type.size, constant_name)
