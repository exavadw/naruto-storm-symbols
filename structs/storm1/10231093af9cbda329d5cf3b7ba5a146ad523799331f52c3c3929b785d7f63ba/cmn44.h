/* cmn44.h — Common struct group for NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 * Reconstructed from Ghidra decompiles via the decompiler cache. All layouts INFERRED.
 * Image base: 0x140000000. Offsets are RVA-relative to object this-pointer.
 * Sizes proven from game code where possible; otherwise noted as >= last field.
 */
#ifndef CMN44_H
#define CMN44_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── Forward declarations / base class stubs ─── */

/* nuccChunkClump is a base class of nuccBillboard. We do not reconstruct it here;
   only note that nuccBillboard inherits it. The base occupies [0x00..0x2ac]
   based on Init/Animate field offsets starting at 0x250+. */

/* BlockAllocator (Nucc::Memory::BlockAllocator) is a base class of nuccBinStreamBuffRing.
   Not reconstructed here. Base occupies [0x00..0x17]. */

/* ─── Vector types (engine standard) ─── */

typedef struct { float x, y, z; } Vector3;
typedef struct { float x, y; } Vector2;

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

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboard
 * Inherits: nuccChunkClump (base occupies [0x00..~0x24f])
 * Vtable: PTR_FUN_14073dd38 (set in ctor)
 * Size: unknown, >= 0x2AC (last proven field anmData ptr at +0x2A8, size 8)
 * Evidence: nuccBillboard::Init, Animate, Draw, Elapse, GetChunkMaterial
 * ═══════════════════════════════════════════════════════════════════ */

/* We cannot emit a full struct because the base class nuccChunkClump is not
   reconstructed in this group. Instead we document the nuccBillboard-specific
   fields that sit on top of the base. The offsets below are absolute from
   the object this-pointer (confirmed by Animate/Draw/Elapse). */

/* nuccBillboard own-fields (offsets relative to this):
 *
 * +0x018  ptr      materialPtr1         Init: *(longlong*)(this+0x30), SetAnmTime
 * +0x028  byte     flags                Draw: *(byte*)(this+0x28) & 1
 * +0x030  ptr      materialPtr2         Init: lVar3 = *(longlong*)(this+0x30)
 * +0x038  ptr      coordPtr             Elapse: lVar3 = *(longlong*)(this+0x38)
 * +0x068  ptr      chunkModelArrayPtr   Draw: *(longlong*)(this+0x68)
 * +0x070  uint32   chunkModelCount      Draw: *(uint*)(this+0x70)
 * +0x098  ptr      chunkMaterialRef     GetChunkMaterial: field at +0x98
 * +0x0A0  float    opacity              Init/Draw/Animate: *(float*)(this+0xa0)
 * +0x250  Vector3  pos                  Animate: Nucc::Vector3::Set(this+0x250,...)
 * +0x25C  uint32   rot                  Animate: *(uint32*)(this+0x25c)
 * +0x260  Vector2  scale                Animate: Nucc::Vector2::Set(this+0x260,...)
 * +0x268  Vector2  uv1                  Animate/Draw: this+0x268
 * +0x270  Vector2  wh1                  Animate/Draw: this+0x270
 * +0x278  Vector2  uv2                  Animate/Draw: this+0x278
 * +0x280  Vector2  wh2                  Animate/Draw: this+0x280
 * +0x288  float    blendRate            Animate/Draw: this+0x288
 * +0x28C  float    blendRate2           Animate/Draw: this+0x28c
 * +0x290  float    glareRate            Animate/Draw: this+0x290
 * +0x294  float    glareMultiplier      Init: set to 1.0f; Draw: opacity *= this
 * +0x298  float    alphaRef             Animate: *(float*)(this+0x298) = val/255.0
 * +0x29C  uint32   outlineId            Animate/Draw: this+0x29c
 * +0x2A0  uint32   anmTime              Elapse: incremented; Animate: used as frame index
 * +0x2A4  uint32   anmFrameCount        Elapse: loop bound; Animate: divisor
 * +0x2A8  ptr      anmData              Animate/Draw/Elapse: *(ptr*)(this+0x2a8)
 *
 * Total own-field span: 0x2A8 + 8 = 0x2B0 minimum after base.
 * Since base ends before 0x250, object size >= 0x2B0.
 */

