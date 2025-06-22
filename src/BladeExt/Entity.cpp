#include <Entities/EntityFuncs.h>
#include "bladex_int.h"
#define PROP_TYPE_OBJ                           0
#define PROP_TYPE_INT                           1
#define PROP_TYPE_FLT                           2
#define PROP_TYPE_STR                           3
#define PROP_TYPE_VEC                           4
#define PROP_ONLY_GET                           1
#define PROP_ONLY_SET                           2
#define PROP_GET_AND_SET                        3


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A010
*/

PyObject *get_entity_by_name(const char *name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A076
*/

PyObject *get_entity_by_index(int index)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A0E6
*/

PyObject *create_entity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A179
*/

PyObject *create_entity_decal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A214
*/

PyObject *create_spark(
        const char *name, double x, double y, double z, double x_spark_dir,
        double y_spark_dir, double z_spark_dir, double d_unknown1,
        double d_unknown2, double d_unknown3, double d_unknown4,
        double d_unknown5, int i_unknown6, int i_unknown7, int i_unknown8,
        int i_unknown9, int i_unknown10, int i_unknown11, double d_unknown12,
        double d_unknown13, double d_unknown14, int i_unknown15
)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A349
*/

PyObject *bex_ent_SeverLimb(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A410
*/

PyObject *bex_ent_ResetWounds(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A45B
*/

PyObject *bex_ent_Impulse(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A4E8
*/

PyObject *bex_ent_ImpulseC(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A57F
*/

PyObject *bex_ent_Fly(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A60C
*/

PyObject *bex_ent_AddCameraEvent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A681
*/

PyObject *bex_ent_RemoveCameraEvent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A6EE
*/

PyObject *bex_ent_SubscribeToList(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A75B
*/

PyObject *bex_ent_MessageEvent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A7C2
*/

PyObject *bex_ent_Rel2AbsPoint(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000A95F
*/

PyObject *bex_ent_Rel2AbsVector(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000AB25
*/

PyObject *bex_ent_Abs2RelPoint(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000ACC2
*/

PyObject *bex_ent_Abs2RelVector(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000AF0C
*/

PyObject *bex_ent_GetDummyAxis(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B003
*/

PyObject *bex_ent_SQDistance2(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B069
*/

PyObject *bex_ent_RemoveFromList(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B0D6
*/

PyObject *bex_ent_RemoveFromInvent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B145
*/

PyObject *bex_ent_RemoveFromInventRight(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B1AA
*/

PyObject *bex_ent_RemoveFromInventLeft(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B20F
*/

PyObject *bex_ent_RemoveFromInventLeft2(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B274
*/

PyObject *bex_ent_LaunchAnimation(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B2E7
*/

PyObject *bex_ent_LaunchAnimation2(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B35E
*/

PyObject *bex_ent_LaunchAnmType(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B3DE
*/

PyObject *bex_ent_GotAnmType(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B451
*/

PyObject *bex_ent_SetMesh(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B4C4
*/

PyObject *bex_ent_SetTmpAnmFlags(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B56A
*/

PyObject *bex_ent_SetAnmFlags(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B609
*/

PyObject *bex_ent_SetActiveEnemy(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B6A0
*/

PyObject *bex_ent_CanISee(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B72B
*/

PyObject *bex_ent_CanISeeFrom(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B7DA
*/

PyObject *bex_ent_ExcludeHitFor(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B877
*/

PyObject *bex_ent_ExcludeHitInAnimationFor(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B914
*/

PyObject *bex_ent_Unlink(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000B9A6
*/

PyObject *bex_ent_Link(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BA38
*/

PyObject *bex_ent_LinkAnchors(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BAD4
*/

PyObject *bex_ent_LinkToNode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BB6E
*/

PyObject *bex_ent_GetNodeIndex(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BBD9
*/

PyObject *bex_ent_GetNChildren(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BC31
*/

PyObject *bex_ent_GetChild(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BC8A
*/

PyObject *bex_ent_InsideActionArea(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BCFF
*/

PyObject *bex_ent_CheckAnimCol(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BD9A
*/

PyObject *bex_ent_TestPos(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BED4
*/

PyObject *bex_ent_TestPosInOwnBox(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000BFFB
*/

PyObject *bex_ent_UnlinkChildren(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C067
*/

PyObject *bex_ent_SetNextAttack(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C0E3
*/

PyObject *bex_ent_SetEnemy(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C168
*/

PyObject *bex_ent_GetEnemyName(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C1C8
*/

PyObject *bex_ent_Chase(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C255
*/

PyObject *bex_ent_ResetChase(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C2BA
*/

PyObject *bex_ent_GoTo(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C339
*/

PyObject *bex_ent_CanGoTo(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C3B8
*/

PyObject *bex_ent_LookAtEntity(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C427
*/

PyObject *bex_ent_QuickFace(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C49A
*/

PyObject *bex_ent_Face(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C50D
*/

PyObject *bex_ent_StartLooking(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C58C
*/

PyObject *bex_ent_StopLooking(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C5F1
*/

PyObject *bex_ent_AddWatchAnim(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C660
*/

PyObject *bex_ent_GraspPos(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C785
*/

PyObject *bex_ent_Freeze(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C7EA
*/

PyObject *bex_ent_UnFreeze(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C84F
*/

PyObject *bex_ent_SwitchTo1H(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C8B4
*/

PyObject *bex_ent_SwitchToBow(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C919
*/

PyObject *bex_ent_LaunchBayRoute(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C97E
*/

PyObject *bex_ent_LaunchWatch(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000C9E3
*/

PyObject *bex_ent_GetActionMode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CA4E
*/

PyObject *bex_ent_StartGrabbing(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CAB3
*/

PyObject *bex_ent_StopGrabbing(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CB18
*/

PyObject *bex_ent_LookAt(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CBE2
*/

PyObject *bex_ent_LookAtPerson(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CC55
*/

PyObject *bex_ent_AddAnimSound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CD17
*/

PyObject *bex_ent_AddAnmEventFunc(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CDA3
*/

PyObject *bex_ent_DelAnmEventFunc(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CE26
*/

PyObject *bex_ent_ClearAnmEventFuncs(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CE8B
*/

PyObject *bex_ent_AddEventSound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CF41
*/

PyObject *bex_ent_SlideTo(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000CFCE
*/

PyObject *bex_ent_ClearPath(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D033
*/

PyObject *bex_ent_CameraClearPath(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D0A0
*/

PyObject *bex_ent_CameraStartPath(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D10D
*/

PyObject *bex_ent_AddPathNode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D1A2
*/

PyObject *bex_ent_StartPath(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D207
*/

PyObject *bex_ent_GoToPath(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D280
*/

PyObject *bex_ent_TurnOn(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D2E5
*/

PyObject *bex_ent_TurnOff(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D34A
*/

PyObject *bex_ent_SetNodeStartTangent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D3DB
*/

PyObject *bex_ent_SetNodeEndTangent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D46C
*/

PyObject *bex_ent_AddCameraNode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D5FA
*/

PyObject *bex_ent_SetCameraStartTangentNode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D769
*/

PyObject *bex_ent_SetCameraEndTangentNode(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D8D2
*/

PyObject *bex_ent_SetPersonView(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D93F
*/

PyObject *bex_ent_SetMaxCamera(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000D9BC
*/

PyObject *bex_ent_Cut(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DA21
*/

PyObject *bex_ent_SetTravellingView(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DA96
*/

PyObject *bex_ent_Rotate(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DB3A
*/

PyObject *bex_ent_RotateAbs(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DC02
*/

PyObject *bex_ent_RotateRel(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DCCA
*/

PyObject *bex_ent_Move(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DD62
*/

PyObject *bex_ent_SetPosition(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DDFA
*/

PyObject *bex_ent_SetOrientation(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DE9E
*/

PyObject *bex_ent_GetGroupMembers(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DEF6
*/

PyObject *bex_ent_GetCombatants(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DF4E
*/

PyObject *bex_ent_PutToWorld(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFB3
*/

PyObject *bex_ent_GetInventoryEntity(PyObject * self, PyObject * args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFD8
*/

PyObject *bex_ent_GetInventorySelected(PyObject * self, PyObject * args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000DFFD
*/

PyObject *bex_ent_GetInventory(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E081
*/

PyObject *bex_ent_RemoveFromWorld(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E0C9
*/

PyObject *bex_ent_RemoveFromWorldWithChilds(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E111
*/

PyObject *bex_ent_Use(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E17D
*/

PyObject *bex_ent_SetSound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E1EA
*/

PyObject *bex_ent_SetObjectSound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E257
*/

PyObject *bex_ent_PlaySound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E2CB
*/

PyObject *bex_ent_StopSound(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E385
*/

PyObject *bex_ent_CatchOnFire(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E40E
*/

PyObject *bex_ent_GetParticleEntity(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E49B
*/

PyObject *bex_ent_DoAction(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E4F2
*/

PyObject *bex_ent_DoActionWI(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E577
*/

PyObject *bex_ent_SetOnFloor(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E5C6
*/

PyObject *bex_ent_RaiseEvent(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E62B
*/

PyObject *bex_ent_SetWoundedZone(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E6A2
*/

PyObject *bex_ent_InterruptCombat(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E6ED
*/

PyObject *bex_ent_GetWoundedZone(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E798
*/

PyObject *bex_ent_SetAuraActive(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E805
*/

PyObject *bex_ent_SetAuraParams(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E8A6
*/

PyObject *bex_ent_SetAuraGradient(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E98E
*/

PyObject *bex_ent_IsValid(PyObject *self, PyObject *args)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000E9DD
*/

void init_entity_properties()
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010208
*/

PyObject *bex_ent_doc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001021B
*/

PyObject *bex_ent_Data_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010230
*/

PyObject *bex_ent_TimerFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010278
*/

PyObject *bex_ent_HitFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100102C0
*/

PyObject *bex_ent_InflictHitFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010308
*/

PyObject *bex_ent_HitShieldFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010350
*/

PyObject *bex_ent_DamageFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010398
*/

PyObject *bex_ent_StickFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100103E0
*/

PyObject *bex_ent_FrameFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010428
*/

PyObject *bex_ent_HearFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010470
*/

PyObject *bex_ent_SeeFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100104B8
*/

PyObject *bex_ent_UseFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010500
*/

PyObject *bex_ent_ChangeNodeFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010548
*/

PyObject *bex_ent_TouchFluidFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010590
*/

PyObject *bex_ent_EnterPrimaryAAFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100105D8
*/

PyObject *bex_ent_EnterSecondaryAAFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010620
*/

PyObject *bex_ent_EnterCloseFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010668
*/

PyObject *bex_ent_EnterLargeFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100106B0
*/

PyObject *bex_ent_AnmEndedFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100106F8
*/

PyObject *bex_ent_DelayNoSeenFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010740
*/

PyObject *bex_ent_RouteEndedFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010788
*/

PyObject *bex_ent_ImHurtFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100107D0
*/

PyObject *bex_ent_ImDeadFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010818
*/

PyObject *bex_ent_EnemyDeadFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010860
*/

PyObject *bex_ent_NoAllowedAreaFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100108A8
*/

PyObject *bex_ent_EnemyNoAllowedAreaFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100108F0
*/

PyObject *bex_ent_CharSeeingEnemyFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010938
*/

PyObject *bex_ent_AnmTranFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010980
*/

PyObject *bex_ent_NewComboFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100109C8
*/

PyObject *bex_ent_BigFallFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010A10
*/

PyObject *bex_ent_AttackFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010A58
*/

PyObject *bex_ent_ToggleCombatFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010AA0
*/

PyObject *bex_ent_TakeFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010AE8
*/

PyObject *bex_ent_ThrowFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010B30
*/

PyObject *bex_ent_MutilateFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010B78
*/

PyObject *bex_ent_AttackList_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010BD6
*/

PyObject *bex_ent_OnHitFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010C1E
*/

PyObject *bex_ent_OnStopFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010C66
*/

PyObject *bex_ent_OnStepFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010CAE
*/

PyObject *bex_ent_OnAnimationEndFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010CF6
*/

PyObject *bex_ent_OnPathNodeFunc_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010D3E
*/

PyObject *bex_ent_RAttackMin_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010D90
*/

PyObject *bex_ent_RAttackMax_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010DE2
*/

PyObject *bex_ent_ActionAreaMin_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010E34
*/

PyObject *bex_ent_ActionAreaMax_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010E86
*/

PyObject *bex_ent_Arrow_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010ED8
*/

PyObject *bex_ent_Static_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010F2A
*/

PyObject *bex_ent_Actor_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010F7C
*/

PyObject *bex_ent_Person_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10010FCE
*/

PyObject *bex_ent_Weapon_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011020
*/

PyObject *bex_ent_Orientation_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011122
*/

PyObject *bex_ent_SubscribedLists_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100111FC
*/

PyObject *bex_ent_FiresIntensity_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100112DB
*/

PyObject *bex_ent_LightIntensity_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100113BA
*/

PyObject *bex_ent_LightPrecission_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011499
*/

PyObject *bex_ent_LightColor_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100115FA
*/

PyObject *bex_ent_LightGlow_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100116D4
*/

int bex_ent_Static_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001174E
*/

int bex_ent_Actor_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100117C8
*/

int bex_ent_Person_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011842
*/

int bex_ent_Weapon_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100118BC
*/

int bex_ent_Arrow_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011936
*/

int bex_ent_Data_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100119B1
*/

int bex_ent_FiresIntensity_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011A7E
*/

int bex_ent_Lights_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011CED
*/

PyObject *bex_ent_Lights_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011F3B
*/

int bex_ent_RAttackMin_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10011FBE
*/

int bex_ent_RAttackMax_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012041
*/

int bex_ent_ActionAreaMin_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100120C4
*/

int bex_ent_ActionAreaMax_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012147
*/

int bex_ent_Orientation_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100121EE
*/

int bex_ent_TimerFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001226D
*/

int bex_ent_HitFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012304
*/

int bex_ent_InflictHitFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001239B
*/

int bex_ent_HitShieldFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001241A
*/

int bex_ent_DamageFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012499
*/

int bex_ent_StickFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012518
*/

int bex_ent_FrameFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012597
*/

int bex_ent_HearFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012616
*/

int bex_ent_SeeFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100126AD
*/

int bex_ent_UseFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001272C
*/

int bex_ent_ChangeNodeFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100127AB
*/

int bex_ent_TouchFluidFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001282A
*/

int bex_ent_EnterPrimaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100128A9
*/

int bex_ent_EnterSecondaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012928
*/

int bex_ent_EnterCloseFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100129A7
*/

int bex_ent_EnterLargeFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012A26
*/

int bex_ent_AnmEndedFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012ABD
*/

int bex_ent_DelayNoSeenFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012B3C
*/

int bex_ent_RouteEndedFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012BBB
*/

int bex_ent_ImHurtFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012C3A
*/

int bex_ent_ImDeadFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012CB9
*/

int bex_ent_EnemyDeadFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012D38
*/

int bex_ent_NoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012DB7
*/

int bex_ent_EnemyNoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012E36
*/

int bex_ent_CharSeeingEnemyFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012EB5
*/

int bex_ent_AnmTranFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012F34
*/

int bex_ent_NewComboFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10012FB3
*/

int bex_ent_BigFallFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013032
*/

int bex_ent_AttackFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100130B1
*/

int bex_ent_ToggleCombatFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013130
*/

int bex_ent_TakeFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100131AF
*/

int bex_ent_ThrowFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001322E
*/

int bex_ent_MutilateFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100132C5
*/

int bex_ent_AttackList_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013340
*/

int bex_ent_OnHitFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100133BF
*/

int bex_ent_OnStopFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001343E
*/

int bex_ent_OnStepFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100134BD
*/

int bex_ent_OnAnimationEndFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013554
*/

int bex_ent_OnPathNodeFunc_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100135D3
*/

int bex_ent_InternalState_set(PyObject *self, char *attr_name, PyObject *value)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001364E
*/

PyObject *bex_ent_InternalState_get(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100136BC
*/

void init_entity()
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100136C6
*/

void init_entity_type()
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013771
*/

void bld_py_entity_dealloc(PyObject *self)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013793
*/

int bld_py_entity_print(PyObject *self, FILE *file, int flags)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100137FE
*/

PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name)
{
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10013C54
*/

int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value)
{
}
