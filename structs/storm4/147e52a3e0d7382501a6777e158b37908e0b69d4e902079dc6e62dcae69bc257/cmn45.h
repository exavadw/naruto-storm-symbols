/* cmn45.h — struct group cmn45 for build s4 (NSUNS4_release.exe)
 * INFERRED from static decompilation. Not CONFIRMED by runtime trace.
 * Own-game names only (Storm 4 symbols/strings). PC x64 offsets only.
 * Build: s4 /NSUNS4_release.exe-75912b
 */
#ifndef CMN45_S4_H
#define CMN45_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccBinStreamReader
 * Size: >= 0x2C (dtor zeroes through offset 0x28; Read accesses param_1[10]=0x28)
 * Vtable: none observed (no vptr in ctor, dtor or Read)
 * Evidence: ctor@0xA72C20, dtor@0xA72C40, Read@0xA72CD0
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamReader {
    uint32_t position;          /* 0x00: stream read position (*param_1 += uVar3) */
    uint8_t  _pad_04[4];        /* 0x04: padding */
    void    *buffer_ptr;        /* 0x08: current buffer pointer (param_1+2 as void**) */
    uint32_t bytes_available;   /* 0x10: bytes remaining in buffer (param_1[4]) */
    uint8_t  _pad_14[4];        /* 0x14: padding */
    void    *stream_obj;        /* 0x18: underlying stream object ptr (param_1+6 as longlong**) */
    uint64_t sync_object;       /* 0x20: mutex/critsec handle (param_1+8 as undefined8) */
    int32_t  abort_flag;        /* 0x28: cancel/abort flag (param_1[10]) */
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
 * Vtable: PTR_FUN_14110ce20 at offset 0x00
 * Evidence: ctor@0xA72F10, dtor@0xA72F40, Write@0xA73100, Open@0xA72F90
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriter {
    void    *vtable;            /* 0x00: vtable ptr (PTR_FUN_14110ce20) */
    uint32_t write_position;    /* 0x08: total bytes written (param_1+1 low4, Write: *(int*)(param_1+8)) */
    uint8_t  _pad_0c[4];        /* 0x0c: padding */
    void    *buffer_ptr;        /* 0x10: current write buffer pointer (param_1[2] / *(longlong*)(param_1+0x10)) */
    uint32_t bytes_available;   /* 0x18: bytes remaining in buffer (*(uint*)(param_1+0x18)) */
    uint8_t  _pad_1c[4];        /* 0x1c: padding */
    void    *stream_obj;        /* 0x20: underlying stream object (param_1[4], Open writes here) */
    uint64_t sync_object;       /* 0x28: critsec/mutex handle (param_1[5]) */
    uint32_t sync_flag;         /* 0x30: synchronization flag (low4 of param_1+6) */
} nuccBinStreamWriter;

static_assert(offsetof(nuccBinStreamWriter, vtable) == 0x00, "nuccBinStreamWriter.vtable");
static_assert(offsetof(nuccBinStreamWriter, write_position) == 0x08, "nuccBinStreamWriter.write_position");
static_assert(offsetof(nuccBinStreamWriter, buffer_ptr) == 0x10, "nuccBinStreamWriter.buffer_ptr");
static_assert(offsetof(nuccBinStreamWriter, bytes_available) == 0x18, "nuccBinStreamWriter.bytes_available");
static_assert(offsetof(nuccBinStreamWriter, stream_obj) == 0x20, "nuccBinStreamWriter.stream_obj");
static_assert(offsetof(nuccBinStreamWriter, sync_object) == 0x28, "nuccBinStreamWriter.sync_object");
static_assert(offsetof(nuccBinStreamWriter, sync_flag) == 0x30, "nuccBinStreamWriter.sync_flag");

/* ========================================================================
 * nuccBinStreamWriteFromFile
 * Size: >= 0x144 (OpenFile writes int at 0x140; ctor writes int at 0x3C)
 * Vtable: PTR_FUN_14110ce40 at offset 0x00 (overrides base writer vtable)
 * Inherits: nuccBinStreamWriter base (0x00–0x33)
 * Evidence: ctor@0xA732A0, OpenFile@0xA73360, Write@0xA734E0, state_surface (0x3C, 0x140)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBinStreamWriteFromFile {
    /* --- inherited nuccBinStreamWriter base (0x00–0x33) --- */
    void    *vtable;            /* 0x00: vtable ptr (PTR_FUN_14110ce40) */
    uint32_t write_position;    /* 0x08: total bytes written (base) */
    uint8_t  _pad_0c[4];        /* 0x0c: padding */
    void    *buffer_ptr;        /* 0x10: current write buffer pointer (base) */
    uint32_t bytes_available;   /* 0x18: bytes remaining in buffer (base) */
    uint8_t  _pad_1c[4];        /* 0x1c: padding */
    void    *stream_obj;        /* 0x20: underlying stream object (base) */
    uint64_t sync_object;       /* 0x28: critsec/mutex handle (base) */
    uint32_t sync_flag;         /* 0x30: synchronization flag (base) */
    /* --- derived fields --- */
    int32_t  cri_file_handle;   /* 0x34: initialized to -1 (0xffffffff) by ctor */
    uint32_t field_38;          /* 0x38: set to -1 in OpenFile, unknown purpose */
    uint32_t file_size;         /* 0x3C: file size from GetFileSize (state_surface confirmed) */
    char     filename[0x100];   /* 0x40: filename buffer (memset+strncpy in OpenFile, 256 bytes) */
    uint32_t cri_load_handle;   /* 0x140: CRI load request handle (state_surface confirmed) */
} nuccBinStreamWriteFromFile;

