import data_types
import expressions
from expressions.operator import Operator
from patterns.make_proc_decl_from_args import make_proc_decl_from_args


def transform_static_cast(data_type, expression, procedure, **kwargs):
    if not isinstance(data_type, data_types.AnyInt):
        return None
    if data_type.size != 4:
        return None
    if not isinstance(expression, expressions.Bin):
        return None
    left = expression.left
    if not isinstance(left, expressions.FieldAccess):
        return None
    if left.field_name != "fd":
        return None
    if expression.operator != Operator.NE:
        return None
    right = expression.right
    if not isinstance(right, expressions.Constant):
        return None
    if not right.data_type.is_any_int:
        return None
    if right.value != -1:
        return None
    obj = left.expression
    obj_class = obj.data_type.pointee
    if not isinstance(obj_class, data_types.ClassType):
        return None
    if obj_class.class_name == "B_IDataFile":
        callee_addr = 0x100021E0
    elif obj_class.class_name == "B_ODataFile":
        callee_addr = 0x10002250
    else:
        return None
    if callee_addr == procedure.address:
        return None
    proc_decl = make_proc_decl_from_args([obj], is_method=True)
    proc_decl.change_return_type(data_types.AnyInt32())
    return expressions.ProcedureCall(
        is_method=True, arguments=[obj], proc_decl=proc_decl,
        callee_addr=callee_addr
    )
