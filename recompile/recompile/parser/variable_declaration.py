def parse_variable_declaration(s):
    last_space = s.rfind(' ')
    if last_space < 0:
        return s, ""
    var_type = s[:last_space]
    var_name = s[last_space + 1:]
    return var_type, var_name
