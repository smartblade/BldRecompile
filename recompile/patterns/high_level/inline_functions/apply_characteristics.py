import data_types
import expressions
import instructions


def apply_characteristics_to_assignment(
    block_instructions, dst, src, characteristics, inline_procedures,
    stack_vars, **kwargs
):
    if dst.size != 4:
        return
    inline_call_chr = characteristics.inline_calls.by_this_offset(dst.offset)
    if inline_call_chr is None:
        return
    num_instructions = 1
    inline_chain = None
    while True:
        chain = block_instructions.interval(num_instructions)
        if chain.as_instr(num_instructions) is None:
            break
        num_instructions += 1
        inline_chain = chain
    if inline_chain is None:
        return
    this_obj = src
    arguments = []
    for arg in inline_call_chr.arguments:
        assert arg.offset not in stack_vars
        arguments.append(
            expressions.intermediate.Stackvar(arg.offset, arg.size))
    assert dst.offset not in stack_vars
    stack_vars[dst.offset] = expressions.Identifier(
        data_types.Pointer32(), "__inline_method_obj")
    inline_instr = []
    for i in range(num_instructions - 1):
        inline_instr.append(inline_chain.as_instr(i + 1))
    inline_procedures.add_method(
        this_obj.data_type.pointee, dst.offset, inline_instr,
        inline_call_chr.name, inline_call_chr.arguments)
    inline_call = instructions.CodeInstruction(
        expressions.ProcedureCall(
            name=inline_call_chr.name,
            is_method=True,
            arguments=[this_obj, *arguments],
        )
    )
    inline_chain.replace_instructions([inline_call])
