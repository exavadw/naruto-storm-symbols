/* cmn76.h — Storm 2 (s2) struct group cmn76
 * Generated from static analysis of NSUNS2.exe (sha256 697488011750...)
 * All layouts INFERRED from decompiled code; not runtime-confirmed.
 * OWN-GAME NAMES only (Storm 2 / ns2:: / Storm 2 strings/code).
 * PC OFFSETS ONLY — derived from x64 s2 decompiles.
 */
#ifndef CMN76_S2_H
#define CMN76_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ============================================================
 * nummRender
 * Global singleton (no heap ctor). Init at RVA 0x55E7F0.
 * Size proven >= 0x140 from Init loop: *(param_1 + 0x120..0x13C) = 0.
 * ============================================================ */
typedef struct __attribute__((packed)) nummRender {
    uint8_t _pad_0x00[0x14];          /* 0x00 */
    uint32_t field_0x14;              /* 0x14 — written by TLS::TLS */
    uint8_t _pad_0x18[0x04];          /* 0x18 */
    uint32_t field_0x1C;              /* 0x1C — written by TLS::TLS */
    uint8_t _pad_0x20[0x04];          /* 0x20 */
    uint32_t field_0x24;              /* 0x24 — written by TLS::TLS */
    uint8_t _pad_0x28[0x58];          /* 0x28 */
    uint8_t vsync_callback_thread[0x54]; /* 0x80 — VSyncCallbackThread embedded (0x80..0xD3) */
    uint32_t field_0xD4;              /* 0xD4 — set to 0 in Init */
    uint32_t refresh_rate;            /* 0xD8 — param_6 passed to Init */
    uint8_t _pad_0xDC[0x24];          /* 0xDC */
    void *event_handle;               /* 0x100 — CreateEventA handle ptr */
    void *critical_section;           /* 0x108 — critical section ptr, locked/unlocked in Init */
    uint8_t _pad_0x110[0x10];         /* 0x110 */
    uint32_t init_slots[8];           /* 0x120 — 8 uints zeroed in Init loop (0x120..0x13C) */
} nummRender;
/* size unknown, >= 0x140 */
static_assert(offsetof(nummRender, field_0x14) == 0x14, "nummRender.field_0x14");
static_assert(offsetof(nummRender, field_0x1C) == 0x1C, "nummRender.field_0x1C");
static_assert(offsetof(nummRender, field_0x24) == 0x24, "nummRender.field_0x24");
static_assert(offsetof(nummRender, vsync_callback_thread) == 0x80, "nummRender.vsync_callback_thread");
static_assert(offsetof(nummRender, field_0xD4) == 0xD4, "nummRender.field_0xD4");
static_assert(offsetof(nummRender, refresh_rate) == 0xD8, "nummRender.refresh_rate");
static_assert(offsetof(nummRender, event_handle) == 0x100, "nummRender.event_handle");
static_assert(offsetof(nummRender, critical_section) == 0x108, "nummRender.critical_section");
static_assert(offsetof(nummRender, init_slots) == 0x120, "nummRender.init_slots");

/* ============================================================
 * nummRender::TLS
 * Thread-local, stored at TLS_base + 0x160 (from nummThread::Construction).
 * Ctor at RVA 0x55D800. Size proven >= 0x28 (writes float at +0x14, byte at +0x1C, int at +0x24).
 * ============================================================ */
typedef struct __attribute__((packed)) nummRender_TLS {
    uint8_t _pad_0x00[0x14];          /* 0x00 */
    float float_0x14;                 /* 0x14 — set to 1.0f (0x3f800000) in ctor */
    uint8_t _pad_0x18[0x04];          /* 0x18 */
    uint8_t byte_0x1C;                /* 0x1C — set to 0 in ctor */
    uint8_t _pad_0x1D[0x03];          /* 0x1D */
    uint32_t int_0x20;                /* 0x20 — padding/unused between 0x1C and 0x24 */
    uint32_t int_0x24;                /* 0x24 — set to 1 in ctor */
} nummRender_TLS;
/* size unknown, >= 0x28 */
static_assert(offsetof(nummRender_TLS, float_0x14) == 0x14, "nummRender_TLS.float_0x14");
static_assert(offsetof(nummRender_TLS, byte_0x1C) == 0x1C, "nummRender_TLS.byte_0x1C");
static_assert(offsetof(nummRender_TLS, int_0x24) == 0x24, "nummRender_TLS.int_0x24");

/* ============================================================
 * nummRenderTextureManager::TLS
 * Thread-local, stored at TLS_base + 0x2998 (from nummThread::Construction).
 * Ctor at RVA 0x55BD00. Size proven >= 0xE0 (last write param_1[0x1b] = byte offset 0xD8).
 * param_1 is undefined8* so param_1[N] = byte offset N*8.
 * Self-pointer pattern at indices 3 (0x18), 9 (0x48), 0xf (0x78).
 * Three identical sub-blocks at 0x18..0x3F, 0x48..0x6F, 0x78..0x9F each with:
 *   self-ptr at +0x00, zero qword at +0x08, zero qword at +0x10,
 *   zero byte at +0x18, zero u32 at +0x1C
 * Followed by 8 zero qwords at 0xA0..0xD8.
 * ============================================================ */
