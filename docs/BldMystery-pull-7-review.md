# Review of BldMystery pull request 7

Pull request: [smartblade/BldMystery#7](https://github.com/smartblade/BldMystery/pull/7)
("Fix B_World class fields and offsets"), reviewed at commit `ee43e85`.

The procedures implemented in the pull request were converted by
BldRecompile (see `recompile/Blade.exe.cpp`). The issues below were found
while doing it. Each one comes with a suggested patch against `ee43e85`.

## 1. `~B_OctantNodeBase` is attributed to the scalar deleting destructor

`src/BWorld/OctTree.cpp` marks `0x00453AC0` as
`B_OctantNodeBase::~B_OctantNodeBase()` (`??1B_OctantNodeBase@@UAE@XZ`).
The code at this address is the compiler-generated scalar deleting
destructor of `B_OctantNodeBase`, not the destructor itself:

- it is the second entry of the `B_OctantNodeBase` vtable `g005BDD0C`,
  the slot of the virtual destructor;
- it takes the delete flag from `[ebp+8]`, calls `operator delete`
  (`l005BBD3D`) when bit 0 is set and returns with `ret 4`;
- the destructor body (`vtable = g005BDD0C; gbl_node_count--;`) is inlined
  into it, the destructor has no address of its own.

```asm
l00453AC0 PROC
           push ebp
           mov ebp, esp
           push ecx
           mov dword ptr [ebp-004h], ecx
           mov eax, dword ptr [ebp-004h]
           mov dword ptr [eax], offset g005BDD0C
           mov ecx, dword ptr [g005E338C]
           sub ecx, 000000001h
           mov dword ptr [g005E338C], ecx
           mov edx, dword ptr [ebp+008h]
           and edx, 000000001h
           test edx, edx
           je l00453AF5
           mov eax, dword ptr [ebp-004h]
           push eax
           call l005BBD3D
           add esp, 000000004h
l00453AF5: mov eax, dword ptr [ebp-004h]
           mov esp, ebp
           pop ebp
           ret 00004h
l00453AC0 ENDP
```

In the native build this is a bug: `procedures.inc` maps
`l00453AC0` to `??1B_OctantNodeBase@@UAE@XZ`, and the vtable still points
to `l00453AC0`. Deleting an octree node through a base class pointer
passes the delete flag, but the C++ destructor returns without popping it
(`ret` instead of `ret 4`) and never calls `operator delete`.

Suggested fix: remove the address from the destructor and regenerate
`native.asm`, so that the original code of `0x00453AC0` comes back.

```diff
--- a/src/BWorld/OctTree.cpp
+++ b/src/BWorld/OctTree.cpp
@@ -804,12 +804,6 @@ B_SectorSurfaceCache::~B_SectorSurfaceCache()
 */
 
 
-/*
-* Module:                 Blade.exe
-* Entry point:            0x00453AC0
-* VC++ mangling:          ??1B_OctantNodeBase@@UAE@XZ
-*/
-
 B_OctantNodeBase::~B_OctantNodeBase()
 {
     gbl_node_count--;
```

## 2. `B_BoundingBox::Intersects` returns `unsigned int`, not `bool`

`Intersects` (`0x0044F052`) is declared as returning `bool`, but it sets
the whole `eax` to 1 or 0, and its caller
`B_BoundingBox::CollectIntersectingSectors` tests the whole `eax`:

```asm
; end of B_BoundingBox::Intersects
           call l0044EDA9
           test eax, eax
           je l004501B7
           mov eax, 000000001h
           jmp l004501B9
l004501B7: xor eax, eax
l004501B9: pop edi
           pop esi
           mov esp, ebp
           pop ebp
           ret 00004h

; B_BoundingBox::CollectIntersectingSectors
           mov ecx, dword ptr [ebp-008h]
           push ecx
           mov ecx, dword ptr [ebp-024h]
           call l0044F052
           test eax, eax
           je l0045031B
```

A `bool` result would be returned and tested in `al` only. Suggested fix:
return `unsigned int` and update the mangled name (`_N` → `I`) in the
source and in `procedures.inc`.

```diff
--- a/src/AnalyticGeometry/BoundingBox.cpp
+++ b/src/AnalyticGeometry/BoundingBox.cpp
@@ -48,11 +48,11 @@ B_BoundingBox::B_BoundingBox(const B_Vector& minCoords, const B_Vector& maxCoord
 /*
 * Module:                 Blade.exe
 * Entry point:            0x0044F052
-* VC++ mangling:          ?Intersects@B_BoundingBox@@QBE_NPBVB_Sector@@@Z
+* VC++ mangling:          ?Intersects@B_BoundingBox@@QBEIPBVB_Sector@@@Z
 */
 
 #ifndef BLD_NATIVE
-bool B_BoundingBox::Intersects(const B_Sector* sector) const
+unsigned int B_BoundingBox::Intersects(const B_Sector* sector) const
 {
     return false;
 }
--- a/src/AnalyticGeometry/BoundingBox.h
+++ b/src/AnalyticGeometry/BoundingBox.h
@@ -24,7 +24,7 @@ public:
 
     void CollectIntersectingSectors(const B_PtrArray<B_Sector>&, B_PtrArray<B_Sector>&);
 
-    bool Intersects(const B_Sector* sector) const;
+    unsigned int Intersects(const B_Sector* sector) const;
 
     B_Vector minCoords;
     B_Vector maxCoords;
--- a/src/Blade/asm/procedures.inc
+++ b/src/Blade/asm/procedures.inc
@@ -660,8 +660,8 @@ externdef _GetMaterialFloatProperty: near
 l0044ED29 equ _GetMaterialFloatProperty
 externdef _AddHitSoundComb: near
 l0044ED6A equ _AddHitSoundComb
-externdef ?Intersects@B_BoundingBox@@QBE_NPBVB_Sector@@@Z: near
-l0044F052 equ ?Intersects@B_BoundingBox@@QBE_NPBVB_Sector@@@Z
+externdef ?Intersects@B_BoundingBox@@QBEIPBVB_Sector@@@Z: near
+l0044F052 equ ?Intersects@B_BoundingBox@@QBEIPBVB_Sector@@@Z
 externdef ?CollectIntersectingSectors@B_BoundingBox@@QAEXABV?$B_PtrArray@VB_Sector@@@@AAV2@@Z: near
 l004501C1 equ ?CollectIntersectingSectors@B_BoundingBox@@QAEXABV?$B_PtrArray@VB_Sector@@@@AAV2@@Z
 externdef ??0B_OctantNode@@QAE@XZ: near
```

## 3. Address of the `B_OctTreeSectorsList` constructor in `OctTree.h`

The address `0x00453264` of `B_OctTreeSectorsList::B_OctTreeSectorsList()`
is given twice: in `OctTree.cpp` above the definition and in `OctTree.h`
above the declaration inside the class. Address comments are expected
above definitions: the comment in the header is followed by a declaration
without a body, so the symbols collector takes everything up to the next
`{` (the rest of `B_OctTreeSectorsList` and the beginning of
`B_OctantNodeBase`) as the definition and assigns the constructor to
`B_OctantNodeBase`. Suggested fix: keep the address in `OctTree.cpp` only.

```diff
--- a/src/BWorld/OctTree.h
+++ b/src/BWorld/OctTree.h
@@ -41,11 +41,6 @@ public:
 class B_OctTreeSectorsList
 {
 public:
-    /*
-    * Module:                 Blade.exe
-    * Entry point:            0x00453264
-    * VC++ mangling:          ??0B_OctTreeSectorsList@@QAE@XZ
-    */
     B_OctTreeSectorsList();
 
     int BuildSurfaceCache(B_GlobalSurfaceCache* cache, const B_Sphere* sphere);
```

## 4. Typo in the mangling of `~B_Sector`

`src/BWorld/BMAP.CPP` has `VC++ man gling` instead of `VC++ mangling`
above `B_Sector::~B_Sector()` (`0x0042E26F`):

```cpp
/*
* Module:                 Blade.exe
* Entry point:            0x0042E26F
* VC++ man gling:          ??1B_Sector@@UAE@XZ
*/
```

Because of it the mangled name is not recognized and
`src/Blade/asm/procedures.inc` gets a name made from the procedure name
instead of `??1B_Sector@@UAE@XZ`:

```asm
externdef _B_Sector: near
l0042E26F equ _B_Sector
```

Suggested fix: correct the comment and regenerate `procedures.inc`.

```diff
--- a/src/BWorld/BMAP.CPP
+++ b/src/BWorld/BMAP.CPP
@@ -49,7 +49,7 @@
 /*
 * Module:                 Blade.exe
 * Entry point:            0x0042E26F
-* VC++ man gling:          ??1B_Sector@@UAE@XZ
+* VC++ mangling:          ??1B_Sector@@UAE@XZ
 */
 #ifndef BLD_NATIVE
 B_Sector::~B_Sector()
```
