#include <BladeApp.h>
#include <Control/Events.h>
#include <Entities/AuraEntity.h>
#include <Entities/CameraEntity.h>
#include <Entities/BipedEntity.h>
#include <Entities/DecalEntity.h>
#include <Entities/PersonEntity.h>
#include <Entities/PhysicSIEntity.h>
#include <Entities/SparkEntity.h>
#include <Math/BSpline.h>
#include <BBLibc/MessageManager.h>
#include "bld_misc_funcs.h"
#include <Entities/EntityFuncs.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEA0
*/

int GetSplinePos(B_Spline *spline, float time, B_Vector *position)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEBA
*/

void AddNodeSpline(
    B_Spline *spline, int nodeIndex, double time, B_Vector position,
    B_Vector startTangent, B_Vector endTangent)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEF3
*/

int CloseSpline(B_Spline *spline)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFF00
*/

int ClearSpline(B_Spline *spline)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFF0D
*/

B_Entity *CreateSpark(
    const char *name, const B_Vector &spark_point, const B_Vector &spark_dir,
    double d_unknown1, double d_unknown2, double d_unknown3,
    double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
    int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
    float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00500036
*/

B_Entity *CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00501FE9
*/

int DeleteEntity(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00503351
*/

B_Entity *CreateEntityDecal(
    const char *name, double x, double y, double z, int i_unknown,
    double d_unknown1, double d_unknown2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050340C
*/

B_Entity *GetEntity(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050360D
*/

B_Entity *GetEntityI(int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005036B2
*/

const char *GetEntityName(B_Entity *entity)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005036E1
*/

int GetEntitiesAt(
        double x, double y, double z, double radius, char ***entity_names
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005039F3
*/

int GetEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00503D6F
*/

int GetObjectEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005040EB
*/

int GetEnemiesVisibleFrom(
    double xc, double yc, double zc, double radius, double xdir,
    double ydir, double zdir, double angle, char ***enemy_names)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504467
*/

int SetCombos(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504527
*/

int GetCombos(const char *person_name, combo_t **combos)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005045A6
*/

int GetWeaponCombos(
        const char *person_name, const char *weapon_kind, combo_t **combos
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504629
*/

int nEntities()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050463C
*/

int GetNewExclusionGroupId()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504646
*/

int AddCameraEvent(const char *entity_name, int frame, PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504695
*/

int DeleteCameraEvent(const char *entity_name, int frame)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005046DB
*/

int CameraAddSourceNode(
    const char *entity_name, float time, B_Vector position
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050472F
*/

int CameraAddTargetNode(
    const char *entity_name, float time, B_Vector position
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504783
*/

int CameraSetStartTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector startTangent
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005047D2
*/

int CameraSetEndTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector endTangent
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504821
*/

int CameraSetStartTangentTargetNode(
    const char *entity_name, int nodeIndex, B_Vector startTangent
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504870
*/

int CameraSetEndTangentTargetNode(
    const char *entity_name, int nodeIndex, B_Vector endTangent
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005048BF
*/

int CameraSetPersonView(
    const char *entity_name, const char *person_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504905
*/

int CameraSetMaxCamera(
    const char *entity_name, const char *cam_file_name, int i_unknown,
    int num_frames
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504953
*/

int CameraCut(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005049E2
*/

int CameraSetTravelingView(
    const char *entity_name, int s_type, int t_type
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504A2C
*/

int CameraClearPath(const char *entity_name, int node)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504ABA
*/

int CameraStartPath(const char *entity_name, int node)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504B29
*/

int UseEntity(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504B5F
*/

int ChangeEntityStatic(const char *entity_name, int is_static)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005050DD
*/

int ChangeEntityActor(const char *entity_name, int is_actor)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00505F63
*/

int ChangeEntityPerson(const char *entity_name, int is_person)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00506E31
*/

int ChangeEntityWeapon(const char *entity_name, int is_weapon)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00507A06
*/

int ChangeEntityArrow(const char *entity_name, int is_arrow)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050888E
*/

int SetNextAttack(
    const char *entity_name, const char *attack, int *res
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005088E8
*/

B_Entity *SeverLimb(const char *entity_name, int limb)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508935
*/

// TODO fix prototype
void SetCombatGroup()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508B11
*/

int SubscribeEntityToList(
        const char *entity_name, const char *timer_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508B80
*/

int MessageEvent(
        const char *entity_name, int message_type, int unknown1, int unknown2
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508BBB
*/

int InterruptCombat(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508CD9
*/

const char *GetParticleEntity(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508D4D
*/

int Rel2AbsVector(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508E06
*/

int Rel2AbsPoint(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00508EBF
*/

int Rel2AbsVectorN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050901D
*/

int Rel2AbsPointN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050917B
*/

int Abs2RelVector(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00509257
*/

int Abs2RelPoint(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00509333
*/

int Abs2RelVectorN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005094D1
*/

int Abs2RelPointN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050966F
*/

double SQDistance2(const char *entity_name1, const char *entity_name2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050973E
*/

int RemoveEntityFromList(
        const char *entity_name, const char *timer_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005097AD
*/

int CreateTimer(const char *timer_name, double period)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005097EB
*/

int GetnTimers()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005097FA
*/

int GetTimerInfo(
        int timer_index, const char **timer_name, double *period
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050981F
*/

int GetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050B513
*/

int GetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050D31F
*/

int GetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char **value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050E086
*/

int GetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050F6E7
*/

int GetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050F8B9
*/

int GetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject **func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00510A2A
*/

int SetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00511DB7
*/

int SetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00513675
*/

int SetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char *value
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00514C9B
*/

int SetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051603F
*/

int SetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005163AA
*/

int SetEntityData(const char *entity_name, PyObject *data)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051645D
*/

PyObject *GetEntityData(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005164FD
*/

int SetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject *func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517526
*/

int SetEntityInternalState(
        const char *entity_name, PyObject *internal_state
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051758B
*/

int GetEntityInternalState(
        const char *entity_name, PyObject **internal_state
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005175E8
*/

int AddSoundAnim(
    const char *entity_name, const char *anm_event, double time, B_Sound *sound
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517688
*/

int AddSoundEvent(
        const char *entity_name, const char *event, B_Sound *sound
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517718
*/

int AddScheduledFunc(
    double time, PyObject *func, PyObject *args, const char *name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517740
*/

int RemoveScheduledFunc(const char *name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517758
*/

int GetnScheduledFuncs()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517767
*/

int GetScheduledFunc(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051778A
*/

int EntityRotate(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517867
*/

int EntityRotateAbs(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005179E7
*/

int EntityRotateRel(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517B67
*/

int EntityMove(
        const char *entity_name, double x, double y, double z, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517C3C
*/

int EntitySetPosition(
        const char *entity_name, double x, double y, double z, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517D17
*/

int EntitySetOrientation(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517E42
*/

int EntityPutToWorld(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517E97
*/

int EntityAddAnmEventFunc(
        const char *entity_name, const char *anm_event, PyObject *func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517F32
*/

int EntityDelAnmEventFunc(
        const char *entity_name, const char *anm_event
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517FB9
*/

int EntityClearAnmEventFuncs(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518030
*/

int ClearActorPath(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005180A2
*/

int AddActorPathnode(
        const char *entity_name, double time, double x, double y, double z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518148
*/

int StartActorPath(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005181BA
*/

int GoToActorPath(
        const char *entity_name, int i_unknown, double d_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518238
*/

int TestPos(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051831A
*/

int TestPosInOwnBox(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005184E8
*/

int TurnOnActor(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051855A
*/

int TurnOffActor(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005185CC
*/

int SetAttackList(const char *entity_name, PyObject *attack_list)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005186BA
*/

PyObject *GetAttackList(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051872A
*/

PyObject *GetGroupMembers(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518910
*/

PyObject *GetCombatants(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051898B
*/

int SetActorNodeStartTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518A2D
*/

int SetActorNodeEndTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518ACF
*/

int SetSound(const char *entity_name, const char *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518B45
*/

int SetObjectSound(const char *entity_name, const char *sound)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518BBB
*/

int PlayEntitySound(const char *entity_name, int i_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518CA3
*/

int Stop(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518D90
*/

int StopAt(const char *entity_name, double x, double y, double z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518E2E
*/

int CheckAnimCol(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00518F1A
*/

int RemoveFromInvent(const char *entity_name, const char *obj_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051919B
*/

int ResetWounds(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051920D
*/

int RemoveFromInventRight(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519285
*/

int RemoveFromInventLeft(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005192FD
*/

int RemoveFromInventLeft2(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519375
*/

int CanISee(
    const char *entity_name, const char *seen_entity_name, int *canISee)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051942F
*/

int CanISeeFrom(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005194EE
*/

int SetActiveEnemy(
        const char *entity_name, const char *active_enemy_name, int *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005195C0
*/

int ExcludeHitFor(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519697
*/

int ExcludeHitInAnimationFor(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519792
*/

int Link(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519833
*/

int LinkToNode(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051996F
*/

int LinkAnchors(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519A7D
*/

int UnlinkChilds(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519ACF
*/

int GetNodeIndex(
        const char *entity_name, const char *node_name, int *index
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519B6F
*/

int UnlinkChild(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519C0D
*/

int InsideActionArea(
        const char *entity_name, int action_area, int *is_inside
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519CBF
*/

int SetTmpAnmFlags(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519D4F
*/

int SetAnmFlags(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519DDF
*/

int LaunchAnimation2(
        const char *entity_name, const char *anm_name1, const char *anm_name2
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519E5F
*/

int SetEnemy(const char *entity_name, const char *enemy_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519F38
*/

const char *GetEnemy(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00519FD6
*/

int Chase(
        const char *entity_name, const char *enemy_name, int action_area
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A0A5
*/

int ResetChase(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A14B
*/

int GoTo(const char *entity_name, int x, int y, int z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A1FC
*/

int CanGoTo(const char *entity_name, int x, int y, int z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A2A8
*/

int QuickFace(const char *entity_name, double angle)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A32A
*/

int Face(const char *entity_name, double angle)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A3E3
*/

int StartLooking(const char *entity_name, int x, int y, int z)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A3ED
*/

int StopLooking(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A47A
*/

int LookAtEntity(
        const char *entity_name, const char *look_at_entity_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A5D6
*/

int LaunchWatch(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A68A
*/

int GetActionMode(const char *entity_name, int *action_mode)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A74D
*/

int StartGrabbing(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A789
*/

int StopGrabbing(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A7C5
*/

int AddEntWatchAnim(const char *entity_name, const char *anm_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A841
*/

int Freeze(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A8D7
*/

int UnFreeze(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A96A
*/

int SwitchTo1H(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051A9E2
*/

int GetDummyAxis(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051AD9B
*/

int GraspPos(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051AF97
*/

int SwitchToBow(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B00F
*/

int LaunchBayRoute(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B09A
*/

int EntityCatchOnFire(
        const char *entity_name, double x, double y, double z
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B18D
*/

int GetNChildren(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B1DB
*/

const char *GetChild(const char *entity_name, int index)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B225
*/

int CreateBipedData(const char *biped_name, const char *kind)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B4D3
*/

int AddBipedAction(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051B971
*/

int RemoveBipedAction(const char *race_name, const char *action_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051BC8F
*/

int AddBipedActionC(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051BEF4
*/

int SetActionEventTable(
    const char *race_name, const char *action_name, const char *table_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051C4A4
*/

int SetEventTableFuncC(
    const char *event_table_name, const char *event_type, const char *func_name
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051CA1C
*/

int SetEventTableFunc(
    const char *event_table_name, const char *event_type, PyObject *func
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051CE46
*/

int DoAction(const char *entity_name, const char *action_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051CEBC
*/

int DoActionWI(
    const char *entity_name, const char *action_name,
    int interpolation_type, double time, double unknown1
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051CF72
*/

int SetOnFloor(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051CFE4
*/

int RaiseEvent(const char *entity_name, const char *event_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D065
*/

int SetSolidMask(const char *kind, int mask)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D25D
*/

int IsValidEntity(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D283
*/

int EntityRemoveFromWorld(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D2D7
*/

int EntityRemoveFromWorldWithChilds(const char *entity_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D32B
*/

int ImpulseC(
    const char *entity_name, double x, double y, double z, double x_vec,
    double y_vec, double z_vec
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D3FA
*/

int SetAuraActive(const char *entity_name, int is_active)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D47C
*/

int SetAuraParams(
    const char *entity_name, double size, double alpha,
    double colour_intensity, int hide_front_faces, int hide_back_faces,
    int alpha_mode
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D554
*/

int SetAuraGradient(
    const char *entity_name, int gap, double r1, double g1, double b1,
    double alpha1, double starting_point, double r2, double g2, double b2,
    double alpha2, double ending_point
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D63D
*/

void GetMouseState(int *invert, double *xsens, double *ysens)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D677
*/

void SetMouseState(int invert, double xsens, double ysens)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D6B1
*/

double GetPSeconds()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D6D4
*/

void BodInspector()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D6DE
*/

void SaveScreeShoot(const char *filename, int width, int height)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D6FB
*/

void CleanArea(double x, double y, double z, float distance)
{
}
