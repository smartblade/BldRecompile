#include "ODataFile.h"
#include "Color.h"
#include "Name.h"
#include "NamedObj.h"
#include "BitMap.h"
#include "BitMap24.h"
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C44
* VC++ mangling:          ??0B_ODataFile@@QAE@PBDH@Z
*/

B_ODataFile::B_ODataFile(const char* file_name, int flags)
    : fd(-1), file_name(nullptr)
{
}
