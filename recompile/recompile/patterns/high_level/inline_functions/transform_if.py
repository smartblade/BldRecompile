import expressions
import instructions
from expressions.operator import Operator


def transform_if(if_instr):
    if not isinstance(if_instr.if_clause, expressions.Bin):
        return if_instr
    if if_instr.if_clause.operator != Operator.NE:
        return if_instr
    if if_instr.if_clause.right != expressions.Null:
        return if_instr
    if if_instr.else_block is not None:
        return if_instr
    if len(if_instr.if_block) == 1:
        return _transform_single_instruction(
            if_instr.if_clause.left, if_instr.if_block[0]
        ) or if_instr
    if len(if_instr.if_block) == 2:
        return _transform_two_instructions(
            if_instr.if_clause.left, if_instr.if_block[0], if_instr.if_block[1]
        ) or if_instr
    return if_instr


def _transform_single_instruction(obj, instr):
    if not _is_assignment(instr, obj, 1, Operator.ADD):
        return None
    return instructions.CodeInstruction(
        expressions.ProcedureCall(name="Py_XINCREF", arguments=[obj]))


def _transform_two_instructions(obj, first_instr, second_instr):
    if not _is_assignment(first_instr, obj, 1, Operator.SUB):
        return None
    if not isinstance(second_instr, instructions.IfInstruction):
        return None
    if_clause = second_instr.if_clause
    if not isinstance(if_clause, expressions.Bin):
        return None
    if if_clause.operator != Operator.EQ:
        return None
    if not _is_int_constant(if_clause.right, 0):
        return None
    left_obj = _try_extract_obj_from_field_access(if_clause.left, "ob_refcnt")
    if left_obj is None:
        return None
    if obj.emit_code() != left_obj.emit_code():
        return None
    if second_instr.else_block is not None:
        return None
    if len(second_instr.if_block) != 1:
        return None
    block_instr = second_instr.if_block[0]
    if not isinstance(block_instr, instructions.CodeInstruction):
        return None
    pc = block_instr.expression
    if not isinstance(pc, expressions.ProcedureCall):
        return None
    ob_type = _try_extract_obj_from_field_access(
        pc.callee_expression, "tp_dealloc")
    if ob_type is None:
        return None
    deleting_obj = _try_extract_obj_from_field_access(ob_type, "ob_type")
    if deleting_obj is None:
        return None
    if obj.emit_code() != deleting_obj.emit_code():
        return None
    if len(pc.arguments) != 1:
        return None
    if obj.emit_code() != pc.arguments[0].emit_code():
        return None
    return instructions.CodeInstruction(
        expressions.ProcedureCall(name="Py_XDECREF", arguments=[obj]))


def _is_assignment(instr, obj, int_const, operator):
    if not isinstance(instr, instructions.Assignment):
        return False
    src = instr.src
    if not isinstance(src, expressions.Bin):
        return False
    if src.operator != operator:
        return False
    if not _is_int_constant(src.right, int_const):
        return False
    left_obj = _try_extract_obj_from_field_access(src.left, "ob_refcnt")
    if left_obj is None:
        return False
    dst_obj = _try_extract_obj_from_field_access(instr.dst, "ob_refcnt")
    if dst_obj is None:
        return False
    if obj.emit_code() != left_obj.emit_code():
        return False
    if obj.emit_code() != dst_obj.emit_code():
        return False
    return True


def _try_extract_obj_from_field_access(e, field_name):
    if not isinstance(e, expressions.FieldAccess):
        return None
    if e.field_name != field_name:
        return None
    return e.expression


def _is_int_constant(e, int_value):
    if not isinstance(e, expressions.Constant):
        return False
    if not e.data_type.is_any_int:
        return False
    if e.value != int_value:
        return False
    return True