static_assert(offsetof(nuccBinStreamWriteFromFile, vtable) == 0x00, "nuccBinStreamWriteFromFile.vtable");
static_assert(offsetof(nuccBinStreamWriteFromFile, write_position) == 0x08, "nuccBinStreamWriteFromFile.write_position");
static_assert(offsetof(nuccBinStreamWriteFromFile, buffer_ptr) == 0x10, "nuccBinStreamWriteFromFile.buffer_ptr");
static_assert(offsetof(nuccBinStreamWriteFromFile, bytes_available) == 0x18, "nuccBinStreamWriteFromFile.bytes_available");
static_assert(offsetof(nuccBinStreamWriteFromFile, stream_obj) == 0x20, "nuccBinStreamWriteFromFile.stream_obj");
static_assert(offsetof(nuccBinStreamWriteFromFile, sync_object) == 0x28, "nuccBinStreamWriteFromFile.sync_object");
static_assert(offsetof(nuccBinStreamWriteFromFile, sync_flag) == 0x30, "nuccBinStreamWriteFromFile.sync_flag");
static_assert(offsetof(nuccBinStreamWriteFromFile, cri_file_handle) == 0x34, "nuccBinStreamWriteFromFile.cri_file_handle");
static_assert(offsetof(nuccBinStreamWriteFromFile, field_38) == 0x38, "nuccBinStreamWriteFromFile.field_38");
static_assert(offsetof(nuccBinStreamWriteFromFile, file_size) == 0x3C, "nuccBinStreamWriteFromFile.file_size");
static_assert(offsetof(nuccBinStreamWriteFromFile, filename) == 0x40, "nuccBinStreamWriteFromFile.filename");
static_assert(offsetof(nuccBinStreamWriteFromFile, cri_load_handle) == 0x140, "nuccBinStreamWriteFromFile.cri_load_handle");

/* ========================================================================
 * nuccBoundingBox
 * Size: 0x18 (Set writes param_1[0..2] = 3 × undefined8 = 24 bytes)
 * Vtable: none (no vptr in any ctor)
 * Wraps MathGeoAABB internally (two Vector3 min/max packed into 3 uint64 slots)
 * Evidence: Set@0xA33090, ctor@0xA32FB0
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccBoundingBox {
    uint64_t data_00;           /* 0x00: first 8 bytes of AABB */
    uint64_t data_08;           /* 0x08: second 8 bytes */
    uint64_t data_10;           /* 0x10: third 8 bytes */
} nuccBoundingBox;

