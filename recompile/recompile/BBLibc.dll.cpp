
// address: 0x10001000
void B_IDataFile::ResetnOpenedFiles()
{
    B_IDataFile::n_opened_files = 0;
}

// address: 0x1000100F
int B_IDataFile::GetnOpenedFiles()
{
    return B_IDataFile::n_opened_files;
}

// address: 0x10001019
int B_IDataFile::GetnOpenFiles()
{
    return B_IDataFile::n_open_files;
}

// address: 0x10001023
int B_IDataFile::SetOnOpenFunc(PyObject *obj)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x10001096
void B_IDataFile::RemoveOnOpenFunc()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [g10049F04], 000000000h'

// address: 0x100010E4
p100010E4
{
    unknown_function_100010F3();
    unknown_function_10001205();
}

// address: 0x100010F3
p100010F3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10001205
p10001205
{
    unknown_function_100415A8(GLOBAL(0x10001217));
}

// address: 0x10001217
p10001217
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100014D2
void B_IDataFile::Close()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100015E2
void B_IDataFile::Open(const char *src, int flags)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10001740
B_IDataFile::B_IDataFile()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = 0xFFFFFFFF;
    REGDEF(ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [ecx+004h], 000000000h'

// address: 0x10001788
B_IDataFile::B_IDataFile(const char *file_name, int flags)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+00000400Ch], 0FFFFC000h'

// address: 0x100017C2
unsigned int B_IDataFile::ReadCacheBlock()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10001882
int B_IDataFile::Length()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=0x00000000)
}
Failed to find pattern for 'cmp dword ptr [eax], 0FFFFFFFFh'

// address: 0x100018A6
int B_IDataFile::Seek(int offset, int whence)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100019AF
int B_IDataFile::Tell()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=ACCESS(STACKVAR(-4, 4), 16396, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'add eax, [ecx+000004010h]'

// address: 0x100019CC
unsigned char B_IDataFile::Peek()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10001A0D
int B_IDataFile::Eof()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+00000400Ch]'

// address: 0x10001A33
void B_IDataFile::Read(void *data, unsigned int size)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10001B55
B_IDataFile &operator >>(B_IDataFile &file, char &c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000001h'

// address: 0x10001B6B
B_IDataFile &operator >>(B_IDataFile &file, unsigned char &c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000001h'

// address: 0x10001B81
B_IDataFile &operator >>(B_IDataFile &file, short &s)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000002h'

// address: 0x10001B97
B_IDataFile &operator >>(B_IDataFile &file, unsigned short &s)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000002h'

// address: 0x10001BAD
B_IDataFile &operator >>(B_IDataFile &file, int &i)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001BC3
B_IDataFile &operator >>(B_IDataFile &file, int &l)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001BD9
B_IDataFile &operator >>(B_IDataFile &file, unsigned int &l)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001BEF
B_IDataFile &operator >>(B_IDataFile &file, unsigned int &i)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001C05
B_IDataFile &operator >>(B_IDataFile &file, float &f)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001C1B
B_IDataFile &operator >>(B_IDataFile &file, double &f)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000008h'

// address: 0x10001C31
B_IDataFile::~B_IDataFile()
{
    this->Close();
}

// address: 0x10001C44
B_ODataFile::B_ODataFile(const char *file_name, int flags)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10001DA0
p10001DA0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+00000400Ch], 000000000h'

// address: 0x10001E01
p10001E01
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp ecx, [eax+000004008h]'

// address: 0x10001E86
void B_ODataFile::Write(const void *data, unsigned int size)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10001F5E
B_ODataFile &operator <<(B_ODataFile &file, const char &c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000001h'

// address: 0x10001F74
B_ODataFile &operator <<(B_ODataFile &file, const char *c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push edi'

// address: 0x10001F9A
B_ODataFile &operator <<(B_ODataFile &file, const unsigned char &c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000001h'

// address: 0x10001FB0
B_ODataFile &operator <<(B_ODataFile &file, const short &s)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000002h'

// address: 0x10001FC6
B_ODataFile &operator <<(B_ODataFile &file, const unsigned short &s)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000002h'

// address: 0x10001FDC
B_ODataFile &operator <<(B_ODataFile &file, const int &i)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10001FF2
B_ODataFile &operator <<(B_ODataFile &file, const int &l)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10002008
B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &l)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x1000201E
B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &i)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x10002034
B_ODataFile &operator <<(B_ODataFile &file, const float &f)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000004h'

// address: 0x1000204A
B_ODataFile &operator <<(B_ODataFile &file, const double &f)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000008h'

// address: 0x10002060
p10002060
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_10001DA0();
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10002082
B_ODataFile::~B_ODataFile()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+004h]'

// address: 0x100020C3
p100020C3
{
    return B_IDataFile::GetnOpenedFiles();
}

// address: 0x100020CD
p100020CD
{
    return B_IDataFile::GetnOpenFiles();
}

// address: 0x100020D7
p100020D7
{
    B_IDataFile::ResetnOpenedFiles();
}

// address: 0x100020E1
p100020E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100020F2
void RemoveOnOpenInputFileFunc()
{
    B_IDataFile::RemoveOnOpenFunc();
}

// address: 0x10002100
p10002100
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100021E0
unsigned int B_IDataFile::OK()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=0x00000000)
}
Failed to find pattern for 'cmp dword ptr [eax], 0FFFFFFFFh'

// address: 0x10002200
char *B_IDataFile::GetFileName()
{
    return this->file_name;
}

// address: 0x10002220
B_IDataFile &B_IDataFile::operator =(const B_IDataFile &file)
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10002250
unsigned int B_ODataFile::OK()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=0x00000000)
}
Failed to find pattern for 'cmp dword ptr [eax], 0FFFFFFFFh'

// address: 0x10002270
p10002270
{
    REGDEF(eax=ACCESS(this, 4, 4))
}

// address: 0x10002290
p10002290
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x100022C0
B_Name &B_Name::Id()
{
    return *this;
}

// address: 0x100022D0
void B_Name::operator const char*()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov eax, dword ptr [eax]'

// address: 0x100022E0
unsigned int B_Name::Length()
{
    return this->len;
}

// address: 0x10002300
B_NamedObj::~B_NamedObj()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g1004217C'

// address: 0x10002320
B_NamedObj::B_NamedObj(const B_NamedObj &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10002350
B_NamedObj &B_NamedObj::operator=(const B_NamedObj &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x100023C0
void sub_100023C0(B_NamedObj *this_ptr, int arg_0)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100024C0
B_MessageChannel::B_MessageChannel(B_Name &name)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100024F0
p100024F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10002540
p10002540
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=0x00000000)
    RESTORE(esp);
}
Failed to find pattern for 'pop ebp'

