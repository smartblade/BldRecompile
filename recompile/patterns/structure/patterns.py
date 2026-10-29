from .prefix_builder import PrefixBuilder
from .instructions_pattern import InstructionsPattern
from .read_operand_patterns import read_operand_patterns


class Patterns:
    def __init__(self, json):
        cmd_code_dict, most_frequent_cmd_code = _make_cmd_code_dict(json)
        self._cmd_code_dict = cmd_code_dict
        self._most_frequent_cmd_code = most_frequent_cmd_code
        self._read_json(json)
        self._build_patterns_by_prefix()

    def _read_json(self, json):
        operand_sets = read_operand_patterns(json["operand-patterns"])
        self._instructions_patterns = []
        for instructions_pattern in json["instructions-patterns"]:
            self._instructions_patterns.append(
                InstructionsPattern(
                    instructions_pattern, operand_sets, self._cmd_code_dict))

    def _build_patterns_by_prefix(self):
        prefix_builder = self.make_prefix_builder()
        self._patterns_by_prefix = []
        for prefix in range(prefix_builder.max_prefix):
            self._patterns_by_prefix.append([])
        for pattern_index in range(len(self._instructions_patterns)):
            instructions_pattern = self._instructions_patterns[pattern_index]
            prefix_builder = self.make_prefix_builder()
            for instruction in instructions_pattern.instructions:
                if not prefix_builder.add_command_code(
                    instruction.command_code
                ):
                    break
            for prefix in prefix_builder.all_prefixes:
                self._patterns_by_prefix[prefix].append(pattern_index)

    @property
    def commands_code_dict(self):
        return self._cmd_code_dict

    def instructions_patterns_by_prefix(self, prefix):
        for index in self._patterns_by_prefix[prefix]:
            yield self._instructions_patterns[index]

    def make_prefix_builder(self):
        return PrefixBuilder(self._most_frequent_cmd_code)


def _make_cmd_code_dict(json):
    cmd_count_dict = {}
    cmd_code_dict = {}
    index = 1
    for instructions_pattern in json["instructions-patterns"]:
        instructions = instructions_pattern["instructions"]
        for instr_pattern in instructions:
            cmd = next(iter(instr_pattern.keys()))
            cmd_count_dict[cmd] = cmd_count_dict.get(cmd, 0) + 1
            if cmd not in cmd_code_dict:
                cmd_code_dict[cmd] = index
                index += 1
    cmd_count_dict = sorted(
        cmd_count_dict.items(), key=lambda item: item[1], reverse=True)
    most_frequent_cmd, count = next(iter(cmd_count_dict))
    return cmd_code_dict, cmd_code_dict[most_frequent_cmd]
