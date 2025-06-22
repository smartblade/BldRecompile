#include <Raster/RasterDevice.h>
#include <BWorld/BWorld.h>
#include <BWorld/BMap.h>
#include <BWorld/light.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x00439F5D
* VC++ mangling:          ?unknown_00439F5D@B_World@@QAEXXZ
*/

void B_World::unknown_00439F5D()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043A6A4
* VC++ mangling:          ?GetTime@B_World@@QAENXZ
*/

double B_World::GetTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043A6B8
* VC++ mangling:          ?SetTime@B_World@@QAEHN@Z
*/

int B_World::SetTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043AC07
* VC++ mangling:          ?GoToTime@B_World@@QAEXN@Z
*/

void B_World::GoToTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043B8E6
* VC++ mangling:          ?AddScheduledFunc@B_World@@QAEXNPAUPyObject@@0PBD@Z
*/

void B_World::AddScheduledFunc(
    double time, PyObject *func, PyObject *args, const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043C5FD
* VC++ mangling:          ?Update@B_World@@QAEXPAVB_ViewPose@@PAXNH@Z
*/

void B_World::Update(
    B_ViewPose *viewPose, void *cameraView, double time, int updateRaster)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043C8B2
* VC++ mangling:          ?SetSun@B_World@@QAEXHABVB_Vector@@@Z
*/

void B_World::SetSun(int exists, const B_Vector &position)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043D434
* VC++ mangling:          ?GetEnemiesVisibleFrom@B_World@@QAEXABVB_Vector@@N0NPAV?$B_PtrArray@VB_Entity@@@@@Z
*/

void B_World::GetEnemiesVisibleFrom(
    const B_Vector &position, double radius,
    const B_Vector &direction, double angle, B_PtrArray<B_Entity> *enemies)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043DBBE
* VC++ mangling:          ?FindSectorIndex@B_World@@QAEHABVB_Vector@@@Z
*/

int B_World::FindSectorIndex(const B_Vector &point)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043DC20
* VC++ mangling:          ?IntersectSegment@B_World@@QAEHABVB_Vector@@00HHPAX@Z
*/

int B_World::IntersectSegment(
    const B_Vector &startPoint, const B_Vector &endPoint,
    const B_Vector &intersection, int flags, int, void *)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043E8E8
* VC++ mangling:          ?GenerateEntityName@B_World@@QAEPBDPBD@Z
*/

const char *B_World::GenerateEntityName(const char *prefix)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043EF43
* VC++ mangling:          ?SetTriggerSectorFunc@B_World@@QAEHPBD0PAUPyObject@@@Z
*/

int B_World::SetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type,
    PyObject *func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F172
* VC++ mangling:          ?GetTriggerSectorFloorHeight@B_World@@QAEHPBD@Z
*/

int B_World::GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F209
* VC++ mangling:          ?GetTriggerSectorRoofHeight@B_World@@QAEHPBD@Z
*/

int B_World::GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F2A0
* VC++ mangling:          ?GetTriggerSectorGroup@B_World@@QAEPBDPBD@Z
*/

const char *B_World::GetTriggerSectorGroup(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F332
* VC++ mangling:          ?GetTriggerSectorPoints@B_World@@QAEPANPBD@Z
*/

double *B_World::GetTriggerSectorPoints(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F467
* VC++ mangling:          ?GetTriggerSectorFunc@B_World@@QAEPAUPyObject@@PBD0@Z
*/

PyObject *B_World::GetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F56D
* VC++ mangling:          ?SetTriggerSectorData@B_World@@QAEHPBDPAUPyObject@@@Z
*/

int B_World::SetTriggerSectorData(
    const char *trigger_sector_name, PyObject *data
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043F65D
* VC++ mangling:          ?GetTriggerSectorData@B_World@@QAEPAUPyObject@@PBD@Z
*/

PyObject *B_World::GetTriggerSectorData(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x000043F98A
* VC++ mangling:          ?LoadEntitiesData@B_World@@QAEHPBD@Z
*/

int B_World::LoadEntitiesData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0043FD82
* VC++ mangling:          ?SaveEntitiesData@B_World@@QAEHPBD@Z
*/

int B_World::SaveEntitiesData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0044008F
* VC++ mangling:          ?AddPoint@B_TriggerSector@@QAEXABVB_Vector@@H@Z
*/

void B_TriggerSector::AddPoint(const B_Vector& point, int numPoints)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00440A19
* VC++ mangling:          ?GetTriggerSectorName@B_World@@QAEPBDH@Z
*/

const char *B_World::GetTriggerSectorName(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00440A5D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@PAVB_World@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_World *world)
{
}
