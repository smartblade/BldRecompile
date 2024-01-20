import json
import argparse
import os
import os.path
import re
import time

from calling_convention import CallingConvention
import data_types
from exceptions import SkippedProcedureException, NextRunException
import execute
import expressions
from expressions.operator import Operator
from files_location import FilesLocation
from header_declarations import HeaderDeclarations
from hex_conversion import from_hex
import instructions
import make_project as prj
from output_dir import process_output_dir
import parser
from procedure_declaration import ProcedureDeclaration
from writer import Writer

argument_parser = argparse.ArgumentParser()
argument_parser.add_argument(
    "--rebuild", action='store_true', dest="rebuild",
    help="Clean up intermediate and output directories and rerun Reko."
)
options = argument_parser.parse_args()


def process_output_code(file_name, addr):
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_output_code(lines, addr)


def ensure_class_fields(method_class, body_instructions):
    char_cast_regexp = re.compile(
        r'^(\(char\s*\*\)\s*ecx|&ecx->(?P<field_name>\w+))$'
    )
    offset_regexp = re.compile(r'^(?P<offset>\d+)$')
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
    field_regexp = re.compile(r'^dw(?P<offset>[\dABCDEF]+)\s*$')
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
    field_access_regexp = re.compile('unknown32\s(?P<var>\w+)\s*=\s*(?P<obj>\w+)->dw(?P<offset>[\dABCDEF]+)')
    seq_regexp = re.compile('double\s\w+\s*=\s*SEQ\((?P<first_var>\w+),\s(?P<second_var>\w+)\)')
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
            parameter_found = False
            for param_type, param_name in parameters:
                if param_name == obj:
                    parameter_found = True
                    if not isinstance(param_type, data_types.Pointer32):
                        raise Exception(
                            "Parameter type should be pointer bat was: {}.".format(
                                 param_type
                             )
                        )
                    param_type.pointee.merge_word32_into_double(second_offset)
            if not parameter_found:
                raise Exception("Parameter {} was not found.".format(obj))

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


def is_addr_of_local(e):
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

def collect_addr_of_locals(pc, recompiled_decls, full_typed_args_by_proc):
    if pc.callee_address not in recompiled_decls:
        return
    callee_decl = recompiled_decls[pc.callee_address]
    parameters = list(callee_decl.get_parameters_ids().keys())
    for i in range(len(parameters)):
        if is_addr_of_local(pc.arguments[i]):
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
            collect_addr_of_locals(e, recompiled_decls, full_typed_args_by_proc)
    callees = set()
    full_typed_args_by_proc = {}
    for instr in body_instructions:
        instr.visit(on_expression_visited)
    return (callees, full_typed_args_by_proc)


def process_header_file(file_name, defined_types):
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_header_declarations(lines, defined_types)


def process_globals_file(file_name, defined_types):
    if file_name is None:
        return {}
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_globals_declarations(lines, defined_types)


def process_dis_file(file_name):
    field_access_regexp = re.compile('//\sstackDelta:\s(?P<stack_offset>\d+);\sfpuStackDelta:\s(?P<fpu_offset>\d+);')
    with open(file_name) as f:
        for line in f:
            match = re.search(field_access_regexp, line)
            if match:
                stack_offset = int(match.group('stack_offset'))
                fpu_offset = int(match.group('fpu_offset'))
                return (stack_offset, fpu_offset)


def load_callees(files):
    try:
        with open(files.callees_json, "rt") as f:
            return json.load(f)
    except FileNotFoundError:
       return None

def dump_callees(files, callees):
    with open(files.callees_json, "wt") as f:
        json.dump(list(sorted(callees)), f)


def ensure_class_name(c, default_name):
    if not c.class_name or c.class_name.startswith("Eq_"):
        return c.rename(default_name)
    return c