typedef struct __attribute__((packed)) nummRenderTextureManager_TLS {
    uint64_t field_0x00;              /* 0x00 — zeroed (*param_1 = 0) */
    uint32_t field_0x08;              /* 0x08 — set to 7 (*(u32*)(param_1+1) = 7) */
    uint8_t _pad_0x0C[0x04];          /* 0x0C */
    uint64_t field_0x10;              /* 0x10 — zeroed (param_1[2] = 0, index 2) */
    void *self_ptr_0x18;              /* 0x18 — self-pointer (param_1+3, index 3) */
    uint64_t field_0x20;              /* 0x20 — zeroed then overwritten (param_1[4]) */
    uint64_t field_0x28;              /* 0x28 — zeroed (param_1[5]) */
    uint64_t field_0x30;              /* 0x30 — zeroed (param_1[6]) */
    uint8_t byte_0x38;                /* 0x38 — zeroed (*(u8*)(param_1+6), byte at index 6) */
    uint8_t _pad_0x39[0x03];          /* 0x39 */
    uint32_t field_0x3C;              /* 0x3C — zeroed (*(u32*)(param_1+7)) */
    uint64_t field_0x40;              /* 0x40 — zeroed (param_1[8], index 8 = 0x40) */
    void *self_ptr_0x48;              /* 0x48 — self-pointer (param_1+9, index 9) */
    uint64_t field_0x50;              /* 0x50 — overwritten with self-ptr (param_1[10]) */
    uint64_t field_0x58;              /* 0x58 — zeroed (param_1[0xb]) */
    uint64_t field_0x60;              /* 0x60 — zeroed (param_1[0xc]) */
    uint8_t byte_0x68;                /* 0x68 — zeroed (*(u8*)(param_1+0xc)) */
    uint8_t _pad_0x69[0x03];          /* 0x69 */
    uint32_t field_0x6C;              /* 0x6C — zeroed (*(u32*)(param_1+0xd)) */
    uint64_t field_0x70;              /* 0x70 — zeroed (param_1[0xe], index 0xe = 0x70) */
    void *self_ptr_0x78;              /* 0x78 — self-pointer (param_1+0xf, index 0xf) */
    uint64_t field_0x80;              /* 0x80 — zeroed (param_1[0x10]) */
    uint64_t field_0x88;              /* 0x88 — zeroed (param_1[0x11]) */
    uint8_t byte_0x90;                /* 0x90 — zeroed (*(u8*)(param_1+0x12)) */
    uint8_t _pad_0x91[0x03];          /* 0x91 */
    uint32_t field_0x94;              /* 0x94 — zeroed (*(u32*)(param_1+0x13)) */
    uint64_t field_0x98;              /* 0x98 — zeroed (param_1[0x13], WAIT: 0x13*8=0x98) */
    uint64_t field_0xA0;              /* 0xA0 — zeroed (param_1[0x14]) */
    uint64_t field_0xA8;              /* 0xA8 — zeroed (param_1[0x15]) */
    uint64_t field_0xB0;              /* 0xB0 — zeroed (param_1[0x16]) */
    uint64_t field_0xB8;              /* 0xB8 — zeroed (param_1[0x17]) */
    uint64_t field_0xC0;              /* 0xC0 — zeroed (param_1[0x18]) */
    uint64_t field_0xC8;              /* 0xC8 — zeroed (param_1[0x19]) */
    uint64_t field_0xD0;              /* 0xD0 — zeroed (param_1[0x1a]) */
    uint64_t field_0xD8;              /* 0xD8 — zeroed (param_1[0x1b], last write) */
} nummRenderTextureManager_TLS;
/* size unknown, >= 0xE0 */
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x00) == 0x00, "RTM_TLS.field_0x00");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x08) == 0x08, "RTM_TLS.field_0x08");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x10) == 0x10, "RTM_TLS.field_0x10");
static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x18) == 0x18, "RTM_TLS.self_ptr_0x18");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x20) == 0x20, "RTM_TLS.field_0x20");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x28) == 0x28, "RTM_TLS.field_0x28");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x30) == 0x30, "RTM_TLS.field_0x30");
static_assert(offsetof(nummRenderTextureManager_TLS, byte_0x38) == 0x38, "RTM_TLS.byte_0x38");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x3C) == 0x3C, "RTM_TLS.field_0x3C");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x40) == 0x40, "RTM_TLS.field_0x40");
static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x48) == 0x48, "RTM_TLS.self_ptr_0x48");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x50) == 0x50, "RTM_TLS.field_0x50");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x58) == 0x58, "RTM_TLS.field_0x58");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x60) == 0x60, "RTM_TLS.field_0x60");
static_assert(offsetof(nummRenderTextureManager_TLS, byte_0x68) == 0x68, "RTM_TLS.byte_0x68");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x6C) == 0x6C, "RTM_TLS.field_0x6C");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x70) == 0x70, "RTM_TLS.field_0x70");
static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x78) == 0x78, "RTM_TLS.self_ptr_0x78");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x80) == 0x80, "RTM_TLS.field_0x80");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x88) == 0x88, "RTM_TLS.field_0x88");
static_assert(offsetof(nummRenderTextureManager_TLS, byte_0x90) == 0x90, "RTM_TLS.byte_0x90");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x94) == 0x94, "RTM_TLS.field_0x94");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x98) == 0x98, "RTM_TLS.field_0x98");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xA0) == 0xA0, "RTM_TLS.field_0xA0");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xA8) == 0xA8, "RTM_TLS.field_0xA8");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xB0) == 0xB0, "RTM_TLS.field_0xB0");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xB8) == 0xB8, "RTM_TLS.field_0xB8");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xC0) == 0xC0, "RTM_TLS.field_0xC0");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xC8) == 0xC8, "RTM_TLS.field_0xC8");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xD0) == 0xD0, "RTM_TLS.field_0xD0");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0xD8) == 0xD8, "RTM_TLS.field_0xD8");

