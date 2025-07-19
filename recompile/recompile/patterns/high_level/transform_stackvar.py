def transform_stackvar(offset, size, stack_vars, analysis, **kwargs):
    variable = stack_vars.get(offset)
    if variable is not None and variable.data_type.size == size:
        return variable
    analysis.process_stackvar(offset, size)
    return None
