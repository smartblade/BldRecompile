#include <console.h>
#include <Raster/RasterDevice.h>
#include "BladeApp.h"
#include "WinClock.h"
#include "sound_device.h"
#include <View/CameraView.h>
#include <BBLibc/BBLibc.h>
#include <BBLibc/BitMap24.h>
#include <BBLibc/MessageManager.h>
#include <BBLibc/IDataFile.h>
#include <BInputc.h>
#include <NetMod/libnet.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0040F040
* VC++ mangling:          ??0B_WinApp@@QAE@PAUHINSTANCE__@@HPADP6GJPAUHWND__@@IIJ@Z@Z
*/

B_WinApp::B_WinApp(HINSTANCE module, int nCmdShow, char *cmdLine, WNDPROC winProc)
:
B_App(cmdLine)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F1B4
* VC++ mangling:          ??1B_WinApp@@UAE@XZ
*/

B_WinApp::~B_WinApp()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F256
* VC++ mangling:          ?InitWindow@B_WinApp@@UAE_NXZ
*/

bool B_WinApp::InitWindow()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F388
* VC++ mangling:          ?ProcessMessage@B_WinApp@@UAEXXZ
*/

void B_WinApp::ProcessMessage()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F3BB
* VC++ mangling:          ?NewWindow@B_WinApp@@UAEPAUHWND__@@XZ
*/

HWND B_WinApp::NewWindow()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F403
* VC++ mangling:          ?NewWindowForClientRectangle@B_WinApp@@UAEPAUHWND__@@XZ
*/

HWND B_WinApp::NewWindowForClientRectangle()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F4A4
* VC++ mangling:          ?Start@B_WinApp@@UAE_NXZ
*/

bool B_WinApp::Start()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
* VC++ mangling:          ?LoadLevel@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::LoadLevel(const char *map)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410305
* VC++ mangling:          ?ProcessEvents@B_WinApp@@UAE_NXZ
*/

bool B_WinApp::ProcessEvents()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410384
* VC++ mangling:          ?End@B_WinApp@@UAEXXZ
*/

void B_WinApp::End()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004103A1
* VC++ mangling:          ?Quit@B_WinApp@@UAEHXZ
*/

int B_WinApp::Quit()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004103D7
* VC++ mangling:          ?ReadArguments@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::ReadArguments(const char *args)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410640
* VC++ mangling:          ?GetCameraView@B_WinApp@@UAE_NPAVB_CameraView@@@Z
*/

bool B_WinApp::GetCameraView(B_CameraView *cameraView)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004106F2
* VC++ mangling:          ?ReadLevel@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::ReadLevel(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041073A
* VC++ mangling:          ?WindowProcedure@B_WinApp@@UAEJPAUHWND__@@IIJ@Z
*/

LRESULT B_WinApp::WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410AF5
* VC++ mangling:          ?Mouse@B_WinApp@@UAEX_N@Z
*/

void B_WinApp::Mouse(bool acquire)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410B53
* VC++ mangling:          ?ExitWithError@B_WinApp@@UAEXPAD0@Z
*/

void B_WinApp::ExitWithError(char *Title, char *Message)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410BBE
* VC++ mangling:          ?PrintWarning@B_WinApp@@UAEXPBD0@Z
*/

void B_WinApp::PrintWarning(const char *Title, const char *Message)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410C3D
* VC++ mangling:          ?Input@B_WinApp@@UAEPBDPBD@Z
*/

const char *B_WinApp::Input(const char *text)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410C77
* VC++ mangling:          ?WindowProcedure@@YGJPAUHWND__@@IIJ@Z
*/

LRESULT CALLBACK WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
* VC++ mangling:          _WinMain@16
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410DC2
* VC++ mangling:          ?LoadRasterDLL@B_WinApp@@QAEHPBD@Z
*/

int B_WinApp::LoadRasterDLL(const char *rasterDllName)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410F6F
* VC++ mangling:          ?SetDirMap@B_WinApp@@UAEHPBD@Z
*/

int B_WinApp::SetDirMap(const char *map)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411034
* VC++ mangling:          ?GetInputMode@B_WinApp@@UAEPBDPBD@Z
*/

const char *B_WinApp::GetInputMode(const char *device)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00411043
* VC++ mangling:          ?SetInputMode@B_WinApp@@UAEHPBD0@Z
*/

int B_WinApp::SetInputMode(const char *device, const char *mode)
{
}