// address: 0x10002550
B_MessageChannel::~B_MessageChannel()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Can't parse line: ;

// address: 0x10002580
B_MessageChannel::B_MessageChannel(const B_MessageChannel &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x100025C0
B_MessageChannel &B_MessageChannel::operator=(const B_MessageChannel &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10002640
p10002640
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10002710
B_MessageManager::~B_MessageManager()
{
}

// address: 0x10002720
B_MessageManager &B_MessageManager::operator=(const B_MessageManager &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov cl, byte ptr [eax]'

// address: 0x10002740
char *GetConfigDirectory()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100028EC
char *GetCurrentLanguage()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000100h'

// address: 0x10002980
B_ListElement::~B_ListElement()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g10042190'

// address: 0x100029AE
p100029AE
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x10002A14
unsigned int B_List::Add(B_ListElement *element)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+008h], 000000000h'

// address: 0x10002A86
unsigned int B_List::AddAfter(B_ListElement *existing, B_ListElement *newElement)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10002B34
unsigned int B_List::AddBefore(B_ListElement *existing, B_ListElement *newElement)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10002BC5
unsigned int B_List::Remove(B_ListElement *element, unsigned int index)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10002CAC
p10002CAC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10002D5D
p10002D5D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10002E0E
p10002E0E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10002E5D
unsigned int B_List::Exists(const B_ListElement *element)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10002EA0
B_ListElement::B_ListElement()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10002EE0
B_List *B_ListElement::GetList()
{
    return this->list;
}

// address: 0x10002F00
B_ListElement *B_ListElement::GetNext()
{
    return this->next;
}

// address: 0x10002F20
B_ListElement *B_ListElement::GetPrev()
{
    return this->prev;
}

// address: 0x10002F40
B_ListElement::B_ListElement(const B_ListElement &other)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x10002F80
B_ListElement &B_ListElement::operator =(const B_ListElement &other)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x10002FF0
p10002FF0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100030A0
B_List::B_List(B_ListElement *element)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x100030E0
B_List::~B_List()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Can't parse line: ;

// address: 0x10003100
p10003100
{
    REGDEF(eax=ACCESS(this, 4, 4))
}

// address: 0x10003120
p10003120
{
    REGDEF(eax=ACCESS(this, 8, 4))
}

// address: 0x10003140
p10003140
{
    REGDEF(eax=ACCESS(this, 12, 4))
}

// address: 0x10003160
B_List::B_List(const B_List &arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x100031A0
B_List &B_List::operator=(const B_List &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x100031E0
p100031E0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10003250
p10003250
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003300
B_Name::B_Name()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10003337
B_Name::B_Name(const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100033A4
B_Name::B_Name(const B_Name &src)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10003410
B_Name::B_Name(unsigned int len)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10003457
char *B_Name::String()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov eax, dword ptr [eax]'

// address: 0x10003467
unsigned int B_Name::operator >(const B_Name &rhs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100034DA
unsigned int B_Name::operator <(const B_Name &rhs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1000354D
unsigned int B_Name::operator ==(const B_Name &rhs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100035D2
unsigned int B_Name::operator ==(const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10003643
unsigned int B_Name::operator !=(const B_Name &rhs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100036C5
unsigned int B_Name::operator !=(const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10003730
p10003730
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [eax+004h]'

// address: 0x10003769
unsigned int B_Name::CompareNoCase(const char *str)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000378E
B_Name &B_Name::operator =(const B_Name &src)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10003821
B_Name B_Name::Right(unsigned int count)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10003898
B_Name B_Name::Left(unsigned int count)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10003904
B_IDataFile &operator >>(B_IDataFile &file, B_Name &name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000398A
B_ODataFile &operator <<(B_ODataFile &file, const B_Name &name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x100039BA
B_Name::~B_Name()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100039E5
B_NamedObj::B_NamedObj()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'add ecx, 000000004h'

// address: 0x10003A07
B_NamedObj::B_NamedObj(const B_Name &n)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10003A2F
B_Name &B_NamedObj::Id()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10003A40
B_IDataFile &operator >>(B_IDataFile &file, B_NamedObj &named_obj)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10003A58
B_ODataFile &operator <<(B_ODataFile &file, const B_NamedObj &namedObj)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10003A70
B_Name operator +(const B_Name &lother, const B_Name &rother)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10003B1E
B_Name operator +(const B_Name &other, const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003BC7
B_Name operator +(const char *str, const B_Name &bName)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003C70
B_Name &B_Name::operator +=(const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003D30
B_Name &B_Name::operator+=(char c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003DCE
B_Name &B_Name::operator +=(const B_Name &other)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10003E91
void B_Name::UpCase()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10003EB0
B_ResourceManager *GetResourceManager()
{
    return &B_resource_manager;
}

// address: 0x10003EBA
B_Resource::B_Resource()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_100039E5();
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g10042198'

// address: 0x10003ED9
p10003ED9
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10003EFE
B_Resource::~B_Resource()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g10042198'

// address: 0x10003F26
p10003F26
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10003FCE
p10003FCE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000054h'

// address: 0x10004371
p10004371
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(16, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100043CB
p100043CB
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g100421DC'

// address: 0x10004406
p10004406
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+01Ch], 000000000h'

// address: 0x10004425
B_Resource *B_ResourceManager::sub_10004425(unsigned short resourceId, const B_Name &name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 00000402Ch'

// address: 0x100045B9
p100045B9
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10004606
p10004606
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10004676
p10004676
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000468E
p1000468E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100046A6
p100046A6
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1000470A
p1000470A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x10004874
p10004874
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100048EF
p100048EF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000494D
p1000494D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100049BB
p100049BB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100049F8
B_ResourceManager::B_ResourceManager()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10004A9B
B_ResourceManager::~B_ResourceManager()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10004AE0
void B_ResourceManager::Clean()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x10004C20
p10004C20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000400h]'

// address: 0x10004C37
p10004C37
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x10004C76
p10004C76
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10004E0B
unsigned int B_ResourceManager::LocateResourceIn(const B_Name &id, const B_Name *arg_2, int arg_3)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 0000040A0h'

// address: 0x10005533
p10005533
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000064h'

// address: 0x1000582E
unsigned int B_ResourceManager::AddAutoResource(const B_Name &arg_1, B_Resource *arg_2, int arg_3)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000048h'

// address: 0x10005AF0
B_Resource *B_ResourceManager::GetResource(unsigned short resourceId, const B_Name &name)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005B2F
p10005B2F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005B6F
p10005B6F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005BB2
p10005BB2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10005C13
p10005C13
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 000004024h'

// address: 0x10005CCD
int B_ResourceManager::IsResourceLoaded(int arg_1, int arg_2)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005D06
p10005D06
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10005DAE
p10005DAE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10005E42
p10005E42
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005E8F
p10005E8F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005ED1
void B_ResourceManager::FreeResource(B_Resource *resource)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x10005F32
unsigned int B_ResourceManager::NResources(unsigned short arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 00000FFFFh'

// address: 0x10005F66
void B_ResourceManager::AddBodLink(const char *c, int i, const char *pc, int i1)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x1000617B
p1000617B
{
    unknown_function_1000618A();
    unknown_function_10006199();
}

// address: 0x1000618A
p1000618A
{
    return B_resource_manager.B_ResourceManager();
}

// address: 0x10006199
p10006199
{
    unknown_function_100415A8(GLOBAL(0x100061AB));
}

// address: 0x100061AB
p100061AB
{
    B_resource_manager.~B_ResourceManager();
}

// address: 0x100061BA
p100061BA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100061F0
p100061F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10006230
p10006230
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10006266
p10006266
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000629C
p1000629C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 00000402Ch'

// address: 0x1000644A
p1000644A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 000004048h'

// address: 0x1000660B
p1000660B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10006620
p10006620
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10006635
p10006635
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000664A
p1000664A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000665F
p1000665F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10006680
p10006680
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_100043CB();
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 000000001h'

// address: 0x100066B0
p100066B0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1000470A();
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 000000001h'

// address: 0x100066E0
B_Resource::B_Resource(const B_Resource &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10006720
B_Resource &B_Resource::operator=(const B_Resource &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10006780
p10006780
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10006830
B_ResourceManager &B_ResourceManager::operator =(const B_ResourceManager &that)
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10006860
B_Color::B_Color()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov byte ptr [eax+004h], 000h'

// address: 0x10006890
B_Color::B_Color(unknown_byte r, unknown_byte g, unknown_byte b)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov cl, byte ptr [ebp+008h]'

// address: 0x100068D0
B_Color B_Color::operator +(const B_Color &color)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10006950
B_Color B_Color::operator *(float coef)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100069E0
B_Color B_Color::operator /(float f)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10006A70
p10006A70
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10006AD0
p10006AD0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10006B30
p10006B30
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov cl, byte ptr [ebp+008h]'

// address: 0x10006B60
B_Color::B_Color(const B_Color &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dl, byte ptr [ecx+004h]'

// address: 0x10006BA0
B_Color &B_Color::operator =(const B_Color &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dl, byte ptr [ecx+004h]'

// address: 0x10006BE0
p10006BE0
{
    REGDEF(eax=this)
}

// address: 0x10006BF0
p10006BF0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10006C20
B_BitMap &B_BitMap::operator=(const B_BitMap &that)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x10006C70
p10006C70
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'add ecx, 00000000Ch'

// address: 0x10006CB0
B_BitMap24::B_BitMap24(int width, int height)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10006E20
p10006E20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10006E70
B_BitMap24::~B_BitMap24()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x10007090
p10007090
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+004h]'

// address: 0x100070C0
p100070C0
{
    REGDEF(eax=ACCESS(this, 12, 4))
}

// address: 0x100070E0
p100070E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10007470
p10007470
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000004Ch'

// address: 0x10007790
p10007790
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x100079D0
p100079D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10007C10
p10007C10
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10007D30
p10007D30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10007EF0
B_RDataLight &B_RDataLight::operator=(const B_RDataLight &other)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov edx, dword ptr [eax]'

// address: 0x10007F20
p10007F20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10007F40
B_RDataTriangle &B_RDataTriangle::operator=(const B_RDataTriangle &other)
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10007F70
B_MeshEdge &B_MeshEdge::operator=(const B_MeshEdge &other)
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10007FA0
p10007FA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10008080
p10008080
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10008160
p10008160
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10008260
p10008260
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10008374
p10008374
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov ax, 00002h'

// address: 0x10008383
p10008383
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10008483
p10008483
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100084D6
p100084D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000000Ch'

// address: 0x100084FB
p100084FB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000000Ch'

// address: 0x10008554
p10008554
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov ax, 00003h'

// address: 0x10008563
p10008563
{
    REGDEF(eax=0x00000000)
}

// address: 0x10008570
p10008570
{
    REGDEF(eax=0x00000000)
}

// address: 0x10008595
p10008595
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000000Ch'

// address: 0x100085AD
p100085AD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov ax, 00004h'

// address: 0x100085D4
p100085D4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000000Ch'

// address: 0x100085F0
p100085F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10008639
B_BitMap::B_BitMap(int type, unsigned int arg_2, unsigned int arg_3, const B_Pal *pal)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100086E3
B_BitMap::B_BitMap(const B_BitMap &src)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x10008974
p10008974
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10008AF0
p10008AF0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10008B51
B_ODataFile &operator <<(B_ODataFile &file, const B_BitMap &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10008C9B
B_IDataFile &operator >>(B_IDataFile &file, B_BitMap &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10008FDA
B_BitMap::~B_BitMap()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10009060
p10009060
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10009110
p10009110
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100091A4
B_IDataFile &operator >>(B_IDataFile &file, B_Color &color)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000006h'

// address: 0x100091DF
B_ODataFile &operator <<(B_ODataFile &file, const B_Color &color)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000006h'

// address: 0x1000921A
void B_Color::MakeCons()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x100093A7
p100093A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x100093C8
unsigned char B_Pal::GetRed(unsigned int val)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x100093E1
unsigned char B_Pal::GetGreen(unsigned int val)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x100093FB
unsigned char B_Pal::GetBlue(unsigned int val)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x10009415
p10009415
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x10009431
p10009431
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x1000944E
p1000944E
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'imul eax, eax, 000000003h'

// address: 0x1000946B
p1000946B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10009633
p10009633
{
    REGDEF(eax=this)
}

// address: 0x10009661
p10009661
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000300h'

// address: 0x1000967A
p1000967A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000300h'

// address: 0x100096A0
p100096A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000980C
p1000980C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000982E
p1000982E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100098C9
p100098C9
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 000000065h'

// address: 0x10009C20
p10009C20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 000000064h'

// address: 0x10009CD5
p10009CD5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10009F40
p10009F40
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1000A05E
p1000A05E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000A14E
p1000A14E
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000144h]'

// address: 0x1000A1C8
p1000A1C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x1000A47B
p1000A47B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x1000A72E
p1000A72E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x1000A930
p1000A930
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000ACCF
p1000ACCF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000ADE0
p1000ADE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1000AF44
p1000AF44
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x1000B01F
p1000B01F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1000B1B5
p1000B1B5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1000B23C
p1000B23C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1000B2ED
p1000B2ED
{
}

// address: 0x1000B300
p1000B300
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000B3E7
p1000B3E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1000B67F
p1000B67F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000012Ch'

// address: 0x1000BA22
p1000BA22
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000148h'

// address: 0x1000BD80
p1000BD80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000530h'

// address: 0x1000C0BE
p1000C0BE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000844h'

// address: 0x1000C580
p1000C580
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000C607
p1000C607
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1000C80D
p1000C80D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x1000C9AC
p1000C9AC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1000CC15
p1000CC15
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000CD6C
p1000CD6C
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+020h]'

// address: 0x1000CDB5
p1000CDB5
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000CEA5
p1000CEA5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000007h'

// address: 0x1000CEDD
p1000CEDD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x1000CF7A
p1000CF7A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1000D08D
p1000D08D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1000D205
p1000D205
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1000D320
p1000D320
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000000h'

// address: 0x1000D450
p1000D450
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000D523
p1000D523
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000D5A2
p1000D5A2
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+00000013Ch]'

// address: 0x1000D6A0
p1000D6A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000020h'

// address: 0x1000D719
p1000D719
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+010h], 00000FFFDh'

// address: 0x1000D764
p1000D764
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 0000000FFh'

// address: 0x1000D78A
p1000D78A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+018h]'

// address: 0x1000D7FA
p1000D7FA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'sar eax, 008h'

// address: 0x1000D82D
p1000D82D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000D842
p1000D842
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000148h]'

// address: 0x1000D8A7
p1000D8A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 0000000E0h'

// address: 0x1000D9A7
p1000D9A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 0000000EEh'

// address: 0x1000DA83
p1000DA83
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1000DBFF
p1000DBFF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1000DD3E
p1000DD3E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000DE6D
p1000DE6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000DF93
p1000DF93
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000E0E2
p1000E0E2
{
}

// address: 0x1000E0E7
p1000E0E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 0000000DDh'

// address: 0x1000E121
p1000E121
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1000E27A
p1000E27A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 0000000D9h'

// address: 0x1000E290
p1000E290
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 0000000D8h'

// address: 0x1000E360
p1000E360
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000020h'

// address: 0x1000E487
p1000E487
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1000E7C0
p1000E7C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000A38h'

// address: 0x1000EDE2
p1000EDE2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000F076
p1000F076
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000F1FC
p1000F1FC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1000F4DE
p1000F4DE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000138h]'

// address: 0x1000F516
p1000F516
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000F5D0
p1000F5D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+004h], 000000000h'

// address: 0x1000F640
p1000F640
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+004h], 000000000h'

// address: 0x1000F672
p1000F672
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000082h'

// address: 0x1000F6A0
p1000F6A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000112h'

// address: 0x1000F6D0
p1000F6D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1000F7ED
p1000F7ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov al, byte ptr [ebp+010h]'

// address: 0x1000F828
p1000F828
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x1000F86D
p1000F86D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1000F895
p1000F895
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 000000064h'

// address: 0x1000FA22
p1000FA22
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ARG(GLOBAL(0x100424E8));
    ARG(GLOBAL(0x100424D4));
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000054h'

// address: 0x1000FA9B
p1000FA9B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1000FB6A
p1000FB6A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+028h]'

// address: 0x1000FC1D
p1000FC1D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100104D2
p100104D2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 0, 4) = 0x00000001;
    REGDEF(ecx=STACKVAR(8, 4), edx=STACKVAR(12, 4))
}
Failed to find pattern for 'mov dword ptr [ecx+004h], edx'

// address: 0x10010519
p10010519
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov dword ptr [ebp-004h], 000000000h'

// address: 0x1001057F
p1001057F
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+00Ch], 000000004h'

// address: 0x10010620
p10010620
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10010695
p10010695
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100108CB
p100108CB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10010AB0
p10010AB0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10010C02
p10010C02
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+020h]'

// address: 0x10010C69
p10010C69
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=0x00000000)
}
Failed to find pattern for 'mov cl, byte ptr [eax+00Ch]'

// address: 0x10010CD3
p10010CD3
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10010DDB
p10010DDB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000007h'

// address: 0x10010E04
p10010E04
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10010ED2
p10010ED2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=0x00000000)
}
Failed to find pattern for 'mov cl, byte ptr [eax+00Ch]'

// address: 0x10010F14
p10010F14
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x1001117B
p1001117B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100112A0
p100112A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000128h'

// address: 0x10011641
p10011641
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000158h]'

// address: 0x100116A7
p100116A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100117C0
p100117C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100118C1
p100118C1
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000140h]'

// address: 0x10011926
p10011926
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10011B35
p10011B35
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = STACKVAR(16, 4);
}
Failed to find pattern for 'jmp l10011B4A'

// address: 0x10011B79
p10011B79
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10011DDE
p10011DDE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10011F30
p10011F30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10012153
p10012153
{
}

// address: 0x10012158
p10012158
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100121E7
p100121E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10012353
p10012353
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100123CA
p100123CA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+01Ch]'

