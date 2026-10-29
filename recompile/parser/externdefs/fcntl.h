#define O_RDONLY       0x0000  /* open for reading only */
#define O_WRONLY       0x0001  /* open for writing only */
#define O_RDWR         0x0002  /* open for reading and writing */
#define O_APPEND       0x0008  /* writes done at eof */

#define O_CREAT        0x0100  /* create and open file */
#define O_TRUNC        0x0200  /* open and truncate */
#define O_EXCL         0x0400  /* open only if file doesn't already exist */

/* O_TEXT files have <cr><lf> sequences translated to <lf> on read()'s,
** and <lf> sequences translated to <cr><lf> on write()'s
*/

// TODO there is collision with OFILE_CACHE_SIZE #define O_TEXT         0x4000  /* file mode is text (translated) */
#define O_BINARY       0x8000  /* file mode is binary (untranslated) */
#define O_WTEXT        0x10000 /* file mode is UTF16 (translated) */
#define O_U16TEXT      0x20000 /* file mode is UTF16 no BOM (translated) */
#define O_U8TEXT       0x40000 /* file mode is UTF8  no BOM (translated) */

/* macro to translate the C 2.0 name used to force binary mode for files */

#define O_RAW  O_BINARY

/* Open handle inherit bit */

#define O_NOINHERIT    0x0080  /* child process doesn't inherit file */

/* Temporary file bit - file is deleted when last handle is closed */

#define O_TEMPORARY    0x0040  /* temporary file bit */

/* temporary access hint */

#define O_SHORT_LIVED  0x1000  /* temporary storage file, try not to flush */

/* sequential/random access hints */

#define O_SEQUENTIAL   0x0020  /* file access is primarily sequential */
#define O_RANDOM       0x0010  /* file access is primarily random */
