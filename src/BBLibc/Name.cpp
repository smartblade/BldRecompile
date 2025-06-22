#include "Name.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003300
* VC++ mangling:          ??0B_Name@@QAE@XZ
*/

B_Name::B_Name() : string(new char[1]), len(0)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003337
* VC++ mangling:          ??0B_Name@@QAE@PBD@Z
*/

B_Name::B_Name(const char* str)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100033A4
* VC++ mangling:          ??0B_Name@@QAE@ABV0@@Z
*/

B_Name::B_Name(const B_Name& src) : len(src.len)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003410
* VC++ mangling:          ??0B_Name@@QAE@I@Z
*/

B_Name::B_Name(unsigned int len) : len(len)
{
}


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
* Entry point:            0x10003467
* VC++ mangling:          ??OB_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator >(const B_Name& rhs) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100034DA
* VC++ mangling:          ??MB_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator <(const B_Name& rhs) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000354D
* VC++ mangling:          ??8B_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator ==(const B_Name& rhs) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100035D2
* VC++ mangling:          ??8B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::operator ==(const char* str) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003643
* VC++ mangling:          ??9B_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator !=(const B_Name& rhs) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100036C5
* VC++ mangling:          ??9B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::operator !=(const char* str) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003769
* VC++ mangling:          ?CompareNoCase@B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::CompareNoCase(const char* str) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000378E
* VC++ mangling:          ??4B_Name@@QAEAAV0@ABV0@@Z
*/

B_Name& B_Name::operator =(const B_Name& src)
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
* Entry point:            0x10003904
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Name@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Name& name)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000398A
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Name@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_Name const& name)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100039BA
* VC++ mangling:          ??1B_Name@@QAE@XZ
*/

B_Name::~B_Name()
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


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003C70
* VC++ mangling:          ??YB_Name@@QAEABV0@PBD@Z
*/

B_Name const& B_Name::operator +=(const char* str)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003D30
* VC++ mangling:          ??YB_Name@@QAEABV0@D@Z
*/

const B_Name& B_Name::operator+=(char c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003DCE
* VC++ mangling:          ??YB_Name@@QAEABV0@ABV0@@Z
*/

B_Name const& B_Name::operator +=(const B_Name& other)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003E91
* VC++ mangling:          ?UpCase@B_Name@@QAEXXZ
*/

void B_Name::UpCase()
{
}
