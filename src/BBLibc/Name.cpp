#include "Name.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003457
* VC++ mangling:          ?String@B_Name@@QBEQADXZ
*/

char* const B_Name::String() const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003821
* VC++ mangling:          ?Right@B_Name@@QBE?AV1@I@Z
*/

B_Name B_Name::Right(unsigned int count) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003898
* VC++ mangling:          ?Left@B_Name@@QBE?AV1@I@Z
*/

B_Name B_Name::Left(unsigned int count) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A70
* VC++ mangling:          ??H@YA?AVB_Name@@ABV0@0@Z
*/

B_Name operator +(B_Name const& lother, B_Name const& rother)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003B1E
* VC++ mangling:          ??H@YA?AVB_Name@@ABV0@PBD@Z
*/

B_Name operator +(B_Name const& other, char const* str)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003BC7
* VC++ mangling:          ??H@YA?AVB_Name@@PBDABV0@@Z
*/

B_Name operator +(const char* str, const B_Name& bName)
{
}
