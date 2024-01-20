from block_transformer import transform_block
import parser
from writer import Writer

class ProcedureBody:
    def __init__(self, declarations, instructions):
        self._proc_decl = declarations.proc_decl
        self._instructions = parser.parse_instructions(
            instructions,
            declared_identifiers={
                **self._proc_decl.get_parameters_ids(),
                **declarations.gbl_vars,
            }
        )

    def __repr__(self):
        return "ProcedureBody(proc_decl={}, instructions={})".format(
            self._proc_decl,
            self._instructions,
        )

    def transform_instructions(self, declarations):
        self._instructions = transform_block(
            self._instructions,
            declared_identifiers=self._proc_decl.get_parameters_ids(),
            id_suffixes={},
            proc_decl=self._proc_decl,
            declarations=declarations,
        )

    def emit_code(self):
        writer = Writer()
        writer.write_line('#include "common.h"')
        writer.write_line('#include "{}.h"'.format(self._proc_decl.proc_name))
        writer.write_line("")
        writer.write_line(
            self._proc_decl.get_declaration(
                is_metafile=False, is_definition=True
            )
        )
        writer.write_line("{")
        with writer.indent():
            for instr in self._instructions:
                instr.emit_code(writer)
        writer.write_line("}")
        return writer.get_string()
