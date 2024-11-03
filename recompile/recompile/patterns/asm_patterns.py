import json
import os
import re

from hex_conversion import from_hex, to_hex
import parser
from patterns.apply_pattern import apply_pattern
from patterns.procedure_builder import ProcedureBuilder
from writer import Writer

command_regexp = re.compile(r'^(?P<cmd>\w+)(\s+(?P<operands>.+))?$')
operand_regexp = re.compile(
    r'^(?P<size>dword\s+ptr\s+)?(offset\s+)?(?P<operand>.+)$')


def process_asm_patterns(lines, declarations):
    if declarations.symbols.module != "BBLibc.dll":
        return
    patterns_path = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "patterns.json")
    with open(patterns_path, "rt") as f:
        patterns = json.load(f)
    proc_addr = None
    proc_lines = []
    writer = Writer()
    smallest_failed_proc_len = None
    smallest_failed_proc_exc = None
    smallest_failed_proc_addr = None
    for line in lines:
        if line.startswith("l") and line.find("PROC") >= 0:
            proc_addr = from_hex(line[1:9])
            proc_lines.clear()
        elif proc_addr is not None and line.find("ENDP") >= 0:
            exc = _build_proc(
                writer, declarations, patterns, proc_addr, proc_lines)
            if exc is not None:
                if (
                    smallest_failed_proc_len is None or
                    len(proc_lines) < smallest_failed_proc_len
                ):
                    smallest_failed_proc_len = len(proc_lines)
                    smallest_failed_proc_addr = proc_addr
                    smallest_failed_proc_exc = exc
            proc_addr = None
        elif proc_addr is not None:
            proc_lines.append(line.strip())
    with open("{}.cpp".format(declarations.symbols.module), "wt") as f:
        f.write(writer.get_string())
    if smallest_failed_proc_exc is not None:
        raise Exception(
            "Failed to build {}".format(to_hex(smallest_failed_proc_addr))
        ) from smallest_failed_proc_exc


def _build_proc(writer, declarations, patterns, proc_addr, proc_lines):
    if (
        proc_addr in declarations.symbols.procedures and
        declarations.symbols.procedures[proc_addr].declaration is not None
    ):
        cpp_declaration = declarations.symbols.procedures[proc_addr]
        proc_decl = parser.parse_cpp_function(
            cpp_declaration.class_name,
            cpp_declaration.declaration,
            declarations.declared_types,
        )
        decl_string = proc_decl.get_declaration(
            is_metafile=False, is_definition=True)
    else:
        proc_decl = None
        decl_string = "p{}".format(to_hex(proc_addr))
    writer.write_line("")
    writer.write_line("// address: 0x{}".format(to_hex(proc_addr)))
    writer.write_line(decl_string)
    builder = ProcedureBuilder(proc_decl)
    try:
        _parse_asm_proc(builder, patterns, proc_lines)
    except Exception as exc:
        builder.emit_code(writer)
        writer.write_line(str(exc))
        return exc
    else:
        builder.make_high_level_code(declarations)
        builder.emit_code(writer)


def _parse_asm_proc(builder, patterns, lines):
    cur_index = 0
    while cur_index < len(lines):
        pattern, match_dict, cur_index = _match_patterns(
            patterns, cur_index, lines)
        apply_pattern(builder, pattern, match_dict)


def _match_patterns(patterns, first_index, lines):
    for pattern in patterns:
        last_index, match_dict = _match_pattern(pattern, first_index, lines)
        if last_index > first_index:
            return pattern, match_dict, last_index
    raise Exception(
        "Failed to find pattern for '{}'".format(lines[first_index]))


def _match_pattern(pattern, first_index, lines):
    match_dict = dict()
    instructions = pattern["instructions"]
    cur_index = first_index
    for instr_pattern in instructions:
        if not _match_instruction(instr_pattern, lines[cur_index], match_dict):
            return -1, None
        cur_index += 1
    return cur_index, match_dict


def _match_instruction(instr_pattern, line, match_dict):
    expected_cmd = next(iter(instr_pattern.keys()))
    expected_operands = next(iter(instr_pattern.values()))
    match = re.search(command_regexp, line)
    if not match:
        raise Exception("Can't parse line: {}".format(line))
    if expected_cmd != match.group("cmd"):
        return False
    operands_str = match.group("operands")
    if operands_str is not None:
        operands = operands_str.split(",")
    else:
        operands = []
    if len(expected_operands) != len(operands):
        return False
    for op_index in range(len(operands)):
        match = re.search(operand_regexp, operands[op_index].strip())
        operand = match.group("operand")
        operand_size = _get_operand_size(match.group("size"))
        expected_operand_regexp = re.escape(expected_operands[op_index])
        expected_operand_regexp = re.sub(
            r"%(?P<variable>[\w\\-]*)%",
            _define_variable_regexp,
            expected_operand_regexp)
        expected_operand_regexp = r"^{}$".format(expected_operand_regexp)
        match = re.search(expected_operand_regexp, operand)
        if not match:
            return False
        operand_match_dict = match.groupdict()
        if operand_size is not None:
            operand_match_dict["size"] = str(operand_size)
        for param, value in operand_match_dict.items():
            param = param.replace("_", "-")
            if param not in match_dict:
                match_dict[param] = value
            elif match_dict[param] != value:
                return False
    return True


def _get_operand_size(s):
    if s is None:
        return None
    if s.startswith("dword"):
        return 4
    raise Exception("Unknown operand size: {}.".format(s))


def _define_variable_regexp(matchobj):
    var_name = matchobj.group("variable")
    var_name = var_name.replace("\\-", "-")
    for key, regexp_value in _regexp_map.items():
        if var_name.startswith(key):
            var_name = var_name.replace("-", "_")
            return r"(?P<{}>{})".format(var_name, regexp_value)
    raise Exception("Unexpected variable: %{}%".format(var_name))


_regexp_map = {
    "eax-ecx-edx": r"eax|ecx|edx",
    "label": r"(g|l)[\dABCDEF]+",
    "hex": r"[\dABCDEF]+h",
    "offset": r"[\+\-][\dABCDEF]+h",
}