/* ═══════════════════════════════════════════════════════════════════
 * nuccBinStreamBuffRing
 * Inherits: Nucc::Memory::BlockAllocator (base occupies [0x00..0x17])
 * Vtable: PTR_FUN_140737c98 (ctor), PTR_FUN_140745358 (dtor swap)
 * Size: unknown, >= 0x4C (last proven field flag at +0x48, byte-sized)
 * Evidence: ctor, dtor, InitBlock, GetReadBlock
 * ═══════════════════════════════════════════════════════════════════ */

typedef struct {
    /* Base: Nucc::Memory::BlockAllocator [0x00..0x17] — not reconstructed */
    uint8_t _base[0x18];                          /* 0x00  base class stub, size 0x18 */

    void   *buffer_ptr;                           /* 0x18  ctor/dtor/InitBlock */
    uint64_t qword_0x20;                          /* 0x20  ctor: =0 */
    uint32_t current_index;                       /* 0x28  ctor: =0xFFFFFFFF; GetReadBlock reads */
    uint32_t _pad_0x2C;                           /* 0x2C  implicit padding before aligned ptr */
    uint64_t current_block_ptr;                   /* 0x30  GetReadBlock: block pointer */
    uint32_t write_index;                         /* 0x38  ctor: =0xFFFFFFFF */
    uint32_t block_size;                          /* 0x3C  ctor/InitBlock: =0x100000 */
    uint32_t field_0x40;                          /* 0x40  ctor: =5 */
    uint32_t total_count;                         /* 0x44  GetReadBlock: ring count */
    uint8_t  flags;                               /* 0x48  ctor/dtor: bit0 = owns buffer */
    uint8_t _pad_0x49[7];                         /* 0x49  trailing padding */
} nuccBinStreamBuffRing;

static_assert(offsetof(nuccBinStreamBuffRing, _base)           == 0x00, "nuccBinStreamBuffRing._base");
static_assert(sizeof(((nuccBinStreamBuffRing*)0)->_base)       == 0x18, "nuccBinStreamBuffRing._base size");
static_assert(offsetof(nuccBinStreamBuffRing, buffer_ptr)      == 0x18, "nuccBinStreamBuffRing.buffer_ptr");
static_assert(offsetof(nuccBinStreamBuffRing, qword_0x20)      == 0x20, "nuccBinStreamBuffRing.qword_0x20");
static_assert(offsetof(nuccBinStreamBuffRing, current_index)   == 0x28, "nuccBinStreamBuffRing.current_index");
static_assert(offsetof(nuccBinStreamBuffRing, current_block_ptr)== 0x30, "nuccBinStreamBuffRing.current_block_ptr");
static_assert(offsetof(nuccBinStreamBuffRing, write_index)     == 0x38, "nuccBinStreamBuffRing.write_index");
static_assert(offsetof(nuccBinStreamBuffRing, block_size)      == 0x3C, "nuccBinStreamBuffRing.block_size");
static_assert(offsetof(nuccBinStreamBuffRing, field_0x40)      == 0x40, "nuccBinStreamBuffRing.field_0x40");
static_assert(offsetof(nuccBinStreamBuffRing, total_count)     == 0x44, "nuccBinStreamBuffRing.total_count");
static_assert(offsetof(nuccBinStreamBuffRing, flags)           == 0x48, "nuccBinStreamBuffRing.flags");

/* ═══════════════════════════════════════════════════════════════════
 * nuccAppShaderParam
 * No visible base class constructor call in ctor.
 * Ctor zeros fields from 0x440 to 0x6E0 (21 qword writes).
 * InitializeShaderParam accesses param_1+0x190 (shadow frustum at +400=0x190),
 *   +0x1A0, +0x1E0, +0x220, +0x2E0 (matrix fields).
 * UpdateShaderParamPreDraw accesses same matrix offsets.
 * Size: unknown, >= 0x6E1 (last zeroed byte in ctor)
 * Evidence: ctor, InitializeShaderParam, UpdateShaderParamPreDraw, SetShaderParam
 * ═══════════════════════════════════════════════════════════════════ */

