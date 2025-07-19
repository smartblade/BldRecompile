def transform_block(instructions, transformer, **kwargs):
    new_instrs_iter = _InstructionsIter(instructions)
    transforming_block = _TransformingBlock(new_instrs_iter)
    for instruction in new_instrs_iter:
        transformer.pre_transform_block_instructions(
            transforming_block, **kwargs)
        cur_instruction = transforming_block.get_current_instruction()
        if cur_instruction == instruction:
            new_instruction = cur_instruction.transform(transformer, **kwargs)
            interval = transforming_block.interval(0)
            interval.replace_instructions([new_instruction])
    new_instrs_iter = _InstructionsIter(new_instrs_iter.instructions)
    transforming_block = _TransformingBlock(new_instrs_iter)
    for _ in new_instrs_iter:
        transformer.transform_block_instructions(transforming_block, **kwargs)
    return new_instrs_iter.instructions


class _InstructionsIter:
    def __init__(self, instructions):
        self._instructions = []
        self._pending_instructions = list(reversed(instructions))
        self._current_index = -1

    def as_instr(self, offset, instr_class):
        if offset > 0:
            if offset > len(self._pending_instructions):
                return None
            instr = self._pending_instructions[-offset]
        else:
            instr = self._instructions[self._current_index + offset]
        if instr_class is not None and not isinstance(instr, instr_class):
            return None
        return instr

    def replace_instructions(self, start_offset, end_offset, new_instructions):
        assert self._current_index == len(self._instructions) - 1
        start_index = self._current_index + start_offset
        index_change = len(new_instructions)
        while len(self._instructions) > start_index:
            self._instructions.pop()
            index_change -= 1
        self._instructions.extend(new_instructions)
        self._current_index += index_change
        for i in range(end_offset):
            self._pending_instructions.pop()
        return index_change

    def __iter__(self):
        return self

    def __next__(self):
        if len(self._pending_instructions) == 0:
            raise StopIteration
        self._instructions.append(self._pending_instructions.pop())
        self._current_index += 1
        return self._instructions[self._current_index]

    @property
    def instructions(self):
        return self._instructions


class _TransformingBlock:
    def __init__(self, instrs_iter):
        self._instrs_iter = instrs_iter

    def get_current_instruction(self, instr_class=None):
        return self._instrs_iter.as_instr(0, instr_class)

    def interval(self, offset):
        return _TransformingInstructionInterval(self._instrs_iter, offset)


class _TransformingInstructionInterval:
    def __init__(self, instrs_iter, offset):
        self._instrs_iter = instrs_iter
        if offset <= 0:
            self._start_offset = offset
            self._end_offset = 0
        else:
            self._start_offset = 0
            self._end_offset = offset

    def as_instr(self, index, instr_class=None):
        assert index >= 0
        return self._instrs_iter.as_instr(
            self._start_offset + index, instr_class)

    def replace_instructions(self, new_instructions):
        self._start_offset -= self._instrs_iter.replace_instructions(
            self._start_offset, self._end_offset, new_instructions)
