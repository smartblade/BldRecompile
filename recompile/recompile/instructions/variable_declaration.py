import re

import data_types
import expressions

loc_var_regexp = re.compile('^((?P<prefix>dw|r|t)Loc(?P<offset>[\dABCDEF]{2}))|(?P<reg>eax|ecx|edx)|(?P<fpu>rLoc1)|(?P<seq>rSeq\w+)_\d+')


class VariableDeclaration:
    def __init__(self, identifier, initial_expression):
        self._id = identifier
        self._initial_expression = initial_expression

    def __repr__(self):
        return "Decl({} {}={})".format(
            self._id.data_type, self._id.name, self._initial_expression
        )

    @property
    def id(self):
        return self._id

    @property
    def initial_expression(self):
        return self._initial_expression

    def transform_instruction(self, **kwargs):
        declared_identifiers = kwargs['declared_identifiers']
        id_suffixes = kwargs['id_suffixes']
        if self._initial_expression is not None:
            initial_expression = self._initial_expression.transform_expression(
                **kwargs
            )
        else:
            initial_expression = None
        var_type = self._id.data_type
        var_name = self._id.name
        new_var_name = self._define_variable_name(var_type, var_name)
        self._id.rename(new_var_name)
        self._ensure_unique_id(self._id, id_suffixes)
        if initial_expression is not None:
            first, second = _as_seq(initial_expression)
            if first is not None:
                seq_id_name = "rSeq_{}_{}".format(
                    first.emit_code(), second.emit_code()
                )
                declared_identifiers[seq_id_name].rename(self._id.name)
                identifier = declared_identifiers[seq_id_name]
                declared_identifiers[var_name] = identifier
                return None
        declared_identifiers[var_name] = self._id
        return VariableDeclaration(self._id, initial_expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        if self._initial_expression is not None:
            self._initial_expression.visit(on_expression_visited, **kwargs)

    def emit_code(self, writer):
        type_name = self._id.data_type.get_type_name(is_metafile=False)
        sep = "" if type_name.endswith("*") else " "
        initial_expression = ""
        if self._initial_expression is not None:
            initial_expression = " = " + self._initial_expression.emit_code()
        writer.write_line("{}{}{}{};".format(
                type_name, sep, self._id.name, initial_expression
            )
        )

    def _define_variable_name(self, var_type, var_name):
        match = re.search(loc_var_regexp, var_name)
        if match:
            offset = match.group('offset')
            if offset is not None:
                prefix = match.group('prefix')
                if prefix == "dw" and isinstance(var_type, data_types.Unknown32):
                    return "unknown_loc_{}".format(offset)
                if prefix == "dw" and isinstance(var_type, data_types.Int32):
                    return "unknown_int_loc_{}".format(offset)
                if prefix == "r":
                    if isinstance(var_type, data_types.Double):
                        return "unknown_double_loc_{}".format(offset)
                    if isinstance(var_type, data_types.Float):
                        return "unknown_float_loc_{}".format(offset)
                if prefix == "t":
                    return "unknown_struct_loc_{}".format(offset)
            reg = match.group('reg')
            if reg is not None and isinstance(var_type, data_types.Unknown32):
                return "unknown_{}".format(reg)
            if match.group('fpu') is not None:
                if isinstance(var_type, data_types.Double):
                    return "unknown_fpu"
            if match.group('seq') is not None:
                return var_name
        raise Exception("Unparsed variable name: {}.".format(var_name))

    def _ensure_unique_id(self, identifier, id_suffixes):
        if not identifier.name in id_suffixes:
            id_suffixes[identifier.name] = identifier
        else:
            if isinstance(id_suffixes[identifier.name], expressions.Identifier):
                self._add_suffix_to_id(
                    id_suffixes[identifier.name], 1, id_suffixes
                )
            self._add_suffix_to_id(
                identifier, id_suffixes[identifier.name] + 1, id_suffixes
            )

    def _add_suffix_to_id(self, identifier, suffix, id_suffixes):
        name = identifier.name
        identifier.rename("{}_{}".format(name, suffix))
        id_suffixes[name] = suffix


def _as_seq(e):
    if not isinstance(e, expressions.ProcedureCall):
        return None, None
    if e.name != "SEQ":
        return None, None
    return e.arguments