// address: 0x1001241B
p1001241B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100124E9
p100124E9
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x100125F5
p100125F5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x100129B4
p100129B4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10012FCC
p10012FCC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dword ptr [eax+024h], 000000001h'

// address: 0x1001307B
p1001307B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1001311D
p1001311D
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000144h]'

// address: 0x10013167
p10013167
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000144h]'

// address: 0x100131E1
p100131E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000070h'

// address: 0x10013490
p10013490
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10013602
p10013602
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10013624
p10013624
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100136D7
p100136D7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100137E3
p100137E3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10013B69
p10013B69
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 0000000CDh'

// address: 0x10013C80
p10013C80
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 0000000CAh'

// address: 0x10013DDE
p10013DDE
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 0000000CCh'

// address: 0x10013EFA
p10013EFA
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+014h], 0000000CDh'

// address: 0x10014240
p10014240
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+018h], 000000000h'

// address: 0x1001429A
p1001429A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+018h]'

// address: 0x100142DC
p100142DC
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+018h]'

// address: 0x10014343
p10014343
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100143E0
p100143E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+018h], 000000000h'

// address: 0x10014486
p10014486
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+018h]'

// address: 0x1001449E
p1001449E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10014552
p10014552
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+018h]'

// address: 0x100145AA
p100145AA
{
}

