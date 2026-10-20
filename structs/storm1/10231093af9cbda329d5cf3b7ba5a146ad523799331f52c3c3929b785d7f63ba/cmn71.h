/* cmn71.h — struct group cmn71 for build s1 (NSUNS1.exe-a9fe00)
 * INFERRED from static decompilation; not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */
#ifndef CMN71_H
#define CMN71_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* MathGeo Matrix44: 4x4 float matrix, 0x40 bytes */
typedef struct __attribute__((packed)) MathGeo_Matrix44 {
    float m[4][4];
} MathGeo_Matrix44;
static_assert(sizeof(MathGeo_Matrix44) == 0x40, "MathGeo_Matrix44 must be 0x40");

/* nuccCriticalSection: opaque, 0x28 bytes */
typedef struct __attribute__((packed)) nuccCriticalSection {
    uint8_t data[0x28];
} nuccCriticalSection;
static_assert(sizeof(nuccCriticalSection) == 0x28, "nuccCriticalSection must be 0x28");

/* =========================================================================
 * nuccView — size 0x2D0 (720 bytes)
 * Evidence: LoadTh(0x2d0) in FUN_1404a3150 (nuccSys_Win64.cpp:0x584)
 * Vtable: PTR_FUN_140736d88 (ctor RVA 0x495BD0)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccView {
    /* 0x000 */ MathGeo_Matrix44 matrix0;
    /* 0x040 */ MathGeo_Matrix44 matrix1;
    /* 0x080 */ MathGeo_Matrix44 matrix2;
    /* 0x0C0 */ MathGeo_Matrix44 matrix3;
    /* 0x100 */ MathGeo_Matrix44 projectionMatrix;
    /* 0x140 */ MathGeo_Matrix44 viewMatrix;
    /* 0x180 */ MathGeo_Matrix44 matrix6;
    /* 0x1C0 */ MathGeo_Matrix44 matrix7;
    /* 0x200 */ uint32_t field_200;
    /* 0x204 */ uint32_t pad_204;
    /* 0x208 */ uint64_t field_208;
    /* 0x210 */ uint32_t field_210;
    /* 0x214 */ uint32_t pad_214;
    /* 0x218 */ uint64_t field_218;
    /* 0x220 */ uint32_t field_220;
    /* 0x224 */ uint32_t pad_224;
    /* 0x228 */ uint64_t field_228;
    /* 0x230 */ uint32_t field_230;
    /* 0x234 */ uint32_t pad_234;
    /* 0x238 */ uint64_t field_238;
    /* 0x240 */ uint32_t field_240;
    /* 0x244 */ uint32_t pad_244;
    /* 0x248 */ float fov;
    /* 0x24C */ float nearZ;
    /* 0x250 */ float farZ;
    /* 0x254 */ float field_254;
    /* 0x258 */ float field_258;
    /* 0x25C */ float halfWidth;
    /* 0x260 */ float halfHeight;
    /* 0x264 */ float frameX;
    /* 0x268 */ float frameY;
    /* 0x26C */ float frameW;
    /* 0x270 */ float frameH;
    /* 0x274 */ int32_t minZ;
    /* 0x278 */ int32_t maxZ;
    /* 0x27C */ float field_27C;
    /* 0x280 */ float field_280;
    /* 0x284 */ float field_284;
    /* 0x288 */ float field_288;
    /* 0x28C */ uint8_t pad_28C[0x2D0 - 0x28C];
} nuccView;

