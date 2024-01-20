import parser


def parse_output_code(lines, addr):
    body_lines = None
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("}"):
            return proc, parser.parse_instructions(body_lines, {})
        if addr in line:
            proc = parser.parse_procedure_declaration(line)
        elif line.startswith("{"):
            body_lines = []
        elif body_lines is not None:
            body_lines.append(line)
