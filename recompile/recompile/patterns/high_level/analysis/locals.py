import data_types
import expressions
from expressions.operator import Operator


class LocalsAnalysis:
    def __init__(self):
        self._types_by_offset = {}
        self._compared_types_by_offset = {}
        self._min_local_ptr_offset = 0

    def process_assignment(self, dst, src):
        if not isinstance(dst, expressions.intermediate.Stackvar):
            return
        assert dst.size == src.data_type.size
        self._update_type(dst.offset, src.data_type)

    def process_binary(self, operator, left, right):
        if (
            operator != Operator.LT and operator != Operator.LE and
            operator != Operator.GT and operator != Operator.GE
        ):
            return
        if not data_types.are_same(left.data_type, right.data_type):
            return
        if not isinstance(
            left.data_type, (data_types.Int32, data_types.UInt32)
        ):
            return
        self._process_comparison_operand(left)
        self._process_comparison_operand(right)

    def _process_comparison_operand(self, e):
        if not isinstance(e, expressions.ReinterpretCast):
            return
        stackvar = e.expression
        if not isinstance(stackvar, expressions.intermediate.Stackvar):
            return
        if stackvar.size != e.data_type.size:
            return
        if stackvar.offset not in self._compared_types_by_offset:
            self._compared_types_by_offset[stackvar.offset] = e.data_type
            return
        existing_type = self._compared_types_by_offset[stackvar.offset]
        if existing_type is None:
            return
        if not data_types.are_same(existing_type, e.data_type):
            self._compared_types_by_offset[stackvar.offset] = None

    def process_reinterpret(self, data_type, expression):
        if not isinstance(expression, expressions.intermediate.Stackvar):
            return
        assert expression.size == data_type.size
        self._update_type(expression.offset, data_type)

    def process_local(self, offset):
        self._types_by_offset[offset] = None
        if offset < self._min_local_ptr_offset:
            self._min_local_ptr_offset = offset

    def fill_stack_variables(self, stack_vars, variable_names):
        for offset, data_type in self._types_by_offset.items():
            if data_type is None:
                continue
            if offset in stack_vars:
                continue
            if offset >= self._min_local_ptr_offset:
                continue
            assert offset < 0
            name = variable_names.get(offset)
            if name is None:
                name = "unknown_loc_{:02X}".format(-offset)
            if isinstance(data_type, data_types.AnyInt):
                data_type = self._compared_types_by_offset.get(offset)
                if data_type is None:
                    continue
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
            if (
                existing_type.is_any_int and data_type.is_any_int and
                existing_type.size == data_type.size
            ):
                self._types_by_offset[offset] = data_types.AnyInt(
                    data_type.size
                )
            else:
                self._types_by_offset[offset] = None


def _is_acceptable_type(data_type):
    if isinstance(data_type, data_types.Pointer32):
        if isinstance(data_type.pointee, data_types.ClassType):
            return True
    if data_type.is_any_int and data_type.size == 4:
        return True
    return False
