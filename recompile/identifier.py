class Identifier:
    def __init__(self, data_type, name):
        self._data_type = data_type
        self._name = name

    @property
    def data_type(self):
        return self._data_type

    @property
    def name(self):
        return self._name

    def change_data_type(self, data_type):
        self._data_type = data_type

    def rename(self, name):
        self._name = name

    def emit_code(self):
        return self._name
