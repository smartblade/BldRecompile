from custom_block_transformer import transform_block


class LabeledBlock:
    def __init__(self, label, instructions):
        self._label = label
        self._instructions = instructions

    @property
    def label(self):
        return self._label

    @property
    def instructions(self):
        return list(self._instructions)

    def transform(self, transform_callback, **kwargs):
        instructions = transform_block(
            self._instructions, transform_callback, **kwargs)
        return LabeledBlock(self._label, instructions)

    def emit_code(self, writer):
        writer.write_line("{}:".format(self._label), indent=0)
        for instr in self._instructions:
            instr.emit_code(writer)
