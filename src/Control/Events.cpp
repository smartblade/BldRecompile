#include <Control/Events.h>
#include <Entities/Entity.h>
#include "bld_misc_funcs.h"
#include <BBLibc/BBLibc.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0048A900
* VC++ mangling:          ??0B_EventFunc@@QAE@XZ
*/

B_EventFunc::B_EventFunc()
 : pyFunc(NULL), func(NULL), name(NULL)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048A92B
* VC++ mangling:          ??0B_EventFuncs@@QAE@ABVB_Name@@@Z
*/

B_EventFuncs::B_EventFuncs(const B_Name &name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048AB7F
* VC++ mangling:          ?AddPyFunc@B_EventFuncs@@QAEXIPAUPyObject@@PBD@Z
*/

void B_EventFuncs::AddPyFunc(
    unsigned int eventIndex, PyObject *func, const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048AEB2
* VC++ mangling:          ?AddFunc@B_EventFuncs@@QAEXIP6AHPAVB_Entity@@I@ZPBD@Z
*/

void B_EventFuncs::AddFunc(
    unsigned int eventIndex, EventFn func, const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048B30B
* VC++ mangling:          ?CallFunc@B_EventFuncs@@QAEHPAVB_Entity@@I@Z
*/

int B_EventFuncs::CallFunc(B_Entity *entity, unsigned int eventIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048B74A
* VC++ mangling:          ?GetEventIndex@B_Events@@QAEHPBD@Z
*/

int B_Events::GetEventIndex(const char *event_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0048BEED
* VC++ mangling:          ?GetEventName@B_Events@@QAEABVB_Name@@H@Z
*/

const B_Name &B_Events::GetEventName(int eventIndex)
{
}
