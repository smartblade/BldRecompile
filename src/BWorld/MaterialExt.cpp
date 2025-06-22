#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0044E9A0
*/

int nMaterials()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044E9AA
*/

material_t *CreateMaterial(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044EB5A
*/

material_t *GetMaterial(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044EBD3
*/

material_t *GetMaterialI(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044EC02
*/

int SetMaterialSoundProperty(
    material_t *material, int property_kind, int index, B_Sound *sound
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044EC62
*/

int GetMaterialSoundProperty(
        material_t *material, int property_kind, int index, B_Sound **sound
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044ECC5
*/

int GetMaterialStringProperty(
        material_t *material, int property_kind, int index, const char **value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044ECF8
*/

int SetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044ED29
*/

int GetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044ED6A
*/

int AddHitSoundComb(
    material_t *material1, material_t *material2, B_Sound *sound
)
{
}
