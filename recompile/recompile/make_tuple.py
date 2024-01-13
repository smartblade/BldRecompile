from collections import namedtuple


def make_tuple(name, **kwargs):
    return namedtuple(name, kwargs.keys())(**kwargs)
