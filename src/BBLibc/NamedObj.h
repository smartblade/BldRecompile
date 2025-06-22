#include "Name.h"

class LIB_EXP B_NamedObj
{
public:

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002300
    * VC++ mangling:          ??1B_NamedObj@@UAE@XZ
    */

    virtual ~B_NamedObj()
    {
    }

    B_NamedObj();


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002320
    * VC++ mangling:          ??0B_NamedObj@@QAE@ABV0@@Z
    */

    B_NamedObj(const B_NamedObj& that) : name(that.name)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002350
    * VC++ mangling:          ??4B_NamedObj@@QAEAAV0@ABV0@@Z
    */

    B_NamedObj& operator=(const B_NamedObj& that)
    {
        name = that.name;
        return *this;
    }

    B_NamedObj(const B_Name& name);
    const B_Name& Id() const;
public:
    B_Name name;
};