// address: 0x100145B0
p100145B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1001473B
p1001473B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dword ptr [eax+000000080h], 000000000h'

// address: 0x10014759
p10014759
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000188h]'

// address: 0x100147D6
p100147D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000188h]'

// address: 0x10014837
p10014837
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x10014AED
p10014AED
{
    REGDEF(eax=0x00000000)
}

// address: 0x10014AF4
p10014AF4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10014D2D
p10014D2D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x10014F46
p10014F46
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x100150C1
p100150C1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000011Ch'

// address: 0x10015B20
p10015B20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10015DFC
p10015DFC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10015F1D
p10015F1D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000003Ch'

// address: 0x10016072
p10016072
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10016126
p10016126
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+05Ch]'

// address: 0x1001614E
p1001614E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100161E7
p100161E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x1001636E
p1001636E
{
}

// address: 0x10016380
p10016380
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10016424
p10016424
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x10016730
p10016730
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000538h'

// address: 0x10016BF7
p10016BF7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10016DB2
p10016DB2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10016F06
p10016F06
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10016F7E
p10016F7E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10017160
p10017160
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000070h'

// address: 0x10017795
p10017795
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10017860
p10017860
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000018h'

// address: 0x100178C6
p100178C6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1001791E
p1001791E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10017BC0
p10017BC0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10017C97
p10017C97
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000190h]'

