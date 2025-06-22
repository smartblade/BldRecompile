#include <bld_net_cb.h>
class bld_abstract_net;

class B_NetCallbacks : public bld_net_cb
{
public:
    B_NetCallbacks()
    {
    }
    virtual void message_received(
        unsigned long idFrom, void *message, unsigned long messageSize);
    virtual void player_destroyed(unsigned long playerId);
    virtual void player_created(unsigned long playerId, const char *name);
    virtual void unknown00C(int i1, int i2, int i3, const char *s);
private:
    char unknown_fields[20];
};
