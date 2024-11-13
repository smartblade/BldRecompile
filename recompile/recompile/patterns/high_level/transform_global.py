import parser
import expressions


def transform_global(address, declarations, **kwargs):
    global_var = declarations.symbols.variables.get(address)
    if global_var is not None and global_var.declaration is not None:
        var_type, var_name = parser.parse_cpp_variable_declaration(
            global_var.declaration.strip().strip(";"),
            declarations.declared_types,
        )
        return expressions.AddressOf(expressions.Identifier(var_type, var_name))
    return None
