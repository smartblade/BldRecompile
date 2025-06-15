import expressions
import instructions

from .is_int_constant import is_int_constant
from .obj_from_field_access import try_extract_obj_from_field_access


def is_refcnt_assignment(instr, obj, int_const, operator):
    if not isinstance(instr, instructions.Assignment):
        return False
    src = instr.src
    if not isinstance(src, expressions.Bin):
        return False
    if src.operator != operator:
        return False
    if not is_int_constant(src.right, int_const):
        return False
    left_obj = try_extract_obj_from_field_access(src.left, "ob_refcnt")
    if left_obj is None:
        return False
    dst_obj = try_extract_obj_from_field_access(instr.dst, "ob_refcnt")
    if dst_obj is None:
        return False
    if obj.emit_code() != left_obj.emit_code():
        return False
    if obj.emit_code() != dst_obj.emit_code():
        return False
    return True