def process_intermediate_output(files, addr, recompiled_decls):
    output = process_output_dir(files.project_output)
    stack_offset, fpu_offset = process_dis_file(output.dis_file)
    if fpu_offset != 0 and fpu_offset != 1:
        raise Exception("Unsupported FPU offset: {}".format(fpu_offset))
    proc, body_instructions = process_output_code(output.code_file, addr)
    (callees, full_typed_args_by_proc) = extract_callees(
        body_instructions, recompiled_decls
    )
    dump_callees(files, callees)
    if len(set(callees) - set(recompiled_decls)) > 0:
        raise SkippedProcedureException()
    defined_types = {}
    for callee_add in full_typed_args_by_proc.keys():
        callee_decl = recompiled_decls[callee_add]
        defined_types.update(callee_decl.get_used_types())
    declarations = process_header_file(output.header_file, defined_types)
    gbl_vars = process_globals_file(output.globals_file, defined_types)
    classes = declarations.defined_types
    method_class = None
    if proc.class_type is not None:
        ptr_to_class = parser.parse_data_type(proc.class_type, classes)
        if (isinstance(ptr_to_class, data_types.Pointer32)):
            if ptr_to_class.pointee is None:
                method_class = data_types.ClassType("", {})
            else:
                method_class = ptr_to_class.pointee
        else:
            raise Exception(
                "Not supported type as method class: {}.".format(ptr_to_class)
            )
        method_class = ensure_class_name(
            method_class, "unknown_class_{}".format(addr)
        )
        ensure_class_fields(method_class, body_instructions)
    if proc.class_type is not None:
        convention = CallingConvention.THISCALL
    else:
        if stack_offset == 4:
            convention = CallingConvention.CDECL
        else:
            convention = CallingConvention.STDCALL
    parameters = []
    cur_offset = 4  # Return address size at stack
    par_by_orig_name = {"ecx": "this"}
    for (var_type, var_name) in proc.parameters:
        offset = from_hex(var_name[-2:])
        fill_unused_params(parameters, cur_offset, offset - cur_offset)
        var_type = parser.parse_data_type(var_type, classes)
        if (
            isinstance(var_type, data_types.Pointer32) and
            isinstance(var_type.pointee, data_types.ClassType)
        ):
            var_type = data_types.Pointer32(
                ensure_class_name(
                    var_type.pointee,
                    "unknown_class_{}_p_{}".format(addr, var_name[-2:])
                )
            )
        par_by_orig_name[var_name] = parser.define_parameter_name(
            var_type, var_name
        )
        var_name = par_by_orig_name[var_name]
        parameters.append((var_type, var_name))
        cur_offset = offset + var_type.size
    if convention != CallingConvention.CDECL:
        fill_unused_params(parameters, cur_offset, stack_offset - cur_offset)
    merge_double_fields(parameters, body_instructions)
    analyse_types(classes, body_instructions)
    if fpu_offset == 1:
        return_arg = data_types.Double()
    else:
        return_arg = data_types.Unknown32()
    if method_class is not None:
        proc_name = "unknown_method_{}".format(addr)
    else:
        proc_name = "unknown_function_{}".format(addr)
    proc_decl = ProcedureDeclaration(
        proc_name=proc_name,
        convention=convention,
        method_class=method_class,
        parameters=parameters,
        return_arg=return_arg,
    )
    if method_class is not None:
        method_class.add_method(proc_decl)
    guess_float_fields(proc_decl, par_by_orig_name, body_instructions)
    return HeaderDeclarations(
        proc_decl, recompiled_decls, full_typed_args_by_proc,
        declarations.external_procedures, gbl_vars
    )

def fill_unused_params(parameters, offset, size):
    if size < 0:
        raise Exception(
            "Inconsistent parameters at {:X} before {:X} offset.".format(
                offset + size, offset
            )
        )
    if size % 4 != 0:
        raise Exception("Size {} should be multiple of 4.".format(size))
    for i in range(offset, offset + size, 4):
        parameters.append(
            (data_types.Unknown32(), "unused_param_{:02X}".format(i))
        )


def extract_procedure_body(file_name, declarations):
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_procedure_body(lines, declarations)


def process_final_output(files, declarations, addr):
    output = process_output_dir(files.project_output)
    body = extract_procedure_body(output.code_file, declarations)
    body.transform_instructions(declarations)
    cpp_file_name = os.path.join(files.output, "{}.cpp".format(addr))
    with open(cpp_file_name, "wt") as f:
        f.write(body.emit_code())
    header_file_name = os.path.join(
        files.output, "{}.h".format(declarations.proc_decl.proc_name)
    )
    with open(header_file_name, "wt") as f:
        f.write(declarations.emit_header())
    execute.compile_cpp(files, cpp_file_name, header_file_name)


def next_run(files, run_callback, max_times):
    for i in range(max_times):
        with files.next_run() as run_files:
            try:
                return run_callback(run_files)
            except NextRunException:
                pass

def process_procedure(files, addr, recompiled_decls):
    def intermediate_output(run_files):
        callees = load_callees(files)
        declarations = HeaderDeclarations(
            None, recompiled_decls, full_typed_args_by_proc, [], {}
        )
        prj.make_procedure_project(run_files, callees, addr, declarations)
        prj.set_output_dir(run_files.project, run_files.project_output_basename)
        prj.set_declarations(run_files, declarations, addr)
        execute.reko(run_files, has_decl_file=False)
        declarations = process_intermediate_output(
            run_files, addr, recompiled_decls
        )
        if (
            len(declarations.full_typed_args_by_proc) > 0 and
            len(full_typed_args_by_proc) == 0
        ):
            full_typed_args_by_proc.update(declarations.full_typed_args_by_proc)
            raise NextRunException()
        return declarations
    def final_output(run_files):
        callees = load_callees(files)
        prj.make_procedure_project(run_files, callees, addr, declarations)
        prj.set_output_dir(run_files.project, run_files.project_output_basename)
        prj.set_declarations(run_files, declarations, addr)
        execute.reko(run_files)
        process_final_output(run_files, declarations, addr)
    full_typed_args_by_proc = {}
    declarations = next_run(files, intermediate_output, max_times=2)
    next_run(files, final_output, max_times=2)
    return declarations.proc_decl

def create_common_header(files):
    with open(files.common_header_name, "wt") as f:
        f.write("#pragma once\n\n")
        f.write("#include <math.h>\n")
        f.write("#include <string.h>\n\n")
        f.write("typedef char unknown_byte;\n")
        f.write("typedef int unknown32;\n")

def run():
    root_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..")
    files = FilesLocation(root_path, options.rebuild)
    with open(files.procedures_dict_file, "rt") as f:
        proc_dict = json.load(f)
    prj.make_project_file(
        files.project_template, files.intermediate_project, proc_dict.keys(),
        HeaderDeclarations(None, {}, {}, [], {})
    )
    create_common_header(files)
    recompiled_decls = {}
    for addr, proc in proc_dict.items():
        try:
            recompiled_decls[addr] = process_procedure(
                files.for_procedure(addr), addr, recompiled_decls
            )
        except SkippedProcedureException:
            print("Skipping {} procedure...".format(addr))
        if addr >= "00407E80":
            break

if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
