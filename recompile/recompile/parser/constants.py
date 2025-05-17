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

    def get_value(self, name):
        return self._values.get(name)

    def single_name(self, value):
        names = self._names.get(value)
        if names is None:
            return None
        return names.single_name()


class _Names:
    def __init__(self):
        self._names = set()

    def single_name(self):
        if len(self._names) != 1:
            return None
        return next(iter(self._names))

    def add(self, name):
        self._names.add(name)

    def remove(self, name):
        self._names.remove(name)
