#include "array.h"
#include <AnalyticGeometry/Vector.h>

class B_WorldPoint
{
public:
    B_WorldPoint();

    B_Vector v;
    int unknown18;
    int unknown1C;
};

class B_WorldPoints
{
public:
    array_t<B_WorldPoint> points;
};

class B_Polygon
{
public:
    B_Polygon();
    virtual ~B_Polygon();

    unsigned int numVertices;
    unsigned int *vertices;
};
