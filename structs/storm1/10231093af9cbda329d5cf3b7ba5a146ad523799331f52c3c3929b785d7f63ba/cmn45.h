/* cmn45.h — struct group cmn45 for build s1 (NSUNS1.exe)
 * INFERRED from static decompilation. Not CONFIRMED by runtime trace.
 * Own-game names only (Storm 1 sources). PC x64 offsets only.
 */
#ifndef CMN45_S1_H
#define CMN45_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccBinStreamReader
 * Size: >= 0x2C (proven by ctor zeroing through offset 0x28 + int at 0x28)
 * Vtable: none observed (no vptr in ctor; Open uses param_2->vfunc)
 * Evidence: ctor@0x4837F0, Read@0x4838B0, Seek@0x483A60, IsEnd@0x483860, Open@0x4838A0
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamReader {
    uint32_t position;              /* 0x00: stream read position (int* param_1[0]) */
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
 * Size: >= 0x34 (proven by ctor writing through offset 0x30)
 * Vtable: PTR_FUN_140736da0 at offset 0x00
 * Evidence: ctor@0x483AF0
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriter {
    void *vtable;                   /* 0x00: vtable ptr (PTR_FUN_140736da0) */
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
 * Size: unknown, >= 0x144 (state_surface found w at 0x140 from ctor)
 * Vtable: not confirmed in this build's decompile
 * Evidence: state_surface, ctor@0x483E80
 * Note: Only 2 fields identified via state_surface; layout largely opaque.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriteFromFile {
    uint8_t unknown_00[0x3C];       /* 0x00: unknown */
    uint32_t field_3c;              /* 0x3C: written by ctor (state_surface) */
    uint8_t unknown_40[0x100];      /* 0x40: unknown gap */
    uint32_t field_140;             /* 0x140: written by ctor (state_surface) */
} nuccBinStreamWriteFromFile;

static_assert(offsetof(nuccBinStreamWriteFromFile, field_3c) == 0x3C, "nuccBinStreamWriteFromFile.field_3c");
static_assert(offsetof(nuccBinStreamWriteFromFile, field_140) == 0x140, "nuccBinStreamWriteFromFile.field_140");

/* ========================================================================
 * nuccBoundingBox
 * Size: 0x18 (3 × undefined8 = 24 bytes, proven by Set writing param_1[0..2])
 * Vtable: none (no vptr in any ctor)
 * Evidence: Set@0x4C9AD0, SetUnion@0x4C9BD0, ctor@0x4C99F0
 * Three floats min, three floats max stored as two vec3 (or min/max as uint64 pairs + extra)
 * Actually: *param_1 = 8 bytes, param_1[1] = 8 bytes, param_1[2] = 8 bytes = 0x18 total
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBoundingBox {
    uint64_t data_00;               /* 0x00: first 8 bytes of bbox (min.xyz packed or similar) */
    uint64_t data_08;               /* 0x08: second 8 bytes */
    uint64_t data_10;               /* 0x10: third 8 bytes */
} nuccBoundingBox;

static_assert(offsetof(nuccBoundingBox, data_00) == 0x00, "nuccBoundingBox.data_00");
static_assert(offsetof(nuccBoundingBox, data_08) == 0x08, "nuccBoundingBox.data_08");
static_assert(offsetof(nuccBoundingBox, data_10) == 0x10, "nuccBoundingBox.data_10");

/* ========================================================================
 * nuccCamera
 * Size: >= 0xA0 (Init writes through offset 0x9C; ctor inits sub-objects at +0x30,+0x48,+0x58,+0x88,+0x94)
 * Vtable: PTR_FUN_1406584e8 at offset 0x00
 * Evidence: ctor@0x4878E0, Init@0x487A50, state_surface (offsets 0x70,0x7C,0x88,0x94)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCamera {
    void *vtable;                   /* 0x00: vtable ptr (PTR_FUN_1406584e8) */
    uint8_t _pad_08[0x20];          /* 0x08: gap (ctor sets param_1[3]=0 at 0x18, param_1[4]=0 at 0x20) */
    uint32_t width;                 /* 0x28: viewport width (Init writes param_2) */
    uint32_t height;                /* 0x2C: viewport height (Init writes param_3) */
    uint8_t subobj_30[0x18];        /* 0x30: sub-object initialized by FUN_140480ba0 */
    uint8_t _pad_48[0x28];          /* 0x48: gap */
    uint64_t view_pos_x;            /* 0x70: view position X (Init, state_surface read) */
    uint32_t view_pos_z;            /* 0x78: view position Z component */
    uint64_t look_at_x;             /* 0x7C: look-at direction X (Init, state_surface read) */
    uint32_t look_at_z;             /* 0x84: look-at direction Z component */
    uint64_t up_x;                  /* 0x88: up vector X (Init, state_surface read) */
    uint32_t up_z;                  /* 0x90: up vector Z component */
    uint64_t right_x;               /* 0x94: right vector X (Init, state_surface read) */
    uint32_t right_z;               /* 0x9C: right vector Z component */
} nuccCamera;

