import data_types
import expressions
import instructions
from instructions.extract_vtbl_addr_from_assign import\
    extract_vtbl_addr_from_assign


def discover_fields_initialization(procedure):
    if procedure.proc_decl is None:
        return procedure
    if not procedure.proc_decl.is_constructor:
        return procedure
    proc_info = procedure.proc_info
    class_type = procedure.proc_decl.method_class
    fields = _get_fields(class_type)
    init_required = False
    for field in fields:
        field_type, field_name = field
        if isinstance(field_type, data_types.ClassType):
            init_required = True
    if not init_required:
        return procedure
    vtbl_addr = _find_vtb_addr(procedure)
    last_init_instr = None
    prev_instr = None
    cur_class_field_index = 0
    for instr in procedure.instructions:
        initialized_field = _extract_initialized_field(proc_info, instr)
        if initialized_field is None:
            if (
                vtbl_addr is not None and
                extract_vtbl_addr_from_assign(proc_info, instr) == vtbl_addr
            ):
                prev_instr = last_init_instr
                last_init_instr = instr
            if _has_class_type(cur_class_field_index, fields):
                last_init_instr = prev_instr
            break
        cur_class_field_index = _go_to_field(
            cur_class_field_index, fields, initialized_field)
        if cur_class_field_index < 0:
            break
        prev_instr = last_init_instr
        last_init_instr = instr
    return procedure.copy(last_init_instr=last_init_instr)


def _find_vtb_addr(procedure):
    for instr in reversed(procedure.instructions):
        vtbl_addr = extract_vtbl_addr_from_assign(procedure.proc_info, instr)
        if vtbl_addr is not None:
            return vtbl_addr
    return None


def _extract_initialized_field(proc_info, instr):
    if not isinstance(instr, instructions.CodeInstruction):
        return None
    pc = instr.expression
    if not isinstance(pc, expressions.ProcedureCall):
        return None
    if pc.proc_decl is None:
        return None
    if not pc.proc_decl.is_constructor:
        return None
    obj_ptr = pc.arguments[0]
    if not isinstance(obj_ptr.data_type, data_types.Pointer32):
        return None
    obj_type = obj_ptr.data_type.pointee
    if proc_info.is_this_expression(obj_ptr):
        if obj_type.parent != pc.proc_decl.method_class:
            return None
        return obj_type.parent, None
    if obj_type != pc.proc_decl.method_class:
        return None
    if not isinstance(obj_ptr, expressions.AddressOf):
        return None
    obj = obj_ptr.expression
    if not isinstance(obj, expressions.FieldAccess):
        return None
    if not proc_info.is_this_expression(obj.expression):
        return None
    return obj.data_type, obj.field_name


def _get_fields(class_type):
    fields = []
    cur_field_and_offset = _get_type_at(class_type, 0)
    if cur_field_and_offset is None:
        return fields
    while cur_field_and_offset is not None:
        cur_field_offset, cur_field = cur_field_and_offset
        fields.append(cur_field)
        cur_field_type, cur_field_name = cur_field
        if cur_field_type.size == 0:
            cur_field_offset += 1
        else:
            cur_field_offset += cur_field_type.size
        cur_field_and_offset = _get_type_at(class_type, cur_field_offset)
    return fields


def _get_type_at(class_type, offset):
    if offset == 0 and class_type.parent is not None:
        return 0, (class_type.parent, None)
    field_offset = class_type.find_nearest_field_offset(offset)
    # Skip virtual methods table
    if field_offset is None and offset == 0:
        offset += 4
        field_offset = class_type.find_nearest_field_offset(offset)
    if field_offset is None:
        return None
    return field_offset, class_type.get_field_by_offset(field_offset)


def _go_to_field(field_index, fields, initialized_field):
    initialized_f_type, initialized_f_name = initialized_field
    while field_index < len(fields):
        data_type, field_name = fields[field_index]
        field_index += 1
        if (
            data_types.are_same(initialized_f_type, data_type) and
            initialized_f_name == field_name
        ):
            return field_index
        if isinstance(data_type, data_types.ClassType):
            return -1
    return -1


def _has_class_type(field_index, fields):
    while field_index < len(fields):
        data_type, field_name = fields[field_index]
        field_index += 1
        if isinstance(data_type, data_types.ClassType):
            return True
    return False
