
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
    if (reinterpret_cast<any_int32>(STACKVAR(8, 4)) == 0x00000000)
    {
        goto l1000108B;
    }
    REGDEF(cmpl=ACCESS(GLOBAL(0x10049F04), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10001037'

// address: 0x10001096
void B_IDataFile::RemoveOnOpenFunc()
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(cmpl=ACCESS(GLOBAL(0x10049F04), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100010A4'

// address: 0x100010E4
p100010E4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100010F3();
    unknown_function_10001205();
}

// address: 0x100010F3
p100010F3
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    ACCESS(GLOBAL(0x10049EF4), 0, 4) = GLOBAL(0x10047040);
    ACCESS(GLOBAL(0x10049EEC), 0, 4) = 0xFFFFFFFF;
    ACCESS(GLOBAL(0x10049EE8), 0, 4) = _open(GLOBAL(0x1004704C), 0x00008000);
    REGDEF(cmpl=ACCESS(GLOBAL(0x10049EE8), 0, 4), cmpr=0xFFFFFFFF)
}
Failed to find pattern for 'jne l10001133'

// address: 0x10001205
p10001205
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x10001217));
}

// address: 0x10001217
p10001217
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000001;
    STACKVAR(-8, 4) = 0x0000001C;
    STACKVAR(-4, 4) = GLOBAL(0x10049EE0);
    REGDEF(eax=STACKVAR(-8, 4))
}
Failed to find pattern for 'imul eax, dword ptr [ebp-00Ch]'

// address: 0x100014D2
void B_IDataFile::Close()
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    ACCESS(STACKVAR(-12, 4), 16396, 4) = 0xFFFFC000;
    ACCESS(STACKVAR(-12, 4), 16400, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 4, 4)) == 0x00000000)
    {
        goto l10001518;
    }
    free(ACCESS(STACKVAR(-12, 4), 4, 4));
    REGDEF(edx=STACKVAR(-12, 4))
}
Can't parse line: l10001518: mov eax, dword ptr [ebp-00Ch]

// address: 0x100015E2
void B_IDataFile::Open(const char *src, int flags)
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-20, 4), 4, 4) = _strdup(STACKVAR(8, 4));
    ACCESS(STACKVAR(-20, 4), 16404, 4) = 0x00000000;
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16404, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10001732'

// address: 0x10001740
B_IDataFile::B_IDataFile()
{
    this->fd = -1;
    this->file_name = NULL;
    this->cacheBlockBytesRead = 4294950912;
    this->cacheBlockPos = 0;
    this->filePosition = 0;
}

// address: 0x10001788
B_IDataFile::B_IDataFile(const char *file_name, int flags)
{
    this->cacheBlockBytesRead = 4294950912;
    this->cacheBlockPos = 0;
    this->Open(file_name, flags);
}

// address: 0x100017C2
unsigned int B_IDataFile::ReadCacheBlock()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 0, 4)) != 0xFFFFFFFF))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10001882
int B_IDataFile::Length()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 0, 4)) != 0xFFFFFFFF))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x100018A6
int B_IDataFile::Seek(int offset, int whence)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    STACKVAR(-16, 4) = STACKVAR(12, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000000)
    {
        goto l100018C9;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000001)
    {
        goto l100018D1;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000002)
    {
        goto l100018E3;
    }
    goto l100018EF;
}
Can't parse line: l100018C9: mov ecx, dword ptr [ebp+008h]

// address: 0x100019AF
int B_IDataFile::Tell()
{
    return reinterpret_cast<int>(this->cacheBlockBytesRead + this->cacheBlockPos);
}

// address: 0x100019CC
unsigned char B_IDataFile::Peek()
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    _eof(ACCESS(STACKVAR(-8, 4), 0, 4));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10001A0D
int B_IDataFile::Eof()
{
    return static_cast<int>(this->cacheBlockBytesRead + this->cacheBlockPos >= this->file_size);
}

// address: 0x10001A33
void B_IDataFile::Read(void *data, unsigned int size)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=12, stack_delta=None)
    REGDEF(ecx=STACKVAR(-8, 4), edx=ACCESS(STACKVAR(-8, 4), 8, 4))
}
Failed to find pattern for 'sub edx, dword ptr [ecx+000004010h]'

// address: 0x10001B55
B_IDataFile &operator >>(B_IDataFile &file, char &c)
{
    file.Read(&c, 1);
    return file;
}

// address: 0x10001B6B
B_IDataFile &operator >>(B_IDataFile &file, unsigned char &c)
{
    file.Read(&c, 1);
    return file;
}

// address: 0x10001B81
B_IDataFile &operator >>(B_IDataFile &file, short &s)
{
    file.Read(&s, 2);
    return file;
}

// address: 0x10001B97
B_IDataFile &operator >>(B_IDataFile &file, unsigned short &s)
{
    file.Read(&s, 2);
    return file;
}

// address: 0x10001BAD
B_IDataFile &operator >>(B_IDataFile &file, int &i)
{
    file.Read(&i, 4);
    return file;
}

// address: 0x10001BC3
B_IDataFile &operator >>(B_IDataFile &file, int &l)
{
    file.Read(&l, 4);
    return file;
}

// address: 0x10001BD9
B_IDataFile &operator >>(B_IDataFile &file, unsigned int &l)
{
    file.Read(&l, 4);
    return file;
}

// address: 0x10001BEF
B_IDataFile &operator >>(B_IDataFile &file, unsigned int &i)
{
    file.Read(&i, 4);
    return file;
}

// address: 0x10001C05
B_IDataFile &operator >>(B_IDataFile &file, float &f)
{
    file.Read(&f, 4);
    return file;
}

// address: 0x10001C1B
B_IDataFile &operator >>(B_IDataFile &file, double &f)
{
    file.Read(&f, 8);
    return file;
}

// address: 0x10001C31
B_IDataFile::~B_IDataFile()
{
    this->Close();
}

// address: 0x10001C44
B_ODataFile::B_ODataFile(const char *file_name, int flags)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 16392, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 16396, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 4, 4) = _strdup(STACKVAR(8, 4));
    ARG(0x00000180);
    REGDEF(edx=STACKVAR(12, 4))
}
Failed to find pattern for 'or edx, 000000301h'

// address: 0x10001DA0
p10001DA0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 16396, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10001DB5'

// address: 0x10001E01
p10001E01
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=ACCESS(STACKVAR(-4, 4), 16392, 4))
}
Failed to find pattern for 'jbe l10001E40'

// address: 0x10001E86
void B_ODataFile::Write(const void *data, unsigned int size)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10001E9C'

// address: 0x10001F5E
B_ODataFile &operator <<(B_ODataFile &file, const char &c)
{
    file.Write(&c, 1);
    return file;
}

// address: 0x10001F74
B_ODataFile &operator <<(B_ODataFile &file, const char *c)
{
    file.Write(c, strlen(c));
    return file;
}

// address: 0x10001F9A
B_ODataFile &operator <<(B_ODataFile &file, const unsigned char &c)
{
    file.Write(&c, 1);
    return file;
}

// address: 0x10001FB0
B_ODataFile &operator <<(B_ODataFile &file, const short &s)
{
    file.Write(&s, 2);
    return file;
}

// address: 0x10001FC6
B_ODataFile &operator <<(B_ODataFile &file, const unsigned short &s)
{
    file.Write(&s, 2);
    return file;
}

// address: 0x10001FDC
B_ODataFile &operator <<(B_ODataFile &file, const int &i)
{
    file.Write(&i, 4);
    return file;
}

// address: 0x10001FF2
B_ODataFile &operator <<(B_ODataFile &file, const int &l)
{
    file.Write(&l, 4);
    return file;
}

// address: 0x10002008
B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &l)
{
    file.Write(&l, 4);
    return file;
}

// address: 0x1000201E
B_ODataFile &operator <<(B_ODataFile &file, const unsigned int &i)
{
    file.Write(&i, 4);
    return file;
}

// address: 0x10002034
B_ODataFile &operator <<(B_ODataFile &file, const float &f)
{
    file.Write(&f, 4);
    return file;
}

// address: 0x1000204A
B_ODataFile &operator <<(B_ODataFile &file, const double &f)
{
    file.Write(&f, 8);
    return file;
}

// address: 0x10002060
p10002060
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    this->unknown_method_10001DA0();
    _commit(ACCESS(this, 0, 4));
}

// address: 0x10002082
B_ODataFile::~B_ODataFile()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    free(ACCESS(STACKVAR(-4, 4), 4, 4));
    REGDEF(eax=static_cast<unsigned int>(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 0, 4)) != 0xFFFFFFFF))
}
Failed to find pattern for 'test eax, eax'

// address: 0x100020C3
p100020C3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return B_IDataFile::GetnOpenedFiles();
}

// address: 0x100020CD
p100020CD
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return B_IDataFile::GetnOpenFiles();
}

// address: 0x100020D7
p100020D7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_IDataFile::ResetnOpenedFiles();
}

// address: 0x100020E1
p100020E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return B_IDataFile::SetOnOpenFunc(reinterpret_cast<PyObject *>(STACKVAR(8, 4)));
}

// address: 0x100020F2
void RemoveOnOpenInputFileFunc()
{
    B_IDataFile::RemoveOnOpenFunc();
}

// address: 0x10002100
p10002100
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=STACKVAR(12, 4))
}
Failed to find pattern for 'jle l10002119'

// address: 0x100021E0
unsigned int B_IDataFile::OK()
{
    return static_cast<unsigned int>(this->fd != -1);
}

// address: 0x10002200
char *B_IDataFile::GetFileName()
{
    return this->file_name;
}

// address: 0x10002220
B_IDataFile &B_IDataFile::operator =(const B_IDataFile &file)
{
    memcpy(this, file, 0x00004018); // TODO improve emitting of memcpy instructions
    return *this;
}

// address: 0x10002250
unsigned int B_ODataFile::OK()
{
    return static_cast<unsigned int>(this->fd != -1);
}

// address: 0x10002270
p10002270
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(this, 4, 4))
}

// address: 0x10002290
p10002290
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    memcpy(this, STACKVAR(8, 4), 0x00004010); // TODO improve emitting of memcpy instructions
    REGDEF(eax=this)
}

// address: 0x100022C0
B_Name &B_Name::Id()
{
    return *this;
}

// address: 0x100022D0
void B_Name::operator const char*()
{
    REGDEF(eax=this->string)
}

// address: 0x100022E0
unsigned int B_Name::Length()
{
    return this->len;
}

// address: 0x10002300
B_NamedObj::~B_NamedObj()
{
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    this->name.~B_Name();
}

// address: 0x10002320
B_NamedObj::B_NamedObj(const B_NamedObj &that)
{
    this->name.B_Name(that.name);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
}

// address: 0x10002350
B_NamedObj &B_NamedObj::operator=(const B_NamedObj &that)
{
    this->name = that.name;
    return *this;
}

// address: 0x100023C0
void sub_100023C0(B_NamedObj *this_ptr, int arg_0)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100024C0
B_MessageChannel::B_MessageChannel(B_Name &name)
{
    this->B_NamedObj(name);
    ACCESS(this, 0, 4) = GLOBAL(0x10042180);
    this->unknown0Ch = 1;
}

// address: 0x100024F0
p100024F0
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=0)
    reinterpret_cast<B_Name *>(LOCAL(-8))->B_Name(reinterpret_cast<char *>(GLOBAL(0x10049F08)));
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj(*reinterpret_cast<B_Name *>(LOCAL(-8)));
    reinterpret_cast<B_Name *>(LOCAL(-8))->~B_Name();
    ACCESS(this, 0, 4) = GLOBAL(0x10042180);
    ACCESS(this, 12, 4) = 0x00000001;
    REGDEF(eax=this)
}

// address: 0x10002540
p10002540
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    REGDEF(eax=0x00000000)
}

// address: 0x10002550
B_MessageChannel::~B_MessageChannel()
{
    ACCESS(this, 0, 4) = GLOBAL(0x10042180);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    this->name.~B_Name();
}

// address: 0x10002580
B_MessageChannel::B_MessageChannel(const B_MessageChannel &that)
{
    this->name.B_Name(that.name);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    this->unknown0Ch = that.unknown0Ch;
    ACCESS(this, 0, 4) = GLOBAL(0x10042180);
}

// address: 0x100025C0
B_MessageChannel &B_MessageChannel::operator=(const B_MessageChannel &that)
{
    this->name = that.name;
    this->unknown0Ch = that.unknown0Ch;
    return *this;
}

// address: 0x10002640
p10002640
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10002710
B_MessageManager::~B_MessageManager()
{
}

// address: 0x10002720
B_MessageManager &B_MessageManager::operator=(const B_MessageManager &that)
{
    this->unknown00 = that.unknown00;
    return *this;
}

// address: 0x10002740
char *GetConfigDirectory()
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    REGDEF(eax=static_cast<unsigned int>(ACCESS(GLOBAL(0x1004A110), 0, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x100028EC
char *GetCurrentLanguage()
{
    ProcedureInfo(this=None, this_offset=None, local_size=256, stack_delta=None)
    REGDEF(edi=unknown_function_10002740(), edx=LOCAL(-256))
}
Failed to find pattern for 'or ecx, 0FFFFFFFFh'

// address: 0x10002980
B_ListElement::~B_ListElement()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042190);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 4, 4)) == 0x00000000)
    {
        goto l100029AA;
    }
    ARG(0x00000000);
    ARG(STACKVAR(-4, 4));
    REGDEF(ecx=ACCESS(STACKVAR(-4, 4), 4, 4))
    unknown_function_10002BC5();
}
Can't parse line: l100029AA: mov esp, ebp

// address: 0x100029AE
p100029AE
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(STACKVAR(8, 4)) == 0x00000000)
    {
        goto l100029F0;
    }
}
Can't parse line: l100029BB: mov eax, dword ptr [ebp-004h]

// address: 0x10002A14
unsigned int B_List::Add(B_ListElement *element)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 8, 4)) == 0x00000000)
    {
        goto l10002A51;
    }
    ACCESS(ACCESS(STACKVAR(-4, 4), 8, 4), 12, 4) = STACKVAR(8, 4);
    ACCESS(STACKVAR(8, 4), 8, 4) = ACCESS(STACKVAR(-4, 4), 8, 4);
    ACCESS(STACKVAR(8, 4), 12, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 8, 4) = STACKVAR(8, 4);
    goto l10002A63;
}
Can't parse line: l10002A51: mov ecx, dword ptr [ebp-004h]

// address: 0x10002A86
unsigned int B_List::AddAfter(B_ListElement *existing, B_ListElement *newElement)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 4, 4), cmpr=STACKVAR(-8, 4))
}
Failed to find pattern for 'jne l10002AAC'

// address: 0x10002B34
unsigned int B_List::AddBefore(B_ListElement *existing, B_ListElement *newElement)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=ACCESS(STACKVAR(-8, 4), 8, 4))
}
Failed to find pattern for 'jne l10002B75'

// address: 0x10002BC5
unsigned int B_List::Remove(B_ListElement *element, unsigned int index)
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10002BDE'

// address: 0x10002CAC
p10002CAC
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=20, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-16, 4), 4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10002CC5'

// address: 0x10002D5D
p10002D5D
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=20, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-16, 4), 4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10002D76'

// address: 0x10002E0E
p10002E0E
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-12, 4), 4, 4), cmpr=STACKVAR(8, 4))
}
Failed to find pattern for 'jnb l10002E26'

// address: 0x10002E5D
unsigned int B_List::Exists(const B_ListElement *element)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-8, 4), 8, 4);
}
Can't parse line: l10002E6F: cmp dword ptr [ebp-004h], 000000000h

// address: 0x10002EA0
B_ListElement::B_ListElement()
{
    this->list = NULL;
    this->next = NULL;
    this->prev = NULL;
    ACCESS(this, 0, 4) = GLOBAL(0x10042190);
}

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
    this->list = other.list;
    this->next = other.next;
    this->prev = other.prev;
    ACCESS(this, 0, 4) = GLOBAL(0x10042190);
}

// address: 0x10002F80
B_ListElement &B_ListElement::operator =(const B_ListElement &other)
{
    this->list = other.list;
    this->next = other.next;
    this->prev = other.prev;
    return *this;
}

// address: 0x10002FF0
p10002FF0
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100030A0
B_List::B_List(B_ListElement *element)
{
    this->numElements = 0;
    this->tail = NULL;
    this->head = NULL;
    ACCESS(this, 0, 4) = GLOBAL(0x10042194);
}

// address: 0x100030E0
B_List::~B_List()
{
    ACCESS(this, 0, 4) = GLOBAL(0x10042194);
}

// address: 0x10003100
p10003100
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(this, 4, 4))
}

// address: 0x10003120
p10003120
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(this, 8, 4))
}

// address: 0x10003140
p10003140
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(this, 12, 4))
}

// address: 0x10003160
B_List::B_List(const B_List &arg_1)
{
    this->numElements = arg_1.numElements;
    this->tail = arg_1.tail;
    this->head = arg_1.head;
    ACCESS(this, 0, 4) = GLOBAL(0x10042194);
}

// address: 0x100031A0
B_List &B_List::operator=(const B_List &that)
{
    this->numElements = that.numElements;
    this->tail = that.tail;
    this->head = that.head;
    return *this;
}

// address: 0x100031E0
p100031E0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x10042194);
}

// address: 0x10003250
p10003250
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10003300
B_Name::B_Name()
{
    STACKVAR(-4, 4) = ??2@YAPAXI@Z(0x00000001);
    this->string = reinterpret_cast<char *>(STACKVAR(-4, 4));
    *this->string = '\0';
    this->len = 0;
}

// address: 0x10003337
B_Name::B_Name(const char *str)
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 4, 4) = strlen(STACKVAR(8, 4));
    STACKVAR(-4, 4) = ??2@YAPAXI@Z(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 4, 4)) + 0x00000001);
    ACCESS(STACKVAR(-8, 4), 0, 4) = STACKVAR(-4, 4);
    REGDEF(edi=STACKVAR(8, 4), edx=ACCESS(STACKVAR(-8, 4), 0, 4))
}
Failed to find pattern for 'or ecx, 0FFFFFFFFh'

// address: 0x100033A4
B_Name::B_Name(const B_Name &src)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    ACCESS(STACKVAR(-12, 4), 4, 4) = STACKVAR(-8, 4);
    STACKVAR(-4, 4) = ??2@YAPAXI@Z(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 4, 4)) + 0x00000001);
    ACCESS(STACKVAR(-12, 4), 0, 4) = STACKVAR(-4, 4);
    REGDEF(edi=ACCESS(STACKVAR(8, 4), 0, 4), edx=ACCESS(STACKVAR(-12, 4), 0, 4))
}
Failed to find pattern for 'or ecx, 0FFFFFFFFh'

// address: 0x10003410
B_Name::B_Name(unsigned int len)
{
    this->len = len;
    STACKVAR(-4, 4) = ??2@YAPAXI@Z(this->len + 0x00000001);
    this->string = reinterpret_cast<char *>(STACKVAR(-4, 4));
    this->string[this->len] = '\0';
}

// address: 0x10003457
char *B_Name::String()
{
    return this->string;
}

// address: 0x10003467
unsigned int B_Name::operator >(const B_Name &rhs)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-4, 4), 0, 4);
}
Can't parse line: l10003480: mov ecx, dword ptr [ebp-00Ch]

// address: 0x100034DA
unsigned int B_Name::operator <(const B_Name &rhs)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-4, 4), 0, 4);
}
Can't parse line: l100034F3: mov ecx, dword ptr [ebp-00Ch]

// address: 0x1000354D
unsigned int B_Name::operator ==(const B_Name &rhs)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 4, 4), cmpr=ACCESS(STACKVAR(8, 4), 4, 4))
}
Failed to find pattern for 'jne l100035CA'

// address: 0x100035D2
unsigned int B_Name::operator ==(const char *str)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = STACKVAR(8, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-4, 4), 0, 4);
}
Can't parse line: l100035E9: mov eax, dword ptr [ebp-00Ch]

// address: 0x10003643
unsigned int B_Name::operator !=(const B_Name &rhs)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 4, 4)) == reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 4, 4)))
    {
        goto l10003661;
    }
    REGDEF(eax=0x00000001)
    goto l100036BF;
}
Can't parse line: l10003661: mov eax, dword ptr [ebp+008h]

// address: 0x100036C5
unsigned int B_Name::operator !=(const char *str)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = STACKVAR(8, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-4, 4), 0, 4);
}
Can't parse line: l100036DC: mov eax, dword ptr [ebp-00Ch]

// address: 0x10003730
p10003730
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 4, 4), cmpr=ACCESS(STACKVAR(8, 4), 4, 4))
}
Failed to find pattern for 'jne l10003761'

// address: 0x10003769
unsigned int B_Name::CompareNoCase(const char *str)
{
    return static_cast<unsigned int>(_stricmp(this->string, str) == 0);
}

// address: 0x1000378E
B_Name &B_Name::operator =(const B_Name &src)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 4, 4)) == reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 4, 4)))
    {
        goto l100037EF;
    }
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    ??3@YAXPAX@Z(STACKVAR(-4, 4));
    ACCESS(STACKVAR(-12, 4), 4, 4) = strlen(ACCESS(STACKVAR(8, 4), 0, 4));
    STACKVAR(-8, 4) = ??2@YAPAXI@Z(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 4, 4)) + 0x00000001);
    ACCESS(STACKVAR(-12, 4), 0, 4) = STACKVAR(-8, 4);
}
Can't parse line: l100037EF: mov ecx, dword ptr [ebp+008h]

// address: 0x10003821
B_Name B_Name::Right(unsigned int count)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jnb l10003839'

// address: 0x10003898
B_Name B_Name::Left(unsigned int count)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jnb l100038B0'

// address: 0x10003904
B_IDataFile &operator >>(B_IDataFile &file, B_Name &name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    unknown_function_10001BEF(STACKVAR(8, 4), LOCAL(-4));
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 4, 4)))
    {
        goto l1000395F;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(12, 4), 0, 4);
    ??3@YAXPAX@Z(STACKVAR(-8, 4));
    ACCESS(STACKVAR(12, 4), 4, 4) = STACKVAR(-4, 4);
    STACKVAR(-12, 4) = ??2@YAPAXI@Z(reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 4, 4)) + 0x00000001);
    ACCESS(STACKVAR(12, 4), 0, 4) = STACKVAR(-12, 4);
}
Can't parse line: l1000395F: mov ecx, dword ptr [ebp+00Ch]

// address: 0x1000398A
B_ODataFile &operator <<(B_ODataFile &file, const B_Name &name)
{
    file << name.len;
    file.Write(name.string, name.len);
    return file;
}

// address: 0x100039BA
B_Name::~B_Name()
{
    this->len = 0;
    STACKVAR(-4, 4) = this->string;
    ??3@YAXPAX@Z(STACKVAR(-4, 4));
}

// address: 0x100039E5
B_NamedObj::B_NamedObj()
{
    this->name.B_Name();
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
}

// address: 0x10003A07
B_NamedObj::B_NamedObj(const B_Name &n)
{
    this->name.B_Name(n);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
}

// address: 0x10003A2F
B_Name &B_NamedObj::Id()
{
    return this->name;
}

// address: 0x10003A40
B_IDataFile &operator >>(B_IDataFile &file, B_NamedObj &named_obj)
{
    file >> named_obj.name;
}

// address: 0x10003A58
B_ODataFile &operator <<(B_ODataFile &file, const B_NamedObj &namedObj)
{
    file << namedObj.name;
}

// address: 0x10003A70
B_Name operator +(const B_Name &lother, const B_Name &rother)
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10003B1E
B_Name operator +(const B_Name &other, const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10003BC7
B_Name operator +(const char *str, const B_Name &bName)
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10003C70
B_Name &B_Name::operator +=(const char *str)
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10003D30
B_Name &B_Name::operator+=(char c)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    ACCESS(STACKVAR(-16, 4), 4, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-16, 4), 4, 4)) + 0x00000001;
    STACKVAR(-8, 4) = ??2@YAPAXI@Z(reinterpret_cast<any_int32>(ACCESS(STACKVAR(-16, 4), 4, 4)) + 0x00000001);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    REGDEF(edi=ACCESS(STACKVAR(-16, 4), 0, 4), edx=STACKVAR(-4, 4))
}
Failed to find pattern for 'or ecx, 0FFFFFFFFh'

// address: 0x10003DCE
B_Name &B_Name::operator +=(const B_Name &other)
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10003E91
void B_Name::UpCase()
{
    _strupr(this->string);
}

// address: 0x10003EB0
B_ResourceManager *GetResourceManager()
{
    return &B_resource_manager;
}

// address: 0x10003EBA
B_Resource::B_Resource()
{
    this->B_NamedObj();
    ACCESS(this, 0, 4) = GLOBAL(0x10042198);
}

// address: 0x10003ED9
p10003ED9
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj(reinterpret_cast<B_Name &>(STACKVAR(8, 4)));
    ACCESS(this, 0, 4) = GLOBAL(0x10042198);
    REGDEF(eax=this)
}

// address: 0x10003EFE
B_Resource::~B_Resource()
{
    ACCESS(this, 0, 4) = GLOBAL(0x10042198);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    this->name.~B_Name();
}

// address: 0x10003F26
p10003F26
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 2) = STACKVAR(12, 4)->(ACCESS(ACCESS(STACKVAR(12, 4), 0, 4), 4, 4))();
    unknown_function_10001FC6(STACKVAR(8, 4), LOCAL(-4));
    STACKVAR(-8, 4) = STACKVAR(12, 4)->(ACCESS(ACCESS(STACKVAR(12, 4), 0, 4), 8, 4))();
    unknown_function_10002008(STACKVAR(8, 4), LOCAL(-8));
    STACKVAR(-12, 4) = STACKVAR(12, 4)->(ACCESS(ACCESS(STACKVAR(12, 4), 0, 4), 12, 4))();
    unknown_function_1000201E(STACKVAR(8, 4), LOCAL(-12));
    STACKVAR(-16, 4) = STACKVAR(12, 4)->(ACCESS(ACCESS(STACKVAR(12, 4), 0, 4), 4, 4))() & 0x0000FFFF;
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000001)
    {
        goto l10003FA8;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000002)
    {
        goto l10003FBA;
    }
    goto l10003FCA;
}
Can't parse line: l10003FA8: mov ecx, dword ptr [ebp+00Ch]

