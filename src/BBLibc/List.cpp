#include "List.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002980
* VC++ mangling:          ??1B_ListElement@@UAE@XZ
*/

B_ListElement::~B_ListElement()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002EE0
* VC++ mangling:          ?GetList@B_ListElement@@QAEPAVB_List@@XZ
*/

B_List* B_ListElement::GetList()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002F80
* VC++ mangling:          ??4B_ListElement@@QAEAAV0@ABV0@@Z
*/

B_ListElement& B_ListElement::operator =(const B_ListElement& other)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100030A0
* VC++ mangling:          ??0B_List@@QAE@PAVB_ListElement@@@Z
*/

B_List::B_List(B_ListElement* element)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003160
* VC++ mangling:          ??0B_List@@QAE@ABV0@@Z
*/

B_List::B_List(B_List const&)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002A14
* VC++ mangling:          ?Add@B_List@@QAEIPAVB_ListElement@@@Z
*/

unsigned int B_List::Add(B_ListElement* element)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002A86
* VC++ mangling:          ?AddAfter@B_List@@QAEIPAVB_ListElement@@0@Z
*/

unsigned int B_List::AddAfter(B_ListElement* existing, B_ListElement* newElement)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002B34
* VC++ mangling:          ?AddBefore@B_List@@QAEIPAVB_ListElement@@0@Z
*/

unsigned int B_List::AddBefore(B_ListElement* existing, B_ListElement* newElement)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002BC5
* VC++ mangling:          ?Remove@B_List@@QAEIPAVB_ListElement@@I@Z
*/

unsigned int B_List::Remove(B_ListElement* element, unsigned int index)
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002E5D
* VC++ mangling:          ?Exists@B_List@@QAEIPBVB_ListElement@@@Z
*/

unsigned int B_List::Exists(const B_ListElement* element)
{
}
