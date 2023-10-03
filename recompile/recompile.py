from collections import namedtuple
import hashlib
import json
import os
import os.path
import re
import shutil
import subprocess
import sys
import time

from class_type import ClassType
from pointer32 import Pointer32
from procedure_body import ProcedureBody
from unknown32 import Unknown32

script_dir = os.path.dirname(os.path.realpath(__file__))
reko_cmdline_dir = os.path.abspath(script_dir + "/../reko")
reko_cmdline = os.path.join(reko_cmdline_dir, "decompile.exe")

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

def set_procedure_declaration(
    project_file_name, proc_decl, decl_base_name, addr
):
    decl_file_name = os.path.join(
        os.path.dirname(project_file_name), decl_base_name
    )
    emit_metafile(proc_decl, decl_file_name)
    cdecl = emit_cdecl(proc_decl)
    with open(project_file_name) as f:
        lines = f.readlines()
    with open(project_file_name, "wt") as f:
        cdecl_str = "<CSignature>{}</CSignature>\n"
        metadata_start = "<metadata>\n"
        filename_str = "<filename>{}</filename>\n"
        metadata_end = "</metadata>\n"
        decl_file_entry_written = False
        for line in lines:
            if not decl_file_entry_written and "<script>" in line:
                f.write(" " * 2 + metadata_start)
                f.write(" " * 4 + filename_str.format(decl_base_name))
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
        type_tokens = var_type.split(" ")
        if type_tokens[0] != "struct":
            raise Exception("Only structures is supported for thiscall parameter.")
        if type_tokens[-1] != "*":
            raise Exception("Only pointers is supported for thiscall parameter.")
        class_name = type_tokens[1]
        if not class_name.startswith("Eq_"):
            raise Exception("Class name should be started with 'Eq_'.")
        return make_tuple(
            'ProcedureDeclation',
             class_name=class_name,
             parameters=parsed_parameters[1:])
    else:
        raise Exception("Only thiscall is implemented.")

def parse_data_type(s):
    if s == "word32":
        return Unknown32()
    if s == "<unknown>*":
        return Pointer32()
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
            if isinstance(arg_type, ClassType):
                arg_type.get_declaration(is_metafile=True)
        class_decl = proc_decl.method_class.get_declaration(is_metafile=True)
        f.write(class_decl)

def process_output_code(file_name, addr):
    with open(file_name) as f:
        lines = f.readlines()
    for line in lines:
        if line.startswith("//"):
            continue
        if addr in line:
            return parse_procedure_declaration(line)

def define_field_name(field_type, field_name):
    if isinstance(field_type, Unknown32):
        field_name = field_name.replace("dw", "unknown_field_")
    return field_name

def define_parameter_name(field_type, parameter_name):
    if isinstance(field_type, Unknown32):
        parameter_name = parameter_name.replace("dwArg", "unknown_param_")
    if isinstance(field_type, Pointer32):
        parameter_name = parameter_name.replace("dwArg", "unknown_ptr_")
    return parameter_name

def process_header_file(file_name, classes):
    with open(file_name) as f:
        lines = f.readlines()
    cur_class = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("typedef struct Eq_"):
            class_name = line.split(" ")[2]
            if class_name in classes:
                cur_class = {}
        elif cur_class is not None:
            if line.startswith("}"):
                classes[class_name] = ClassType(class_name, cur_class)
                cur_class = None
                continue
            tokens = line.split("//")
            offset = fromHex(tokens[1])
            decl = tokens[0].strip().strip(";")
            var_type, var_name = parse_variable_declaration(decl)
            var_type = parse_data_type(var_type)
            var_name = define_field_name(var_type, var_name)
            cur_class[offset] = (var_type, var_name)

def process_output_dir(output_dir):
    for root, dirs, files in os.walk(output_dir):
        for file in files:
            if file.endswith("globals.c"):
                continue
            if file.endswith(".c"):
                code_file = file
            if file.endswith(".h"):
                header_file = file
    return (code_file, header_file)

