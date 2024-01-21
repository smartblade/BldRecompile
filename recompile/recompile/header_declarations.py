import data_types


class HeaderDeclarations:
    def __init__(
        self, proc_decl, recompiled_decls, full_typed_args_by_proc,
        external_procedures, gbl_vars
    ):
        self._proc_decl = proc_decl
        self._recompiled_decls = recompiled_decls
        self._typed_args_by_proc = full_typed_args_by_proc
        self._external_procedures = _procedures_to_dict(external_procedures)
        self._gbl_vars = gbl_vars

    @property
    def proc_decl(self):
        return self._proc_decl

    @property
    def recompiled_decls(self):
        return self._recompiled_decls

    @property
    def full_typed_args_by_proc(self):
        return self._typed_args_by_proc

    @property
    def gbl_vars(self):
        return self._gbl_vars

    def external_procedure_by_name(self, name):
        return self._external_procedures.get(name)

    def get_declaration_at(self, addr):
        if addr in self._recompiled_decls:
            full_typed_args = self._typed_args_by_proc.get(addr, set())
            cdecl = self._recompiled_decls[addr].get_declaration(
                is_metafile=True, full_typed_args=full_typed_args
            )
            proc_name = self._recompiled_decls[addr].proc_name
        else:
            cdecl = None
            proc_name = "unknown_procedure_{}".format(addr)
        return proc_name, cdecl

    def emit_metafile(self, decl_file_name):
        if self._proc_decl is None and len(self._typed_args_by_proc) == 0:
            return False
        lines = []
        self._emit_types_declarations(is_metafile=True, lines=lines)
        with open(decl_file_name, "wt") as f:
            f.write("\n".join(lines))
        return True

    def emit_header(self):
        lines = [
            "#pragma once",
            "",
        ]
        self._emit_types_declarations(is_metafile=False, lines=lines)
        need_new_line = False
        for ext_proc in self._external_procedures.values():
            if ext_proc.method_class is not None:
                continue
            declaration = ext_proc.get_declaration(is_metafile=False)
            lines.append("{};".format(declaration))
            need_new_line = True
        for gbl in self._gbl_vars.values():
            if gbl.data_type is not None:
                declaration = gbl.data_type.make_variable_declaration(
                    gbl.name, is_metafile=False
                )
            else:
                declaration = "struct unknown {}".format(gbl.name)
            lines.append("extern {};".format(declaration))
            need_new_line = True
        if need_new_line:
            lines.append("")
        return "\n".join(lines)

    def _emit_types_declarations(self, is_metafile, lines):
        emitted_types = set()
        if self._proc_decl is not None:
            _emit_procedure_types_declarations(
                self._proc_decl, is_metafile, lines, emitted_types
            )
        for callee_addr, typed_args in self._typed_args_by_proc.items():
            callee = self._recompiled_decls[callee_addr]
            _emit_procedure_types_declarations(
                callee, is_metafile, lines, emitted_types
            )
        for gbl in self._gbl_vars.values():
            _emit_type_declaration(
                gbl.data_type, is_metafile, lines, emitted_types
            )


def _emit_procedure_types_declarations(
        proc_decl, is_metafile, lines, emitted_types
):
    for data_type in proc_decl.get_used_types().values():
        _emit_type_declaration(data_type, is_metafile, lines, emitted_types)


def _emit_type_declaration(data_type, is_metafile, lines, emitted_types):
    if isinstance(data_type, data_types.Pointer32):
        _emit_type_declaration(
            data_type.pointee, is_metafile, lines, emitted_types
        )
        return
    if not isinstance(data_type, data_types.ClassType):
        return
    if data_type.class_name in emitted_types:
        return
    emitted_types.add(data_type.class_name)
    alignment = data_type.alignment
    if alignment:
        lines.append("#pragma pack(push, {})".format(alignment))
        lines.append("")
    lines.append(data_type.get_declaration(is_metafile))
    if alignment:
        lines.append("#pragma pack(pop)")
        lines.append("")


def _procedures_to_dict(procedures):
    proc_dict = {}
    for proc in procedures:
        if proc.proc_name in proc_dict:
            raise Exception(
                "Redeclared external procedure: {}".format(proc.proc_name)
            )
        proc_dict[proc.proc_name] = proc
    return proc_dict
