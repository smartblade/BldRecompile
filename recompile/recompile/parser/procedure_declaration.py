from make_tuple import make_tuple
import parser


def parse_procedure_declaration(s):
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
        parsed_parameters.append(parser.parse_variable_declaration(p.strip()))
    if parsed_parameters:
        var_type, var_name = parsed_parameters[0]
    else:
        var_name = None
    # Check if it is 'thiscall' convention
    if var_name == "ecx":
        class_type=var_type
        parameters=parsed_parameters[1:]
    else:
        class_type=None
        parameters=parsed_parameters
    return make_tuple(
        'ProcedureDeclation',
         class_type=class_type,
         parameters=parameters
    )
