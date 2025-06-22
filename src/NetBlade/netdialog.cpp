#include "netblade_int.h"


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001DCD
*/

DPID bld_get_session_player_dpid()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001EAF
*/

//TODO implement
HRESULT bld_show_connection_dialog(HMODULE module, PLAYER_INFO *player_info)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001EE9
*/

BOOL PASCAL bld_enum_players_cb(
        DPID dpId, DWORD dwPlayerType, LPCDPNAME lpName, DWORD dwFlags,
        LPVOID lpContext)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001F08
*/

void bld_enum_players(LPDIRECTPLAY4A dp_interface)
{
}
