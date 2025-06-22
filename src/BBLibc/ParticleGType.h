#include "array.h"
#include "Name.h"
#include "NamedObj.h"

struct B_Particle
{
    double x;
    double y;
    double z;
    int time;
};

struct B_ParticleElement
{
public:
    byte r;
    byte g;
    byte b;
    byte alpha;
    float size;
};
#define B_PARTICLE_GTYPE_COPY          0
#define B_PARTICLE_GTYPE_BLEND         1
#define B_PARTICLE_GTYPE_ADD           2
#define B_PARTICLE_GTYPE_MUL           3

class B_ParticleGType : public B_NamedObj
{
public:
    LIB_EXP virtual ~B_ParticleGType();
    LIB_EXP B_ParticleGType() : duration(0), bmpHandle(-1), operation_type(0)
    {
    }
    LIB_EXP B_ParticleGType(
        const B_Name& new_type, const B_Name& parent_type,
        unsigned long operation_type, unsigned int duration);

public:
    array_t<B_ParticleElement> a00C;
    unsigned int duration;
    int bmpHandle;
    int operation_type;
};
