import re

import data_types
from exceptions import UndefinedTypeException
import expressions
from expressions.operator import Operator
from hex_conversion import from_hex
import instructions
from writer import Writer

char_cast_regexp = re.compile(
    r'^(\(char\s*\*\)\s*this|&this->(?P<field_name>\w+))$'
)
offset_regexp = re.compile(r'^(?P<offset>\d+)$')
field_regexp = re.compile(r'^dw(?P<offset>[\dABCDEF]+)\s*$')
field_access_regexp = re.compile(
    r'unknown32\s(?P<var>\w+)\s*=\s*(?P<obj>\w+)->dw(?P<offset>[\dABCDEF]+)'
)
seq_regexp = re.compile(
    r'double\s\w+\s*=\s*SEQ\((?P<first_var>\w+),\s(?P<second_var>\w+)\)'
)


def ensure_class_fields(method_class, body_instructions):
    def on_expression_visited(e):
        if not isinstance(e, expressions.Bin):
            return
        if e.operator != Operator.ADD:
            return
        match = re.search(char_cast_regexp, e.left.emit_code())
        if not match:
            return
        field_name = match.group('field_name')
        match = re.search(offset_regexp, e.right.emit_code())
        if match:
            offset = match.group('offset')
            size = None
            if field_name is None:
                size = 1
            # TODO deduce type from expression instead of field name parsing
            elif field_name.startswith("ptr"):
                size = 4
            method_class.ensure_field(int(offset) * size)
    for instr in body_instructions:
        instr.visit(on_expression_visited)


def guess_float_fields(proc_decl, body_instructions):
    parameters = proc_decl.get_parameters_ids()

    def on_expression_visited(e):
        if not isinstance(e, instructions.Assignment):
            return
        if not isinstance(e.dst, expressions.FieldAccess):
            return
        match = re.search(field_regexp, e.dst.field_name)
        if not match:
            return
        offset = match.group('offset')
        if not isinstance(e.dst.expression, expressions.Identifier):
            return
        identifier = e.dst.expression
        if not isinstance(identifier.data_type, data_types.Pointer32):
            return
        parameter_class = identifier.data_type.pointee
        if not isinstance(e.src, expressions.Constant):
            return
        if e.src.emit_code() == "0x3FF00000":
            parameter_class.merge_word32_into_double(from_hex(offset) - 4)
    for instr in body_instructions:
        instr.visit(on_expression_visited)


def merge_double_fields(parameters, body_instructions):
    merge_candidates = {}
    writer = Writer()
    for instr in body_instructions:
        instr.emit_code(writer)
    lines = writer.get_string()
    for line in lines.split("\n"):
        match = re.search(field_access_regexp, line)
        if match:
            var = match.group('var')
            offset = match.group('offset')
            obj = match.group('obj')
            merge_candidates[var] = (obj, from_hex(offset))
            continue
        match = re.search(seq_regexp, line)
        if match:
            first_var = match.group('first_var')
            second_var = match.group('second_var')
            first_obj, first_offset = merge_candidates[first_var]
            second_obj, second_offset = merge_candidates[second_var]
            if first_obj != second_obj:
                raise Exception(
                    "Can't merge different object fields into double sequence: {} and {}.".format(
                        first_obj, second_obj
                    )
                )
            if first_offset != second_offset + 4:
                raise Exception(
                    "Inconsistent offsets can't merge into double sequence: {} and {}.".format(
                        first_offset, second_offset
                    )
                )
            obj = first_obj
            parameter = parameters.get(obj)
            if parameter is None:
                raise Exception("Parameter {} was not found.".format(obj))
            param_type = parameter.data_type
            if not isinstance(param_type, data_types.Pointer32):
                raise Exception(
                    "Parameter type should be pointer bat was: {}.".format(
                        param_type
                    )
                )
            param_type.pointee.merge_word32_into_double(second_offset)


def analyse_types(classes, gbl_vars, body_instructions):
    def on_expression_visited(e):
        if not isinstance(e, instructions.Assignment):
            return
        _analyse_assignment(e, gbl_vars, changed_types)
        if not isinstance(e.src, expressions.Cast):
            return
        cast = e.src
        _analyse_cast(e.dst, cast, gbl_vars, changed_types)
        if not isinstance(cast.data_type, data_types.Unknown32):
            return
        if not isinstance(e.dst, expressions.FieldAccess):
            return
        fa = e.dst
        if not isinstance(fa.expression.data_type, data_types.Pointer32):
            return
        pointee = fa.expression.data_type.pointee
        if (
            isinstance(pointee, data_types.UnknownClass) and
            isinstance(fa.expression, expressions.AddressOf) and
            isinstance(fa.expression.expression, expressions.Identifier)
        ):
            identifier = fa.expression.expression
            identifier.change_data_type(classes[pointee.class_name])
        if not isinstance(
            fa.expression.data_type.pointee, data_types.ClassType
        ):
            return
        class_type = fa.expression.data_type.pointee
        offset = class_type.find_offset_by_field_name(fa.field_name)
        class_type.merge_word32_into_double(offset)
    changed_types = {}
    while True:
        num_changed_types_before = len(changed_types)
        for instr in body_instructions:
            instr.visit(on_expression_visited)
        if len(changed_types) <= num_changed_types_before:
            break


class _FieldType:
    def __init__(self, obj_type, offset, size):
        self.obj_type = obj_type
        self.offset = offset
        self.size = size

    def make_type(self):
        data_type, field_name = self.obj_type.get_field_by_offset(self.offset)
        if data_type.size != self.size:
            raise Exception(
                "Expected size {}, but was {}".format(
                    self.size, data_type.size
                )
            )
        return data_type


