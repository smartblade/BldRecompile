#include "array.h"
#include "Resource.h"
#include <Raster/RasterDevice.h>

class LIB_EXP B_ObjDscr : public B_Resource
{
public:
    B_ObjDscr();
    ~B_ObjDscr();
    void SetUpNormals();
    void SetUpInertialT();
    int GetVtxNode(unsigned int);
    void SetUpEdges();
    void Draw(
        B_3DRasterDevice* raster, float x1, float y1, float x2, float y2,
        float scale, int i_unknown);
    void SetUpBSP();
    unsigned char EdgeFaceGrp(unsigned int);
    
};
