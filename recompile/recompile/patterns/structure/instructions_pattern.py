from .instruction import Instruction


class InstructionsPattern:
    def __init__(self, json, operand_sets, cmd_code_dict):
        self._instructions = json["instructions"]
        self._instructions = []
        for instruction in json["instructions"]:
            self._instructions.append(
                Instruction(instruction, operand_sets, cmd_code_dict))
        self._action = json.get("action")
        self._actions = json.get("actions")
        self._restrictions = json.get("restrictions")
        _validate_instructions_pattern_attributes(json)

    @property
    def action(self):
        return self._action

    @property
    def actions(self):
        return self._actions

    @property
    def instructions(self):
        return self._instructions

    @property
    def restrictions(self):
        return self._restrictions


def _validate_instructions_pattern_attributes(json):
    unknown_attributes = set(json.keys()) - {
        'instructions',
        'action',
        'actions',
        'restrictions',
    }
    if unknown_attributes:
        raise Exception(
            "Unknown pattern attributes: {}".format(unknown_attributes))
