from block_transformer import transform_block
from class_type import ClassType
from parse_instructions import parse_instructions
from pointer32 import Pointer32
from writer import Writer

class ProcedureBody:
    def __init__(self, proc_decl, instructions):
        self._proc_decl = proc_decl
        self._instructions = parse_instructions(instructions)

    def __repr__(self):
        return "ProcedureBody(proc_decl={}, instructions={})".format(
            self._proc_decl,
            self._instructions,
        )

    def transform_instructions(self, recompiled_decls):
        self._instructions = transform_block(
            self._instructions,
            declared_identifiers=self._proc_decl.get_parameters_ids(),
            id_suffixes={},
            proc_decl=self._proc_decl,
            recompiled_decls=recompiled_decls,
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

    def emit_header(self):
        lines = []
        lines.append("#pragma once")
        lines.append("")
        lines.append(self._proc_decl.get_types_declarations(is_metafile=False))
        return "\n".join(lines)
