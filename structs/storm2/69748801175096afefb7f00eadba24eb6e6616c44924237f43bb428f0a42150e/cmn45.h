/* cmn45.h — struct group cmn45 for build s2 (NSUNS2.exe)
 * INFERRED from static decompilation. Not CONFIRMED by runtime trace.
 * Own-game names only (Storm 2 sources). PC x64 offsets only.
 */
#ifndef CMN45_S2_H
#define CMN45_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccBinStreamReader
 * Size: >= 0x2C (dtor zeroes through offset 0x20; Read accesses param_1[10]=0x28)
 * Vtable: none observed (no vptr in dtor or Read)
 * Evidence: dtor@0x5F79B0, Read@0x5F7A40
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamReader {
    uint32_t position;              /* 0x00: stream read position (*param_1 += uVar3) */
    uint8_t _pad_04[4];             /* 0x04: padding */
    void *buffer_ptr;               /* 0x08: current buffer pointer (param_1+2 as void**) */
    uint32_t bytes_available;       /* 0x10: bytes remaining in buffer (param_1[4]) */
    uint8_t _pad_14[4];             /* 0x14: padding */
    void *stream_obj;               /* 0x18: underlying stream object ptr (param_1+6 as longlong**) */
    uint64_t sync_object;           /* 0x20: mutex/sync handle (param_1+8 as undefined8) */
    int32_t abort_flag;             /* 0x28: cancel/abort flag (param_1[10]) */
} nuccBinStreamReader;

static_assert(offsetof(nuccBinStreamReader, position) == 0x00, "nuccBinStreamReader.position");
static_assert(offsetof(nuccBinStreamReader, buffer_ptr) == 0x08, "nuccBinStreamReader.buffer_ptr");
static_assert(offsetof(nuccBinStreamReader, bytes_available) == 0x10, "nuccBinStreamReader.bytes_available");
static_assert(offsetof(nuccBinStreamReader, stream_obj) == 0x18, "nuccBinStreamReader.stream_obj");
static_assert(offsetof(nuccBinStreamReader, sync_object) == 0x20, "nuccBinStreamReader.sync_object");
static_assert(offsetof(nuccBinStreamReader, abort_flag) == 0x28, "nuccBinStreamReader.abort_flag");

/* ========================================================================
 * nuccBinStreamWriter
 * Size: >= 0x34 (ctor writes through offset 0x30)
 * Vtable: PTR_FUN_140898398 at offset 0x00
 * Evidence: ctor@0x5F7C80
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriter {
    void *vtable;                   /* 0x00: vtable ptr (PTR_FUN_140898398) */
    uint32_t field_08;              /* 0x08: initialized to 0 (low 4 bytes of param_1+1) */
    uint8_t _pad_0c[4];             /* 0x0c: padding */
    uint64_t field_10;              /* 0x10: initialized to 0 (param_1[2]) */
    uint32_t field_18;              /* 0x18: initialized to 0 (low 4 bytes of param_1+3) */
    uint8_t _pad_1c[4];             /* 0x1c: padding */
    uint64_t field_20;              /* 0x20: initialized to 0 (param_1[4]) */
    uint64_t field_28;              /* 0x28: initialized to 0 (param_1[5]) */
    uint32_t field_30;              /* 0x30: initialized to 0 (low 4 bytes of param_1+6) */
} nuccBinStreamWriter;

static_assert(offsetof(nuccBinStreamWriter, vtable) == 0x00, "nuccBinStreamWriter.vtable");
static_assert(offsetof(nuccBinStreamWriter, field_08) == 0x08, "nuccBinStreamWriter.field_08");
static_assert(offsetof(nuccBinStreamWriter, field_10) == 0x10, "nuccBinStreamWriter.field_10");
static_assert(offsetof(nuccBinStreamWriter, field_18) == 0x18, "nuccBinStreamWriter.field_18");
static_assert(offsetof(nuccBinStreamWriter, field_20) == 0x20, "nuccBinStreamWriter.field_20");
static_assert(offsetof(nuccBinStreamWriter, field_28) == 0x28, "nuccBinStreamWriter.field_28");
static_assert(offsetof(nuccBinStreamWriter, field_30) == 0x30, "nuccBinStreamWriter.field_30");

