/* cmn71 s3 — nuccView, nuccViewFrustumCulling, nuccWorkerThread, nuccXfbinData
 * Build: s3 (NSUNS3.exe-a7124b, SHA 55b726e94dad)
 * All layouts INFERRED from decompiled pseudocode; not CONFIRMED at runtime.
 * Sizes proven from ccFileLoadListForUi::LoadTh allocator calls in s3 code.
 */
#ifndef CMN71_S3_H
#define CMN71_S3_H

#include <stdint.h>
#include <stddef.h>

/* MathGeo_Matrix44 — 4x4 float matrix, 0x40 bytes */
typedef struct __attribute__((packed)) {
    float m[4][4];
} ns3_MathGeo_Matrix44;
_Static_assert(sizeof(ns3_MathGeo_Matrix44) == 0x40, "MathGeo_Matrix44 size");

/* nuccCriticalSection — wraps Windows CRITICAL_SECTION, 0x28 bytes */
typedef struct __attribute__((packed)) {
    uint8_t cs[0x28];
} ns3_nuccCriticalSection;
_Static_assert(sizeof(ns3_nuccCriticalSection) == 0x28, "nuccCriticalSection size");

/* nuccViewFrustumCulling — embedded in nuccView at +0x200
 * Size: 0x50 (proven by nuccView total 0x2D0 minus fields after frustum)
 * Fields are a uint array of frustum plane data written by Setup().
 */
typedef struct __attribute__((packed)) {
    uint32_t planeData[0x14]; /* indices 0..0x11 used in Setup, rest padding to 0x50 */
} ns3_nuccViewFrustumCulling;
_Static_assert(sizeof(ns3_nuccViewFrustumCulling) == 0x50, "nuccViewFrustumCulling size");

/* nuccView — non-virtual render view class
 * Size: 0x2D0 (proven by ccFileLoadListForUi::LoadTh(0x2d0,...) in ccCmnScreen::ccCmnScreen @ 0x799490)
 * No vtable (non-virtual class).
 */
typedef struct __attribute__((packed)) {
    /* 0x000 - 0x1BF: eight 4x4 matrices (view/proj/combo transforms) */
    ns3_MathGeo_Matrix44 matrix0;           /* 0x000 */
    ns3_MathGeo_Matrix44 matrix1;           /* 0x040 */
    ns3_MathGeo_Matrix44 matrix2;           /* 0x080 */
    ns3_MathGeo_Matrix44 matrix3;           /* 0x0C0 */
    ns3_MathGeo_Matrix44 matrix4;           /* 0x100 */
    ns3_MathGeo_Matrix44 matrix5;           /* 0x140 */
    ns3_MathGeo_Matrix44 matrix6;           /* 0x180 */
    ns3_MathGeo_Matrix44 matrix7;           /* 0x1C0 */
    /* 0x200: embedded frustum culling sub-object */
    ns3_nuccViewFrustumCulling frustumCulling; /* 0x200 */
    /* 0x250 - 0x28B: scalar fields set by ctor and SetFrame */
    uint32_t _pad_250;                      /* 0x250: zeroed in ctor */
    float fov;                              /* 0x254: default 45.0f */
    float nearZ;                            /* 0x258 */
    float farZ;                             /* 0x25C */
    float _unk_260;                         /* 0x260: 1.0f in ctor */
    float _unk_264;                         /* 0x264: 1.0f in ctor */
    float halfWidth;                        /* 0x268: recomputed in SetFrame */
    float halfHeight;                       /* 0x26C: recomputed in SetFrame */
    float frameX;                           /* 0x270 */
    float frameY;                           /* 0x274 */
    float frameW;                           /* 0x278 */
    float frameH;                           /* 0x27C */
    float minZ;                             /* 0x280 */
    float maxZ;                             /* 0x284 */
    float _copy_frameX;                     /* 0x288: copy of frameX (SetFrame) */
    float _copy_frameY;                     /* 0x28C: copy of frameY (SetFrame) */
    float _copy_frameH;                     /* 0x290: copy of frameH (SetFrame) */
    float _copy_frameW;                     /* 0x294: copy of frameW (SetFrame) */
    /* 0x298 - 0x2CF: remaining bytes (zeroed/padding to reach 0x2D0) */
    uint8_t _tail[0x38];                   /* 0x298 */
} ns3_nuccView;
_Static_assert(sizeof(ns3_nuccView) == 0x2D0, "nuccView size");
_Static_assert(offsetof(ns3_nuccView, matrix0) == 0x000, "nuccView.matrix0");
_Static_assert(offsetof(ns3_nuccView, matrix1) == 0x040, "nuccView.matrix1");
_Static_assert(offsetof(ns3_nuccView, matrix2) == 0x080, "nuccView.matrix2");
_Static_assert(offsetof(ns3_nuccView, matrix3) == 0x0C0, "nuccView.matrix3");
_Static_assert(offsetof(ns3_nuccView, matrix4) == 0x100, "nuccView.matrix4");
_Static_assert(offsetof(ns3_nuccView, matrix5) == 0x140, "nuccView.matrix5");
_Static_assert(offsetof(ns3_nuccView, matrix6) == 0x180, "nuccView.matrix6");
_Static_assert(offsetof(ns3_nuccView, matrix7) == 0x1C0, "nuccView.matrix7");
_Static_assert(offsetof(ns3_nuccView, frustumCulling) == 0x200, "nuccView.frustumCulling");
_Static_assert(offsetof(ns3_nuccView, fov) == 0x254, "nuccView.fov");
_Static_assert(offsetof(ns3_nuccView, nearZ) == 0x258, "nuccView.nearZ");
_Static_assert(offsetof(ns3_nuccView, farZ) == 0x25C, "nuccView.farZ");
_Static_assert(offsetof(ns3_nuccView, halfWidth) == 0x268, "nuccView.halfWidth");
_Static_assert(offsetof(ns3_nuccView, halfHeight) == 0x26C, "nuccView.halfHeight");
_Static_assert(offsetof(ns3_nuccView, frameX) == 0x270, "nuccView.frameX");
_Static_assert(offsetof(ns3_nuccView, frameY) == 0x274, "nuccView.frameY");
_Static_assert(offsetof(ns3_nuccView, frameW) == 0x278, "nuccView.frameW");
_Static_assert(offsetof(ns3_nuccView, frameH) == 0x27C, "nuccView.frameH");
_Static_assert(offsetof(ns3_nuccView, minZ) == 0x280, "nuccView.minZ");
_Static_assert(offsetof(ns3_nuccView, maxZ) == 0x284, "nuccView.maxZ");

