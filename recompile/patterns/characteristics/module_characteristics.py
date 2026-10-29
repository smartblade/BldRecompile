import json
import os

from hex_conversion import to_hex
import patterns.characteristics as characteristics


class ModuleCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    def __getitem__(self, item):
        addr_str = to_hex(item) if item is not None else None
        procedure_dict = self._characteristics_dict.get(addr_str, {})
        return characteristics.Procedure(procedure_dict)

    @staticmethod
    def read(module_name):
        file_path = os.path.join(
            os.path.dirname(os.path.realpath(__file__)),
            "..",
            "{}.characteristics.json".format(module_name),
        )
        try:
            with open(file_path, "rt") as f:
                characteristics_dict = json.load(f)
        except FileNotFoundError:
            characteristics_dict = {}
        return ModuleCharacteristics(characteristics_dict)
