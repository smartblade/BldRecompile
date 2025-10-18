import expressions


def get_call_characteristics(declarations, pc: expressions.ProcedureCall):
    if pc.callee_address is None:
        proc_decl = declarations.external_procedures.get(pc.name)
        if proc_decl is None:
            return declarations.external_characteristics[pc.name]
        return declarations.external_characteristics[proc_decl.proc_name]
    return declarations.characteristics[pc.callee_address]