// address: 0x10017CAB
p10017CAB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10017DBD
p10017DBD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100180D6
p100180D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000190h]'

// address: 0x10018140
p10018140
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10018280
p10018280
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10018398
p10018398
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1001844D
p1001844D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x100185CF
p100185CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10018671
p10018671
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10018845
p10018845
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1001897D
p1001897D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x10018A6D
p10018A6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(20, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10018AA0
p10018AA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10018C16
p10018C16
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10018E36
p10018E36
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10018EEC
p10018EEC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x10019118
p10019118
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100194DC
p100194DC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1001962B
p1001962B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10019770
p10019770
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Can't parse line: ;

// address: 0x10019BF8
p10019BF8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10019D0E
p10019D0E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x1001A32B
p1001A32B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1001A86C
p1001A86C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000013Ch'

// address: 0x1001AF2C
p1001AF2C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x1001B3A6
p1001B3A6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1001B595
p1001B595
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1001B6C6
p1001B6C6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+00000017Ch], 000000000h'

// address: 0x1001B79A
p1001B79A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000194h]'

// address: 0x1001B8FD
p1001B8FD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1001BD40
p1001BD40
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1001C089
p1001C089
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=0x00000000)
}
Failed to find pattern for 'mov cl, byte ptr [eax+048h]'

// address: 0x1001C23B
p1001C23B
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 00000001Ch'

// address: 0x1001C28B
p1001C28B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1001C61D
p1001C61D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1001C6F1
p1001C6F1
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000180h]'

// address: 0x1001C912
p1001C912
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+000000180h]'

// address: 0x1001C960
p1001C960
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000030h'

// address: 0x1001CA18
p1001CA18
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1001CB39
p1001CB39
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+0000001A0h]'

// address: 0x1001CB60
p1001CB60
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1001CC76
p1001CC76
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+0000001A0h]'

// address: 0x1001CCC7
p1001CCC7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000044h'

// address: 0x1001CEF2
p1001CEF2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000004Ch'

// address: 0x1001D220
p1001D220
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1001D2FB
p1001D2FB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1001D69E
p1001D69E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000060h'

// address: 0x1001D97A
p1001D97A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1001DA41
p1001DA41
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000004Ch'

// address: 0x1001DDAD
p1001DDAD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1001DEFE
p1001DEFE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000158h'

// address: 0x1001E580
p1001E580
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 00000001Ch'

// address: 0x1001E668
p1001E668
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1001E788
p1001E788
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1001E829
p1001E829
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1001E926
p1001E926
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1001EA30
p1001EA30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x1001ED04
p1001ED04
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+0000001A0h]'

// address: 0x1001ED33
p1001ED33
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1001EE8E
p1001EE8E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(20, 4), ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'mov dword ptr [eax], ecx'

// address: 0x1001EE9B
p1001EE9B
{
    ACCESS(STACKVAR(20, 4), 0, 4) = 0x00000000;
}

// address: 0x1001EEA9
p1001EEA9
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1001EFBF
p1001EFBF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1001F054
p1001F054
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1001F121
p1001F121
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1001F26C
p1001F26C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1001F5B0
p1001F5B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov byte ptr [eax+040h], 001h'

// address: 0x1001F6E0
p1001F6E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset l1001F76C'

// address: 0x1001F76C
p1001F76C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1001F794
p1001F794
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000C8h'

// address: 0x1001F7D6
p1001F7D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x1001F834
p1001F834
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1001F977
p1001F977
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x1001F9A0
p1001F9A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000054h'

// address: 0x1001FD10
p1001FD10
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000054h'

// address: 0x100200A0
p100200A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000004Ch'

// address: 0x10020550
p10020550
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000184h'

// address: 0x10020C70
p10020C70
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000164h'

// address: 0x10021410
p10021410
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000154h'

// address: 0x10021D80
p10021D80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000C0h'

// address: 0x100222BF
p100222BF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000006Ch'

// address: 0x1002257C
p1002257C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100225E0
p100225E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100227DF
p100227DF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100229A5
p100229A5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x100229CF
p100229CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10022AC1
p10022AC1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x10022BC2
p10022BC2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x10022CD7
p10022CD7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10022D76
p10022D76
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10022E15
p10022E15
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x100230E4
p100230E4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100232EE
p100232EE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x1002343B
p1002343B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10023648
p10023648
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10023798
p10023798
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1002394E
p1002394E
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov dword ptr [ebp-004h], 000000001h'

// address: 0x100239B0
p100239B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100239C2
p100239C2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100239D4
p100239D4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100239E6
p100239E6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x100239F8
p100239F8
{
    REGDEF(eax=STACKVAR(16, 4))
}

// address: 0x10023A00
p10023A00
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10023A1F
p10023A1F
{
    REGDEF(eax=0x00000000)
}

// address: 0x10023A26
p10023A26
{
}

// address: 0x10023A30
p10023A30
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000058h'

// address: 0x10023B19
p10023B19
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x10023CDA
p10023CDA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10023E52
p10023E52
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'imul ecx, ecx, 0000000FFh'

// address: 0x10023E6E
p10023E6E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10024015
p10024015
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(16, 4))
}
Failed to find pattern for 'lea eax, [eax+eax+001h]'

// address: 0x10024032
p10024032
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10024094
p10024094
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100241EA
p100241EA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10024296
p10024296
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10024357
p10024357
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10024436
p10024436
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10024538
p10024538
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x10024677
p10024677
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000003Ch'

// address: 0x100247FF
p100247FF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000050h'

// address: 0x10024A44
p10024A44
{
}

// address: 0x10024A49
p10024A49
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax]'

// address: 0x10024A70
p10024A70
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10024C3A
p10024C3A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10024D38
p10024D38
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10024ED3
p10024ED3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10024FA9
p10024FA9
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x100250C5
p100250C5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000001ACh'

// address: 0x100252A3
p100252A3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000438h'

// address: 0x100257D0
p100257D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000240h'

// address: 0x10025A2F
p10025A2F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000070h'

// address: 0x10025E00
p10025E00
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+0000001A8h]'

// address: 0x10025E3A
p10025E3A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10025F35
p10025F35
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000040h'

