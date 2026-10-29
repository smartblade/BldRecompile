from patterns.procedure import Procedure
from procedure_declaration import ProcedureDeclaration


def apply_parameters_names(procedure, characteristics):
    variables_names = characteristics.variables_names
    proc_decl = procedure.proc_decl
    if proc_decl is None:
        return procedure
    stack_vars = proc_decl.stack_variables
    changed_names = {}
    for offset, param_id in stack_vars.items():
        variable_name = variables_names.get(offset)
        if variable_name is not None:
            changed_names[param_id.name] = variable_name
    if not changed_names:
        return procedure
    param_ids = list(proc_decl.get_parameters_ids().values())
    if proc_decl.is_instance_method:
        param_ids = param_ids[1:]
    parameters = []
    for param_id in param_ids:
        name = changed_names.get(param_id.name, param_id.name)
        parameters.append((param_id.data_type, name))
    proc_decl = proc_decl.copy(parameters=parameters)
    return procedure.copy(proc_decl=proc_decl)
