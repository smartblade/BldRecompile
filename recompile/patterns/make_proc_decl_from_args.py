from calling_convention import CallingConvention
from procedure_declaration import ProcedureDeclaration


def make_proc_decl_from_args(args, is_method=False, callee_cleanup=True):
    parameters = []
    for arg in args:
        parameters.append((arg.data_type, None))
    if is_method:
        assert callee_cleanup
        convention = CallingConvention.THISCALL
        parameters = parameters[1:]
    elif callee_cleanup:
        convention = CallingConvention.STDCALL
    else:
        convention = CallingConvention.CDECL
    return ProcedureDeclaration(
        None, convention, None, parameters, None)
