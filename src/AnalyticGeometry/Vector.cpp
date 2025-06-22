#include <AnalyticGeometry/Vector.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/ODataFile.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0040A375
* VC++ mangling:          ??D@YA?AVB_Vector@@NABV0@@Z
*/

B_Vector operator *(double c, const B_Vector &v)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040A3D1
* VC++ mangling:          ??DB_Vector@@QBE?AV0@N@Z
*/

B_Vector B_Vector::operator *(double c) const
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040A493
* VC++ mangling:          ??XB_Vector@@QAEAAV0@N@Z
*/

B_Vector &B_Vector::operator *=(double c)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040A567
* VC++ mangling:          ??HB_Vector@@QBE?AV0@ABV0@@Z
*/

B_Vector B_Vector::operator +(const B_Vector &that) const
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040A67C
* VC++ mangling:          ??ZB_Vector@@QAEABV0@ABV0@@Z
*/

const B_Vector &B_Vector::operator -=(const B_Vector &that)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040AA41
* VC++ mangling:          ?SetAngle@B_Vector@@QAEXN@Z
*/

void B_Vector::SetAngle(double angle)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040ACDD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Vector@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_Vector &vector)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040ACF4
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@AAVB_Vector@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_Vector &vector)
{
}
