#include <dplobby.h>
#include <bld_abstract_net.h>
#include <bld_net_cb.h>
#define MAX_SESSIONS_NUM                                 32

class bld_net : public bld_abstract_net
{
private:
        bld_net_cb *cb;
public:
        bld_net(bld_net_cb *cb) {
                this->cb = cb;
        }
        virtual unsigned long get_session_player_dpid();
        virtual unsigned long get_all_players_id();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual unsigned long get_player_dpid();
        virtual long send_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        );
        virtual long send_guaranteed_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        );
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        );
        virtual bool browse_sessions(const char *ip_address);
        virtual bool get_browse_result(int index, bld_server_info *info);
        virtual bool join_session(int index, const char *player_name);
        virtual bool is_valid_protocol(bool tcp);
        virtual ~bld_net();
        static void message_received(
                unsigned long idFrom, void *message, unsigned long messageSize
        );
        static void player_destroyed(unsigned long playerId);
        static void cb_unknown00C(int i1, int i2, int i3, const char *s);
        static void player_created(unsigned long playerId, const char *name);
};
