import json
import argparse
import os
import os.path
import re
import time

from calling_convention import CallingConvention
from common_header import create_common_header
import data_types
from exceptions import SkippedProcedureException, NextRunException
import execute
from files_location import FilesLocation
from header_declarations import HeaderDeclarations
from hex_conversion import from_hex
import intermediate_analysis as analysis
import make_project as prj
from output_dir import process_output_dir
import parser
from procedure_declaration import ProcedureDeclaration

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
    (callees, full_typed_args_by_proc) = analysis.extract_callees(
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
        analysis.ensure_class_fields(method_class, body_instructions)
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
    analysis.merge_double_fields(parameters, body_instructions)
    analysis.analyse_types(classes, body_instructions)
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
    analysis.guess_float_fields(proc_decl, par_by_orig_name, body_instructions)
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
