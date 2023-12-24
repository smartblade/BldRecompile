class HeaderDeclarations:
    def __init__(self, proc_decl, recompiled_decls, full_typed_args_by_proc):
        self._proc_decl = proc_decl
        self._recompiled_decls = recompiled_decls
        self._typed_args_by_proc = full_typed_args_by_proc

    @property
    def proc_decl(self):
        return self._proc_decl

    @property
    def recompiled_decls(self):
        return self._recompiled_decls

    @property
    def full_typed_args_by_proc(self):
        return self._typed_args_by_proc

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
        with open(decl_file_name, "wt") as f:
            if self._proc_decl is not None:
                f.write(
                    self._proc_decl.get_types_declarations(is_metafile=True)
                )
            for callee_addr, typed_args in self._typed_args_by_proc.items():
                callee = self._recompiled_decls[callee_addr]
                f.write(callee.get_types_declarations(is_metafile=True))
        return True

    def emit_header(self):
        lines = [
            "#pragma once",
            "",
            self._proc_decl.get_types_declarations(is_metafile=False),
        ]
        for callee_addr, full_typed_args in self._typed_args_by_proc.items():
            callee = self._recompiled_decls[callee_addr]
            lines.append(callee.get_types_declarations(is_metafile=False))
        return "\n".join(lines)
