/* cmn71.h — struct group cmn71 for build s2 (NSUNS2.exe-abf2b6)
 * INFERRED from static decompilation; not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */
#ifndef CMN71_H
#define CMN71_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* MathGeo Matrix44: 4x4 float matrix, 0x40 bytes */
typedef struct {
    float m[4][4];
} __attribute__((packed)) MathGeo_Matrix44;
static_assert(sizeof(MathGeo_Matrix44) == 0x40, "MathGeo_Matrix44 must be 0x40");

/* nuccCriticalSection: opaque, 0x28 bytes (standard Windows CRITICAL_SECTION wrapper) */
typedef struct {
    uint8_t data[0x28];
} __attribute__((packed)) nuccCriticalSection;
static_assert(sizeof(nuccCriticalSection) == 0x28, "nuccCriticalSection must be 0x28");

/* =========================================================================
 * nuccView — size 0x2D0 (720 bytes)
 * Evidence: ccFileLoadListForUi::LoadTh(0x2d0,"..\\source\\nuccSys_Win64.cpp",0x584)
 * in FUN_140582790 (nuccSys::Initialize region)
 * Vtable: NONE (non-virtual class in s2; ctor at RVA 0x59B810 sets no vtable ptr)
 * ========================================================================= */
typedef struct {
    /* 0x000 */ MathGeo_Matrix44 matrix0;           /* identity when param_2!=0 in ctor */
    /* 0x040 */ MathGeo_Matrix44 matrix1;
    /* 0x080 */ MathGeo_Matrix44 matrix2;
    /* 0x0C0 */ MathGeo_Matrix44 matrix3;
    /* 0x100 */ MathGeo_Matrix44 projectionMatrix;  /* SetView/UpdateViewMatrix/GetFovPlanes reads here */
    /* 0x140 */ MathGeo_Matrix44 viewMatrix;         /* SetView copies camera matrix here; WorldToScreen reads */
    /* 0x180 */ MathGeo_Matrix44 matrix6;
    /* 0x1C0 */ MathGeo_Matrix44 matrix7;
    /* 0x200 */ uint32_t field_200;                  /* zeroed in ctor (via 8-byte write at 0x204 covers 0x200-0x207) */
    /* 0x204 */ uint32_t pad_204;                    /* part of 8-byte zero at 0x204 */
    /* 0x208 */ uint64_t field_208;                  /* zeroed via *(param_1+0x20c)=0 covering 0x208-0x20f */
    /* 0x210 */ uint32_t field_210;                  /* zeroed in ctor */
    /* 0x214 */ uint32_t pad_214;                    /* zeroed via *(param_1+0x214)=0 */
    /* 0x218 */ uint64_t field_218;                  /* zeroed in ctor */
    /* 0x220 */ uint32_t field_220;                  /* zeroed in ctor */
    /* 0x224 */ uint32_t pad_224;                    /* zeroed via *(param_1+0x224)=0 */
    /* 0x228 */ uint64_t field_228;                  /* zeroed in ctor */
    /* 0x230 */ uint32_t field_230;                  /* zeroed in ctor */
    /* 0x234 */ uint32_t pad_234;                    /* zeroed via *(param_1+0x238)=0 covering 0x234-0x23b? Actually 0x230 then 0x238 */
    /* 0x238 */ uint64_t field_238;                  /* zeroed in ctor */
    /* 0x240 */ uint32_t field_240;                  /* zeroed in ctor */
    /* 0x244 */ uint32_t pad_244;                    /* zeroed via *(param_1+0x244)=0 */
    /* 0x248 */ float fov;                           /* 45.0f default (0x42340000); SetProjectionOrtho writes 45.0f */
    /* 0x24C */ float nearZ;                         /* from global DAT_140a5ce88+0x5c0 in ctor */
    /* 0x250 */ float farZ;                          /* from global DAT_140a5ce88+0x5c4 in ctor */
    /* 0x254 */ float field_254;                     /* 1.0f default (0x3f800000) */
    /* 0x258 */ float field_258;                     /* not explicitly set in ctor visible portion; likely 1.0f or computed */
    /* 0x25C */ float halfWidth;                     /* computed in ctor: global*0.5; read by SetProjectionOrtho */
    /* 0x260 */ float halfHeight;                    /* computed in ctor: global*0.5; read by SetProjectionOrtho */
    /* 0x264 */ float frameX;                        /* SetFrame/SetViewport/WorldToScreen reads/writes */
    /* 0x268 */ float frameY;                        /* SetFrame/SetViewport/WorldToScreen reads/writes */
    /* 0x26C */ float frameW;                        /* SetFrame/SetViewport/WorldToScreen reads/writes */
    /* 0x270 */ float frameH;                        /* SetFrame/SetViewport/WorldToScreen reads/writes */
    /* 0x274 */ int32_t minZ;                        /* from global in ctor; SetViewport/WorldToScreen reads */
    /* 0x278 */ int32_t maxZ;                        /* from global in ctor; SetViewport/WorldToScreen reads */
    /* 0x27C */ float field_27C;                     /* copy of frameX in SetFrame; zeroed in ctor */
    /* 0x280 */ float field_280;                     /* copy of frameY in SetFrame */
    /* 0x284 */ float field_284;                     /* copy of frameH in SetFrame; from global in ctor */
    /* 0x288 */ float field_288;                     /* param_5/frameW copy in SetFrame; from global in ctor */
    /* 0x28C */ uint8_t pad_28C[0x2D0 - 0x28C];     /* padding to proven size */
} __attribute__((packed)) nuccView;

