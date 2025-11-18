import os

from hex_conversion import to_hex
import parser

from .writer import get_metadata_and_and_procedure_stub, get_procedure_code


def update_src(src_path, module_name, procedures, exported_procedures):
    proc_by_addr = {}
    for procedure in procedures:
        proc_by_addr[procedure.address] = procedure
    src_files = _get_source_files(src_path)
    procedures_data = _get_procedures_data(
        src_files, module_name, exported_procedures, proc_by_addr)
    _define_files_from_adjacent_procedures(procedures_data)
    updating_procedures = _get_updating_procedures(procedures_data)
    for src_file in src_files:
        _process_file(
            src_file, module_name, updating_procedures, exported_procedures)


def _get_source_files(src_path):
    src_files = []
    for root, dirs, files in os.walk(src_path):
        for file in files:
            if file.lower().endswith(".h") or file.lower().endswith(".cpp"):
                src_file_name = os.path.join(root, file)
                with open(src_file_name) as f:
                    lines = f.readlines()
                src_files.append(_FileData(src_file_name, lines))
    return src_files


def _get_procedures_data(
    src_files, module_name, exported_procedures, proc_by_addr
):
    procedures_data = {}
    for src_file in src_files:
        definitions = parser.SrcSymbols.collect_procedures(src_file.lines)
        for (cur_module, addr), definition in definitions.items():
            if cur_module != module_name:
                continue
            if addr not in proc_by_addr:
                continue
            is_exported = addr in exported_procedures
            procedures_data[addr] = _ProcedureData(
                src_file, is_exported, definition, proc_by_addr[addr])
    for addr in proc_by_addr.keys():
        if addr in procedures_data:
            continue
        is_exported = addr in exported_procedures
        procedures_data[addr] = _ProcedureData(
            None, is_exported, None, proc_by_addr[addr])
    sorted_addresses = sorted(procedures_data.keys())
    return dict(
        (addr, procedures_data[addr]) for addr in sorted_addresses
    )


def _define_files_from_adjacent_procedures(procedures_data):
    unset_file_addresses = []
    cur_file = None
    for addr, procedure_data in procedures_data.items():
        if addr % 16 == 0:
            unset_file_addresses = []
            cur_file = None
        if procedure_data.file is None:
            if cur_file is not None:
                procedure_data.file = cur_file
            else:
                unset_file_addresses.append(addr)
        else:
            cur_file = procedure_data.file
            for cur_file_addr in unset_file_addresses:
                if procedures_data[cur_file_addr].file is None:
                    procedures_data[cur_file_addr].file = cur_file
            unset_file_addresses = []


def _get_updating_procedures(procedures_data):
    updating_procedures = {}
    for addr, procedure_data in procedures_data.items():
        if addr in _excluded_addresses:
            continue
        src_definition = procedure_data.src_definition
        if src_definition is not None:
            if not src_definition.is_implemented:
                continue
            if src_definition.declaration is None:
                continue
        else:
            if not procedure_data.is_exported:
                continue
        updating_procedures[addr] = procedure_data
    return updating_procedures


def _define_nearest_src_definitions(procedures_data):
    prev_src_definition = None
    prev_addr = None
    first_undefined_procs = []
    for proc_data in procedures_data:
        if proc_data.src_definition is None:
            if prev_src_definition is not None:
                proc_data.prev_src_definition = prev_src_definition
            else:
                first_undefined_procs.append(proc_data)
            continue
        for undefined_proc in first_undefined_procs:
            undefined_proc.next_src_definition = proc_data.src_definition
        first_undefined_procs = []
        if prev_src_definition is not None:
            if (
                proc_data.src_definition.definition_start_line <=
                prev_src_definition.definition_start_line
            ):
                raise Exception(
                    "Procedure 0x{} should be before 0x{}".format(
                        to_hex(prev_addr), to_hex(proc_data.procedure.address))
                )
        prev_src_definition = proc_data.src_definition
        prev_addr = proc_data.procedure.address


def _process_file(
    src_file, module_name, updating_procedures, exported_procedures
):
    lines = src_file.lines
    procedures = sorted(
        src_file.procedures,
        key=lambda p: p.procedure.address,
    )
    _define_nearest_src_definitions(procedures)
    procedures = [
        proc_data for proc_data in procedures
        if proc_data.procedure.address in updating_procedures
    ]
    if len(procedures) == 0:
        return
    cur_proc_data = procedures.pop()
    new_lines = []
    for line_index, line in reversed(list(enumerate(lines))):
        while (
            cur_proc_data is not None and cur_proc_data.src_definition is None
        ):
            prev_src_def = cur_proc_data.prev_src_definition
            next_src_definition = cur_proc_data.next_src_definition
            if prev_src_def is not None:
                if line_index > prev_src_def.definition_end_line + 1:
                    break
            else:
                assert next_src_definition is not None
                if line_index >= next_src_definition.metadata_start_line - 1:
                    break
            procedure_code = get_metadata_and_and_procedure_stub(
                cur_proc_data.procedure, module_name, exported_procedures)
            new_lines.append(procedure_code)
            if len(procedures) > 0:
                cur_proc_data = procedures.pop()
            else:
                cur_proc_data = None
        if (
            cur_proc_data is None or
            cur_proc_data.src_definition is None or
            line_index > cur_proc_data.src_definition.definition_end_line
        ):
            new_lines.append(line)
        elif line_index == cur_proc_data.src_definition.definition_start_line:
            procedure_code = get_procedure_code(
                cur_proc_data.procedure, line_index, lines)
            new_lines.append(procedure_code)
            if len(procedures) > 0:
                cur_proc_data = procedures.pop()
            else:
                cur_proc_data = None
    new_lines = list(reversed(new_lines))
    _strip_last_empty_lines(new_lines)
    with open(src_file.file_name, "wt") as f:
        for line in new_lines:
            f.write(line)


def _strip_last_empty_lines(lines):
    while len(lines[-1].strip()) == 0:
        lines.pop()


class _ProcedureData:
    def __init__(self, file, is_exported, src_definition, procedure):
        self._file = None
        self.file = file
        self.is_exported = is_exported
        self.src_definition = src_definition
        self.procedure = procedure
        self.prev_src_definition = None
        self.next_src_definition = None

    @property
    def file(self):
        return self._file

    @file.setter
    def file(self, file):
        assert self._file is None
        if file is None:
            return
        self._file = file
        file.add_procedure(self)


class _FileData:
    def __init__(self, file_name, lines):
        self.file_name = file_name
        self.lines = lines
        self._procedures = []

    @property
    def procedures(self):
        return self._procedures

    def add_procedure(self, proc):
        self._procedures.append(proc)


_excluded_addresses = {
    0x100022D0, 0x10002300, 0x10002320, 0x100024C0, 0x10002550, 0x10002580,
    0x100025C0, 0x10002980, 0x10002EA0, 0x10002F40, 0x100030E0, 0x10003300,
    0x10003337, 0x100033A4, 0x10003410, 0x100039BA, 0x100039E5, 0x10003A07,
    0x100066E0, 0x10006720, 0x10006860, 0x10006890, 0x10006B60, 0x10029BE0,
    0x1002A590,
}
