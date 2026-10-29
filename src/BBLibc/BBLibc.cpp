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
* Data address:           0x1004A00C
*/
static char configDirectory[260];

/*
* Module:                 BBLibc.dll
* Data address:           0x1004A110
*/
static byte isConfigDirectorySet;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029BE0
* VC++ mangling:          ?vararg@@YAPBDPBDZZ
*/

const char* vararg(const char* format, ...)
{
}
