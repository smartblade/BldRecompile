import json
import os
import os.path
import re

from exceptions import SkippedProcedureException, NextRunException
import execute
from header_declarations import HeaderDeclarations
import intermediate_analysis as analysis
import make_project as prj
import naming
from output_dir import process_output_dir
import parser

stack_delta_regexp = re.compile(
    r'//\sstackDelta:\s(?P<stack_offset>\d+);'
    r'\sfpuStackDelta:\s(?P<fpu_offset>\d+);'
)


def process_output_code(file_name, *args, **kwargs):
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_output_code(lines, *args, **kwargs)


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
    with open(file_name) as f:
        for line in f:
            match = re.search(stack_delta_regexp, line)
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


def process_intermediate_output(files, proc_state):
    addr = proc_state.address
    output = process_output_dir(files.project_output)
    stack_offset, fpu_offset = process_dis_file(output.dis_file)
    if fpu_offset != 0 and fpu_offset != 1:
        raise Exception("Unsupported FPU offset: {}".format(fpu_offset))
    proc, body_instructions = process_output_code(
        output.code_file, addr, {}, {}
    )
    (callees, full_typed_args_by_proc) = analysis.extract_callees(
        body_instructions, proc_state.recompiled_decls
    )
    proc_state.callees = callees
    dump_callees(files, callees)
    if len(set(callees) - set(proc_state.recompiled_decls)) > 0:
        raise SkippedProcedureException()
    defined_types = {}
    for callee_add in full_typed_args_by_proc.keys():
        callee_decl = proc_state.recompiled_decls[callee_add]
        defined_types.update(callee_decl.get_used_types())
    declarations = process_header_file(output.header_file, defined_types)
    gbl_vars = process_globals_file(output.globals_file, defined_types)
    par_by_orig_name, proc_decl = parser.parse_procedure_declaration(
        proc, addr, stack_offset, fpu_offset, declarations.defined_types
    )
    parameters = proc_decl.get_parameters_ids()
    orig_parameters = dict(
        (orig_name, parameters[name])
        for orig_name, name in par_by_orig_name.items()
    )
    proc, body_instructions = process_output_code(
        output.code_file,
        addr,
        declared_identifiers={**orig_parameters, **gbl_vars},
        defined_types=declarations.defined_types,
    )
    gbl_vars = analysis.collect_used_globals(gbl_vars, body_instructions)
    naming.define_class_names(gbl_vars)
    if proc_decl.method_class is not None:
        analysis.ensure_class_fields(proc_decl.method_class, body_instructions)
    analysis.merge_double_fields(
        proc_decl.get_parameters_ids(), body_instructions
    )
    analysis.analyse_types(
        declarations.defined_types, gbl_vars, body_instructions
    )
    analysis.guess_float_fields(proc_decl, body_instructions)
    return HeaderDeclarations(
        proc_decl, proc_state.recompiled_decls, full_typed_args_by_proc,
        declarations.external_procedures, gbl_vars
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


def process_procedure(proc_state):
    addr = proc_state.address

    def intermediate_output(run_files):
        callees = load_callees(run_files)
        declarations = HeaderDeclarations(
            None, proc_state.recompiled_decls, full_typed_args_by_proc, [], {}
        )
        prj.make_procedure_project(run_files, callees, addr, declarations)
        prj.set_output_dir(run_files.project, run_files.project_output_basename)
        prj.set_declarations(run_files, declarations, addr)
        execute.reko(run_files, has_decl_file=False)
        declarations = process_intermediate_output(run_files, proc_state)
        if (
            len(declarations.full_typed_args_by_proc) > 0 and
            len(full_typed_args_by_proc) == 0
        ):
            full_typed_args_by_proc.update(declarations.full_typed_args_by_proc)
            raise NextRunException()
        return declarations

    def final_output(run_files):
        callees = load_callees(run_files)
        prj.make_procedure_project(run_files, callees, addr, declarations)
        prj.set_output_dir(run_files.project, run_files.project_output_basename)
        prj.set_declarations(run_files, declarations, addr)
        execute.reko(run_files)
        process_final_output(run_files, declarations, addr)
    full_typed_args_by_proc = {}
    declarations = next_run(proc_state.files, intermediate_output, max_times=2)
    next_run(proc_state.files, final_output, max_times=2)
    proc_state.recompiled_decls[addr] = declarations.proc_decl
