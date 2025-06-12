def transform_block(instructions, transformer, **kwargs):
    new_instrs_iter = _InstructionsIter()
    transforming_block = _TransformingBlock(new_instrs_iter)
    for instruction in instructions:
        new_instrs_iter.add_instruction(instruction)
        transformer.pre_transform_block_instructions(
            transforming_block, **kwargs)
        cur_instruction = transforming_block.get_current_instruction()
        if cur_instruction == instruction:
            new_instruction = cur_instruction.transform(transformer, **kwargs)
            interval = transforming_block.interval(0)
            interval.replace_instructions([new_instruction])
        transformer.transform_block_instructions(transforming_block, **kwargs)
    return new_instrs_iter.instructions


class _InstructionsIter:
    def __init__(self):
        self._instructions = []
        self._current_index = -1

    def as_instr(self, offset, instr_class):
        instr = self._instructions[self._current_index + offset]
        if instr_class is not None and not isinstance(instr, instr_class):
            return None
        return instr

    def replace_instructions(self, start_offset, new_instructions):
        assert self._current_index == len(self._instructions) - 1
        start_index = self._current_index + start_offset
        index_change = len(new_instructions)
        while len(self._instructions) > start_index:
            self._instructions.pop()
            index_change -= 1
        self._instructions.extend(new_instructions)
        self._current_index += index_change
        return index_change

    def add_instruction(self, instr):
        self._instructions.append(instr)
        self._current_index = len(self._instructions) - 1

    @property
    def instructions(self):
        return self._instructions


class _TransformingBlock:
    def __init__(self, instrs_iter):
        self._instrs_iter = instrs_iter

    def get_current_instruction(self, instr_class=None):
        return self._instrs_iter.as_instr(0, instr_class)

    def interval(self, offset):
        assert offset <= 0
        return _TransformingInstructionInterval(self._instrs_iter, offset)


class _TransformingInstructionInterval:
    def __init__(self, instrs_iter, start_offset):
        self._instrs_iter = instrs_iter
        self._start_offset = start_offset

    def as_instr(self, index, instr_class=None):
        assert index >= 0
        return self._instrs_iter.as_instr(
            self._start_offset + index, instr_class)

    def replace_instructions(self, new_instructions):
        self._start_offset -= self._instrs_iter.replace_instructions(
            self._start_offset, new_instructions)