static_assert(offsetof(nuccView, matrix0) == 0x000, "nuccView.matrix0");
static_assert(offsetof(nuccView, matrix1) == 0x040, "nuccView.matrix1");
static_assert(offsetof(nuccView, matrix2) == 0x080, "nuccView.matrix2");
static_assert(offsetof(nuccView, matrix3) == 0x0C0, "nuccView.matrix3");
static_assert(offsetof(nuccView, projectionMatrix) == 0x100, "nuccView.projectionMatrix");
static_assert(offsetof(nuccView, viewMatrix) == 0x140, "nuccView.viewMatrix");
static_assert(offsetof(nuccView, matrix6) == 0x180, "nuccView.matrix6");
static_assert(offsetof(nuccView, matrix7) == 0x1C0, "nuccView.matrix7");
static_assert(offsetof(nuccView, field_200) == 0x200, "nuccView.field_200");
static_assert(offsetof(nuccView, field_208) == 0x208, "nuccView.field_208");
static_assert(offsetof(nuccView, field_210) == 0x210, "nuccView.field_210");
static_assert(offsetof(nuccView, field_218) == 0x218, "nuccView.field_218");
static_assert(offsetof(nuccView, field_220) == 0x220, "nuccView.field_220");
static_assert(offsetof(nuccView, field_228) == 0x228, "nuccView.field_228");
static_assert(offsetof(nuccView, field_230) == 0x230, "nuccView.field_230");
static_assert(offsetof(nuccView, field_238) == 0x238, "nuccView.field_238");
static_assert(offsetof(nuccView, field_240) == 0x240, "nuccView.field_240");
static_assert(offsetof(nuccView, fov) == 0x248, "nuccView.fov");
static_assert(offsetof(nuccView, nearZ) == 0x24C, "nuccView.nearZ");
static_assert(offsetof(nuccView, farZ) == 0x250, "nuccView.farZ");
static_assert(offsetof(nuccView, field_254) == 0x254, "nuccView.field_254");
static_assert(offsetof(nuccView, field_258) == 0x258, "nuccView.field_258");
static_assert(offsetof(nuccView, halfWidth) == 0x25C, "nuccView.halfWidth");
static_assert(offsetof(nuccView, halfHeight) == 0x260, "nuccView.halfHeight");
static_assert(offsetof(nuccView, frameX) == 0x264, "nuccView.frameX");
static_assert(offsetof(nuccView, frameY) == 0x268, "nuccView.frameY");
static_assert(offsetof(nuccView, frameW) == 0x26C, "nuccView.frameW");
static_assert(offsetof(nuccView, frameH) == 0x270, "nuccView.frameH");
static_assert(offsetof(nuccView, minZ) == 0x274, "nuccView.minZ");
static_assert(offsetof(nuccView, maxZ) == 0x278, "nuccView.maxZ");
static_assert(offsetof(nuccView, field_27C) == 0x27C, "nuccView.field_27C");
static_assert(offsetof(nuccView, field_280) == 0x280, "nuccView.field_280");
static_assert(offsetof(nuccView, field_284) == 0x284, "nuccView.field_284");
static_assert(offsetof(nuccView, field_288) == 0x288, "nuccView.field_288");
static_assert(sizeof(nuccView) == 0x2D0, "nuccView size");

