#include <bld_python.h>
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00491B70
*/

int AddStepSound(const char *name, B_Sound *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00491E7C
*/

int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0049259A
*/

int AddTextureMaterial(const char *texture, const char *material)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004929C4
*/

int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005856A0
*/

int GetCharByName(const char *name, const char *short_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585715
*/

int LoadAllAnimations(int charID)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585758
*/

int ChangeAnimation(
        int charID, const char *old_anm_name, const char *new_anm_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585789
*/

int SetAnmDefaultPrefix(int charID, const char *prefix)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005857C3
*/

int AddAttack(int charID, const char *attack_name, const char *anm_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585807
*/

int AttackWindow(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585853
*/

int AttackLevels(
        int charID, const char *anm_name, float level1, float level2
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0058589B
*/

int AttackEnergyLevel(
        int charID, const char *anm_name, float  level
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005858DF
*/

// TODO fix prototype
void ForwardsOffset()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585923
*/

int AttackTypeFlag(int charID, const char *attack_name, int flag)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585967
*/

int AllowAttack(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005859BB
*/

int MetaAttack(
        int charID, const char *meta_attack_name, const char *attack_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005859FF
*/

int AssignTrail(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585A47
*/

int SetNCDSpheres(int charID, int NCDSpheres)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585C53
*/

int SetCDSphere(int charID, int index, double h, double r)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585CE3
*/

int GetCharIntProperty(int charID, int property_kind, int index, int *value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585D4E
*/

int SetCharIntProperty(int charID, int property_kind, int index, int value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00585DB4
*/

int GetCharFloatProperty(int charID, int property_kind, int index, double *value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0058616F
*/

int SetCharFloatProperty(int charID, int property_kind, int index, double value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00586518
*/

int GetCharStringProperty(int charID, int property_kind, int index, const char **value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00586614
*/

int SetCharStringProperty(int charID, int property_kind, int index, const char *value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005867AB
*/

int SetCharFuncProperty(int charID, int property_kind, int index, PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596E90
*/

int GetTrailByName(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596EFE
*/

// TODO fix prototype
void GetTrailIntProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596F08
*/

// TODO fix prototype
void SetTrailIntProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596F12
*/

int GetTrailFloatProperty(
        int trailID, int property_kind, int index, double *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596F82
*/

int SetTrailFloatProperty(
        int trailID, int property_kind, int index, double value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00596FFE
*/

// TODO fix prototype
void GetTrailStringProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00597024
*/

int GetTrailVectorProperty(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005970DE
*/

// TODO fix prototype
void SetTrailFuncProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005970FC
*/

int SetTrailVectorProperty(
        int trailID, int property_kind, int index, double x, double y, double z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D660
*/

// TODO fix prototype
void GetInventory()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D8A0
*/

// TODO fix prototype
void GetInventoryFloatProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D8A8
*/

// TODO fix prototype
void SetInventoryFloatProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D8B0
*/

int GetInventoryStringProperty(
    const char *name, int property_kind, const char **value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D937
*/

// TODO fix prototype
void SetInventoryStringProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059D93F
*/

int GetInventoryIntProperty(
        const char *name, int property_kind, int *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059DCFF
*/

int SetInventoryIntProperty(
        const char *name, int property_kind, int value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059DDE6
*/

int LinkRightHand(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059E03F
*/

int LinkLeftHand(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059E298
*/

int LinkLeftHand2(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059E4F1
*/

int LinkRightBack(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059E74A
*/

int LinkLeftBack(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059E9A3
*/

int LinkBack(const char *inv_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059EBFC
*/

int SetCurrentQuiver(const char *inv_name, const char *quiver_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059EE55
*/

int AddWeapon(const char *inv_name, int flag, const char *weapon_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F08C
*/

int AddObject(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F2C7
*/

int RemoveObject(
        const char *inv_name, int obj_type, const char *obj_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F316
*/

const char *GetObject(const char *inv_name, int obj_type, int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F362
*/

const char *GetObjectByName(
        const char *inv_name, int obj_type, const char *obj_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F3C4
*/

const char *GetRightBack(const char *inv_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F406
*/

const char *GetLeftBack(const char *inv_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F448
*/

const char *GetSelectedObject(const char *inv_name, int obj_type)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F490
*/

const char *GetActiveShield(const char *inv_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F4D4
*/

const char *GetActiveWeapon(const char *inv_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F518
*/

// TODO fix prototype
void ActiveWeaponActive()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F541
*/

const char *GetActiveQuiver(const char *inv_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F585
*/

void Cycle(const char *inv_name, int obj_type)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F5B0
*/

int GetNumberObjectsAt(const char *inv_name, int obj_type, int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F5E1
*/

int GetMaxNumberObjectsAt(
        const char *inv_name, int obj_type, int index
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F612
*/

int IsSelected(const char *inv_name, int obj_type, int obj_index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0059F643
*/

int CarringObject(const char *inv_name, const char *obj_name)
{
}
