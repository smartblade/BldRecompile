import expressions

from .call_characteristics import get_call_characteristics


def get_expression_characteristics(e, **kwargs):
    cb = _cb_by_expression_type.get(type(e))
    if cb is None:
        return None
    return cb(e, **kwargs)


def _get_deref_characteristics(deref, **kwargs):
    characteristics = get_expression_characteristics(deref.expression, **kwargs)
    if characteristics is None:
        return None
    return characteristics.pointee


def _get_id_characteristics(identifier, procedure, characteristics, **kwargs):
    if procedure.proc_decl is None:
        return None
    parameters = list(
        procedure.proc_decl.get_parameters_ids().values())
    parameter_index = None
    for i, parameter in enumerate(parameters):
        if identifier.name == parameter.name:
            parameter_index = i
            break
    if parameter_index is None:
        return None
    return characteristics.parameters[parameter_index]


def _get_call_characteristics(pc, declarations, **kwargs):
    call_characteristics = get_call_characteristics(declarations, pc)
    return call_characteristics.ret


_cb_by_expression_type = {
    expressions.Dereference: _get_deref_characteristics,
    expressions.Identifier: _get_id_characteristics,
    expressions.ProcedureCall: _get_call_characteristics,
}
