class Parameter:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    @property
    def constant_set(self):
        return self._json_dict.get("constantset", None)
