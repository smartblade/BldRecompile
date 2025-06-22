#include <BBLibc/Name.h>
#include <BBLibc/NamedObj.h>

class B_SolidMask : public B_NamedObj
{
public:
    B_SolidMask(const B_Name &kind, int mask)
     : B_NamedObj(kind), mask(mask)
    {
    }

    int mask;
};
