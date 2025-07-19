import patterns.high_level.inline_functions as inline_functions


def transform_block_instructions(block_instructions, analysis, **kwargs):
    inline_functions.transform_block_instructions(block_instructions, **kwargs)
    analysis.transform_block_instructions(block_instructions, **kwargs)
