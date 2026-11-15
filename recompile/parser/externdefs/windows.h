#define FORMAT_MESSAGE_ALLOCATE_BUFFER  0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS   0x00000200
#define FORMAT_MESSAGE_FROM_STRING      0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE     0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM      0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY   0x00002000

#define LANG_SYSTEM_DEFAULT             0x0800
#define LANG_USER_DEFAULT               0x0400

#define FormatMessage                   FormatMessageA
#define GetPrivateProfileString         GetPrivateProfileStringA
