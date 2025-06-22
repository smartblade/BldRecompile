#include <App/App.h>
#include <bld_python.h>
#include <Raster/RasterDevice.h>
#include <Control/anim.h>
#include <View/CameraView.h>
#include <Entities/BipedEntity.h>
#include <Entities/CameraEntity.h>
#include <Entities/PersonEntity.h>
#include <Person/simpleact.h>
#include "sound_device.h"
#include <NetMod/libnet.h>
#include <BInputc.h>
#include <BBLibc/BBLibc.h>
#include <BBLibc/ResourceManager.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/NDataBase.h>
#include <BBLibc/BitMap24.h>
#include <BUIxc.h>
#include "bld_misc_funcs.h"
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00411281
* VC++ mangling:          ?Call@B_AfterFrameFunc@@QAEXM@Z
*/

void B_AfterFrameFunc::Call(float time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004113CE
* VC++ mangling:          ??0B_App@@QAE@PAD@Z
*/

B_App::B_App(char *cmdLine)
:
viewPose(B_Vector(0.0, 0.0, 0.0), 0.0, 0.0, 0.0)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411843
* VC++ mangling:          ??1B_App@@UAE@XZ
*/

B_App::~B_App()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411C2E
* VC++ mangling:          ?Start@B_App@@UAE_NXZ
*/

bool B_App::Start()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411C54
* VC++ mangling:          ?InitPythonPath@B_App@@UAE_NXZ
*/

bool B_App::InitPythonPath()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411CC4
* VC++ mangling:          ?SetListenerMode@B_App@@QAEHHABVB_Vector@@@Z
*/

int B_App::SetListenerMode(int mode, const B_Vector &v)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411D95
* VC++ mangling:          ?DeactivateInput@B_App@@QAEHXZ
*/

int B_App::DeactivateInput()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411E25
* VC++ mangling:          ?ActivateInput@B_App@@QAEHXZ
*/

int B_App::ActivateInput()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411EB9
* VC++ mangling:          ?SetAppMode@B_App@@QAEHABVB_Name@@@Z
*/

int B_App::SetAppMode(const B_Name &mode)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412053
* VC++ mangling:          ?GetCmdLine@B_App@@QAEPBDXZ
*/

const char *B_App::GetCmdLine()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412067
* VC++ mangling:          ?GetAppMode@B_App@@QAEABVB_Name@@XZ
*/

const B_Name &B_App::GetAppMode()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041207A
* VC++ mangling:          ?Quit@B_App@@UAEHXZ
*/

int B_App::Quit()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041208A
* VC++ mangling:          ?SetTime@B_App@@QAEHN@Z
*/

int B_App::SetTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004120D3
* VC++ mangling:          ?GoToTime@B_App@@QAEHN@Z
*/

int B_App::GoToTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041211C
* VC++ mangling:          ?GetTime@B_App@@QAENXZ
*/

double B_App::GetTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412138
* VC++ mangling:          ?StopTime@B_App@@QAEXXZ
*/

void B_App::StopTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412154
* VC++ mangling:          ?RestartTime@B_App@@QAEXXZ
*/

void B_App::RestartTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00412170
* VC++ mangling:          ?GetTimeSpeed@B_App@@QAENXZ
*/

double B_App::GetTimeSpeed()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041218C
* VC++ mangling:          ?SetTimeSpeed@B_App@@QAEXN@Z
*/

void B_App::SetTimeSpeed(double speed)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004121CE
* VC++ mangling:          ?ProcessEvents@B_App@@UAE_NXZ
*/

bool B_App::ProcessEvents()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413121
* VC++ mangling:          ?End@B_App@@UAEXXZ
*/

void B_App::End()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041316C
* VC++ mangling:          ?MarkLevelToLoad@B_App@@UAEXPBD@Z
*/

void B_App::MarkLevelToLoad(const char *map)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004131BB
* VC++ mangling:          ?CloseLevel@B_App@@UAEXPBD0@Z
*/

void B_App::CloseLevel(const char *statement, const char *newMap)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413256
* VC++ mangling:          ?LoadLevel@B_App@@UAEXPBD@Z
*/

void B_App::LoadLevel(const char *script)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413840
* VC++ mangling:          ?SaveScreenShot@B_App@@QAEXPBDHH@Z
*/

void B_App::SaveScreenShot(const char *filename, int width, int height)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004138A0
* VC++ mangling:          ?TakeSnapShot@B_App@@QAEXXZ
*/

void B_App::TakeSnapShot()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004138B8
* VC++ mangling:          ?ReadLevel@B_App@@UAEXPBD@Z
*/

void B_App::ReadLevel(const char * file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413EE1
* VC++ mangling:          ?StoreCombustionParticleNames@B_App@@UAEXXZ
*/

void B_App::StoreCombustionParticleNames()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00413FB6
* VC++ mangling:          ?ReassignCombustionData@B_App@@UAEXXZ
*/

void B_App::ReassignCombustionData()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041412A
* VC++ mangling:          ?ClearLevel@B_App@@UAEXH@Z
*/

void B_App::ClearLevel(int flag)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00414F58
* VC++ mangling:          ?GetPlayerStatus1@B_App@@QAEPAVB_PersonStatus@@XZ
*/

B_PersonStatus *B_App::GetPlayerStatus1()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00414F7F
* VC++ mangling:          ?PrepareLevel@B_App@@QAEXXZ
*/

void B_App::PrepareLevel()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004150B4
* VC++ mangling:          ?DoneLoadGame@B_App@@QAEXXZ
*/

void B_App::DoneLoadGame()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415145
* VC++ mangling:          ?BeginLoadGame@B_App@@QAEXXZ
*/

void B_App::BeginLoadGame()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041520F
* VC++ mangling:          ?GetPlayerStatus2@B_App@@QAEPAVB_PersonStatus@@XZ
*/

B_PersonStatus *B_App::GetPlayerStatus2()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415236
* VC++ mangling:          ?GetAttachedDevice@B_App@@QAEPAVB_InputDevice@@PBD@Z
*/

B_InputDevice *B_App::GetAttachedDevice(const char *device)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415255
* VC++ mangling:          ?GetInputActions@B_App@@QAEPAVB_InputActions@@XZ
*/

B_InputActions *B_App::GetInputActions()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041526D
* VC++ mangling:          ?GetTimeActionHeld@B_App@@QAENPBD@Z
*/

double B_App::GetTimeActionHeld(const char *action)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041529D
* VC++ mangling:          ?AddInputAction@B_App@@QAEXPBDH@Z
*/

void B_App::AddInputAction(const char *action_name, int npi)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004152C0
* VC++ mangling:          ?RemoveInputAction@B_App@@QAEXPBD@Z
*/

void B_App::RemoveInputAction(const char *action_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415425
* VC++ mangling:          ?Bind@B_App@@QAE_NPBDPAUPyObject@@@Z
*/

bool B_App::Bind(const char *key, PyObject *proc)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415471
* VC++ mangling:          ?Bind2@B_App@@QAEXPBD00H@Z
*/

void B_App::Bind2(
    const char *act, const char *subact1,
    const char *subact2, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041549C
* VC++ mangling:          ?BindPred@B_App@@QAE_NPBD0@Z
*/

bool B_App::BindPred(const char *key, const char *pred)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004154F2
* VC++ mangling:          ?UnBindPred@B_App@@QAE_NPBD0@Z
*/

bool B_App::UnBindPred(const char *key, const char *pred)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415548
* VC++ mangling:          ?UnBind@B_App@@QAE_NPBDPAUPyObject@@@Z
*/

bool B_App::UnBind(const char *key, PyObject *proc)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004155AE
* VC++ mangling:          ?AssocKey@B_App@@QAEHPBD00H@Z
*/

int B_App::AssocKey(
    const char *action, const char *input_device, const char *key,
    int press
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004155D9
* VC++ mangling:          ?UnBindAll@B_App@@QAEXXZ
*/

void B_App::UnBindAll()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415610
* VC++ mangling:          ?SetAutoGenTexture@B_App@@QAEHPBDH@Z
*/

int B_App::SetAutoGenTexture(const char *textureName, int textureEffect)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415759
* VC++ mangling:          ?RunPythonFile@B_App@@QAE_NPBD@Z
*/

bool B_App::RunPythonFile(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00415811
* VC++ mangling:          ?ReadArguments@B_App@@UAEXPBD@Z
*/

void B_App::ReadArguments(const char *args)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041617B
* VC++ mangling:          ?OutSound@B_App@@QAE_NHNNNH@Z
*/

bool B_App::OutSound(int soundId, double x, double y, double z, int unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004161EA
* VC++ mangling:          ?CallCdCb@B_App@@UAEXH@Z
*/

void B_App::CallCdCb(int arg)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416298
* VC++ mangling:          ?CDSetCallBack@B_App@@QAEHPAUPyObject@@@Z
*/

int B_App::CDSetCallBack(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416309
* VC++ mangling:          ?SetAfterFrameFunc@B_App@@QAEXPBDPAUPyObject@@@Z
*/

void B_App::SetAfterFrameFunc(const char *name, PyObject *function)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041653E
* VC++ mangling:          ?GetAfterFrameFunc@B_App@@QAEPAUPyObject@@PBD@Z
*/

PyObject *B_App::GetAfterFrameFunc(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004165D8
* VC++ mangling:          ?GetAfterFrameFuncName@B_App@@QAEPBDH@Z
*/

const char *B_App::GetAfterFrameFuncName(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041661D
* VC++ mangling:          ?GetnAfterFrameFuncs@B_App@@QAEHXZ
*/

int B_App::GetnAfterFrameFuncs()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416631
* VC++ mangling:          ?SetMenuTgapFunc@B_App@@QAEXPAUPyObject@@@Z
*/

void B_App::SetMenuTgapFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416678
* VC++ mangling:          ?GetMenuTgapFunc@B_App@@QAEPAUPyObject@@XZ
*/

PyObject *B_App::GetMenuTgapFunc()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041668C
* VC++ mangling:          ?RemoveAfterFrameFunc@B_App@@QAEHPBD@Z
*/

int B_App::RemoveAfterFrameFunc(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004167E1
* VC++ mangling:          ?StringSplit@B_App@@UAEXPBD0PAV?$B_PtrArray@VB_Name@@@@@Z
*/

void B_App::StringSplit(
    const char *str, const char *sep, B_PtrArray<B_Name> *tokens)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416C0B
* VC++ mangling:          ?SetBloodLevel@B_App@@QAEHH@Z
*/

int B_App::SetBloodLevel(int bloodLevel)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416C29
* VC++ mangling:          ?GetBloodLevel@B_App@@QAEHXZ
*/

int B_App::GetBloodLevel()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416C3D
* VC++ mangling:          ?SetMutilationLevel@B_App@@QAEHH@Z
*/

int B_App::SetMutilationLevel(int mutilationLevel)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416C5B
* VC++ mangling:          ?GetMutilationLevel@B_App@@QAEHXZ
*/

int B_App::GetMutilationLevel()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416C6F
* VC++ mangling:          ?LoadWorld@B_App@@QAEHPBD@Z
*/

int B_App::LoadWorld(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416EAB
* VC++ mangling:          ?SetPyInteractiveString@B_App@@UAEXPBD@Z
*/

void B_App::SetPyInteractiveString(const char *str)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00416EFA
* VC++ mangling:          ?SetStringValue@B_App@@QAEHPBD0@Z
*/

int B_App::SetStringValue(const char *variable, const char *value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041712A
* VC++ mangling:          ?GetStringValue@B_App@@QAEPBDPBD@Z
*/

const char *B_App::GetStringValue(const char *variable)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004171D1
* VC++ mangling:          ?DeleteStringValue@B_App@@QAEHPBD@Z
*/

int B_App::DeleteStringValue(const char *variable)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00417417
* VC++ mangling:          ?GetInputMode@B_App@@UAEPBDPBD@Z
*/

const char *B_App::GetInputMode(const char *device)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00417426
* VC++ mangling:          ?SetInputMode@B_App@@UAEHPBD0@Z
*/

int B_App::SetInputMode(const char *device, const char *mode)
{
}
