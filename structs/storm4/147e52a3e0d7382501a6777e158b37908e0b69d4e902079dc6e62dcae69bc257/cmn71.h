/* cmn71 s4 — nuccView, nuccViewFrustumCulling, nuccWorkerThread, nuccXfbinData
 * Build: s4 (NSUNS4_release.exe-75912b, SHA 147e52a3e0d7)
 * All layouts INFERRED from decompiled pseudocode; not CONFIRMED at runtime.
 * Sizes proven from operator_new allocator calls in s4 code.
 */
#ifndef CMN71_S4_H
#define CMN71_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* MathGeo_Matrix44 — 4x4 float matrix, 0x40 bytes */
typedef struct __attribute__((packed)) {
    float m[4][4];
} ns4_MathGeo_Matrix44;
_Static_assert(sizeof(ns4_MathGeo_Matrix44) == 0x40, "MathGeo_Matrix44 size");

/* nuccCriticalSection — wraps Windows CRITICAL_SECTION, 0x28 bytes */
typedef struct __attribute__((packed)) {
    uint8_t cs[0x28];
} ns4_nuccCriticalSection;
_Static_assert(sizeof(ns4_nuccCriticalSection) == 0x28, "nuccCriticalSection size");

/* nuccViewFrustumCulling — embedded in nuccView at +0x200
 * Size: 0x48 (ctor zeroes 0x204..0x244 = 0x40 bytes of plane data;
 * first 4 bytes at 0x200-0x203 not zeroed by ctor).
 * Setup() writes uint indices 0..0x11 (18 uints = 0x48 bytes total from 0x200).
 */
typedef struct __attribute__((packed)) {
    uint32_t _flags_or_pad;       /* 0x00: not written by Setup; flags or padding */
    uint32_t planeData[0x11];     /* 0x04: 17 uints of plane index data (0x44 bytes) */
} ns4_nuccViewFrustumCulling;
_Static_assert(sizeof(ns4_nuccViewFrustumCulling) == 0x48, "nuccViewFrustumCulling size");

/* nuccView — non-virtual render view class
 * Size: 0x2D0 (proven by operator_new(0x2d0,...) in ccCmnScreen::ccCmnScreen @ RVA 0xABC150)
 * No vtable (non-virtual class).
 *
 * s4 offset changes vs s3:
 * - Frustum culling embedded at +0x200, size 0x48 (not 0x50 as in s3)
 * - fov at 0x248 (was 0x254 in s3)
 * - nearZ at 0x24C, farZ at 0x250 (shifted -0xC from s3)
 */
typedef struct __attribute__((packed)) {
    /* 0x000 - 0x1BF: eight 4x4 matrices (view/proj/combo transforms) */
    ns4_MathGeo_Matrix44 matrix0;           /* 0x000 */
    ns4_MathGeo_Matrix44 matrix1;           /* 0x040 */
    ns4_MathGeo_Matrix44 matrix2;           /* 0x080 */
    ns4_MathGeo_Matrix44 matrix3;           /* 0x0C0 */
    ns4_MathGeo_Matrix44 matrix4;           /* 0x100 */
    ns4_MathGeo_Matrix44 matrix5;           /* 0x140 */
    ns4_MathGeo_Matrix44 matrix6;           /* 0x180 */
    ns4_MathGeo_Matrix44 matrix7;           /* 0x1C0 */

    /* 0x200: embedded frustum culling sub-object (0x48 bytes) */
    ns4_nuccViewFrustumCulling frustumCulling; /* 0x200 */

    /* 0x248 - 0x28B: scalar fields set by ctor and SetFrame */
    float fov;                              /* 0x248: default 45.0f (0x42340000) */
    float nearZ;                            /* 0x24C: from global config DAT+0x5b0 */
    float farZ;                             /* 0x250: from global config DAT+0x5b4 */
    float _unk_254;                         /* 0x254: 1.0f in ctor (0x3f800000) */
    float halfWidth;                        /* 0x258: *(DAT+0x5c0)*0.5; recomputed in SetFrame */
    float halfHeight;                       /* 0x25C: *(DAT+0x5c4)*0.5; recomputed in SetFrame */
    float frameX;                           /* 0x260: zeroed in ctor; SetFrame writes param_2 */
    float frameY;                           /* 0x264: zeroed in ctor (qword zero covers 0x264+0x268) */
    float frameW;                           /* 0x268: from DAT+0x5c0; SetFrame writes param_4 */
    float frameH;                           /* 0x26C: from DAT+0x5c4; SetFrame writes param_5 */
    float minZ;                             /* 0x270: from DAT+0x5b8 */
    float maxZ;                             /* 0x274: from DAT+0x5bc */
    float _copy_frameW;                     /* 0x278: copy of frameW (SetFrame) */
    uint32_t _pad_27c;                      /* 0x27C: zeroed in ctor (qword zero at 0x27c) */
    float _copy_farZ;                       /* 0x280: copy of farZ? (ctor writes DAT+0x5c0) */
    float _copy_frameH;                     /* 0x284: copy of frameH (ctor writes DAT+0x5c4) */
    float _copy_frameX;                     /* 0x288: copy of frameX (SetFrame copies param_2) */

    /* 0x28C - 0x2CF: remaining bytes to reach 0x2D0 */
    uint8_t _tail[0x44];                    /* 0x28C */
} ns4_nuccView;

