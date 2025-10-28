import expressions


def transform_local(offset, stack_vars, analysis, **kwargs):
    variable = stack_vars.get(offset)
    if variable is not None:
        return expressions.AddressOf(variable)
    analysis.process_local(offset)
    return None
