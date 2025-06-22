#include "netblade_int.h"


/*
* Module:                 NetBlade.dll
* Entry point:            0x100037D0
*/

void bld_net::message_received(
        unsigned long idFrom, void *message, unsigned long messageSize
)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100037F6
*/

void unknown100037F6()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100037FB
*/

void bld_net::player_destroyed(unsigned long playerId)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000381B
*/

void bld_net::cb_unknown00C(int i1, int i2, int i3, const char *s)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003847
*/

void unknown10003847()
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000384C
*/

void bld_net::player_created(unsigned long playerId, const char *name)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000386F
*/

bld_abstract_net *GetNetInterface(bld_net_cb *cb, HMODULE module)
{
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003928
*/

void CloseConection()
{
}