_Static_assert(sizeof(ns4_nuccView) == 0x2D0, "nuccView size");
_Static_assert(offsetof(ns4_nuccView, matrix0) == 0x000, "nuccView.matrix0");
_Static_assert(offsetof(ns4_nuccView, matrix1) == 0x040, "nuccView.matrix1");
_Static_assert(offsetof(ns4_nuccView, matrix2) == 0x080, "nuccView.matrix2");
_Static_assert(offsetof(ns4_nuccView, matrix3) == 0x0C0, "nuccView.matrix3");
_Static_assert(offsetof(ns4_nuccView, matrix4) == 0x100, "nuccView.matrix4");
_Static_assert(offsetof(ns4_nuccView, matrix5) == 0x140, "nuccView.matrix5");
_Static_assert(offsetof(ns4_nuccView, matrix6) == 0x180, "nuccView.matrix6");
_Static_assert(offsetof(ns4_nuccView, matrix7) == 0x1C0, "nuccView.matrix7");
_Static_assert(offsetof(ns4_nuccView, frustumCulling) == 0x200, "nuccView.frustumCulling");
_Static_assert(offsetof(ns4_nuccView, fov) == 0x248, "nuccView.fov");
_Static_assert(offsetof(ns4_nuccView, nearZ) == 0x24C, "nuccView.nearZ");
_Static_assert(offsetof(ns4_nuccView, farZ) == 0x250, "nuccView.farZ");
_Static_assert(offsetof(ns4_nuccView, _unk_254) == 0x254, "nuccView._unk_254");
_Static_assert(offsetof(ns4_nuccView, halfWidth) == 0x258, "nuccView.halfWidth");
_Static_assert(offsetof(ns4_nuccView, halfHeight) == 0x25C, "nuccView.halfHeight");
_Static_assert(offsetof(ns4_nuccView, frameX) == 0x260, "nuccView.frameX");
_Static_assert(offsetof(ns4_nuccView, frameY) == 0x264, "nuccView.frameY");
_Static_assert(offsetof(ns4_nuccView, frameW) == 0x268, "nuccView.frameW");
_Static_assert(offsetof(ns4_nuccView, frameH) == 0x26C, "nuccView.frameH");
_Static_assert(offsetof(ns4_nuccView, minZ) == 0x270, "nuccView.minZ");
_Static_assert(offsetof(ns4_nuccView, maxZ) == 0x274, "nuccView.maxZ");
_Static_assert(offsetof(ns4_nuccView, _copy_frameW) == 0x278, "nuccView._copy_frameW");
_Static_assert(offsetof(ns4_nuccView, _pad_27c) == 0x27C, "nuccView._pad_27c");
_Static_assert(offsetof(ns4_nuccView, _copy_farZ) == 0x280, "nuccView._copy_farZ");
_Static_assert(offsetof(ns4_nuccView, _copy_frameH) == 0x284, "nuccView._copy_frameH");
_Static_assert(offsetof(ns4_nuccView, _copy_frameX) == 0x288, "nuccView._copy_frameX");