def _analyse_assignment(ass, gbl_vars, changed_types):
    _push_type(ass.src, ass.dst, gbl_vars, changed_types)
    _push_type(ass.dst, ass.src, gbl_vars, changed_types)


def _push_type(from_expression, to_expression, gbl_vars, changed_types):
    try:
        data_type = _get_type_of(from_expression, changed_types)
    except UndefinedTypeException:
        return
    _push_type_down(data_type, to_expression, gbl_vars, changed_types)


def _analyse_cast(dst, src_cast, gbl_vars, changed_types):
    if not isinstance(src_cast.data_type, data_types.Pointer32):
        return
    _push_type_down(
        dst.data_type, src_cast.expression, gbl_vars, changed_types
    )


def _pointee(data_type):
    if isinstance(data_type, data_types.ClassType):
        field_type, field_name = data_type.get_field_by_offset(0)
        return _pointee(field_type)
    return data_type.pointee


def _push_type_down(data_type, e, gbl_vars, changed_types):
    if isinstance(e, expressions.AddressOf):
        _push_type_down(
            _pointee(data_type), e.expression, gbl_vars, changed_types
        )
        return
    if isinstance(e, expressions.FieldAccess):
        obj_type = e.expression.data_type.pointee
        offset = from_hex(e.field_name[-4:])
        _merge_field(obj_type, offset, data_type)
        return
    if isinstance(e, expressions.Identifier):
        try:
            new_data_type = _merge_types(e.data_type, data_type)
        except UndefinedTypeException:
            return
        e.change_data_type(new_data_type)
        changed_types[e] = new_data_type
        if (
            isinstance(e.data_type, data_types.ClassType) and
            e.address is not None
        ):
            _merge_globals_to_class(
                gbl_vars, e.address, e.data_type, changed_types
            )


def _get_type_of(e, changed_types):
    if isinstance(e, expressions.AddressOf):
        return data_types.Pointer32(_get_type_of(e.expression, changed_types))
    if isinstance(e, expressions.Identifier):
        if e in changed_types:
            data_type = changed_types[e]
            if isinstance(data_type, _FieldType):
                data_type = data_type.make_type()
            return data_type
    raise UndefinedTypeException()


def _merge_globals_to_class(gbl_vars, address, data_type, changed_types):
    globals_to_be_removed = []
    for gbl in gbl_vars.values():
        if gbl.address <= address:
            continue
        if gbl.address >= address + data_type.size:
            break
        _merge_field(data_type, gbl.address - address, gbl.data_type)
        changed_types[gbl] = _FieldType(
            data_type, gbl.address - address, gbl.data_type.size
        )
        globals_to_be_removed.append(gbl.name)
    for gbl_name in globals_to_be_removed:
        del gbl_vars[gbl_name]


def _merge_field(obj_type, offset, new_field_type):
    try:
        field_type, field_name = obj_type.get_field_by_offset(offset)
    except KeyError:
        obj_type.add_field(offset, new_field_type)
        return
    try:
        new_field_type = _merge_types(field_type, new_field_type)
    except UndefinedTypeException:
        return
    obj_type.add_field(offset, new_field_type)


def _merge_types(data_type, new_data_type):
    if data_type == new_data_type:
        raise UndefinedTypeException()
    if data_type is None:
        return new_data_type
    if (
        isinstance(new_data_type, data_types.Pointer32) and
        isinstance(data_type, data_types.Pointer32)
    ):
        return data_types.Pointer32(
            _merge_types(data_type.pointee, new_data_type.pointee)
        )
    if isinstance(new_data_type, data_types.ClassType):
        if isinstance(data_type, data_types.Pointer32):
            _merge_field(new_data_type, 0, data_type)
            return new_data_type
    raise Exception(
        "Can't merge {} with {}.".format(
            data_type, new_data_type
        )
    )


def collect_used_globals(gbl_vars, body_instructions):
    def on_expression_visited(e):
        if not isinstance(e, expressions.Identifier):
            return
        used_ids.add(e.name)
    used_ids = set()
    for instr in body_instructions:
        instr.visit(on_expression_visited)
    return dict(
        (name if gbl.data_type is None else gbl.name, gbl)
        for name, gbl in gbl_vars.items() if gbl.name in used_ids
    )


def _is_addr_of_local(e):
    if (
        isinstance(e, expressions.AddressOf) and
        isinstance(e.expression, expressions.Identifier)
    ):
        return True
    if (
        isinstance(e, expressions.Bin) and
        isinstance(e.left, expressions.Identifier) and
        e.left.name == "fp"
    ):
        return True
    return False


def _collect_addr_of_locals(pc, recompiled_decls, full_typed_args_by_proc):
    if pc.callee_address not in recompiled_decls:
        return
    callee_decl = recompiled_decls[pc.callee_address]
    parameters = list(callee_decl.get_parameters_ids().keys())
    for i in range(len(parameters)):
        if _is_addr_of_local(pc.arguments[i]):
            if pc.callee_address not in full_typed_args_by_proc:
                full_typed_args = set()
                full_typed_args_by_proc[pc.callee_address] = full_typed_args
            else:
                full_typed_args = full_typed_args_by_proc[pc.callee_address]
            full_typed_args.add(parameters[i])


def extract_callees(body_instructions, recompiled_decls):
    def on_expression_visited(e):
        if not isinstance(e, expressions.ProcedureCall):
            return
        if e.callee_address is not None:
            callees.add(e.callee_address)
            _collect_addr_of_locals(e, recompiled_decls, full_typed_args_by_proc)
    callees = set()
    full_typed_args_by_proc = {}
    for instr in body_instructions:
        instr.visit(on_expression_visited)
    return (callees, full_typed_args_by_proc)
