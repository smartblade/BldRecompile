import json
import os

from hex_conversion import to_hex


class ModuleCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    def __getitem__(self, item):
        procedure_dict = self._characteristics_dict.get(to_hex(item), {})
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


class ProcedureCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    @property
    def is_boolean_return(self):
        return_dict = self._characteristics_dict.get("return", {})
        return return_dict.get("boolean") == "yes"
