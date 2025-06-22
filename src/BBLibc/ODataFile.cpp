#include "ODataFile.h"
#include "Color.h"
#include "Name.h"
#include "NamedObj.h"
#include "BitMap.h"
#include "BitMap24.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C44
* VC++ mangling:          ??0B_ODataFile@@QAE@PBDH@Z
*/

B_ODataFile::B_ODataFile(const char* file_name, int flags)
    : fd(-1), file_name(nullptr)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001E86
* VC++ mangling:          ?Write@B_ODataFile@@QAEXPBXI@Z
*/

void B_ODataFile::Write(const void* data, unsigned int size)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F5E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABD@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, char const& c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F74
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@PBD@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, char const* c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001F9A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABE@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned char const& c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FB0
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABF@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, short const& s)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FC6
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABG@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, const unsigned short& s)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FDC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABH@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, int const& i)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001FF2
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABJ@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, long const& l)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002008
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABK@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned long const& l)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000201E
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABI@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, unsigned int const& i)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002034
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABM@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, float const& f)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000204A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABN@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, double const& f)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002082
* VC++ mangling:          ??1B_ODataFile@@QAE@XZ
*/

B_ODataFile::~B_ODataFile()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002250
* VC++ mangling:          ?OK@B_ODataFile@@QBEIXZ
*/

unsigned int B_ODataFile::OK() const
{
}
