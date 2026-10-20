/* cmn44.h — Common struct group for NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 * Reconstructed from Ghidra decompiles via the decompiler cache. All layouts INFERRED.
 * Image base: 0x140000000. Offsets are RVA-relative to object this-pointer.
 * Sizes proven from game code where possible; otherwise noted as >= last field.
 */
#ifndef CMN44_S3_H
#define CMN44_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── Forward declarations / base class stubs ─── */

/* nuccChunkClump is a base class of nuccBillboard. We do not reconstruct it here;
   only note that nuccBillboard inherits it. The base occupies [0x00..0x2ac]
   based on Init/Animate field offsets starting at 0x250+. */

/* BlockAllocator (Nucc::Memory::BlockAllocator) is a base class of nuccBinStreamBuffRing
   and nuccAnmUtil::ClumpData. Not reconstructed here. Base occupies [0x00..0x17]. */

/* ─── Vector types (engine standard) ─── */

typedef struct { float x, y, z; } Vector3;
typedef struct { float x, y; } Vector2;
typedef struct { float x, y, z, w; } Vector4;
typedef struct { float m[4][4]; } Matrix44;

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboardAnmData
 * NOT a fixed-layout struct. This is a packed variable-length animation
 * data stream accessed by static GetData* methods. Each record starts
 * with a uint32 bitmask at offset 0, followed by a uint16 frame count
 * at offset 4, then variable-length per-frame data arrays whose presence
 * and stride are determined by bit pairs in the mask.
 *
 * Bitmask layout (from accessors):
 *   bits [1:0]   → Pos present       (stride 0xC = 3 floats)
 *   bits [3:2]   → Rot present       (stride 0x4 = 1 uint32)
 *   bits [5:4]   → Scale present     (stride 0x8 = 2 floats)
 *   bits [7:6]   → Opacity present   (stride 0x4 = 1 float)
 *   bits [9:8]   → UV1 present       (stride 0x8 = 2 floats)
 *   bits [11:10] → WH1 present       (stride 0x8 = 2 floats)
 *   bits [13:12] → BlendRate present (stride 0x4 = 1 float)
 *   bits [15:14] → BlendRate2 present(stride 0x4 = 1 float)
 *   bits [17:16] → GlareRate present (stride 0x4 = 1 float)
 *   bits [19:18] → AlphaRef present  (stride 0x4 = 1 float, stored as uint8 /255.0)
 *   bits [21:20] → OutlineId present (stride 0x4 = 1 uint32)
 *   bits [23:22] → UV2 present       (stride 0x8 = 2 floats)
 *   bits [25:24] → WH2 present       (stride 0x8 = 2 floats)
 *
 * No fixed struct is emitted. Documented here for reference only.
 * ═══════════════════════════════════════════════════════════════════ */

/* nuccBillboardAnmData: no instance state — all 13 methods are static accessors on a raw byte stream; INFERRED */

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboard
 * Inherits: nuccChunkClump (base occupies [0x00..~0x24f])
 * Vtable: PTR_FUN_1409e5d38 (set in ctor FUN_1406D80D0)
 * Size: unknown, >= 0x2B0 (last proven field anmData ptr at +0x2A8, size 8)
 * Evidence: nuccBillboard::Init RVA 0x6D80D0, Animate RVA 0x6D7B70,
 *           Draw, Elapse, GetChunkMaterial
 * ═══════════════════════════════════════════════════════════════════ */

/* We cannot emit a full struct because the base class nuccChunkClump is not
   reconstructed in this group. Instead we document the nuccBillboard-specific
   fields that sit on top of the base. The offsets below are absolute from
   the object this-pointer (confirmed by Init/Animate/Draw/Elapse in s3). */

