from hex_conversion import to_hex


def make_metadata_header(procedure, module_name, exported_procedures):
    mangling = exported_procedures.get(procedure.address)
    hex_addr = to_hex(procedure.address)
    lines = [
        "/*",
        "* Module:                 {}".format(module_name),
        "* Entry point:            0x{}".format(hex_addr),
    ]
    if mangling is not None and mangling.startswith("?"):
        lines.append("* VC++ mangling:          {}".format(mangling))
    lines.append("*/\n")
    return "\n".join(lines)
