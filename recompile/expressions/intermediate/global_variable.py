import data_types


class Global:
    def __init__(self, address):
        self._address = address
        self._ptr32 = data_types.Pointer32()

    @property
    def data_type(self):
        return self._ptr32

    @property
    def address(self):
        return self._address

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_global(self._address, **kwargs)
        if e is not None:
            return e
        return self

    def emit_code(self):
        return "GLOBAL(0x{:08X})".format(self._address)
