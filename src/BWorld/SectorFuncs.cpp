#include <BWorld/SectorFuncs.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0045C040
*/

int GetSectorByPosition(double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C080
*/

int GetSectorByIndex(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C0A3
*/

// TODO fix prototype
void GetNumberOfSectors()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C0AD
*/

int InitBreakSector(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C159
*/

int DoBreakSector(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C1F5
*/

int GetSectorIntProperty(
        int sectorID, int property_kind, int index, int *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C34D
*/

int SetSectorIntProperty(
        int sectorID, int property_kind, int index, int value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C415
*/

int GetSectorFloatProperty(
        int sectorID, int property_kind, int index, double *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C5A6
*/

int SetSectorFloatProperty(
        int sectorID, int property_kind, int index, double value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C735
*/

int GetSectorStringProperty(
        int sectorID, int property_kind, int index, const char **value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C8B0
*/

int SetSectorStringProperty(
        int sectorID, int property_kind, int index, const char *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045C9A0
*/

int SetSectorVectorProperty(
        int sectorID, int property_kind, int index, double x,
        double y, double z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045CA86
*/

int GetSectorVectorProperty(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045CB7C
*/

int SetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045CCD8
*/

int GetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject **value
)
{
}
