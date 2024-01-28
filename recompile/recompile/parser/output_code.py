import parser


def parse_output_code(lines, addr, declared_identifiers):
    body_lines = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("}"):
            return proc, parser.parse_instructions(
                body_lines, declared_identifiers
            )
        if addr in line:
            proc = parser.split_procedure_parameters(line)
        elif line.startswith("{"):
            body_lines = []
        elif body_lines is not None:
            body_lines.append(line)
