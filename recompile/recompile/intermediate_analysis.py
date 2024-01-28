import re

import data_types
import expressions
from expressions.operator import Operator
from hex_conversion import from_hex
import instructions
from writer import Writer

char_cast_regexp = re.compile(
    r'^(\(char\s*\*\)\s*ecx|&ecx->(?P<field_name>\w+))$'
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


def guess_float_fields(proc_decl, par_by_orig_name, body_instructions):
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
        if not isinstance(e.dst.expression, expressions.UnparsedToken):
            return
        parameter_name = par_by_orig_name.get(e.dst.expression.emit_code())
        if parameter_name is None:
            return
        parameter = parameters[parameter_name]
        if not isinstance(parameter.data_type, data_types.Pointer32):
            return
        parameter_class = parameter.data_type.pointee
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
            obj = first_obj.replace("dwArg", "unknown_ptr_")
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


def analyse_types(classes, body_instructions):
    def on_expression_visited(e):
        if not isinstance(e, instructions.Assignment):
            return
        if not isinstance(e.src, expressions.Cast):
            return
        cast = e.src
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
    for instr in body_instructions:
        instr.visit(on_expression_visited)


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
