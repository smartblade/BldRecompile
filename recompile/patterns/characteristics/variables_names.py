class VariablesNames:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    def get(self, offset):
        return self._json_dict.get(str(offset))
