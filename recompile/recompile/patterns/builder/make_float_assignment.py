import data_types
import instructions
import expressions


def make_float_assignment(block_builder, dst, src):
    if dst.data_type.size != src.data_type.size:
        if dst.data_type.size == 4:
            src = expressions.StaticCast(data_types.Float(), src)
        else:
            raise Exception(
                "Can't convert {} to {}.".format(src.data_type, dst.data_type))
    block_builder.add_instruction(instructions.Assignment(dst, src))
