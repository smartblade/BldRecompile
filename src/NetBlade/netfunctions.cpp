#include "netblade_int.h"


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001000
*/

bool bld_is_server()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000100A
*/

bool bld_is_net_game()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001014
*/

PLAYER_INFO *bld_get_gbl_player_info()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000101E
*/

void bld_set_gbl_player_info(PLAYER_INFO *player_info)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001036
*/

DPID bld_get_player_dpid()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001040
*/

HRESULT bld_create_thread_by_module(HMODULE module)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001203
*/

DWORD WINAPI bld_thread_start_cb(LPVOID lpThreadParameter)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001253
*/

HRESULT bld_get_player_name(
        LPDIRECTPLAY4A dp_interface, DPID dpid, LPDPNAME *lpdpname
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001312
*/

int bld_destroy_handles()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000141A
*/

int bld_receive(PLAYER_INFO *playerInfo)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001547
*/

void bld_system_message_received(
        PLAYER_INFO *playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001711
*/

void bld_user_message_received(
        PLAYER_INFO *playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001734
*/

const char *bld_get_unknown_name(int index)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001744
*/

void bld_shift_unknown_names(const char *name)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000188C
*/

HRESULT bld_send_message(DPID idTo, LPVOID lpData, DWORD wDataSize)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100018BF
*/

HRESULT bld_send_guaranteed_message(DPID idTo, LPVOID lpData, DWORD wDataSize)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001BFB
*/

HRESULT bld_create_thread()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001CD7
*/

HRESULT bld_update_player_data()
{
}
