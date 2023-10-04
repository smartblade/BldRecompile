from block_transformer import transform_block
from class_type import ClassType
from code_instruction import CodeInstruction
from if_instruction import IfInstruction
from pointer32 import Pointer32

class ProcedureBody:
    def __init__(self, proc_decl, instructions):
        self._proc_decl = proc_decl
        processing_blocks = []
        current_block = []
        block_type = None
        for instr_str in instructions:
            instr_str = instr_str.strip()
            if instr_str.startswith("if (") and instr_str.endswith(")"):
                if_clause = instr_str[4:-1]
                processing_blocks.append((block_type, current_block))
                block_type = "if"
                current_block = []
            elif instr_str == "else":
                processing_blocks.append((block_type, current_block))
                block_type = "else"
                current_block = []
            elif instr_str == "{":
                continue
            elif instr_str == "}":
                finished_block_type = block_type
                finished_block = current_block
                (block_type, current_block) = processing_blocks.pop()
                if finished_block_type == "if":
                    current_block.append(
                        IfInstruction(if_clause, finished_block)
                    )
                elif finished_block_type == "else":
                    current_block[-1].add_else_block(finished_block)
            elif instr_str.endswith(";"):
                current_block.append(CodeInstruction(instr_str[:-1]))
            else:
                raise Exception(
                    "Not supported instruction type: '{}'.".format(instr_str)
                )
        self._instructions = current_block

    def __repr__(self):
        return "ProcedureBody(proc_decl={}, instructions={})".format(
            self._proc_decl,
            self._instructions,
        )

    def transform_instructions(self):
        self._instructions = transform_block(self._instructions)

    def emit_code(self):
        lines = []
        lines.append('#include "common.h"')
        lines.append('#include "{}.h"'.format(self._proc_decl.proc_name))
        lines.append("")
        if self._proc_decl.method_class is None:
            raise Exception("Only thiscall is implemented.")
        parameters = []
        for parameter_type, parameter_name in self._proc_decl.parameters:
            type_name = parameter_type.get_type_name(is_metafile=False)
            sep = "" if type_name.endswith("*") else " "
            parameters.append("{}{}{}".format(type_name, sep, parameter_name))
        lines.append(
            "{}{}::{}({})".format(
                self._proc_decl.return_arg,
                self._proc_decl.method_class.class_name,
                self._proc_decl.proc_name,
                ", ".join(parameters),
            )
        )
        lines.append("{")
        for instr in self._instructions:
            lines.append(instr.emit_code())
        lines.append("}")
        return "\n".join(lines) + "\n"

    def emit_header(self):
        lines = []
        lines.append("#pragma once")
        lines.append("")
        for parameter_type, parameter_name in self._proc_decl.parameters:
            if (
                isinstance(parameter_type, Pointer32) and
                isinstance(parameter_type.pointee, ClassType)
            ):
                lines.append(
                    parameter_type.pointee.get_declaration(is_metafile=False)
                )
        class_cpp_decl = self._proc_decl.method_class.get_declaration(
            is_metafile=False
        )
        lines.append(class_cpp_decl)
        return "\n".join(lines) + "\n"
