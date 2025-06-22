#include "ResourceManager.h"
#include "IDataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004425
*/

B_Resource* B_ResourceLocation::GetResource(unsigned short resourceId)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100049F8
* VC++ mangling:          ??0B_ResourceManager@@QAE@XZ
*/

B_ResourceManager::B_ResourceManager()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004A9B
* VC++ mangling:          ??1B_ResourceManager@@QAE@XZ
*/

B_ResourceManager::~B_ResourceManager()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004AE0
* VC++ mangling:          ?Clean@B_ResourceManager@@QAEXXZ
*/

void B_ResourceManager::Clean()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10004E0B
* VC++ mangling:          ?LocateResourceIn@B_ResourceManager@@QAEIABVB_Name@@PBV2@H@Z
*/

unsigned int B_ResourceManager::LocateResourceIn(const B_Name& id, const B_Name*, int)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000582E
* VC++ mangling:          ?AddAutoResource@B_ResourceManager@@QAEIABVB_Name@@PAVB_Resource@@H@Z
*/

unsigned int B_ResourceManager::AddAutoResource(B_Name const&, B_Resource*, int)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005AF0
* VC++ mangling:          ?GetResource@B_ResourceManager@@QAEPAVB_Resource@@GABVB_Name@@@Z
*/

B_Resource* B_ResourceManager::GetResource(unsigned short resourceId, const B_Name& name)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005CCD
* VC++ mangling:          ?IsResourceLoaded@B_ResourceManager@@QAEHHH@Z
*/

int B_ResourceManager::IsResourceLoaded(int, int)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005ED1
* VC++ mangling:          ?FreeResource@B_ResourceManager@@QAEXPAVB_Resource@@@Z
*/

void B_ResourceManager::FreeResource(B_Resource* resource)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F32
* VC++ mangling:          ?NResources@B_ResourceManager@@QAEIG@Z
*/

unsigned int B_ResourceManager::NResources(unsigned short)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10005F66
* VC++ mangling:          ?AddBodLink@B_ResourceManager@@QAEXPBDH0H@Z
*/

void B_ResourceManager::AddBodLink(char const* c, int i, char const* pc, int i1)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10006830
* VC++ mangling:          ??4B_ResourceManager@@QAEAAV0@ABV0@@Z
*/

B_ResourceManager& B_ResourceManager::operator =(const B_ResourceManager& that)
{
}
