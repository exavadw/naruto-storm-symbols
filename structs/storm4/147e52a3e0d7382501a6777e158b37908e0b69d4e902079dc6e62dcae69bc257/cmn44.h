/* cmn44.h — Common struct group for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 * Reconstructed from Ghidra decompiles via the decompiler cache. All layouts INFERRED.
 * Image base: 0x140000000. Offsets are RVA-relative to object this-pointer.
 * Sizes proven from game code where possible; otherwise noted as >= last field.
 * Names carried from s3 prior art; every offset re-verified in s4 decompiles.
 */
#ifndef CMN44_S4_H
#define CMN44_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── Forward declarations / base class stubs ─── */

/* nuccChunkClump is a base class of nuccBillboard. Not reconstructed here;
   the base occupies [0x00..~0x24f] based on Init/Animate field offsets starting at 0x250+. */

/* BlockAllocator (Nucc::Memory::BlockAllocator) is a base class of nuccBinStreamBuffRing
   and nuccAnmUtil::ClumpData. Not reconstructed here. Base occupies [0x00..0x17]. */

/* ─── Vector types (engine standard) ─── */

typedef struct { float x, y, z; } Vector3;
typedef struct { float x, y; } Vector2;
typedef struct { float x, y, z, w; } Vector4;
typedef struct { float m[4][4]; } Matrix44;

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboardAnmData
 * NOT a fixed-layout struct. Variable-length animation data stream accessed
 * by static GetData* methods. Each record starts with a uint32 bitmask at
 * offset 0, followed by a uint16 frame count at offset 4, then variable-
 * length per-frame data arrays whose presence and stride are determined by
 * bit pairs in the mask. Same format as s3. Documented for reference only.
 * ═══════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboard
 * Inherits: nuccChunkClump (base occupies [0x00..~0x24f])
 * Vtable: PTR_FUN_141107830 (set in ctor RVA 0xA2EE10)
 * Size: PROVEN 0x2B0 — FUN_140a017f0(0x2b0,...) in nuccParticleElm::EntryMdl RVA 0xA52290
 * Evidence: ctor RVA 0xA2EE10, Init RVA 0xA2F770, Animate RVA 0xA2F1F0,
 *           Draw RVA 0xA2F470, Elapse RVA 0xA2F600
 * ═══════════════════════════════════════════════════════════════════ */

/* nuccBillboard own-fields (offsets relative to this, all verified in s4):
 *
 * +0x018 ptr   chunk_ptr           Init: *(longlong*)(this+0x18)
 * +0x028 byte  flags               Draw: *(byte*)(this+0x28) & 1
 * +0x030 ptr   materialPtr2        Init: lVar3 = *(longlong*)(this+0x30)
 * +0x038 ptr   coordPtr            Elapse: lVar3 = *(longlong*)(this+0x38)
 * +0x068 ptr   chunkModelArrayPtr  Draw: *(longlong*)(this+0x68)
 * +0x070 uint32 chunkModelCount    Draw: *(uint*)(this+0x70)
 * +0x0A0 float opacity             Init/Draw/Animate: *(float*)(this+0xa0)
 * +0x250 Vector3 pos               ctor: sub-object at +0x4a (=+0x250); Animate: Set(this+0x250)
 * +0x25C uint32 rot                Animate: *(uint32*)(this+0x25c)
 * +0x260 Vector2 scale             ctor: sub-object at +0x4c (=+0x260); Animate: Set(this+0x260)
 * +0x268 Vector2 uv1               ctor: sub-object at +0x4d (=+0x268); Animate/Draw
 * +0x270 Vector2 wh1               ctor: sub-object at +0x4e (=+0x270); Animate/Draw
 * +0x278 Vector2 uv2               ctor: sub-object at +0x4f (=+0x278); Animate/Draw
 * +0x280 Vector2 wh2               ctor: sub-object at +0x50 (=+0x280); Animate/Draw
 * +0x288 float blendRate           Animate/Draw: this+0x288
 * +0x28C float blendRate2          Animate/Draw: this+0x28c
 * +0x290 float glareRate           Animate/Draw: this+0x290
 * +0x294 float glareMultiplier     Init: set to 1.0f; Draw: opacity *= this
 * +0x298 float alphaRef            Animate: *(float*)(this+0x298) = val/255.0
 * +0x29C uint32 outlineId          Animate/Draw: this+0x29c
 * +0x2A0 uint32 anmTime            Elapse: incremented; Animate: frame index
 * +0x2A4 uint32 anmFrameCount      Elapse: loop bound; Animate: divisor
 * +0x2A8 ptr   anmData             Animate/Draw/Elapse: *(ptr*)(this+0x2a8)
 *
 * Total own-field span: 0x2A8 + 8 = 0x2B0 minimum. Allocation proven = 0x2B0.
 */

