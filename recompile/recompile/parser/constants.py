class Constants:
    def __init__(self):
        self._names = {}
        self._values = {}

    def add(self, name, value):
        if name not in self._values:
            self._values[name] = value
            names = self._names.get(value)
            if names is None:
                names = _Names()
                self._names[value] = names
            names.add(name)
            return
        old_value = self._values[name]
        if value != old_value and old_value is not None:
            self._values[name] = None
            self._names[old_value].remove(name)

    def update(self, other):
        assert isinstance(other, Constants)
        for name, value in other._values.items():
            self.add(name, value)

    def get_value(self, name):
        return self._values.get(name)

    def single_name(self, value):
        names = self._names.get(value)
        if names is None:
            return None
        return names.single_name()

    def find_name(self, value, constant_set):
        result = self._find_name_by_value(value, constant_set)
        if result is not None:
            return result
        return self._find_bit_flags(value, constant_set)

    def _find_name_by_value(self, value, constant_set):
        names = self._names.get(value)
        if names is None:
            return None
        return names.find_name(constant_set)

    def _find_bit_flags(self, value, constant_set):
        assert value >= 0
        found = False
        defined_bits = []
        bit_mask = 1
        while value != 0:
            if value & bit_mask:
                bit_name = self._find_name_by_value(bit_mask, constant_set)
                if bit_name is not None:
                    found = True
                else:
                    bit_name = "0x{:X}".format(bit_mask)
                defined_bits.append(bit_name)
                value -= bit_mask
            bit_mask *= 2
        if not found:
            return None
        return " | ".join(defined_bits)


class _Names:
    def __init__(self):
        self._names = set()

    def single_name(self):
        if len(self._names) != 1:
            return None
        return next(iter(self._names))

    def find_name(self, constant_set):
        if constant_set is None:
            return None
        if not constant_set.endswith("*"):
            return None
        return self._find_name_by_prefix(constant_set[:-1])

    def _find_name_by_prefix(self, prefix):
        result = None
        num_found = 0
        for name in self._names:
            if name.startswith(prefix):
                result = name
                num_found += 1
        return result if num_found == 1 else None

    def add(self, name):
        self._names.add(name)

    def remove(self, name):
        self._names.remove(name)
