import parser


def split_procedure_parameters(s):
    start_brackets_pos = s.find("(")
    if start_brackets_pos < 0:
        raise Exception("Failed to parse declaration: '(' was not found.")
    end_brackets_pos = s.find(")")
    if end_brackets_pos < 0:
        raise Exception("Failed to parse declaration: ')' was not found.")
    parameters = s[start_brackets_pos + 1:end_brackets_pos].split(',')
    if len(parameters) == 1 and not parameters[0]:
        parameters = []
    parsed_parameters = []
    for p in parameters:
        p = p.strip()
        if p == "...":
            parsed_parameters.append((None, p))
            continue
        parsed_parameters.append(parser.parse_variable_declaration(p))
    return parsed_parameters
