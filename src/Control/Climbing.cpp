#include <Control/Climbing.h>
#include <AnalyticGeometry/Vector.h>
#include <BWorld/BWorld.h>
#include <Entities/BipedEntity.h>
#include <Entities/PersonEntity.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x00477CC6
*/

int FindClimbingTopPosition(
    const B_Vector &bottomPos, double maxHeight, B_Vector *topFloorPos,
    double step)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00477D6E
*/

int FindLeanPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    double leftHandDist, double rightHandDist,
    B_Vector *leftHandPos, B_Vector *rightHandPos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00478385
*/

int FindLowClimbingTopPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    B_Vector *lowClmbTopFloorPos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00478561
*/

int ClimbingImpulse(B_Entity *entity, unsigned int eventIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00478D62
*/

int LowClimbingImpulse(B_Entity *entity, unsigned int eventIndex)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0047920C
*/

int FindEndPos(
    B_PersonEntity *personEntity, B_BipedAction *action,
    const B_Vector &leftHandPos, const B_Vector &rightHandPos,
    B_Vector *topPersonPos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004798DC
*/

int TestClimb(B_Entity *entity, unsigned int eventIndex)
{
}
