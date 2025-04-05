from .operand import Operand


def make_operand(operand, operand_sets):
    if operand in operand_sets:
        return operand_sets[operand]
    return Operand(operand)

