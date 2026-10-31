import data_types
import parser
import expressions


def transform_global(address, declarations, **kwargs):
    global_var = declarations.symbols.variables.get(address)
    if global_var is not None and global_var.declaration is not None:
        var_type, var_name = parser.parse_cpp_variable_declaration(
            global_var.declaration.strip().strip(";"),
            declarations.declared_types,
        )
        _expect_not_float_constant(address, var_type, var_name, declarations)
        return expressions.AddressOf(expressions.Identifier(var_type, var_name))
    return None


def _expect_not_float_constant(address, var_type, var_name, declarations):
    # Compiler places float literals to read only data
    if not isinstance(var_type, (data_types.Float, data_types.Double)):
        return
    data = declarations.read_only_data.get_bytes(address, var_type.size)
    if data is not None:
        raise Exception(
            "Global variable {} at 0x{:08X} is read only float "
            "constant.".format(var_name, address))
