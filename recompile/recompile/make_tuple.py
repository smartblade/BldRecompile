from collections import namedtuple


def make_tuple(name, **kwargs):
    return namedtuple(name, kwargs.keys())(**kwargs)


def add_attributes(obj, **kwargs):
    values = dict(**obj._asdict(), **kwargs)
    return namedtuple(obj.__class__.__name__, values.keys())(**values)
