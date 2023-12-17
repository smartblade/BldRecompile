from collections import namedtuple

from assignment import Assignment
from code_instruction import CodeInstruction
import code_parser as parser
from for_instruction import ForInstruction
from if_instruction import IfInstruction
from return_instruction import ReturnInstruction
from variable_declaration import VariableDeclaration
from while_instruction import WhileInstruction

def parse_instructions(instructions, declared_identifiers):
    blocks_state = []
    state = _new_state(
        block_type=None,
        current_block=[],
        multiple_lines=True,
    )
    for instr_str in instructions:
        instr_str = instr_str.strip()
        if instr_str.startswith("if (") and instr_str.endswith(")"):
            clause = parser.parse_cpp_expression(
                instr_str[4:-1], declared_identifiers
            )
            state = _start_block(blocks_state, state, "if", clause)
        elif instr_str.startswith("else if (") and instr_str.endswith(")"):
            clause = parser.parse_cpp_expression(
                "'else if' is not implemented yet.", declared_identifiers
            )
            state = _start_block(blocks_state, state, "if", clause)
        elif instr_str == "else":
            state = _start_block(blocks_state, state, "else", None)
        elif instr_str.startswith("while (") and instr_str.endswith(")"):
            clause = parser.parse_cpp_expression(
                instr_str[7:-1], declared_identifiers
            )
            state = _start_block(blocks_state, state, "while", clause)
        elif instr_str.startswith("for (") and instr_str.endswith(")"):
            clause = parser.parse_cpp_expression(
                instr_str[5:-1], declared_identifiers
            )
            state = _start_block(blocks_state, state, "for", clause)
        elif instr_str == "{":
            state = _multiple_lines(state)
        elif instr_str == "}":
            state = _end_block(blocks_state, state)
        elif instr_str.endswith(";"):
            instr = _parse_instruction(instr_str[:-1], declared_identifiers)
            state.current_block.append(instr)
            if not state.multiple_lines:
                state = _end_block(blocks_state, state)
        else:
            raise Exception(
                "Not supported instruction type: '{}'.".format(instr_str)
            )
    return state.current_block

def _new_state(**kwargs):
    return namedtuple('State', kwargs.keys())(**kwargs)

def _multiple_lines(state):
    return _new_state(
        block_type=state.block_type,
        clause=state.clause,
        current_block=state.current_block,
        multiple_lines=True,
    )

def _start_block(blocks_state, state, new_block_type, clause):
    blocks_state.append(state)
    return _new_state(
        block_type=new_block_type,
        clause=clause,
        current_block=[],
        multiple_lines=False,
    )

def _end_block(blocks_state, state):
    prev_state = blocks_state.pop()
    if state.block_type == "if":
        prev_state.current_block.append(
            IfInstruction(state.clause, state.current_block)
        )
    elif state.block_type == "else":
        prev_state.current_block[-1].add_else_block(state.current_block)
    elif state.block_type == "while":
        prev_state.current_block.append(
            WhileInstruction(state.clause, state.current_block)
        )
    elif state.block_type == "for":
        prev_state.current_block.append(
            ForInstruction(state.clause, state.current_block)
        )
    return prev_state

def _parse_instruction(instr, declared_identifiers):
    tokens = parser.parse_cpp_expression(instr, declared_identifiers)
    return_expression = tokens.as_return()
    if return_expression is not None:
        return ReturnInstruction(return_expression)
    (dst, src) = tokens.as_assignment()
    if src is not None:
        identifier = dst.as_variable_declaration(declared_identifiers)
        if identifier is not None:
            return VariableDeclaration(identifier, src)
        return Assignment(dst, src)
    identifier = tokens.as_variable_declaration(declared_identifiers)
    if identifier is not None:
        return VariableDeclaration(identifier, None)
    return CodeInstruction(tokens)
