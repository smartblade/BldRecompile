def ensure_class_name(c, default_name):
    if not c.class_name or c.class_name.startswith("Eq_"):
        return c.rename(default_name)
    return c
