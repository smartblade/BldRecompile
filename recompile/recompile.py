import hashlib
import json
import argparse
import os
import os.path
import re
import shutil
import subprocess
import sys
import time

from assignment import Assignment
from calling_convention import CallingConvention
from class_type import ClassType
import code_parser as parser
from double import Double
from exceptions import SkippedProcedureException, NextRunException
from files_location import FilesLocation
from hex_conversion import from_hex
from pointer32 import Pointer32
from parse_instructions import parse_instructions
from procedure_call import ProcedureCall
from procedure_body import ProcedureBody
from procedure_declaration import ProcedureDeclaration
from unknown32 import Unknown32
from unparsed_tokens import UnparsedTokens
from writer import Writer

argument_parser = argparse.ArgumentParser()
argument_parser.add_argument(
    "--rebuild", action='store_true', dest="rebuild",
    help="Clean up intermediate and output directories and rerun Reko."
)
options = argument_parser.parse_args()

def make_project_file(
    template_name, output_file_name, proc_addrs, recompiled_calles
):
    with open(template_name) as f:
        lines = f.readlines()
    with open(output_file_name, "wt") as f:
        procedure_start = "<procedure name=\"{}\">\n"
        addr_str = "<address>{}</address>\n"
        cdecl_str = "<CSignature>{}</CSignature>\n"
        procedure_end = "</procedure>\n"
        defined_procedures = set()
        procedure_declarations_inserted = False
        for line in lines:
            if "<address>" in line:
                defined_procedures.add(line[17:25])
            if "<registerValues />" in line:
                for addr in proc_addrs:
                    if addr in defined_procedures:
                        continue
                    if addr in recompiled_calles:
                        cdecl = recompiled_calles[addr].get_declaration(
                            is_metafile=True, is_brief=True
                        )
                        proc_name = recompiled_calles[addr].proc_name
                    else:
                        cdecl = None
                        proc_name = "unknown_procedure_{}".format(addr)
                    f.write(" " * 6 + procedure_start.format(proc_name))
                    f.write(" " * 8 + addr_str.format(addr))
                    if cdecl is not None:
                        f.write(" " * 8 + cdecl_str.format(cdecl))
                    f.write(" " * 6 + procedure_end)
                procedure_declarations_inserted = True
            f.write(line)
        if not procedure_declarations_inserted:
            raise Exception(
                'Failed to insert declarations of procedures to project file.'
            )

def set_decompiled_part(project_file_name, addr):
    with open(project_file_name) as f:
        lines = f.readlines()
    with open(project_file_name, "wt") as f:
        intv_regexp = re.compile('procedure name="decompile_(?P<intv>[\d\-_ABCDEF]+)"')
        for line in lines:
            match = re.search(intv_regexp, line)
            if match:
                intv = match.group('intv')
                line = line.replace(intv, '{}'.format(addr))
            f.write(line)

def set_output_dir(project_file_name, output_dir):
    with open(project_file_name) as f:
        lines = f.readlines()
    with open(project_file_name, "wt") as f:
        for line in lines:
            if ".reko" in line:
                line = line.replace(".reko", output_dir)
            f.write(line)

def set_procedure_declaration(files, proc_decl, addr):
    emit_metafile(proc_decl, files.decl)
    cdecl = proc_decl.get_declaration(is_metafile=True)
    with open(files.project) as f:
        lines = f.readlines()
    with open(files.project, "wt") as f:
        cdecl_str = "<CSignature>{}</CSignature>\n"
        metadata_start = "<metadata>\n"
        filename_str = "<filename>{}</filename>\n"
        metadata_end = "</metadata>\n"
        decl_file_entry_written = False
        for line in lines:
            if not decl_file_entry_written and "<script>" in line:
                f.write(" " * 2 + metadata_start)
                f.write(" " * 4 + filename_str.format(files.decl_basename))
                f.write(" " * 2 + metadata_end)
                decl_file_entry_written = True
            f.write(line)
            if "<address>" in line and addr == line[17:25]:
                f.write(" " * 8 + cdecl_str.format(cdecl))

