import expressions


def write_procedure_call(
    proc_decl, is_method, proc_name, callee, arguments
):
    operator = proc_decl.operator if proc_decl is not None else None
    if operator is not None and len(arguments) == 2:
        assert callee is None
        return "{} {} {}".format(
            arguments[0].emit_code(),
            operator.value,
            arguments[1].emit_code(),
        )
    if is_method:
        call = _method_access_code(arguments[0], proc_decl, callee, proc_name)
        arguments = arguments[1:]
    else:
        if proc_decl is not None and proc_decl.is_static:
            assert callee is None
            call = "{}::{}".format(
                proc_decl.method_class.class_name, proc_name)
        else:
            call = _callee_code(callee, proc_name)
    return "{}({})".format(
        call, ", ".join(map(lambda a: a.emit_code(), arguments))
    )


def _is_obj_initialization(obj, proc_decl):
    if proc_decl is None:
        return False
    if not proc_decl.is_constructor:
        return False
    if not isinstance(obj, expressions.AddressOf):
        return False
    identifier = obj.expression
    if not isinstance(identifier, expressions.Identifier):
        return False
    return identifier.is_implicit


def _method_access_code(obj, proc_decl, callee, proc_name):
    if callee is not None:
        method_code = "({})".format(callee.emit_code())
    else:
        method_code = proc_name
    if _is_obj_initialization(obj, proc_decl):
        return method_code
    return expressions.FieldAccess(obj, method_code).emit_code()


def _callee_code(callee, proc_name):
    if callee is not None:
        return callee.emit_code()
    return proc_name
