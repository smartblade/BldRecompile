#define IFILE_CACHE_SIZE 0x4000
struct PyObject;
class B_FileInfo;

class LIB_EXP B_IDataFile
{
public:
    B_IDataFile();
    B_IDataFile(const char* file_name, int flags);
    ~B_IDataFile();
    static void ResetnOpenedFiles();
    static int GetnOpenedFiles();
    static int GetnOpenFiles();
    static int SetOnOpenFunc(PyObject* func);
    static void RemoveOnOpenFunc();
    void Close();
    void Open(const char* src, int flags);
    long Length() const;
    long Seek(long offset, int whence);
    long Tell();
    unsigned char Peek();
    int Eof();
    void Read(void* data, unsigned int size);


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100021E0
    * VC++ mangling:          ?OK@B_IDataFile@@QBEIXZ
    */

    unsigned int OK() const
    {
        return fd != -1;
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002200
    * VC++ mangling:          ?GetFileName@B_IDataFile@@QBEPBDXZ
    */

    char const* GetFileName() const
    {
        return this->file_name;
    }

    B_IDataFile& operator =(const B_IDataFile& other);
private:
    unsigned int ReadCacheBlock();
    int fd;
    char* file_name;
    unsigned int file_size;
    char fileCache[IFILE_CACHE_SIZE];
    unsigned int cacheBlockStartPos;
    unsigned int posInCacheBlock;
    B_FileInfo *fileInfo;

    static int n_opened_files;
    static int n_open_files;
    static PyObject* OnOpenFunc;
    int SetPosition(long position);
};