def make_procedure_project(files, addr, recompiled_decls):
    calles = load_callees(files)
    if calles is not None:
        recompiled_calles = dict(
            (addr, recompiled_decls[addr]) for addr in calles
            if addr in recompiled_decls
        )
        procs = [*calles, addr]
        make_project_file(
            files.project_template, files.project, sorted(procs),
            recompiled_calles,
        )
    else:
        shutil.copyfile(files.intermediate_project, files.project)
    set_decompiled_part(files.project, addr)

def execute_command(command):
    print("command started: {}".format(command))
    process = subprocess.Popen(command)
    code = process.wait()
    print("command finished with code {}".format(code))
    if code:
        raise Exception('Failed to execute {}.'.format(command))

def emit_metafile(proc_decl, decl_file_name):
    with open(decl_file_name, "wt") as f:
        f.write(proc_decl.get_types_declarations(is_metafile=True))

def process_output_code(file_name, addr):
    with open(file_name) as f:
        lines = f.readlines()
    body_lines = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("}"):
            return proc, parse_instructions(body_lines, {})
        if addr in line:
            proc = parser.parse_procedure_declaration(line)
        elif line.startswith("{"):
            body_lines = []
        elif body_lines is not None:
            body_lines.append(line)

def ensure_class_fields(method_class, body_instructions):
    field_offset_regexp = re.compile('\(char\s*\*\)\s*ecx\s*\+\s*(?P<offset>\d+)')
    def on_expression_visited(e):
        if isinstance(e, UnparsedTokens):
            match = re.search(field_offset_regexp, e.emit_code())
            if match:
                offset = match.group('offset')
                method_class.ensure_field(int(offset))
    for instr in body_instructions:
        instr.visit(on_expression_visited)

def guess_float_fields(method_class, body_instructions):
    field_access_regexp = re.compile('^ecx->dw(?P<offset>[\dABCDEF]+)\s*$')
    hex_regexp = re.compile('^\s*0x(?P<const>[\dABCDEF]+)$')
    def on_expression_visited(e):
        if not isinstance(e, Assignment):
            return
        match = re.search(field_access_regexp, e.dst.emit_code())
        if not match:
            return
        offset = match.group('offset')
        match = re.search(hex_regexp, e.src.emit_code())
        if not match:
            return
        const = match.group('const')
        if const == "3FF00000":
            method_class.merge_word32_into_double(from_hex(offset) - 4)
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
                    if not isinstance(param_type, Pointer32):
                        raise Exception(
                            "Parameter type should be pointer bat was: {}.".format(
                                 param_type
                             )
                        )
                    param_type.pointee.merge_word32_into_double(second_offset)
            if not parameter_found:
                raise Exception("Parameter {} was not found.".format(obj))

def extract_callees(body_instructions):
    def on_expression_visited(e):
        if isinstance(e, ProcedureCall) and e.callee_address is not None:
            callees.add(e.callee_address)
    callees = set()
    for instr in body_instructions:
        instr.visit(on_expression_visited)
    return callees

def define_parameter_name(field_type, parameter_name):
    if isinstance(field_type, Unknown32):
        parameter_name = parameter_name.replace("dwArg", "unknown_param_")
    elif isinstance(field_type, Pointer32):
        parameter_name = parameter_name.replace("dwArg", "unknown_ptr_")
    elif isinstance(field_type, Double):
        parameter_name = parameter_name.replace("rArg", "unknown_double_")
    return parameter_name

def process_header_file(file_name):
    with open(file_name) as f:
        lines = f.readlines()
    return parser.parse_data_types_declarations(lines)

def process_dis_file(file_name):
    field_access_regexp = re.compile('//\sstackDelta:\s(?P<stack_offset>\d+);\sfpuStackDelta:\s(?P<fpu_offset>\d+);')
    with open(file_name) as f:
        for line in f:
            match = re.search(field_access_regexp, line)
            if match:
                stack_offset = int(match.group('stack_offset'))
                fpu_offset = int(match.group('fpu_offset'))
                return (stack_offset, fpu_offset)

