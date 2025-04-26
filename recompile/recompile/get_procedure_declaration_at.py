import parser


def get_procedure_declaration_at(declarations, addr):
    cpp_declaration = declarations.symbols.procedures.get(addr)
    if (
        cpp_declaration is not None and
        cpp_declaration.declaration is not None
    ):
        return parser.parse_cpp_function(
            cpp_declaration.class_name,
            cpp_declaration.declaration,
            declarations.declared_types,
        )
    exported_proc = declarations.exported_procedures.get(addr)
    if exported_proc is not None:
        return parser.parse_cpp_mangling(
            exported_proc, declarations.declared_types)
    return None