// address: 0x10003FCE
p10003FCE
{
    ProcedureInfo(this=None, this_offset=None, local_size=84, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-68, 4) = reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x0000FFFF;
    REGDEF(ecx=STACKVAR(-68, 4))
}
Failed to find pattern for 'sub ecx, 000000001h'

// address: 0x10004371
p10004371
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=16)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj(reinterpret_cast<B_Name &>(STACKVAR(16, 4)));
    reinterpret_cast<B_Name *>(reinterpret_cast<any_int32>(this) + 0x0000000C)->B_Name(reinterpret_cast<B_Name &>(STACKVAR(8, 4)));
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 24, 4) = STACKVAR(20, 4);
    ACCESS(this, 28, 4) = 0x00000000;
    ACCESS(this, 32, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x100421DC);
    REGDEF(eax=this)
}

// address: 0x100043CB
p100043CB
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 0, 4) = GLOBAL(0x100421DC);
    this->unknown_method_10004606();
    reinterpret_cast<B_Name *>(reinterpret_cast<any_int32>(this) + 0x0000000C)->~B_Name();
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    reinterpret_cast<B_Name *>(reinterpret_cast<any_int32>(this) + 0x00000004)->~B_Name();
}

// address: 0x10004406
p10004406
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 28, 4)) == 0x00000000)
    {
        goto l1000441D;
    }
    REGDEF(eax=0x00000001)
    goto l1000441F;
}
Can't parse line: l1000441D: xor eax, eax

// address: 0x10004425
B_Resource *B_ResourceManager::sub_10004425(unsigned short resourceId, const B_Name &name)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x0000402C)
    unknown_function_10041600();
}
'ecx'

// address: 0x100045B9
p100045B9
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 28, 4)) == 0x00000000)
    {
        goto l10004602;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-12, 4), 28, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l100045F1;
    }
    STACKVAR(-16, 4) = STACKVAR(-4, 4)->(ACCESS(ACCESS(STACKVAR(-4, 4), 0, 4), 0, 4))(0x00000001);
    goto l100045F8;
}
Can't parse line: l100045F1: mov dword ptr [ebp-010h], 000000000h

// address: 0x10004606
p10004606
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-12, 4), 32, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000461A'

// address: 0x10004676
p10004676
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4));
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1000468E
p1000468E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4));
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100046A6
p100046A6
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = 0x00000010;
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = 0x00000001;
    ACCESS(this, 0, 4) = GLOBAL(0x100421EC);
    ACCESS(this, 0, 4) = GLOBAL(0x100421E8);
    ACCESS(this, 0, 4) = GLOBAL(0x100421E4);
    ACCESS(this, 0, 4) = GLOBAL(0x100421E0);
    REGDEF(eax=this)
}

// address: 0x1000470A
p1000470A
{
    ProcedureInfo(this=Id(this), this_offset=-40, local_size=48, stack_delta=None)
    ACCESS(STACKVAR(-40, 4), 0, 4) = GLOBAL(0x100421E0);
    REGDEF(cmpl=ACCESS(STACKVAR(-40, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000472A'

// address: 0x10004874
p10004874
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000000;
    goto l1000488F;
}
Can't parse line: l10004886: mov eax, dword ptr [ebp-008h]

// address: 0x100048EF
p100048EF
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l1000490A;
}
Can't parse line: l10004901: mov eax, dword ptr [ebp-004h]

// address: 0x1000494D
p1000494D
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 4) = 0x00000000;
    goto l1000496F;
}
Can't parse line: l10004966: mov eax, dword ptr [ebp-004h]

// address: 0x100049BB
p100049BB
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l100049D6;
}
Can't parse line: l100049CD: mov eax, dword ptr [ebp-004h]

// address: 0x100049F8
B_ResourceManager::B_ResourceManager()
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l10004A13;
}
Can't parse line: l10004A0A: mov eax, dword ptr [ebp-004h]

// address: 0x10004A9B
B_ResourceManager::~B_ResourceManager()
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    STACKVAR(-12, 4)->unknown_method_10004AE0();
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-12, 4), 1024, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l10004AD5;
    }
    STACKVAR(-16, 4) = STACKVAR(-4, 4)->(ACCESS(ACCESS(STACKVAR(-4, 4), 0, 4), 0, 4))(0x00000001);
    goto l10004ADC;
}
Can't parse line: l10004AD5: mov dword ptr [ebp-010h], 000000000h

// address: 0x10004AE0
void B_ResourceManager::Clean()
{
    ProcedureInfo(this=Id(this), this_offset=-36, local_size=44, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l10004AFB;
}
Can't parse line: l10004AF2: mov eax, dword ptr [ebp-004h]

// address: 0x10004C20
p10004C20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(ACCESS(this, 1024, 4), 8, 4))
}

// address: 0x10004C37
p10004C37
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jbe l10004C6E'

// address: 0x10004C76
p10004C76
{
    ProcedureInfo(this=Id(this), this_offset=-40, local_size=40, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l10004C92;
}
Can't parse line: l10004C89: mov eax, dword ptr [ebp-004h]

// address: 0x10004E0B
unsigned int B_ResourceManager::LocateResourceIn(const B_Name &id, const B_Name *arg_2, int arg_3)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x000040A0)
    unknown_function_10041600();
}
Unexpected instruction type <class 'instructions.code_instruction.CodeInstruction'>

// address: 0x10005533
p10005533
{
    ProcedureInfo(this=Id(this), this_offset=-96, local_size=100, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    LOCAL(-28)->unknown_method_10003300();
    STACKVAR(-36, 2) = 0x0000;
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000000;
    unknown_function_10001BEF(STACKVAR(12, 4), LOCAL(-16));
    STACKVAR(-12, 4) = 0x00000000;
    goto l10005582;
}
Can't parse line: l10005579: mov edx, dword ptr [ebp-00Ch]

// address: 0x1000582E
unsigned int B_ResourceManager::AddAutoResource(const B_Name &arg_1, B_Resource *arg_2, int arg_3)
{
    ProcedureInfo(this=Id(this), this_offset=-64, local_size=72, stack_delta=None)
    STACKVAR(-36, 4) = 0x00000000;
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000585D'

// address: 0x10005AF0
B_Resource *B_ResourceManager::GetResource(unsigned short resourceId, const B_Name &name)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005B2F
p10005B2F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005B6F
p10005B6F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005BB2
p10005BB2
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-16, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005C13
p10005C13
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x00004024)
    unknown_function_10041600();
}
'ecx'

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
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=STACKVAR(-24, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005DAE
p10005DAE
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(8, 4), ecx=STACKVAR(-24, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005E42
p10005E42
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005E8F
p10005E8F
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005ED1
void B_ResourceManager::FreeResource(B_Resource *resource)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10005EF2'

// address: 0x10005F32
unsigned int B_ResourceManager::NResources(unsigned short arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x0000FFFF, ecx=STACKVAR(-4, 4))
}
Failed to find pattern for 'cmp dword ptr [ecx+eax*04h], 000000000h'

// address: 0x10005F66
void B_ResourceManager::AddBodLink(const char *c, int i, const char *pc, int i1)
{
    ProcedureInfo(this=Id(this), this_offset=-60, local_size=64, stack_delta=None)
    STACKVAR(-28, 4) = 0x00000000;
    REGDEF(cmpl=ACCESS(STACKVAR(-60, 4), 4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10005FB0'

// address: 0x1000617B
p1000617B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000618A();
    unknown_function_10006199();
}

// address: 0x1000618A
p1000618A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return B_resource_manager.B_ResourceManager();
}

// address: 0x10006199
p10006199
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x100061AB));
}

// address: 0x100061AB
p100061AB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.~B_ResourceManager();
}

// address: 0x100061BA
p100061BA
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=0)
    reinterpret_cast<B_Name *>(LOCAL(-12))->B_Name(reinterpret_cast<char *>(STACKVAR(8, 4)));
    STACKVAR(-4, 4) = B_resource_manager.LocateResourceIn(*reinterpret_cast<B_Name *>(LOCAL(-12)), NULL, 1);
    reinterpret_cast<B_Name *>(LOCAL(-12))->~B_Name();
    REGDEF(eax=STACKVAR(-4, 4))
}

// address: 0x100061F0
p100061F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    LOCAL(-12)->unknown_method_10003337(STACKVAR(8, 4));
    STACKVAR(-4, 4) = GLOBAL(0x1004A118)->unknown_method_10005AF0(0x00000001, LOCAL(-12));
    LOCAL(-12)->unknown_method_100039BA();
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l1000622A;
    }
    REGDEF(eax=0x00000001)
    goto l1000622C;
}
Can't parse line: l1000622A: xor eax, eax

// address: 0x10006230
p10006230
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=0)
    reinterpret_cast<B_Name *>(LOCAL(-12))->B_Name(reinterpret_cast<char *>(STACKVAR(8, 4)));
    STACKVAR(-4, 4) = B_resource_manager.LocateResourceIn(*reinterpret_cast<B_Name *>(LOCAL(-12)), NULL, 2);
    reinterpret_cast<B_Name *>(LOCAL(-12))->~B_Name();
    REGDEF(eax=STACKVAR(-4, 4))
}

// address: 0x10006266
p10006266
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=0)
    reinterpret_cast<B_Name *>(LOCAL(-12))->B_Name(reinterpret_cast<char *>(STACKVAR(8, 4)));
    STACKVAR(-4, 4) = B_resource_manager.LocateResourceIn(*reinterpret_cast<B_Name *>(LOCAL(-12)), NULL, 5);
    reinterpret_cast<B_Name *>(LOCAL(-12))->~B_Name();
    REGDEF(eax=STACKVAR(-4, 4))
}

// address: 0x1000629C
p1000629C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x0000402C)
    unknown_function_10041600();
}
'ecx'

// address: 0x1000644A
p1000644A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x00004048)
    unknown_function_10041600();
}
'ecx'

// address: 0x1000660B
p1000660B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.unknown_method_1000629C(0x00000001, STACKVAR(8, 4));
}

// address: 0x10006620
p10006620
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.unknown_method_1000644A(0x00000001, STACKVAR(8, 4));
}

// address: 0x10006635
p10006635
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.unknown_method_1000629C(0x00000005, STACKVAR(8, 4));
}

// address: 0x1000664A
p1000664A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.unknown_method_1000644A(0x00000005, STACKVAR(8, 4));
}

// address: 0x1000665F
p1000665F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    B_resource_manager.unknown_method_10005BB2(STACKVAR(8, 2), STACKVAR(12, 4));
}

// address: 0x10006680
p10006680
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_100043CB();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100066B0
p100066B0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1000470A();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100066E0
B_Resource::B_Resource(const B_Resource &that)
{
    this->name.B_Name(that.name);
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    ACCESS(this, 0, 4) = GLOBAL(0x10042198);
}

// address: 0x10006720
B_Resource &B_Resource::operator=(const B_Resource &that)
{
    this->name = that.name;
    return *this;
}

// address: 0x10006780
p10006780
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10006830
B_ResourceManager &B_ResourceManager::operator =(const B_ResourceManager &that)
{
    memcpy(this, that, 0x00000404); // TODO improve emitting of memcpy instructions
    return *this;
}

// address: 0x10006860
B_Color::B_Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    ACCESS(this, 0, 4) = GLOBAL(0x100421F0);
}

// address: 0x10006890
B_Color::B_Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    ACCESS(this, 0, 4) = GLOBAL(0x100421F0);
    this->MakeCons();
}

// address: 0x100068D0
B_Color B_Color::operator +(const B_Color &color)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(-16, 4), 6, 1)) + static_cast<unsigned int>(ACCESS(STACKVAR(12, 4), 6, 1)))
}
'cl'

// address: 0x10006950
B_Color B_Color::operator *(float coef)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=28, stack_delta=None)
    STACKVAR(-20, 4) = static_cast<unsigned int>(ACCESS(STACKVAR(-16, 4), 6, 1));
}
Failed to find pattern for 'fild dword ptr [ebp-014h]'

// address: 0x100069E0
B_Color B_Color::operator /(float f)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=28, stack_delta=None)
    STACKVAR(-20, 4) = static_cast<unsigned int>(ACCESS(STACKVAR(-16, 4), 6, 1));
}
Failed to find pattern for 'fild dword ptr [ebp-014h]'

// address: 0x10006A70
p10006A70
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    REGDEF(cmpl=static_cast<unsigned int>(ACCESS(STACKVAR(-4, 4), 4, 1)), cmpr=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 4, 1)))
}
Failed to find pattern for 'jne l10006ABE'

// address: 0x10006AD0
p10006AD0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    REGDEF(cmpl=static_cast<unsigned int>(ACCESS(STACKVAR(-4, 4), 4, 1)), cmpr=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 4, 1)))
}
Failed to find pattern for 'jne l10006B1E'

// address: 0x10006B30
p10006B30
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=12)
    ACCESS(this, 4, 1) = STACKVAR(8, 1);
    ACCESS(this, 6, 1) = STACKVAR(16, 1);
    ACCESS(this, 5, 1) = STACKVAR(12, 1);
}

// address: 0x10006B60
B_Color::B_Color(const B_Color &that)
{
    this->r = that.r;
    this->g = that.g;
    this->b = that.b;
    ACCESS(this, 0, 4) = GLOBAL(0x100421F0);
}

// address: 0x10006BA0
B_Color &B_Color::operator =(const B_Color &that)
{
    this->r = that.r;
    this->g = that.g;
    this->b = that.b;
    return *this;
}

// address: 0x10006BE0
p10006BE0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=this)
}

// address: 0x10006BF0
p10006BF0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    memcpy(this, STACKVAR(8, 4), 0x00000300); // TODO improve emitting of memcpy instructions
    REGDEF(eax=this)
}

// address: 0x10006C20
B_BitMap &B_BitMap::operator=(const B_BitMap &that)
{
    this->type = that.type;
    this->dimension1 = that.dimension1;
    this->dimension2 = that.dimension2;
    this->data = that.data;
    this->pal = that.pal;
    return *this;
}

// address: 0x10006C70
p10006C70
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x0000000C)->unknown_method_10008FDA();
    STACKVAR(-4, 4)->unknown_method_10003EFE();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10006CB0
B_BitMap24::B_BitMap24(int width, int height)
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-28, 4), 0, 4) = GLOBAL(0x100421C8);
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A530), 0, 4), cmpr=ACCESS(GLOBAL(0x1004A528), 0, 4))
}
Failed to find pattern for 'jbe l10006CF6'

// address: 0x10006E20
p10006E20
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 12, 4)) == 0x00000000)
    {
        goto l10006E51;
    }
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-8, 4), 12, 4);
    ??3@YAXPAX@Z(STACKVAR(-4, 4));
    REGDEF(ecx=STACKVAR(-8, 4))
}
Can't parse line: l10006E51: mov edx, dword ptr [ebp-008h]

// address: 0x10006E70
B_BitMap24::~B_BitMap24()
{
    ProcedureInfo(this=Id(this), this_offset=-48, local_size=52, stack_delta=None)
    ACCESS(STACKVAR(-48, 4), 0, 4) = GLOBAL(0x100421C8);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10006E95;
}
Can't parse line: l10006E8C: mov ecx, dword ptr [ebp-008h]

// address: 0x10007090
p10007090
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(STACKVAR(8, 4), 0, 4) = ACCESS(this, 4, 4);
    ACCESS(STACKVAR(12, 4), 0, 4) = ACCESS(this, 8, 4);
}

// address: 0x100070C0
p100070C0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=ACCESS(this, 12, 4))
}

// address: 0x100070E0
p100070E0
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-28, 4), 0, 4) = GLOBAL(0x100421C8);
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A530), 0, 4), cmpr=ACCESS(GLOBAL(0x1004A528), 0, 4))
}
Failed to find pattern for 'jbe l10007126'

// address: 0x10007470
p10007470
{
    ProcedureInfo(this=Id(this), this_offset=-72, local_size=76, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10007790
p10007790
{
    ProcedureInfo(this=Id(this), this_offset=-52, local_size=56, stack_delta=None)
    STACKVAR(-48, 4) = reinterpret_cast<any_int32>(STACKVAR(-52, 4)) + 0x0000000C;
    ACCESS(STACKVAR(-48, 4), 0, 4) = GLOBAL(0x100421C8);
    STACKVAR(-8, 4) = 0x00000000;
    goto l100077BE;
}
Can't parse line: l100077B5: mov edx, dword ptr [ebp-008h]

// address: 0x100079D0
p100079D0
{
    ProcedureInfo(this=Id(this), this_offset=-52, local_size=56, stack_delta=None)
    STACKVAR(-48, 4) = reinterpret_cast<any_int32>(STACKVAR(-52, 4)) + 0x0000000C;
    ACCESS(STACKVAR(-48, 4), 0, 4) = GLOBAL(0x100421C8);
    STACKVAR(-8, 4) = 0x00000000;
    goto l100079FE;
}
Can't parse line: l100079F5: mov edx, dword ptr [ebp-008h]

// address: 0x10007C10
p10007C10
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=ACCESS(STACKVAR(-24, 4), 8, 4))
}
Failed to find pattern for 'jbe l10007C4E'

// address: 0x10007D30
p10007D30
{
    ProcedureInfo(this=Id(this), this_offset=-36, local_size=40, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=ACCESS(STACKVAR(-36, 4), 8, 4))
}
Failed to find pattern for 'jb l10007D4A'

// address: 0x10007EF0
B_RDataLight &B_RDataLight::operator=(const B_RDataLight &other)
{
    memcpy(this, other, 16); // TODO improve emitting of memcpy instructions
    return *this;
}

// address: 0x10007F20
p10007F20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 0, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    REGDEF(eax=this)
}

// address: 0x10007F40
B_RDataTriangle &B_RDataTriangle::operator=(const B_RDataTriangle &other)
{
    memcpy(this, other, 0x0000001C); // TODO improve emitting of memcpy instructions
    return *this;
}

// address: 0x10007F70
B_MeshEdge &B_MeshEdge::operator=(const B_MeshEdge &other)
{
    memcpy(this, other, 0x00000018); // TODO improve emitting of memcpy instructions
    return *this;
}

// address: 0x10007FA0
p10007FA0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x100421EC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l10008061;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10007FD6'

// address: 0x10008080
p10008080
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x100421EC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l10008141;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100080B6'

// address: 0x10008160
p10008160
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x100421F4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l10008238;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10008196'

// address: 0x10008260
p10008260
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x100421EC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l10008321;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10008296'

// address: 0x10008374
p10008374
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(ax=0x0002)
}

// address: 0x10008383
p10008383
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-16, 4), 16, 4)) + reinterpret_cast<any_int32>(ACCESS(STACKVAR(-16, 4), 20, 4)) + reinterpret_cast<any_int32>(ACCESS(STACKVAR(-16, 4), 24, 4));
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-16, 4), 16, 4);
    REGDEF(eax=STACKVAR(-20, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10008483
p10008483
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = 0x0000000C;
    STACKVAR(-4, 4) = (reinterpret_cast<any_int32>(STACKVAR(-12, 4)) + 0x0000000C)->unknown_method_10008AF0();
    REGDEF(ecx=STACKVAR(-12, 4), edx=ACCESS(STACKVAR(-12, 4), 20, 4))
}
Failed to find pattern for 'imul edx, dword ptr [ecx+018h]'

// address: 0x100084D6
p100084D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_ODataFile &>(unknown_function_1000468E(STACKVAR(8, 4), STACKVAR(12, 4))) << reinterpret_cast<B_BitMap &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
}

// address: 0x100084FB
p100084FB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_IDataFile &>(unknown_function_10004676(STACKVAR(8, 4), STACKVAR(12, 4))) >> reinterpret_cast<B_BitMap &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
}

// address: 0x10008554
p10008554
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(ax=0x0003)
}

// address: 0x10008563
p10008563
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10008570
p10008570
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10008595
p10008595
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_BitMap24 &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
}

// address: 0x100085AD
p100085AD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(ax=0x0004)
}

// address: 0x100085D4
p100085D4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_BitMap24 &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
}

// address: 0x100085F0
p100085F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = 0x00000000;
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x100421F8);
    REGDEF(eax=this)
}

// address: 0x10008639
B_BitMap::B_BitMap(int type, unsigned int arg_2, unsigned int arg_3, const B_Pal *pal)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-16, 4), 4, 4) = STACKVAR(8, 4);
    ACCESS(STACKVAR(-16, 4), 8, 4) = STACKVAR(12, 4);
    ACCESS(STACKVAR(-16, 4), 12, 4) = STACKVAR(16, 4);
    ACCESS(STACKVAR(-16, 4), 0, 4) = GLOBAL(0x100421F8);
    STACKVAR(-4, 4) = STACKVAR(-16, 4)->unknown_method_10008AF0();
    REGDEF(ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'imul ecx, dword ptr [ebp+010h]'

// address: 0x100086E3
B_BitMap::B_BitMap(const B_BitMap &src)
{
    ProcedureInfo(this=Id(this), this_offset=-32, local_size=44, stack_delta=None)
    ACCESS(STACKVAR(-32, 4), 4, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    ACCESS(STACKVAR(-32, 4), 8, 4) = ACCESS(STACKVAR(8, 4), 8, 4);
    ACCESS(STACKVAR(-32, 4), 12, 4) = ACCESS(STACKVAR(8, 4), 12, 4);
    ACCESS(STACKVAR(-32, 4), 0, 4) = GLOBAL(0x100421F8);
    ACCESS(STACKVAR(-32, 4), 20, 4) = 0x00000000;
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-32, 4), 4, 4);
    REGDEF(ecx=STACKVAR(-36, 4))
}
Failed to find pattern for 'sub ecx, 000000001h'

// address: 0x10008974
p10008974
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x100421F8);
    ACCESS(STACKVAR(-24, 4), 20, 4) = 0x00000000;
    STACKVAR(-28, 4) = STACKVAR(8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-28, 4)) == 0x00000002)
    {
        goto l100089AD;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-28, 4)) == 0x00000004)
    {
        goto l10008A4A;
    }
}
Failed to find pattern for 'jmp near ptr l10008ABD'

// address: 0x10008AF0
p10008AF0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-4, 4), 4, 4);
    REGDEF(edx=STACKVAR(-8, 4))
}
Failed to find pattern for 'sub edx, 000000001h'

// address: 0x10008B51
B_ODataFile &operator <<(B_ODataFile &file, const B_BitMap &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(12, 4), 4, 4);
    unknown_function_1000201E(unknown_function_1000201E(unknown_function_10002008(STACKVAR(8, 4), LOCAL(-4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(12, 4), 4, 4);
    REGDEF(edx=STACKVAR(-8, 4))
}
Failed to find pattern for 'sub edx, 000000001h'

// address: 0x10008C9B
B_IDataFile &operator >>(B_IDataFile &file, B_BitMap &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l10008CC9;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(12, 4), 16, 4);
    ??3@YAXPAX@Z(STACKVAR(-8, 4));
    REGDEF(ecx=STACKVAR(12, 4))
}
Can't parse line: l10008CC9: mov edx, dword ptr [ebp+00Ch]

// address: 0x10008FDA
B_BitMap::~B_BitMap()
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x100421F8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 16, 4)) == 0x00000000)
    {
        goto l1000900A;
    }
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-12, 4), 16, 4);
    ??3@YAXPAX@Z(STACKVAR(-4, 4));
}
Can't parse line: l1000900A: mov edx, dword ptr [ebp-00Ch]

// address: 0x10009060
p10009060
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10009110
p10009110
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x100091A4
B_IDataFile &operator >>(B_IDataFile &file, B_Color &color)
{
    file >> color.r >> color.g >> color.b;
    return file;
}

// address: 0x100091DF
B_ODataFile &operator <<(B_ODataFile &file, const B_Color &color)
{
    file << color.r << color.g << color.b;
    return file;
}

// address: 0x1000921A
void B_Color::MakeCons()
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=40, stack_delta=None)
    REGDEF(cmpl=static_cast<unsigned int>(ACCESS(STACKVAR(-4, 4), 4, 1)), cmpr=0x000000FF)
}
Failed to find pattern for 'jle l1000923C'

// address: 0x100093A7
p100093A7
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    memcpy(this, STACKVAR(8, 4), 0x00000300); // TODO improve emitting of memcpy instructions
    REGDEF(eax=this)
}

// address: 0x100093C8
unsigned char B_Pal::GetRed(unsigned int val)
{
    return this->data[3 * val];
}

// address: 0x100093E1
unsigned char B_Pal::GetGreen(unsigned int val)
{
    return this->data[3 * val + 1];
}

// address: 0x100093FB
unsigned char B_Pal::GetBlue(unsigned int val)
{
    return this->data[3 * val + 2];
}

// address: 0x10009415
p10009415
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(ARRPTR(this, 1, 0x00000003 * reinterpret_cast<any_int32>(STACKVAR(8, 4)), 0), 0, 1) = STACKVAR(12, 1);
}

// address: 0x10009431
p10009431
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(ARRPTR(this, 1, 0x00000003 * reinterpret_cast<any_int32>(STACKVAR(8, 4)), 1), 0, 1) = STACKVAR(12, 1);
}

// address: 0x1000944E
p1000944E
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(ARRPTR(this, 1, 0x00000003 * reinterpret_cast<any_int32>(STACKVAR(8, 4)), 2), 0, 1) = STACKVAR(12, 1);
}

// address: 0x1000946B
p1000946B
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x10009633
p10009633
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=this)
}

// address: 0x10009661
p10009661
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile *>(STACKVAR(8, 4))->Read(reinterpret_cast<void *>(STACKVAR(12, 4)), 768);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1000967A
p1000967A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile *>(STACKVAR(8, 4))->Write(reinterpret_cast<void *>(STACKVAR(12, 4)), 768);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100096A0
p100096A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 4, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x0000003E)
    {
        goto l100096E8;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000000C;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = 0x0000003E;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 28, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l100096E8: cmp dword ptr [ebp+010h], 000000164h

// address: 0x1000980C
p1000980C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000F640(STACKVAR(8, 4));
}

