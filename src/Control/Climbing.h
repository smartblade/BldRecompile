#include <BBLibc/NamedObj.h>
#include <AnalyticGeometry/Vector.h>
#include "array.h"
class B_BipedAction;
class B_Entity;
class B_PersonEntity;

class B_ClimbingData : public B_NamedObj
{
public:
    B_Vector leftPos;
    B_Vector rightPos;
    double height;
};

/*
* Module:                 Blade.exe
* Data address:           0x007072C8
*/
extern B_PtrArray<B_ClimbingData> climbing_data_list;
