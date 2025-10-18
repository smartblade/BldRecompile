#include <io.h>
#include <bld_python.h>
#include "BBLibc.h"
#include "IDataFile.h"
#include "FileInfo.h"

/*
* Module:                 BBLibc.dll
* Data address:           0x10049EFC
* VC++ mangling:          ?n_opened_files@B_IDataFile@@0HA
*/
int B_IDataFile::n_opened_files = 0;

/*
* Module:                 BBLibc.dll
* Data address:           0x10049F00
* VC++ mangling:          ?n_open_files@B_IDataFile@@0HA
*/
int B_IDataFile::n_open_files = 0;

/*
* Module:                 BBLibc.dll
* Data address:           0x10049F04
* VC++ mangling:          ?OnOpenFunc@B_IDataFile@@0PAUPyObject@@A
*/
PyObject* B_IDataFile::OnOpenFunc = nullptr;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001000
* VC++ mangling:          ?ResetnOpenedFiles@B_IDataFile@@SAXXZ
*/

void B_IDataFile::ResetnOpenedFiles()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000100F
* VC++ mangling:          ?GetnOpenedFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenedFiles()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001019
* VC++ mangling:          ?GetnOpenFiles@B_IDataFile@@SAHXZ
*/

int B_IDataFile::GetnOpenFiles()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001023
* VC++ mangling:          ?SetOnOpenFunc@B_IDataFile@@SAHPAUPyObject@@@Z
*/

int B_IDataFile::SetOnOpenFunc(PyObject* obj)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001096
* VC++ mangling:          ?RemoveOnOpenFunc@B_IDataFile@@SAXXZ
*/

void B_IDataFile::RemoveOnOpenFunc()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100014D2
* VC++ mangling:          ?Close@B_IDataFile@@QAEXXZ
*/

void B_IDataFile::Close()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100015E2
* VC++ mangling:          ?Open@B_IDataFile@@QAEXPBDH@Z
*/

void B_IDataFile::Open(const char* src, int flags)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001740
* VC++ mangling:          ??0B_IDataFile@@QAE@XZ
*/

B_IDataFile::B_IDataFile()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001788
* VC++ mangling:          ??0B_IDataFile@@QAE@PBDH@Z
*/

B_IDataFile::B_IDataFile(const char* file_name, int flags)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100017C2
* VC++ mangling:          ?ReadCacheBlock@B_IDataFile@@AAEIXZ
*/

unsigned int B_IDataFile::ReadCacheBlock()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001882
* VC++ mangling:          ?Length@B_IDataFile@@QBEJXZ
*/

long B_IDataFile::Length() const
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100018A6
* VC++ mangling:          ?Seek@B_IDataFile@@QAEJJH@Z
*/

long B_IDataFile::Seek(long offset, int whence)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019AF
* VC++ mangling:          ?Tell@B_IDataFile@@QAEJXZ
*/

long B_IDataFile::Tell()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100019CC
* VC++ mangling:          ?Peek@B_IDataFile@@QAEEXZ
*/

unsigned char B_IDataFile::Peek()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A0D
* VC++ mangling:          ?Eof@B_IDataFile@@QAEHXZ
*/

int B_IDataFile::Eof()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001A33
* VC++ mangling:          ?Read@B_IDataFile@@QAEXPAXI@Z
*/

void B_IDataFile::Read(void* data, unsigned int size)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B55
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAD@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, char& c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B6B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAE@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned char& c)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B81
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAF@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, short& s)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001B97
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAG@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned short& s)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BAD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAH@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, int& i)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BC3
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAJ@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, long& l)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BD9
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAK@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned long& l)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001BEF
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAI@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, unsigned int& i)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C05
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAM@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, float& f)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C1B
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAN@Z
*/

B_IDataFile& operator >>(B_IDataFile& file, double& f)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10001C31
* VC++ mangling:          ??1B_IDataFile@@QAE@XZ
*/

B_IDataFile::~B_IDataFile()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002220
* VC++ mangling:          ??4B_IDataFile@@QAEAAV0@ABV0@@Z
*/

B_IDataFile& B_IDataFile::operator =(B_IDataFile const& file)
{
}
