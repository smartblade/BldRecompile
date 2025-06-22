#include <BWorld/Surface.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00453B10
* VC++ mangling:          ??0B_Surface@@QAE@XZ
*/

B_Surface::B_Surface()
 : unknown024(0)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00453B81
* VC++ mangling:          ??1B_Surface@@UAE@XZ
*/

B_Surface::~B_Surface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00453B9E
* VC++ mangling:          ?GetPortals@B_Surface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_Surface::GetPortals(B_Portal **portals, int *numPortals)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004547D7
* VC++ mangling:          ?unknown018@B_Surface@@UAEXXZ
*/

void B_Surface::unknown018()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454806
* VC++ mangling:          ?unknown01C@B_Surface@@UAEXXZ
*/

void B_Surface::unknown01C()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004548AF
* VC++ mangling:          ?unknown018@B_OpaqueSurface@@UAEXXZ
*/

void B_OpaqueSurface::unknown018()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045499F
*/

B_Surface *ReadSurface(B_IDataFile &file)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454C0A
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Surface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Surface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454C44
* VC++ mangling:          ?ClassId@B_DomeSurface@@UAEHXZ
*/

int B_DomeSurface::ClassId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454E39
* VC++ mangling:          ?unknown014@B_DomeSurface@@UAEXXZ
*/

void B_DomeSurface::unknown014()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454ED5
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_DomeSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_DomeSurface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00454F25
* VC++ mangling:          ?ClassId@B_OpaqueSurface@@UAEHXZ
*/

int B_OpaqueSurface::ClassId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456594
* VC++ mangling:          ?unknown014@B_OpaqueSurface@@UAEXXZ
*/

void B_OpaqueSurface::unknown014()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004566EC
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_OpaqueSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_OpaqueSurface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456760
* VC++ mangling:          ??0B_Portal@@QAE@XZ
*/

B_Portal::B_Portal()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004567CD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Portal@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Portal &portal)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045681F
* VC++ mangling:          ??0B_TransparentSurface@@QAE@XZ
*/

B_TransparentSurface::B_TransparentSurface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456960
* VC++ mangling:          ?ClassId@B_TransparentSurface@@UAEHXZ
*/

int B_TransparentSurface::ClassId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456970
* VC++ mangling:          ?GetPortals@B_TransparentSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_TransparentSurface::GetPortals(B_Portal **portals, int *numPortals)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456B78
* VC++ mangling:          ?unknown010@B_TransparentSurface@@UAEXXZ
*/

void B_TransparentSurface::unknown010()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456C3A
* VC++ mangling:          ?unknown014@B_TransparentSurface@@UAEXXZ
*/

void B_TransparentSurface::unknown014()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00456FF1
* VC++ mangling:          ?unknown018@B_TransparentSurface@@UAEXXZ
*/

void B_TransparentSurface::unknown018()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045719A
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_TransparentSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_TransparentSurface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045729D
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_PortalPlanes@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_PortalPlanes &portalPlanes)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004574A5
* VC++ mangling:          ??0B_SinglePortalSurface@@QAE@XZ
*/

B_SinglePortalSurface::B_SinglePortalSurface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00457EFE
* VC++ mangling:          ?ClassId@B_SinglePortalSurface@@UAEHXZ
*/

int B_SinglePortalSurface::ClassId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00457F0E
* VC++ mangling:          ?GetPortals@B_SinglePortalSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_SinglePortalSurface::GetPortals(B_Portal **portals, int *numPortals)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00458123
* VC++ mangling:          ?unknown010@B_SinglePortalSurface@@UAEXXZ
*/

void B_SinglePortalSurface::unknown010()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00458217
* VC++ mangling:          ?unknown014@B_SinglePortalSurface@@UAEXXZ
*/

void B_SinglePortalSurface::unknown014()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00458CE9
* VC++ mangling:          ?unknown018@B_SinglePortalSurface@@UAEXXZ
*/

void B_SinglePortalSurface::unknown018()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00458F60
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_SinglePortalSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_SinglePortalSurface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045AC13
* VC++ mangling:          ??0B_MultiplePortalSurface@@QAE@XZ
*/

B_MultiplePortalSurface::B_MultiplePortalSurface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045AD21
* VC++ mangling:          ??1B_MultiplePortalSurface@@UAE@XZ
*/

B_MultiplePortalSurface::~B_MultiplePortalSurface()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045AE93
* VC++ mangling:          ?ClassId@B_MultiplePortalSurface@@UAEHXZ
*/

int B_MultiplePortalSurface::ClassId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045AEA3
* VC++ mangling:          ?GetPortals@B_MultiplePortalSurface@@UAEXPAPAVB_Portal@@PAH@Z
*/

void B_MultiplePortalSurface::GetPortals(B_Portal **portals, int *numPortals)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045B110
* VC++ mangling:          ?unknown010@B_MultiplePortalSurface@@UAEXXZ
*/

void B_MultiplePortalSurface::unknown010()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045B28B
* VC++ mangling:          ?unknown014@B_MultiplePortalSurface@@UAEXXZ
*/

void B_MultiplePortalSurface::unknown014()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045B67E
* VC++ mangling:          ?unknown018@B_MultiplePortalSurface@@UAEXXZ
*/

void B_MultiplePortalSurface::unknown018()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045B707
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_MultiplePortalSurface@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_MultiplePortalSurface &surface)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045BCC0
* VC++ mangling:          ?unknown010@B_Surface@@UAEXXZ
*/

void B_Surface::unknown010()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0045BCD0
* VC++ mangling:          ?unknown014@B_Surface@@UAEXXZ
*/

void B_Surface::unknown014()
{
}