static_assert(offsetof(nuccBoundingBox, data_00) == 0x00, "nuccBoundingBox.data_00");
static_assert(offsetof(nuccBoundingBox, data_08) == 0x08, "nuccBoundingBox.data_08");
static_assert(offsetof(nuccBoundingBox, data_10) == 0x10, "nuccBoundingBox.data_10");

/* ========================================================================
 * nuccCamera
 * Size: >= 0x148 (ctor@0x5AF894 writes param_1[0x28] = offset 0x140;
 *        main ctor@0xA26E20 writes through right_z@0x9C + BlockAllocator base)
 * Vtable: PTR_FUN_1410075d8 at offset 0x00 (from dtor@0xA26F30);
 *         alternate vtable PTR_FUN_141065440 in simple ctor@0x5AF894
 * Layout: vtable → gap(BlockAllocator base) → width/height → Matrix44_MathGeo(0x40) → 4×Vector3
 * Evidence: dtor@0xA26F30, Init@0xA26FD0, ctors@0xA26E20/0xA26EC0/0x5AF894, state_surface
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCamera {
    void    *vtable;            /* 0x00: vtable ptr (PTR_FUN_1410075d8 or PTR_FUN_141065440) */
    uint8_t  _pad_08[0x20];     /* 0x08: gap (BlockAllocator base + ctor zeroing) */
    uint32_t width;             /* 0x28: viewport width (Init writes param_2) */
    uint32_t height;            /* 0x2C: viewport height (Init writes param_3) */
    uint8_t  matrix44[0x40];    /* 0x30: Nucc::Matrix44_MathGeo (identity in Init) */
    uint64_t view_pos_xy;       /* 0x70: view position XY (Vector3, Init zero) */
    uint32_t view_pos_z;        /* 0x78: view position Z component */
    uint64_t look_at_xy;        /* 0x7C: look-at direction XY (Vector3, Init zero) */
    uint32_t look_at_z;         /* 0x84: look-at direction Z component */
    uint64_t up_xy;             /* 0x88: up vector XY (Vector3, Init zAxis) */
    uint32_t up_z;              /* 0x90: up vector Z component */
    uint64_t right_xy;          /* 0x94: right vector XY (Vector3, Init xAxis) */
    uint32_t right_z;           /* 0x9C: right vector Z component */
    uint8_t  _pad_a0[0x98];     /* 0xA0: gap (BlockAllocator internals / unused) */
    uint64_t field_138;         /* 0x138: zeroed in simple ctor@0x5AF894 (state_surface) */
    uint64_t field_140;         /* 0x140: zeroed in simple ctor@0x5AF894 (state_surface) */
} nuccCamera;

static_assert(offsetof(nuccCamera, vtable) == 0x00, "nuccCamera.vtable");
static_assert(offsetof(nuccCamera, width) == 0x28, "nuccCamera.width");
static_assert(offsetof(nuccCamera, height) == 0x2C, "nuccCamera.height");
static_assert(offsetof(nuccCamera, matrix44) == 0x30, "nuccCamera.matrix44");
static_assert(offsetof(nuccCamera, view_pos_xy) == 0x70, "nuccCamera.view_pos_xy");
static_assert(offsetof(nuccCamera, view_pos_z) == 0x78, "nuccCamera.view_pos_z");
static_assert(offsetof(nuccCamera, look_at_xy) == 0x7C, "nuccCamera.look_at_xy");
static_assert(offsetof(nuccCamera, look_at_z) == 0x84, "nuccCamera.look_at_z");
static_assert(offsetof(nuccCamera, up_xy) == 0x88, "nuccCamera.up_xy");
static_assert(offsetof(nuccCamera, up_z) == 0x90, "nuccCamera.up_z");
static_assert(offsetof(nuccCamera, right_xy) == 0x94, "nuccCamera.right_xy");
static_assert(offsetof(nuccCamera, right_z) == 0x9C, "nuccCamera.right_z");
static_assert(offsetof(nuccCamera, field_138) == 0x138, "nuccCamera.field_138");
static_assert(offsetof(nuccCamera, field_140) == 0x140, "nuccCamera.field_140");

