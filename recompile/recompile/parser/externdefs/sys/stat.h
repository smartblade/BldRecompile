#define S_IFMT         0xF000          /* file type mask */
// TODO there is collision with OFILE_CACHE_SIZE #define S_IFDIR        0x4000          /* directory */
#define S_IFCHR        0x2000          /* character special */
#define S_IFIFO        0x1000          /* pipe */
#define S_IFREG        0x8000          /* regular */
#define S_IREAD        0x0100          /* read permission, owner */
#define S_IWRITE       0x0080          /* write permission, owner */
#define S_IEXEC        0x0040          /* execute/search permission, owner */
