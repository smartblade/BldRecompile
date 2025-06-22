#include <AnalyticGeometry/Vector.h>
#include <BBLibc/IDataFile.h>

class B_Plane
{
public:
    virtual ~B_Plane()
    {
    }

    B_Vector normal;
    double p;
};
