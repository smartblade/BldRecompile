import expressions


def transform_local(local, stack_vars, analysis, **kwargs):
    variable = stack_vars.get(local.offset)
    if variable is not None:
        return expressions.AddressOf(variable)
    analysis.process_local(local)
    return None
