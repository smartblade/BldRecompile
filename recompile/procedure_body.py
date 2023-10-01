from code_instruction import CodeInstruction

class ProcedureBody:
    def __init__(self, proc_decl, instructions):
        self._proc_decl = proc_decl
        self._instructions = []
        for instr_str in instructions:
            instr_str = instr_str.strip()
            self._instructions.append(CodeInstruction(instr_str))

    def __repr__(self):
        return "ProcedureBody(proc_decl={}, instructions={})".format(
            self._proc_decl,
            self._instructions,
        )

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
        class_cpp_decl = self._proc_decl.method_class.get_declaration(
            is_metafile=False
        )
        lines.append(class_cpp_decl)
        return "\n".join(lines) + "\n"
