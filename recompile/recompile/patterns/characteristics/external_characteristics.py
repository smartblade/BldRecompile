import json

import patterns.characteristics as characteristics


class ExternalCharacteristics:
    def __init__(self, characteristics_dict):
        self._characteristics_dict = characteristics_dict

    def __getitem__(self, proc_name):
        procedure_dict = self._characteristics_dict.get(proc_name, {})
        return characteristics.Procedure(procedure_dict)

    @staticmethod
    def read(file_path):
        try:
            with open(file_path, "rt") as f:
                characteristics_dict = json.load(f)
        except FileNotFoundError:
            characteristics_dict = {}
        return ExternalCharacteristics(characteristics_dict)
