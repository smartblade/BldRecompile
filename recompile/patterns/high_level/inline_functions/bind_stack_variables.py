from expression_transformer import ExpressionTransformer
import expressions


def bind_stack_variables(instrs, proc_decl, arguments):
    stack_variables = list(proc_decl.stack_variables.keys())
    assert len(stack_variables) == len(arguments)
    stack_mapping = {}
    for i, offset in enumerate(stack_variables):
        stack_mapping[arguments[i].offset] = offset
    new_instructions = []
    for instr in instrs:
        new_instructions.append(
            instr.transform(_Transformer(stack_mapping)))
        return new_instructions


class _Transformer(ExpressionTransformer):
    def __init__(self, stack_mapping):
        self._stack_mapping = stack_mapping

    def transform_stackvar(self, offset, size):
        new_offset = self._stack_mapping.get(offset)
        if new_offset is None:
            return None
        return expressions.intermediate.Stackvar(new_offset, size)
