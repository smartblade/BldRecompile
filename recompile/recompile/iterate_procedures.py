from procedure_state import ProcedureState
import queue


_skipping_procedures_again = {"00405AA2", "00405BA9"}


def iterate_procedures(proc_dict, files):
    recompiled_decls = {}
    processed_procs = set()
    proc_queue = queue.PriorityQueue()
    proc_states = {}
    for addr in proc_dict.keys():
        proc_states[addr] = ProcedureState(
            addr, files.for_procedure(addr), proc_states, recompiled_decls,
            processed_procs
        )
        proc_queue.put(addr)
    while True:
        proc_state = proc_states[proc_queue.get()]
        processed_procs.add(proc_state.address)
        yield proc_state
        _add_caller_to_queue(
            proc_state, proc_states, proc_queue, recompiled_decls
        )


def _add_caller_to_queue(proc_state, proc_states, proc_queue, recompiled_decls):
    if not proc_state.callers:
        return
    for caller in sorted(proc_state.callers):
        if _are_all_callees_recompiled(proc_states[caller], recompiled_decls):
            if caller in _skipping_procedures_again:
                print("Skipping {} procedure again...".format(caller))
                continue
            proc_queue.put(caller)


def _are_all_callees_recompiled(proc_state, recompiled_decls):
    for callee in proc_state.callees:
        if callee not in recompiled_decls:
            return False
    return True
