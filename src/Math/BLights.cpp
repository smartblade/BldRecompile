#include <Math/BLights.h>
#include <BBLibc/IDataFile.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004943A0
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_LightSource@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_LightSource &light)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004947F4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_DirectedLightSource@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_DirectedLightSource &light)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00494866
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_AmbientLight@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_AmbientLight &ambient)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00494BB8
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_FlatLight@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_FlatLight &flat)
{
}