/* nuccBillboard own-fields (offsets relative to this):
 *
 * +0x018 ptr   materialPtr1      Init RVA 0x6D80D0: *(longlong*)(this+0x18)
 * +0x028 byte  flags             Draw: *(byte*)(this+0x28) & 1
 * +0x030 ptr   materialPtr2      Init: lVar3 = *(longlong*)(this+0x30)
 * +0x038 ptr   coordPtr          Elapse: lVar3 = *(longlong*)(this+0x38)
 * +0x068 ptr   chunkModelArrayPtr Draw: *(longlong*)(this+0x68)
 * +0x070 uint32 chunkModelCount  Draw: *(uint*)(this+0x70)
 * +0x098 ptr   chunkMaterialRef  GetChunkMaterial: field at +0x98
 * +0x0A0 float opacity           Init/Draw/Animate: *(float*)(this+0xa0)
 * +0x250 Vector3 pos             Animate RVA 0x6D7B70: Nucc::Vector3::Set(this+0x250,...)
 * +0x25C uint32 rot              Animate: *(uint32*)(this+0x25c)
 * +0x260 Vector2 scale           Animate: Nucc::Vector2::Set(this+0x260,...)
 * +0x268 Vector2 uv1             Animate/Draw: this+0x268
 * +0x270 Vector2 wh1             Animate/Draw: this+0x270
 * +0x278 Vector2 uv2             Animate/Draw: this+0x278
 * +0x280 Vector2 wh2             Animate/Draw: this+0x280
 * +0x288 float blendRate         Animate/Draw: this+0x288
 * +0x28C float blendRate2        Animate/Draw: this+0x28c
 * +0x290 float glareRate         Animate/Draw: this+0x290
 * +0x294 float glareMultiplier   Init: set to 1.0f (0x3f800000); Draw: opacity *= this
 * +0x298 float alphaRef          Animate: *(float*)(this+0x298) = val/255.0
 * +0x29C uint32 outlineId        Animate/Draw: this+0x29c
 * +0x2A0 uint32 anmTime          Elapse: incremented; Animate: frame index
 * +0x2A4 uint32 anmFrameCount    Elapse: loop bound; Animate: divisor
 * +0x2A8 ptr   anmData           Animate/Draw/Elapse: *(ptr*)(this+0x2a8)
 *
 * Total own-field span: 0x2A8 + 8 = 0x2B0 minimum after base.
 * Since base ends before 0x250, object size >= 0x2B0.
 */

/* nuccBillboard: no instance state — base class nuccChunkClump not reconstructed; 22 own-fields documented above; INFERRED */

/* ═══════════════════════════════════════════════════════════════════
 * nuccBinStreamBuffRing
 * Inherits: Nucc::Memory::BlockAllocator (base occupies [0x00..0x17])
 * Vtable: PTR_FUN_1409e7ea0 (ctor RVA 0x715B70), dtor swap vtable differs
 * Size: unknown, >= 0x4C (last proven field flag at +0x48, byte-sized)
 * Evidence: ctor RVA 0x715B70, dtor, InitBlock, GetReadBlock RVA 0x715DD0
 * ═══════════════════════════════════════════════════════════════════ */

typedef struct __attribute__((packed)) {
    /* Base: Nucc::Memory::BlockAllocator [0x00..0x17] — not reconstructed */
    uint8_t _base[0x18];            /* 0x00 base class stub, size 0x18 */

    void    *buffer_ptr;            /* 0x18 ctor/dtor/InitBlock */
    uint64_t qword_0x20;            /* 0x20 ctor: =0 */
    uint32_t current_index;         /* 0x28 ctor: =0xFFFFFFFF; GetReadBlock reads */
    uint32_t _pad_0x2C;             /* 0x2C implicit padding before aligned ptr */
    uint64_t current_block_ptr;     /* 0x30 GetReadBlock RVA 0x715DD0: block pointer */
    uint32_t write_index;           /* 0x38 ctor: =0xFFFFFFFF */
    uint32_t block_size;            /* 0x3C ctor/InitBlock: =0x100000 */
    uint32_t field_0x40;            /* 0x40 ctor: =5 */
    uint32_t total_count;           /* 0x44 GetReadBlock: ring count */
    uint8_t  flags;                 /* 0x48 ctor/dtor: bit0 = owns buffer */
    uint8_t  _pad_0x49[7];          /* 0x49 trailing padding */
} nuccBinStreamBuffRing;

