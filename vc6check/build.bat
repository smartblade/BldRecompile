@echo off
rem Compile BBLibc sources of BldMystery with Visual C++ 6.0 and compare
rem procedures with the original BBLibc.dll.
rem
rem Usage: build.bat <path to BldMystery>
rem
rem Run it in a command prompt with VC6 environment (VCVARS32.BAT).
rem Compiler options can be changed with CFLAGS environment variable.

setlocal
if "%~1"=="" (
    echo Usage: build.bat ^<path to BldMystery^>
    exit /b 1
)
set BLD=%~1
set OUT=%~dp0out
if not exist "%OUT%" mkdir "%OUT%"

if "%CFLAGS%"=="" set CFLAGS=/Zp4 /MD /Od /Ob1 /Gd /W3
set INCLUDES=/I "%BLD%\src" /I "%BLD%\src\include" /I "%BLD%\src\Python-1.5.2\Include"
set DEFINES=/D WIN32 /D NDEBUG /D _WINDOWS /D _USRDLL /D BUILD_LIB /D BLD_NATIVE

cl 2>&1 | findstr /C:"Version 12.00" >nul
if errorlevel 1 (
    echo cl.exe is not Visual C++ 6.0 compiler:
    cl 2>&1 | findstr /C:"Version"
    exit /b 1
)

for %%f in (IDataFile Name BBLibc) do (
    cl /nologo /c %CFLAGS% %INCLUDES% %DEFINES% /Fo"%OUT%\%%f.obj" "%BLD%\src\BBLibc\%%f.cpp"
    if errorlevel 1 exit /b 1
)

python "%~dp0compare_obj.py" --raw "%BLD%\src\BBLibc\asm\raw.txt" %COMPARE_FLAGS% "%OUT%\IDataFile.obj" "%OUT%\Name.obj" "%OUT%\BBLibc.obj"
