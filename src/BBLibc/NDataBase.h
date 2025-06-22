#include "array.h"
#include "Name.h"
#include "NamedObj.h"

struct LIB_EXP B_ElementCSV : public B_NamedObj
{
    virtual ~B_ElementCSV();
    float mass;
    B_Name material;
};

template<class T> class B_NDataBase : public B_PtrArray<T>
{
};
