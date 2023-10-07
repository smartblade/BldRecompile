from collections import namedtuple
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

from class_type import ClassType
from double import Double
from files_location import FilesLocation
from pointer32 import Pointer32
from procedure_body import ProcedureBody
from unknown32 import Unknown32

parser = argparse.ArgumentParser()
parser.add_argument(
    "--rebuild", action='store_true', dest="rebuild",
    help="Clean up intermediate and output directories and rerun Reko."
)
options = parser.parse_args()

def toHex(n):
    return format(n, '08X')

def fromHex(h):
    return int(h, 16)

def make_tuple(name, **kwargs):
    return namedtuple(name, kwargs.keys())(**kwargs)

def make_project_file(template_name, output_file_name, proc_dict):
    with open(template_name) as f:
        lines = f.readlines()
    with open(output_file_name, "wt") as f:
        procedure_start = "<procedure name=\"unknown_procedure_{}\">\n"
        addr_str = "<address>{}</address>\n"
        procedure_end = "</procedure>\n"
        defined_procedures = set()
        procedure_declarations_inserted = False
        for line in lines:
            if "<address>" in line:
                defined_procedures.add(line[17:25])
            if "<registerValues />" in line:
                for addr in proc_dict.keys():
                    if addr in defined_procedures:
                        continue
                    f.write(" " * 6 + procedure_start.format(addr))
                    f.write(" " * 8 + addr_str.format(addr))
                    f.write(" " * 6 + procedure_end)
                procedure_declarations_inserted = True
            f.write(line)
        if not procedure_declarations_inserted:
            raise Exception(
                'Failed to insert declarations of procedures to project file.'
            )

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
    cdecl = emit_cdecl(proc_decl)
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

def execute_command(command):
    print("command started: {}".format(command))
    process = subprocess.Popen(command)
    code = process.wait()
    print("command finished with code {}".format(code))
    if code:
        raise Exception('Failed to execute {}.'.format(command))

def parse_variable_declaration(s):
    last_space = s.rfind(' ')
    if last_space < 0:
        raise Exception("Failed to parse variable declaration: ' ' was not found.")
    return (s[:last_space], s[last_space + 1:])

def parse_procedure_declaration(s):
    start_brackets_pos = s.find("(")
    if start_brackets_pos < 0:
        raise Exception("Failed to parse declaration: '(' was not found.")
    end_brackets_pos = s.find(")")
    if end_brackets_pos < 0:
        raise Exception("Failed to parse declaration: ')' was not found.")
    parameters = s[start_brackets_pos + 1:end_brackets_pos].split(',')
    parsed_parameters = []
    for p in parameters:
        parsed_parameters.append(parse_variable_declaration(p.strip()))
    var_type, var_name = parsed_parameters[0]
    # Check if it is 'thiscall' convention
    if var_name == "ecx":
        return make_tuple(
            'ProcedureDeclation',
             class_type=var_type,
             parameters=parsed_parameters[1:])
    else:
        raise Exception("Only thiscall is implemented.")

def extract_class_name(class_type):
    type_tokens = class_type.split(" ")
    if type_tokens[0] != "struct":
        return None
    if type_tokens[-1] != "*":
        raise Exception("Only pointers is supported for thiscall parameter.")
    class_name = type_tokens[1]
    if not class_name.startswith("Eq_"):
        raise Exception("Class name should be started with 'Eq_'.")
    return class_name

def parse_data_type(s, classes):
    if s == "word32":
        return Unknown32()
    if s == "real64":
        return Double()
    if s == "<unknown>*":
        return Pointer32()
    class_name = extract_class_name(s)
    if class_name is not None:
        return Pointer32(classes[class_name])
    raise Exception("Not implemented type: {}.".format(s))

def emit_cdecl(proc_decl):
    if proc_decl.method_class is None:
        raise Exception("Only thiscall is implemented.")
    this_arg = "{} *this".format(proc_decl.method_class.class_name)
    parameters = [this_arg]
    for parameter_type, parameter_name in proc_decl.parameters:
        parameters.append(
            "{} {}".format(
                parameter_type.get_type_name(is_metafile=True),
                parameter_name,
            )
        )
    return "word32 __thiscall {}({})".format(
        proc_decl.proc_name, ", ".join(parameters)
    )

