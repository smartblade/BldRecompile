import patterns.characteristics as characteristics


class Return(characteristics.Identifier):
    def __init__(self, json_dict):
        super().__init__(json_dict)
        self._json_dict = json_dict

    @property
    def is_boolean(self):
        return self._json_dict.get("boolean") == "yes"
