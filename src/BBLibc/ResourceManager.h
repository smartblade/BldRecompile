#include "array.h"
#include "Resource.h"

class B_ResourceLocation
{
public:
    B_Resource* GetResource(unsigned short resourceId);
};

class LIB_EXP B_ResourceManager
{
public:
    B_ResourceManager();
    ~B_ResourceManager();
    void Clean();
    unsigned int LocateResourceIn(const B_Name& id, const B_Name*, int);
    unsigned int AddAutoResource(B_Name const&, B_Resource*, int);
    B_Resource* GetResource(unsigned short resourceId, const B_Name& name);
    int IsResourceLoaded(int, int);
    void FreeResource(B_Resource* resource);
    unsigned int NResources(unsigned short);
    void AddBodLink(char const* c, int i, char const* pc, int i1);
    B_ResourceManager& operator =(const B_ResourceManager& that);

private:
    B_Resource** resources_;
    void *unknown04;
    int unknown08;
    int unknown0C;
    int unknown10;
    int unknown14;
    int unknown18;
    unsigned short resourceId; // 1Ch
    int counter; // 20h
};
