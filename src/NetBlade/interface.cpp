#include "netblade_int.h"


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002C70
*/

bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002EE5
*/

HRESULT bld_create_player(
        LPDIRECTPLAY4A dp_interface, const char *game_name,
        const char *player_name, PLAYER_INFO *player_info
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002FF1
*/

HRESULT bld_create_dp_interface(
        LPGUID dp_provider, LPDIRECTPLAY4A *dp_interface
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003065
*/

HRESULT bld_destroy_dp_interface(LPDIRECTPLAY4A dp_interface)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000308C
*/

bool bld_get_browse_result(int index, bld_server_info *info)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003107
*/

bool bld_browse_sessions(const char *ip_address)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000346E
*/

HRESULT bld_enum_sessions(LPDIRECTPLAY4A dp_interface)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100034E7
*/

BOOL PASCAL bld_enum_sessions_cb(
        LPCDPSESSIONDESC2 lpThisSD, LPDWORD lpdwTimeOut, DWORD dwFlags,
        LPVOID lpContext)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100035A7
*/

bool bld_join_session(int index, const char *player_name)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003614
*/

HRESULT bld_create_client_player(
        LPDIRECTPLAY4A dp_interface, LPGUID sessionGuid,
        const char *player_name, PLAYER_INFO *player_info)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100036FC
*/

bool bld_check_protocol(bool tcp)
{
}