// address: 0x1000982E
p1000982E
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    goto l10009846;
}
Can't parse line: l1000983D: mov eax, dword ptr [ebp-00Ch]

// address: 0x100098C9
p100098C9
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000065)
    {
        goto l100098DF;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 20, 4), cmpr=0x00000066)
}
Failed to find pattern for 'jne l1000991F'

// address: 0x10009C20
p10009C20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000064)
    {
        goto l10009C54;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10009C54: mov ecx, dword ptr [ebp+00Ch]

// address: 0x10009CD5
p10009CD5
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000065)
    {
        goto l10009D0C;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10009D0C: mov ecx, dword ptr [ebp+008h]

// address: 0x10009F40
p10009F40
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000068);
    ACCESS(STACKVAR(8, 4), 324, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000A05E);
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000A05E
p1000A05E
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    ACCESS(STACKVAR(-4, 4), 8, 4) = 0x00000000;
    unknown_function_1000A14E(STACKVAR(8, 4));
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000000)
    {
        goto l1000A0A3;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000002)
    {
        goto l1000A101;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000003)
    {
        goto l1000A0D2;
    }
}
Failed to find pattern for 'jmp near ptr l1000A130'

// address: 0x1000A14E
p1000A14E
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 224, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jle l1000A176'

// address: 0x1000A1C8
p1000A1C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 244, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x1000A47B
p1000A47B
{
    ProcedureInfo(this=None, this_offset=None, local_size=64, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 220, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x1000A72E
p1000A72E
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    STACKVAR(-36, 4) = 0x00000000;
    goto l1000A752;
}
Can't parse line: l1000A749: mov edx, dword ptr [ebp-024h]

// address: 0x1000A930
p1000A930
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000000C);
    ACCESS(STACKVAR(8, 4), 332, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000B2ED);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 40, 4);
    REGDEF(edx=STACKVAR(-8, 4))
}
Failed to find pattern for 'sub edx, 000000001h'

// address: 0x1000ACCF
p1000ACCF
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 332, 4);
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00002000);
    ACCESS(STACKVAR(-12, 4), 8, 4) = STACKVAR(-4, 4);
    STACKVAR(-8, 4) = 0x00000000;
    goto l1000AD15;
}
Can't parse line: l1000AD0C: mov ecx, dword ptr [ebp-008h]

// address: 0x1000ADE0
p1000ADE0
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-36, 4) = ACCESS(STACKVAR(8, 4), 332, 4);
    STACKVAR(-44, 4) = ACCESS(STACKVAR(-36, 4), 8, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
}
Can't parse line: l1000AE04: mov eax, dword ptr [ebp+018h]

// address: 0x1000AF44
p1000AF44
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-32, 4) = ACCESS(STACKVAR(8, 4), 332, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-32, 4), 8, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
}
Can't parse line: l1000AF68: mov eax, dword ptr [ebp+018h]

// address: 0x1000B01F
p1000B01F
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 332, 4);
    STACKVAR(-48, 4) = ACCESS(STACKVAR(-40, 4), 8, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
}
Can't parse line: l1000B043: mov eax, dword ptr [ebp+018h]

// address: 0x1000B1B5
p1000B1B5
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 36, 4);
}
Can't parse line: l1000B1CD: mov ecx, dword ptr [ebp+018h]

// address: 0x1000B23C
p1000B23C
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 56, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
}
Can't parse line: l1000B254: mov ecx, dword ptr [ebp+018h]

// address: 0x1000B2ED
p1000B2ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x1000B300
p1000B300
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000030);
    ACCESS(STACKVAR(8, 4), 340, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000B3E7);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 180, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-12, 4)) == 0x00000000)
    {
        goto l1000B351;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-12, 4)) == 0x00000001)
    {
        goto l1000B367;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-12, 4)) == 0x00000002)
    {
        goto l1000B37D;
    }
    goto l1000B393;
}
Can't parse line: l1000B351: mov edx, dword ptr [ebp-004h]

// address: 0x1000B3E7
p1000B3E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 340, 4);
    STACKVAR(-24, 4) = 0x00000000;
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 64, 4);
    goto l1000B41D;
}
Can't parse line: l1000B40B: mov ecx, dword ptr [ebp-018h]

// address: 0x1000B67F
p1000B67F
{
    ProcedureInfo(this=None, this_offset=None, local_size=300, stack_delta=None)
    STACKVAR(-272, 4) = ACCESS(STACKVAR(8, 4), 340, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-272, 4), 8, 4);
    REGDEF(edx=ACCESS(STACKVAR(12, 4), 16, 4), eax=STACKVAR(-272, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+edx*04h+00Ch]'

// address: 0x1000BA22
p1000BA22
{
    ProcedureInfo(this=None, this_offset=None, local_size=328, stack_delta=None)
    STACKVAR(-272, 4) = ACCESS(STACKVAR(8, 4), 340, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-272, 4), 28, 4);
    REGDEF(edx=ACCESS(STACKVAR(12, 4), 16, 4), eax=STACKVAR(-272, 4))
}
Failed to find pattern for 'mov ecx, dword ptr [eax+edx*04h+020h]'

// address: 0x1000BD80
p1000BD80
{
    ProcedureInfo(this=None, this_offset=None, local_size=1328, stack_delta=None)
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jl l1000BD96'

// address: 0x1000C0BE
p1000C0BE
{
    ProcedureInfo(this=None, this_offset=None, local_size=2116, stack_delta=None)
    REGDEF(ecx=0x00000008, eax=0x00000000)
}
Failed to find pattern for 'lea edi, [ebp-000000434h]'

// address: 0x1000C580
p1000C580
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000006C);
    ACCESS(STACKVAR(8, 4), 344, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000C607);
    STACKVAR(-8, 4) = 0x00000000;
    goto l1000C5C3;
}
Can't parse line: l1000C5BA: mov eax, dword ptr [ebp-008h]

// address: 0x1000C607
p1000C607
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    REGDEF(edx=reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF)
}
Failed to find pattern for 'test edx, edx'

// address: 0x1000C80D
p1000C80D
{
    ProcedureInfo(this=None, this_offset=None, local_size=52, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-40, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    STACKVAR(-36, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    REGDEF(esi=STACKVAR(-4, 4))
}
Failed to find pattern for 'add esi, 00000000Ch'

// address: 0x1000C9AC
p1000C9AC
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'movsx ecx, word ptr [eax]'

// address: 0x1000CC15
p1000CC15
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 12, 4);
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000CC53'

// address: 0x1000CD6C
p1000CD6C
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 32, 4), 24, 4);
    REGDEF(eax=ACCESS(STACKVAR(-4, 4), 12, 4)(ACCESS(STACKVAR(8, 4), 32, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000CDB5
p1000CDB5
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(eax=unknown_function_1000CEA5(STACKVAR(8, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000CEA5
p1000CEA5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=unknown_function_1000CC15(STACKVAR(8, 4), 0x0000007F, 0x00000007) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000CEDD
p1000CEDD
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-40, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    STACKVAR(-36, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    REGDEF(esi=STACKVAR(-4, 4))
}
Failed to find pattern for 'add esi, 00000000Ch'

// address: 0x1000CF7A
p1000CF7A
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 184, 4)) == 0x00000000)
    {
        goto l1000CFEF;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 36, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000CFE0'

// address: 0x1000D08D
p1000D08D
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'movsx ecx, word ptr [eax]'

// address: 0x1000D205
p1000D205
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-28, 4) = 0x00000000;
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-20, 4) = 0x00000000;
    goto l1000D233;
}
Can't parse line: l1000D22A: mov ecx, dword ptr [ebp-014h]

// address: 0x1000D320
p1000D320
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    unknown_function_1000E360(STACKVAR(8, 4), 0x00000000);
    REGDEF(edx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 172, 1)))
}
Failed to find pattern for 'test edx, edx'

// address: 0x1000D450
p1000D450
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000040);
    ACCESS(STACKVAR(8, 4), 316, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000D523);
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 172, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x1000D523
p1000D523
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 316, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 172, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000D5A2
p1000D5A2
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 316, 4);
}
Can't parse line: l1000D5B2: mov edx, dword ptr [ebp-004h]

// address: 0x1000D6A0
p1000D6A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000020);
    ACCESS(STACKVAR(8, 4), 328, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000D842);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x1000DA83);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x1000DE6D);
    ACCESS(STACKVAR(-4, 4), 12, 4) = GLOBAL(0x1000E27A);
    ACCESS(STACKVAR(-4, 4), 16, 4) = GLOBAL(0x1000E290);
    ACCESS(STACKVAR(-4, 4), 20, 4) = GLOBAL(0x1000D719);
    ACCESS(STACKVAR(-4, 4), 24, 4) = GLOBAL(0x1000D82D);
    ACCESS(STACKVAR(-4, 4), 28, 4) = 0x00000000;
}

// address: 0x1000D719
p1000D719
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x0000FFFD)
}
Failed to find pattern for 'jbe l1000D73F'

// address: 0x1000D764
p1000D764
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D78A(STACKVAR(8, 4), 0x000000FF);
    unknown_function_1000D78A(STACKVAR(8, 4), STACKVAR(12, 4));
}

// address: 0x1000D78A
p1000D78A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    ACCESS(ACCESS(STACKVAR(-4, 4), 0, 4), 0, 1) = STACKVAR(12, 1);
    ACCESS(STACKVAR(-4, 4), 0, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 0, 4)) + 0x00000001;
    REGDEF(eax=ACCESS(STACKVAR(-4, 4), 4, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x1000D7FA
p1000D7FA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D78A(STACKVAR(8, 4), reinterpret_cast<int>(STACKVAR(12, 4)) >> 8 & 0x000000FF);
    unknown_function_1000D78A(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF);
}

// address: 0x1000D82D
p1000D82D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D78A(STACKVAR(8, 4), STACKVAR(12, 4));
}

// address: 0x1000D842
p1000D842
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 328, 4);
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000D8);
    ACCESS(STACKVAR(-4, 4), 28, 4) = 0x00000000;
    REGDEF(edx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 192, 1)))
}
Failed to find pattern for 'test edx, edx'

// address: 0x1000D8A7
p1000D8A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000E0);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000010);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x0000004A);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000046);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000049);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000046);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000000);
    unknown_function_1000D78A(STACKVAR(8, 4), static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 193, 1)));
    unknown_function_1000D78A(STACKVAR(8, 4), static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 194, 1)));
    unknown_function_1000D78A(STACKVAR(8, 4), static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 195, 1)));
    unknown_function_1000D7FA(STACKVAR(8, 4), static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 196, 2)));
    unknown_function_1000D7FA(STACKVAR(8, 4), static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 198, 2)));
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000000);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000000);
}

// address: 0x1000D9A7
p1000D9A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000EE);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x0000000E);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000041);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000064);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x0000006F);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000062);
    unknown_function_1000D78A(STACKVAR(8, 4), 0x00000065);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000064);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000000);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000000);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 60, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000003)
    {
        goto l1000DA51;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000005)
    {
        goto l1000DA61;
    }
    goto l1000DA71;
}
Can't parse line: l1000DA51: push 000000001h

// address: 0x1000DA83
p1000DA83
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 64, 4);
    goto l1000DAB4;
}
Can't parse line: l1000DAA2: mov edx, dword ptr [ebp-010h]

// address: 0x1000DBFF
p1000DBFF
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4), ecx=STACKVAR(8, 4))
}
Failed to find pattern for 'mov edx, dword ptr [ecx+eax*04h+044h]'

// address: 0x1000DD3E
p1000DD3E
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    unknown_function_1000D764(STACKVAR(8, 4), STACKVAR(12, 4));
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000003 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 56, 4)) + 0x00000008);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 32, 4), cmpr=0x0000FFFF)
}
Failed to find pattern for 'jg l1000DD85'

// address: 0x1000DE6D
p1000DE6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 328, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 173, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000DF93
p1000DF93
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(16, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1000E0E2
p1000E0E2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x1000E0E7
p1000E0E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000DD);
    unknown_function_1000D7FA(STACKVAR(8, 4), 0x00000004);
    unknown_function_1000D7FA(STACKVAR(8, 4), ACCESS(STACKVAR(8, 4), 184, 4));
}

// address: 0x1000E121
p1000E121
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000DA);
    unknown_function_1000D7FA(STACKVAR(8, 4), 2 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 224, 4)) + 6);
    unknown_function_1000D78A(STACKVAR(8, 4), ACCESS(STACKVAR(8, 4), 224, 4));
    STACKVAR(-8, 4) = 0x00000000;
    goto l1000E17A;
}
Can't parse line: l1000E171: mov edx, dword ptr [ebp-008h]

// address: 0x1000E27A
p1000E27A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000D9);
}

// address: 0x1000E290
p1000E290
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    unknown_function_1000D764(STACKVAR(8, 4), 0x000000D8);
    STACKVAR(-4, 4) = 0x00000000;
    goto l1000E2B7;
}
Can't parse line: l1000E2AE: mov ecx, dword ptr [ebp-004h]

// address: 0x1000E360
p1000E360
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000020);
    ACCESS(STACKVAR(8, 4), 312, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1000EDE2);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x1000F4DE);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x1000F516);
    ACCESS(STACKVAR(-4, 4), 13, 1) = 0;
    unknown_function_1000E487(STACKVAR(8, 4));
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 168, 4)) == 0x00000000)
    {
        goto l1000E3D0;
    }
    unknown_function_1000E7C0(STACKVAR(8, 4));
    goto l1000E3E7;
}
Can't parse line: l1000E3D0: mov eax, dword ptr [ebp+008h]

// address: 0x1000E487
p1000E487
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 32, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jbe l1000E4B1'

// address: 0x1000E7C0
p1000E7C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=2616, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 164, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jg l1000E7FB'

// address: 0x1000EDE2
p1000EDE2
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 312, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-4, 4), 16, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000000)
    {
        goto l1000EE1C;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000001)
    {
        goto l1000EF04;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000002)
    {
        goto l1000EF90;
    }
}
Failed to find pattern for 'jmp near ptr l1000F017'

// address: 0x1000F076
p1000F076
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 168, 4)) == 0x00000000)
    {
        goto l1000F13E;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 312, 4);
    STACKVAR(-12, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 168, 4)) + 0x00000024 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 28, 4));
    ACCESS(STACKVAR(8, 4), 224, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    STACKVAR(-4, 4) = 0x00000000;
    goto l1000F0CF;
}
Can't parse line: l1000F0C6: mov ecx, dword ptr [ebp-004h]

// address: 0x1000F1FC
p1000F1FC
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 224, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jne l1000F2B7'

// address: 0x1000F4DE
p1000F4DE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 312, 4), 12, 1) = 0;
    ACCESS(ACCESS(STACKVAR(8, 4), 328, 4), 4, 4)(STACKVAR(8, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 328, 4), 8, 4)(STACKVAR(8, 4));
}

// address: 0x1000F516
p1000F516
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 312, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 344, 4), 8, 4)(STACKVAR(8, 4));
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-4, 4), 16, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000000)
    {
        goto l1000F558;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000001)
    {
        goto l1000F582;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000002)
    {
        goto l1000F58E;
    }
    goto l1000F5B6;
}
Can't parse line: l1000F558: mov ecx, dword ptr [ebp-004h]

// address: 0x1000F5D0
p1000F5D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000F5DF'

// address: 0x1000F640
p1000F640
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 4, 4)) == 0x00000000)
    {
        goto l1000F65C;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 40, 4)(STACKVAR(8, 4));
}
Can't parse line: l1000F65C: mov ecx, dword ptr [ebp+008h]

// address: 0x1000F672
p1000F672
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000000, 0x00000082);
    ACCESS(STACKVAR(-4, 4), 128, 1) = 0;
    REGDEF(eax=STACKVAR(-4, 4))
}

// address: 0x1000F6A0
p1000F6A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000000, 0x00000112);
    ACCESS(STACKVAR(-4, 4), 273, 1) = 0;
    REGDEF(eax=STACKVAR(-4, 4))
}

// address: 0x1000F6D0
p1000F6D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000064)
    {
        goto l1000F707;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1000F707: cmp dword ptr [ebp+00Ch], 000000000h

// address: 0x1000F7ED
p1000F7ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000F6D0(STACKVAR(8, 4), 0x00000000, GLOBAL(0x100422D4), STACKVAR(12, 4), STACKVAR(16, 1));
    unknown_function_1000F6D0(STACKVAR(8, 4), 0x00000001, GLOBAL(0x100423D4), STACKVAR(12, 4), STACKVAR(16, 1));
}

// address: 0x1000F828
p1000F828
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jg l1000F838'

// address: 0x1000F86D
p1000F86D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    STACKVAR(12, 4) = unknown_function_1000F828(STACKVAR(12, 4));
    unknown_function_1000F7ED(STACKVAR(8, 4), STACKVAR(12, 4), STACKVAR(16, 1));
}

// address: 0x1000F895
p1000F895
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000064)
    {
        goto l1000F8CA;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1000F8CA: mov ecx, dword ptr [ebp+008h]

// address: 0x1000FA22
p1000FA22
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000FA9B(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000054, GLOBAL(0x100424D4), GLOBAL(0x100424E8));
    unknown_function_1000FA9B(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000064, GLOBAL(0x10042514), GLOBAL(0x10042528));
    unknown_function_1000FA9B(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000058, GLOBAL(0x100424F4), GLOBAL(0x10042508));
    unknown_function_1000FA9B(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000068, GLOBAL(0x100425CC), GLOBAL(0x100425E0));
}

// address: 0x1000FA9B
p1000FA9B
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1000FABC'

// address: 0x1000FB6A
p1000FB6A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 40, 4);
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=0x00000005)
}
Failed to find pattern for 'ja l1000FBE7'

// address: 0x1000FC1D
p1000FC1D
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x00000064)
    {
        goto l1000FC54;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1000FC54: mov ecx, dword ptr [ebp+008h]

// address: 0x100104D2
p100104D2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(STACKVAR(8, 4), 0, 4) = 0x00000001;
    ACCESS(STACKVAR(8, 4), 4, 4) = STACKVAR(12, 4);
    ACCESS(STACKVAR(8, 4), 20, 4) = STACKVAR(16, 4);
    ACCESS(STACKVAR(8, 4), 24, 4) = STACKVAR(20, 4);
    ACCESS(STACKVAR(8, 4), 28, 4) = STACKVAR(24, 4);
    ACCESS(STACKVAR(8, 4), 32, 4) = STACKVAR(28, 4);
    STACKVAR(8, 4) = reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000024;
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10010519
p10010519
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l1001052F;
}
Can't parse line: l10010526: mov eax, dword ptr [ebp-004h]

// address: 0x1001057F
p1001057F
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000004)
}
Failed to find pattern for 'jg l100105EB'

// address: 0x10010620
p10010620
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000006C);
    ACCESS(STACKVAR(8, 4), 344, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10010695);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10010663;
}
Can't parse line: l1001065A: mov eax, dword ptr [ebp-008h]

// address: 0x10010695
p10010695
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    ACCESS(STACKVAR(-12, 4), 32, 4) = STACKVAR(8, 4);
    ACCESS(STACKVAR(-12, 4), 12, 1) = STACKVAR(12, 1);
    REGDEF(ecx=0x00000000, cmpl=ACCESS(STACKVAR(8, 4), 296, 4), cmpr=0x00000000)
}
Failed to find pattern for 'sete  cl'

// address: 0x100108CB
p100108CB
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 308, 4);
    ACCESS(STACKVAR(-12, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    ACCESS(STACKVAR(-12, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 184, 4)) == 0x00000000)
    {
        goto l1001092E;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-12, 4), 68, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001092E'

// address: 0x10010AB0
p10010AB0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 28, 4);
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10010AEE'

// address: 0x10010C02
p10010C02
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 32, 4), 24, 4);
    REGDEF(eax=ACCESS(STACKVAR(-4, 4), 12, 4)(ACCESS(STACKVAR(8, 4), 32, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10010C69
p10010C69
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 12, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10010CD3
p10010CD3
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    unknown_function_10010E04(STACKVAR(8, 4));
    REGDEF(edx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 12, 1)))
}
Failed to find pattern for 'test edx, edx'

// address: 0x10010DDB
p10010DDB
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10010AB0(STACKVAR(8, 4), 0x0000007F, 0x00000007);
    ACCESS(STACKVAR(8, 4), 24, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 28, 4) = 0x00000000;
}

// address: 0x10010E04
p10010E04
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 56, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jbe l10010ECE'

// address: 0x10010ED2
p10010ED2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 12, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10010F14
p10010F14
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 300, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 308, 4);
    ACCESS(STACKVAR(-16, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    ACCESS(STACKVAR(-16, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 184, 4)) == 0x00000000)
    {
        goto l10010F83;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-16, 4), 68, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10010F83'

// address: 0x1001117B
p1001117B
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 308, 4);
    ACCESS(STACKVAR(-8, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    ACCESS(STACKVAR(-8, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 184, 4)) == 0x00000000)
    {
        goto l100111DE;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 68, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100111DE'

// address: 0x100112A0
p100112A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=296, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 300, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 308, 4);
    ACCESS(STACKVAR(-16, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    ACCESS(STACKVAR(-16, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 184, 4)) == 0x00000000)
    {
        goto l10011312;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-16, 4), 68, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10011312'

// address: 0x10011641
p10011641
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    ACCESS(STACKVAR(-4, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4);
    ACCESS(STACKVAR(-4, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4);
    unknown_function_10010E04(STACKVAR(-4, 4));
    unknown_function_10010DDB(STACKVAR(-4, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 0, 4) = ACCESS(STACKVAR(-4, 4), 16, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 24, 4), 4, 4) = ACCESS(STACKVAR(-4, 4), 20, 4);
}

// address: 0x100116A7
p100116A7
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 344, 4);
    unknown_function_10010E04(STACKVAR(-12, 4));
    REGDEF(ecx=0x00000000, cmpl=ACCESS(STACKVAR(8, 4), 296, 4), cmpr=0x00000000)
}
Failed to find pattern for 'sete  cl'

// address: 0x100117C0
p100117C0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100118C1
p100118C1
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 320, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x00000000)
    {
        goto l100118F1;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000004;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l100118F1: mov ecx, dword ptr [ebp-004h]

// address: 0x10011926
p10011926
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 320, 4);
}
Can't parse line: l10011938: mov edx, dword ptr [ebp+010h]

// address: 0x10011B35
p10011B35
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = STACKVAR(16, 4);
    goto l10011B4A;
}
Can't parse line: l10011B41: mov ecx, dword ptr [ebp-004h]

// address: 0x10011B79
p10011B79
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 320, 4);
    STACKVAR(-8, 4) = 0x00000003 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 216, 4));
}
Can't parse line: l10011B9A: mov ecx, dword ptr [ebp+01Ch]

// address: 0x10011DDE
p10011DDE
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 320, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 216, 4);
    REGDEF(edx=0x00000005 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 56, 4)))
}
Failed to find pattern for 'imul edx, dword ptr [ebp-01Ch]'

// address: 0x10011F30
p10011F30
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 1) = 0x01;
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000034);
    ACCESS(STACKVAR(8, 4), 336, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10012153);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x10012158);
    ACCESS(STACKVAR(-4, 4), 8, 1) = 0;
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 175, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x10012153
p10012153
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10012158
p10012158
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 336, 4);
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 64, 4);
    goto l1001218E;
}
Can't parse line: l1001217C: mov ecx, dword ptr [ebp-014h]

// address: 0x100121E7
p100121E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 28, 4));
    STACKVAR(-20, 4) = reinterpret_cast<int>(ACCESS(STACKVAR(8, 4), 212, 4)) / reinterpret_cast<int>(ACCESS(STACKVAR(12, 4), 8, 4));
    STACKVAR(-44, 4) = reinterpret_cast<int>(ACCESS(STACKVAR(8, 4), 216, 4)) / reinterpret_cast<int>(ACCESS(STACKVAR(12, 4), 12, 4));
    REGDEF(edx=STACKVAR(-20, 4))
}
Failed to find pattern for 'imul edx, dword ptr [ebp-02Ch]'

// address: 0x10012353
p10012353
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    REGDEF(eax=STACKVAR(20, 4))
}
Failed to find pattern for 'sub eax, dword ptr [ebp+010h]'

// address: 0x100123CA
p100123CA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100268D1(STACKVAR(16, 4), 0x00000000, STACKVAR(20, 4), 0x00000000, ACCESS(STACKVAR(8, 4), 216, 4), ACCESS(STACKVAR(8, 4), 28, 4));
    unknown_function_10012353(STACKVAR(20, 4), ACCESS(STACKVAR(8, 4), 216, 4), ACCESS(STACKVAR(8, 4), 28, 4), 0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 28, 4)));
}

// address: 0x1001241B
p1001241B
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 28, 4));
    unknown_function_10012353(STACKVAR(16, 4), ACCESS(STACKVAR(8, 4), 216, 4), ACCESS(STACKVAR(8, 4), 28, 4), 0x00000002 * reinterpret_cast<any_int32>(STACKVAR(-4, 4)));
    STACKVAR(-16, 4) = 0x00000000;
    goto l10012462;
}
Can't parse line: l10012459: mov edx, dword ptr [ebp-010h]

// address: 0x100124E9
p100124E9
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
}
Failed to find pattern for 'push ebx'

// address: 0x100125F5
p100125F5
{
    ProcedureInfo(this=None, this_offset=None, local_size=52, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 28, 4));
    ARG(0x00000002 * reinterpret_cast<any_int32>(STACKVAR(-8, 4)));
    ARG(ACCESS(STACKVAR(8, 4), 28, 4));
    ARG(reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 216, 4)) + 0x00000002);
    REGDEF(ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'sub ecx, 000000004h'

// address: 0x100129B4
p100129B4
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 28, 4));
    ARG(STACKVAR(-8, 4));
    ARG(ACCESS(STACKVAR(8, 4), 28, 4));
    ARG(reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 216, 4)) + 0x00000002);
    REGDEF(ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'sub ecx, 000000004h'

// address: 0x10012FCC
p10012FCC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 36, 4) = 0x00000001;
    unknown_function_1000E360(STACKVAR(8, 4), 0x00000001);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 173, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001307B
