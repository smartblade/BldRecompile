#include "sound_device.h"
#include "bld_misc_funcs.h"
#include <Sound/SoundFuncs.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004BF1EF
*/

B_Sound *CreateSound(const char *file_name, const char *sound_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF236
*/

B_Sound *CreateSoundS(B_Sound * sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF25D
*/

void DestroySound(B_Sound * sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF2A4
*/

int SetSoundVolume(double volume)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF2D8
*/

double GetSoundVolume()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF2FE
*/

int SoundSystemActive()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF31A
*/

int SetSSFrecuency(int frequency)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF34D
*/

int SetSS2dChannels(int num_ch)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF380
*/

int SetSS3dChannels(int num_ch)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF3B3
*/

int SetSSFilter(int filter_output)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF3E6
*/

int KillMusic()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF410
*/

int ShutDownSoundChannels()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF43A
*/

int PauseSoundSystem()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF470
*/

int PauseSoundSystemButMusic()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF492
*/

int ResumeSoundSystem()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF4C8
*/

int SetMusicVolume(float volume)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF4F4
*/

double GetMusicVolume()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF51A
*/

int GetSSQuality()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF53C
*/

int SetSSQuality(int SSQuality)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF563
*/

int GetSSSpeakerConfig()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF5E2
*/

int SetEAXOverride(int EAXOverride)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF63F
*/

int GetEAXOverride()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF656
*/

int SaveSSConfig()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF678
*/

int SetSSSpeakerConfig(int config)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF75B
*/

int CreateGhostSector(
    const char *ghost_sector_name, const char *group_name,
    double floor_height, double roof_height, int num_points,
    point_2d_t *points
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF957
*/

int SetEAX(int eax_flag)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BF95E
*/

int SetGhostSectorSound(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFEAB
*/

B_Sound *GetGhostSectorSound(const char *gs_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFEEA
*/

int SetGhostSectorGroupSound(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFEF1
*/

int SetShowSounds(int showSounds)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFEFB
*/

int GetSoundDevInstace()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFF02
*/

int nSounds()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFF27
*/

const char *GetSoundName(int soundId)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFF44
*/

const char *GetSoundFileName(int soundId)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFF6E
*/

int PlaySoundM(B_Sound *sound, double x, double y, double z, int i_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004BFFEE
*/

int PlaySoundStereo(B_Sound *sound, int i_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C003B
*/

int StopSound(B_Sound *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0082
*/

double GetSoundFloatProperty(int property_kind, B_Sound *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0143
*/

void SetSoundFloatProperty(int property_kind, B_Sound *sound, double value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0293
*/

char *GetSoundStringProperty(int property_kind, B_Sound *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C02E9
*/

// TODO fix prototype
void SetSoundStringProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C02F0
*/

// TODO fix prototype
void GetSoundIntProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C033D
*/

int SetSoundIntProperty(int property_kind, B_Sound *sound, int value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0394
*/

void SetSoundPitchVar(
        B_Sound *sound, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C03B7
*/

// TODO fix prototype
void GetSoundFuncProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0436
*/

// TODO fix prototype
void SetSoundFuncProperty()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0508
*/

int dropDebugInfo()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C052F
*/

int GetMusicEventPriority(int unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0550
*/

int getMusicEvent(const char *event_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0571
*/

int exeMusicEvent(int unknown1, int unknown2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C05A0
*/

int addMusicEventCD(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C05F5
*/

int addMusicEventMP3(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C064B
*/

int addMusicEventWAV(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C06A1
*/

int addMusicEventADPCM(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C06F7
*/

B_Sound *GetSound(const char *sound_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C071E
*/

int addSoundVar(B_Sound *sound, const char *alt_sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0750
*/

void saveSoundStats(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0779
*/

int loadMusicState(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C07D1
*/

int saveMusicState(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C0897
*/

int loadSoundDataBase(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004C08F0
*/

int saveSoundDataBase(const char *file_name)
{
}
