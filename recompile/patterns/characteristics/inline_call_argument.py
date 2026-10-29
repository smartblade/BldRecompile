class InlineCallArgument:
    def __init__(self, json_dict):
        self._json_dict = json_dict

    @property
    def name(self):
        return self._json_dict["name"]

    @property
    def offset(self):
        return int(self._json_dict["offset"])

    @property
    def size(self):
        return int(self._json_dict["size"])