p1001307B
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000044);
    ACCESS(STACKVAR(8, 4), 324, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001311D);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x100131E1);
    ACCESS(STACKVAR(-4, 4), 24, 4) = STACKVAR(12, 4);
    STACKVAR(-12, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 4, 4)(STACKVAR(8, 4), 0x00000001, 0x00000500);
    unknown_function_10026972(STACKVAR(-12, 4), 0x00000500);
    STACKVAR(-8, 4) = 0x00000000;
    goto l100130FC;
}
Can't parse line: l100130F3: mov ecx, dword ptr [ebp-008h]

// address: 0x1001311D
p1001311D
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x00000002)
    {
        goto l1001314D;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000004;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1001314D: mov ecx, dword ptr [ebp-004h]

// address: 0x10013167
p10013167
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 224, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jle l1001318F'

// address: 0x100131E1
p100131E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=112, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 324, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 244, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10013490
p10013490
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 4, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x0000003E)
    {
        goto l100134D8;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000000C;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = 0x0000003E;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 28, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l100134D8: cmp dword ptr [ebp+010h], 0000001ACh

// address: 0x10013602
p10013602
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1000F640(STACKVAR(8, 4));
}

// address: 0x10013624
p10013624
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000C8)
    {
        goto l1001366A;
    }
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000C9)
    {
        goto l1001366A;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1001366A: mov edx, dword ptr [ebp+008h]

// address: 0x100136D7
p100136D7
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    REGDEF(edx=STACKVAR(-8, 4))
}
Failed to find pattern for 'sub edx, 0000000C8h'

// address: 0x100137E3
p100137E3
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 36, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-20, 4)) == 0x00000001)
    {
        goto l1001380D;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-20, 4)) == 0x00000003)
    {
        goto l10013826;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-20, 4)) == 0x00000004)
    {
        goto l10013990;
    }
}
Failed to find pattern for 'jmp near ptr l10013A23'

// address: 0x10013B69
p10013B69
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000CD)
    {
        goto l10013B84;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 20, 4), cmpr=0x000000CE)
}
Failed to find pattern for 'jne l10013BD7'

// address: 0x10013C80
p10013C80
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 20, 4), cmpr=0x000000CA)
}
Failed to find pattern for 'jne l10013CC3'

// address: 0x10013DDE
p10013DDE
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000CC)
    {
        goto l10013E14;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 384, 4), 0, 4)(STACKVAR(8, 4));
    ACCESS(STACKVAR(8, 4), 120, 4) = 0x00000000;
    REGDEF(edx=STACKVAR(8, 4))
}
Can't parse line: l10013E14: mov eax, dword ptr [ebp+008h]

// address: 0x10013EFA
p10013EFA
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000CD)
    {
        goto l10013F32;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10013F32: mov ecx, dword ptr [ebp+008h]

// address: 0x10014240
p10014240
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 24, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10014266'

// address: 0x1001429A
p1001429A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    ACCESS(STACKVAR(-4, 4), 24, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00001000);
    ACCESS(STACKVAR(-4, 4), 0, 4) = ACCESS(STACKVAR(-4, 4), 24, 4);
    ACCESS(STACKVAR(-4, 4), 4, 4) = 0x00001000;
}

// address: 0x100142DC
p100142DC
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    if (fwrite(ACCESS(STACKVAR(-4, 4), 24, 4), 0x00000001, 0x00001000, ACCESS(STACKVAR(-4, 4), 20, 4)) == 0x00001000)
    {
        goto l10014328;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000025;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10014328: mov edx, dword ptr [ebp-004h]

// address: 0x10014343
p10014343
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    REGDEF(edx=STACKVAR(-4, 4), eax=0x00001000)
}
Failed to find pattern for 'sub eax, dword ptr [edx+004h]'

// address: 0x100143E0
p100143E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 24, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001442B'

// address: 0x10014486
p10014486
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    ACCESS(STACKVAR(-4, 4), 36, 1) = 0x01;
}

// address: 0x1001449E
p1001449E
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-4, 4) = fread(ACCESS(STACKVAR(-8, 4), 32, 4), 0x00000001, 0x00001000, ACCESS(STACKVAR(-8, 4), 28, 4));
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'ja l10014531'

// address: 0x10014552
p10014552
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jle l100145A6'

// address: 0x100145AA
p100145AA
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x100145B0
p100145B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000074);
    ACCESS(STACKVAR(8, 4), 392, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001473B);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x100147D6);
    ACCESS(STACKVAR(-4, 4), 112, 4) = 0x00000000;
    REGDEF(edx=reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF)
}
Failed to find pattern for 'test edx, edx'

// address: 0x1001473B
p1001473B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(STACKVAR(8, 4), 128, 4) = 0x00000000;
    unknown_function_10014759(STACKVAR(8, 4));
}

// address: 0x10014759
p10014759
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 292, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jle l10014781'

// address: 0x100147D6
p100147D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 16, 4)) == 0x00000000)
    {
        goto l10014826;
    }
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 73, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10014837
p10014837
{
    ProcedureInfo(this=None, this_offset=None, local_size=64, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 312, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10014AED
p10014AED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10014AF4
p10014AF4
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    STACKVAR(-36, 4) = 0x00000000;
    goto l10014B18;
}
Can't parse line: l10014B0F: mov edx, dword ptr [ebp-024h]

// address: 0x10014D2D
p10014D2D
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 284, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10014F46
p10014F46
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    STACKVAR(-16, 1) = 0;
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 200, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x100150C1
p100150C1
{
    ProcedureInfo(this=None, this_offset=None, local_size=284, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 392, 4);
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 284, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10015B20
p10015B20
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000018);
    ACCESS(STACKVAR(8, 4), 420, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001636E);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 40, 4);
    REGDEF(edx=STACKVAR(-12, 4))
}
Failed to find pattern for 'sub edx, 000000001h'

// address: 0x10015DFC
p10015DFC
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 420, 4);
    ACCESS(STACKVAR(-12, 4), 8, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 12, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 4) = 0xFFFFFF80;
    goto l10015EA0;
}
Can't parse line: l10015E8E: mov edx, dword ptr [ebp-008h]

// address: 0x10015F1D
p10015F1D
{
    ProcedureInfo(this=None, this_offset=None, local_size=60, stack_delta=None)
    STACKVAR(-56, 4) = ACCESS(STACKVAR(8, 4), 420, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-44, 4) = ACCESS(STACKVAR(-56, 4), 8, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-56, 4), 12, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-56, 4), 16, 4);
    STACKVAR(-60, 4) = ACCESS(STACKVAR(-56, 4), 20, 4);
}
Can't parse line: l10015F68: mov edx, dword ptr [ebp+018h]

// address: 0x10016072
p10016072
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 36, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
}
Can't parse line: l1001608A: mov ecx, dword ptr [ebp+018h]

// address: 0x10016126
p10016126
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100268D1(ACCESS(STACKVAR(12, 4), 0, 4), STACKVAR(16, 4), STACKVAR(20, 4), 0x00000000, STACKVAR(24, 4), ACCESS(STACKVAR(8, 4), 92, 4));
}

// address: 0x1001614E
p1001614E
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
}
Can't parse line: l1001615D: mov edx, dword ptr [ebp+018h]

// address: 0x100161E7
p100161E7
{
    ProcedureInfo(this=None, this_offset=None, local_size=64, stack_delta=None)
    STACKVAR(-60, 4) = ACCESS(STACKVAR(8, 4), 420, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-44, 4) = ACCESS(STACKVAR(-60, 4), 8, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-60, 4), 12, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-60, 4), 16, 4);
    STACKVAR(-64, 4) = ACCESS(STACKVAR(-60, 4), 20, 4);
}
Can't parse line: l10016232: mov edx, dword ptr [ebp+018h]

// address: 0x1001636E
p1001636E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10016380
p10016380
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000054);
    ACCESS(STACKVAR(8, 4), 412, 4) = STACKVAR(-12, 4);
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10016424);
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 196, 4);
    goto l100163D9;
}
Can't parse line: l100163C7: mov edx, dword ptr [ebp-008h]

// address: 0x10016424
p10016424
{
    ProcedureInfo(this=None, this_offset=None, local_size=64, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 412, 4);
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-28, 4) = 0x00000000;
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 196, 4);
    goto l1001646B;
}
Can't parse line: l10016459: mov ecx, dword ptr [ebp-014h]

// address: 0x10016730
p10016730
{
    ProcedureInfo(this=None, this_offset=None, local_size=1336, stack_delta=None)
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jl l10016746'

// address: 0x10016BF7
p10016BF7
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 16, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 380, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10016D2E'

// address: 0x10016DB2
p10016DB2
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = STACKVAR(24, 4);
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=STACKVAR(-4, 4))
}
Failed to find pattern for 'jnl l10016E02'

// address: 0x10016F06
p10016F06
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x000000AC);
    ACCESS(STACKVAR(8, 4), 408, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10016F7E);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x10017160);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10016F56;
}
Can't parse line: l10016F4D: mov ecx, dword ptr [ebp-008h]

// address: 0x10016F7E
p10016F7E
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 364, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10016FC1'

// address: 0x10017160
p10017160
{
    ProcedureInfo(this=None, this_offset=None, local_size=112, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 252, 4)) == 0x00000000)
    {
        goto l100171A3;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 36, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100171A3'

// address: 0x10017795
p10017795
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    REGDEF(ecx=ACCESS(STACKVAR(8, 4), 404, 4), eax=ACCESS(STACKVAR(-4, 4), 16, 4))
}
Failed to find pattern for 'cdq'

// address: 0x10017860
p10017860
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000000, 0x00000018);
    ACCESS(STACKVAR(8, 4), 400, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10017CAB);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x100180D6);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x100178C6);
    ACCESS(STACKVAR(-4, 4), 12, 4) = GLOBAL(0x10017C97);
    ACCESS(STACKVAR(-4, 4), 16, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 17, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 20, 1) = 0x01;
}

// address: 0x100178C6
p100178C6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1001791E(STACKVAR(8, 4));
    unknown_function_10017BC0(STACKVAR(8, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 408, 4), 0, 4)(STACKVAR(8, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 392, 4), 0, 4)(STACKVAR(8, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 400, 4), 0, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 392, 4), 4, 4);
}

// address: 0x1001791E
p1001791E
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 292, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jne l100179DB'

// address: 0x10017BC0
p10017BC0
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    goto l10017BDA;
}
Can't parse line: l10017BD1: mov eax, dword ptr [ebp-010h]

// address: 0x10017C97
p10017C97
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 400, 4), 0, 4) = GLOBAL(0x10017CAB);
}

// address: 0x10017CAB
p10017CAB
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 400, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(-8, 4), 17, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x10017DBD
p10017DBD
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 32, 4), cmpr=0x0000FFDC)
}
Failed to find pattern for 'jg l10017DDB'

// address: 0x100180D6
p100180D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 400, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10017CAB);
    ACCESS(STACKVAR(-4, 4), 16, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 17, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 20, 1) = 0x01;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 16, 4)(STACKVAR(8, 4));
    ACCESS(ACCESS(STACKVAR(8, 4), 404, 4), 0, 4)(STACKVAR(8, 4));
    ACCESS(STACKVAR(8, 4), 140, 4) = 0x00000000;
}

// address: 0x10018140
p10018140
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000050);
    ACCESS(STACKVAR(8, 4), 388, 4) = STACKVAR(-8, 4);
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10018398);
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(12, 4)) & 0x000000FF)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10018280
p10018280
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 280, 4);
    ACCESS(STACKVAR(-8, 4), 56, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000004 * 0x00000002 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 36, 4)));
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 36, 4), edx=ACCESS(STACKVAR(-8, 4), 56, 4))
}
Failed to find pattern for 'lea eax, [edx+eax*04h]'

// address: 0x10018398
p10018398
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000000)
    {
        goto l100183BE;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000002)
    {
        goto l10018423;
    }
    goto l1001842F;
}
Can't parse line: l100183BE: mov eax, dword ptr [ebp+008h]

// address: 0x1001844D
p1001844D
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(8, 4), 280, 4);
    STACKVAR(-28, 4) = 0x00000000;
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 196, 4);
    goto l10018493;
}
Can't parse line: l10018481: mov eax, dword ptr [ebp-01Ch]

// address: 0x100185CF
p100185CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(-8, 4), 48, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x10018671
p10018671
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(-4, 4), 48, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x10018845
p10018845
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 280, 4);
    STACKVAR(-24, 4) = 0x00000000;
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 196, 4);
    goto l1001888B;
}
Can't parse line: l10018879: mov eax, dword ptr [ebp-018h]

// address: 0x1001897D
p1001897D
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 388, 4);
    STACKVAR(-28, 4) = 0x00000000;
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 196, 4);
    goto l100189B7;
}
Can't parse line: l100189A5: mov ecx, dword ptr [ebp-01Ch]

// address: 0x10018A6D
p10018A6D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 396, 4), 4, 4)(STACKVAR(8, 4), 0x00000000, 0x00000000, 0x00000000, STACKVAR(12, 4), STACKVAR(16, 4), STACKVAR(20, 4));
}

// address: 0x10018AA0
p10018AA0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 380, 4);
    STACKVAR(-4, 4) = 0x00000001;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000079;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = STACKVAR(-8, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 28, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 4, 4)(STACKVAR(8, 4), 0xFFFFFFFF);
}
Can't parse line: l10018AEC: cmp dword ptr [ebp-008h], 0000000C0h

// address: 0x10018C16
p10018C16
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-8, 4), 0, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-8, 4), 4, 4);
}
Can't parse line: l10018C36: cmp dword ptr [ebp-00Ch], 000000000h

// address: 0x10018E36
p10018E36
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000000, 0x000000A8);
    ACCESS(STACKVAR(8, 4), 404, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001B79A);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x10019770);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x1001B6C6);
    ACCESS(STACKVAR(-4, 4), 24, 4) = GLOBAL(0x1001962B);
    ACCESS(STACKVAR(-4, 4), 92, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000000;
    goto l10018EA4;
}
Can't parse line: l10018E9B: mov ecx, dword ptr [ebp-008h]

// address: 0x10018EEC
p10018EEC
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-40, 4) = ACCESS(STACKVAR(-24, 4), 0, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(-24, 4), 4, 4);
}
Can't parse line: l10018F0C: cmp dword ptr [ebp-020h], 000000000h

// address: 0x10019118
p10019118
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(16, 4)) + reinterpret_cast<any_int32>(STACKVAR(20, 4));
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x0000000E)
}
Failed to find pattern for 'jb l10019378'

// address: 0x100194DC
p100194DC
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x0000000C)
}
Failed to find pattern for 'jb l100195FC'

// address: 0x1001962B
p1001962B
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-8, 4), 0, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-8, 4), 4, 4);
}
Can't parse line: l1001964B: cmp dword ptr [ebp-00Ch], 000000000h

// address: 0x10019770
p10019770
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
}
Can't parse line: l10019774: mov eax, dword ptr [ebp+008h]

// address: 0x10019BF8
p10019BF8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000066;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 4, 4)(STACKVAR(8, 4), 0x00000001);
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(ACCESS(STACKVAR(8, 4), 404, 4), 12, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10019D0E
p10019D0E
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-12, 4), 4, 4);
    ACCESS(STACKVAR(8, 4), 200, 1) = STACKVAR(12, 1);
    ACCESS(STACKVAR(8, 4), 201, 1) = STACKVAR(16, 1);
}
Can't parse line: l10019D46: cmp dword ptr [ebp-010h], 000000000h

// address: 0x1001A32B
p1001A32B
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-16, 4), 0, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(-16, 4), 4, 4);
    REGDEF(edx=static_cast<unsigned int>(ACCESS(ACCESS(STACKVAR(8, 4), 404, 4), 13, 1)))
}
Failed to find pattern for 'test edx, edx'

// address: 0x1001A86C
p1001A86C
{
    ProcedureInfo(this=None, this_offset=None, local_size=316, stack_delta=None)
    STACKVAR(-288, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-304, 4) = ACCESS(STACKVAR(-288, 4), 0, 4);
    STACKVAR(-296, 4) = ACCESS(STACKVAR(-288, 4), 4, 4);
}
Can't parse line: l1001A8A0: cmp dword ptr [ebp-000000128h], 000000000h

// address: 0x1001AF2C
p1001AF2C
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(-12, 4), 4, 4);
}
Can't parse line: l1001AF4C: cmp dword ptr [ebp-01Ch], 000000000h

// address: 0x1001B3A6
p1001B3A6
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-12, 4), 4, 4);
}
Can't parse line: l1001B3C6: cmp dword ptr [ebp-010h], 000000000h

// address: 0x1001B595
p1001B595
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-12, 4), 0, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-12, 4), 4, 4);
}
Can't parse line: l1001B5B5: cmp dword ptr [ebp-010h], 000000000h

// address: 0x1001B6C6
p1001B6C6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 380, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001B6F1'

// address: 0x1001B79A
p1001B79A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 404, 4);
    ACCESS(STACKVAR(8, 4), 196, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 124, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 380, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 12, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 13, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 20, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 160, 4) = 0x00000000;
}

// address: 0x1001B8FD
p1001B8FD
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 404, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-20, 4), 160, 4);
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 24, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(-16, 4), 0, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(-16, 4), 4, 4);
    REGDEF(cmpl=STACKVAR(-36, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001BAE2'

// address: 0x1001BD40
p1001BD40
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 20, 4)) == 0x000000CA)
    {
        goto l1001BD7A;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000014;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = ACCESS(STACKVAR(8, 4), 20, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l1001BD7A: mov ecx, dword ptr [ebp+008h]

// address: 0x1001C089
p1001C089
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(ecx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 72, 1)))
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x1001C23B
p1001C23B
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000001C);
    ACCESS(STACKVAR(8, 4), 384, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001C6F1);
    ACCESS(STACKVAR(-4, 4), 4, 4) = GLOBAL(0x1001C912);
    ACCESS(STACKVAR(-4, 4), 8, 1) = 0;
    unknown_function_1001C28B(STACKVAR(8, 4));
}

// address: 0x1001C28B
p1001C28B
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 384, 4);
    unknown_function_1001BD40(STACKVAR(8, 4));
    unknown_function_1001C61D(STACKVAR(8, 4));
    REGDEF(edx=STACKVAR(8, 4), eax=ACCESS(STACKVAR(8, 4), 92, 4))
}
Failed to find pattern for 'imul eax, dword ptr [edx+064h]'

// address: 0x1001C61D
p1001C61D
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000580);
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000100;
    ACCESS(STACKVAR(8, 4), 288, 4) = STACKVAR(-4, 4);
    REGDEF(ecx=0x00000040, eax=0x00000000, edi=STACKVAR(-4, 4))
}
Failed to find pattern for 'sub edi, 000000100h'

// address: 0x1001C6F1
p1001C6F1
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 384, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(-4, 4), 8, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001C912
p1001C912
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 384, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 74, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001C960
p1001C960
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000030);
    ACCESS(STACKVAR(8, 4), 416, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001CB39);
    ACCESS(STACKVAR(-4, 4), 8, 1) = 0;
    REGDEF(edx=STACKVAR(8, 4), eax=ACCESS(STACKVAR(8, 4), 92, 4))
}
Failed to find pattern for 'imul eax, dword ptr [edx+064h]'

// address: 0x1001CA18
p1001CA18
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    ACCESS(STACKVAR(-12, 4), 16, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 24, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    ACCESS(STACKVAR(-12, 4), 28, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 4) = 0xFFFFFF80;
    goto l1001CABC;
}
Can't parse line: l1001CAAA: mov edx, dword ptr [ebp-008h]

// address: 0x1001CB39
p1001CB39
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    ACCESS(STACKVAR(-4, 4), 36, 1) = 0;
    ACCESS(STACKVAR(-4, 4), 44, 4) = ACCESS(STACKVAR(8, 4), 96, 4);
}

// address: 0x1001CB60
p1001CB60
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(-16, 4), 36, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001CC76
p1001CC76
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    REGDEF(eax=ACCESS(STACKVAR(28, 4), 0, 4), ecx=STACKVAR(24, 4))
}
Failed to find pattern for 'lea edx, [ecx+eax*04h]'

// address: 0x1001CCC7
p1001CCC7
{
    ProcedureInfo(this=None, this_offset=None, local_size=68, stack_delta=None)
    STACKVAR(-60, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-48, 4) = ACCESS(STACKVAR(-60, 4), 16, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-60, 4), 20, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-60, 4), 24, 4);
    STACKVAR(-68, 4) = ACCESS(STACKVAR(-60, 4), 28, 4);
    REGDEF(ecx=ACCESS(STACKVAR(12, 4), 0, 4), edx=STACKVAR(16, 4))
}
Failed to find pattern for 'mov eax, dword ptr [ecx+edx*04h]'

// address: 0x1001CEF2
p1001CEF2
{
    ProcedureInfo(this=None, this_offset=None, local_size=76, stack_delta=None)
    STACKVAR(-56, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-44, 4) = ACCESS(STACKVAR(-56, 4), 16, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-56, 4), 20, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-56, 4), 24, 4);
    STACKVAR(-76, 4) = ACCESS(STACKVAR(-56, 4), 28, 4);
    REGDEF(eax=0x00000002 * reinterpret_cast<any_int32>(STACKVAR(16, 4)), edx=ACCESS(STACKVAR(12, 4), 0, 4))
}
Failed to find pattern for 'mov eax, dword ptr [edx+eax*04h]'

// address: 0x1001D220
p1001D220
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000040);
    ACCESS(STACKVAR(8, 4), 408, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001D2FB);
    STACKVAR(-8, 4) = 0x00000000;
    goto l1001D263;
}
Can't parse line: l1001D25A: mov eax, dword ptr [ebp-008h]

// address: 0x1001D2FB
p1001D2FB
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    REGDEF(eax=0x00000000, cmpl=ACCESS(STACKVAR(8, 4), 364, 4), cmpr=0x00000000)
}
Failed to find pattern for 'sete  al'

// address: 0x1001D69E
p1001D69E
{
    ProcedureInfo(this=None, this_offset=None, local_size=96, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 376, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 252, 4)) == 0x00000000)
    {
        goto l1001D6EF;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 40, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001D6EF'

// address: 0x1001D97A
p1001D97A
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    REGDEF(ecx=ACCESS(STACKVAR(8, 4), 404, 4), eax=ACCESS(STACKVAR(-4, 4), 16, 4))
}
Failed to find pattern for 'cdq'

// address: 0x1001DA41
p1001DA41
{
    ProcedureInfo(this=None, this_offset=None, local_size=76, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(8, 4), 368, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 376, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 252, 4)) == 0x00000000)
    {
        goto l1001DA9C;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-28, 4), 40, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001DA9C'

// address: 0x1001DDAD
p1001DDAD
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    REGDEF(eax=0x00000001, ecx=ACCESS(STACKVAR(8, 4), 376, 4))
}
Failed to find pattern for 'shl eax, cl'

// address: 0x1001DEFE
p1001DEFE
{
    ProcedureInfo(this=None, this_offset=None, local_size=344, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 408, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(8, 4), 368, 4);
    REGDEF(edx=0x00000001, ecx=ACCESS(STACKVAR(8, 4), 376, 4))
}
Failed to find pattern for 'shl edx, cl'

// address: 0x1001E580
p1001E580
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000001C);
    ACCESS(STACKVAR(8, 4), 396, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1001E668);
    ACCESS(STACKVAR(-4, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 12, 4) = 0x00000000;
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 74, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001E668
p1001E668
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 396, 4);
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000000)
    {
        goto l1001E69B;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000002)
    {
        goto l1001E727;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-8, 4)) == 0x00000003)
    {
        goto l1001E6F8;
    }
}
Failed to find pattern for 'jmp near ptr l1001E756'

// address: 0x1001E788
p1001E788
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 396, 4);
    REGDEF(edx=STACKVAR(28, 4), eax=STACKVAR(32, 4))
}
Failed to find pattern for 'sub eax, dword ptr [edx]'

// address: 0x1001E829
p1001E829
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 396, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 24, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001E871'

// address: 0x1001E926
p1001E926
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 396, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 24, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1001E96E'

// address: 0x1001EA30
p1001EA30
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x000000A0);
    ACCESS(STACKVAR(8, 4), 416, 4) = STACKVAR(-20, 4);
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x1001ED04);
    ACCESS(STACKVAR(-20, 4), 4, 4) = GLOBAL(0x1001ED33);
    ACCESS(STACKVAR(-20, 4), 8, 1) = 0;
    REGDEF(eax=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 266, 1)))
}
Failed to find pattern for 'test eax, eax'

// address: 0x1001ED04
p1001ED04
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    ACCESS(STACKVAR(-4, 4), 92, 4) = ACCESS(STACKVAR(8, 4), 276, 4);
    ACCESS(STACKVAR(-4, 4), 96, 4) = ACCESS(STACKVAR(8, 4), 96, 4);
}

// address: 0x1001ED33
p1001ED33
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 92, 4), cmpr=ACCESS(STACKVAR(8, 4), 276, 4))
}
Failed to find pattern for 'jl l1001EDD1'

// address: 0x1001EE8E
p1001EE8E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(STACKVAR(20, 4), 0, 4) = STACKVAR(16, 4);
}

// address: 0x1001EE9B
p1001EE9B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(STACKVAR(20, 4), 0, 4) = 0x00000000;
}

// address: 0x1001EEA9
p1001EEA9
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(8, 4), 416, 4);
    STACKVAR(-40, 4) = ACCESS(STACKVAR(20, 4), 0, 4);
    STACKVAR(-8, 4) = static_cast<unsigned int>(ACCESS(ARRPTR(STACKVAR(-24, 4), 1, ACCESS(STACKVAR(12, 4), 4, 4), 140), 0, 1));
    STACKVAR(-28, 4) = static_cast<unsigned int>(ACCESS(ARRPTR(STACKVAR(-24, 4), 1, ACCESS(STACKVAR(12, 4), 4, 4), 150), 0, 1));
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-44, 4) = STACKVAR(-12, 4);
}
Can't parse line: l1001EEFA: mov ecx, dword ptr [ebp+008h]

