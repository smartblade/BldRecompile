class B_IDataFile;
class B_ODataFile;

class LIB_EXP B_Color
{
public:

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006860
    * VC++ mangling:          ??0B_Color@@QAE@XZ
    */

    B_Color() : r(0), g(0), b(0)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006890
    * VC++ mangling:          ??0B_Color@@QAE@EEE@Z
    */

    B_Color(byte r, byte g, byte b) : r(r), g(g), b(b)
    {
        MakeCons();
    };


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006B60
    * VC++ mangling:          ??0B_Color@@QAE@ABV0@@Z
    */

    B_Color(const B_Color& that) : r(that.r), g(that.g), b(that.b)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006BA0
    * VC++ mangling:          ??4B_Color@@QAEAAV0@ABV0@@Z
    */

    B_Color& operator =(const B_Color& that)
    {
        r = that.r;
        g = that.g;
        b = that.b;
        return *this;
    }

    virtual void MakeCons();

    B_Color operator +(B_Color const& color) const;
    B_Color operator *(float coef) const;
    B_Color operator /(float f)const;

    byte r;
    byte g;
    byte b;
};
