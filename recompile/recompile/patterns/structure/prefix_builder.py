class PrefixBuilder:
    def __init__(self, most_frequent_cmd_code):
        self._max_bit_size = 16
        self._most_frequent_cmd_code = most_frequent_cmd_code
        self._cur_bit = 0
        self._prefix = 0

    @property
    def prefix(self):
        return self._prefix

    @property
    def max_prefix(self):
        return 1 << self._max_bit_size

    @property
    def all_prefixes(self):
        assert self._cur_bit <= self._max_bit_size
        for i in range(1 << (self._max_bit_size - self._cur_bit)):
            yield (1 << self._cur_bit) * i + self._prefix

    def add_command_code(self, command_code):
        if command_code != self._most_frequent_cmd_code:
            bit_size = 8
            code = 2 * command_code
            assert code < 256
        else:
            bit_size = 1
            code = 1
        if self._cur_bit + bit_size > self._max_bit_size:
            return False
        self._prefix += (1 << self._cur_bit) * code
        self._cur_bit += bit_size
        return True

    def remove_first_command_code(self):
        assert self._cur_bit > 0
        if self._prefix & 1 == 0:
            bit_size = 8
        else:
            bit_size = 1
        assert self._cur_bit >= bit_size
        self._cur_bit -= bit_size
        self._prefix = self._prefix >> bit_size
