class PrefixStatus:
    def __init__(self, prefix_builder, instrs):
        self._prefix_builder = prefix_builder
        self._instrs = instrs
        self._start_pos = 0
        self._end_pos = 0
        self._add_instructions_to_prefix()

    @property
    def prefix(self):
        return self._prefix_builder.prefix

    def _add_instructions_to_prefix(self):
        while self._end_pos < len(self._instrs):
            command_code = self._instrs[self._end_pos].command_code
            if not self._prefix_builder.add_command_code(command_code):
                break
            self._end_pos += 1

    def _remove_instructions_from_prefix(self, num_instructions):
        for i in range(num_instructions):
            if self._start_pos < self._end_pos:
                self._prefix_builder.remove_first_command_code()
                self._start_pos += 1
            else:
                assert self._start_pos == self._end_pos
                assert self._prefix_builder.prefix == 0
                self._start_pos += 1
                self._end_pos += 1

    def update(self, num_matched_instructions):
        self._remove_instructions_from_prefix(num_matched_instructions)
        self._add_instructions_to_prefix()
