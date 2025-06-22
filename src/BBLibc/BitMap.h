#include <BBLibc/Pal.h>
class B_IDataFile;
class B_ODataFile;

class LIB_EXP B_BitMap
{
public:
    enum BitMapType
    {
        BitMapType2 = 2,
        BitMapType4 = 4,
    };
    virtual ~B_BitMap();
    B_BitMap(const B_BitMap& src);
    B_BitMap(BitMapType type, unsigned int, unsigned int, const B_Pal* pal);


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006C20
    * VC++ mangling:          ??4B_BitMap@@QAEAAV0@ABV0@@Z
    */

    B_BitMap& operator=(const B_BitMap& that)
    {
        type = that.type;
        dimension1 = that.dimension1;
        dimension2 = that.dimension2;
        data = that.data;
        pal = that.pal;
        return *this;
    }

    BitMapType type;
    unsigned int dimension1;
    unsigned int dimension2;
    void* data;
    B_Pal* pal;
};
