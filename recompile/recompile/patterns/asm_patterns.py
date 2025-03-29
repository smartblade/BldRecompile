import json
import os

from hex_conversion import from_hex, to_hex
from make_tuple import add_attributes
import parser
from patterns.apply_pattern import apply_pattern
from patterns.collect_string_constants import collect_string_constants
from patterns.match_operand import match_operand
from patterns.asm_parser import parse_asm_lines
from patterns.prefix_status import PrefixStatus
from patterns.structure import Patterns
from patterns.builder import ProcedureBuilder
from writer import Writer


def process_asm_patterns(lines, declarations):
    if declarations.symbols.module != "BBLibc.dll":
        return
    patterns_path = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "patterns.json")
    with open(patterns_path, "rt") as f:
        patterns = Patterns(json.load(f))
    proc_addr = None
    proc_lines = []
    writer = Writer()
    smallest_failed_proc_len = None
    smallest_failed_proc_exc = None
    smallest_failed_proc_addr = None
    standard_inlines = {}
    string_constants = collect_string_constants(lines)
    declarations = add_attributes(
        declarations, string_constants=string_constants)
    for line in lines:
        if line.startswith("l") and line.find("PROC") >= 0:
            proc_addr = from_hex(line[1:9])
            proc_lines.clear()
        elif proc_addr is not None and line.find("ENDP") >= 0:
            exc = _build_proc(
                writer, declarations, standard_inlines, patterns, proc_addr,
                proc_lines)
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


def _build_proc(
    writer, declarations, standard_inlines, patterns, proc_addr, proc_lines
):
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
    builder = ProcedureBuilder(proc_decl, proc_addr, standard_inlines)
    try:
        _parse_asm_proc(
            builder, declarations.string_constants, patterns, proc_lines)
    except Exception as exc:
        builder.emit_code(writer)
        writer.write_line('Error: "{}"'.format(str(exc)))
        return exc
    else:
        builder.make_high_level_code(declarations)
        builder.emit_code(writer)


def _parse_asm_proc(builder, string_constants, patterns, lines):
    instrs = parse_asm_lines(lines, patterns.commands_code_dict)
    prefix_status = PrefixStatus(patterns.make_prefix_builder(), instrs)
    cur_index = 0
    while cur_index < len(instrs):
        pattern, match_dict, cur_index = _match_patterns(
            prefix_status, patterns, cur_index, instrs)
        apply_pattern(builder, string_constants, pattern, match_dict)


def _match_patterns(prefix_status, patterns, first_index, instrs):
    instructions_patterns = patterns.instructions_patterns_by_prefix(
        prefix_status.prefix)
    for pattern in instructions_patterns:
        last_index, match_dict = _match_instructions_pattern(
            pattern, patterns.operand_sets, first_index, instrs)
        if last_index > first_index:
            prefix_status.update(last_index - first_index)
            return pattern, match_dict, last_index
    raise Exception(
        "Failed to find pattern for '{}'".format(instrs[first_index]))


def _match_instructions_pattern(
    pattern, operand_pattern_sets, first_index, instrs
):
    match_dict = dict()
    cur_index = first_index
    for instr_pattern in pattern.instructions:
        if not _match_instruction(
            instr_pattern, operand_pattern_sets, instrs[cur_index], match_dict
        ):
            return -1, None
        cur_index += 1
    return cur_index, match_dict


def _match_instruction(instr_pattern, operand_pattern_sets, instr, match_dict):
    if instr_pattern.command_code != instr.command_code:
        return False
    if len(instr_pattern.operands) != len(instr.operands):
        return False
    for op_index in range(len(instr.operands)):
        cur_match_dict = match_operand(
            instr.operands[op_index], instr_pattern.operands[op_index],
            operand_pattern_sets
        )
        if cur_match_dict is None:
            return False
        for param, value in cur_match_dict.items():
            if param not in match_dict:
                match_dict[param] = value
            elif match_dict[param] != value:
                if param == "size":
                    match_dict[param] = "<different-sizes>"
                else:
                    return False
    return True
