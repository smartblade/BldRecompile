import patterns.characteristics as characteristics


class Constants:
    def __init__(self, json_dict):
        self._constants = {}
        for str_value, constant_dict in json_dict.items():
            self._constants[int(str_value)] = characteristics.Constant(
                constant_dict)

    def by_value(self, value):
        return self._constants.get(value)
