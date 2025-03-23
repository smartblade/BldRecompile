from enum import Enum


class Operator(Enum):
    PRE_INC = '++'
    NEG = '-'
    ADDR_OF = "&"
    DEREF = "*"
    ADD = "+"
    SUB = "-"
    MUL = "*"
    DIV = "/"
    MOD = "%"
    SHL = "<<"
    SHR = ">>"
    LT = "<"
    GT = ">"
    LE = "<="
    GE = ">="
    EQ = "=="
    NE = "!="
    BIT_AND = "&"
    XOR = "^"
    BIT_OR = "|"
    AND = "&&"
    COND = "?"
    COND_SEP = ":"
    ASS = "="
    ADD_ASS = "+="
    DIV_ASS = "/="


# C++ operand priorities:
# https://learn.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-170
priorities = {
    Operator.PRE_INC: 3,
    Operator.NEG: 3,
    Operator.ADDR_OF: 3,
    Operator.DEREF: 3,
    Operator.MUL: 5,
    Operator.DIV: 5,
    Operator.MOD: 5,
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
    Operator.BIT_AND: 10,
    Operator.XOR: 11,
    Operator.BIT_OR: 12,
    Operator.AND: 13,
    Operator.COND: 15,
    Operator.COND_SEP: 15,
    Operator.ASS: 15,
    Operator.ADD_ASS: 15,
    Operator.DIV_ASS: 15,
}

logical = {
    Operator.LT,
    Operator.GT,
    Operator.LE,
    Operator.GE,
    Operator.EQ,
    Operator.NE,
    Operator.AND,
}

is_associative = {
    Operator.MUL: True,
    Operator.DIV: False,
    Operator.ADD: True,
    Operator.SUB: False,
}

operators = dict(
    (o.value, o) for o in Operator
)
