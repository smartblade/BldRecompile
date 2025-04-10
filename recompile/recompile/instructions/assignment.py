import data_types
import expressions
from merge_types import merge_types


class Assignment:
    def __init__(self, dst, src):
        self._dst = dst
        self._src = src

    def __repr__(self):
        return "Assign({}={})".format(self._dst, self._src)

    @property
    def dst(self):
        return self._dst

    @property
    def src(self):
        return self._src

    def transform_instruction(
        self, **kwargs
    ):
        src = self._src.transform_expression(**kwargs)
        dst = self._dst.transform_expression(**kwargs)
        src = _strip_brackets(src)
        if (
            isinstance(src, expressions.Constant) and
            isinstance(src.data_type, data_types.UnknownByte) and
            src.value > 0
        ):
            # Small value can not be pointer, and it's unlikely float, so make
            # it integer
            if isinstance(dst, expressions.Identifier):
                identifier = dst
                new_data_type = merge_types(
                    identifier.data_type, data_types.Int32()
                )
                identifier.change_data_type(new_data_type)
                if identifier.address is None:
                    new_var_name = identifier.name.replace(
                        "unknown_loc_", "unknown_int_loc_"
                    )
                else:
                    new_var_name = identifier.name.replace(
                        "unknown_gbl_", "unknown_int_gbl_"
                    )
                identifier.rename(new_var_name)
                src = expressions.Constant(identifier.data_type, src.value)
        return Assignment(dst, src)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._src.visit(on_expression_visited, **kwargs)
        self._dst.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        src = self._src.transform(transformer, **kwargs)
        dst = self._dst.transform(transformer, **kwargs)
        instr = transformer.transform_assignment(dst, src, **kwargs)
        if instr is not None:
            return instr
        if src == self._src and dst == self._dst:
            return self
        return self.__class__(dst, src)

    def emit_code(self, writer):
        dst = self._dst.emit_code()
        src = self._src.emit_code()
        comment = ""
        if (
            src.endswith("unknown_fpu_2") and
            dst.startswith("unknown_ptr_0C")
        ):
            comment += " // TODO inconsitent coalescing"
        writer.write_line("{} = {};{}".format(dst, src, comment))


def _strip_brackets(e):
    if isinstance(e, expressions.BracketsExpression):
        return e.expression
    return e
