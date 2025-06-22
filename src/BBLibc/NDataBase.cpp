#include "NDataBase.h"

/*
* Module:                 BBLibc.dll
* Data address:           0x1004A9D0
* VC++ mangling:          ?B_csvs@@3V?$B_NDataBase@UB_ElementCSV@@@@A
*/
B_NDataBase<B_ElementCSV> B_csvs;


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBF3
* VC++ mangling:          ?ReadCSV@@YAIPBDPAV?$B_NDataBase@UB_ElementCSV@@@@@Z
*/

unsigned int ReadCSV(const char* file_name, B_NDataBase<B_ElementCSV>* csvs)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003DBC0
* VC++ mangling:          ??1B_ElementCSV@@UAE@XZ
*/

B_ElementCSV::~B_ElementCSV()
{
}
