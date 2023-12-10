def visit_block(instructions, on_expression_visited, **kwargs):
    for instruction in instructions:
        instruction.visit(on_expression_visited, **kwargs)
