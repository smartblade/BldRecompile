class PopFpu:
    def transform(self, transformer, **kwargs):
        e = transformer.transform_pop_fpu(**kwargs)
        if e is not None:
            return e
        return self
