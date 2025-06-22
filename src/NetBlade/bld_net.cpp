#include "netblade_int.h"


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003960
*/

unsigned long bld_net::get_session_player_dpid()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003970
*/

unsigned long bld_net::get_all_players_id()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003980
*/

bool bld_net::is_net_game()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003990
*/

bool bld_net::is_server()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039A0
*/

unsigned long bld_net::get_player_dpid()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039B0
*/

long bld_net::send_message(unsigned long idTo, void *lpData, unsigned long wDataSize)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039E0
*/

long bld_net::send_guaranteed_message(
        unsigned long idTo, void *lpData, unsigned long wDataSize
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A10
*/

bool bld_net::start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A40
*/

bool bld_net::browse_sessions(const char *ip_address)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A60
*/

bool bld_net::get_browse_result(int index, bld_server_info *info)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A80
*/

bool bld_net::join_session(int index, const char *player_name)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003AA0
*/

bool bld_net::is_valid_protocol(bool tcp)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003AD0
*/

bld_net::~bld_net()
{
}
