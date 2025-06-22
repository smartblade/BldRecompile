#include <bld_python.h>
#include <Raster/RasterDevice.h>
#include <View/CameraView.h>
#include "BladeApp.h"
#include <BBLibc/BBLibc.h>
#include <BBLibc/Name.h>
#include <BBLibc/MessageManager.h>
#include <BBLibc/NDataBase.h>
#include <BBLibc/ResourceManager.h>
#include <BBLibc/BitMap.h>
#include <BBLibc/BitMap24.h>
#include <BBLibc/Resource.h>
#include <BBLibc/ObjDscr.h>
#include <BBLibc/ODataFile.h>
#include <Entities/CameraEntity.h>
#include <Entities/PersonEntity.h>
#include "bld_misc_funcs.h"
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00427880
*/

int SetAppMode(const char *mode)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004278D5
*/

const char *GetAppMode()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427910
*/

void BeginLoadGame()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427943
*/

void DoneLoadGame()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427976
*/

int SetSaveInfo(PyObject *info)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004279E1
*/

PyObject *GetSaveInfo()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A0D
*/

int SaveEntitiesData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A20
*/

int LoadEntitiesData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A33
*/

int SaveParticleSystemsData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427B03
*/

int LoadParticleSystemsData(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427DE8
*/

int SaveCombustionData(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427EB7
*/

int LoadCombustionData(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042819A
*/

void ReassignCombustionData()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004281D3
*/

int SaveAnmRaceData(const char *file_name, const char *race)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042857B
*/

int LoadAnmRaceData(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004289E0
*/

int GetnRaces()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004289EA
*/

const char *GetRaceName(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00428A22
*/

int SaveAnmSoundData(const char *file_name, const char *race)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00428BEE
*/

int LoadAnmSoundData(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00428FD6
*/

const char *GetCommandLine()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042900C
*/

const char *GetCurrentMap(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429049
*/

int SetCurrentMap(const char *map)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429086
*/

int LoadWorld(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004290C0
*/

int SetListenerMode(int mode, double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429128
*/

int GetListenerMode()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042915B
*/

int Quit()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429194
*/

int SetTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004291D2
*/

int GoToTime(double time)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429210
*/

double GetTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042921F
*/

void StopTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429255
*/

void RestartTime()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042928B
*/

void SetTimeSpeed(double speed)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292C9
*/

double GetTimeSpeed()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292FF
*/

int AddInputAction(const char *action_name, int npi)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429342
*/

int RemoveInputAction(const char *action_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429381
*/

int AssocKey(
    const char *action, const char *input_device, const char *key,
    int press
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004293C7
*/

int Bind(const char *key, PyObject *proc)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429446
*/

int UnBind(const char *key, PyObject *proc)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004294C5
*/

int Bind2(
    const char *act, const char *subact1,
    const char *subact2, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042956A
*/

double GetTimeActionHeld(const char *Action)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004295C2
*/

int BindPred(const char *key, const char *pred)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429641
*/

int UnBindPred(const char *key, const char *pred)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004296C0
*/

void UnBindAll()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004296F6
*/

const char *Input(const char *text)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429733
*/

int MarkLevelToLoad(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429793
*/

int ReadLevel(const char *filename)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004297F3
*/

unsigned int ReadBitMap(const char *filename, const char *internalname)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429863
*/

unsigned int ReadAlphaBitMap(const char *filename, const char *internalname)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004298D3
*/

void CloseLevel(const char *statement, const char *newMap)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429914
*/

int StartRecordingDemo()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429923
*/

int EndRecordingDemo(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429936
*/

int PlayDemo(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429949
*/

int DeactivateInput()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042997F
*/

int ActivateInput()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004299B5
*/

int OutSound(int soundId, double x, double y, double z, int unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429A10
*/

int SetDefaultMass(const char *entity_kind, double mass)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429C4F
*/

int SetDefaultMaterial(const char *entity_kind, const char *material)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429F2D
*/

void SetSun(int exists, double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429F71
*/

int InsideAA(int AA, double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429FDF
*/

int SetDrawObjectShadows(int draw)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A000
*/

int GetDrawObjectShadows()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A019
*/

int SetAutoEngageCombat(int auto_engage_combat)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A03A
*/

int GetAutoEngageCombat()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A053
*/

int SetAecGap(double aec_gap)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A07D
*/

double GetAecGap()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A095
*/

int SetBloodLevel(int blood_level)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A0CF
*/

int GetBloodLevel()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A105
*/

int SetMutilationLevel(int mutilation_level)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A13F
*/

int GetMutilationLevel()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A175
*/

void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A232
*/

void AnmDelEvent(const char *anm_name, const char *event_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A2D0
*/

void AnmClearEvents(const char *anm_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A354
*/

double AnmGetEventFrame(const char *anm_name, const char *event_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A400
*/

int AddParticleGType(
    const char *new_type, const char *parent_type, int operation_type,
    int duration
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A697
*/

int SetParticleGVal(
    const char *type, int i, int r, int g, int b, int alpha, double size
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A775
*/

int GetnParticleGType()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A77F
*/

int GetParticleGType(
    int index, const char **type, const char **parent_type,
    int *operation_type, int *duration
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A82F
*/

int GetParticleGVal(
    const char *type, int index, int *r, int *g, int *b, int *alpha,
    double *size
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A915
*/

int SetTurnSpeed(const char *race_name, double new_speed)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A930
*/

int SetAnimationFactor(const char *mov, double new_speed_factor)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A94B
*/

int SetAutoGenTexture(const char *textureName, int textureEffect)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A98E
*/

const char *GenerateEntityName()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A9A2
*/

int AddWatchAnim(const char *anim)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A9B5
*/

int AddAnimFlags(
    const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
    int bng_mov, int head_f
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042A9E0
*/

int SetActionCameraMovement(
    const char *action_name, double angle, double start_pos, double end_pos
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042ABBA
*/

int SetRootWidget(B_Widget *widget)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042ABF6
*/

B_Widget *GetRootWidget()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042AC32
*/

int AddCombustionDataFor(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042AE7A
*/

void RM_FreeResource(B_Resource *resource)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042AEAE
*/

B_BitMap *RM_GetResource(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B0F4
*/

void UpdateAGTexture(long bmpHandle)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B192
*/

const char *GetWorldFileName(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B1A5
*/

int SetAfterFrameFunc(const char *name, PyObject *function)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B1E8
*/

int RemoveAfterFrameFunc(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B227
*/

PyObject *GetAfterFrameFunc(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B261
*/

const char *GetAfterFrameFuncName(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B29B
*/

int GetnAfterFrameFuncs()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B2D1
*/

int SetMenuTgapFunc(PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B310
*/

PyObject *GetMenuTgapFunc()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B346
*/

int SetCallCheck(int check)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B366
*/

int OpenDebugChannel(const char *channel_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B39C
*/

int CloseDebugChannel(const char *channel_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B444
*/

int SetShowAreas(int action_areas_bit_mask)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B453
*/

int WriteText(double x, double y, const char *text)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B4EC
*/

int GetTextWH(const char *text, double *w, double *h)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B672
*/

int GetScreenRect(
    double *x_min, double *y_min, double *x_max, double *y_max
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B795
*/

int GetScreenXY(
    double map_x, double map_y, double map_z, double *screen_x,
    double *screen_y
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B8E8
*/

int DrawBOD(
    const char *BODName, int x, int y, int w, int h, double scale,
    int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B97A
*/

int CreateTriggerSector(
    const char *trigger_sector_name, const char *group_name,
    double floor_height, double roof_height, int num_points,
    point_2d_t *points
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BC9A
*/

int SetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type, PyObject *func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BCB5
*/

PyObject *GetTriggerSectorFunc(
    const char *trigger_sector_name, const char *func_type
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BCCC
*/

int GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BCDF
*/

int GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BCF2
*/

const char *GetTriggerSectorGroup(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD05
*/

double *GetTriggerSectorPoints(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD18
*/

int SetTriggerSectorData(
    const char *trigger_sector_name, PyObject *data
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD2F
*/

PyObject *GetTriggerSectorData(const char *trigger_sector_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD42
*/

int nTriggerSectors()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD55
*/

const char *GetTriggerSectorName(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BD68
*/

int GetModelPos(const char *person, double *x, double *y, double *z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042BFF8
*/

size_t GetWindowId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C031
*/

size_t GetProgramId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C06A
*/

int TakeSnapShot()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C0A5
*/

int nSectors()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C0AF
*/

void SetRunString(const char *str)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C0EC
*/

int SetStringValue(const char *variable, const char *value)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C12A
*/

const char *GetStringValue(const char *variable)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C164
*/

int DeleteStringValue(const char *variable)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C19E
*/

int SaveProfileData(const char *file_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C1B9
*/

int OpenProfileSection(int section, const char *comment)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C1D4
*/

int CloseProfileSection(int section)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C1EF
*/

int StartProfile()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C20A
*/

int EnableProfiler(void)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C225
*/

int DisableProfiler()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C240
*/

int SetInputMode(const char *device, const char *mode)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C281
*/

const char *GetInputMode(const char *device)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042C2BE
*/

const char *GetLastPlayerCType()
{
}
