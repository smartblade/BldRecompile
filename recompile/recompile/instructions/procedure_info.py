import data_types
import expressions


class ProcedureInfo:
    def __init__(self, method_class, local_size):
        self._this = None
        self._stack_delta = None
        self._this_offset = None
        self._method_class = method_class
        self._local_size = local_size
        self._preserved = []

    @property
    def stack_variables(self):
        if not self.is_thiscall:
            return {}
        return {self._this_offset: self._this}

    @property
    def stack_delta(self):
        return self._stack_delta

    @property
    def is_thiscall(self):
        return self._this_offset is not None

    @property
    def is_stack_pointer_trashed(self):
        return self._local_size != 0

    def __repr__(self):
        return (
            "ProcedureInfo("
            "this={}, this_offset={}, local_size={}, stack_delta={})").format(
            self._this, self._this_offset, self._local_size, self._stack_delta)

    def pop_reg_value(self, reg):
        if reg == "ecx" and self._this is None:
            self._this = expressions.Identifier(
                data_types.Pointer32(self._method_class), "this")
            return self._this
        raise Exception("Undefined register: {}".format(reg))

    def is_this_expression(self, e):
        return e is not None and self._this == e

    def define_this_offset(self, e):
        if (
            isinstance(e, expressions.ProcedureCall) and
            e.name == "STACKVAR" and
            len(e.arguments) == 2
        ):
            offset = int(e.arguments[0].emit_code())
            size = int(e.arguments[1].emit_code())
            if size == 4:
                self._this_offset = offset
                return
        raise Exception(
            "Unexpected expression found when defining 'this' variable "
            "offset: {}".format(e))

    def preserve(self, reg):
        self._preserved.append(reg)

    def set_stack_delta(self, stack_delta):
        self._stack_delta = stack_delta

    def transform(self, transform_callback, **kwargs):
        return transform_callback(self, **kwargs)

    def emit_code(self, writer):
        writer.write_line(repr(self))
