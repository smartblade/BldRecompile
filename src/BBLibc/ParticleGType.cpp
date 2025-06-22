#include "ParticleGType.h"
#include "ODataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040F69
* VC++ mangling:          ??0B_ParticleGType@@QAE@ABVB_Name@@0KI@Z
*/

B_ParticleGType::B_ParticleGType(const B_Name& new_type, const B_Name& parent_type, unsigned long operation_type, unsigned int duration)
    : B_NamedObj(new_type), duration(duration), bmpHandle(-1), operation_type(operation_type)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1004118F
* VC++ mangling:          ??1B_ParticleGType@@UAE@XZ
*/

B_ParticleGType::~B_ParticleGType()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1004122B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_ParticleGType@@@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, B_ParticleGType& particleType)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100413EE
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_ParticleGType@@@Z
*/

B_ODataFile& operator <<(B_ODataFile& file, const B_ParticleGType& particleType)
{
}
