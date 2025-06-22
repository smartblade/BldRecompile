#include <NetMod/libnet.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x005B64C0
*/

void SetDedicatedServer(bool isDedicated)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B64CD
*/

bool IsDedicatedServer()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B65C8
*/

const char *GetServerMap()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B65D2
*/

bool LoadNetModule(char *fileName)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B668D
*/

bool FreeNetData(bool freeNetLibrary)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6750
* VC++ mangling:          ?message_received@B_NetCallbacks@@UAEXKPAXK@Z
*/

void B_NetCallbacks::message_received(
    unsigned long idFrom, void *message, unsigned long messageSize)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6780
* VC++ mangling:          ?player_destroyed@B_NetCallbacks@@UAEXK@Z
*/

void B_NetCallbacks::player_destroyed(unsigned long playerId)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B67F0
* VC++ mangling:          ?player_created@B_NetCallbacks@@UAEXKPBD@Z
*/

void B_NetCallbacks::player_created(unsigned long playerId, const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6840
* VC++ mangling:          ?unknown00C@B_NetCallbacks@@UAEXHHHPBD@Z
*/

void B_NetCallbacks::unknown00C(int i1, int i2, int i3, const char *s)
{
}
