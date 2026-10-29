import instructions
from custom_block_transformer import transform_block
from block_visitor import visit_block


class Switch:
    def __init__(
        self, index, case_set_dict, blocks_dict, default_label, constant_dict
    ):
        self._index = index
        self._case_set_dict = case_set_dict
        self._default_label = default_label
        self._blocks_dict = blocks_dict
        self._constant_dict = constant_dict
        self._ensure_blocks_dict()

    def __repr__(self):
        return "Switch({})".format(self._index)

    @property
    def index(self):
        return self._index

    @property
    def default_label(self):
        return self._default_label

    @property
    def blocks_dict(self):
        return self._blocks_dict

    def copy(self, index=None, default_label=None, cases_offset=None):
        index = index or self._index
        default_label = default_label or self._default_label
        if cases_offset is not None:
            case_set_dict = {}
            for label, case_set in self._case_set_dict.items():
                case_set_dict[label] = set(c + cases_offset for c in case_set)
        else:
            case_set_dict = self._case_set_dict
        return self.__class__(
            index, case_set_dict, self._blocks_dict, default_label,
            self._constant_dict)

    def validate_cases(self, min_case, range_diff):
        min_case = min_case or 0
        max_case = min_case + range_diff
        all_cases = set()
        for case_set in self._case_set_dict.values():
            for case in case_set:
                assert min_case <= case <= max_case
                assert case not in all_cases
                all_cases.add(case)
        assert len(all_cases) == range_diff + 1

    def _ensure_blocks_dict(self):
        for label in self._case_set_dict.keys():
            if label not in self._blocks_dict:
                self._blocks_dict[label] = [instructions.Goto(label)]
        if (
            self._default_label is not None and
            self._default_label not in self._blocks_dict
        ):
            self._blocks_dict[self._default_label] = [
                instructions.Goto(self._default_label)
            ]

    def _emit_case_constant(self, case):
        if case not in self._constant_dict:
            return case
        return self._constant_dict[case]

    def has_label(self, label):
        if self._default_label is not None and label == self._default_label:
            return True
        return label in self._case_set_dict

    def set_block(self, label, block):
        old_block = self._blocks_dict.pop(label)
        self._blocks_dict[label] = block
        return old_block

    def eliminate_empty_default_block(self):
        default_block = self._blocks_dict[self._default_label]
        if len(default_block) != 1:
            return
        if not isinstance(default_block[0], instructions.Break):
            return
        del self._blocks_dict[self._default_label]
        self._default_label = None

    def visit(self, on_expression_visited, **kwargs):
        self._index.visit(on_expression_visited, **kwargs)
        self._ensure_blocks_dict()
        for label, block in self._blocks_dict.items():
            visit_block(block, on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        index = self._index.transform(transformer, **kwargs)
        blocks_dict = {}
        self._ensure_blocks_dict()
        for label, block in self._blocks_dict.items():
            blocks_dict[label] = transform_block(
                block, transformer, **kwargs)
        instr = transformer.transform_switch(
            index, self._case_set_dict, blocks_dict, self._default_label,
            self._constant_dict, **kwargs)
        if instr is not None:
            return instr
        return self.__class__(
            index, self._case_set_dict, blocks_dict, self._default_label,
            self._constant_dict)

    def emit_code(self, writer):
        index = self._index.emit_code()
        writer.write_line("switch ({})".format(index))
        writer.write_line("{")
        with writer.indent():
            self._ensure_blocks_dict()
            for label, block in self._blocks_dict.items():
                if label == self._default_label:
                    writer.write_line("default:")
                else:
                    case_set = self._case_set_dict[label]
                    for case in case_set:
                        writer.write_line(
                            "case {}:".format(self._emit_case_constant(case)))
                with writer.indent():
                    for instr in block:
                        instr.emit_code(writer)
        writer.write_line("}")
