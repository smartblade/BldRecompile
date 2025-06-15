import expressions
import instructions
from expressions.operator import Operator

from .is_int_constant import is_int_constant
from .is_refcnt_assignment import is_refcnt_assignment
from .obj_from_field_access import try_extract_obj_from_field_access


def transform_if(if_clause, if_block, else_block):
    if not isinstance(if_clause, expressions.Bin):
        return None
    if if_clause.operator != Operator.NE:
        return None
    if if_clause.right != expressions.Null:
        return None
    if else_block is not None:
        return None
    if len(if_block) == 1:
        return _transform_single_instruction(
            if_clause.left, if_block[0]
        )
    return None


def _transform_single_instruction(obj, instr):
    if not is_refcnt_assignment(instr, obj, 1, Operator.ADD):
        return _transform_x_decref(obj, instr)
    return instructions.CodeInstruction(
        expressions.ProcedureCall(name="Py_XINCREF", arguments=[obj]))


def _transform_x_decref(obj, instr):
    if not isinstance(instr, instructions.CodeInstruction):
        return None
    pc = instr.expression
    if not isinstance(pc, expressions.ProcedureCall):
        return None
    if pc.name != "Py_DECREF":
        return None
    if len(pc.arguments) != 1:
        return None
    if obj.emit_code() != pc.arguments[0].emit_code():
        return None
    return instructions.CodeInstruction(
        expressions.ProcedureCall(name="Py_XDECREF", arguments=[obj]))
