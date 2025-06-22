#include <Entities/BipedEntity.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004D6B8A
* VC++ mangling:          ?GetEventTime@B_BipedAction@@QAENPBD@Z
*/

double B_BipedAction::GetEventTime(const char *eventName)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004D741B
* VC++ mangling:          ??0B_BipedData@@QAE@ABVB_Name@@0@Z
*/

B_BipedData::B_BipedData(const B_Name &bipedName, const B_Name &kind)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004D7990
* VC++ mangling:          ?GetNodePose@B_BipedData@@QAEABVB_Matrix@@PAVB_BipedAction@@MH@Z
*/

const B_Matrix &B_BipedData::GetNodePose(
    B_BipedAction *action, float time, int nodeIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004D7A82
* VC++ mangling:          ?GetPose@B_BipedData@@QAEABVB_Matrix@@PAVB_BipedAction@@M@Z
*/

const B_Matrix &B_BipedData::GetPose(B_BipedAction *action, float time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004D7D97
* VC++ mangling:          ?GetRightFootPose@B_BipedData@@QAEHPAVB_BipedAction@@MPAVB_Vector@@1@Z
*/

int B_BipedData::GetRightFootPose(
    B_BipedAction *action, float time, B_Vector *, B_Vector *)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x04D7E72
* VC++ mangling:          ?GetLeftFootPose@B_BipedData@@QAEHPAVB_BipedAction@@MPAVB_Vector@@1@Z
*/

int B_BipedData::GetLeftFootPose(
    B_BipedAction *action, float time, B_Vector *, B_Vector *)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004DDB85
* VC++ mangling:          ?GetAngle@B_BipedEntity@@QAENXZ
*/

double B_BipedEntity::GetAngle()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E3AD9
* VC++ mangling:          ?DoAction@B_BipedEntity@@QAEXABVB_Name@@NHPAN@Z
*/

void B_BipedEntity::DoAction(
    const B_Name &action_name, double unknown1, int iUnknown,
    double *dUnknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E3B6A
* VC++ mangling:          ?DoActionWI@B_BipedEntity@@QAEXABVB_Name@@HNNPANN@Z
*/

void B_BipedEntity::DoActionWI(
    const B_Name &actionName, int interpolationType, double time,
    double unknown1, double *dUnknown, double unknown2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E56DE
* VC++ mangling:          ?IsIncorrectPosition@B_BipedEntity@@QAEHABVB_Vector@@@Z
*/

int B_BipedEntity::IsIncorrectPosition(const B_Vector &pos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E5798
* VC++ mangling:          ?unknown004E5798@B_BipedEntity@@QAEXABVB_Vector@@@Z
*/

void B_BipedEntity::unknown004E5798(const B_Vector &pos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E5DA7
* VC++ mangling:          ?SetOnFloor@B_BipedEntity@@QAEHXZ
*/

int B_BipedEntity::SetOnFloor()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E73AF
* VC++ mangling:          ?RaiseEvent@B_BipedEntity@@QAEHH@Z
*/

int B_BipedEntity::RaiseEvent(int eventIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004E7E61
* VC++ mangling:          ?GetFloorHeight@B_BipedEntity@@QAENPAX0@Z
*/

double B_BipedEntity::GetFloorHeight(void *unknown1, void *unknown2)
{
}
