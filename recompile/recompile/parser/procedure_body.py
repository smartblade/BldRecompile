import parser
from procedure_body import ProcedureBody


def parse_procedure_body(lines, declarations):
    proc_decl = declarations.proc_decl
    instructions = None
    for line in lines:
        if line.startswith("//"):
            continue
        if proc_decl.proc_name in line:
            proc_decl.extract_return_arg_from_line(line, declarations)
        if line.startswith("{"):
            instructions = []
            continue
        if line.startswith("}"):
            instructions = parser.parse_instructions(
                instructions,
                declared_identifiers={
                    **declarations.proc_decl.get_parameters_ids(),
                    **declarations.gbl_vars,
                },
                defined_types=declarations.get_types_declarations(),
            )
            return ProcedureBody(declarations.proc_decl, instructions)
        if instructions is not None:
            instructions.append(line)
