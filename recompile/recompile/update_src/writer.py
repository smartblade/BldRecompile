import data_types
import expressions
import instructions
from patterns.procedure import Procedure
from writer import Writer

from .make_metadata_header import make_metadata_header


def get_metadata_and_and_procedure_stub(
    procedure, module_name, exported_procedures
):
    metadata = make_metadata_header(
        procedure, module_name, exported_procedures)
    procedure_code = _get_procedure_stub_code(procedure).lstrip()
    return "\n{}#ifndef BLD_NATIVE\n{}#endif\n".format(metadata, procedure_code)


def _make_return_stub(proc_decl):
    if proc_decl.return_type is None or proc_decl.is_constructor:
        return None
    if isinstance(proc_decl.return_type, data_types.Pointer32):
        return instructions.ReturnInstruction(expressions.Null)
    const_value = None
    if proc_decl.return_type.is_any_int:
        const_value = 0
    elif isinstance(proc_decl.return_type, data_types.Float):
        const_value = 0.0
    if const_value is not None:
        return instructions.ReturnInstruction(
            expressions.Constant(proc_decl.return_type, const_value))
    if isinstance(proc_decl.return_type, data_types.Reference):
        for param in proc_decl.get_parameters_ids().values():
            if data_types.are_same(param.data_type, proc_decl.return_type):
                return instructions.ReturnInstruction(param)
            if (
                isinstance(param.data_type, data_types.Pointer32) and
                data_types.are_same(
                    param.data_type.pointee, proc_decl.return_type.referent)
            ):
                return instructions.ReturnInstruction(
                    expressions.Dereference(param))
    raise Exception("Unsupported return type: {}".format(proc_decl.return_type))


def _make_writer():
    return Writer(max_line_len=80)


def _get_procedure_stub_code(procedure):
    writer = _make_writer()
    instrs = []
    return_stub = _make_return_stub(procedure.proc_decl)
    if return_stub is not None:
        instrs.append(return_stub)
    procedure_stub = Procedure(
        procedure.proc_info, procedure.address, procedure.proc_decl, instrs)
    _write_procedure(writer, procedure_stub, 0)
    return writer.get_string()


def get_procedure_code(procedure, start_line, lines):
    writer = _make_writer()
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
