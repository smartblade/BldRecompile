from procedure_body import ProcedureBody


def parse_procedure_body(lines, declarations):
    proc_decl = declarations.proc_decl
    instructions = None
    for line in lines:
        if line.startswith("//"):
            continue
        if proc_decl.proc_name in line:
            proc_decl.extract_return_arg_from_line(line)
        if line.startswith("{"):
            instructions = []
            continue
        if line.startswith("}"):
            return ProcedureBody(declarations, instructions)
        if instructions is not None:
            instructions.append(line)
