from .action import Action
from .expression_pattern import ExpressionPattern
from .instruction import Instruction


class InstructionsPattern:
    def __init__(self, json, operand_sets, cmd_code_dict):
        self._instructions = json["instructions"]
        self._instructions = []
        for instruction in json["instructions"]:
            self._instructions.append(
                Instruction(instruction, operand_sets, cmd_code_dict))
        action_json = json.get("action")
        self._action = None
        if action_json is not None:
            self._action = Action(action_json)
        actions_json = json.get("actions")
        self._actions = None
        if actions_json is not None:
            self._actions = []
            for action_json in actions_json:
                self._actions.append(Action(action_json))
        restrictions_json = json.get("restrictions")
        self._restrictions = None
        if restrictions_json is not None:
            self._restrictions = []
            for restriction_json in restrictions_json:
                self._restrictions.append(ExpressionPattern(restriction_json))
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
