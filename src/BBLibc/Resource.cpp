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
