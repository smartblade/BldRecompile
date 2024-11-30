import json
import os
import re

from hex_conversion import from_hex, to_hex
import parser
from patterns.apply_pattern import apply_pattern
from patterns.match_operand import match_operand
from patterns.parse_asm_lines import parse_asm_lines
from patterns.procedure_builder import ProcedureBuilder
from writer import Writer

command_regexp = re.compile(r'^(?P<cmd>\w+)(\s+(?P<operands>.+))?$')


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
            if exc is not None and to_hex(proc_addr) not in ["10041808"]:
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
    lines = parse_asm_lines(lines)
    cur_index = 0
    while cur_index < len(lines):
        pattern, match_dict, cur_index = _match_patterns(
            patterns, cur_index, lines)
        apply_pattern(builder, pattern, match_dict)


def _match_patterns(patterns, first_index, lines):
    instructions_patterns = patterns["instructions-patterns"]
    operand_pattern_sets = patterns["operand-patterns"]
    for pattern in instructions_patterns:
        last_index, match_dict = _match_instructions_pattern(
            pattern, operand_pattern_sets, first_index, lines)
        if last_index > first_index:
            return pattern, match_dict, last_index
    raise Exception(
        "Failed to find pattern for '{}'".format(lines[first_index]))


def _match_instructions_pattern(
    pattern, operand_pattern_sets, first_index, lines
):
    match_dict = dict()
    instructions = pattern["instructions"]
    cur_index = first_index
    for instr_pattern in instructions:
        if not _match_instruction(
            instr_pattern, operand_pattern_sets, lines[cur_index], match_dict
        ):
            return -1, None
        cur_index += 1
    return cur_index, match_dict


def _match_instruction(instr_pattern, operand_pattern_sets, line, match_dict):
    line = _add_size_to_call_operand(line)
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
        cur_match_dict = match_operand(
            operands[op_index], expected_operands[op_index],
            operand_pattern_sets
        )
        if cur_match_dict is None:
            return False
        for param, value in cur_match_dict.items():
            if param not in match_dict:
                match_dict[param] = value
            elif match_dict[param] != value:
                return False
    return True


def _add_size_to_call_operand(line):
    if not line.startswith("call"):
        return line
    return line.replace("call [", "call dword ptr [")
