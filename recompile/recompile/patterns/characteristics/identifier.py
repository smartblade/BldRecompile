class Identifier:
    def __init__(self, json_dict):
        self._json_dict = json_dict
        self._pointee = None
        pointee_dict = self._json_dict.get("pointee")
        if pointee_dict is not None:
            self._pointee = Identifier(pointee_dict)

    @property
    def constant_set(self):
        return self._json_dict.get("constantset", None)

    @property
    def pointee(self):
        return self._pointee
