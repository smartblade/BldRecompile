import expressions
import instructions


def extract_vtbl_addr_from_assign(proc_info, instr):
    if not isinstance(instr, instructions.Assignment):
        return None
    dst = instr.dst
    if not isinstance(dst, expressions.intermediate.Access):
        return None
    if dst.size != 4:
        return None
    if dst.offset != 0:
        return None
    if not proc_info.is_this_expression(dst.expression):
        return None
    src = instr.src
    if not isinstance(src, expressions.intermediate.Global):
        return None
    return src.address
