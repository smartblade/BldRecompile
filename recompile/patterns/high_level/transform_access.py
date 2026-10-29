from expressions.do_pointer_dereference import do_pointer_dereference


def transform_access(expression, offset, size, analysis, **kwargs):
    analysis.process_access(expression, offset, size)
    return do_pointer_dereference(expression, offset, size)