static_assert(offsetof(nuccBinStreamBuffRing, _base) == 0x00, "nuccBinStreamBuffRing._base");
static_assert(sizeof(((nuccBinStreamBuffRing*)0)->_base) == 0x18, "nuccBinStreamBuffRing._base size");
static_assert(offsetof(nuccBinStreamBuffRing, buffer_ptr) == 0x18, "nuccBinStreamBuffRing.buffer_ptr");
static_assert(offsetof(nuccBinStreamBuffRing, qword_0x20) == 0x20, "nuccBinStreamBuffRing.qword_0x20");
static_assert(offsetof(nuccBinStreamBuffRing, current_index) == 0x28, "nuccBinStreamBuffRing.current_index");
static_assert(offsetof(nuccBinStreamBuffRing, current_block_ptr)== 0x30, "nuccBinStreamBuffRing.current_block_ptr");
static_assert(offsetof(nuccBinStreamBuffRing, write_index) == 0x38, "nuccBinStreamBuffRing.write_index");
static_assert(offsetof(nuccBinStreamBuffRing, block_size) == 0x3C, "nuccBinStreamBuffRing.block_size");
static_assert(offsetof(nuccBinStreamBuffRing, field_0x40) == 0x40, "nuccBinStreamBuffRing.field_0x40");
static_assert(offsetof(nuccBinStreamBuffRing, total_count) == 0x44, "nuccBinStreamBuffRing.total_count");
static_assert(offsetof(nuccBinStreamBuffRing, flags) == 0x48, "nuccBinStreamBuffRing.flags");

/* ═══════════════════════════════════════════════════════════════════
 * nuccAppShaderParam
 * Ctor RVA 0x6EC2D0 zeros fields from 0x440 to 0x6E0.
 * InitializeShaderParam RVA 0x6EC3C0 accesses many field offsets.
 * UpdateShaderParamPreDraw accesses shadow/view matrices.
 * Size: unknown, >= 0x6E1 (last zeroed byte in ctor at +0x6E0)
 * Evidence: ctor RVA 0x6EC2D0, InitializeShaderParam RVA 0x6EC3C0,
 *           UpdateShaderParamPreDraw
 * Note: s3 ctor zeros +0x560 and +0x568 which were not zeroed in s2 ctor.
 *       These may be new fields or additional initialization in s3.
 * ═══════════════════════════════════════════════════════════════════ */

