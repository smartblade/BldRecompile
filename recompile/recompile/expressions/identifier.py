class Identifier:
    def __init__(self, data_type, name, address=None):
        self._data_type = data_type
        self._name = name
        self._address = address

    def __repr__(self):
        return "Id({})".format(self._name)

    @property
    def data_type(self):
        return self._data_type

    @property
    def name(self):
        return self._name

    @property
    def address(self):
        return self._address

    def change_data_type(self, data_type):
        self._data_type = data_type

    def rename(self, name):
        self._name = name

    def transform_expression(self, **kwargs):
        return self

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_identifier(self, **kwargs)
        if e is not None:
            return e
        return self

    def emit_code(self):
        return self._name
