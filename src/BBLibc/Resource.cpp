#include "Resource.h"
#include "ResourceManager.h"

/*
* Module:                 BBLibc.dll
* Data address:           0x1004A118
* VC++ mangling:          ?B_resource_manager@@3VB_ResourceManager@@A
*/
B_ResourceManager B_resource_manager;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003EB0
* VC++ mangling:          ?GetResourceManager@@YAPAVB_ResourceManager@@XZ
*/

B_ResourceManager* GetResourceManager()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003EBA
* VC++ mangling:          ??0B_Resource@@QAE@XZ
*/

B_Resource::B_Resource()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003EFE
* VC++ mangling:          ??1B_Resource@@UAE@XZ
*/

B_Resource::~B_Resource()
{
}
