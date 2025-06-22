#include <BBLibc/Color.h>
#include <BBLibc/NamedObj.h>
#include <BBLibc/IDataFile.h>

class atmosphere_t : public B_NamedObj
{
public:
        atmosphere_t();
        ~atmosphere_t();
public:
        B_Color color;
        float intensity;
};
