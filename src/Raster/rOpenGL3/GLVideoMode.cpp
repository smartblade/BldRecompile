#include "ROpenGLDeviceDLL.h"


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001BEC0
* VC++ mangling:          ?FullScreen@B_OpenGLRasterDevice@@UAEHXZ
*/

int B_OpenGLRasterDevice::FullScreen()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001BEDC
*/

void GetVideoModes(B_PtrArray<B_VideoMode> &videoModes)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C0BC
* VC++ mangling:          ?GetVideoModes@B_OpenGLRasterDevice@@QAEXXZ
*/

void B_OpenGLRasterDevice::GetVideoModes()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C0D8
* VC++ mangling:          ?GetVideoModeDscr@B_OpenGLRasterDevice@@UAEHHAAH0000@Z
*/

int B_OpenGLRasterDevice::GetVideoModeDscr(
    int mode_index, int &depth, int &w, int &h, int &flags,
    int &frequency
)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001C197
* VC++ mangling:          ?SetVideoMode@B_OpenGLRasterDevice@@UAEHH@Z
*/

int B_OpenGLRasterDevice::SetVideoMode(int mode_index)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CCF8
* VC++ mangling:          ?GetCurrentMode@B_OpenGLRasterDevice@@UAEHAAH0000@Z
*/

int B_OpenGLRasterDevice::GetCurrentMode(
    int &depth, int &w, int &h, int &flags,
    int &frequency
)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CD74
* VC++ mangling:          ?SetVideoModeParameters@B_OpenGLRasterDevice@@UAEHHHHH@Z
*/

int B_OpenGLRasterDevice::SetVideoModeParameters(
    int depth, int width, int height, int frequency
)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001CED6
* VC++ mangling:          ?SetWindowSize@B_OpenGLRasterDevice@@UAEHHH@Z
*/

int B_OpenGLRasterDevice::SetWindowSize(int w, int h)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001D667
* VC++ mangling:          ?GetWindowSize@B_OpenGLRasterDevice@@UAEHAAH0@Z
*/

int B_OpenGLRasterDevice::GetWindowSize(int &w, int &h)
{
}