// address: 0x1002642C
p1002642C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10026606
p10026606
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1002666F
p1002666F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100266CF
p100266CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000044h'

// address: 0x10026874
p10026874
{
}

// address: 0x10026879
p10026879
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+0000001A8h]'

// address: 0x100268A0
p100268A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'lea eax, [ecx+eax-001h]'

// address: 0x100268B3
p100268B3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'lea edx, [ecx+eax-001h]'

// address: 0x100268D1
p100268D1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1002694F
p1002694F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x10026972
p10026972
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push edi'

// address: 0x10026990
p10026990
{
    unknown_function_1002699F();
    unknown_function_100269E0();
}

// address: 0x1002699F
p1002699F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A524), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A528), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A52C), 0, 4) = 0x00000010;
    ACCESS(GLOBAL(0x1004A530), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A534), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [g1004A520], offset g10042CB8'

// address: 0x100269E0
p100269E0
{
    unknown_function_100415A8(GLOBAL(0x100269F2));
}

// address: 0x100269F2
p100269F2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10026AD5
B_BitMap24::B_BitMap24(const B_BitMap24 &that)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10026C70
void B_BitMap24::SetBits(int arg_1, int arg_2, const char *arg_3, const char *arg_4)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x10026D6D
p10026D6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000048h'

// address: 0x100271BE
B_BitMap24 &B_BitMap24::operator=(const B_BitMap24 &that)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100272A5
p100272A5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10027382
int B_BitMap24::SaveToBMP(const char *fileName)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 000004084h'

// address: 0x1002778F
int B_BitMap24::SaveToBMPSized(const char *fileName, int width, int height)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 0000040ACh'

// address: 0x10027D86
p10027D86
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov eax, 000004024h'

// address: 0x10027E11
p10027E11
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x10027F15
int B_BitMap24::SaveToFile(const char *arg_1, int arg_2)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x10028021
B_IDataFile &operator >>(B_IDataFile &file, B_BitMap24 &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100280CC
B_ODataFile &operator <<(B_ODataFile &file, const B_BitMap24 &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000064h'

// address: 0x10028353
void B_BitMap24::EscribeArchivoRAW(const char *arg_1)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100283CD
p100283CD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10028434
p10028434
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100284C0
p100284C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100285A0
p100285A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000000Ch'

// address: 0x100285F5
p100285F5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100289E4
p100289E4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000002h'

// address: 0x10028A19
p10028A19
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000038h'

// address: 0x10029170
p10029170
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10029217
p10029217
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000090h'

// address: 0x10029510
p10029510
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000244h'

// address: 0x10029700
int B_BitMap24::SaveToJPEG(const char *arg_1, int arg_2)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000001FCh'

// address: 0x100298B0
p100298B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1002994D
p1002994D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x100299E1
p100299E1
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+010h], 000000000h'

// address: 0x10029A08
p10029A08
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+00Ch], 000000001h'

// address: 0x10029A22
p10029A22
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [eax+00Ch], 000000000h'

// address: 0x10029A60
p10029A60
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10029AC0
p10029AC0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'add eax, 000000004h'

// address: 0x10029B30
p10029B30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10029BE0
char *vararg(const char *format)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10029C15
p10029C15
{
    unknown_function_10029C24();
    unknown_function_10029C33();
}

// address: 0x10029C24
p10029C24
{
    mout.unknown_method_10029C4A();
}

// address: 0x10029C33
p10029C33
{
    unknown_function_100415A8(GLOBAL(0x10029C45));
}

// address: 0x10029C45
p10029C45
{
}

// address: 0x10029C4A
p10029C4A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10029CFC
unsigned int B_MessageManager::Add(B_MessageChannel *channel)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10029E17
unsigned int B_MessageManager::OpenChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10029E98
unsigned int B_MessageManager::CloseChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10029F19
B_MessageChannel *B_MessageManager::DisconnectChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x1002A13C
p1002A13C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1002A1B9
p1002A1B9
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1002A23E
p1002A23E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1002A26A
unsigned int B_MessageChannel::Open()
{
    return 0;
}

// address: 0x1002A277
unsigned int B_MessageChannel::Close()
{
    return 0;
}

// address: 0x1002A284
unsigned int B_MessageChannel::Message(const char *message)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=0x00000000)
    RESTORE(esp);
}
Failed to find pattern for 'pop ebp'

// address: 0x1002A293
p1002A293
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1002A2C3
B_MessageManager &operator<<(B_MessageManager &mout, const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x1002A2D7
p1002A2D7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'mov al, byte ptr [ebp+00Ch]'

// address: 0x1002A2F0
p1002A2F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1002A3D0
p1002A3D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1002A4B0
p1002A4B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1002A590
void OutputWin32Error(const char *message)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1002A5F0
p1002A5F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1002A7F2
p1002A7F2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000018h'

// address: 0x1002A81A
p1002A81A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000018h'

// address: 0x1002DEF0
p1002DEF0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1002DF30
p1002DF30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1002E0B0
p1002E0B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x1002E0F0
p1002E0F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1002E190
p1002E190
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 03FF00000h'

// address: 0x1002E2AD
p1002E2AD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dword ptr [eax], ecx'

// address: 0x1002E600
p1002E600
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1002ED7C
p1002ED7C
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x1002EDB2
p1002EDB2
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [eax+020h]'

// address: 0x1002EDEA
p1002EDEA
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [eax+040h]'

// address: 0x1002EF9F
p1002EF9F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1002F052
p1002F052
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000054h'

// address: 0x1002F159
p1002F159
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000D4h'

// address: 0x1002F537
p1002F537
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000080h'

// address: 0x1002FEB3
p1002FEB3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100300A1
p100300A1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10030219
p10030219
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000080h'

// address: 0x10030232
p10030232
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000080h'

// address: 0x10031284
p10031284
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x100312FC
p100312FC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10031430
p10031430
{
    unknown_function_1003143A();
}

// address: 0x1003143A
p1003143A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A960), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A964), 0, 4) = 0x3FF00000;
    ACCESS(GLOBAL(0x1004A968), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10031477
p10031477
{
    unknown_function_10031481();
}

// address: 0x10031481
p10031481
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A948), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A94C), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A950), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 03FF00000h'

// address: 0x100314BE
p100314BE
{
    unknown_function_100314C8();
}

// address: 0x100314C8
p100314C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A978), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A97C), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A980), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10031505
p10031505
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10031561
p10031561
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100315C2
p100315C2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10031623
p10031623
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [ebp+008h]'

// address: 0x1003165E
p1003165E
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x100316F7
p100316F7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10031760
p10031760
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100317C9
p100317C9
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x1003184F
p1003184F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x10031882
p10031882
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x10031913
p10031913
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x10031E6D
p10031E6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000018h'