/* nuccWorkerThread — inherits nuccThread (base 0x60), adds ownerPtr/busyFlag/priorityState
 * Size: 0x70 (proven by operator_new(0x70,...) in nuccChannel::Create @ RVA 0xA57760)
 * Vtable: PTR_FUN_141112390 (set in ctor @ RVA 0xAA1740)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 - 0x5F: nuccThread base (opaque here) */
    uint8_t threadBase[0x60];               /* 0x00 */
    /* 0x60: owner pointer (nuccChannel*), set from ctor param_2 */
    uint64_t ownerPtr;                      /* 0x60 */
    /* 0x68: busy flag (0=idle, 1=working), set in Exec */
    uint32_t busyFlag;                      /* 0x68 */
    /* 0x6C: priority state (2=idle default), read/written in Exec */
    uint32_t priorityState;                 /* 0x6C */
} ns4_nuccWorkerThread;

_Static_assert(sizeof(ns4_nuccWorkerThread) == 0x70, "nuccWorkerThread size");
_Static_assert(offsetof(ns4_nuccWorkerThread, threadBase) == 0x00, "nuccWorkerThread.threadBase");
_Static_assert(offsetof(ns4_nuccWorkerThread, ownerPtr) == 0x60, "nuccWorkerThread.ownerPtr");
_Static_assert(offsetof(ns4_nuccWorkerThread, busyFlag) == 0x68, "nuccWorkerThread.busyFlag");
_Static_assert(offsetof(ns4_nuccWorkerThread, priorityState) == 0x6C, "nuccWorkerThread.priorityState");

/* nuccXfbinData — xfbin document wrapper with critical section and load state
 * Size: 0x90 (proven by operator_new(0x90,...) in nuccXfbinDocManager::Regist @ RVA 0xA03B80)
 * Vtable: PTR_FUN_141107bb0 in ctor/i_Initialize, changes to PTR_FUN_1410075d8 in dtor
 */
typedef struct __attribute__((packed)) {
    /* 0x00: vtable pointer */
    uint64_t vtable;                        /* 0x00 */
    /* 0x08 - 0x17: BlockAllocator base fields */
    uint8_t blockAllocBase[0x10];           /* 0x08 */
    /* 0x18: critical section for thread-safe doc access */
    ns4_nuccCriticalSection critSection;    /* 0x18 */
    /* 0x40 - 0x67: gap (zeroed or unused in observed methods) */
    uint8_t _gap_40[0x28];                  /* 0x40 */
    /* 0x68: field zeroed in i_Initialize ([0xd]=0x68 relative to qword ptr) */
    uint64_t _field_68;                     /* 0x68 */
    /* 0x70: document pointer (nuccXfbinDocument*), freed in dtor, returned by GetDoc */
    uint64_t docPtr;                        /* 0x70 */
    /* 0x78: reference count or similar (incremented in Regist after ctor) */
    uint64_t _field_78;                     /* 0x78 */
    /* 0x80: unknown qword (zeroed in i_Initialize) */
    uint64_t _field_80;                     /* 0x80 */
    /* 0x88: load state (int), checked ==2 in GetDoc, set in SetDoc/SetloadState */
    uint32_t loadState;                     /* 0x88 */
    /* 0x8C: padding to 0x90 */
    uint32_t _pad_8c;                       /* 0x8C */
} ns4_nuccXfbinData;

_Static_assert(sizeof(ns4_nuccXfbinData) == 0x90, "nuccXfbinData size");
_Static_assert(offsetof(ns4_nuccXfbinData, vtable) == 0x00, "nuccXfbinData.vtable");
_Static_assert(offsetof(ns4_nuccXfbinData, blockAllocBase) == 0x08, "nuccXfbinData.blockAllocBase");
_Static_assert(offsetof(ns4_nuccXfbinData, critSection) == 0x18, "nuccXfbinData.critSection");
_Static_assert(offsetof(ns4_nuccXfbinData, _field_68) == 0x68, "nuccXfbinData._field_68");
_Static_assert(offsetof(ns4_nuccXfbinData, docPtr) == 0x70, "nuccXfbinData.docPtr");
_Static_assert(offsetof(ns4_nuccXfbinData, _field_78) == 0x78, "nuccXfbinData._field_78");
_Static_assert(offsetof(ns4_nuccXfbinData, _field_80) == 0x80, "nuccXfbinData._field_80");
_Static_assert(offsetof(ns4_nuccXfbinData, loadState) == 0x88, "nuccXfbinData.loadState");

#endif /* CMN71_S4_H */