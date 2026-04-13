#include "NamedObj.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100039E5
* VC++ mangling:          ??0B_NamedObj@@QAE@XZ
*/

B_NamedObj::B_NamedObj() : name() {}
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A07
* VC++ mangling:          ??0B_NamedObj@@QAE@ABVB_Name@@@Z
*/

B_NamedObj::B_NamedObj(const B_Name& name)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A2F
* VC++ mangling:          ?Id@B_NamedObj@@QBEABVB_Name@@XZ
*/

const B_Name& B_NamedObj::Id() const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A40
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_NamedObj@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_NamedObj& named_obj)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A58
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_NamedObj@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, B_NamedObj const& namedObj)
{
}