// address: 0x10031E83
p10031E83
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'push 000000018h'

// address: 0x10031EA0
p10031EA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10031F20
p10031F20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10031F48
p10031F48
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'push eax'

// address: 0x10031F82
p10031F82
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10032003
p10032003
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x100321A0
p100321A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000018h'

// address: 0x100321C8
p100321C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000018h'

// address: 0x100321F0
B_MeshEdge::B_MeshEdge()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003221C
B_MeshEdge::B_MeshEdge(unsigned int a, unsigned int b, unsigned int c)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003227E
unsigned int B_MeshEdge::operator==(const B_MeshEdge &other)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100322BC
p100322BC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000014h'

// address: 0x10032314
p10032314
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000014h'

// address: 0x1003236C
p1003236C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000034h'

// address: 0x10032420
p10032420
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000034h'

// address: 0x100324B4
p100324B4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000024h'

// address: 0x100324EC
p100324EC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000024h'

// address: 0x10032524
p10032524
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1003270D
p1003270D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100327E1
p100327E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000020h'

// address: 0x10032829
p10032829
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000020h'

// address: 0x10032871
p10032871
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000008Ch'

// address: 0x100328B6
p100328B6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 00000008Ch'

// address: 0x100328ED
p100328ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000040h'

// address: 0x10032945
p10032945
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000040h'

// address: 0x1003299D
p1003299D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000028h'

// address: 0x100329E5
p100329E5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000028h'

// address: 0x10032A2D
p10032A2D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000028h'

// address: 0x10032A75
p10032A75
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'add eax, 000000028h'

// address: 0x10032ABD
p10032ABD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov ax, 00001h'

// address: 0x10032ACC
p10032ACC
{
    REGDEF(eax=0x00000000)
}

// address: 0x10032AD9
p10032AD9
{
    REGDEF(eax=0x00000000)
}

// address: 0x10032AE6
void B_ObjDscr::SetUpNormals()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000288h'

// address: 0x100335C3
void B_ObjDscr::SetUpInertialT()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000002A8h'

// address: 0x100342BD
int B_ObjDscr::GetVtxNode(unsigned int arg_1)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10034345
p10034345
{
    unknown_function_10034354();
    unknown_function_1003438B();
}

// address: 0x10034354
p10034354
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A994), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A998), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A99C), 0, 4) = 0x00000080;
    ACCESS(GLOBAL(0x1004A9A0), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [g1004A990], offset g10042D78'

// address: 0x1003438B
p1003438B
{
    unknown_function_100415A8(GLOBAL(0x1003439D));
}

// address: 0x1003439D
p1003439D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003440F
p1003440F
{
    unknown_function_1003441E();
    unknown_function_10034455();
}

// address: 0x1003441E
p1003441E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A9AC), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9B0), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9B4), 0, 4) = 0x00000080;
    ACCESS(GLOBAL(0x1004A9B8), 0, 4) = 0x00000000;
}
Failed to find pattern for 'mov dword ptr [g1004A9A8], offset g10042D7C'

// address: 0x10034455
p10034455
{
    unknown_function_100415A8(GLOBAL(0x10034467));
}

// address: 0x10034467
p10034467
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov dword ptr [g1004A9A8], offset g10042D7C'

// address: 0x100344BF
p100344BF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000C0h'

// address: 0x10034A8A
void B_ObjDscr::SetUpEdges()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000090h'

// address: 0x10034D5A
void B_ObjDscr::Draw(B_3DRasterDevice *raster, float x1, float y1, float x2, float y2, float scale, int i_unknown)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000048Ch'

// address: 0x1003590B
p1003590B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000002C4h'

// address: 0x100369F0
p100369F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000068h'

// address: 0x10036E0D
void B_ObjDscr::SetUpBSP()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000A8h'

// address: 0x100371B3
p100371B3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x10037338
p10037338
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 8, 4), edx=0x00000000)
}
Failed to find pattern for 'mov ecx, 000000003h'

// address: 0x1003737B
p1003737B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000001E0h'

// address: 0x10037E84
unsigned char B_ObjDscr::EdgeFaceGrp(unsigned int arg_1)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10037EF5
B_ObjDscr::B_ObjDscr()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000003Ch'

// address: 0x1003819B
B_ObjDscr::~B_ObjDscr()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000064h'

// address: 0x100384CA
p100384CA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000064h'

// address: 0x1003896F
p1003896F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000014Ch'

// address: 0x100395E0
p100395E0
{
}
Can't parse line: ;

// address: 0x10039610
p10039610
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039670
p10039670
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10039750
p10039750
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100397F0
p100397F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g1004217C'

// address: 0x10039830
p10039830
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100398B0
p100398B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10039960
p10039960
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1003819B();
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 000000001h'

// address: 0x10039990
p10039990
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039A10
p10039A10
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039A90
p10039A90
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039B10
p10039B10
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039B90
p10039B90
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039C10
p10039C10
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x10039D30
p10039D30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10039D90
p10039D90
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x10039EA0
p10039EA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10039F20
p10039F20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x10039F60
p10039F60
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003A010
p1003A010
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003A050
p1003A050
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1003A160
p1003A160
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003A1A0
p1003A1A0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003A1E0
p1003A1E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003A240
p1003A240
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003A360
p1003A360
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003A3C0
p1003A3C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003A4E0
p1003A4E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003A560
p1003A560
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003A630
p1003A630
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003A700
p1003A700
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003A780
p1003A780
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003A800
p1003A800
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003A8E0
p1003A8E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003A9C0
p1003A9C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003AA40
p1003AA40
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003AAC0
p1003AAC0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003ABA0
p1003ABA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003AC80
p1003AC80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003AD00
p1003AD00
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003ADE0
p1003ADE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003AEC0
p1003AEC0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1003B070
p1003B070
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003B140
p1003B140
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1003B2F0
p1003B2F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003B3D0
p1003B3D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003B4B0
p1003B4B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003B590
p1003B590
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003B670
p1003B670
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003B6F0
p1003B6F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1003B780
p1003B780
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push esi'

// address: 0x1003B7C0
p1003B7C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003B840
p1003B840
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1003B8D0
p1003B8D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003B920
p1003B920
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003B980
p1003B980
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003B9D0
p1003B9D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003BA20
p1003BA20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003BA80
p1003BA80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003BB30
p1003BB30
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003BB80
p1003BB80
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003BBE0
p1003BBE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003BC90
p1003BC90
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003BCE0
p1003BCE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1003BE50
p1003BE50
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003BEB0
p1003BEB0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003BF60
p1003BF60
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003BFC0
p1003BFC0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003C070
p1003C070
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C150
p1003C150
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C230
p1003C230
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C310
p1003C310
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C3F0
p1003C3F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C4D0
p1003C4D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C5B0
p1003C5B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C690
p1003C690
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C770
p1003C770
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C850
p1003C850
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003C930
p1003C930
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000003Ch'

