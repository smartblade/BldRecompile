from exceptions import NextRunException
import expressions
from merge_types import merge_types


class ReturnInstruction:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Return({})".format(self._expression)

    @property
    def expression(self):
        return self._expression

    def transform_instruction(self, proc_decl, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        if isinstance(expression, expressions.Identifier):
            new_data_type = merge_types(
                proc_decl.return_type, expression.data_type
            )
            proc_decl.change_return_type(new_data_type)
        if (
            isinstance(expression, expressions.UnparsedToken) and
            expression.emit_code() == "<invalid>"
        ):
            proc_decl.change_return_type(None)
            raise NextRunException()
        return ReturnInstruction(expression)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self, writer):
        writer.write_line("return {};".format(self._expression.emit_code()))
