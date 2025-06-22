#include <AnalyticGeometry/Plane.h>
#include <BBLibc/Color.h>
class B_IDataFile;

class B_LightSource
{
public:
    char unknownFields[0x014];
    B_Color color;
    float intensity;
    float precision;
    float unknown24;
};

class B_DirectedLightSource : public B_LightSource
{
public:
    B_Plane plane;
    float fUnknown;
    B_Plane unknownPlane;
};

class B_AmbientLight : public B_DirectedLightSource
{
};

class B_FlatLight : public B_DirectedLightSource
{
public:
    B_Vector direction;
    B_Vector unknownVector;
    char unknownFields[0x004];
};
