from enum import Enum


class CallingConvention(Enum):
    THISCALL = "__thiscall"
    STDCALL = "__stdcall"
    CDECL = "__cdecl"
    FASTCALL = "__fastcall"


calling_conventions = dict(
    (o.value, o) for o in CallingConvention
)