/* nuccWorkerThread — inherits nuccThread (base 0x60), adds ownerPtr/busyFlag/priorityState
 * Size: 0x70 (proven by ccFileLoadListForUi::LoadTh(0x70,...) in nuccChannel::Create @ 0x6DA110)
 * Vtable: PTR_FUN_1409e9b98 (set in ctor @ 0x724270)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 - 0x5F: nuccThread base (opaque here) */
    uint8_t threadBase[0x60];              /* 0x00 */
    /* 0x60: owner pointer (nuccChannel*), set from ctor param_1[0xc] */
    uint64_t ownerPtr;                     /* 0x60 */
    /* 0x68: busy flag (0=idle, 1=working), set in Exec */
    uint32_t busyFlag;                     /* 0x68 */
    /* 0x6C: priority state (2=idle default), read/written in Exec */
    uint32_t priorityState;                /* 0x6C */
} ns3_nuccWorkerThread;
_Static_assert(sizeof(ns3_nuccWorkerThread) == 0x70, "nuccWorkerThread size");
_Static_assert(offsetof(ns3_nuccWorkerThread, threadBase) == 0x00, "nuccWorkerThread.threadBase");
_Static_assert(offsetof(ns3_nuccWorkerThread, ownerPtr) == 0x60, "nuccWorkerThread.ownerPtr");
_Static_assert(offsetof(ns3_nuccWorkerThread, busyFlag) == 0x68, "nuccWorkerThread.busyFlag");
_Static_assert(offsetof(ns3_nuccWorkerThread, priorityState) == 0x6C, "nuccWorkerThread.priorityState");

/* nuccXfbinData — xfbin document wrapper with critical section and load state
 * Size: 0x90 (proven by ccFileLoadListForUi::LoadTh(0x90,...) in nuccXfbinDocManager::Regist @ 0x693770)
 * Vtable: PTR_FUN_1409e04a0 in ctor, changes to PTR_FUN_1409ec308 in dtor
 */
typedef struct __attribute__((packed)) {
    /* 0x00: vtable pointer */
    uint64_t vtable;                       /* 0x00 */
    /* 0x08 - 0x17: BlockAllocator base fields */
    uint8_t blockAllocBase[0x10];          /* 0x08 */
    /* 0x18: critical section for thread-safe doc access */
    ns3_nuccCriticalSection critSection;   /* 0x18 */
    /* 0x40 - 0x67: gap (zeroed or unused in observed methods) */
    uint8_t _gap_40[0x28];                 /* 0x40 */
    /* 0x68: field zeroed in ctor ([0xd]=0x68 relative to qword ptr) */
    uint64_t _field_68;                    /* 0x68 */
    /* 0x70: document pointer (nuccXfbinDocument*), freed in dtor, returned by GetDoc */
    uint64_t docPtr;                       /* 0x70 */
    /* 0x78: reference count or similar (incremented in Regist after ctor) */
    uint64_t _field_78;                    /* 0x78 */
    /* 0x80: unknown qword (zeroed in ctor) */
    uint64_t _field_80;                    /* 0x80 */
    /* 0x88: load state (int), checked ==2 in GetDoc, set in SetDoc/SetloadState */
    uint32_t loadState;                    /* 0x88 */
    /* 0x8C: padding to 0x90 */
    uint32_t _pad_8c;                      /* 0x8C */
} ns3_nuccXfbinData;
_Static_assert(sizeof(ns3_nuccXfbinData) == 0x90, "nuccXfbinData size");
_Static_assert(offsetof(ns3_nuccXfbinData, vtable) == 0x00, "nuccXfbinData.vtable");
_Static_assert(offsetof(ns3_nuccXfbinData, blockAllocBase) == 0x08, "nuccXfbinData.blockAllocBase");
_Static_assert(offsetof(ns3_nuccXfbinData, critSection) == 0x18, "nuccXfbinData.critSection");
_Static_assert(offsetof(ns3_nuccXfbinData, _field_68) == 0x68, "nuccXfbinData._field_68");
_Static_assert(offsetof(ns3_nuccXfbinData, docPtr) == 0x70, "nuccXfbinData.docPtr");
_Static_assert(offsetof(ns3_nuccXfbinData, _field_78) == 0x78, "nuccXfbinData._field_78");
_Static_assert(offsetof(ns3_nuccXfbinData, _field_80) == 0x80, "nuccXfbinData._field_80");
_Static_assert(offsetof(ns3_nuccXfbinData, loadState) == 0x88, "nuccXfbinData.loadState");

#endif /* CMN71_S3_H */