import patterns.characteristics as characteristics


class Parameters:
    def __init__(self, json_list):
        self._parameters = []
        for param_dict in json_list:
            index = int(param_dict["index"])
            if index > len(self._parameters):
                for i in range(index - len(self._parameters)):
                    self._parameters.append(characteristics.Parameter({}))
            self._parameters.append(characteristics.Parameter(param_dict))

    def __getitem__(self, index):
        if index < len(self._parameters):
            return self._parameters[index]
        return characteristics.Parameter({})
