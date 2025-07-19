import patterns.high_level.inline_functions as inline_functions


def transform_if(if_clause, if_block, else_block, **kwargs):
    return inline_functions.transform_if(if_clause, if_block, else_block)