/* nuccAppShaderParam known field offsets (from InitializeShaderParam/UpdateShaderParamPreDraw):
 *
 * +0x190  Matrix44  shadowFrustum[3]    UpdateShaderParamPreDraw: param_1+400 (=0x190), 3×64 bytes
 * +0x1A0  Matrix44  shadowProjMatrix0   UpdateShaderParamPreDraw: param_1+0x1a0
 * +0x1E0  Matrix44  shadowProjMatrix1   UpdateShaderParamPreDraw: param_1+0x1e0
 * +0x220  Matrix44  shadowProjMatrix2   UpdateShaderParamPreDraw: param_1+0x220
 * +0x2E0  Matrix44  viewProjMatrix      UpdateShaderParamPreDraw: Mul(param_1+0x2e0,...)
 * +0x440..0x6E0  zeroed region          ctor: 21 qword/byte writes clearing this range
 *
 * Cannot emit packed struct: too many unknown gaps between 0x000 and 0x190,
 * and between 0x2E0+0x40=0x320 and 0x440. Documented in fields TSV only.
 */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil
 * Primarily a static utility class. Methods take external ClumpData** params.
 * state_surface found 2 low-confidence fields at 0xC0 and 0x100 but these
 * may belong to a global/singleton rather than instance state.
 * No instance struct emitted. See fields TSV for details.
 * ═══════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════
 * nuccAnmUtil::ClumpData
 * Allocated via ccFileLoadListForUi::LoadTh(0x28,...) in CreateClumpData.
 * Allocation size = 0x28 = 40 bytes.
 * Inherits BlockAllocator (ctor calls BlockAllocator::BlockAllocator).
 * Vtable: PTR_FUN_1407395c8
 * Fields from ClearClumpData:
 *   +0x18  ptr   entries array pointer
 *   +0x20  uint16 entry count
 * Entry stride = 0x68 (from ClearClumpData loop: lVar4 += 0x68)
 * Each entry: +0x00 = clump ptr, +0x08 = nuccInstanceList ptr
 * ═══════════════════════════════════════════════════════════════════ */

typedef struct {
    /* Base: BlockAllocator [0x00..0x17] */
    uint8_t  _base[0x18];          /* 0x00  base class stub, size 0x18 */
    void    *entries;              /* 0x18  ClearClumpData: *(longlong*)(*param_1+0x18) */
    uint16_t entry_count;          /* 0x20  ClearClumpData: *(ushort*)(*param_1+0x20) */
    uint8_t  _pad_0x22[6];        /* 0x22  padding to reach 0x28 allocation */
} nuccAnmUtil_ClumpData;

static_assert(offsetof(nuccAnmUtil_ClumpData, _base)       == 0x00, "nuccAnmUtil_ClumpData._base");
static_assert(sizeof(((nuccAnmUtil_ClumpData*)0)->_base)   == 0x18, "nuccAnmUtil_ClumpData._base size");
static_assert(offsetof(nuccAnmUtil_ClumpData, entries)     == 0x18, "nuccAnmUtil_ClumpData.entries");
static_assert(offsetof(nuccAnmUtil_ClumpData, entry_count) == 0x20, "nuccAnmUtil_ClumpData.entry_count");
/* Allocation proven: ccFileLoadListForUi::LoadTh(0x28,...) in CreateClumpData */
static_assert(sizeof(nuccAnmUtil_ClumpData) == 0x28, "nuccAnmUtil_ClumpData size == 0x28");


/* Forward declaration from cmn17.h */
typedef struct { float m[16]; } ns1_Matrix44;

/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboardAnmData
 * Packed variable-length animation data stream. NOT a fixed-layout object.
 * This struct represents only the fixed 8-byte header prefix; the remainder
 * is variable-length per-frame data driven by the bitmask.
 * All 13 GetData* methods are static accessors operating on this stream.
 * Evidence RVAs: 0x522070 (GetDataAlphaRef), 0x522260 (GetDataBlendRate2),
 *   0x5223B0 (GetDataBlendRate), 0x5224D0 (GetDataGlareRate),
 *   0x522640 (GetDataOpacity), 0x5226D0 (GetDataOutlineId),
 *   0x5228F0 (GetDataPos), 0x522900 (GetDataRot), 0x522940 (GetDataScale),
 *   0x5229A0 (GetDataUV1), 0x522A60 (GetDataUV2), 0x522C00 (GetDataWH1),
 *   0x522D00 (GetDataWH2).
 * Size: 0x08 (header only; full stream is variable-length)
 * ═══════════════════════════════════════════════════════════════════ */