// address: 0x1001EFBF
p1001EFBF
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(STACKVAR(20, 4), 0, 4);
    STACKVAR(-24, 4) = 0x00000000;
    goto l1001EFDF;
}
Can't parse line: l1001EFD6: mov edx, dword ptr [ebp-018h]

// address: 0x1001F054
p1001F054
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(20, 4), 0, 4);
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-28, 4) = STACKVAR(-8, 4);
}
Can't parse line: l1001F06F: mov eax, dword ptr [ebp+008h]

// address: 0x1001F121
p1001F121
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(20, 4), 0, 4);
    STACKVAR(-20, 4) = 0x00000000;
    goto l1001F141;
}
Can't parse line: l1001F138: mov edx, dword ptr [ebp-014h]

// address: 0x1001F26C
p1001F26C
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-32, 4) = ACCESS(STACKVAR(20, 4), 0, 4);
    STACKVAR(-24, 4) = 0x00000000;
    STACKVAR(-36, 4) = STACKVAR(-24, 4);
}
Can't parse line: l1001F287: mov eax, dword ptr [ebp+008h]

// address: 0x1001F5B0
p1001F5B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 64, 1) = 0x01;
    REGDEF(edx=static_cast<unsigned int>(ACCESS(STACKVAR(8, 4), 201, 1)))
}
Failed to find pattern for 'test edx, edx'

// address: 0x1001F6E0
p1001F6E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(STACKVAR(8, 4), 0, 4) = GLOBAL(0x1001F76C);
    ACCESS(STACKVAR(8, 4), 4, 4) = GLOBAL(0x1001F7D6);
    ACCESS(STACKVAR(8, 4), 8, 4) = GLOBAL(0x1001F794);
    ACCESS(STACKVAR(8, 4), 12, 4) = GLOBAL(0x1001F834);
    ACCESS(STACKVAR(8, 4), 16, 4) = GLOBAL(0x1001F977);
    ACCESS(STACKVAR(8, 4), 104, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 108, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 20, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 112, 4) = GLOBAL(0x10042848);
    ACCESS(STACKVAR(8, 4), 116, 4) = 0x0000007B;
    ACCESS(STACKVAR(8, 4), 120, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 124, 4) = 0x00000000;
    ACCESS(STACKVAR(8, 4), 128, 4) = 0x00000000;
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1001F76C
p1001F76C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 8, 4)(STACKVAR(8, 4));
    unknown_function_1000F640(STACKVAR(8, 4));
    exit(0x00000001);
}

// address: 0x1001F794
p1001F794
{
    ProcedureInfo(this=None, this_offset=None, local_size=200, stack_delta=None)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 12, 4)(STACKVAR(8, 4), LOCAL(-200));
    ARG(LOCAL(-200));
    ARG(GLOBAL(0x100487B4));
}
Failed to find pattern for 'mov edx, dword ptr [__imp__iob]; [BICRT._iob].'

// address: 0x1001F7D6
p1001F7D6
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jnl l1001F818'

// address: 0x1001F834
p1001F834
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 0, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-8, 4), 20, 4);
    STACKVAR(-16, 4) = 0x00000000;
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jle l1001F874'

// address: 0x1001F977
p1001F977
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 108, 4) = 0x00000000;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000000;
}

// address: 0x1001F9A0
p1001F9A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=84, stack_delta=None)
    STACKVAR(-76, 4) = STACKVAR(8, 4);
    STACKVAR(-56, 4) = 0x00000007;
    goto l1001F9BE;
}
Can't parse line: l1001F9B5: mov ecx, dword ptr [ebp-038h]

// address: 0x1001FD10
p1001FD10
{
    ProcedureInfo(this=None, this_offset=None, local_size=84, stack_delta=None)
    STACKVAR(-76, 4) = STACKVAR(8, 4);
    STACKVAR(-56, 4) = 0x00000007;
    goto l1001FD2E;
}
Can't parse line: l1001FD25: mov ecx, dword ptr [ebp-038h]

// address: 0x100200A0
p100200A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=76, stack_delta=None)
    STACKVAR(-68, 4) = STACKVAR(8, 4);
    STACKVAR(-48, 4) = 0x00000007;
    goto l100200BE;
}
Can't parse line: l100200B5: mov ecx, dword ptr [ebp-030h]

// address: 0x10020550
p10020550
{
    ProcedureInfo(this=None, this_offset=None, local_size=388, stack_delta=None)
    STACKVAR(-48, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-324, 4) = STACKVAR(16, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    STACKVAR(-56, 4) = LOCAL(-312);
    STACKVAR(-316, 4) = 0x00000008;
    goto l100205A1;
}
Can't parse line: l10020592: mov eax, dword ptr [ebp-00000013Ch]

// address: 0x10020C70
p10020C70
{
    ProcedureInfo(this=None, this_offset=None, local_size=356, stack_delta=None)
    STACKVAR(-48, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-324, 4) = STACKVAR(16, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    STACKVAR(-56, 4) = LOCAL(-312);
    STACKVAR(-316, 4) = 0x00000008;
    goto l10020CC1;
}
Can't parse line: l10020CB2: mov eax, dword ptr [ebp-00000013Ch]

// address: 0x10021410
p10021410
{
    ProcedureInfo(this=None, this_offset=None, local_size=340, stack_delta=None)
    STACKVAR(-44, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-316, 4) = STACKVAR(16, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    STACKVAR(-48, 4) = LOCAL(-304);
    STACKVAR(-308, 4) = 0x00000008;
    goto l10021461;
}
Can't parse line: l10021452: mov eax, dword ptr [ebp-000000134h]

// address: 0x10021D80
p10021D80
{
    ProcedureInfo(this=None, this_offset=None, local_size=192, stack_delta=None)
    STACKVAR(-32, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-176, 4) = STACKVAR(16, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    STACKVAR(-36, 4) = LOCAL(-164);
    STACKVAR(-168, 4) = 0x00000008;
    goto l10021DF2;
}
Can't parse line: l10021DC2: mov eax, dword ptr [ebp-0000000B0h]

// address: 0x100222BF
p100222BF
{
    ProcedureInfo(this=None, this_offset=None, local_size=108, stack_delta=None)
    STACKVAR(-16, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-96, 4) = STACKVAR(16, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    STACKVAR(-20, 4) = LOCAL(-84);
    STACKVAR(-88, 4) = 0x00000008;
    goto l10022319;
}
Can't parse line: l100222F5: mov eax, dword ptr [ebp-060h]

// address: 0x1002257C
p1002257C
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 288, 4)) + 0x00000080;
    STACKVAR(-4, 4) = ACCESS(STACKVAR(12, 4), 80, 4);
    REGDEF(ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'movsx edx, word ptr [ecx]'

// address: 0x100225E0
p100225E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    ACCESS(STACKVAR(8, 4), 4, 4) = 0x00000000;
    REGDEF(ecx=0x00000000)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x100227DF
p100227DF
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x3B9AC9F4)
}
Failed to find pattern for 'jbe l10022805'

// address: 0x100229A5
p100229A5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000036;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}

// address: 0x100229CF
p100229CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    REGDEF(cmpl=STACKVAR(16, 4), cmpr=0x3B9AC9F4)
}
Failed to find pattern for 'jbe l100229F5'

// address: 0x10022AC1
p10022AC1
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    REGDEF(eax=0x3B9AC9F4, edx=0x00000000)
}
Failed to find pattern for 'div dword ptr [ebp+010h]'

// address: 0x10022BC2
p10022BC2
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    REGDEF(ecx=0x00000080 * reinterpret_cast<any_int32>(STACKVAR(16, 4)), eax=0x3B9AC9F4, edx=0x00000000)
}
Failed to find pattern for 'div ecx'

// address: 0x10022CD7
p10022CD7
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x00000001)
    {
        goto l10022D11;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000000E;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10022D11: push 000000078h

// address: 0x10022D76
p10022D76
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(12, 4)) == 0x00000001)
    {
        goto l10022DB0;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000000E;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 24, 4) = STACKVAR(12, 4);
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10022DB0: push 000000078h

// address: 0x10022E15
p10022E15
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-24, 4) = ACCESS(STACKVAR(-16, 4), 68, 4);
    goto l10022E46;
}
Can't parse line: l10022E3D: mov ecx, dword ptr [ebp-018h]

// address: 0x100230E4
p100230E4
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(16, 4)) + reinterpret_cast<any_int32>(STACKVAR(20, 4));
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=ACCESS(STACKVAR(12, 4), 4, 4))
}
Failed to find pattern for 'ja l10023111'

// address: 0x100232EE
p100232EE
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(12, 4), 8, 4);
    REGDEF(eax=ACCESS(STACKVAR(12, 4), 24, 4))
}
Failed to find pattern for 'imul eax, dword ptr [ebp-00Ch]'

// address: 0x1002343B
p1002343B
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(16, 4)) + reinterpret_cast<any_int32>(STACKVAR(20, 4));
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=ACCESS(STACKVAR(12, 4), 4, 4))
}
Failed to find pattern for 'ja l10023468'

// address: 0x10023648
p10023648
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000080 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 8, 4));
    REGDEF(eax=ACCESS(STACKVAR(12, 4), 24, 4))
}
Failed to find pattern for 'imul eax, dword ptr [ebp-00Ch]'

// address: 0x10023798
p10023798
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 4, 4);
    REGDEF(cmpl=STACKVAR(12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jl l100237B3'

// address: 0x1002394E
p1002394E
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000001;
    goto l10023964;
}
Can't parse line: l1002395B: mov eax, dword ptr [ebp-004h]

// address: 0x100239B0
p100239B0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    malloc(STACKVAR(12, 4));
}

// address: 0x100239C2
p100239C2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    free(STACKVAR(12, 4));
}

// address: 0x100239D4
p100239D4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    malloc(STACKVAR(12, 4));
}

// address: 0x100239E6
p100239E6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    free(STACKVAR(12, 4));
}

// address: 0x100239F8
p100239F8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=STACKVAR(16, 4))
}

// address: 0x10023A00
p10023A00
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x00000031;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}

// address: 0x10023A1F
p10023A1F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10023A26
p10023A26
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10023A30
p10023A30
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000058);
    ACCESS(STACKVAR(8, 4), 424, 4) = STACKVAR(-4, 4);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10024094);
    ACCESS(STACKVAR(-4, 4), 8, 4) = GLOBAL(0x10024A44);
    ACCESS(STACKVAR(-4, 4), 12, 4) = GLOBAL(0x10024A49);
    ACCESS(STACKVAR(-4, 4), 68, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 52, 4) = 0x00000000;
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 100, 4), cmpr=0x00000004)
}
Failed to find pattern for 'jle l10023AB6'

// address: 0x10023B19
p10023B19
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-44, 4) = unknown_function_10023CDA(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(-28, 4)) + 0x00000020);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 100, 4), cmpr=0x00000003)
}
Failed to find pattern for 'jne l10023BA6'

// address: 0x10023CDA
p10023CDA
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 100, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 84, 4);
    STACKVAR(-28, 4) = 0x00000001;
}
Can't parse line: l10023CFA: mov ecx, dword ptr [ebp-01Ch]

// address: 0x10023E52
p10023E52
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=(reinterpret_cast<int>(STACKVAR(20, 4)) / 2 + 255 * reinterpret_cast<int>(STACKVAR(16, 4))) / reinterpret_cast<int>(STACKVAR(20, 4)))
}

// address: 0x10023E6E
p10023E6E
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(8, 4), 76, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jne l10023E99'

// address: 0x10024015
p10024015
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=(255 * (2 * reinterpret_cast<int>(STACKVAR(16, 4)) + 1) + reinterpret_cast<int>(STACKVAR(20, 4))) / 2 * reinterpret_cast<int>(STACKVAR(20, 4)))
}

// address: 0x10024032
p10024032
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-4, 4) = 2 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 92, 4)) + 4;
    STACKVAR(-8, 4) = 0x00000000;
    goto l10024063;
}
Can't parse line: l1002405A: mov edx, dword ptr [ebp-008h]

// address: 0x10024094
p10024094
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    ACCESS(STACKVAR(8, 4), 116, 4) = ACCESS(STACKVAR(-12, 4), 16, 4);
    ACCESS(STACKVAR(8, 4), 112, 4) = ACCESS(STACKVAR(-12, 4), 20, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 76, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000000)
    {
        goto l100240E2;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000001)
    {
        goto l10024106;
    }
    if (reinterpret_cast<any_int32>(STACKVAR(-16, 4)) == 0x00000002)
    {
        goto l10024161;
    }
}
Failed to find pattern for 'jmp near ptr l100241CC'

// address: 0x100241EA
p100241EA
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-4, 4) = 0x00000000;
    goto l1002420E;
}
Can't parse line: l10024205: mov edx, dword ptr [ebp-004h]

// address: 0x10024296
p10024296
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000400);
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'sub eax, 000000001h'

// address: 0x10024357
p10024357
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-28, 4) = ACCESS(STACKVAR(-40, 4), 24, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 100, 4);
    STACKVAR(-16, 4) = 0x00000000;
    goto l10024396;
}
Can't parse line: l1002438D: mov edx, dword ptr [ebp-010h]

// address: 0x10024436
p10024436
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-32, 4) = ACCESS(ACCESS(STACKVAR(-40, 4), 24, 4), 0, 4);
    STACKVAR(-24, 4) = ACCESS(ACCESS(STACKVAR(-40, 4), 24, 4), 4, 4);
    STACKVAR(-28, 4) = ACCESS(ACCESS(STACKVAR(-40, 4), 24, 4), 8, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-12, 4) = 0x00000000;
    goto l10024486;
}
Can't parse line: l1002447D: mov ecx, dword ptr [ebp-00Ch]

// address: 0x10024538
p10024538
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    STACKVAR(-48, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 100, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-24, 4) = 0x00000000;
    goto l1002456E;
}
Can't parse line: l10024565: mov eax, dword ptr [ebp-018h]

// address: 0x10024677
p10024677
{
    ProcedureInfo(this=None, this_offset=None, local_size=60, stack_delta=None)
    STACKVAR(-60, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-56, 4) = ACCESS(ACCESS(STACKVAR(-60, 4), 24, 4), 0, 4);
    STACKVAR(-40, 4) = ACCESS(ACCESS(STACKVAR(-60, 4), 24, 4), 4, 4);
    STACKVAR(-48, 4) = ACCESS(ACCESS(STACKVAR(-60, 4), 24, 4), 8, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-16, 4) = 0x00000000;
    goto l100246C7;
}
Can't parse line: l100246BE: mov ecx, dword ptr [ebp-010h]

// address: 0x100247FF
p100247FF
{
    ProcedureInfo(this=None, this_offset=None, local_size=80, stack_delta=None)
    STACKVAR(-60, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 100, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-24, 4) = 0x00000000;
    goto l10024841;
}
Can't parse line: l10024838: mov edx, dword ptr [ebp-018h]

// address: 0x10024A44
p10024A44
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10024A49
p10024A49
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000002E;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}

// address: 0x10024A70
p10024A70
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x0000002C);
    ACCESS(STACKVAR(8, 4), 424, 4) = STACKVAR(-8, 4);
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10024D38);
    ACCESS(STACKVAR(-8, 4), 12, 4) = GLOBAL(0x10026879);
    ACCESS(STACKVAR(-8, 4), 32, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 40, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 100, 4)) == 0x00000003)
    {
        goto l10024AE2;
    }
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 20, 4) = 0x0000002F;
    ACCESS(ACCESS(STACKVAR(8, 4), 0, 4), 0, 4)(STACKVAR(8, 4));
}
Can't parse line: l10024AE2: push 000000080h

// address: 0x10024C3A
p10024C3A
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-16, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-8, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x000007FC);
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(-8, 4)) + 0x000003FC;
    ACCESS(STACKVAR(-16, 4), 40, 4) = STACKVAR(-8, 4);
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-12, 4) = 0x00000000;
    goto l10024C9C;
}
Can't parse line: l10024C8A: mov edx, dword ptr [ebp-00Ch]

// address: 0x10024D38
p10024D38
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-12, 4), 24, 4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 76, 4)) == 0x00000000)
    {
        goto l10024D66;
    }
    REGDEF(edx=STACKVAR(8, 4))
}
Can't parse line: l10024D66: mov eax, dword ptr [ebp+00Ch]

// address: 0x10024ED3
p10024ED3
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(-28, 4), 24, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-16, 4) = 0x00000000;
    goto l10024F09;
}
Can't parse line: l10024F00: mov eax, dword ptr [ebp-010h]

// address: 0x10024FA9
p10024FA9
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-40, 4), 24, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-12, 4) = 0x00000000;
    goto l10024FDF;
}
Can't parse line: l10024FD6: mov eax, dword ptr [ebp-00Ch]

// address: 0x100250C5
p100250C5
{
    ProcedureInfo(this=None, this_offset=None, local_size=428, stack_delta=None)
    STACKVAR(-424, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-284, 4) = ACCESS(STACKVAR(-424, 4), 24, 4);
    STACKVAR(12, 4) = reinterpret_cast<int>(STACKVAR(12, 4)) >> 2;
    STACKVAR(16, 4) = reinterpret_cast<int>(STACKVAR(16, 4)) >> 3;
    STACKVAR(20, 4) = reinterpret_cast<int>(STACKVAR(20, 4)) >> 2;
    STACKVAR(-272, 4) = 0x00000020 * reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004;
    STACKVAR(-276, 4) = 0x00000020 * reinterpret_cast<any_int32>(STACKVAR(16, 4)) + 0x00000002;
    STACKVAR(-280, 4) = 0x00000020 * reinterpret_cast<any_int32>(STACKVAR(20, 4)) + 0x00000004;
    STACKVAR(-416, 4) = unknown_function_100252A3(STACKVAR(8, 4), STACKVAR(-272, 4), STACKVAR(-276, 4), STACKVAR(-280, 4), LOCAL(-256));
    unknown_function_100257D0(STACKVAR(8, 4), STACKVAR(-272, 4), STACKVAR(-276, 4), STACKVAR(-280, 4), STACKVAR(-416, 4), LOCAL(-256), LOCAL(-412));
    STACKVAR(12, 4) = 0x00000004 * reinterpret_cast<any_int32>(STACKVAR(12, 4));
    STACKVAR(16, 4) = 0x00000008 * reinterpret_cast<any_int32>(STACKVAR(16, 4));
    STACKVAR(20, 4) = 0x00000004 * reinterpret_cast<any_int32>(STACKVAR(20, 4));
    STACKVAR(-420, 4) = LOCAL(-412);
    STACKVAR(-260, 4) = 0x00000000;
    goto l100251DA;
}
Can't parse line: l100251CB: mov edx, dword ptr [ebp-000000104h]

// address: 0x100252A3
p100252A3
{
    ProcedureInfo(this=None, this_offset=None, local_size=1080, stack_delta=None)
    STACKVAR(-1052, 4) = ACCESS(STACKVAR(8, 4), 112, 4);
    STACKVAR(-1060, 4) = reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018;
    STACKVAR(-1072, 4) = reinterpret_cast<int>(STACKVAR(12, 4)) + reinterpret_cast<int>(STACKVAR(-1060, 4)) >> 1;
    STACKVAR(-1068, 4) = reinterpret_cast<any_int32>(STACKVAR(16, 4)) + 0x0000001C;
    STACKVAR(-1080, 4) = reinterpret_cast<int>(STACKVAR(16, 4)) + reinterpret_cast<int>(STACKVAR(-1068, 4)) >> 1;
    STACKVAR(-1076, 4) = reinterpret_cast<any_int32>(STACKVAR(20, 4)) + 0x00000018;
    STACKVAR(-1040, 4) = reinterpret_cast<int>(STACKVAR(20, 4)) + reinterpret_cast<int>(STACKVAR(-1076, 4)) >> 1;
    STACKVAR(-1064, 4) = 0x7FFFFFFF;
    STACKVAR(-1044, 4) = 0x00000000;
    goto l10025334;
}
Can't parse line: l10025325: mov edx, dword ptr [ebp-000000414h]

// address: 0x100257D0
p100257D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=576, stack_delta=None)
    STACKVAR(-40, 4) = LOCAL(-556);
    STACKVAR(-560, 4) = 0x0000007F;
    goto l100257FD;
}
Can't parse line: l100257EE: mov ecx, dword ptr [ebp-000000230h]

// address: 0x10025A2F
p10025A2F
{
    ProcedureInfo(this=None, this_offset=None, local_size=112, stack_delta=None)
    STACKVAR(-76, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-56, 4) = ACCESS(STACKVAR(-76, 4), 24, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(8, 4), 92, 4);
    STACKVAR(-40, 4) = ACCESS(STACKVAR(8, 4), 288, 4);
    STACKVAR(-44, 4) = ACCESS(STACKVAR(-76, 4), 40, 4);
    STACKVAR(-64, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 116, 4), 0, 4);
    STACKVAR(-80, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 116, 4), 4, 4);
    STACKVAR(-92, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 116, 4), 8, 4);
    STACKVAR(-16, 4) = 0x00000000;
    goto l10025A9D;
}
Can't parse line: l10025A94: mov ecx, dword ptr [ebp-010h]

// address: 0x10025E00
p10025E00
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    ACCESS(STACKVAR(8, 4), 116, 4) = ACCESS(STACKVAR(-4, 4), 16, 4);
    unknown_function_10025E3A(STACKVAR(8, 4), ACCESS(STACKVAR(-4, 4), 20, 4));
    ACCESS(STACKVAR(-4, 4), 28, 1) = 0x01;
}

// address: 0x10025E3A
p10025E3A
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = ACCESS(ACCESS(STACKVAR(8, 4), 4, 4), 0, 4)(STACKVAR(8, 4), 0x00000001, 0x00000020 * reinterpret_cast<any_int32>(STACKVAR(12, 4)));
    STACKVAR(-4, 4) = 0x00000001;
    ACCESS(STACKVAR(-8, 4), 0, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 4, 4) = 0x0000001F;
    ACCESS(STACKVAR(-8, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 12, 4) = 0x0000003F;
    ACCESS(STACKVAR(-8, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 20, 4) = 0x0000001F;
    unknown_function_10025F35(STACKVAR(8, 4), STACKVAR(-8, 4));
    STACKVAR(-4, 4) = unknown_function_1002642C(STACKVAR(8, 4), STACKVAR(-8, 4), STACKVAR(-4, 4), STACKVAR(12, 4));
    STACKVAR(-12, 4) = 0x00000000;
    goto l10025EDA;
}
Can't parse line: l10025ED1: mov ecx, dword ptr [ebp-00Ch]

// address: 0x10025F35
p10025F35
{
    ProcedureInfo(this=None, this_offset=None, local_size=64, stack_delta=None)
    STACKVAR(-64, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-60, 4) = ACCESS(STACKVAR(-64, 4), 24, 4);
    STACKVAR(-48, 4) = ACCESS(STACKVAR(12, 4), 0, 4);
    STACKVAR(-4, 4) = ACCESS(STACKVAR(12, 4), 4, 4);
    STACKVAR(-52, 4) = ACCESS(STACKVAR(12, 4), 8, 4);
    STACKVAR(-8, 4) = ACCESS(STACKVAR(12, 4), 12, 4);
    STACKVAR(-56, 4) = ACCESS(STACKVAR(12, 4), 16, 4);
    STACKVAR(-20, 4) = ACCESS(STACKVAR(12, 4), 20, 4);
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=STACKVAR(-48, 4))
}
Failed to find pattern for 'jle l10026024'

// address: 0x1002642C
p1002642C
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
}
Can't parse line: l10026432: mov eax, dword ptr [ebp+010h]

// address: 0x10026606
p10026606
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-4, 4) = STACKVAR(8, 4);
    goto l1002663B;
}
Can't parse line: l10026629: mov ecx, dword ptr [ebp-00Ch]

// address: 0x1002666F
p1002666F
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 4) = STACKVAR(8, 4);
    goto l100266A4;
}
Can't parse line: l10026692: mov ecx, dword ptr [ebp-008h]

// address: 0x100266CF
p100266CF
{
    ProcedureInfo(this=None, this_offset=None, local_size=68, stack_delta=None)
    STACKVAR(-64, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    STACKVAR(-60, 4) = ACCESS(STACKVAR(-64, 4), 24, 4);
    STACKVAR(-44, 4) = 0x00000000;
    STACKVAR(-68, 4) = 0x00000000;
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-48, 4) = ACCESS(STACKVAR(12, 4), 0, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(12, 4), 4, 4);
    STACKVAR(-52, 4) = ACCESS(STACKVAR(12, 4), 8, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(12, 4), 12, 4);
    STACKVAR(-56, 4) = ACCESS(STACKVAR(12, 4), 16, 4);
    STACKVAR(-24, 4) = ACCESS(STACKVAR(12, 4), 20, 4);
    STACKVAR(-20, 4) = STACKVAR(-48, 4);
    goto l1002674C;
}
Can't parse line: l10026743: mov edx, dword ptr [ebp-014h]

// address: 0x10026874
p10026874
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10026879
p10026879
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=0)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 424, 4);
    ACCESS(STACKVAR(-4, 4), 28, 1) = 0x01;
}

// address: 0x100268A0
p100268A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    REGDEF(eax=(reinterpret_cast<int>(STACKVAR(8, 4)) + reinterpret_cast<int>(STACKVAR(12, 4)) - 1) / reinterpret_cast<int>(STACKVAR(12, 4)))
}

// address: 0x100268B3
p100268B3
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    STACKVAR(8, 4) = reinterpret_cast<any_int32>(STACKVAR(8, 4)) + reinterpret_cast<any_int32>(STACKVAR(12, 4)) - 1;
    REGDEF(eax=reinterpret_cast<int>(STACKVAR(8, 4)) - reinterpret_cast<int>(STACKVAR(8, 4)) % reinterpret_cast<int>(STACKVAR(12, 4)))
}

