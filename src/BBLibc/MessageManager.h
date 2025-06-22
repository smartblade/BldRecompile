#include <BBLibc/Name.h>
#include <BBLibc/MessageChannel.h>

class LIB_EXP B_MessageManager
{
public:
    ~B_MessageManager();


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002720
    * VC++ mangling:          ??4B_MessageManager@@QAEAAV0@ABV0@@Z
    */

    B_MessageManager& operator=(const B_MessageManager& that)
    {
        unknown00 = that.unknown00;
        return *this;
    }

    unsigned int Add(B_MessageChannel* channel);
    unsigned int OpenChannel(const B_Name& channel_name);
    unsigned int CloseChannel(const B_Name& channel_name);
    B_MessageChannel* DisconnectChannel(const B_Name& channel_name);

private:
    byte unknown00;
};