/* nuccAppShaderParam known field offsets (from InitializeShaderParam/UpdateShaderParamPreDraw in s3):
 *
 * +0x080 Vector4 identityMatrix    InitializeShaderParam: param_1+0x80 (4 floats)
 * +0x114 float fogNear[i]          InitializeShaderParam: param_1+0x114+i*0x10 (i=0..3)
 * +0x118 float fogFar[i]           InitializeShaderParam: param_1+0x118+i*0x10
 * +0x11C float fogInvRange[i]      InitializeShaderParam: param_1+0x11c+i*0x10
 * +0x150 Matrix44 viewMatrix       InitializeShaderParam: FUN(param_1+0x150,...)
 * +0x190 Matrix44 shadowFrustum[3] UpdateShaderParamPreDraw: param_1+400 (=0x190), 3x64 bytes
 * +0x1A0 Matrix44 shadowProjMat0   UpdateShaderParamPreDraw: param_1+0x1a0
 * +0x1E0 Matrix44 shadowProjMat1   UpdateShaderParamPreDraw: param_1+0x1e0
 * +0x220 Matrix44 shadowProjMat2   UpdateShaderParamPreDraw: param_1+0x220
 * +0x260 Matrix44 shadowViewProj   UpdateShaderParamPreDraw: param_1+0x260
 * +0x2A0 uint32 shaderFlags        InitializeShaderParam: param_1+0x2a0
 * +0x2B0 Vector4 colorParam        InitializeShaderParam: param_1+0x2b0 (4 floats)
 * +0x2C0 Vector4 ambientColor      InitializeShaderParam: param_1+0x2c0
 * +0x2D0 Vector4 fogColor          InitializeShaderParam: param_1+0x2d0
 * +0x2E0 Matrix44 viewProjMatrix   UpdateShaderParamPreDraw: Mul(param_1+0x2e0,...)
 * +0x320 Matrix44 invViewProjMat   InitializeShaderParam: param_1+800 (=0x320)
 * +0x360 Matrix44 cameraViewMat    InitializeShaderParam: param_1+0x360
 * +0x3A0 Vector4 lightDirScaled    InitializeShaderParam: param_1+0x3a0
 * +0x3B0 Vector4 userColorParam    InitializeShaderParam: param_1+0x3b0
 * +0x3C0 Matrix44 prevViewProjMat  InitializeShaderParam: param_1+0x3c0
 * +0x400 Matrix44 curViewProjMat   InitializeShaderParam: param_1+0x400
 * +0x440 uint64 textureHandle0     UpdateShaderParamPreDraw: param_1+0x440
 * +0x448 uint32 textureFlags0      UpdateShaderParamPreDraw: param_1+0x448
 * +0x450 uint64 textureHandle1     UpdateShaderParamPreDraw: param_1+0x450
 * +0x458 uint32 textureId1         UpdateShaderParamPreDraw: param_1+0x458
 * +0x460 uint64 textureHandle2     UpdateShaderParamPreDraw: param_1+0x460
 * +0x468 uint32 textureId2         UpdateShaderParamPreDraw: param_1+0x468
 * +0x470 uint64 textureHandle3     UpdateShaderParamPreDraw: param_1+0x470
 * +0x478 uint32 textureId3         UpdateShaderParamPreDraw: param_1+0x478
 * +0x480 uint64 textureHandle4     UpdateShaderParamPreDraw: param_1+0x480
 * +0x488 uint32 textureId4         UpdateShaderParamPreDraw: param_1+0x488
 * +0x490 uint64 textureHandle5     UpdateShaderParamPreDraw: param_1+0x490
 * +0x498 uint32 textureId5         UpdateShaderParamPreDraw: param_1+0x498
 * +0x4A0 uint64 textureHandle6     UpdateShaderParamPreDraw: param_1+0x4a0
 * +0x4A8 uint32 textureId6         UpdateShaderParamPreDraw: param_1+0x4a8
 * +0x4B0 Vector4 boneWeightParam   InitializeShaderParam: param_1+0x4b0
 * +0x4C0 Vector4 timeParam         InitializeShaderParam: param_1+0x4c0
 * +0x4D0 Vector4 texOffsetParam    UpdateShaderParamPreDraw: param_1+0x4d0
 * +0x4F0 Vector4 texScaleParam     UpdateShaderParamPreDraw: param_1+0x4f0
 * +0x500 Vector4 animBlendParam0   InitializeShaderParam: param_1+0x500
 * +0x510 Vector4 animBlendParam1   InitializeShaderParam: param_1+0x510
 * +0x520 Vector4 animBlendParam2   InitializeShaderParam: param_1+0x520
 * +0x530 Vector4 animBlendParam3   InitializeShaderParam: param_1+0x530
 * +0x540 Vector4 animBlendParam4   InitializeShaderParam: param_1+0x540
 * +0x550 Vector4 identityVec       InitializeShaderParam: param_1+0x550
 * +0x560 uint64 field_0x560        ctor RVA 0x6EC2D0: zeroed (NEW in s3 vs s2)
 * +0x568 uint64 field_0x568        ctor RVA 0x6EC2D0: zeroed (NEW in s3 vs s2)
 * +0x570 Matrix44 extraMatrix      InitializeShaderParam: param_1+0x570
 * +0x5B0 Matrix44 boneMatrix       InitializeShaderParam: param_1+0x5b0
 * +0x5F0 Vector3 charLightDir      InitializeShaderParam: param_1+0x5f0..0x5f8
 * +0x5FC float charLightInvW       UpdateShaderParamPreDraw: param_1+0x5fc
 * +0x600 Vector3 charLightColor    InitializeShaderParam: param_1+0x600..0x608
 * +0x60C float charLightInvH       UpdateShaderParamPreDraw: param_1+0x60c
 * +0x610 Vector4 charLightParams   InitializeShaderParam: param_1+0x610
 * +0x620 Vector4 uiTexTransform    UpdateShaderParamPreDraw: param_1+0x620
 * +0x630 Vector4 uiColorTransform  UpdateShaderParamPreDraw: param_1+0x630
 * +0x640 Vector4 outlineColor      InitializeShaderParam: param_1+0x640
 * +0x650 Vector4 effectColor       InitializeShaderParam: param_1+0x650
 * +0x660 Vector4 effectParams      InitializeShaderParam: param_1+0x660
 * +0x670 uint64 resolutionParam    InitializeShaderParam: param_1+0x670 (=0x100000)
 * +0x678 uint32 resField0x678      InitializeShaderParam: param_1+0x678
 * +0x67C uint32 resField0x67C      InitializeShaderParam: param_1+0x67c (=0)
 * +0x680 Vector4 viewportRect      InitializeShaderParam: param_1+0x680
 * +0x690 uint64 timestampParam     InitializeShaderParam: param_1+0x690
 * +0x698 uint32 timestampField     InitializeShaderParam: param_1+0x698
 * +0x6A0..0x6AF (gap)
 * +0x6B0 Vector4 postProcessParam  InitializeShaderParam: param_1+0x6b0
 * +0x6C0 uint64 dofParams          InitializeShaderParam: param_1+0x6c0
 * +0x6C8 uint64 dofParams2         InitializeShaderParam: param_1+0x6c8
 * +0x6D0 uint64 sentinelMinus1     InitializeShaderParam: param_1+0x6d0 (=0xFFFFFFFFFFFFFFFF)
 * +0x6D8 uint64 sentinelMinus1b    InitializeShaderParam: param_1+0x6d8 (=0xFFFFFFFFFFFFFFFF)
 * +0x6E0 uint8  endFlag            ctor/InitializeShaderParam: param_1+0x6e0 (=0)
 *
 * Cannot emit packed struct: too many unknown gaps between 0x000 and 0x080,
 * and various unexplored regions. Documented in fields TSV only.
 */

