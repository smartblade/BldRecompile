#include <bld_python.h>
#include "bld_misc_funcs.h"
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x005B5340
*/

void SetGameSpySupport(boolean enabled)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B534D
*/

// TODO fix prototype
void GetGameSpySupport()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5357
*/

void StartGSQR(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5582
*/

// TODO fix prototype
void EndGSQR()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B55ED
*/

// TODO fix prototype
void LoopGSQR()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5647
*/

void PersonChangeAnmSoundIndex(const char *person_name, int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B565C
*/

void SetDedicatedServerState(int dedicated)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5673
*/

int GetDedicatedServerState(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B568F
*/

void SetLocalOptions(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5716
*/

const char *ServerInfoBlock(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5720
*/

void ClientSetPyClientSoundFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5731
*/

void CallNetEventSound(const char *entity_name, byte id)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5959
*/

void ClientSetPyClientMutilaFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B596A
*/

void ClientSetPyClientDamageFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B597B
*/

void NetAddSoundToClient(
        const char *entity_name, const char *animation_name,
        PyObject *sound_object
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BB2
*/

const char *NetGetClientId(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BBC
*/

boolean NetSetObjectState(const char *entity_name, boolean state)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BD1
*/

void NetAddEventUserFunc(
        const char *action, PyObject *func, int ignore_host
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BF0
*/

void NetAddPosition(double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5C15
*/

void NetSetPersonView(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5DE9
*/

void GetLocalOptionsNet(
        const char **name, const char **kind, const char **weapon,
        const char **shield
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E06
*/

void GetNextPosition(double *x, double *y, double *z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E74
*/

void ServerSetPyByePlayerFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E85
*/

void ServerSetPyGetUserString(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E96
*/

void SendNetUserString(
        short kind, const char *str, int guaranteed, const char *str_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5EB4
*/

void GetLifeAndLevel(const char *entity_name, int *energy, int *life)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6146
*/

void ServerSetPyCreatePlayerFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6157
*/

boolean ClientStartMainChar(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6188
*/

int ServerSetSendDataState(int state)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B61B6
*/

int GetNetState(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B61FD
*/

void ClearPools(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B637B
*/

boolean StartServer(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63E4
*/

boolean BrowseSessions(const char *ip_address)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63FE
*/

boolean GetBrowseResult(int index, bld_server_info *info)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B641C
*/

boolean JoinSession(int index, const char *player_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6448
*/

void RestartNet(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6464
*/

void NetServerChangeLevel(const char *level_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6475
*/

float NetGetTime(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B647F
*/

int NetSetPPS(int PPS)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6490
*/

int IsValidProtocol(int protocol)
{
}
