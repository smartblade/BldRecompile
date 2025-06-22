#include "Clock.h"
class B_ProcessorTimer;

class B_WinClock : public B_Clock
{
public:
    B_WinClock();
    virtual double GetSystemTime();
private:
    int isNotNT;
    int hasCpuid;
    int hasCpiudFunc;
    int hasProcessorTimer;
    TIMECAPS timeCaps;
    B_ProcessorTimer *processorTimer;
    double initialTime;
};
