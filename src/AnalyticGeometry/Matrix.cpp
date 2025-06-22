#include <AnalyticGeometry/Matrix.h>
#include <AnalyticGeometry/Vector.h>


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10003430
* Module:                 Blade.exe
* Entry point:            0x00404BE0
* VC++ mangling:          ??0B_Matrix@@QAE@XZ
*/

B_Matrix::B_Matrix()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1000377F
* Module:                 Blade.exe
* Entry point:            0x00404F2F
* VC++ mangling:          ??0B_Matrix@@QAE@ABVB_Vector@@@Z
*/

B_Matrix::B_Matrix(const B_Vector &v)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10003F6F
* Module:                 Blade.exe
* Entry point:            0x0040571F
* VC++ mangling:          ?TranslationVector@B_Matrix@@QBE?AVB_Vector@@XZ
*/

B_Vector B_Matrix::TranslationVector() const
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x406903
* VC++ mangling:          ??D@YA?AVB_Vector@@ABV0@ABVB_Matrix@@@Z
*/

B_Vector operator *(const B_Vector& vector, const B_Matrix &matrix)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00406AF1
* VC++ mangling:          ?Rotate@@YA?AVB_Vector@@ABV1@ABVB_Matrix@@@Z
*/

B_Vector Rotate(const B_Vector &v, const B_Matrix &rotateMatrix)
{
}