static_assert(offsetof(nuccView, matrix0) == 0x000, "nuccView.matrix0");
static_assert(offsetof(nuccView, matrix1) == 0x040, "nuccView.matrix1");
static_assert(offsetof(nuccView, matrix2) == 0x080, "nuccView.matrix2");
static_assert(offsetof(nuccView, matrix3) == 0x0C0, "nuccView.matrix3");
static_assert(offsetof(nuccView, projectionMatrix) == 0x100, "nuccView.projectionMatrix");
static_assert(offsetof(nuccView, viewMatrix) == 0x140, "nuccView.viewMatrix");
static_assert(offsetof(nuccView, matrix6) == 0x180, "nuccView.matrix6");
static_assert(offsetof(nuccView, matrix7) == 0x1C0, "nuccView.matrix7");
static_assert(offsetof(nuccView, field_200) == 0x200, "nuccView.field_200");
static_assert(offsetof(nuccView, pad_204) == 0x204, "nuccView.pad_204");
static_assert(offsetof(nuccView, field_208) == 0x208, "nuccView.field_208");
static_assert(offsetof(nuccView, field_210) == 0x210, "nuccView.field_210");
static_assert(offsetof(nuccView, pad_214) == 0x214, "nuccView.pad_214");
static_assert(offsetof(nuccView, field_218) == 0x218, "nuccView.field_218");
static_assert(offsetof(nuccView, field_220) == 0x220, "nuccView.field_220");
static_assert(offsetof(nuccView, pad_224) == 0x224, "nuccView.pad_224");
static_assert(offsetof(nuccView, field_228) == 0x228, "nuccView.field_228");
static_assert(offsetof(nuccView, field_230) == 0x230, "nuccView.field_230");
static_assert(offsetof(nuccView, pad_234) == 0x234, "nuccView.pad_234");
static_assert(offsetof(nuccView, field_238) == 0x238, "nuccView.field_238");
static_assert(offsetof(nuccView, field_240) == 0x240, "nuccView.field_240");
static_assert(offsetof(nuccView, pad_244) == 0x244, "nuccView.pad_244");
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
static_assert(offsetof(nuccView, pad_28C) == 0x28C, "nuccView.pad_28C");
static_assert(sizeof(nuccView) == 0x2D0, "nuccView size");

/* =========================================================================
 * nuccWorkerThread — size 0x70 (112 bytes)
 * Evidence: LoadTh(0x70) in nuccChannel::Create (RVA 0x4F5BC0)
 * Vtable: PTR_FUN_140744418 (ctor RVA 0x526CB0)
 * Inherits nuccThread (base 0x00-0x5F)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccWorkerThread {
    /* 0x00 */ uint8_t base_nuccThread[0x60];
    /* 0x60 */ uint64_t ownerPtr;
    /* 0x68 */ uint32_t busyFlag;
    /* 0x6C */ uint32_t priorityState;
} nuccWorkerThread;

static_assert(offsetof(nuccWorkerThread, base_nuccThread) == 0x00, "nuccWorkerThread.base_nuccThread");
static_assert(offsetof(nuccWorkerThread, ownerPtr) == 0x60, "nuccWorkerThread.ownerPtr");
static_assert(offsetof(nuccWorkerThread, busyFlag) == 0x68, "nuccWorkerThread.busyFlag");
static_assert(offsetof(nuccWorkerThread, priorityState) == 0x6C, "nuccWorkerThread.priorityState");
static_assert(sizeof(nuccWorkerThread) == 0x70, "nuccWorkerThread size");

/* =========================================================================
 * nuccXfbinData — size 0x90 (144 bytes)
 * Evidence: LoadTh(0x90) in nuccXfbinDocManager::Regist (RVA 0x49D810)
 * Vtable: PTR_FUN_140736d88 (ctor RVA 0x483590)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccXfbinData {
    /* 0x00 */ uint64_t vtablePtr;
    /* 0x08 */ uint8_t unk_08[0x10];
    /* 0x18 */ nuccCriticalSection critSection;
    /* 0x40 */ uint8_t unk_40[0x28];
    /* 0x68 */ uint64_t field_68;
    /* 0x70 */ uint64_t docPtr;
    /* 0x78 */ uint64_t field_78;
    /* 0x80 */ uint64_t field_80;
    /* 0x88 */ uint32_t loadState;
    /* 0x8C */ uint8_t pad_8C[0x90 - 0x8C];
} nuccXfbinData;

static_assert(offsetof(nuccXfbinData, vtablePtr) == 0x00, "nuccXfbinData.vtablePtr");
static_assert(offsetof(nuccXfbinData, unk_08) == 0x08, "nuccXfbinData.unk_08");
static_assert(offsetof(nuccXfbinData, critSection) == 0x18, "nuccXfbinData.critSection");
static_assert(offsetof(nuccXfbinData, unk_40) == 0x40, "nuccXfbinData.unk_40");
static_assert(offsetof(nuccXfbinData, field_68) == 0x68, "nuccXfbinData.field_68");
static_assert(offsetof(nuccXfbinData, docPtr) == 0x70, "nuccXfbinData.docPtr");
static_assert(offsetof(nuccXfbinData, field_78) == 0x78, "nuccXfbinData.field_78");
static_assert(offsetof(nuccXfbinData, field_80) == 0x80, "nuccXfbinData.field_80");
static_assert(offsetof(nuccXfbinData, loadState) == 0x88, "nuccXfbinData.loadState");
static_assert(offsetof(nuccXfbinData, pad_8C) == 0x8C, "nuccXfbinData.pad_8C");
static_assert(sizeof(nuccXfbinData) == 0x90, "nuccXfbinData size");

#endif /* CMN71_H */