def reduce_header_file(header_file):
    with open(header_file) as f:
        lines = f.readlines()
    with open(header_file, "wt") as f:
        skip = False
        for line in lines:
            if line.startswith("//"):
                continue
            elif line.startswith("/*"):
                skip = True
            elif line.startswith("*/"):
                skip = False
                continue
            elif line.startswith("typedef struct Globals"):
                skip = True
            elif line.startswith("}"):
                if skip:
                    skip = False
                    continue
            if skip:
                continue
            f.write(line)

def process_output_dir(output_dir):
    for root, dirs, files in os.walk(output_dir):
        for file in files:
            if file.endswith("globals.c"):
                continue
            if file.endswith(".c"):
                code_file = os.path.join(output_dir, file)
            elif file.endswith(".h"):
                header_file = os.path.join(output_dir, file)
                reduce_header_file(header_file)
            elif file.endswith(".dis"):
                dis_file = os.path.join(output_dir, file)
    return (code_file, header_file, dis_file)

def load_callees(files):
    try:
        with open(files.callees_json, "rt") as f:
            return json.load(f)
    except FileNotFoundError:
       return None

def dump_callees(files, callees):
    with open(files.callees_json, "wt") as f:
        json.dump(list(sorted(callees)), f)

def process_intermediate_output(files, addr, recompiled_decls):
    code_file, header_file, dis_file = process_output_dir(files.project_output)
    stack_offset, fpu_offset = process_dis_file(dis_file)
    if fpu_offset != 0 and fpu_offset != 1:
        raise Exception("Unsupported FPU offset: {}".format(fpu_offset))
    proc, body_instructions = process_output_code(code_file, addr)
    callees = extract_callees(body_instructions)
    dump_callees(files, callees)
    if len(set(callees) - set(recompiled_decls)) > 0:
        raise SkippedProcedureException()
    classes = process_header_file(header_file)
    method_class = None
    if proc.class_type is not None:
        ptr_to_class = parser.parse_data_type(proc.class_type, classes)
        if (isinstance(ptr_to_class, Pointer32)):
            if ptr_to_class.pointee is None:
                method_class = ClassType("", {})
            else:
                method_class = ptr_to_class.pointee
        else:
            raise Exception(
                "Not supported type as method class: {}.".format(ptr_to_class)
            )
        method_class = method_class.rename("unknown_class_{}".format(addr))
        ensure_class_fields(method_class, body_instructions)
        guess_float_fields(method_class, body_instructions)
    if proc.class_type is not None:
        convention = CallingConvention.THISCALL
    else:
        if stack_offset == 4:
            convention = CallingConvention.CDECL
        else:
            convention = CallingConvention.STDCALL
    parameters = []
    cur_offset = 4 #Return address size at stack
    for (var_type, var_name) in proc.parameters:
        offset = from_hex(var_name[-2:])
        fill_unused_params(parameters, cur_offset, offset - cur_offset)
        var_type = parser.parse_data_type(var_type, classes)
        if (
            isinstance(var_type, Pointer32) and
            isinstance(var_type.pointee, ClassType)
        ):
            var_type = Pointer32(
                var_type.pointee.rename(
                    "unknown_class_{}_p_{}".format(addr, var_name[-2:])
                )
            )
        var_name = define_parameter_name(var_type, var_name)
        parameters.append((var_type, var_name))
        cur_offset = offset + var_type.size
    if convention != CallingConvention.CDECL:
        fill_unused_params(parameters, cur_offset, stack_offset - cur_offset)
    merge_double_fields(parameters, body_instructions)
    if fpu_offset == 1:
        return_arg = Double()
    else:
        return_arg = Unknown32()
    proc_decl = ProcedureDeclaration(
        proc_name="unknown_method_{}".format(addr),
        convention=convention,
        method_class=method_class,
        parameters=parameters,
        return_arg=return_arg,
    )
    if method_class is not None:
        method_class.add_method(proc_decl)
    return proc_decl

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
        parameters.append((Unknown32(), "unused_param_{:02X}".format(i)))

