class ProcedureState:
    def __init__(
            self, addr, files, proc_states, recompiled_decls, processed_procs
    ):
        self._addr = addr
        self._files = files
        self._callees = set()
        self._callers = set()
        self._proc_states = proc_states
        self._recompiled_decls = recompiled_decls
        self._processed_procs = processed_procs

    @property
    def address(self):
        return self._addr

    @property
    def files(self):
        return self._files

    @property
    def recompiled_decls(self):
        return self._recompiled_decls

    @property
    def callees(self):
        return self._callees

    @callees.setter
    def callees(self, callees):
        if self._callees:
            if callees != self._callees:
                raise Exception(
                    "Can't change callees of procedure state "
                    "from {} to {}".format(self._callees, callees)
                )
            return
        self._callees = frozenset(callees)
        for callee in callees:
            self._proc_states[callee].callers.add(self.address)

    @property
    def callers(self):
        return self._callers

    def print_status(self):
        print(
            "{} procedures was recompiled, {} was skipped.".format(
                len(self._recompiled_decls),
                len(self._processed_procs - self._recompiled_decls.keys())
            )
        )