// address: 0x100268D1
p100268D1
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-8, 4) = STACKVAR(28, 4);
    REGDEF(ecx=STACKVAR(12, 4), edx=STACKVAR(8, 4))
}
Failed to find pattern for 'lea eax, [edx+ecx*04h]'

// address: 0x1002694F
p1002694F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    memcpy(STACKVAR(12, 4), STACKVAR(8, 4), 0x00000080 * reinterpret_cast<any_int32>(STACKVAR(16, 4))); // TODO improve emitting of memcpy instructions
}

// address: 0x10026972
p10026972
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    memset(STACKVAR(8, 4), 0x00000000, STACKVAR(12, 4));
}

// address: 0x10026990
p10026990
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1002699F();
    unknown_function_100269E0();
}

// address: 0x1002699F
p1002699F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A524), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A528), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A52C), 0, 4) = 0x00000010;
    ACCESS(GLOBAL(0x1004A530), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A534), 0, 4) = 0x00000000;
    ACCESS(&B_BitMap24::BitMap24DataList(1), 0, 4) = GLOBAL(0x10042CB8);
}

// address: 0x100269E0
p100269E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x100269F2));
}

// address: 0x100269F2
p100269F2
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=static_cast<unsigned int>(ACCESS(GLOBAL(0x1004A538), 0, 1)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10026AD5
B_BitMap24::B_BitMap24(const B_BitMap24 &that)
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-28, 4), 0, 4) = GLOBAL(0x100421C8);
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A530), 0, 4), cmpr=ACCESS(GLOBAL(0x1004A528), 0, 4))
}
Failed to find pattern for 'jbe l10026B1C'

// address: 0x10026C70
void B_BitMap24::SetBits(int arg_1, int arg_2, const char *arg_3, const char *arg_4)
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l10026C88;
}
Can't parse line: l10026C7F: mov eax, dword ptr [ebp-004h]

// address: 0x10026D6D
p10026D6D
{
    ProcedureInfo(this=Id(this), this_offset=-68, local_size=72, stack_delta=None)
    ACCESS(STACKVAR(-68, 4), 0, 4) = GLOBAL(0x100421C8);
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A530), 0, 4), cmpr=ACCESS(GLOBAL(0x1004A528), 0, 4))
}
Failed to find pattern for 'jbe l10026DB4'

// address: 0x100271BE
B_BitMap24 &B_BitMap24::operator=(const B_BitMap24 &that)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-12, 4), 4, 4), cmpr=ACCESS(STACKVAR(8, 4), 4, 4))
}
Failed to find pattern for 'jne l100271E9'

// address: 0x100272A5
p100272A5
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(edi=GLOBAL(0x100487C8), esi=STACKVAR(20, 4), ecx=0x00000004, eax=0x00000000)
}
Failed to find pattern for 'rep cmpsb'

// address: 0x10027382
int B_BitMap24::SaveToBMP(const char *fileName)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x00004084)
    unknown_function_10041600();
}
'ecx'

// address: 0x1002778F
int B_BitMap24::SaveToBMPSized(const char *fileName, int width, int height)
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x000040AC)
    unknown_function_10041600();
}
'ecx'

// address: 0x10027D86
p10027D86
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    REGDEF(eax=0x00004024)
    unknown_function_10041600();
}
'ecx'

// address: 0x10027E11
p10027E11
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=44, stack_delta=None)
    LOCAL(-8)->unknown_method_10003337(STACKVAR(8, 4));
    LOCAL(-8)->unknown_method_10003821(LOCAL(-16), 0x00000004);
    ARG(GLOBAL(0x100487F4));
    REGDEF(ecx=LOCAL(-16))
    unknown_function_10003769();
}
Failed to find pattern for 'test eax, eax'

// address: 0x10027F15
int B_BitMap24::SaveToFile(const char *arg_1, int arg_2)
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=44, stack_delta=None)
    LOCAL(-8)->unknown_method_10003337(STACKVAR(8, 4));
    LOCAL(-8)->unknown_method_10003821(LOCAL(-16), 0x00000004);
    ARG(GLOBAL(0x1004880C));
    REGDEF(ecx=LOCAL(-16))
    unknown_function_10003769();
}
Failed to find pattern for 'test eax, eax'

// address: 0x10028021
B_IDataFile &operator >>(B_IDataFile &file, B_BitMap24 &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(12, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(12, 4), 4, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 12, 4)) == 0x00000000)
    {
        goto l10028063;
    }
    STACKVAR(-12, 4) = ACCESS(STACKVAR(12, 4), 12, 4);
    ??3@YAXPAX@Z(STACKVAR(-12, 4));
    REGDEF(eax=STACKVAR(12, 4))
}
Can't parse line: l10028063: mov ecx, dword ptr [ebp+008h]

// address: 0x100280CC
B_ODataFile &operator <<(B_ODataFile &file, const B_BitMap24 &bitMap)
{
    ProcedureInfo(this=None, this_offset=None, local_size=100, stack_delta=None)
    STACKVAR(-44, 4) = 0x0000001D;
    STACKVAR(-48, 2) = 0x0000;
    STACKVAR(-52, 2) = 0x0000;
    STACKVAR(-56, 4) = 0x00000000;
    STACKVAR(-60, 2) = 0x4D42;
    unknown_function_10002008(unknown_function_10001FC6(unknown_function_10001FC6(unknown_function_10002008(unknown_function_10001FC6(STACKVAR(8, 4), LOCAL(-60)), LOCAL(-56)), LOCAL(-52)), LOCAL(-48)), LOCAL(-44));
    STACKVAR(-64, 2) = 0x0018;
    STACKVAR(-68, 2) = 0x0001;
    STACKVAR(-72, 2) = ACCESS(STACKVAR(12, 4), 8, 2);
    STACKVAR(-76, 2) = ACCESS(STACKVAR(12, 4), 4, 2);
    STACKVAR(-80, 4) = 0x0000000C;
    unknown_function_10001FC6(unknown_function_10001FC6(unknown_function_10001FC6(unknown_function_10001FC6(unknown_function_10002008(STACKVAR(8, 4), LOCAL(-80)), LOCAL(-76)), LOCAL(-72)), LOCAL(-68)), LOCAL(-64));
    STACKVAR(-84, 1) = 0;
    STACKVAR(-88, 1) = 0;
    STACKVAR(-92, 1) = 0;
    unknown_function_10001F9A(unknown_function_10001F9A(unknown_function_10001F9A(STACKVAR(8, 4), LOCAL(-92)), LOCAL(-88)), LOCAL(-84));
    STACKVAR(-96, 4) = ??2@YAPAXI@Z(0x00000003 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 4, 4)));
    STACKVAR(-8, 4) = STACKVAR(-96, 4);
    REGDEF(eax=reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 4, 4)) & 0x80000003)
}
Failed to find pattern for 'jns l10028206'

// address: 0x10028353
void B_BitMap24::EscribeArchivoRAW(const char *arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    REGDEF(ecx=STACKVAR(-12, 4), edx=ACCESS(STACKVAR(-12, 4), 4, 4))
}
Failed to find pattern for 'imul edx, dword ptr [ecx+008h]'

// address: 0x100283CD
p100283CD
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    REGDEF(ecx=STACKVAR(-20, 4), edx=ACCESS(STACKVAR(-20, 4), 4, 4))
}
Failed to find pattern for 'imul edx, dword ptr [ecx+008h]'

// address: 0x10028434
p10028434
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jl l100284B6'

// address: 0x100284C0
p100284C0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042CB8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l10028581;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100284F6'

// address: 0x100285A0
p100285A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<unsigned short &>(STACKVAR(12, 4)) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004) >> reinterpret_cast<short &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008) >> reinterpret_cast<short &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000A) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C);
}

// address: 0x100285F5
p100285F5
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    REGDEF(ecx=0x00000010, eax=0x00000000, edi=STACKVAR(12, 4))
}
Failed to find pattern for 'rep stosd'

// address: 0x100289E4
p100289E4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<unsigned char &>(STACKVAR(12, 4)) >> reinterpret_cast<unsigned char &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000001) >> reinterpret_cast<unsigned char &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000002);
}

// address: 0x10028A19
p10028A19
{
    ProcedureInfo(this=None, this_offset=None, local_size=56, stack_delta=None)
    STACKVAR(-48, 4) = STACKVAR(24, 4);
    REGDEF(ecx=STACKVAR(-48, 4))
}
Failed to find pattern for 'sub ecx, 000000001h'

// address: 0x10029170
p10029170
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(12, 4) = 0x00000003 * reinterpret_cast<any_int32>(STACKVAR(12, 4));
    STACKVAR(-8, 4) = 0x00000000;
    goto l10029192;
}
Can't parse line: l10029189: mov ecx, dword ptr [ebp-008h]

// address: 0x10029217
p10029217
{
    ProcedureInfo(this=None, this_offset=None, local_size=144, stack_delta=None)
    STACKVAR(-24, 4) = 0x00000000;
    unknown_function_100285A0(STACKVAR(8, 4), LOCAL(-104));
    if ((reinterpret_cast<any_int32>(STACKVAR(-104, 4)) & 0x0000FFFF) == 0x00004D42)
    {
        goto l10029272;
    }
    if ((reinterpret_cast<any_int32>(STACKVAR(-104, 4)) & 0x0000FFFF) == 0x00004943)
    {
        goto l10029272;
    }
    if ((reinterpret_cast<any_int32>(STACKVAR(-104, 4)) & 0x0000FFFF) == 0x00005043)
    {
        goto l10029272;
    }
    REGDEF(eax=0x000003E8)
}
Failed to find pattern for 'jmp near ptr l10029506'

// address: 0x10029510
p10029510
{
    ProcedureInfo(this=Id(this), this_offset=-580, local_size=580, stack_delta=None)
    STACKVAR(-428, 4) = unknown_function_1001F6E0(LOCAL(-564));
    unknown_function_10013490(LOCAL(-428), 0x0000003E, 0x000001AC);
    STACKVAR(-432, 4) = fopen(STACKVAR(8, 4), GLOBAL(0x10048828));
    REGDEF(cmpl=STACKVAR(-432, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10029591'

// address: 0x10029700
int B_BitMap24::SaveToJPEG(const char *arg_1, int arg_2)
{
    ProcedureInfo(this=Id(this), this_offset=-508, local_size=508, stack_delta=None)
    STACKVAR(-356, 4) = unknown_function_1001F6E0(LOCAL(-500));
    unknown_function_100096A0(LOCAL(-356), 0x0000003E, 0x00000164);
    STACKVAR(-368, 4) = fopen(STACKVAR(8, 4), GLOBAL(0x10048870));
    REGDEF(cmpl=STACKVAR(-368, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10029781'

// address: 0x100298B0
p100298B0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=12, stack_delta=None)
    STACKVAR(-8, 4)->unknown_method_10003A07(LOCAL(8));
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042180);
    ACCESS(STACKVAR(-8, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042CBC);
    STACKVAR(-4, 4) = ??2@YAPAXI@Z(0x00004010);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l1002990D;
    }
    STACKVAR(-12, 4) = STACKVAR(-4, 4)->unknown_method_10001C44(STACKVAR(16, 4), 0x00004000);
    goto l10029914;
}
Can't parse line: l1002990D: mov dword ptr [ebp-00Ch], 000000000h

// address: 0x1002994D
p1002994D
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10042CBC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 16, 4)) == 0x00000000)
    {
        goto l100299C0;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-12, 4), 16, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l100299A5;
    }
    STACKVAR(-4, 4)->unknown_method_10002082();
    REGDEF(edx=0x00000001 & 0x00000001)
}
Failed to find pattern for 'test edx, edx'

// address: 0x100299E1
p100299E1
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 16, 4)) == 0x00000000)
    {
        goto l10029A02;
    }
    ACCESS(STACKVAR(-4, 4), 12, 4) = 0x00000000;
    REGDEF(eax=0x00000001)
    goto l10029A04;
}
Can't parse line: l10029A02: xor eax, eax

// address: 0x10029A08
p10029A08
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 12, 4) = 0x00000001;
    REGDEF(eax=0x00000001)
}

// address: 0x10029A22
p10029A22
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 12, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10029A57'

// address: 0x10029A60
p10029A60
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    reinterpret_cast<B_Name *>(reinterpret_cast<any_int32>(this) + 0x00000004)->B_Name(reinterpret_cast<B_Name &>(reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000004));
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    ACCESS(this, 12, 4) = ACCESS(STACKVAR(8, 4), 12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042180);
    ACCESS(this, 16, 4) = ACCESS(STACKVAR(8, 4), 16, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042CBC);
    REGDEF(eax=this)
}

// address: 0x10029AC0
p10029AC0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    reinterpret_cast<B_Name &>(reinterpret_cast<any_int32>(this) + 0x00000004) = reinterpret_cast<B_Name &>(reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000004);
    ACCESS(this, 12, 4) = ACCESS(STACKVAR(8, 4), 12, 4);
    ACCESS(this, 16, 4) = ACCESS(STACKVAR(8, 4), 16, 4);
    REGDEF(eax=this)
}

// address: 0x10029B30
p10029B30
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10029BE0
char *vararg(const char *format)
{
    STACKVAR(-8, 4) = LOCAL(12);
    STACKVAR(-4, 4) = vsprintf(GLOBAL(0x1004A540), format, STACKVAR(-8, 4));
    STACKVAR(-8, 4) = 0x00000000;
    return reinterpret_cast<char *>(GLOBAL(0x1004A540));
}

// address: 0x10029C15
p10029C15
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10029C24();
    unknown_function_10029C33();
}

// address: 0x10029C24
p10029C24
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    mout.unknown_method_10029C4A();
}

// address: 0x10029C33
p10029C33
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x10029C45));
}

// address: 0x10029C45
p10029C45
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
}

// address: 0x10029C4A
p10029C4A
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=12, stack_delta=None)
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A944), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10029CF5'

// address: 0x10029CFC
unsigned int B_MessageManager::Add(B_MessageChannel *channel)
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(GLOBAL(0x1004A944), 0, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=ACCESS(STACKVAR(-24, 4), 8, 4))
}
Failed to find pattern for 'jbe l10029D42'

// address: 0x10029E17
unsigned int B_MessageManager::OpenChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(GLOBAL(0x1004A944), 0, 4);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10029E3A;
}
Can't parse line: l10029E31: mov ecx, dword ptr [ebp-008h]

// address: 0x10029E98
unsigned int B_MessageManager::CloseChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(GLOBAL(0x1004A944), 0, 4);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10029EBB;
}
Can't parse line: l10029EB2: mov ecx, dword ptr [ebp-008h]

// address: 0x10029F19
B_MessageChannel *B_MessageManager::DisconnectChannel(const B_Name &channel_name)
{
    ProcedureInfo(this=Id(this), this_offset=-48, local_size=52, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l10029F35;
}
Can't parse line: l10029F2C: mov eax, dword ptr [ebp-004h]

// address: 0x1002A13C
p1002A13C
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    if (reinterpret_cast<any_int32>(ACCESS(ACCESS(GLOBAL(0x1004A944), 0, 4), 8, 4)) == 0x00000000)
    {
        goto l1002A1B0;
    }
    STACKVAR(-8, 4) = 0x00000000;
    goto l1002A169;
}
Can't parse line: l1002A160: mov ecx, dword ptr [ebp-008h]

// address: 0x1002A1B9
p1002A1B9
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = ACCESS(GLOBAL(0x1004A944), 0, 4);
    STACKVAR(-8, 4) = 0x00000000;
    goto l1002A1DC;
}
Can't parse line: l1002A1D3: mov ecx, dword ptr [ebp-008h]

// address: 0x1002A23E
p1002A23E
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=4)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 1) = STACKVAR(8, 1);
    STACKVAR(-3, 1) = 0;
    this->unknown_method_1002A13C(LOCAL(-4));
}

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
    return 0;
}

// address: 0x1002A293
p1002A293
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=8)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-4, 1) = STACKVAR(8, 1);
    STACKVAR(-3, 1) = 0;
    this->unknown_method_1002A1B9(LOCAL(-4), STACKVAR(12, 4));
}

// address: 0x1002A2C3
B_MessageManager &operator<<(B_MessageManager &mout, const char *str)
{
    mout->unknown_method_1002A13C(str);
    return mout;
}

// address: 0x1002A2D7
p1002A2D7
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    STACKVAR(8, 4)->unknown_method_1002A23E(STACKVAR(12, 1));
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1002A2F0
p1002A2F0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042CD4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1002A3B1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1002A326'

// address: 0x1002A3D0
p1002A3D0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042CD4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1002A491;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1002A406'

// address: 0x1002A4B0
p1002A4B0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042CD4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1002A571;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1002A4E6'

// address: 0x1002A590
void OutputWin32Error(const char *message)
{
    STACKVAR(-4, 4) = GetLastError();
    mout << message;
    FormatMessageA(0x00001100, 0x00000000, STACKVAR(-4, 4), 0x00000400, LOCAL(-8), 0x00000000, 0x00000000);
    mout << reinterpret_cast<char *>(STACKVAR(-8, 4));
    LocalFree(STACKVAR(-8, 4));
}

// address: 0x1002A5F0
p1002A5F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 0, 8) = 0.0;
    ACCESS(this, 8, 8) = 0.0;
    ACCESS(this, 16, 8) = 0.0;
    ACCESS(this, 24, 8) = 0.0;
    REGDEF(eax=this)
}

// address: 0x1002A7F2
p1002A7F2
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(unknown_function_10031E6D(STACKVAR(8, 4), STACKVAR(12, 4))) >> reinterpret_cast<double &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1002A81A
p1002A81A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(unknown_function_10031E83(STACKVAR(8, 4), STACKVAR(12, 4))) << reinterpret_cast<double &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1002DEF0
p1002DEF0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 0, 8) = 0.0;
    ACCESS(this, 8, 8) = 0.0;
    ACCESS(this, 16, 8) = 0.0;
    REGDEF(eax=this)
}

// address: 0x1002DF30
p1002DF30
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=44, stack_delta=None)
    REGDEF(eax=STACKVAR(-44, 4), ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [eax+004h]'

// address: 0x1002E0B0
p1002E0B0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    memcpy(STACKVAR(-4, 4), STACKVAR(8, 4), 0x00000018); // TODO improve emitting of memcpy instructions
    REGDEF(esi=STACKVAR(12, 4), edi=STACKVAR(-4, 4))
}
Failed to find pattern for 'add edi, 000000018h'

// address: 0x1002E0F0
p1002E0F0
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=12)
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000048;
    ACCESS(STACKVAR(-4, 4), 4, 1) = ACCESS(STACKVAR(8, 4), 4, 1);
    ACCESS(STACKVAR(-4, 4), 5, 1) = ACCESS(STACKVAR(8, 4), 5, 1);
    ACCESS(STACKVAR(-4, 4), 6, 1) = ACCESS(STACKVAR(8, 4), 6, 1);
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(this) + 0x00000050;
    ACCESS(STACKVAR(-8, 4), 4, 1) = ACCESS(STACKVAR(12, 4), 4, 1);
    ACCESS(STACKVAR(-8, 4), 5, 1) = ACCESS(STACKVAR(12, 4), 5, 1);
    ACCESS(STACKVAR(-8, 4), 6, 1) = ACCESS(STACKVAR(12, 4), 6, 1);
    STACKVAR(-12, 4) = reinterpret_cast<any_int32>(this) + 0x00000058;
    ACCESS(STACKVAR(-12, 4), 4, 1) = ACCESS(STACKVAR(16, 4), 4, 1);
    ACCESS(STACKVAR(-12, 4), 5, 1) = ACCESS(STACKVAR(16, 4), 5, 1);
    ACCESS(STACKVAR(-12, 4), 6, 1) = ACCESS(STACKVAR(16, 4), 6, 1);
}

// address: 0x1002E190
p1002E190
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    ACCESS(this, 0, 8) = 1.0;
    ACCESS(this, 8, 8) = 0.0;
    ACCESS(this, 16, 8) = 0.0;
    ACCESS(this, 24, 8) = 0.0;
    ACCESS(this, 32, 8) = 0.0;
    ACCESS(this, 40, 8) = 1.0;
    ACCESS(this, 48, 8) = 0.0;
    ACCESS(this, 56, 8) = 0.0;
    ACCESS(this, 64, 8) = 0.0;
    ACCESS(this, 72, 8) = 0.0;
    ACCESS(this, 80, 8) = 1.0;
    ACCESS(this, 88, 8) = 0.0;
    ACCESS(this, 96, 8) = 0.0;
    ACCESS(this, 104, 8) = 0.0;
    ACCESS(this, 112, 8) = 0.0;
    ACCESS(this, 120, 8) = 1.0;
    REGDEF(eax=this)
}

// address: 0x1002E2AD
p1002E2AD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = STACKVAR(8, 4);
    REGDEF(edx=STACKVAR(12, 4))
}
'eax'

// address: 0x1002E600
p1002E600
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=44, stack_delta=None)
}
Failed to find pattern for 'fld qword ptr [ebp+00Ch]'

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
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(ecx=STACKVAR(-28, 4))
    unknown_function_1002ED7C();
}
Failed to find pattern for 'fstp qword ptr [ebp-008h]'

// address: 0x1002F052
p1002F052
{
    ProcedureInfo(this=Id(this), this_offset=-84, local_size=84, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l1002F06F;
}
Can't parse line: l1002F066: mov eax, dword ptr [ebp-004h]

// address: 0x1002F159
p1002F159
{
    ProcedureInfo(this=Id(this), this_offset=-212, local_size=212, stack_delta=None)
    LOCAL(-128)->unknown_method_1002E190();
    REGDEF(eax=STACKVAR(-212, 4), ecx=STACKVAR(-212, 4))
}
Failed to find pattern for 'fld qword ptr [ecx]'

// address: 0x1002F537
p1002F537
{
    ProcedureInfo(this=None, this_offset=None, local_size=128, stack_delta=None)
    LOCAL(-128)->unknown_method_1002E190();
    REGDEF(eax=STACKVAR(12, 4), ecx=STACKVAR(16, 4))
}
Failed to find pattern for 'fld qword ptr [eax]'

// address: 0x1002FEB3
p1002FEB3
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(16, 4), ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [ecx]'

// address: 0x100300A1
p100300A1
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(16, 4), ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [ecx]'

// address: 0x10030219
p10030219
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile *>(STACKVAR(8, 4))->Read(reinterpret_cast<void *>(STACKVAR(12, 4)), 128);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10030232
p10030232
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile *>(STACKVAR(8, 4))->Write(reinterpret_cast<void *>(STACKVAR(12, 4)), 128);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10031284
p10031284
{
    ProcedureInfo(this=Id(this), this_offset=-52, local_size=52, stack_delta=None)
    REGDEF(esi=STACKVAR(12, 4)->unknown_method_10031882(LOCAL(-24), STACKVAR(16, 4)), edi=STACKVAR(-52, 4))
}
Failed to find pattern for 'add edi, 000000004h'

// address: 0x100312FC
p100312FC
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    ARG(reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000004);
    REGDEF(ecx=reinterpret_cast<any_int32>(STACKVAR(8, 4)) + 0x00000004)
    unknown_function_1003184F();
}
Failed to find pattern for 'fcomp qword ptr [g10042D10]'

// address: 0x10031430
p10031430
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1003143A();
}

// address: 0x1003143A
p1003143A
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A960), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A964), 0, 4) = 0x3FF00000;
    ACCESS(GLOBAL(0x1004A968), 0, 8) = 0.0;
    ACCESS(GLOBAL(0x1004A970), 0, 8) = 0.0;
}

// address: 0x10031477
p10031477
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031481();
}

// address: 0x10031481
p10031481
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A948), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A94C), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A950), 0, 8) = 1.0;
    ACCESS(GLOBAL(0x1004A958), 0, 8) = 0.0;
}

// address: 0x100314BE
p100314BE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100314C8();
}

// address: 0x100314C8
p100314C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A978), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A97C), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A980), 0, 8) = 0.0;
    ACCESS(GLOBAL(0x1004A988), 0, 8) = 1.0;
}

// address: 0x10031505
p10031505
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=STACKVAR(20, 4))
}
Failed to find pattern for 'fld qword ptr [ebp+00Ch]'

// address: 0x10031561
p10031561
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(eax=STACKVAR(-28, 4))
}
Failed to find pattern for 'fld qword ptr [ebp+00Ch]'

// address: 0x100315C2
p100315C2
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(eax=STACKVAR(-28, 4))
}
Failed to find pattern for 'fld qword ptr [eax+010h]'

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
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(eax=STACKVAR(-28, 4), ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [eax+010h]'

// address: 0x10031760
p10031760
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(eax=STACKVAR(-28, 4), ecx=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [eax+010h]'

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
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=28, stack_delta=None)
    REGDEF(eax=STACKVAR(12, 4), ecx=STACKVAR(-28, 4))
}
Failed to find pattern for 'fld qword ptr [ecx]'

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
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile *>(STACKVAR(8, 4))->Read(reinterpret_cast<void *>(STACKVAR(12, 4)), 24);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10031E83
p10031E83
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile *>(STACKVAR(8, 4))->Write(reinterpret_cast<void *>(STACKVAR(12, 4)), 24);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10031EA0
p10031EA0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=0)
    ACCESS(this, 0, 4) = 0x00000000;
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000004;
    ACCESS(STACKVAR(-4, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 16, 8) = 0.0;
    REGDEF(eax=this)
}

// address: 0x10031F20
p10031F20
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(unknown_function_10031E83(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004)) << reinterpret_cast<int &>(STACKVAR(12, 4));
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10031F48
p10031F48
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    unknown_function_10001BAD(unknown_function_10031E6D(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004), STACKVAR(12, 4));
    REGDEF(eax=STACKVAR(12, 4))
}
Failed to find pattern for 'fld qword ptr [eax+014h]'

// address: 0x10031F82
p10031F82
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008;
    unknown_function_1000201E(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(-8, 4)) + 0x00000008);
    STACKVAR(-4, 4) = 0x00000000;
    goto l10031FB6;
}
Can't parse line: l10031FAD: mov eax, dword ptr [ebp-004h]

