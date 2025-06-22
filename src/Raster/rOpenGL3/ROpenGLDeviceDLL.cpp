#include "ROpenGLDeviceDLL.h"
#include "ConfigSections.h"
#include "GlExtensions.h"
#include <AnalyticGeometry/ViewPose.h>
#include <View/CameraView.h>
#include <BBLibc/BBLibc.h>
#include <BBLibc/MessageManager.h>
#include <BBLibc/ParticleGType.h>


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001E100
* VC++ mangling:          ??0B_OpenGLRasterDevice@@QAE@PAUHWND__@@PAUHINSTANCE__@@@Z
*/

B_OpenGLRasterDevice::B_OpenGLRasterDevice(HWND window, HMODULE rasterModule)
    : unknown0847B4(0), domeColor(255, 255, 255), fullScreenMode(NULL)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001F599
* VC++ mangling:          ??1B_OpenGLRasterDevice@@UAE@XZ
*/

B_OpenGLRasterDevice::~B_OpenGLRasterDevice()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FA3E
* VC++ mangling:          ?CreateContext@B_OpenGLRasterDevice@@QAEHXZ
*/

int B_OpenGLRasterDevice::CreateContext()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FDF8
* VC++ mangling:          ?SwapBuffers@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::SwapBuffers()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FE3A
* VC++ mangling:          ?SetFlags@B_OpenGLRasterDevice@@UAEXJ@Z
*/

void B_OpenGLRasterDevice::SetFlags(long flags)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FE50
* VC++ mangling:          ?SetProjection@B_OpenGLRasterDevice@@UAEXABVB_CameraView@@@Z
*/

void B_OpenGLRasterDevice::SetProjection(const B_CameraView &cameraView)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002022E
* VC++ mangling:          ?Cls@B_OpenGLRasterDevice@@UAEXVB_Color@@@Z
*/

void B_OpenGLRasterDevice::Cls(B_Color color)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100202D7
* VC++ mangling:          ?ClsRGB@B_OpenGLRasterDevice@@UAEXEEE@Z
*/

void B_OpenGLRasterDevice::ClsRGB(byte r, byte g, byte b)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020380
* VC++ mangling:          ?unknown0EC@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0EC()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002045B
* VC++ mangling:          ?StartScene@B_OpenGLRasterDevice@@UAEXPAVB_ViewPose@@@Z
*/

void B_OpenGLRasterDevice::StartScene(B_ViewPose *cameraPose)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020755
* VC++ mangling:          ?EndScene@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::EndScene()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100208FB
* VC++ mangling:          ?ClearMap@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::ClearMap()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020B5D
* VC++ mangling:          ?HasWglExtension@B_OpenGLRasterDevice@@QAEHPBD@Z
*/

int B_OpenGLRasterDevice::HasWglExtension(const char *extension)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020B94
* VC++ mangling:          ?HasExtension@B_OpenGLRasterDevice@@QAEHPBD@Z
*/

int B_OpenGLRasterDevice::HasExtension(const char *extension)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021571
* VC++ mangling:          ?LoadExtensions@B_OpenGLRasterDevice@@QAEHXZ
*/

int B_OpenGLRasterDevice::LoadExtensions()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021A5B
* VC++ mangling:          ?SetMode@B_OpenGLRasterDevice@@UAEXH@Z
*/

void B_OpenGLRasterDevice::SetMode(int mode)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021DD4
* VC++ mangling:          ?unknown0D4@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0D4()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021EB5
* VC++ mangling:          ?unknown240@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown240()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002206C
* VC++ mangling:          ?unknown124@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown124()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100221EA
* VC++ mangling:          ?RasterParticles@B_OpenGLRasterDevice@@UAEXPAUB_Particle@@IPAVB_ParticleGType@@@Z
*/

void B_OpenGLRasterDevice::RasterParticles(
    B_Particle *particles, unsigned int numParticles,
    B_ParticleGType *particleType)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002249D
