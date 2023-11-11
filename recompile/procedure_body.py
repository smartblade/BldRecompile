from collections import namedtuple

from block_transformer import transform_block
from class_type import ClassType
from code_instruction import CodeInstruction
import code_parser as parser
from if_instruction import IfInstruction
from pointer32 import Pointer32
from writer import Writer

class ProcedureBody:
    def __init__(self, proc_decl, instructions):
        self._proc_decl = proc_decl
        self._instructions = self._parse_instructions(instructions)

    def __repr__(self):
        return "ProcedureBody(proc_decl={}, instructions={})".format(
            self._proc_decl,
            self._instructions,
        )

    def _parse_instructions(self, instructions):
        blocks_state = []
        state = self._new_state(
            block_type=None,
            current_block=[],
            multiple_lines=True,
        )
        for instr_str in instructions:
            instr_str = instr_str.strip()
            if instr_str.startswith("if (") and instr_str.endswith(")"):
                if_clause = parser.parse_cpp_expression(instr_str[4:-1])
                state = self._start_block(blocks_state, state, "if")
            elif instr_str == "else":
                state = self._start_block(blocks_state, state, "else")
            elif instr_str == "{":
                state = self._multiple_lines(state)
            elif instr_str == "}":
                state = self._end_block(blocks_state, state, if_clause)
            elif instr_str.endswith(";"):
                state.current_block.append(CodeInstruction(instr_str[:-1]))
                if not state.multiple_lines:
                    state = self._end_block(blocks_state, state, if_clause)
            else:
                raise Exception(
                    "Not supported instruction type: '{}'.".format(instr_str)
                )
        return state.current_block

    def _new_state(self, **kwargs):
        return namedtuple('State', kwargs.keys())(**kwargs)

    def _multiple_lines(self, state):
        return self._new_state(
            block_type=state.block_type,
            current_block=state.current_block,
            multiple_lines=True,
        )

    def _start_block(self, blocks_state, state, new_block_type):
        blocks_state.append(state)
        return self._new_state(
            block_type=new_block_type,
            current_block=[],
            multiple_lines=False,
        )

    def _end_block(self, blocks_state, state, if_clause):
        prev_state = blocks_state.pop()
        if state.block_type == "if":
            prev_state.current_block.append(
                IfInstruction(if_clause, state.current_block)
            )
        elif state.block_type == "else":
            prev_state.current_block[-1].add_else_block(state.current_block)
        return prev_state

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