/* ═══════════════════════════════════════════════════════════════════
 * nuccBinStreamBuffRing
 * Inherits: Nucc::Memory::BlockAllocator (base occupies [0x00..0x17])
 * Vtable: PTR_FUN_1411101e0 (ctor RVA 0xA90010)
 * Size: unknown, >= 0x4C (last proven field flags at +0x48, byte-sized)
 * Stack-allocated in callers (local_e8[80]); no heap allocator size found.
 * Evidence: ctor RVA 0xA90010, dtor RVA 0xA900B0, InitBlock RVA 0xA90430,
 *           GetReadBlock RVA 0xA90270
 * ═══════════════════════════════════════════════════════════════════ */

typedef struct __attribute__((packed)) {
    /* Base: Nucc::Memory::BlockAllocator [0x00..0x17] — not reconstructed */
    uint8_t _base[0x18];            /* 0x00 base class stub, size 0x18 */

    void    *buffer_ptr;            /* 0x18 ctor/dtor/InitBlock */
    uint64_t qword_0x20;            /* 0x20 ctor: =0 */
    uint32_t current_index;         /* 0x28 ctor: =0xFFFFFFFF; GetReadBlock reads */
    uint32_t _pad_0x2C;             /* 0x2C implicit padding before aligned ptr */
    uint64_t current_block_ptr;     /* 0x30 GetReadBlock: block pointer */
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
 * Ctor RVA 0xA76D80 zeros fields from 0x440 to 0x6E0.
 * InitializeShaderParam RVA 0xA76E70 accesses many field offsets.
 * UpdateShaderParamPreDraw RVA 0xA77F50 accesses shadow/view matrices.
 * Size: unknown, >= 0x6E1 (last zeroed byte in ctor at +0x6E0).
 * Embedded as sub-object at parent+0x80 in nuccDrawCmd_DrawPrimitive::Create
 * (parent allocated as param_2*param_3+0x770). No standalone allocator size found.
 * Evidence: ctor RVA 0xA76D80, InitializeShaderParam RVA 0xA76E70,
 *           UpdateShaderParamPreDraw RVA 0xA77F50
 * ═══════════════════════════════════════════════════════════════════ */

/* nuccAppShaderParam known field offsets (verified in s4 decompiles):
 *
 * +0x080 Vector4 identityMatrix    InitializeShaderParam: param_1+0x80 (4 floats)
 * +0x084 float   field_0x84        InitializeShaderParam: param_1+0x84
 * +0x088 float   field_0x88        InitializeShaderParam: param_1+0x88
 * +0x08C float   field_0x8c        InitializeShaderParam: param_1+0x8c
 * +0x114 float fogNear[i]          InitializeShaderParam: param_1+0x114+i*0x10 (i=0..3)
 * +0x118 float fogFar[i]           InitializeShaderParam: param_1+0x118+i*0x10
 * +0x11C float fogInvRange[i]      InitializeShaderParam: param_1+0x11c+i*0x10
 * +0x150 Matrix44 viewMatrix       InitializeShaderParam: FUN(param_1+0x150,...)
 * +0x1A0 Matrix44 shadowProjMat0   UpdateShaderParamPreDraw: param_1+0x1a0
 * +0x1E0 Matrix44 shadowProjMat1   UpdateShaderParamPreDraw: param_1+0x1e0
 * +0x220 Matrix44 shadowProjMat2   UpdateShaderParamPreDraw: param_1+0x220
 * +0x260 Matrix44 shadowViewProj   UpdateShaderParamPreDraw: param_1+0x260
 * +0x2A0 uint32 shaderFlags        InitializeShaderParam: param_1+0x2a0
 * +0x2E0 Matrix44 viewProjMatrix   UpdateShaderParamPreDraw: Mul(param_1+0x2e0,...)
 * +0x440 uint64 textureHandle0     ctor zeroed; UpdateShaderParamPreDraw: param_1+0x440
 * +0x448 uint32 textureFlags0      UpdateShaderParamPreDraw: param_1+0x448
 * +0x44C uint32 field_0x44c        UpdateShaderParamPreDraw: param_1+0x44c
 * +0x450 uint64 textureHandle1     UpdateShaderParamPreDraw: param_1+0x450
 * +0x458 uint32 textureId1         UpdateShaderParamPreDraw: param_1+0x458
 * +0x45C uint32 field_0x45c        UpdateShaderParamPreDraw: param_1+0x45c
 * +0x460 uint64 textureHandle2     UpdateShaderParamPreDraw: param_1+0x460
 * +0x468 uint32 textureId2         UpdateShaderParamPreDraw: param_1+0x468
 * +0x46C uint32 field_0x46c        UpdateShaderParamPreDraw: param_1+0x46c
 * +0x470 uint64 textureHandle3     UpdateShaderParamPreDraw: param_1+0x470
 * +0x478 uint32 textureId3         UpdateShaderParamPreDraw: param_1+0x478
 * +0x47C uint32 field_0x47c        UpdateShaderParamPreDraw: param_1+0x47c
 * +0x480 uint64 textureHandle4     UpdateShaderParamPreDraw: param_1+0x480
 * +0x488 uint32 textureId4         UpdateShaderParamPreDraw: param_1+0x488
 * +0x48C uint32 field_0x48c        UpdateShaderParamPreDraw: param_1+0x48c
 * +0x490 uint64 textureHandle5     UpdateShaderParamPreDraw: param_1+0x490
 * +0x498 uint32 textureId5         UpdateShaderParamPreDraw: param_1+0x498
 * +0x49C uint32 field_0x49c        UpdateShaderParamPreDraw: param_1+0x49c
 * +0x4A0 uint64 textureHandle6     UpdateShaderParamPreDraw: param_1+0x4a0
 * +0x4A8 uint32 textureId6         UpdateShaderParamPreDraw: param_1+0x4a8
 * +0x4AC uint32 field_0x4ac        UpdateShaderParamPreDraw: param_1+0x4ac
 * +0x4D0 Vector4 texOffsetParam    UpdateShaderParamPreDraw: param_1+0x4d0
 * +0x4F0 Vector4 texScaleParam     UpdateShaderParamPreDraw: param_1+0x4f0
 * +0x560 uint64 field_0x560        ctor RVA 0xA76D80: zeroed
 * +0x568 uint64 field_0x568        ctor RVA 0xA76D80: zeroed
 * +0x670 uint64 resolutionParam    ctor RVA 0xA76D80: zeroed
 * +0x678 uint64 field_0x678        ctor RVA 0xA76D80: zeroed
 * +0x680 uint64 field_0x680        ctor RVA 0xA76D80: zeroed
 * +0x688 uint64 field_0x688        ctor RVA 0xA76D80: zeroed
 * +0x690 uint64 field_0x690        ctor RVA 0xA76D80: zeroed
 * +0x698 uint64 field_0x698        ctor RVA 0xA76D80: zeroed
 * +0x6E0 uint8  endFlag            ctor/InitializeShaderParam: param_1+0x6e0 (=0)
 *
 * Cannot emit packed struct: too many unknown gaps between 0x000 and 0x080,
 * and various unexplored regions. Documented in fields TSV only.
 */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil
 * Primarily a static utility class. Methods take external ClumpData** params.
 * No instance struct emitted. See fields TSV for details.
 * ═══════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil::ClumpData
 * Allocated via FUN_140a017f0(0x28,...) in CreateClumpData RVA 0xAA1120.
 * Allocation size = 0x28 = 40 bytes (PROVEN from s4 decompile).
 * Inherits BlockAllocator (ctor calls BlockAllocator::BlockAllocator).
 * Vtable: PTR_FUN_141105460 (set in CreateClumpData)
 * Fields from ClearClumpData RVA 0xAA1060:
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
/* Allocation proven: FUN_140a017f0(0x28,...) in CreateClumpData RVA 0xAA1120 */
static_assert(sizeof(nuccAnmUtil_ClumpData) == 0x28, "nuccAnmUtil_ClumpData size == 0x28");

#endif /* CMN44_S4_H */