def emit_metafile(proc_decl, decl_file_name):
    with open(decl_file_name, "wt") as f:
        if proc_decl.method_class is None:
            raise Exception("Only thiscall is implemented.")
        for arg_type, arg_name in proc_decl.parameters:
            if (
                isinstance(arg_type, Pointer32) and
                isinstance(arg_type.pointee, ClassType)
            ):
                f.write(arg_type.pointee.get_declaration(is_metafile=True))
                f.write("\n")
        class_decl = proc_decl.method_class.get_declaration(is_metafile=True)
        f.write(class_decl)

def process_output_code(file_name, addr):
    with open(file_name) as f:
        lines = f.readlines()
    body_lines = None
    for line in lines:
        if line.startswith("//"):
            continue
        if addr in line:
            proc = parse_procedure_declaration(line)
            body_lines = []
        elif body_lines is not None:
            body_lines.append(line)
        if line.startswith("}"):
            return proc, body_lines

def ensure_class_fields(method_class, body_lines):
    field_offset_regexp = re.compile('\(char\s*\*\)\s*ecx\s*\+\s*(?P<offset>\d+)')
    for line in body_lines:
        match = re.search(field_offset_regexp, line)
        if match:
            offset = match.group('offset')
            method_class.ensure_field(int(offset))

def define_field_name(field_type, field_name):
    if isinstance(field_type, Unknown32):
        field_name = field_name.replace("dw", "unknown_field_")
    elif isinstance(field_type, Double):
        field_name = field_name.replace("t", "unknown_double_")
    return field_name

def define_parameter_name(field_type, parameter_name):
    if isinstance(field_type, Unknown32):
        parameter_name = parameter_name.replace("dwArg", "unknown_param_")
    if isinstance(field_type, Pointer32):
        parameter_name = parameter_name.replace("dwArg", "unknown_ptr_")
    return parameter_name

def process_header_file(file_name, required_classes):
    with open(file_name) as f:
        lines = f.readlines()
    unions = {}
    classes = {}
    cur_class = None
    union_types = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("typedef struct Eq_"):
            class_name = line.split(" ")[2]
            cur_class = {}
        elif cur_class is not None:
            if line.startswith("}"):
                classes[class_name] = cur_class
                cur_class = None
                continue
            tokens = line.split("//")
            offset = fromHex(tokens[1])
            decl = tokens[0].strip().strip(";")
            var_type, var_name = parse_variable_declaration(decl)
            cur_class[offset] = (var_type, var_name)
        elif line.startswith("typedef union Eq_"):
            union_name = line.split(" ")[2]
            union_types = {}
        elif union_types is not None:
            if line.startswith("}"):
                unions[union_name] = union_types
                union_types = None
                continue
            decl = line.strip().strip(";")
            var_type, var_name = parse_variable_declaration(decl)
            union_types[var_type] = var_name
    for class_name in required_classes.keys():
        skip_offset_if_word32 = None
        new_fields = {}
        for offset, (var_type, var_name) in classes[class_name].items():
            if offset == skip_offset_if_word32 and var_type == "word32":
                continue
            if (
                var_type in unions and
                "real64" in unions[var_type] and
                "word32" in unions[var_type]
            ):
                # Merge 2 'word32' fields into 1 'double'
                var_type = "real64"
                skip_offset_if_word32 = offset + 4
            var_type = parse_data_type(var_type, {})
            var_name = define_field_name(var_type, var_name)
            new_fields[offset] = (var_type, var_name)
        required_classes[class_name] = ClassType(class_name, new_fields)

def process_output_dir(output_dir):
    for root, dirs, files in os.walk(output_dir):
        for file in files:
            if file.endswith("globals.c"):
                continue
            if file.endswith(".c"):
                code_file = os.path.join(output_dir, file)
            if file.endswith(".h"):
                header_file = os.path.join(output_dir, file)
    return (code_file, header_file)