#pragma pack(push, 1)
typedef struct {
    uint32_t bitmask;          /* 0x00  bit pairs control presence of each channel */
    uint16_t frame_count;      /* 0x04  number of frames in stream */
    uint8_t  _pad_0x06[2];    /* 0x06  padding to align next read */
} nuccBillboardAnmData;
#pragma pack(pop)

static_assert(offsetof(nuccBillboardAnmData, bitmask)     == 0x00, "nuccBillboardAnmData.bitmask");
static_assert(offsetof(nuccBillboardAnmData, frame_count)  == 0x04, "nuccBillboardAnmData.frame_count");
static_assert(offsetof(nuccBillboardAnmData, _pad_0x06)    == 0x06, "nuccBillboardAnmData._pad_0x06");
static_assert(sizeof(nuccBillboardAnmData)                 == 0x08, "nuccBillboardAnmData size == 0x08");


/* ═══════════════════════════════════════════════════════════════════
 * nuccBillboard
 * Inherits: nuccChunkClump (base occupies [0x00..~0x24F], not reconstructed here)
 * Vtable: PTR_FUN_14073dd38 (set in ctor)
 * Size: unknown, >= 0x2B0 (last field anmData ptr at +0x2A8, size 8)
 * Only the billboard-specific own-fields region [0x250..0x2AF] is laid out;
 * the base class stub covers [0x00..0x24F].
 * Evidence: nuccBillboard::Init, Animate, Draw, Elapse, GetChunkMaterial
 * ═══════════════════════════════════════════════════════════════════ */

#pragma pack(push, 1)
typedef struct {
    uint8_t  _base[0x250];                     /* 0x000  nuccChunkClump base stub */
    Vector3  pos;                              /* 0x250  Animate: Nucc::Vector3::Set(this+0x250,...) */
    uint32_t rot;                              /* 0x25C  Animate: *(uint32*)(this+0x25c) packed rotation */
    Vector2  scale;                            /* 0x260  Animate: Nucc::Vector2::Set(this+0x260,...) */
    Vector2  uv1;                              /* 0x268  Animate/Draw: copied to chunk model +0x38 */
    Vector2  wh1;                              /* 0x270  Animate/Draw: copied to chunk model +0x58 */
    Vector2  uv2;                              /* 0x278  Animate/Draw: copied to chunk model +0x40 */
    Vector2  wh2;                              /* 0x280  Animate/Draw: copied to chunk model +0x60 */
    float    blendRate;                        /* 0x288  Animate/Draw: copied to chunk model +0x78 */
    float    blendRate2;                       /* 0x28C  Animate/Draw: copied to chunk model +0x7c */
    float    glareRate;                        /* 0x290  Animate/Draw: copied to chunk model +0x34 */
    float    glareMultiplier;                  /* 0x294  Init: 1.0f; Draw: opacity *= this */
    float    alphaRef;                         /* 0x298  Animate: val/255.0; Draw: chunk model +0x30 */
    uint32_t outlineId;                        /* 0x29C  Animate/Draw: copied to chunk model +0x84 */
    uint32_t anmTime;                          /* 0x2A0  Elapse: incremented; Animate: frame index */
    uint32_t anmFrameCount;                    /* 0x2A4  Elapse: loop bound; Animate: divisor */
    void    *anmData;                          /* 0x2A8  Animate/Draw/Elapse: ptr to nuccBillboardAnmData stream */
} nuccBillboard;
#pragma pack(pop)