def extract_procedure_body(file_name, proc_decl):
    with open(file_name) as f:
        lines = f.readlines()
    instructions = None
    for line in lines:
        if line.startswith("//"):
            continue
        if proc_decl.proc_name in line:
            proc_decl.extract_return_arg_from_line(line)
        if line.startswith("{"):
            instructions = []
            continue
        if line.startswith("}"):
            return ProcedureBody(proc_decl, instructions)
        if instructions is not None:
            instructions.append(line)

def process_final_output(files, proc_decl, addr, recompiled_decls):
    code_file, header_file, dis_file = process_output_dir(files.project_output)
    body = extract_procedure_body(code_file, proc_decl)
    body.transform_instructions(recompiled_decls)
    cpp_file_name = os.path.join(files.output, "{}.cpp".format(addr))
    with open(cpp_file_name, "wt") as f:
        f.write(body.emit_code())
    header_file_name = os.path.join(
        files.output, "{}.h".format(proc_decl.proc_name)
    )
    with open(header_file_name, "wt") as f:
        f.write(body.emit_header())
    compile_cpp(files, cpp_file_name, header_file_name)

def update_hash(hasher, file_name):
    with open(file_name, "rb") as f:
        hasher.update(f.read())
    return hasher.digest()

def is_hash_changed(hash_file_name, new_hash):
    try:
        with open(hash_file_name, "rb") as f:
            existing_hash = f.read()
            return existing_hash != new_hash
    except FileNotFoundError:
        return True

def write_hash(hash_file_name, new_hash):
    with open(hash_file_name, "wb") as f:
        f.write(new_hash)

def execute_reko(files, has_decl_file=True):
    hasher = hashlib.sha256()
    update_hash(hasher, files.project)
    if has_decl_file:
        update_hash(hasher, files.decl)
    new_hash = hasher.digest()
    if not is_hash_changed(files.reko_hash, new_hash):
        print("Input files were not changed: skipping executing of Reko...")
        return
    execute_command([files.reko_cmdline, files.project])
    write_hash(files.reko_hash, new_hash)

def compile_cpp(files, cpp_file_name, header_file_name):
    hasher = hashlib.sha256()
    update_hash(hasher, cpp_file_name)
    update_hash(hasher, header_file_name)
    new_hash = hasher.digest()
    if not is_hash_changed(files.compile_hash, new_hash):
        print("Source files were not changed: skipping compilation...")
        return
    execute_command([files.compile_bat, cpp_file_name])
    write_hash(files.compile_hash, new_hash)

def next_run(files, run_callback, max_times):
    for i in range(max_times):
        with files.next_run() as run_files:
            try:
                return run_callback(run_files)
            except NextRunException:
                pass

def process_procedure(files, addr, recompiled_decls):
    with files.next_run() as run_files:
        make_procedure_project(run_files, addr, recompiled_decls)
        set_output_dir(run_files.project, run_files.project_output_basename)
        execute_reko(run_files, has_decl_file=False)
        proc_decl = process_intermediate_output(
            run_files, addr, recompiled_decls
        )
    def final_output(run_files):
        make_procedure_project(run_files, addr, recompiled_decls)
        set_output_dir(run_files.project, run_files.project_output_basename)
        set_procedure_declaration(run_files, proc_decl, addr)
        execute_reko(run_files)
        process_final_output(run_files, proc_decl, addr, recompiled_decls)
    next_run(files, final_output, max_times=2)
    return proc_decl

def create_common_header(files):
    with open(files.common_header_name, "wt") as f:
        f.write("#pragma once\n\n")
        f.write("#include <math.h>\n")
        f.write("#include <string.h>\n\n")
        f.write("typedef char unknown_byte;\n")
        f.write("typedef int unknown32;\n")

def run():
    root_path = os.path.dirname(os.path.realpath(__file__))
    files = FilesLocation(root_path, options.rebuild)
    with open(files.procedures_dict_file, "rt") as f:
        proc_dict = json.load(f)
    make_project_file(
        files.project_template, files.intermediate_project, proc_dict.keys(), {}
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
        if addr >= "00405F0D":
            break

if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
