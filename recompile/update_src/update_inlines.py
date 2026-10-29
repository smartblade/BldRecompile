def define_nearest_inline_definitions(src_files, procedures_data):
    header_declarations_data = _get_header_procedures_data(src_files)
    header_procedures_data = dict(
        (addr, p) for addr, p in procedures_data.items()
        if (
            (p.file is None or p.file.file_name.lower().endswith(".h")) and
            p.procedure.address % 16 == 0
        )
    )
    header_procedures_data.update(header_declarations_data)
    sorted_declarations = sorted(
        header_procedures_data.values(),
        key=lambda p: (
            p.get_class_name() or "",
            not p.is_declaration,
            p.procedure.address,
        ),
    )
    first_undefined_decls = []
    prev_procedure_data = None
    cur_class_name = None
    for procedure_data in sorted_declarations:
        if procedure_data.procedure.proc_decl is None:
            continue
        if procedure_data.get_class_name() != cur_class_name:
            first_undefined_decls = []
            prev_procedure_data = None
            cur_class_name = procedure_data.get_class_name()
        if procedure_data.file is None:
            if prev_procedure_data is not None:
                procedure_data.file = prev_procedure_data.file
                procedure_data.is_inline = True
                procedure_data.prev_src_definition = \
                    prev_procedure_data.src_definition
            else:
                first_undefined_decls.append(procedure_data)
        else:
            for undefined_proc in first_undefined_decls:
                undefined_proc.file = procedure_data.file
                undefined_proc.is_inline = True
                undefined_proc.next_src_definition = \
                    procedure_data.src_definition
            first_undefined_decls = []
            prev_procedure_data = procedure_data


def _get_header_procedures_data(src_files):
    header_declarations_data = {}
    for src_file in src_files:
        for procedure_data in src_file.procedures:
            if not procedure_data.is_declaration:
                continue
            if procedure_data.src_definition is None:
                continue
            procedure = procedure_data.procedure
            header_declarations_data[procedure.address] = procedure_data
    return header_declarations_data
