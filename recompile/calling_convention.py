from enum import auto, Enum

class CallingConvention(Enum):
    THISCALL = auto()
    STDCALL = auto()
    CDECL = auto()
