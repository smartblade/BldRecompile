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
* Entry point:            0x100014D2
* VC++ mangling:          ?Close@B_IDataFile@@QAEXXZ
*/

void B_IDataFile::Close()
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
* Entry point:            0x100018A6
* VC++ mangling:          ?Seek@B_IDataFile@@QAEJJH@Z
*/

long B_IDataFile::Seek(long offset, int whence)
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
* Entry point:            0x10001A33
* VC++ mangling:          ?Read@B_IDataFile@@QAEXPAXI@Z
*/

void B_IDataFile::Read(void* data, unsigned int size)
{
}