/* nuccAppShaderParam: no instance state — too many gaps for packed struct; 49 fields documented above; INFERRED */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil
 * Primarily a static utility class. Methods take external ClumpData** params.
 * No instance struct emitted. See fields TSV for details.
 * ═══════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil::ClumpData
 * Allocated via ccFileLoadListForUi::LoadTh(0x28,...) in CreateClumpData RVA 0x72B5A0.
 * Allocation size = 0x28 = 40 bytes (proven from s3 decompile).
 * Inherits BlockAllocator (ctor calls BlockAllocator::BlockAllocator).
 * Vtable: PTR_FUN_1409dcfa0 (set in CreateClumpData)
 * Fields from ClearClumpData:
 *   +0x18 ptr entries array pointer
 *   +0x20 uint16 entry count
 * Entry stride = 0x68 (from ClearClumpData loop)
 * Each entry: +0x00 = clump ptr, +0x08 = nuccInstanceList ptr
 * ═══════════════════════════════════════════════════════════════════ */

typedef struct __attribute__((packed)) {
    /* Base: BlockAllocator [0x00..0x17] */
    uint8_t  _base[0x18];           /* 0x00 base class stub, size 0x18 */
    void    *entries;               /* 0x18 ClearClumpData: *(longlong*)(*param_1+0x18) */
    uint16_t entry_count;           /* 0x20 ClearClumpData: *(ushort*)(*param_1+0x20) */
    uint8_t  _pad_0x22[6];          /* 0x22 padding to reach 0x28 allocation */
} nuccAnmUtil_ClumpData;

static_assert(offsetof(nuccAnmUtil_ClumpData, _base) == 0x00, "nuccAnmUtil_ClumpData._base");
static_assert(sizeof(((nuccAnmUtil_ClumpData*)0)->_base) == 0x18, "nuccAnmUtil_ClumpData._base size");
static_assert(offsetof(nuccAnmUtil_ClumpData, entries) == 0x18, "nuccAnmUtil_ClumpData.entries");
static_assert(offsetof(nuccAnmUtil_ClumpData, entry_count) == 0x20, "nuccAnmUtil_ClumpData.entry_count");
/* Allocation proven: ccFileLoadListForUi::LoadTh(0x28,...) in CreateClumpData RVA 0x72B5A0 */
static_assert(sizeof(nuccAnmUtil_ClumpData) == 0x28, "nuccAnmUtil_ClumpData size == 0x28");

#endif /* CMN44_S3_H */
