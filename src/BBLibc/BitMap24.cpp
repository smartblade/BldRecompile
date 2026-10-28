#include "BitMap24.h"
#include "ODataFile.h"

/*
* Module:                 BBLibc.dll
* Data address:           0x1004A520
* VC++ mangling:          ?BitMap24DataList@B_BitMap24@@0V?$B_Array@VB_BitMap24@@@@A
*/
B_Array<B_BitMap24> B_BitMap24::BitMap24DataList(1);


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006CB0
* VC++ mangling:          ??0B_BitMap24@@QAE@HH@Z
*/

B_BitMap24::B_BitMap24(int width, int height)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006E70
* VC++ mangling:          ??1B_BitMap24@@UAE@XZ
*/

B_BitMap24::~B_BitMap24()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10026AD5
* VC++ mangling:          ??0B_BitMap24@@QAE@ABV0@@Z
*/

B_BitMap24::B_BitMap24(const B_BitMap24& that)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10026C70
* VC++ mangling:          ?ClearBitMap24Data@B_BitMap24@@SAXXZ
*/

void B_BitMap24::ClearBitMap24Data()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100271BE
* VC++ mangling:          ??4B_BitMap24@@QAEAAV0@ABV0@@Z
*/

B_BitMap24& B_BitMap24::operator=(const B_BitMap24& that)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100272A5
* VC++ mangling:          ?SetBits@B_BitMap24@@QAEIHHPBD0@Z
*/

unsigned int B_BitMap24::SetBits(int, int, char const*, char const*)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10027382
* VC++ mangling:          ?SaveToBMP@B_BitMap24@@QBEHPBD@Z
*/

int B_BitMap24::SaveToBMP(char const* fileName) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002778F
* VC++ mangling:          ?SaveToBMPSized@B_BitMap24@@QBEHPBDHH@Z
*/

int B_BitMap24::SaveToBMPSized(char const* fileName, int width, int height) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10027F15
* VC++ mangling:          ?SaveToFile@B_BitMap24@@QBEHPBDH@Z
*/

int B_BitMap24::SaveToFile(char const*, int) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10028021
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_BitMap24@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_BitMap24& bitMap)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100280CC
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_BitMap24@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_BitMap24 const& bitMap)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10028353
* VC++ mangling:          ?EscribeArchivoRAW@B_BitMap24@@QBEXPBD@Z
*/

void B_BitMap24::EscribeArchivoRAW(char const*) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029700
* VC++ mangling:          ?SaveToJPEG@B_BitMap24@@QBEHPBDH@Z
*/

int B_BitMap24::SaveToJPEG(char const*, int) const
{
}
