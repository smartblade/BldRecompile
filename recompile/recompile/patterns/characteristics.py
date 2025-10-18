import json
import os

from hex_conversion import to_hex


class ModuleCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    def __getitem__(self, item):
        addr_str = to_hex(item) if item is not None else None
        procedure_dict = self._characteristics_dict.get(addr_str, {})
        return ProcedureCharacteristics(procedure_dict)

    @staticmethod
    def read(module_name):
        file_path = os.path.join(
            os.path.dirname(os.path.realpath(__file__)),
            "{}.characteristics.json".format(module_name)
        )
        try:
            with open(file_path, "rt") as f:
                characteristics_dict = json.load(f)
        except FileNotFoundError:
            characteristics_dict = {}
        return ModuleCharacteristics(characteristics_dict)


class ExternalCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    def __getitem__(self, proc_name):
        procedure_dict = self._characteristics_dict.get(proc_name, {})
        return ProcedureCharacteristics(procedure_dict)

    @staticmethod
    def read(file_path):
        try:
            with open(file_path, "rt") as f:
                characteristics_dict = json.load(f)
        except FileNotFoundError:
            characteristics_dict = {}
        return ExternalCharacteristics(characteristics_dict)


class ProcedureCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict
        self._variable_names = VariablesNames(
            self._characteristics_dict.get("varnames", {}))
        self._parameters = Parameters(
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


class VariablesNames:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    def get(self, offset):
        return self._json_dict.get(str(offset))


class Parameters:
    def __init__(self, json_list):
        self._parameters = []
        for param_dict in json_list:
            index = int(param_dict["index"])
            if index > len(self._parameters):
                for i in range(index - len(self._parameters)):
                    self._parameters.append(Parameter({}))
            self._parameters.append(Parameter(param_dict))

    def __getitem__(self, index):
        if index < len(self._parameters):
            return self._parameters[index]
        return Parameter({})


class Parameter:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    @property
    def constant_set(self):
        return self._json_dict.get("constantset", None)
