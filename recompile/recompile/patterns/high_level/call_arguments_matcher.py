import expressions
from calling_convention import CallingConvention
from patterns.make_proc_decl_from_args import make_proc_decl_from_args
from procedure_declaration import ProcedureDeclaration


class CallArgumentsMatcher:
    def __init__(self):
        self._msg_by_unmatched_args = {}

    def match_args(self, pc, proc_decl):
        pc = self._push_unmatched_arguments(pc)
        if proc_decl is None:
            return pc
        if pc.proc_decl.convention == CallingConvention.CDECL:
            return pc
        if pc.proc_decl.stack_delta <= proc_decl.stack_delta:
            return pc
        if pc.proc_decl.convention != proc_decl.convention:
            raise Exception(
                "Calling convention expected to be "
                "{} for {} but was: {}.".format(
                    pc.proc_decl.convention,
                    proc_decl.proc_name,
                    proc_decl.convention,
                )
            )
        message = "Stack delta expected to be {} for {} but was: {}.".format(
            pc.proc_decl.stack_delta,
            proc_decl.proc_name,
            proc_decl.stack_delta,
        )
        new_pc_proc_decl = pc.proc_decl
        new_arguments = pc.arguments
        unmatched_args = []
        while new_pc_proc_decl.stack_delta > proc_decl.stack_delta:
            unmatched_args.append(new_arguments[-1])
            new_arguments = new_arguments[:-1]
            parameters = [
                (param_name, param_type)
                for param_name, param_type
                in new_pc_proc_decl.get_parameters_ids().items()
            ]
            parameters.pop()
            if new_pc_proc_decl.is_instance_method:
                parameters = parameters[1:]
            new_pc_proc_decl = ProcedureDeclaration(
                new_pc_proc_decl.proc_name, new_pc_proc_decl.convention,
                new_pc_proc_decl.method_class, parameters,
                new_pc_proc_decl.return_type, new_pc_proc_decl.is_static,
                new_pc_proc_decl.is_vararg)
        if new_pc_proc_decl.stack_delta != proc_decl.stack_delta:
            return pc
        unmatched_args = tuple(unmatched_args)
        self._msg_by_unmatched_args[unmatched_args] = message
        pc = pc.copy(arguments=new_arguments, proc_decl=new_pc_proc_decl)
        return _CallWithUnmatchedArgs(pc, unmatched_args)

    def _push_unmatched_arguments(self, pc):
        if not self._msg_by_unmatched_args:
            return pc
        for arg in pc.arguments:
            arg_call = self._find_call(arg)
            if arg_call is not None:
                pc = self._push_unmatched_arguments_from(pc, arg_call)
                break
        self.expect_all_args_are_matched()
        return pc

    def _push_unmatched_arguments_from(self, pc, arg_call):
        new_arguments = list(pc.arguments)
        for arg in reversed(arg_call.unmatched_args):
            new_arguments.append(arg)
        proc_decl = make_proc_decl_from_args(
            new_arguments, is_method=pc.is_method)
        proc_decl.change_return_type(proc_decl.return_type)
        del self._msg_by_unmatched_args[arg_call.unmatched_args]
        return pc.copy(arguments=new_arguments, proc_decl=proc_decl)

    def _find_call(self, e):
        if isinstance(e, expressions.Bin):
            return self._find_call(e.left)
        if not isinstance(e, _CallWithUnmatchedArgs):
            return None
        return e

    def expect_all_args_are_matched(self):
        if self._msg_by_unmatched_args:
            raise Exception(next(iter(self._msg_by_unmatched_args.values())))


class _CallWrapper:
    def __init__(self, pc, unmatched_args):
        self.__call = pc
        self.__unmatched_args = unmatched_args

    @property
    def unmatched_args(self):
        return self.__unmatched_args

    def __getattr__(self, attr_name):
        return getattr(self.__call, attr_name)

    def copy(self, **kwargs):
        return self.__class__(self.__call.copy(**kwargs), self.__unmatched_args)


class _CallWithUnmatchedArgs(_CallWrapper, expressions.ProcedureCall):
    pass
