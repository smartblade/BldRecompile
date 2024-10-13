def parse_variable_declaration(s):
    last_space = s.rfind(' ')
    if last_space < 0:
        return s, ""
    var_type = s[:last_space]
    var_name = s[last_space + 1:]
    if var_name.endswith("[]"):
        var_type = "{} *".format(var_type)
        if var_type.startswith("Eq_"):
            var_type = "struct {}".format(var_type)
        var_name = var_name[:-2]
    return var_type, var_name
