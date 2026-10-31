# Comparing BldMystery sources compiled with Visual C++ 6.0

`build.bat` compiles BBLibc sources of
[BldMystery](https://github.com/smartblade/BldMystery) with Visual C++ 6.0
and `compare_obj.py` compares compiled procedures with the original
`BBLibc.dll` byte by byte (using `src/BBLibc/asm/raw.txt` of BldMystery).
Bytes changed by the linker (addresses of called procedures and global
variables) are not compared.

Compared procedures:

| Address | Procedure | Characteristic code |
|---|---|---|
| `0x1000100F` | `B_IDataFile::GetnOpenedFiles` | trivial static method |
| `0x100018A6` | `B_IDataFile::Seek` | `switch`, inlined method |
| `0x10001A33` | `B_IDataFile::Read` | loop, `memcpy` |
| `0x10003337` | `B_Name::B_Name(const char *)` | constructor, `new`, `strlen` |
| `0x1002A590` | `OutputWin32Error` | WinAPI calls, `cdecl` |

## Usage

Requirements: Visual C++ 6.0 (`cl.exe` version 12.00), Python 3 and a
checkout of BldMystery.

```bat
"C:\Program Files\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"
vc6check\build.bat C:\path\to\BldMystery
```

Default compiler options are `/Zp4 /MD /Od /Ob1 /Gd /W3`, they can be
changed with `CFLAGS`, for example:

```bat
set CFLAGS=/Zp4 /MD /Od /Gd /W3
vc6check\build.bat C:\path\to\BldMystery
```

`COMPARE_FLAGS=--all` compares all exported procedures found in the
compiled object files, not only the procedures above.

Output for each procedure is `OK` or `MISMATCH` with differing rows of
bytes (`..` marks bytes changed by the linker). The format, as produced
for hand-made object files with `GetnOpenedFiles` (the second one with
changed code):

```
OK ?GetnOpenedFiles@B_IDataFile@@SAHXZ at 0x1000100F, 10 bytes, 4 relocated bytes not compared
MISMATCH ?GetnOpenedFiles@B_IDataFile@@SAHXZ at 0x1000100F, 10 bytes, 0 relocated bytes not compared
    +0000 compiled: 55 8B EC 33 C0 90 90 90 90 5D
    +0000 original: 55 8B EC A1 FC 9E 04 10 5D C3
```

The script exits with code 1 if a procedure does not match or is not found.