def process_intermediate_output(output_dir, addr):
    code_file, header_file = process_output_dir(output_dir)
    proc = process_output_code(os.path.join(output_dir, code_file), addr)
    classes = {}
    if proc.class_name is not None:
        classes[proc.class_name] = None
    process_header_file(os.path.join(output_dir, header_file), classes)
    method_class = None
    if proc.class_name is not None:
        method_class = classes[proc.class_name]
        method_class = method_class.rename("unknown_class_{}".format(addr))
    parameters = []
    for parameter in proc.parameters:
        var_type, var_name = parameter
        var_type = parse_data_type(var_type)
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

def process_final_output(output_dir, proc_decl, addr):
    code_file, header_file = process_output_dir(output_dir)
    body = extract_procedure_body(
        os.path.join(output_dir, code_file), proc_decl
    )
    output_dir = os.path.join(output_dir, "..", "..", "output")
    cpp_file_name = os.path.join(output_dir, "{}.cpp".format(addr))
    with open(cpp_file_name, "wt") as f:
        f.write(body.emit_code())
    header_file_name = os.path.join(
        output_dir, "{}.h".format(proc_decl.proc_name)
    )
    with open(header_file_name, "wt") as f:
        f.write(body.emit_header())
    compile_bat = os.path.join(script_dir, "compile.bat")
    execute_command([compile_bat, cpp_file_name])

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

def execute_reko(project_file_name, decl_base_name):
    hash_file_name = project_file_name + ".obj"
    hasher = hashlib.sha256()
    update_hash(hasher, project_file_name)
    if decl_base_name is not None:
        decl_file_name = os.path.join(
            os.path.dirname(project_file_name), decl_base_name
        )
        update_hash(hasher, decl_file_name)
    new_hash = hasher.digest()
    if not is_hash_changed(hash_file_name, new_hash):
        print("Input files were not changed: skipping executing of Reko...")
        return
    execute_command([reko_cmdline, project_file_name])
    write_hash(hash_file_name, new_hash)

def process_procedure(project_template, addr):
    decompile_file_part_py = os.path.join(
        script_dir, "..", "projects", "decompile_file_part.py"
    )
    command = [
        sys.executable, decompile_file_part_py,
        "--file-name={}".format(project_template),
        "--start-address={}".format(addr),
        "--end-address={}".format(toHex(fromHex(addr) + 1))
    ]
    execute_command(command)
    fname_regexp = re.compile('^(?P<fname>.+)\.(?P<ext>.+)')
    match = re.search(fname_regexp, project_template)
    output_file_name = "{}_{}-{}.{}".format(
        match.group('fname'),
        addr,
        toHex(fromHex(addr) + 1),
        match.group('ext'))
    shutil.copyfile(output_file_name, output_file_name + "_")
    output_dir_name = addr
    set_output_dir(output_file_name, output_dir_name)
    execute_reko(output_file_name, None)
    output_dir = os.path.join(os.path.dirname(output_file_name), output_dir_name)
    proc_decl = process_intermediate_output(output_dir, addr)
    output_file_name += "_"
    output_dir_name += "_"
    set_output_dir(output_file_name, output_dir_name)
    decl_file_name = "decl_{}.inc".format(output_dir_name)
    set_procedure_declaration(output_file_name, proc_decl, decl_file_name, addr)
    execute_reko(output_file_name, decl_file_name)
    output_dir = os.path.join(os.path.dirname(output_file_name), output_dir_name)
    process_final_output(output_dir, proc_decl, addr)

def create_common_header():
    common_header_name = os.path.join(script_dir, "output", "common.h")
    with open(common_header_name, "wt") as f:
        f.write("#pragma once\n\n")
        f.write("#include <string.h>\n\n")
        f.write("typedef int unknown32;\n")

def run():
    procedures_dict_file = os.path.join(script_dir, "procedures_dict.json")
    with open(procedures_dict_file, "rt") as f:
        proc_dict = json.load(f)
    project_name = "Blade.dcproject"
    project_template = os.path.join(script_dir, project_name)
    output_file_name = os.path.join(script_dir, "intermediate", project_name)
    make_project_file(project_template, output_file_name, proc_dict)
    create_common_header()
    for addr, proc in proc_dict.items():
        process_procedure(output_file_name, addr)
        if addr > "00401051":
            break

if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