static_assert(offsetof(nuccBillboard, _base)           == 0x250 - 0x250, "nuccBillboard._base");
static_assert(offsetof(nuccBillboard, pos)             == 0x250, "nuccBillboard.pos");
static_assert(offsetof(nuccBillboard, rot)             == 0x25C, "nuccBillboard.rot");
static_assert(offsetof(nuccBillboard, scale)           == 0x260, "nuccBillboard.scale");
static_assert(offsetof(nuccBillboard, uv1)             == 0x268, "nuccBillboard.uv1");
static_assert(offsetof(nuccBillboard, wh1)             == 0x270, "nuccBillboard.wh1");
static_assert(offsetof(nuccBillboard, uv2)             == 0x278, "nuccBillboard.uv2");
static_assert(offsetof(nuccBillboard, wh2)             == 0x280, "nuccBillboard.wh2");
static_assert(offsetof(nuccBillboard, blendRate)       == 0x288, "nuccBillboard.blendRate");
static_assert(offsetof(nuccBillboard, blendRate2)      == 0x28C, "nuccBillboard.blendRate2");
static_assert(offsetof(nuccBillboard, glareRate)       == 0x290, "nuccBillboard.glareRate");
static_assert(offsetof(nuccBillboard, glareMultiplier) == 0x294, "nuccBillboard.glareMultiplier");
static_assert(offsetof(nuccBillboard, alphaRef)        == 0x298, "nuccBillboard.alphaRef");
static_assert(offsetof(nuccBillboard, outlineId)       == 0x29C, "nuccBillboard.outlineId");
static_assert(offsetof(nuccBillboard, anmTime)         == 0x2A0, "nuccBillboard.anmTime");
static_assert(offsetof(nuccBillboard, anmFrameCount)   == 0x2A4, "nuccBillboard.anmFrameCount");
static_assert(offsetof(nuccBillboard, anmData)         == 0x2A8, "nuccBillboard.anmData");


/* ═══════════════════════════════════════════════════════════════════
 * nuccAppShaderParam
 * No visible base class constructor call in ctor.
 * Ctor zeros fields from 0x440 to 0x6E0 (21 qword writes).
 * Size: unknown, >= 0x6E1 (last zeroed byte in ctor)
 * Large unexplored regions: [0x000–0x190] and [0x320–0x440].
 * Evidence: ctor, InitializeShaderParam, UpdateShaderParamPreDraw, SetShaderParam
 * ═══════════════════════════════════════════════════════════════════ */

#pragma pack(push, 1)
typedef struct {
    uint8_t       _unk_0x000[0x190];          /* 0x000  unexplored region */
    uint8_t       field_0x190[0x10];          /* 0x190  InitializeShaderParam: param_1+0x190 (16 bytes before first matrix) */
    ns1_Matrix44  shadowProjMatrix0;          /* 0x1A0  UpdateShaderParamPreDraw: param_1+0x1a0 */
    ns1_Matrix44  shadowProjMatrix1;          /* 0x1E0  UpdateShaderParamPreDraw: param_1+0x1e0 */
    ns1_Matrix44  shadowProjMatrix2;          /* 0x220  UpdateShaderParamPreDraw: param_1+0x220 */
    uint8_t       _gap_0x260[0x80];           /* 0x260  gap to viewProjMatrix */
    ns1_Matrix44  viewProjMatrix;             /* 0x2E0  UpdateShaderParamPreDraw: Mul(param_1+0x2e0,...) */
    uint8_t       _gap_0x320[0x120];          /* 0x320  gap to zeroedRegion */
    uint8_t       zeroedRegion[0x2A1];        /* 0x440  ctor: clears 0x440..0x6E0 inclusive */
} nuccAppShaderParam;
#pragma pack(pop)

static_assert(offsetof(nuccAppShaderParam, _unk_0x000)        == 0x000, "nuccAppShaderParam._unk_0x000");
static_assert(offsetof(nuccAppShaderParam, field_0x190)       == 0x190, "nuccAppShaderParam.field_0x190");
static_assert(offsetof(nuccAppShaderParam, shadowProjMatrix0) == 0x1A0, "nuccAppShaderParam.shadowProjMatrix0");
static_assert(offsetof(nuccAppShaderParam, shadowProjMatrix1) == 0x1E0, "nuccAppShaderParam.shadowProjMatrix1");
static_assert(offsetof(nuccAppShaderParam, shadowProjMatrix2) == 0x220, "nuccAppShaderParam.shadowProjMatrix2");
static_assert(offsetof(nuccAppShaderParam, _gap_0x260)        == 0x260, "nuccAppShaderParam._gap_0x260");
static_assert(offsetof(nuccAppShaderParam, viewProjMatrix)    == 0x2E0, "nuccAppShaderParam.viewProjMatrix");
static_assert(offsetof(nuccAppShaderParam, _gap_0x320)        == 0x320, "nuccAppShaderParam._gap_0x320");
static_assert(offsetof(nuccAppShaderParam, zeroedRegion)      == 0x440, "nuccAppShaderParam.zeroedRegion");

#endif /* CMN44_H */