/* ============================================================
 * nummPrimitiveManager
 * Global singleton. Initialize at RVA 0x56D3E0.
 * Fields proven: +0x08 (semantic array ptr), +0x10 (render state wrapper ptr).
 * Sub-object at +0x10 allocated with operator_new(0x20), vtable PTR_FUN_14088d448.
 * Size unknown, >= 0x18.
 * ============================================================ */
typedef struct __attribute__((packed)) nummPrimitiveManager {
    uint8_t _pad_0x00[0x08];          /* 0x00 */
    void *semantic_array;             /* 0x08 — ptr to allocated semantic buffer */
    void *render_state_wrap;          /* 0x10 — ptr to heap-allocated wrapper with vtable PTR_FUN_14088d448 */
} nummPrimitiveManager;
/* size unknown, >= 0x18 */
static_assert(offsetof(nummPrimitiveManager, semantic_array) == 0x08, "nummPrimitiveManager.semantic_array");
static_assert(offsetof(nummPrimitiveManager, render_state_wrap) == 0x10, "nummPrimitiveManager.render_state_wrap");

/* ============================================================
 * nummNutParser
 * Polymorphic class. Ctor at RVA 0x576540.
 * Vtable: PTR_FUN_14088e2c8. Size proven >= 0x30 (param_1[5] = offset 0x28).
 * ============================================================ */
typedef struct __attribute__((packed)) nummNutParser {
    void *vtable;                     /* 0x00 — PTR_FUN_14088e2c8 */
    uint8_t _pad_0x08[0x10];          /* 0x08 */
    uint64_t field_0x18;              /* 0x18 — zeroed in ctor (param_1[3]) */
    uint64_t field_0x20;              /* 0x20 — zeroed in ctor (param_1[4]) */
    uint64_t field_0x28;              /* 0x28 — zeroed in ctor (param_1[5]) */
} nummNutParser;
/* size unknown, >= 0x30 */
static_assert(offsetof(nummNutParser, vtable) == 0x00, "nummNutParser.vtable");
static_assert(offsetof(nummNutParser, field_0x18) == 0x18, "nummNutParser.field_0x18");
static_assert(offsetof(nummNutParser, field_0x20) == 0x20, "nummNutParser.field_0x20");
static_assert(offsetof(nummNutParser, field_0x28) == 0x28, "nummNutParser.field_0x28");

/* ============================================================
 * nummNutPictureParser
 * Polymorphic class. Dtor at RVA 0x5769A0.
 * Vtable: PTR_FUN_14088e298 (dtor sets it before cleanup).
 * Secondary vtable: PTR_FUN_14088e2c0.
 * Accesses param_1[0xc] (0x60), param_1[0xd] (0x68), param_1[10] (0x50).
 * Size proven >= 0x70.
 * ============================================================ */
typedef struct __attribute__((packed)) nummNutPictureParser {
    void *vtable;                     /* 0x00 — PTR_FUN_14088e298 (set in dtor) */
    void *secondary_vtbl;             /* 0x08 — PTR_FUN_14088e2c0 (set in dtor) */
    uint8_t _pad_0x10[0x40];          /* 0x10 */
    void *field_0x50;                 /* 0x50 — param_1[10], checked in dtor */
    uint8_t _pad_0x58[0x08];          /* 0x58 */
    void *field_0x60;                 /* 0x60 — param_1[0xc], used in dtor */
    void *field_0x68;                 /* 0x68 — param_1[0xd], used in dtor */
} nummNutPictureParser;
/* size unknown, >= 0x70 */
static_assert(offsetof(nummNutPictureParser, vtable) == 0x00, "nummNutPictureParser.vtable");
static_assert(offsetof(nummNutPictureParser, secondary_vtbl) == 0x08, "nummNutPictureParser.secondary_vtbl");
static_assert(offsetof(nummNutPictureParser, field_0x50) == 0x50, "nummNutPictureParser.field_0x50");
static_assert(offsetof(nummNutPictureParser, field_0x60) == 0x60, "nummNutPictureParser.field_0x60");
static_assert(offsetof(nummNutPictureParser, field_0x68) == 0x68, "nummNutPictureParser.field_0x68");

#endif /* CMN76_S2_H */