static_assert(offsetof(nuccCamera, vtable) == 0x00, "nuccCamera.vtable");
static_assert(offsetof(nuccCamera, width) == 0x28, "nuccCamera.width");
static_assert(offsetof(nuccCamera, height) == 0x2C, "nuccCamera.height");
static_assert(offsetof(nuccCamera, subobj_30) == 0x30, "nuccCamera.subobj_30");
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
 * Vtable: PTR_FUN_140736f28 at offset 0xC8 (embedded sub-object at +0xC8 has its own vtable)
 * Evidence: ctor@0x520990
 * Contains three embedded sub-objects at +0x00, +0x40, +0x80 (each initialized by FUN_140480da0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdHitElp {
    uint8_t subobj_00[0x40];        /* 0x00: sub-object #1 (FUN_140480da0) */
    uint8_t subobj_40[0x40];        /* 0x40: sub-object #2 (FUN_140480da0) */
    uint8_t subobj_80[0x40];        /* 0x80: sub-object #3 (FUN_140480da0 + FUN_140480e00 + FUN_140481e90) */
    uint64_t field_c0;              /* 0xC0: set from ctor param_2 */
    void *vtable_sub;               /* 0xC8: sub-object vtable (PTR_FUN_140736f28) */
    uint8_t _pad_d0[0x10];          /* 0xD0: gap */
    uint64_t field_e0;              /* 0xE0: zeroed in ctor */
    uint64_t field_e8;              /* 0xE8: zeroed in ctor */
    uint64_t field_f0;              /* 0xF0: zeroed in ctor */
    uint16_t field_f8;              /* 0xF8: zeroed in ctor */
    uint8_t _pad_fa[6];             /* 0xFA: padding */
    uint64_t field_100;             /* 0x100: zeroed in ctor */
    uint8_t flags_108;              /* 0x108: bitfield (AND 0xFC in ctor) */
    uint8_t _pad_109[3];            /* 0x109: padding */
} nuccCdHitElp;

static_assert(offsetof(nuccCdHitElp, subobj_00) == 0x00, "nuccCdHitElp.subobj_00");
static_assert(offsetof(nuccCdHitElp, subobj_40) == 0x40, "nuccCdHitElp.subobj_40");
static_assert(offsetof(nuccCdHitElp, subobj_80) == 0x80, "nuccCdHitElp.subobj_80");
static_assert(offsetof(nuccCdHitElp, field_c0) == 0xC0, "nuccCdHitElp.field_c0");
static_assert(offsetof(nuccCdHitElp, vtable_sub) == 0xC8, "nuccCdHitElp.vtable_sub");
static_assert(offsetof(nuccCdHitElp, field_e0) == 0xE0, "nuccCdHitElp.field_e0");
static_assert(offsetof(nuccCdHitElp, field_e8) == 0xE8, "nuccCdHitElp.field_e8");
static_assert(offsetof(nuccCdHitElp, field_f0) == 0xF0, "nuccCdHitElp.field_f0");
static_assert(offsetof(nuccCdHitElp, field_f8) == 0xF8, "nuccCdHitElp.field_f8");
static_assert(offsetof(nuccCdHitElp, field_100) == 0x100, "nuccCdHitElp.field_100");
static_assert(offsetof(nuccCdHitElp, flags_108) == 0x108, "nuccCdHitElp.flags_108");

#endif /* CMN45_S1_H */