// address: 0x10032003
p10032003
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-28, 4) = reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-28, 4), 16, 4)) == 0x00000000)
    {
        goto l100320A0;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-28, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003202A'

// address: 0x100321A0
p100321A0
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E6D(unknown_function_10031E6D(STACKVAR(8, 4), STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100321C8
p100321C8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E83(unknown_function_10031E83(STACKVAR(8, 4), STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100321F0
B_MeshEdge::B_MeshEdge()
{
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 20, 4) = 0x00000001;
}

// address: 0x1003221C
B_MeshEdge::B_MeshEdge(unsigned int a, unsigned int b, unsigned int c)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = STACKVAR(16, 4);
    ACCESS(STACKVAR(-4, 4), 20, 4) = 0x00000001;
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=STACKVAR(12, 4))
}
Failed to find pattern for 'jnb l10032247'

// address: 0x1003227E
unsigned int B_MeshEdge::operator==(const B_MeshEdge &other)
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-4, 4), 4, 4), cmpr=ACCESS(STACKVAR(8, 4), 4, 4))
}
Failed to find pattern for 'jne l100322AC'

// address: 0x100322BC
p100322BC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008) >> reinterpret_cast<unsigned int &>(STACKVAR(12, 4)) >> reinterpret_cast<double &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000014);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032314
p10032314
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008) << reinterpret_cast<unsigned int &>(STACKVAR(12, 4)) << reinterpret_cast<double &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000014);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1003236C
p1003236C
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    unknown_function_10001BD9(unknown_function_10040D58(unknown_function_10001BEF(unknown_function_10001BEF(unknown_function_10001BEF(STACKVAR(8, 4), STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000034);
    REGDEF(cmpl=ACCESS(GLOBAL(0x100488B4), 0, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jbe l100323FD'

// address: 0x10032420
p10032420
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    unknown_function_10002008(unknown_function_10040E61(unknown_function_1000201E(unknown_function_1000201E(unknown_function_1000201E(STACKVAR(8, 4), STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000018), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000034);
    REGDEF(cmpl=ACCESS(GLOBAL(0x100488B4), 0, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jbe l100324AF'

// address: 0x100324B4
p100324B4
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(unknown_function_1002A7F2(STACKVAR(8, 4), STACKVAR(12, 4))) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000020) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000024);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100324EC
p100324EC
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(unknown_function_1002A81A(STACKVAR(8, 4), STACKVAR(12, 4))) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000020) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000024);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032524
p10032524
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
}
Failed to find pattern for 'fld dword ptr [g100488B8]'

// address: 0x1003270D
p1003270D
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
}
Failed to find pattern for 'fld dword ptr [g100488B8]'

// address: 0x100327E1
p100327E1
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(unknown_function_10031E6D(reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<float &>(STACKVAR(12, 4)) >> reinterpret_cast<float &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008)) >> reinterpret_cast<int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000020);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032829
p10032829
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_ODataFile &>(unknown_function_10031E83(reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<float &>(STACKVAR(12, 4)) << reinterpret_cast<float &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000004), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000008)) << reinterpret_cast<int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000020);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032871
p10032871
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    reinterpret_cast<B_IDataFile &>(unknown_function_10030219(reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C)) >> reinterpret_cast<int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000008C);
    (reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C)->unknown_method_1002EF9F();
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100328B6
p100328B6
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    return reinterpret_cast<B_ODataFile &>(unknown_function_10030232(reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C)) << reinterpret_cast<int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000008C);
}

// address: 0x100328ED
p100328ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E6D(unknown_function_10031E6D(unknown_function_10031E6D(reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000040);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032945
p10032945
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E83(unknown_function_10031E83(unknown_function_10031E83(reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000040);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x1003299D
p1003299D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E6D(unknown_function_10031E6D(reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x100329E5
p100329E5
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E83(unknown_function_10031E83(reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032A2D
p10032A2D
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E6D(unknown_function_10031E6D(reinterpret_cast<B_IDataFile &>(STACKVAR(8, 4)) >> reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) >> reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032A75
p10032A75
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10031E83(unknown_function_10031E83(reinterpret_cast<B_ODataFile &>(STACKVAR(8, 4)) << reinterpret_cast<B_NamedObj &>(STACKVAR(12, 4)) << reinterpret_cast<unsigned int &>(reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x0000000C), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000010), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028);
    REGDEF(eax=STACKVAR(8, 4))
}

// address: 0x10032ABD
p10032ABD
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(ax=0x0001)
}

// address: 0x10032ACC
p10032ACC
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10032AD9
p10032AD9
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    REGDEF(eax=0x00000000)
}

// address: 0x10032AE6
void B_ObjDscr::SetUpNormals()
{
    ProcedureInfo(this=Id(this), this_offset=-628, local_size=648, stack_delta=None)
    STACKVAR(-28, 4) = ACCESS(STACKVAR(-628, 4), 44, 4);
    STACKVAR(-204, 4) = ??2@YAPAXI@Z(0x00000018 * reinterpret_cast<any_int32>(STACKVAR(-28, 4)));
    if (reinterpret_cast<any_int32>(STACKVAR(-204, 4)) == 0x00000000)
    {
        goto l10032BB9;
    }
    STACKVAR(-492, 4) = STACKVAR(-28, 4);
    STACKVAR(-488, 4) = 0x00000018;
    STACKVAR(-484, 4) = STACKVAR(-204, 4);
}
Can't parse line: l10032B44: mov edx, dword ptr [ebp-0000001ECh]

// address: 0x100335C3
void B_ObjDscr::SetUpInertialT()
{
    ProcedureInfo(this=Id(this), this_offset=-660, local_size=680, stack_delta=None)
    STACKVAR(-120, 4) = ??2@YAPAXI@Z(0x00000008 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(-660, 4), 44, 4)));
    STACKVAR(-24, 4) = STACKVAR(-120, 4);
    STACKVAR(-32, 4) = ACCESS(STACKVAR(-660, 4), 44, 4);
    STACKVAR(-124, 4) = ??2@YAPAXI@Z(0x00000018 * reinterpret_cast<any_int32>(STACKVAR(-32, 4)));
    if (reinterpret_cast<any_int32>(STACKVAR(-124, 4)) == 0x00000000)
    {
        goto l100336A8;
    }
    STACKVAR(-520, 4) = STACKVAR(-32, 4);
    STACKVAR(-516, 4) = 0x00000018;
    STACKVAR(-512, 4) = STACKVAR(-124, 4);
}
Can't parse line: l10033636: mov edx, dword ptr [ebp-000000208h]

// address: 0x100342BD
int B_ObjDscr::GetVtxNode(unsigned int arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l100342D8;
}
Can't parse line: l100342CF: mov eax, dword ptr [ebp-004h]

// address: 0x10034345
p10034345
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_10034354();
    unknown_function_1003438B();
}

// address: 0x10034354
p10034354
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A994), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A998), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A99C), 0, 4) = 0x00000080;
    ACCESS(GLOBAL(0x1004A9A0), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A990), 0, 4) = GLOBAL(0x10042D78);
}

// address: 0x1003438B
p1003438B
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x1003439D));
}

// address: 0x1003439D
p1003439D
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    ACCESS(GLOBAL(0x1004A990), 0, 4) = GLOBAL(0x10042D78);
    if (reinterpret_cast<any_int32>(ACCESS(GLOBAL(0x1004A9A0), 0, 4)) == 0x00000000)
    {
        goto l1003440B;
    }
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A9A0), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100343C1'

// address: 0x1003440F
p1003440F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1003441E();
    unknown_function_10034455();
}

// address: 0x1003441E
p1003441E
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A9AC), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9B0), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9B4), 0, 4) = 0x00000080;
    ACCESS(GLOBAL(0x1004A9B8), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9A8), 0, 4) = GLOBAL(0x10042D7C);
}

// address: 0x10034455
p10034455
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x10034467));
}

// address: 0x10034467
p10034467
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    ACCESS(GLOBAL(0x1004A9A8), 0, 4) = GLOBAL(0x10042D7C);
    if (reinterpret_cast<any_int32>(ACCESS(GLOBAL(0x1004A9B8), 0, 4)) == 0x00000000)
    {
        goto l100344BB;
    }
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A9B8), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10034489'

// address: 0x100344BF
p100344BF
{
    ProcedureInfo(this=Id(this), this_offset=-168, local_size=192, stack_delta=None)
    STACKVAR(-4, 4) = STACKVAR(-168, 4)->unknown_method_100342BD(STACKVAR(8, 4));
    LOCAL(-28)->unknown_method_1003221C(STACKVAR(8, 4), STACKVAR(12, 4), STACKVAR(-4, 4));
    STACKVAR(-32, 4) = 0x00000000;
    goto l10034508;
}
Can't parse line: l100344FF: mov ecx, dword ptr [ebp-020h]

// address: 0x10034A8A
void B_ObjDscr::SetUpEdges()
{
    ProcedureInfo(this=Id(this), this_offset=-140, local_size=144, stack_delta=None)
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A9A0), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10034AA4'

// address: 0x10034D5A
void B_ObjDscr::Draw(B_3DRasterDevice *raster, float x1, float y1, float x2, float y2, float scale, int i_unknown)
{
    ProcedureInfo(this=Id(this), this_offset=-1036, local_size=1164, stack_delta=None)
}
Failed to find pattern for 'fld dword ptr [ebp+00Ch]'

// address: 0x1003590B
p1003590B
{
    ProcedureInfo(this=None, this_offset=None, local_size=708, stack_delta=None)
    STACKVAR(-528, 4) = unknown_function_10004676(STACKVAR(8, 4), STACKVAR(12, 4));
    STACKVAR(-532, 4) = reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000024;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-532, 4), 16, 4)) == 0x00000000)
    {
        goto l10035997;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-532, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10035952'

// address: 0x100369F0
p100369F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=104, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 84, 4), cmpr=0x00000001)
}
Failed to find pattern for 'jbe l10036A0B'

// address: 0x10036E0D
void B_ObjDscr::SetUpBSP()
{
    ProcedureInfo(this=Id(this), this_offset=-160, local_size=168, stack_delta=None)
    STACKVAR(-24, 4) = ACCESS(STACKVAR(-160, 4), 64, 4);
    STACKVAR(-36, 4) = ??2@YAPAXI@Z(0x00000024 * reinterpret_cast<any_int32>(STACKVAR(-24, 4)) + 0x00000004);
    if (reinterpret_cast<any_int32>(STACKVAR(-36, 4)) == 0x00000000)
    {
        goto l10036ED2;
    }
    ACCESS(STACKVAR(-36, 4), 0, 4) = STACKVAR(-24, 4);
    STACKVAR(-108, 4) = STACKVAR(-24, 4);
    STACKVAR(-104, 4) = 0x00000024;
    STACKVAR(-100, 4) = reinterpret_cast<any_int32>(STACKVAR(-36, 4)) + 0x00000004;
}
Can't parse line: l10036E66: mov ecx, dword ptr [ebp-06Ch]

// address: 0x100371B3
p100371B3
{
    ProcedureInfo(this=Id(this), this_offset=-40, local_size=40, stack_delta=None)
    STACKVAR(-28, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-40, 4), 40, 4)) + 0x00000030 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(8, 4), 0, 4));
    REGDEF(ecx=STACKVAR(12, 4), edx=STACKVAR(12, 4), eax=STACKVAR(-28, 4))
}
Failed to find pattern for 'fld qword ptr [eax+010h]'

// address: 0x10037338
p10037338
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(eax=ACCESS(STACKVAR(8, 4), 8, 4), edx=0x00000000, ecx=0x00000003)
}
Failed to find pattern for 'div ecx'

// address: 0x1003737B
p1003737B
{
    ProcedureInfo(this=Id(this), this_offset=-464, local_size=480, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(-8, 4) = 0x00000001;
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-20, 4) = GLOBAL(0x10042D7C);
    STACKVAR(-40, 4) = 0x00000000;
    STACKVAR(-36, 4) = 0x00000000;
    STACKVAR(-32, 4) = 0x00000001;
    STACKVAR(-28, 4) = 0x00000000;
    STACKVAR(-44, 4) = GLOBAL(0x10042D7C);
    ACCESS(STACKVAR(16, 4), 0, 4) = STACKVAR(-464, 4)->unknown_method_10037338(STACKVAR(8, 4), STACKVAR(12, 4));
    ACCESS(STACKVAR(16, 4), 20, 4) = 0x00000000;
    STACKVAR(-280, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 60, 4)) + 0x00000038 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(16, 4), 0, 4));
    STACKVAR(-284, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 40, 4)) + 0x00000030 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(-280, 4), 0, 4));
    STACKVAR(-288, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 60, 4)) + 0x00000038 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(16, 4), 0, 4));
    STACKVAR(-292, 4) = reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 40, 4)) + 0x00000030 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(-288, 4), 4, 4));
    REGDEF(ecx=STACKVAR(-292, 4)->unknown_method_10031760(LOCAL(-72), STACKVAR(-284, 4), LOCAL(-120), (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 40, 4)) + 0x00000030 * reinterpret_cast<any_int32>(ACCESS(ARRPTR(ACCESS(STACKVAR(-464, 4), 60, 4), 1, 0x00000038 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(16, 4), 0, 4)), 8), 0, 4)))->unknown_method_10031760(LOCAL(-96), reinterpret_cast<any_int32>(ACCESS(STACKVAR(-464, 4), 40, 4)) + 0x00000030 * reinterpret_cast<any_int32>(ACCESS(ARRPTR(ACCESS(STACKVAR(-464, 4), 60, 4), 1, 0x00000038 * reinterpret_cast<any_int32>(ACCESS(STACKVAR(16, 4), 0, 4)), 0), 0, 4))))->unknown_method_10031882())
    unknown_function_10031913();
}
Failed to find pattern for 'fdivr qword ptr [g100422C0]'

// address: 0x10037E84
unsigned char B_ObjDscr::EdgeFaceGrp(unsigned int arg_1)
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-4, 4) = ACCESS(STACKVAR(-12, 4), 60, 4);
    STACKVAR(-8, 4) = 0x00000000;
    goto l10037EA8;
}
Can't parse line: l10037E9F: mov edx, dword ptr [ebp-008h]

// address: 0x10037EF5
B_ObjDscr::B_ObjDscr()
{
    this->B_Resource();
    STACKVAR(-4, 4) = &this->data;
    ACCESS(STACKVAR(-4, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 12, 4) = 0x00000010;
    ACCESS(STACKVAR(-4, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 20, 4) = 0x00000001;
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042DE8);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042DE4);
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(this) + 0x00000024;
    ACCESS(STACKVAR(-8, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-8, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DE0);
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DDC);
    STACKVAR(-12, 4) = reinterpret_cast<any_int32>(this) + 0x00000038;
    ACCESS(STACKVAR(-12, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-12, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-12, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-12, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10042DD8);
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10042DD4);
    STACKVAR(-16, 4) = reinterpret_cast<any_int32>(this) + 0x0000004C;
    STACKVAR(-16, 4)->unknown_method_1003B920(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-16, 4), 0, 4) = GLOBAL(0x10042DD0);
    STACKVAR(-20, 4) = reinterpret_cast<any_int32>(this) + 0x00000064;
    STACKVAR(-20, 4)->unknown_method_1003A010(0x00000001);
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x10042DCC);
    STACKVAR(-24, 4) = reinterpret_cast<any_int32>(this) + 0x00000078;
    STACKVAR(-24, 4)->unknown_method_1003A160(0x00000001);
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DC8);
    STACKVAR(-28, 4) = reinterpret_cast<any_int32>(this) + 0x0000008C;
    STACKVAR(-28, 4)->unknown_method_1003BA20(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-28, 4), 0, 4) = GLOBAL(0x10042DC4);
    STACKVAR(-32, 4) = reinterpret_cast<any_int32>(this) + 0x000000A4;
    ACCESS(STACKVAR(-32, 4), 0, 4) = 0x00000000;
    ACCESS(STACKVAR(-32, 4), 12, 4) = 0x00000000;
    ACCESS(STACKVAR(-32, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-32, 4), 20, 4) = 0x00000000;
    STACKVAR(-36, 4) = reinterpret_cast<any_int32>(this) + 0x000000BC;
    STACKVAR(-36, 4)->unknown_method_1003A1A0(0x00000001);
    ACCESS(STACKVAR(-36, 4), 0, 4) = GLOBAL(0x10042DC0);
    STACKVAR(-40, 4) = reinterpret_cast<any_int32>(this) + 0x000000D0;
    STACKVAR(-40, 4)->unknown_method_1003BB80(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-40, 4), 0, 4) = GLOBAL(0x10042DBC);
    STACKVAR(-44, 4) = reinterpret_cast<any_int32>(this) + 0x000000E8;
    STACKVAR(-44, 4)->unknown_method_1003BC90(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-44, 4), 0, 4) = GLOBAL(0x10042DB8);
    STACKVAR(-48, 4) = reinterpret_cast<any_int32>(this) + 0x00000100;
    STACKVAR(-48, 4)->unknown_method_1003BE50(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-48, 4), 0, 4) = GLOBAL(0x10042DB4);
    STACKVAR(-52, 4) = reinterpret_cast<any_int32>(this) + 0x00000118;
    STACKVAR(-52, 4)->unknown_method_1003BF60(0x00000010, 0x00000001);
    ACCESS(STACKVAR(-52, 4), 0, 4) = GLOBAL(0x10042DB0);
    (reinterpret_cast<any_int32>(this) + 0x00000130)->unknown_method_1002E190();
    (reinterpret_cast<any_int32>(this) + 0x000001B0)->unknown_method_1002E190();
    STACKVAR(-56, 4) = reinterpret_cast<any_int32>(this) + 0x00000240;
    ACCESS(STACKVAR(-56, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-56, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-56, 4), 16, 8) = 0.0;
    (reinterpret_cast<any_int32>(this) + 0x00000258)->unknown_method_1002A5F0();
    ACCESS(this, 0, 4) = GLOBAL(0x10042DA0);
}

// address: 0x1003819B
B_ObjDscr::~B_ObjDscr()
{
    ProcedureInfo(this=Id(this), this_offset=-88, local_size=100, stack_delta=None)
    ACCESS(STACKVAR(-88, 4), 0, 4) = GLOBAL(0x10042DA0);
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(-88, 4)) + 0x00000118;
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042E0C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-4, 4), 16, 4)) == 0x00000000)
    {
        goto l100381DA;
    }
    ARG(ACCESS(STACKVAR(-4, 4), 20, 4));
    REGDEF(ecx=STACKVAR(-4, 4))
    unknown_function_1003BFC0();
}
Can't parse line: l100381DA: mov eax, dword ptr [ebp-058h]

// address: 0x100384CA
p100384CA
{
    ProcedureInfo(this=Id(this), this_offset=-100, local_size=100, stack_delta=None)
    ACCESS(GLOBAL(0x100488B8), 0, 4) = 0x40000000;
    ACCESS(GLOBAL(0x100488B4), 0, 4) = 0x00000002;
    unknown_function_1000468E(STACKVAR(8, 4), STACKVAR(-100, 4));
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(-100, 4)) + 0x0000000C;
    unknown_function_1000201E(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(-8, 4)) + 0x00000008);
    STACKVAR(-4, 4) = 0x00000000;
    goto l10038525;
}
Can't parse line: l1003851C: mov edx, dword ptr [ebp-004h]

// address: 0x1003896F
p1003896F
{
    ProcedureInfo(this=Id(this), this_offset=-312, local_size=332, stack_delta=None)
    ACCESS(GLOBAL(0x100488B8), 0, 4) = 0x40000000;
    ACCESS(GLOBAL(0x100488B4), 0, 4) = 0x00000002;
    ACCESS(GLOBAL(0x1004BF6C), 0, 4) = 0x00000001;
    unknown_function_10004676(STACKVAR(8, 4), STACKVAR(-312, 4));
    STACKVAR(-220, 4) = reinterpret_cast<any_int32>(STACKVAR(-312, 4)) + 0x0000000C;
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-220, 4), 16, 4)) == 0x00000000)
    {
        goto l100389D9;
    }
    ARG(0x00000001);
    REGDEF(ecx=STACKVAR(-220, 4))
    unknown_function_1003B840();
}
Can't parse line: l100389D9: mov ecx, dword ptr [ebp-0000000DCh]

// address: 0x100395E0
p100395E0
{
}
Can't parse line: l100395E3: mov eax, dword ptr [ebp+010h]

// address: 0x10039610
p10039610
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=0)
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000004;
    ACCESS(STACKVAR(-4, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 16, 8) = 0.0;
    ACCESS(this, 0, 4) = GLOBAL(0x10042D3C);
    REGDEF(eax=this)
}

// address: 0x10039670
p10039670
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=0)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj();
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000010;
    ACCESS(STACKVAR(-4, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 16, 8) = 0.0;
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(this) + 0x00000028;
    ACCESS(STACKVAR(-8, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-8, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-8, 4), 16, 8) = 0.0;
    STACKVAR(-12, 4) = reinterpret_cast<any_int32>(this) + 0x00000040;
    ACCESS(STACKVAR(-12, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-12, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-12, 4), 16, 8) = 0.0;
    ACCESS(this, 0, 4) = GLOBAL(0x10042D98);
    REGDEF(eax=this)
}

// address: 0x10039750
p10039750
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(-12, 4)) + 0x00000090;
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042D9C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l100397B4;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039781'

// address: 0x100397F0
p100397F0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1004217C);
    (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000004)->unknown_method_100039BA();
    REGDEF(ecx=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10039830
p10039830
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042D9C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l10039889;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039856'

// address: 0x100398B0
p100398B0
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10039960
p10039960
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1003819B();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x10039990
p10039990
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DE0);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l100399E9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100399B6'

// address: 0x10039A10
p10039A10
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DD8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l10039A69;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039A36'

// address: 0x10039A90
p10039A90
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DEC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l10039AE9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039AB6'

// address: 0x10039B10
p10039B10
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DF0);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l10039B69;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039B36'

// address: 0x10039B90
p10039B90
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DF4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l10039BE9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039BB6'

// address: 0x10039C10
p10039C10
{
    ProcedureInfo(this=Id(this), this_offset=-36, local_size=52, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-36, 4), 12, 4)) == 0x00000000)
    {
        goto l10039C66;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-36, 4), 12, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l10039C5F;
    }
    STACKVAR(-4, 4)->unknown_method_10039C10();
    REGDEF(ecx=0x00000001 & 0x00000001)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x10039D30
p10039D30
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 4, 4)) == 0x00000000)
    {
        goto l10039D6D;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-12, 4), 4, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l10039D66;
    }
    STACKVAR(-16, 4) = STACKVAR(-4, 4)->unknown_method_10039D30(0x00000001);
    goto l10039D6D;
}
Can't parse line: l10039D66: mov dword ptr [ebp-010h], 000000000h

// address: 0x10039D90
p10039D90
{
    ProcedureInfo(this=Id(this), this_offset=-36, local_size=52, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-36, 4), 12, 4)) == 0x00000000)
    {
        goto l10039DCD;
    }
    STACKVAR(-8, 4) = ACCESS(STACKVAR(-36, 4), 12, 4);
    STACKVAR(-4, 4) = STACKVAR(-8, 4);
    if (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) == 0x00000000)
    {
        goto l10039DC6;
    }
    STACKVAR(-40, 4) = STACKVAR(-4, 4)->unknown_method_10039D90(0x00000001);
    goto l10039DCD;
}
Can't parse line: l10039DC6: mov dword ptr [ebp-028h], 000000000h

// address: 0x10039EA0
p10039EA0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=0)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj();
    (reinterpret_cast<any_int32>(this) + 0x00000010)->unknown_method_1002E190();
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000090;
    ACCESS(STACKVAR(-4, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-4, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042D9C);
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x10042D94);
    ACCESS(this, 0, 4) = GLOBAL(0x10042D90);
    REGDEF(eax=this)
}

// address: 0x10039F20
p10039F20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x10042D9C);
    REGDEF(eax=this)
}

// address: 0x10039F60
p10039F60
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10039F77'

// address: 0x1003A010
p1003A010
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x10042DEC);
    REGDEF(eax=this)
}

// address: 0x1003A050
p1003A050
{
    ProcedureInfo(this=Id(this), this_offset=-28, local_size=32, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) + reinterpret_cast<any_int32>(ACCESS(STACKVAR(-28, 4), 12, 4)) - 1, ecx=STACKVAR(-28, 4), edx=0x00000000)
}
Failed to find pattern for 'div dword ptr [ecx+00Ch]'

// address: 0x1003A160
p1003A160
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x10042DF0);
    REGDEF(eax=this)
}

// address: 0x1003A1A0
p1003A1A0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 0, 4) = GLOBAL(0x10042DF4);
    REGDEF(eax=this)
}

// address: 0x1003A1E0
p1003A1E0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l1003A1FB;
}
Can't parse line: l1003A1F2: mov eax, dword ptr [ebp-004h]

// address: 0x1003A240
p1003A240
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=ACCESS(STACKVAR(-24, 4), 8, 4))
}
Failed to find pattern for 'jbe l1003A27E'

// address: 0x1003A360
p1003A360
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    goto l1003A37B;
}
Can't parse line: l1003A372: mov eax, dword ptr [ebp-004h]

// address: 0x1003A3C0
p1003A3C0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=ACCESS(STACKVAR(-24, 4), 8, 4))
}
Failed to find pattern for 'jbe l1003A400'

// address: 0x1003A4E0
p1003A4E0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042D9C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A539;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A506'

// address: 0x1003A560
p1003A560
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x10042DE8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-20, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A606;
    }
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-20, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A593'

// address: 0x1003A630
p1003A630
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x10042DE8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-20, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A6D6;
    }
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-20, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A663'

// address: 0x1003A700
p1003A700
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DE0);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A759;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A726'

// address: 0x1003A780
p1003A780
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DD8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A7D9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A7A6'

// address: 0x1003A800
p1003A800
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DF8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A8C1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A836'

// address: 0x1003A8E0
p1003A8E0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DF8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003A9A1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A916'

// address: 0x1003A9C0
p1003A9C0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DEC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003AA19;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003A9E6'

// address: 0x1003AA40
p1003AA40
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DF0);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003AA99;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003AA66'

