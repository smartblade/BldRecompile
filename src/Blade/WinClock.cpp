#include "WinClock.h"
#include "ProcessorTimer.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004CC1C0
* VC++ mangling:          ??0B_WinClock@@QAE@XZ
*/

B_WinClock::B_WinClock()
:
isNotNT(false), hasCpuid(false), hasCpiudFunc(false), hasProcessorTimer(false)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004CC3A6
* VC++ mangling:          ?GetSystemTime@B_WinClock@@UAENXZ
*/

double B_WinClock::GetSystemTime()
{
}