def process_intermediate_output(output_dir, addr):
    code_file, header_file = process_output_dir(output_dir)
    proc, body_lines = process_output_code(code_file, addr)
    class_name = extract_class_name(proc.class_type)
    classes = {}
    if class_name is not None:
        classes[class_name] = None
    for (var_type, var_name) in proc.parameters:
        class_name = extract_class_name(var_type)
        if class_name is not None:
            classes[class_name] = None
    process_header_file(header_file, classes)
    method_class = None
    if proc.class_type is not None:
        ptr_to_class = parse_data_type(proc.class_type, classes)
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
        ensure_class_fields(method_class, body_lines)
    parameters = []
    for (var_type, var_name) in proc.parameters:
        var_type = parse_data_type(var_type, classes)
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
    proc_decl = make_tuple(
        'ProcedureDeclation',
        proc_name = "unknown_method_{}".format(addr),
        method_class=method_class,
        parameters=parameters,
    )
    if method_class is not None:
        method_class.add_method(proc_decl)
    return proc_decl

def extract_procedure_body(file_name, proc_decl):
    with open(file_name) as f:
        lines = f.readlines()
    instructions = None
    for line in lines:
        if line.startswith("//"):
            continue
        if proc_decl.proc_name in line:
            name_pos = line.find(proc_decl.proc_name)
            return_arg = line[:name_pos].strip()
            proc_decl = make_tuple(
                'ProcedureDeclation',
                 return_arg=return_arg,
                 **proc_decl._asdict(),
            )
            if proc_decl.method_class is not None:
                proc_decl.method_class.update_method(proc_decl)
        if line.startswith("{"):
            instructions = []
            continue
        if line.startswith("}"):
            return ProcedureBody(proc_decl, instructions)
        if instructions is not None:
            instructions.append(line)

def process_final_output(files, proc_decl, addr):
    code_file, header_file = process_output_dir(files.project_output)
    body = extract_procedure_body(code_file, proc_decl)
    body.transform_instructions()
    cpp_file_name = os.path.join(files.output, "{}.cpp".format(addr))
    with open(cpp_file_name, "wt") as f:
        f.write(body.emit_code())
    header_file_name = os.path.join(
        files.output, "{}.h".format(proc_decl.proc_name)
    )
    with open(header_file_name, "wt") as f:
        f.write(body.emit_header())
    execute_command([files.compile_bat, cpp_file_name])

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
    hash_file_name = files.project + ".obj"
    hasher = hashlib.sha256()
    update_hash(hasher, files.project)
    if has_decl_file:
        update_hash(hasher, files.decl)
    new_hash = hasher.digest()
    if not is_hash_changed(hash_file_name, new_hash):
        print("Input files were not changed: skipping executing of Reko...")
        return
    execute_command([files.reko_cmdline, files.project])
    write_hash(hash_file_name, new_hash)

def process_procedure(files, addr):
    command = [
        sys.executable, files.decompile_file_part_py,
        "--file-name={}".format(files.intermediate_project),
        "--start-address={}".format(addr),
        "--end-address={}".format(toHex(fromHex(addr) + 1))
    ]
    execute_command(command)
    fname_regexp = re.compile('^(?P<fname>.+)\.(?P<ext>.+)')
    match = re.search(fname_regexp, files.intermediate_project)
    output_file_name = "{}_{}-{}.{}".format(
        match.group('fname'),
        addr,
        toHex(fromHex(addr) + 1),
        match.group('ext'))
    with files.next_run() as run_files:
        shutil.copyfile(output_file_name, run_files.project)
        set_output_dir(run_files.project, run_files.project_output_basename)
        execute_reko(run_files, has_decl_file=False)
        proc_decl = process_intermediate_output(run_files.project_output, addr)
    with files.next_run() as run_files:
        shutil.copyfile(output_file_name, run_files.project)
        set_output_dir(run_files.project, run_files.project_output_basename)
        set_procedure_declaration(run_files, proc_decl, addr)
        execute_reko(run_files)
        process_final_output(run_files, proc_decl, addr)

def create_common_header(files):
    with open(files.common_header_name, "wt") as f:
        f.write("#pragma once\n\n")
        f.write("#include <string.h>\n\n")
        f.write("typedef int unknown32;\n")

def run():
    root_path = os.path.dirname(os.path.realpath(__file__))
    files = FilesLocation(root_path, options.rebuild)
    with open(files.procedures_dict_file, "rt") as f:
        proc_dict = json.load(f)
    make_project_file(
        files.project_template, files.intermediate_project, proc_dict
    )
    create_common_header(files)
    for addr, proc in proc_dict.items():
        process_procedure(files.for_procedure(addr), addr)
        if addr >= "004015F6":
            break

if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
