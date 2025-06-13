import data_types
import expressions


class LocalsAnalysis:
    def __init__(self):
        self._types_by_offset = {}

    def process_assignment(self, dst, src):
        if not isinstance(dst, expressions.intermediate.Stackvar):
            return
        assert dst.size == src.data_type.size
        self._update_type(dst.offset, src.data_type)

    def process_reinterpret(self, data_type, expression):
        if not isinstance(expression, expressions.intermediate.Stackvar):
            return
        assert expression.size == data_type.size
        self._update_type(expression.offset, data_type)

    def process_local(self, offset):
        self._types_by_offset[offset] = None

    def fill_stack_variables(self, stack_vars, variable_names):
        for offset, data_type in self._types_by_offset.items():
            if data_type is None:
                continue
            if offset in stack_vars:
                continue
            assert offset < 0
            name = variable_names.get(offset)
            if name is None:
                name = "unknown_loc_{:02X}".format(-offset)
            stack_vars[offset] = expressions.Identifier(data_type, name)

    def _update_type(self, offset, data_type):
        if offset >= 0:
            return
        if offset not in self._types_by_offset:
            if _is_acceptable_type(data_type):
                self._types_by_offset[offset] = data_type
            else:
                self._types_by_offset[offset] = None
            return
        existing_type = self._types_by_offset[offset]
        if existing_type is None:
            return
        if not data_types.are_compatible(existing_type, data_type):
            self._types_by_offset[offset] = None


def _is_acceptable_type(data_type):
    if isinstance(data_type, data_types.Pointer32):
        if isinstance(data_type.pointee, data_types.ClassType):
            return True
    return False
