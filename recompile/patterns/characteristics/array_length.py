class ArrayLength:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    @property
    def parameter(self):
        parameter = self._json_dict.get("parameter")
        if parameter is None:
            return None
        return int(parameter)

