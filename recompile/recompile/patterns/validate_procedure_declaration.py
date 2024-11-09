from calling_convention import CallingConvention


def validate_procedure_declaration(proc_decl, stack_delta, is_thiscall):
    if stack_delta != proc_decl.stack_delta:
        raise Exception(
            "Stack delta expected to be {} for {} but was: {}.".format(
                proc_decl.proc_name, stack_delta, proc_decl.stack_delta))
    if (
        is_thiscall and
        proc_decl.convention != CallingConvention.THISCALL
    ):
        raise Exception(
            "Convention expected to be 'thiscall' for {} but was: {}".format(
                proc_decl.proc_name, proc_decl.convention))
    if (
        not is_thiscall and
        proc_decl.convention == CallingConvention.THISCALL
    ):
        raise Exception(
            "Convention expected to be non-'thiscall'"
            " for {} but was: {}".format(
                proc_decl.proc_name, proc_decl.convention))
