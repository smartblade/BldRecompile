from enum import Enum


class Operator(Enum):
    ADD = "+"
    SUB = "-"
    MUL = "*"
    DIV = "/"
    SHL = "<<"
    SHR = ">>"
    LT = "<"
    GT = ">"
    LE = "<="
    GE = ">="
    EQ = "=="
    NE = "!="
    AND = "&&"
    ASS = "="
    DIV_ASS = "/="


# C++ operand priorities:
# https://learn.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-170
priorities = {
    Operator.MUL: 5,
    Operator.DIV: 5,
    Operator.ADD: 6,
    Operator.SUB: 6,
    Operator.SHL: 7,
    Operator.SHR: 7,
    Operator.LT: 8,
    Operator.GT: 8,
    Operator.LE: 8,
    Operator.GE: 8,
    Operator.EQ: 9,
    Operator.NE: 9,
    Operator.AND: 13,
    Operator.ASS: 15,
    Operator.DIV_ASS: 15,
}

operators = dict(
    (o.value, o) for o in Operator
)