* VC++ mangling:          ?unknown0FC@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0FC()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100239E7
* VC++ mangling:          ?unknown100@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown100()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10023A08
* VC++ mangling:          ?unknown244@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown244()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10023F15
* VC++ mangling:          ?unknown0D0@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0D0()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100241EF
* VC++ mangling:          ?unknown234@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown234()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024730
* VC++ mangling:          ?unknown23C@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown23C()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024A68
* VC++ mangling:          ?unknown238@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown238()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024D13
* VC++ mangling:          ?AddAtmosphere@B_OpenGLRasterDevice@@UAEHABVB_Name@@ABVB_Color@@M@Z
*/

int B_OpenGLRasterDevice::AddAtmosphere(
    const B_Name &name, const B_Color &color, float intensity)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024ECB
* VC++ mangling:          ?GetAtmosphere@B_OpenGLRasterDevice@@UAEHABVB_Name@@@Z
*/

int B_OpenGLRasterDevice::GetAtmosphere(const B_Name &name)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024F36
* VC++ mangling:          ?GetAtmosphereName@B_OpenGLRasterDevice@@UAE?AVB_Name@@H@Z
*/

B_Name B_OpenGLRasterDevice::GetAtmosphereName(int atmosphereHandle)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024FA8
* VC++ mangling:          ?unknown0B0@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0B0()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025229
* VC++ mangling:          ?GetAtmosphereColor@B_OpenGLRasterDevice@@UAEXHNAAMAAVB_Color@@@Z
*/

void B_OpenGLRasterDevice::GetAtmosphereColor(
    int atmosphereHandle, double intensityFactor, float &alpha,
    B_Color &color)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100252A6
* VC++ mangling:          ?unknown108@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown108()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002562B
* VC++ mangling:          ?unknown0F8@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown0F8()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025AAF
* VC++ mangling:          ?unknown118@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown118()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025C79
* VC++ mangling:          ?unknown120@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown120()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025E28
* VC++ mangling:          ?unknown07C@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::unknown07C()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025F18
* VC++ mangling:          ?SetClipActive@B_OpenGLRasterDevice@@UAEXH@Z
*/

void B_OpenGLRasterDevice::SetClipActive(int clip_active)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025F82
* VC++ mangling:          ?SetClipWindow@B_OpenGLRasterDevice@@UAEXHHHH@Z
*/

void B_OpenGLRasterDevice::SetClipWindow(int x, int y, int w, int h)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025FEA
* VC++ mangling:          ?SetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::SetTransformation()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10026067
* VC++ mangling:          ?ResetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::ResetTransformation()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100260C0
* VC++ mangling:          ?IncModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::IncModeReflection()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100260DA
* VC++ mangling:          ?DecModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::DecModeReflection()
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10026115
* VC++ mangling:          ?SetRasterParameter@B_OpenGLRasterDevice@@UAEHPBD0@Z
*/

int B_OpenGLRasterDevice::SetRasterParameter(
    const char *parameter, const char *value)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10027929
* VC++ mangling:          ?GetRasterParameter@B_OpenGLRasterDevice@@UAEPBDPBD@Z
*/

const char *B_OpenGLRasterDevice::GetRasterParameter(const char *parameter)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100286FC
* VC++ mangling:          ?SetDomeColor@B_OpenGLRasterDevice@@UAEXEEE@Z
*/

void B_OpenGLRasterDevice::SetDomeColor(byte r, byte g, byte b)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002872D
* VC++ mangling:          ?GetDomeColor@B_OpenGLRasterDevice@@UAEXAAE00@Z
*/

void B_OpenGLRasterDevice::GetDomeColor(byte &r, byte &g, byte &b)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10028764
* VC++ mangling:          ?unknown204@B_OpenGLRasterDevice@@UAEXH@Z
*/

void B_OpenGLRasterDevice::unknown204(int)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100289BA
*/

B_3DRasterDevice *CreateRaster(
    HWND window, HMODULE mainModule, HMODULE rasterModule)
{
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10028A98
*/

int DestroyRaster(B_3DRasterDevice* raster)
{
}
