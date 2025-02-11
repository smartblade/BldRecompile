import instructions
from custom_block_transformer import transform_block
from block_visitor import visit_block


class Switch:
    def __init__(self, index, case_set_dict, blocks_dict):
        self._index = index
        self._case_set_dict = case_set_dict
        self._blocks_dict = blocks_dict
        self._ensure_blocks_dict()

    def __repr__(self):
        return "Switch({})".format(self._index)

    def _ensure_blocks_dict(self):
        for label in self._case_set_dict.keys():
            if label not in self._blocks_dict:
                self._blocks_dict[label] = [instructions.Goto(label)]

    def has_label(self, label):
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

    def transform(self, transform_callback, **kwargs):
        index = self._index.transform(transform_callback, **kwargs)
        blocks_dict = {}
        self._ensure_blocks_dict()
        for label, block in self._blocks_dict.items():
            blocks_dict[label] = transform_block(
                block, transform_callback, **kwargs)
        while_instr = self.__class__(index, self._case_set_dict, blocks_dict)
        return transform_callback(while_instr, **kwargs)

    def emit_code(self, writer):
        index = self._index.emit_code()
        writer.write_line("switch ({})".format(index))
        writer.write_line("{")
        with writer.indent():
            self._ensure_blocks_dict()
            for label, block in self._blocks_dict.items():
                case_set = self._case_set_dict[label]
                for case in case_set:
                    writer.write_line("case {}:".format(case))
                with writer.indent():
                    for instr in block:
                        instr.emit_code(writer)
        writer.write_line("}")
