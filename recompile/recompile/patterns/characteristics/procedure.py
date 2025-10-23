import patterns.characteristics as characteristics


class Procedure:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict
        self._variable_names = characteristics.VariablesNames(
            self._characteristics_dict.get("varnames", {}))
        self._parameters = characteristics.Parameters(
            self._characteristics_dict.get("parameters", []))

    @property
    def is_boolean_return(self):
        return_dict = self._characteristics_dict.get("return", {})
        return return_dict.get("boolean") == "yes"

    @property
    def variables_names(self):
        return self._variable_names

    @property
    def parameters(self):
        return self._parameters
