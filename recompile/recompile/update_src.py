import os

import parser
from writer import Writer


def update_src(src_path, module_name, procedures):
    proc_by_addr = {}
    for procedure in procedures:
        proc_by_addr[procedure.address] = procedure
    for root, dirs, files in os.walk(src_path):
        for file in files:
            if file.lower().endswith(".h") or file.lower().endswith(".cpp"):
                src_file_name = os.path.join(root, file)
                process_file(src_file_name, module_name, proc_by_addr)


def process_file(src_file_name, module_name, proc_by_addr):
    with open(src_file_name) as f:
        lines = f.readlines()
    proc_dict = parser.SrcSymbols.collect_procedures(lines)
    definitions = [
        (addr, definition)
        for (cur_module, addr), definition in proc_dict.items()
        if (
            cur_module == module_name and
            definition.is_implemented and
            definition.declaration is not None and
            addr in proc_by_addr and
            addr not in _excluded_addresses
        )
    ]
    definitions = sorted(definitions, key=lambda d: d[1].definition_start_line)
    if len(definitions) == 0:
        return
    proc_addr, cur_definition = definitions.pop()
    new_lines = []
    for line_index, line in reversed(list(enumerate(lines))):
        if (
            cur_definition is None or
            line_index > cur_definition.definition_end_line
        ):
            new_lines.append(line)
        elif line_index == cur_definition.definition_start_line:
            procedure_code = _get_procedure_code(
                proc_by_addr[proc_addr], line_index, lines)
            new_lines.append(procedure_code)
            if len(definitions) > 0:
                proc_addr, cur_definition = definitions.pop()
            else:
                proc_addr = None
                cur_definition = None
    with open(src_file_name, "wt") as f:
        for line in reversed(new_lines):
            f.write(line)


def _get_procedure_code(procedure, start_line, lines):
    writer = Writer(max_line_len=80)
    num_spaces = _get_num_spaces(lines[start_line + 1])
    num_indent = num_spaces // writer.indent_length
    _write_procedure(writer, procedure, num_indent)
    return writer.get_string()


def _get_num_spaces(line):
    num_spaces = 0
    while line[num_spaces] == ' ':
        num_spaces += 1
    return num_spaces


def _write_procedure(writer, procedure, num_indent, is_definition=True):
    if num_indent == 0:
        procedure.emit_code(
            writer, is_definition=is_definition, show_address=False)
        return
    with writer.indent():
        _write_procedure(writer, procedure, num_indent - 1, is_definition=False)


_excluded_addresses = {
    0x100022D0, 0x10002300, 0x10002320, 0x100024C0, 0x10002550, 0x10002580,
    0x100025C0, 0x10002980, 0x10002EA0, 0x10002F40, 0x100030E0, 0x10003300,
    0x10003337, 0x100033A4, 0x10003410, 0x100039BA, 0x100039E5, 0x10003A07,
    0x100066E0, 0x10006720, 0x10006860, 0x10006890, 0x10006B60, 0x10029BE0,
    0x1002A590,
}
