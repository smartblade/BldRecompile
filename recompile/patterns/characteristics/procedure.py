import patterns.characteristics as characteristics


class Procedure:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict
        self._variable_names = characteristics.VariablesNames(
            self._characteristics_dict.get("varnames", {}))
        self._constants = characteristics.Constants(
            self._characteristics_dict.get("constants", {}))
        self._parameters = characteristics.Parameters(
            self._characteristics_dict.get("parameters", []))
        self._return = characteristics.Return(
            self._characteristics_dict.get("return", {}))
        self._inline_calls = characteristics.InlineCalls(
            self._characteristics_dict.get("inlinecalls", []))

    @property
    def variables_names(self):
        return self._variable_names

    @property
    def constants(self):
        return self._constants

    @property
    def parameters(self):
        return self._parameters

    @property
    def ret(self):
        return self._return

    @property
    def inline_calls(self):
        return self._inline_calls
