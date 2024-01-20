import re

import data_types
from hex_conversion import to_hex, from_hex

global_name_regexp = re.compile(r'^g_[a-z]+(?P<var_addr>[\dABCDEF]+)$')


def define_field_name(field_type, field_name):
    if isinstance(field_type, data_types.Unknown32):
        field_name = field_name.replace("dw", "unknown_field_")
    elif isinstance(field_type, data_types.Double):
        if field_name[0] == "t" or field_name[0] == "r":
            field_name = "unknown_double_{}".format(field_name[1:])
    elif isinstance(field_type, data_types.Float):
        field_name = field_name.replace("r", "unknown_float_")
    elif isinstance(field_type, data_types.UnknownByte):
        field_name = field_name.replace("b", "unknown_byte_")
    elif field_name[0] == "a":
        field_name = field_name.replace("a", "unknown_array_")
    elif isinstance(field_type, data_types.Pointer32):
        field_name = field_name.replace("ptr", "unknown_ptr_")
    return field_name


def define_parameter_name(field_type, parameter_name):
    if isinstance(field_type, data_types.Unknown32):
        parameter_name = parameter_name.replace("dwArg", "unknown_param_")
    elif isinstance(field_type, data_types.Pointer32):
        if parameter_name.startswith("dw"):
            parameter_name = parameter_name.replace("dwArg", "unknown_ptr_")
        else:
            parameter_name = parameter_name.replace("ptrArg", "unknown_ptr_")
    elif isinstance(field_type, data_types.Double):
        parameter_name = parameter_name.replace("rArg", "unknown_double_")
    elif isinstance(field_type, data_types.UInt32):
        parameter_name = parameter_name.replace("dwArg", "unknown_uint_")
    return parameter_name


def define_global_name(data_type, gbl_name):
    match = re.search(global_name_regexp, gbl_name)
    if not match:
        return gbl_name
    addr = from_hex(match.group("var_addr"))
    prefix = None
    if data_type is None or isinstance(data_type, data_types.Unknown32):
        prefix = "unknown_gbl_"
    elif isinstance(data_type, data_types.Pointer32):
        prefix = "unknown_ptr_gbl_"
    elif isinstance(data_type, data_types.Double):
        prefix = "unknown_double_gbl_"
    elif isinstance(data_type, data_types.UInt32):
        prefix = "unknown_uint_gbl_"
    if prefix is not None:
        gbl_name = "{}{}".format(prefix, to_hex(addr))
    return gbl_name