// address: 0x1003AAC0
p1003AAC0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DFC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003AB81;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003AAF6'

// address: 0x1003ABA0
p1003ABA0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DFC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003AC61;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003ABD6'

// address: 0x1003AC80
p1003AC80
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042DF4);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003ACD9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003ACA6'

// address: 0x1003AD00
p1003AD00
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E00);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003ADC1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003AD36'

// address: 0x1003ADE0
p1003ADE0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E00);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003AEA1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003AE16'

// address: 0x1003AEC0
p1003AEC0
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=48, stack_delta=None)
    ACCESS(STACKVAR(-44, 4), 0, 4) = GLOBAL(0x10042E04);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-44, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B045;
    }
    STACKVAR(-40, 4) = ACCESS(STACKVAR(-44, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-44, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003AEF6'

// address: 0x1003B070
p1003B070
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x10042E10);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-20, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B116;
    }
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-20, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B0A3'

// address: 0x1003B140
p1003B140
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=48, stack_delta=None)
    ACCESS(STACKVAR(-44, 4), 0, 4) = GLOBAL(0x10042E04);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-44, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B2C5;
    }
    STACKVAR(-40, 4) = ACCESS(STACKVAR(-44, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-44, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B176'

// address: 0x1003B2F0
p1003B2F0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E08);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B3B1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B326'

// address: 0x1003B3D0
p1003B3D0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E08);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B491;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B406'

// address: 0x1003B4B0
p1003B4B0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E0C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B571;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B4E6'

// address: 0x1003B590
p1003B590
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E0C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B651;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B5C6'

// address: 0x1003B670
p1003B670
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042D68);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B6C9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B696'

// address: 0x1003B6F0
p1003B6F0
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=16, stack_delta=None)
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10042D78);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B761;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B716'

// address: 0x1003B780
p1003B780
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    REGDEF(esi=STACKVAR(8, 4))
}
Failed to find pattern for 'add esi, 000000004h'

// address: 0x1003B7C0
p1003B7C0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042D7C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l1003B819;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B7E6'

// address: 0x1003B840
p1003B840
{
    ProcedureInfo(this=Id(this), this_offset=-16, local_size=16, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-16, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B854'

// address: 0x1003B8D0
p1003B8D0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B8E4'

// address: 0x1003B920
p1003B920
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042DF8);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E18);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E14);
    REGDEF(eax=this)
}

// address: 0x1003B980
p1003B980
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B994'

// address: 0x1003B9D0
p1003B9D0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003B9E4'

// address: 0x1003BA20
p1003BA20
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042DFC);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E20);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E1C);
    REGDEF(eax=this)
}

// address: 0x1003BA80
p1003BA80
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BA97'

// address: 0x1003BB30
p1003BB30
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BB44'

// address: 0x1003BB80
p1003BB80
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E00);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E28);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E24);
    REGDEF(eax=this)
}

// address: 0x1003BBE0
p1003BBE0
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BBF7'

// address: 0x1003BC90
p1003BC90
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E04);
    REGDEF(eax=this)
}

// address: 0x1003BCE0
p1003BCE0
{
    ProcedureInfo(this=Id(this), this_offset=-40, local_size=44, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-40, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BCF7'

// address: 0x1003BE50
p1003BE50
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E08);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E30);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E2C);
    REGDEF(eax=this)
}

// address: 0x1003BEB0
p1003BEB0
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BEC7'

// address: 0x1003BF60
p1003BF60
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E0C);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E38);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E34);
    REGDEF(eax=this)
}

// address: 0x1003BFC0
p1003BFC0
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=24, stack_delta=None)
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003BFD7'

// address: 0x1003C070
p1003C070
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DF8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C131;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C0A6'

// address: 0x1003C150
p1003C150
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DFC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C211;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C186'

// address: 0x1003C230
p1003C230
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E00);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C2F1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C266'

// address: 0x1003C310
p1003C310
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E08);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C3D1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C346'

// address: 0x1003C3F0
p1003C3F0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E0C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C4B1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C426'

// address: 0x1003C4D0
p1003C4D0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DF8);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C591;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C506'

// address: 0x1003C5B0
p1003C5B0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042DFC);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C671;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C5E6'

// address: 0x1003C690
p1003C690
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E00);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C751;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C6C6'

// address: 0x1003C770
p1003C770
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E08);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C831;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C7A6'

// address: 0x1003C850
p1003C850
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E0C);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003C911;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C886'

// address: 0x1003C930
p1003C930
{
    ProcedureInfo(this=None, this_offset=None, local_size=60, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003CAA3;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003C951'

// address: 0x1003CBD0
p1003CBD0
{
    ProcedureInfo(this=None, this_offset=None, local_size=36, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003CC7F;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003CBF1'

// address: 0x1003CD80
p1003CD80
{
    ProcedureInfo(this=None, this_offset=None, local_size=48, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003CE2F;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003CDA1'

// address: 0x1003CFD0
p1003CFD0
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003D07F;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003CFF1'

// address: 0x1003D1F0
p1003D1F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003D23D;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003D20A'

// address: 0x1003D2E0
p1003D2E0
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003D32D;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003D2FA'

// address: 0x1003D3D0
p1003D3D0
{
    ProcedureInfo(this=None, this_offset=None, local_size=44, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003D47F;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003D3F1'

// address: 0x1003D5F0
p1003D5F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(12, 4), 16, 4)) == 0x00000000)
    {
        goto l1003D63D;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(12, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003D60A'

// address: 0x1003D740
p1003D740
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=0)
    ACCESS(this, 0, 8) = 0.0;
    ACCESS(this, 8, 8) = 0.0;
    ACCESS(this, 16, 8) = 0.0;
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000018;
    ACCESS(STACKVAR(-4, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 16, 8) = 0.0;
    REGDEF(eax=this)
}

// address: 0x1003D7C0
p1003D7C0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=0)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj();
    (reinterpret_cast<any_int32>(this) + 0x0000000C)->unknown_method_1002E190();
    ACCESS(this, 0, 4) = GLOBAL(0x10042E40);
    REGDEF(eax=this)
}

// address: 0x1003D7F0
p1003D7F0
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=0)
    reinterpret_cast<B_NamedObj *>(this)->B_NamedObj();
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000010;
    ACCESS(STACKVAR(-4, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-4, 4), 16, 8) = 0.0;
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(this) + 0x00000028;
    ACCESS(STACKVAR(-8, 4), 0, 8) = 0.0;
    ACCESS(STACKVAR(-8, 4), 8, 8) = 0.0;
    ACCESS(STACKVAR(-8, 4), 16, 8) = 0.0;
    ACCESS(this, 0, 4) = GLOBAL(0x10042E44);
    REGDEF(eax=this)
}

// address: 0x1003D890
p1003D890
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1004217C);
    (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000004)->unknown_method_100039BA();
    REGDEF(ecx=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x1003D8D0
p1003D8D0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1004217C);
    (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000004)->unknown_method_100039BA();
    REGDEF(ecx=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x1003D910
p1003D910
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x1004217C);
    (reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + 0x00000004)->unknown_method_100039BA();
    REGDEF(ecx=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test ecx, ecx'

// address: 0x1003D950
p1003D950
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=8)
    ACCESS(this, 4, 4) = 0x00000000;
    ACCESS(this, 8, 4) = 0x00000000;
    ACCESS(this, 12, 4) = STACKVAR(8, 4);
    ACCESS(this, 16, 4) = 0x00000000;
    ACCESS(this, 20, 4) = STACKVAR(12, 4);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E10);
    ACCESS(this, 0, 4) = GLOBAL(0x10042E3C);
    REGDEF(eax=this)
}

// address: 0x1003D9B0
p1003D9B0
{
    ProcedureInfo(this=Id(this), this_offset=-20, local_size=20, stack_delta=None)
    ACCESS(STACKVAR(-20, 4), 0, 4) = GLOBAL(0x10042E10);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-20, 4), 16, 4)) == 0x00000000)
    {
        goto l1003DA56;
    }
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-20, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-20, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003D9E3'

// address: 0x1003DA80
p1003DA80
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_1003DA8F();
    unknown_function_1003DAEE();
}

// address: 0x1003DA8F
p1003DA8F
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    ACCESS(GLOBAL(0x1004A9D4), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9D8), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9DC), 0, 4) = 0x00000010;
    ACCESS(GLOBAL(0x1004A9E0), 0, 4) = 0x00000000;
    ACCESS(GLOBAL(0x1004A9E4), 0, 4) = 0x00000001;
    ACCESS(&B_csvs, 0, 4) = GLOBAL(0x10042E58);
    ACCESS(&B_csvs, 0, 4) = GLOBAL(0x10042E54);
    ACCESS(&B_csvs, 0, 4) = GLOBAL(0x10042E50);
    ACCESS(&B_csvs, 0, 4) = GLOBAL(0x10042E4C);
}

// address: 0x1003DAEE
p1003DAEE
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    unknown_function_100415A8(GLOBAL(0x1003DB00));
}

// address: 0x1003DB00
p1003DB00
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    ACCESS(GLOBAL(0x1004A9D0), 0, 4) = GLOBAL(0x10042E58);
    if (reinterpret_cast<any_int32>(ACCESS(GLOBAL(0x1004A9E0), 0, 4)) == 0x00000000)
    {
        goto l1003DBBC;
    }
    STACKVAR(-20, 4) = ACCESS(GLOBAL(0x1004A9E4), 0, 4);
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004A9E0), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003DB33'

// address: 0x1003DBC0
B_ElementCSV::~B_ElementCSV()
{
    ACCESS(this, 0, 4) = GLOBAL(0x10042E5C);
    this->material.~B_Name();
    ACCESS(this, 0, 4) = GLOBAL(0x1004217C);
    this->name.~B_Name();
}

// address: 0x1003DBF3
unsigned int ReadCSV(const char *file_name, B_NDataBase<B_ElementCSV> *csvs)
{
    ProcedureInfo(this=None, this_offset=None, local_size=836, stack_delta=None)
    STACKVAR(-264, 4) = 0x00000000;
    STACKVAR(-4, 4) = fopen(STACKVAR(8, 4), GLOBAL(0x1004893C));
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003DC48'

// address: 0x1003DED0
p1003DED0
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1003DBC0();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003DF00
p1003DF00
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E58);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003DFC1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003DF36'

// address: 0x1003DFE0
p1003DFE0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E58);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003E0A1;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003E016'

// address: 0x1003E0C0
p1003E0C0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E58);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003E181;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003E0F6'

// address: 0x1003E1A0
p1003E1A0
{
    ProcedureInfo(this=Id(this), this_offset=-24, local_size=28, stack_delta=None)
    ACCESS(STACKVAR(-24, 4), 0, 4) = GLOBAL(0x10042E58);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-24, 4), 16, 4)) == 0x00000000)
    {
        goto l1003E261;
    }
    STACKVAR(-20, 4) = ACCESS(STACKVAR(-24, 4), 20, 4);
    REGDEF(cmpl=ACCESS(STACKVAR(-24, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003E1D6'

// address: 0x1003E280
p1003E280
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    REGDEF(ecx=ACCESS(STACKVAR(8, 4), 4, 4))
}
Failed to find pattern for 'cmp ecx, dword ptr [__imp__PyTuple_Type]; [python15.PyTuple_Type].'

// address: 0x1003E436
PyObject *CallPythonObject(PyObject *func, PyObject *args)
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    REGDEF(eax=reinterpret_cast<any_int32>(ACCESS(GLOBAL(0x10048984), 0, 4)) & 0x00000002)
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003E660
p1003E660
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=0)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyString_FromString(GLOBAL(0x10048CD8));
}

// address: 0x1003E679
p1003E679
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(16, 4) = STACKVAR(16, 4);
    fprintf(STACKVAR(12, 4), GLOBAL(0x10048CEC));
}
Can't parse line: l1003E69C: mov edx, dword ptr [ebp+008h]

// address: 0x1003E710
p1003E710
{
    ProcedureInfo(this=None, this_offset=None, local_size=152, stack_delta=None)
    STACKVAR(-132, 4) = 0x00000000;
}
Can't parse line: l1003E723: mov eax, dword ptr [ebp+008h]

// address: 0x1003E831
p1003E831
{
    ProcedureInfo(this=None, this_offset=None, local_size=152, stack_delta=None)
    STACKVAR(-132, 4) = 0x00000000;
}
Can't parse line: l1003E844: mov eax, dword ptr [ebp+008h]

// address: 0x1003E95C
p1003E95C
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048D98));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003E9A6
p1003E9A6
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048DB4));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003E9F0
p1003E9F0
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048DCC));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EA3C
p1003EA3C
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048DE4), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EAB8
p1003EAB8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E04));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EB04
p1003EB04
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E20), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EB59
p1003EB59
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E30), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EBAE
p1003EBAE
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E40), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EC03
p1003EC03
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E54), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EC58
p1003EC58
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E64), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003ECAD
p1003ECAD
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E78), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003ED02
p1003ED02
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048E8C), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003ED57
p1003ED57
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048EA4), LOCAL(-8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EDAC
p1003EDAC
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048EBC), LOCAL(-8), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EE09
p1003EE09
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048ED8));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EE53
p1003EE53
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048EF0));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EE9D
p1003EE9D
{
    ProcedureInfo(this=None, this_offset=None, local_size=136, stack_delta=None)
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048F08));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003EF05
p1003EF05
{
    ProcedureInfo(this=None, this_offset=None, local_size=32, stack_delta=None)
    STACKVAR(-8, 4) = LOCAL(-32);
    STACKVAR(-4, 4) = STACKVAR(12, 4);
    REGDEF(cmpl=STACKVAR(-4, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jbe l1003EF80'

// address: 0x1003EFD4
p1003EFD4
{
    ProcedureInfo(this=None, this_offset=None, local_size=184, stack_delta=None)
    STACKVAR(-8, 4) = 0x00000000;
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048F38), LOCAL(-8), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003F24C
p1003F24C
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048F60), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003F305
p1003F305
{
    ProcedureInfo(this=None, this_offset=None, local_size=372, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    REGDEF(eax=STACKVAR(8, 4))
}
Failed to find pattern for 'movsx ecx, byte ptr [eax]'

// address: 0x1003FA24
p1003FA24
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-4, 4) = STACKVAR(8, 4);
    STACKVAR(-8, 4) = STACKVAR(12, 4);
    STACKVAR(-12, 4) = ACCESS(STACKVAR(-8, 4), 0, 4);
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-4, 4), 0, 4);
}
Can't parse line: l1003FA46: mov eax, dword ptr [ebp-010h]

// address: 0x1003FA98
p1003FA98
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=0)
    STACKVAR(-8, 4) = STACKVAR(8, 4);
    STACKVAR(-4, 4) = STACKVAR(12, 4);
    strncmp(STACKVAR(-8, 4), ACCESS(STACKVAR(-4, 4), 0, 4), ACCESS(STACKVAR(-4, 4), 4, 4));
}

// address: 0x1003FAC8
p1003FAC8
{
    ProcedureInfo(this=None, this_offset=None, local_size=40, stack_delta=None)
    STACKVAR(-24, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    STACKVAR(-16, 4) = LOCAL(-28);
    STACKVAR(-20, 4) = LOCAL(-4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10048FCC), LOCAL(-24));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003FBCD
p1003FBCD
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=None)
    REGDEF(cmpl=STACKVAR(8, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l1003FBE4'

// address: 0x1003FCF4
p1003FCF4
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049048), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003FD8A
p1003FD8A
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    if (reinterpret_cast<any_int32>(STACKVAR(8, 4)) == 0x00000000)
    {
        goto l1003FDA2;
    }
    STACKVAR(-4, 4) = ACCESS(STACKVAR(8, 4), 12, 4);
    REGDEF(eax=STACKVAR(-4, 4))
    goto l1003FDA4;
}
Can't parse line: l1003FDA2: xor eax, eax

// address: 0x1003FDA8
p1003FDA8
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x100490BC), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003FE79
p1003FE79
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049128), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003FF12
p1003FF12
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x100491A0), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1003FFAB
p1003FFAB
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000032;
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x1004921C), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040054
p10040054
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049298), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x100400ED
p100400ED
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049318), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040186
p10040186
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000032;
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049398), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1004022F
p1004022F
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049414), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x100402C4
p100402C4
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049490), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x1004035E
p1004035E
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049528), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040401
p10040401
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x100495CC), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x100404A4
p100404A4
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049670), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040546
p10040546
{
    ProcedureInfo(this=None, this_offset=None, local_size=28, stack_delta=None)
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x10049714), LOCAL(-20), LOCAL(-12), LOCAL(-16), LOCAL(-24));
}
Failed to find pattern for 'test eax, eax'

// address: 0x100405F1
p100405F1
{
    ProcedureInfo(this=None, this_offset=None, local_size=24, stack_delta=None)
    STACKVAR(-20, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x100497B0), LOCAL(-20), LOCAL(-12), LOCAL(-16));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040694
p10040694
{
    ProcedureInfo(this=None, this_offset=None, local_size=16, stack_delta=None)
    STACKVAR(-12, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x1004985C), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x10040726
p10040726
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    STACKVAR(-16, 4) = 0x00000000;
    STACKVAR(8, 4) = STACKVAR(8, 4);
    PyArg_ParseTuple(STACKVAR(12, 4), GLOBAL(0x100498F0), LOCAL(-16), LOCAL(-12));
}
Failed to find pattern for 'test eax, eax'

// address: 0x100407BF
p100407BF
{
    ProcedureInfo(this=None, this_offset=None, local_size=8, stack_delta=0)
    ACCESS(GLOBAL(0x1004AB10), 0, 4) = unknown_function_100409D8();
    STACKVAR(-8, 4) = Py_InitModule4(GLOBAL(0x10049CC8), GLOBAL(0x10048A78), 0x00000000, 0x00000000, 0x000003EF);
    STACKVAR(-4, 4) = PyModule_GetDict(STACKVAR(-8, 4));
    PyDict_SetItemString(STACKVAR(-4, 4), GLOBAL(0x10049CD0), PyInt_FromLong(0x00000001));
    PyDict_SetItemString(STACKVAR(-4, 4), GLOBAL(0x10049CE0), PyInt_FromLong(0x00000002));
    PyDict_SetItemString(STACKVAR(-4, 4), GLOBAL(0x10049CF0), PyInt_FromLong(0x00000003));
    PyDict_SetItemString(STACKVAR(-4, 4), GLOBAL(0x10049CFC), PyInt_FromLong(0x00000004));
    PyDict_SetItemString(STACKVAR(-4, 4), GLOBAL(0x10049D0C), PyInt_FromLong(0x00000005));
    unknown_function_10040A5E(GLOBAL(0x10049D28), GLOBAL(0x10049D20), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049D48), GLOBAL(0x10049D38), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049D60), GLOBAL(0x10049D50), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049D7C), GLOBAL(0x10049D68), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049DA4), GLOBAL(0x10049D88), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049DC0), GLOBAL(0x10049DB8), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049DDC), GLOBAL(0x10049DD0), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049DF8), GLOBAL(0x10049DF0), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E0C), GLOBAL(0x10049E04), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E24), GLOBAL(0x10049E1C), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E3C), GLOBAL(0x10049E34), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E5C), GLOBAL(0x10049E4C), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E74), GLOBAL(0x10049E64), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049E8C), GLOBAL(0x10049E7C), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049EA0), GLOBAL(0x10049E94), 0x00000000);
    unknown_function_10040A5E(GLOBAL(0x10049EBC), GLOBAL(0x10049EA8), 0x00000000);
}

// address: 0x100409D8
p100409D8
{
    ProcedureInfo(this=None, this_offset=None, local_size=4, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    STACKVAR(-4, 4) = malloc(0x00000014);
}
Failed to find pattern for 'mov eax, dword ptr [__imp__PyType_Type]; [python15.PyType_Type].'

// address: 0x10040A5E
p10040A5E
{
    ProcedureInfo(this=None, this_offset=None, local_size=52, stack_delta=None)
    STACKVAR(-4, 4) = 0x00000000;
    REGDEF(cmpl=ACCESS(GLOBAL(0x1004BF60), 0, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l10040A96'

// address: 0x10040CB0
B_RDataLight::B_RDataLight()
{
}

// address: 0x10040CBE
B_RDataLight::B_RDataLight(float a, float b, float c, float d)
{
    a = a;
    b = b;
    c = c;
    d = d;
}

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
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    LOCAL(-8)->unknown_method_10003300();
    unknown_function_10003904(STACKVAR(8, 4), LOCAL(-8));
}
Failed to find pattern for 'mov edx, dword ptr [__imp_?B_3D_raster_device@@3PAVB_3DRasterDevice@@A]; [Raster.?B_3D_raster_device@@3PAVB_3DRasterDevice@@A].'

// address: 0x10040E61
p10040E61
{
    ProcedureInfo(this=None, this_offset=None, local_size=20, stack_delta=None)
    ARG(ACCESS(STACKVAR(12, 4), 0, 4));
}
Failed to find pattern for 'mov edx, dword ptr [__imp_?B_3D_raster_device@@3PAVB_3DRasterDevice@@A]; [Raster.?B_3D_raster_device@@3PAVB_3DRasterDevice@@A].'

// address: 0x10040F39
p10040F39
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=4)
    ACCESS(this, 0, 4) = STACKVAR(8, 4);
    REGDEF(eax=this)
}

// address: 0x10040F51
B_RDataTriangle::B_RDataTriangle()
{
    this->unknown_method_10040F39(0x00000001);
}

// address: 0x10040F69
B_ParticleGType::B_ParticleGType(const B_Name &new_type, const B_Name &parent_type, unsigned int operation_type, unsigned int duration)
{
    ProcedureInfo(this=Id(this), this_offset=-44, local_size=48, stack_delta=None)
    STACKVAR(-44, 4)->unknown_method_10003A07(STACKVAR(8, 4));
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(-44, 4)) + 0x0000000C;
    ACCESS(STACKVAR(-8, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-8, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042E68);
    ACCESS(STACKVAR(-44, 4), 32, 4) = STACKVAR(20, 4);
    ACCESS(STACKVAR(-44, 4), 40, 4) = STACKVAR(16, 4);
    ACCESS(STACKVAR(-44, 4), 0, 4) = GLOBAL(0x10042E64);
    ACCESS(STACKVAR(-44, 4), 12, 4) = GLOBAL(0x10042E60);
    ARG(STACKVAR(12, 4)->unknown_method_10003457());
}
Failed to find pattern for 'mov ecx, dword ptr [__imp_?B_3D_raster_device@@3PAVB_3DRasterDevice@@A]; [Raster.?B_3D_raster_device@@3PAVB_3DRasterDevice@@A].'

// address: 0x1004118F
B_ParticleGType::~B_ParticleGType()
{
    ProcedureInfo(this=Id(this), this_offset=-12, local_size=12, stack_delta=None)
    ACCESS(STACKVAR(-12, 4), 0, 4) = GLOBAL(0x10042E64);
    ACCESS(STACKVAR(-12, 4), 12, 4) = GLOBAL(0x10042E60);
    if (reinterpret_cast<any_int32>(STACKVAR(-12, 4)) == 0x00000000)
    {
        goto l100411BC;
    }
    STACKVAR(-8, 4) = reinterpret_cast<any_int32>(STACKVAR(-12, 4)) + 0x0000000C;
    goto l100411C3;
}
Can't parse line: l100411BC: mov dword ptr [ebp-008h], 000000000h

// address: 0x1004122B
B_IDataFile &operator >>(B_IDataFile &file, B_ParticleGType &particleType)
{
    ProcedureInfo(this=None, this_offset=None, local_size=52, stack_delta=None)
    unknown_function_10003A40(STACKVAR(8, 4), STACKVAR(12, 4));
    LOCAL(-8)->unknown_method_10003300();
    unknown_function_10001BD9(unknown_function_10003904(unknown_function_10001BEF(STACKVAR(8, 4), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000020), LOCAL(-8)), reinterpret_cast<any_int32>(STACKVAR(12, 4)) + 0x00000028);
    ARG(STACKVAR(-8, 4));
}
Failed to find pattern for 'mov ecx, dword ptr [__imp_?B_3D_raster_device@@3PAVB_3DRasterDevice@@A]; [Raster.?B_3D_raster_device@@3PAVB_3DRasterDevice@@A].'

// address: 0x100413EE
B_ODataFile &operator <<(B_ODataFile &file, const B_ParticleGType &particleType)
{
    ProcedureInfo(this=None, this_offset=None, local_size=12, stack_delta=None)
    unknown_function_10003A58(STACKVAR(8, 4), STACKVAR(12, 4));
    ARG(ACCESS(STACKVAR(12, 4), 36, 4));
}
Failed to find pattern for 'mov ecx, dword ptr [__imp_?B_3D_raster_device@@3PAVB_3DRasterDevice@@A]; [Raster.?B_3D_raster_device@@3PAVB_3DRasterDevice@@A].'

// address: 0x100414A0
p100414A0
{
    ProcedureInfo(this=Id(this), this_offset=-8, local_size=8, stack_delta=None)
    ACCESS(STACKVAR(-8, 4), 0, 4) = GLOBAL(0x10042E68);
    if (reinterpret_cast<any_int32>(ACCESS(STACKVAR(-8, 4), 16, 4)) == 0x00000000)
    {
        goto l100414F9;
    }
    REGDEF(cmpl=ACCESS(STACKVAR(-8, 4), 16, 4), cmpr=0x00000000)
}
Failed to find pattern for 'jne l100414C6'

// address: 0x10041520
p10041520
{
    ProcedureInfo(this=Id(this), this_offset=-4, local_size=4, stack_delta=None)
    STACKVAR(-4, 4)->unknown_method_1004118F();
    REGDEF(eax=reinterpret_cast<any_int32>(STACKVAR(8, 4)) & 0x00000001)
}
Failed to find pattern for 'test eax, eax'

// address: 0x100415A8
p100415A8
{
    ProcedureInfo(this=None, this_offset=None, local_size=0, stack_delta=None)
    atexit_0x1004157C();
}

// address: 0x10041600
p10041600
{
}
Unexpected instruction type <class 'NoneType'>

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
