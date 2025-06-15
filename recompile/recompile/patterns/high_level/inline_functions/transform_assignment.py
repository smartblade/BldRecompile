import data_types
import expressions
import instructions


def transform_assignment(dst, src, **kwargs):
    if not isinstance(dst, expressions.intermediate.Access):
        return None
    if not _is_ptr_to_class(src, "PyObject"):
        return None
    if not _is_ptr_to_class(dst.expression, "PyObject"):
        return None
    if dst.size != 4:
        return None
    if dst.offset < 12:
        return None
    if dst.offset % 4 != 0:
        return None
    index = (dst.offset - 12) // 4
    index_const = expressions.Constant(data_types.Int32(), index)
    return instructions.CodeInstruction(
        expressions.ProcedureCall(
            name="PyTuple_SET_ITEM",
            arguments=[dst.expression, index_const, src]))


def _is_ptr_to_class(obj, class_name):
    ptr = obj.data_type
    if not isinstance(ptr, data_types.Pointer32):
        return False
    class_type = ptr.pointee
    if not isinstance(class_type, data_types.ClassType):
        return False
    if class_type.class_name != class_name:
        return False
    return True