// address: 0x1003CBD0
p1003CBD0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000024h'

// address: 0x1003CD80
p1003CD80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1003CFD0
p1003CFD0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1003D1F0
p1003D1F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003D2E0
p1003D2E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003D3D0
p1003D3D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000002Ch'

// address: 0x1003D5F0
p1003D5F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1003D740
p1003D740
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003D7C0
p1003D7C0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_100039E5();
    REGDEF(ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'add ecx, 00000000Ch'

// address: 0x1003D7F0
p1003D7F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003D890
p1003D890
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g1004217C'

// address: 0x1003D8D0
p1003D8D0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g1004217C'

// address: 0x1003D910
p1003D910
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g1004217C'

// address: 0x1003D950
p1003D950
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax+004h], 000000000h'

// address: 0x1003D9B0
p1003D9B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003DA80
p1003DA80
{
    unknown_function_1003DA8F();
    unknown_function_1003DAEE();
}

// address: 0x1003DA8F
p1003DA8F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(GLOBAL(0x1004A9D4), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9D8), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9DC), 0, 4) = 0x00000010;
    ACCESS(GLOBAL(0x1004A9E0), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9E4), 0, 4) = 0x00000001;
}
Failed to find pattern for 'mov dword ptr [g1004A9D0], offset g10042E58'

// address: 0x1003DAEE
p1003DAEE
{
    unknown_function_100415A8(GLOBAL(0x1003DB00));
}

// address: 0x1003DB00
p1003DB00
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003DBC0
B_ElementCSV::~B_ElementCSV()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4))
}
Failed to find pattern for 'mov dword ptr [eax], offset g10042E5C'

// address: 0x1003DBF3
unsigned int ReadCSV(const char *file_name, B_NDataBase<B_ElementCSV> *csvs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000344h'

// address: 0x1003DED0
p1003DED0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1003DBC0();
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 000000001h'

// address: 0x1003DF00
p1003DF00
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003DFE0
p1003DFE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003E0C0
p1003E0C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003E1A0
p1003E1A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003E280
p1003E280
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003E436
PyObject *CallPythonObject(PyObject *func, PyObject *args)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003E660
p1003E660
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
}
Can't parse line: ;

// address: 0x1003E679
p1003E679
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov dword ptr [ebp-004h], 000000000h'

// address: 0x1003E710
p1003E710
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000098h'

// address: 0x1003E831
p1003E831
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000098h'

// address: 0x1003E95C
p1003E95C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003E9A6
p1003E9A6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003E9F0
p1003E9F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
}
Can't parse line: ;

// address: 0x1003EA3C
p1003EA3C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1003EAB8
p1003EAB8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
}
Can't parse line: ;

// address: 0x1003EB04
p1003EB04
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003EB59
p1003EB59
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003EBAE
p1003EBAE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003EC03
p1003EC03
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003EC58
p1003EC58
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003ECAD
p1003ECAD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003ED02
p1003ED02
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003ED57
p1003ED57
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1003EDAC
p1003EDAC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1003EE09
p1003EE09
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003EE53
p1003EE53
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003EE9D
p1003EE9D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000088h'

// address: 0x1003EF05
p1003EF05
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000020h'

// address: 0x1003EFD4
p1003EFD4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 0000000B8h'

// address: 0x1003F24C
p1003F24C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1003F305
p1003F305
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000174h'

// address: 0x1003FA24
p1003FA24
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x1003FA98
p1003FA98
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003FAC8
p1003FAC8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000028h'

// address: 0x1003FBCD
p1003FBCD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x1003FCF4
p1003FCF4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x1003FD8A
p1003FD8A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'cmp dword ptr [ebp+008h], 000000000h'

// address: 0x1003FDA8
p1003FDA8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003FE79
p1003FE79
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003FF12
p1003FF12
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1003FFAB
p1003FFAB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10040054
p10040054
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100400ED
p100400ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10040186
p10040186
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x1004022F
p1004022F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100402C4
p100402C4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x1004035E
p1004035E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10040401
p10040401
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x100404A4
p100404A4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10040546
p10040546
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000001Ch'

// address: 0x100405F1
p100405F1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000018h'

// address: 0x10040694
p10040694
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000010h'

// address: 0x10040726
p10040726
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x100407BF
p100407BF
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x100409D8
p100409D8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Failed to find pattern for 'mov dword ptr [ebp-004h], 000000000h'

// address: 0x10040A5E
p10040A5E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x10040CB0
B_RDataLight::B_RDataLight()
{
}

// address: 0x10040CBE
B_RDataLight::B_RDataLight(float a, float b, float c, float d)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    STACKVAR(12, 4) = STACKVAR(12, 4);
    STACKVAR(16, 4) = STACKVAR(16, 4);
    STACKVAR(20, 4) = STACKVAR(20, 4);
    REGDEF(eax=STACKVAR(-4, 4))
    RESTORE(esp);
}
Failed to find pattern for 'pop ebp'

// address: 0x10040CE6
void B_RDataLight::Interp(double t, B_RDataLight &start, double u, B_RDataLight &end)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(16, 4))
}
Failed to find pattern for 'fld dword ptr [eax]'

// address: 0x10040D58
p10040D58
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x10040E61
p10040E61
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000014h'

// address: 0x10040F39
p10040F39
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=STACKVAR(-4, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov dword ptr [eax], ecx'

// address: 0x10040F51
B_RDataTriangle::B_RDataTriangle()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
}
Failed to find pattern for 'push 000000001h'

// address: 0x10040F69
B_ParticleGType::B_ParticleGType(const B_Name &new_type, const B_Name &parent_type, unsigned int operation_type, unsigned int duration)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000030h'

// address: 0x1004118F
B_ParticleGType::~B_ParticleGType()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x1004122B
B_IDataFile &operator >>(B_IDataFile &file, B_ParticleGType &particleType)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000034h'

// address: 0x100413EE
B_ODataFile &operator <<(B_ODataFile &file, const B_ParticleGType &particleType)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 00000000Ch'

// address: 0x100414A0
p100414A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
}
Failed to find pattern for 'sub esp, 000000008h'

// address: 0x10041520
p10041520
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1004118F();
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'and eax, 000000001h'

// address: 0x100415A8
p100415A8
{
}
Failed to find pattern for 'push dword ptr [esp+004h]'

// address: 0x10041600
p10041600
{
}
Failed to find pattern for 'push ecx'

// address: 0x100416B4
p100416B4
{
}
Failed to find pattern for 'mov eax, dword ptr [esp+008h]'

// address: 0x10041808
p10041808
{
}
Failed to find pattern for 'cmp dword ptr [esp+008h], 000000001h'
