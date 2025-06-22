#include "MessageManager.h"
#include "BBLibc.h"
#include "ObjDscr.h"

/*
* Module:                 BBLibc.dll
* Data address:           0x10048984
* VC++ mangling:          ?CheckErrors@@3HA
*/
int CheckErrors = 3;


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A590
* VC++ mangling:          ?OutputWin32Error@@YAXPBD@Z
*/

void OutputWin32Error(char const* message)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029BE0
* VC++ mangling:          ?vararg@@YAPBDPBDZZ
*/

const char* vararg(const char* format, ...)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002740
* VC++ mangling:          ?GetConfigDirectory@@YAPBDXZ
*/

const char* GetConfigDirectory()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100028EC
* VC++ mangling:          ?GetCurrentLanguage@@YAPBDXZ
*/

char const* GetCurrentLanguage()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020F2
* VC++ mangling:          ?RemoveOnOpenInputFileFunc@@YAXXZ
*/

void RemoveOnOpenInputFileFunc()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003E436
* VC++ mangling:          ?CallPythonObject@@YAPAUPyObject@@PAU1@0@Z
*/

PyObject * CallPythonObject(PyObject * func, PyObject * args)
{
}
