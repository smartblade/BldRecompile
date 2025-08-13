import instructions
from custom_block_transformer import transform_block
from block_visitor import visit_block


class Switch:
    def __init__(self, index, case_set_dict, blocks_dict, default_label):
        self._index = index
        self._case_set_dict = case_set_dict
        self._default_label = default_label
        self._blocks_dict = blocks_dict
        self._ensure_blocks_dict()

    def __repr__(self):
        return "Switch({})".format(self._index)

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

    def has_label(self, label):
        if self._default_label is not None and label == self._default_label:
            return True
        return label in self._case_set_dict

    def set_block(self, label, block):
        old_block = self._blocks_dict.pop(label)
        self._blocks_dict[label] = block
        return old_block

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
            index, self._case_set_dict, blocks_dict, **kwargs)
        if instr is not None:
            return instr
        return self.__class__(
            index, self._case_set_dict, blocks_dict, self._default_label)

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
                        writer.write_line("case {}:".format(case))
                with writer.indent():
                    for instr in block:
                        instr.emit_code(writer)
        writer.write_line("}")