/* =========================================================================
 * nuccWorkerThread — size 0x70 (112 bytes)
 * Evidence: ccFileLoadListForUi::LoadTh(0x70,"..\\source\\std\\nuccChannel.cpp")
 * in FUN_1405f9350
 * Vtable: PTR_FUN_14089c6f0 (set in ctor at RVA 0x6230E0)
 * Inherits nuccThread (base occupies 0x00-0x5F)
 * ========================================================================= */
typedef struct {
    /* 0x00 */ uint8_t base_nuccThread[0x60];   /* nuccThread base class */
    /* 0x60 */ uint64_t ownerPtr;               /* param_1[0xc] in ctor (=0x60); Exec reads */
    /* 0x68 */ uint32_t busyFlag;               /* *(param_1+0xd)=0 in ctor (=0x68); Exec sets 1/0 */
    /* 0x6C */ uint32_t priorityState;          /* =2 in ctor; Exec reads/writes */
} __attribute__((packed)) nuccWorkerThread;

static_assert(offsetof(nuccWorkerThread, base_nuccThread) == 0x00, "nuccWorkerThread.base_nuccThread");
static_assert(offsetof(nuccWorkerThread, ownerPtr) == 0x60, "nuccWorkerThread.ownerPtr");
static_assert(offsetof(nuccWorkerThread, busyFlag) == 0x68, "nuccWorkerThread.busyFlag");
static_assert(offsetof(nuccWorkerThread, priorityState) == 0x6C, "nuccWorkerThread.priorityState");
static_assert(sizeof(nuccWorkerThread) == 0x70, "nuccWorkerThread size");

/* =========================================================================
 * nuccXfbinData — size 0x90 (144 bytes)
 * Evidence: ccFileLoadListForUi::LoadTh(0x90,"..\\source\\render\\nuccXfbinDocManager.cpp",0x27c)
 * in FUN_140593f60
 * Vtable: PTR_FUN_1408984e8 (set in ctor at RVA 0x5F88C0)
 * NOTE: nuccXfbinData::UnloadRequest (0x58FDB0) accesses offsets beyond 0x90;
 *       this is likely a symbol mapping issue (operates on a containing object).
 *       The base nuccXfbinData layout below is bounded at 0x90 per allocator proof.
 * ========================================================================= */
typedef struct {
    /* 0x00 */ uint64_t vtablePtr;              /* PTR_FUN_1408984e8 */
    /* 0x08 */ uint8_t pad_08[0x10];            /* gap before critical section */
    /* 0x18 */ nuccCriticalSection critSection; /* Lock/Unlock in GetDoc/SetDoc/SetloadState/GetloadState */
    /* 0x40 */ uint8_t pad_40[0x28];            /* gap between critSection and doc fields */
    /* 0x68 */ uint64_t field_68;               /* zeroed in ctor */
    /* 0x70 */ uint64_t docPtr;                 /* GetDoc returns; SetDoc sets; dtor frees */
    /* 0x78 */ uint64_t field_78;               /* incremented in Regist post-ctor; possible refcount */
    /* 0x80 */ uint64_t field_80;               /* zeroed in ctor */
    /* 0x88 */ uint32_t loadState;              /* GetloadState/SetloadState; 2=loaded (checked in GetDoc) */
    /* 0x8C */ uint32_t pad_8C;                 /* padding to 0x90 */
} __attribute__((packed)) nuccXfbinData;

static_assert(offsetof(nuccXfbinData, vtablePtr) == 0x00, "nuccXfbinData.vtablePtr");
static_assert(offsetof(nuccXfbinData, critSection) == 0x18, "nuccXfbinData.critSection");
static_assert(offsetof(nuccXfbinData, field_68) == 0x68, "nuccXfbinData.field_68");
static_assert(offsetof(nuccXfbinData, docPtr) == 0x70, "nuccXfbinData.docPtr");
static_assert(offsetof(nuccXfbinData, field_78) == 0x78, "nuccXfbinData.field_78");
static_assert(offsetof(nuccXfbinData, field_80) == 0x80, "nuccXfbinData.field_80");
static_assert(offsetof(nuccXfbinData, loadState) == 0x88, "nuccXfbinData.loadState");
static_assert(sizeof(nuccXfbinData) == 0x90, "nuccXfbinData size");

#endif /* CMN71_H */