/* ========================================================================
 * nuccCdHitElp
 * Size: >= 0x10C (Reset reads/writes through flags@0x108; AddInvHitTarget uses +0xe0)
 * Vtable: sub-object vtable at offset 0xC8 (BlockAllocator embedded)
 * Contains three embedded Matrix44_MathGeo at +0x00, +0x40, +0x80
 * Evidence: Reset@0xAA06E0, CalcHit@0xA9FB10, AddInvHitTarget@0xA9FA30
 * Note: no standalone ctor symbol found in s4; layout inferred from Reset + CalcHit + AddInvHitTarget
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdHitElp {
    uint8_t  matrix44_00[0x40]; /* 0x00: Nucc::Matrix44_MathGeo #1 (world transform) */
    uint8_t  matrix44_40[0x40]; /* 0x40: Nucc::Matrix44_MathGeo #2 (inverse transform) */
    uint8_t  matrix44_80[0x40]; /* 0x80: Nucc::Matrix44_MathGeo #3 (local transform) */
    uint64_t field_c0;          /* 0xC0: source matrix ptr or null (Reset checks != 0) */
    void    *vtable_sub;        /* 0xC8: BlockAllocator vtable (sub-object base) */
    uint8_t  _pad_d0[0x10];     /* 0xD0: gap (BlockAllocator internals) */
    void    *inv_hit_list;      /* 0xE0: linked list head for inverse hit targets (AddInvHitTarget) */
    uint64_t field_e8;          /* 0xE8: unknown (zeroed/unused in analyzed methods) */
    uint64_t field_f0;          /* 0xF0: unknown */
    uint16_t field_f8;          /* 0xF8: unknown */
    uint8_t  _pad_fa[6];        /* 0xFA: padding */
    uint64_t field_100;         /* 0x100: unknown */
    uint8_t  flags_108;         /* 0x108: bitfield (|= 1 in CalcHit, &= 0xFE in Reset) */
    uint8_t  _pad_109[3];       /* 0x109: padding */
} nuccCdHitElp;

static_assert(offsetof(nuccCdHitElp, matrix44_00) == 0x00, "nuccCdHitElp.matrix44_00");
static_assert(offsetof(nuccCdHitElp, matrix44_40) == 0x40, "nuccCdHitElp.matrix44_40");
static_assert(offsetof(nuccCdHitElp, matrix44_80) == 0x80, "nuccCdHitElp.matrix44_80");
static_assert(offsetof(nuccCdHitElp, field_c0) == 0xC0, "nuccCdHitElp.field_c0");
static_assert(offsetof(nuccCdHitElp, vtable_sub) == 0xC8, "nuccCdHitElp.vtable_sub");
static_assert(offsetof(nuccCdHitElp, inv_hit_list) == 0xE0, "nuccCdHitElp.inv_hit_list");
static_assert(offsetof(nuccCdHitElp, field_e8) == 0xE8, "nuccCdHitElp.field_e8");
static_assert(offsetof(nuccCdHitElp, field_f0) == 0xF0, "nuccCdHitElp.field_f0");
static_assert(offsetof(nuccCdHitElp, field_f8) == 0xF8, "nuccCdHitElp.field_f8");
static_assert(offsetof(nuccCdHitElp, field_100) == 0x100, "nuccCdHitElp.field_100");
static_assert(offsetof(nuccCdHitElp, flags_108) == 0x108, "nuccCdHitElp.flags_108");

#endif /* CMN45_S4_H */