/* ========================================================================
 * nuccBinStreamWriteFromFile
 * Size: >= 0x144 (ctor writes int at 0x140 via param_1+0x28 as undefined4*)
 * Vtable: PTR_FUN_1408983b8 at offset 0x00 (overrides base writer vtable)
 * Inherits: nuccBinStreamWriter base (0x00–0x33)
 * Evidence: ctor@0x5F8010, state_surface (fields at 0x3C, 0x140)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriteFromFile {
    /* --- inherited nuccBinStreamWriter base (0x00–0x33) --- */
    void *vtable;                   /* 0x00: vtable ptr (PTR_FUN_1408983b8) */
    uint32_t base_field_08;         /* 0x08: from base ctor */
    uint8_t _pad_0c[4];             /* 0x0c: padding */
    uint64_t base_field_10;         /* 0x10: from base ctor */
    uint32_t base_field_18;         /* 0x18: from base ctor */
    uint8_t _pad_1c[4];             /* 0x1c: padding */
    uint64_t base_field_20;         /* 0x20: from base ctor */
    uint64_t base_field_28;         /* 0x28: from base ctor */
    uint32_t base_field_30;         /* 0x30: from base ctor */
    /* --- derived fields --- */
    int32_t field_34;               /* 0x34: initialized to -1 (0xffffffff) by ctor param_1+7 */
    uint32_t field_38;              /* 0x38: gap before 0x3C write */
    uint32_t field_3c;              /* 0x3C: initialized to 0 (state_surface confirmed) */
    uint8_t unknown_40[0x100];      /* 0x40: unknown gap (no accesses found) */
    uint32_t field_140;             /* 0x140: initialized to 0 (state_surface confirmed) */
} nuccBinStreamWriteFromFile;

static_assert(offsetof(nuccBinStreamWriteFromFile, vtable) == 0x00, "nuccBinStreamWriteFromFile.vtable");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_08) == 0x08, "nuccBinStreamWriteFromFile.base_field_08");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_10) == 0x10, "nuccBinStreamWriteFromFile.base_field_10");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_18) == 0x18, "nuccBinStreamWriteFromFile.base_field_18");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_20) == 0x20, "nuccBinStreamWriteFromFile.base_field_20");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_28) == 0x28, "nuccBinStreamWriteFromFile.base_field_28");
static_assert(offsetof(nuccBinStreamWriteFromFile, base_field_30) == 0x30, "nuccBinStreamWriteFromFile.base_field_30");
static_assert(offsetof(nuccBinStreamWriteFromFile, field_34) == 0x34, "nuccBinStreamWriteFromFile.field_34");
static_assert(offsetof(nuccBinStreamWriteFromFile, field_3c) == 0x3C, "nuccBinStreamWriteFromFile.field_3c");
static_assert(offsetof(nuccBinStreamWriteFromFile, field_140) == 0x140, "nuccBinStreamWriteFromFile.field_140");

/* ========================================================================
 * nuccBoundingBox
 * Size: 0x18 (Set writes param_1[0..2] = 3 × undefined8 = 24 bytes)
 * Vtable: none (no vptr in any ctor)
 * Wraps MathGeoAABB internally (two Vector3 min/max packed into 3 uint64 slots)
 * Evidence: Set@0x5C60D0, ctor@0x5C5FF0
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBoundingBox {
    uint64_t data_00;               /* 0x00: first 8 bytes of AABB */
    uint64_t data_08;               /* 0x08: second 8 bytes */
    uint64_t data_10;               /* 0x10: third 8 bytes */
} nuccBoundingBox;

static_assert(offsetof(nuccBoundingBox, data_00) == 0x00, "nuccBoundingBox.data_00");
static_assert(offsetof(nuccBoundingBox, data_08) == 0x08, "nuccBoundingBox.data_08");
static_assert(offsetof(nuccBoundingBox, data_10) == 0x10, "nuccBoundingBox.data_10");

/* ========================================================================
 * nuccCamera
 * Size: >= 0xA0 (Init writes through offset 0x9C)
 * Vtable: PTR_FUN_140831290 at offset 0x00
 * Layout: BlockAllocator base → vtable → width/height → Matrix44_MathGeo(0x40) → 4×Vector3
 * Evidence: ctor@0x59D6D0, Init@0x59D870, state_surface (offsets 0x70,0x7C,0x88,0x94)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCamera {
    void *vtable;                   /* 0x00: vtable ptr (PTR_FUN_140831290) */
    uint8_t _pad_08[0x20];          /* 0x08: gap (BlockAllocator base + ctor zeroing) */
    uint32_t width;                 /* 0x28: viewport width (Init writes param_2) */
    uint32_t height;                /* 0x2C: viewport height (Init writes param_3) */
    uint8_t matrix44[0x40];         /* 0x30: Nucc::Matrix44_MathGeo (identity in Init) */
    uint64_t view_pos_x;            /* 0x70: view position XY (Vector3, Init zero) */
    uint32_t view_pos_z;            /* 0x78: view position Z component */
    uint64_t look_at_x;             /* 0x7C: look-at direction XY (Vector3, Init zero) */
    uint32_t look_at_z;             /* 0x84: look-at direction Z component */
    uint64_t up_x;                  /* 0x88: up vector XY (Vector3, Init zAxis) */
    uint32_t up_z;                  /* 0x90: up vector Z component */
    uint64_t right_x;               /* 0x94: right vector XY (Vector3, Init xAxis) */
    uint32_t right_z;               /* 0x9C: right vector Z component */
} nuccCamera;

