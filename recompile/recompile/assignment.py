from unparsed_token import UnparsedToken
from int32 import Int32
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
        if src.as_one_token() == "0x00":
            src = UnparsedToken("0")
        elif src.as_one_token() == "0x01":
            # 0x01 can not be pointer and it's unlikely float, so make it
            # integer
            identifier = dst.as_identifier()
            if identifier is not None:
                new_data_type = merge_types(identifier.data_type, Int32())
                identifier.change_data_type(new_data_type)
                new_var_name = identifier.name.replace(
                    "unknown_loc_", "unknown_int_loc_"
                )
                identifier.rename(new_var_name)
                src = UnparsedToken("1")
        return Assignment(dst, src)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._src.visit(on_expression_visited, **kwargs)
        self._dst.visit(on_expression_visited, **kwargs)

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
