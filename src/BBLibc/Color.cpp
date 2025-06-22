#include "Color.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100068D0
* VC++ mangling:          ??HB_Color@@QBE?AV0@ABV0@@Z
*/

B_Color B_Color::operator +(B_Color const& color) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006950
* VC++ mangling:          ??DB_Color@@QBE?AV0@M@Z
*/

B_Color B_Color::operator *(float coef) const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100069E0
* VC++ mangling:          ??KB_Color@@QBE?AV0@M@Z
*/

B_Color B_Color::operator /(float f)const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100091A4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Color@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Color& color)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100091DF
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_Color@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_Color const& color)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000921A
* VC++ mangling:          ?MakeCons@B_Color@@UAEXXZ
*/

void B_Color::MakeCons()
{
}