static_assert(offsetof(nuccCamera, vtable) == 0x00, "nuccCamera.vtable");
static_assert(offsetof(nuccCamera, width) == 0x28, "nuccCamera.width");
static_assert(offsetof(nuccCamera, height) == 0x2C, "nuccCamera.height");
static_assert(offsetof(nuccCamera, matrix44) == 0x30, "nuccCamera.matrix44");
static_assert(offsetof(nuccCamera, view_pos_x) == 0x70, "nuccCamera.view_pos_x");
static_assert(offsetof(nuccCamera, view_pos_z) == 0x78, "nuccCamera.view_pos_z");
static_assert(offsetof(nuccCamera, look_at_x) == 0x7C, "nuccCamera.look_at_x");
static_assert(offsetof(nuccCamera, look_at_z) == 0x84, "nuccCamera.look_at_z");
static_assert(offsetof(nuccCamera, up_x) == 0x88, "nuccCamera.up_x");
static_assert(offsetof(nuccCamera, up_z) == 0x90, "nuccCamera.up_z");
static_assert(offsetof(nuccCamera, right_x) == 0x94, "nuccCamera.right_x");
static_assert(offsetof(nuccCamera, right_z) == 0x9C, "nuccCamera.right_z");

/* ========================================================================
 * nuccCdHitElp
 * Size: >= 0x10C (ctor writes through offset 0x108)
 * Vtable: PTR_FUN_1408910b8 at offset 0xC8 (embedded BlockAllocator sub-object)
 * Contains three embedded Matrix44_MathGeo at +0x00, +0x40, +0x80
 * Evidence: ctor@0x61CE30
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdHitElp {
    uint8_t matrix44_00[0x40];      /* 0x00: Nucc::Matrix44_MathGeo #1 */
    uint8_t matrix44_40[0x40];      /* 0x40: Nucc::Matrix44_MathGeo #2 */
    uint8_t matrix44_80[0x40];      /* 0x80: Nucc::Matrix44_MathGeo #3 */
    uint64_t field_c0;              /* 0xC0: set from ctor param_2 */
    void *vtable_sub;               /* 0xC8: BlockAllocator vtable (PTR_FUN_1408910b8) */
    uint8_t _pad_d0[0x10];          /* 0xD0: gap (BlockAllocator internals) */
    uint64_t field_e0;              /* 0xE0: zeroed in ctor */
    uint64_t field_e8;              /* 0xE8: zeroed in ctor */
    uint64_t field_f0;              /* 0xF0: zeroed in ctor */
    uint16_t field_f8;              /* 0xF8: zeroed in ctor */
    uint8_t _pad_fa[6];             /* 0xFA: padding */
    uint64_t field_100;             /* 0x100: zeroed in ctor */
    uint8_t flags_108;              /* 0x108: bitfield (AND 0xFC in ctor) */
    uint8_t _pad_109[3];            /* 0x109: padding */
} nuccCdHitElp;

static_assert(offsetof(nuccCdHitElp, matrix44_00) == 0x00, "nuccCdHitElp.matrix44_00");
static_assert(offsetof(nuccCdHitElp, matrix44_40) == 0x40, "nuccCdHitElp.matrix44_40");
static_assert(offsetof(nuccCdHitElp, matrix44_80) == 0x80, "nuccCdHitElp.matrix44_80");
static_assert(offsetof(nuccCdHitElp, field_c0) == 0xC0, "nuccCdHitElp.field_c0");
static_assert(offsetof(nuccCdHitElp, vtable_sub) == 0xC8, "nuccCdHitElp.vtable_sub");
static_assert(offsetof(nuccCdHitElp, field_e0) == 0xE0, "nuccCdHitElp.field_e0");
static_assert(offsetof(nuccCdHitElp, field_e8) == 0xE8, "nuccCdHitElp.field_e8");
static_assert(offsetof(nuccCdHitElp, field_f0) == 0xF0, "nuccCdHitElp.field_f0");
static_assert(offsetof(nuccCdHitElp, field_f8) == 0xF8, "nuccCdHitElp.field_f8");
static_assert(offsetof(nuccCdHitElp, field_100) == 0x100, "nuccCdHitElp.field_100");
static_assert(offsetof(nuccCdHitElp, flags_108) == 0x108, "nuccCdHitElp.flags_108");

#endif /* CMN45_S2_H */