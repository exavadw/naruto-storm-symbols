/* cmn76.h — Storm 1 (s1) struct group cmn76
 * Generated from static analysis of NSUNS1.exe (sha256 10231093...)
 * All layouts INFERRED from decompiled code; not runtime-confirmed.
 * OWN-GAME NAMES only (Storm 1 / ns1:: / Switch Trilogy).
 * PC OFFSETS ONLY — derived from x64 s1 decompiles.
 */
#ifndef CMN76_S1_H
#define CMN76_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ============================================================
 * nummRender
 * Global singleton (no heap ctor). Init at RVA 0x44EF50.
 * Size proven >= 0x140 from Init loop: *(param_1 + 0x120..0x13C) = 0.
 * ============================================================ */
typedef struct __attribute__((packed)) nummRender {
    uint8_t  _pad_0x00[0x14];             /* 0x00 */
    uint32_t field_0x14;                  /* 0x14 — written by TLS::TLS */
    uint8_t  _pad_0x18[0x04];             /* 0x18 */
    uint32_t field_0x1C;                  /* 0x1C — written by TLS::TLS */
    uint8_t  _pad_0x20[0x04];             /* 0x20 */
    uint32_t field_0x24;                  /* 0x24 — written by TLS::TLS */
    uint8_t  _pad_0x28[0x58];             /* 0x28 */
    uint8_t  vsync_callback_thread[0x54]; /* 0x80 — VSyncCallbackThread embedded (0x80..0xD3) */
    uint32_t field_0xD4;                  /* 0xD4 — set to 0 in Init */
    uint32_t refresh_rate;                /* 0xD8 — param_6 passed to Init */
    uint8_t  _pad_0xDC[0x24];             /* 0xDC */
    void    *event_handle;                /* 0x100 — CreateEventA handle ptr */
    void    *critical_section;            /* 0x108 — critical section ptr, locked/unlocked in Init */
    uint8_t  _pad_0x110[0x10];            /* 0x110 */
    uint32_t init_slots[8];               /* 0x120 — 8 uints zeroed in Init loop (0x120..0x13C) */
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
 * Ctor at RVA 0x44DF90. Size proven >= 0x28 (writes float at +0x14, +0x18, byte at +0x1C, int at +0x24).
 * ============================================================ */
typedef struct __attribute__((packed)) nummRender_TLS {
    uint8_t  _pad_0x00[0x14];   /* 0x00 */
    float    float_0x14;        /* 0x14 — set to 1.0f in ctor */
    float    float_0x18;        /* 0x18 — set to 1.0f in ctor */
    uint8_t  byte_0x1C;         /* 0x1C — set to 0 in ctor */
    uint8_t  _pad_0x1D[0x03];   /* 0x1D */
    uint32_t int_0x20;          /* 0x20 — padding/unused between 0x1C and 0x24 */
    uint32_t int_0x24;          /* 0x24 — set to 1 in ctor */
} nummRender_TLS;
/* size unknown, >= 0x28 */
static_assert(offsetof(nummRender_TLS, float_0x14) == 0x14, "nummRender_TLS.float_0x14");
static_assert(offsetof(nummRender_TLS, float_0x18) == 0x18, "nummRender_TLS.float_0x18");
static_assert(offsetof(nummRender_TLS, byte_0x1C) == 0x1C, "nummRender_TLS.byte_0x1C");
static_assert(offsetof(nummRender_TLS, int_0x24) == 0x24, "nummRender_TLS.int_0x24");

/* ============================================================
 * nummRenderTextureManager::TLS
 * Thread-local, stored at TLS_base + 0x2998 (from nummThread::Construction).
 * Ctor at RVA 0x443840. Size proven >= 0xE0 (accesses param_1[0x1b] = byte 0xD8).
 * Self-pointer pattern at indices 3, 9, 0xf.
 * ============================================================ */
typedef struct __attribute__((packed)) nummRenderTextureManager_TLS {
    uint8_t  _pad_0x00[0x18];   /* 0x00 */
    void    *self_ptr_0x18;     /* 0x18 — self-pointer (index 3) */
    uint8_t  _pad_0x20[0x38];   /* 0x20 */
    uint64_t field_0x58;        /* 0x58 — state_surface field */
    uint64_t field_0x60;        /* 0x60 */
    uint64_t field_0x68;        /* 0x68 */
    uint64_t field_0x70;        /* 0x70 */
    uint64_t field_0x78;        /* 0x78 */
    uint64_t field_0x80;        /* 0x80 */
    uint64_t field_0x88;        /* 0x88 */
    uint64_t field_0x90;        /* 0x90 */
    uint64_t field_0x98;        /* 0x98 */
    uint64_t field_0xA0;        /* 0xA0 */
    uint64_t field_0xA8;        /* 0xA8 */
    uint64_t field_0xB0;        /* 0xB0 */
    uint64_t field_0xB8;        /* 0xB8 */
    uint64_t field_0xC0;        /* 0xC0 */
    uint64_t field_0xC8;        /* 0xC8 */
    uint64_t field_0xD0;        /* 0xD0 */
    uint64_t field_0xD8;        /* 0xD8 — last state_surface field */
} nummRenderTextureManager_TLS;
/* size unknown, >= 0xE0 */
static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x18) == 0x18, "RTM_TLS.self_ptr_0x18");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x58) == 0x58, "RTM_TLS.field_0x58");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x60) == 0x60, "RTM_TLS.field_0x60");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x68) == 0x68, "RTM_TLS.field_0x68");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x70) == 0x70, "RTM_TLS.field_0x70");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x78) == 0x78, "RTM_TLS.field_0x78");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x80) == 0x80, "RTM_TLS.field_0x80");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x88) == 0x88, "RTM_TLS.field_0x88");
static_assert(offsetof(nummRenderTextureManager_TLS, field_0x90) == 0x90, "RTM_TLS.field_0x90");
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
 * Global singleton at DAT_1408833c0. No heap allocation for the manager itself.
 * Initialize at RVA 0x46CBA0, Finalize at 0x46C9C0.
 * Fields proven: +0x08 (semantic array ptr), +0x10 (render state wrapper ptr).
 * Size unknown, >= 0x18.
 * ============================================================ */
typedef struct __attribute__((packed)) nummPrimitiveManager {
    uint8_t  _pad_0x00[0x08];   /* 0x00 */
    void    *semantic_array;    /* 0x08 — ptr to allocated semantic buffer (mmEngineMalloc) */
    void    *render_state_wrap; /* 0x10 — ptr to heap-allocated wrapper with vtable PTR_FUN_140734c90 */
} nummPrimitiveManager;
/* size unknown, >= 0x18 */
static_assert(offsetof(nummPrimitiveManager, semantic_array) == 0x08, "nummPrimitiveManager.semantic_array");
static_assert(offsetof(nummPrimitiveManager, render_state_wrap) == 0x10, "nummPrimitiveManager.render_state_wrap");

/* ============================================================
 * nummNutParser
 * Polymorphic class. Ctor at RVA 0x4768F0.
 * Vtable: PTR_FUN_140735a80. Size proven >= 0x30 (param_1[5] = offset 0x28).
 * ============================================================ */
typedef struct __attribute__((packed)) nummNutParser {
    void    *vtable;            /* 0x00 — PTR_FUN_140735a80 */
    uint8_t  _pad_0x08[0x10];   /* 0x08 */
    uint64_t field_0x18;        /* 0x18 — zeroed in ctor (param_1[3]) */
    uint64_t field_0x20;        /* 0x20 — zeroed in ctor (param_1[4]) */
    uint64_t field_0x28;        /* 0x28 — zeroed in ctor (param_1[5]) */
} nummNutParser;
/* size unknown, >= 0x30 */
static_assert(offsetof(nummNutParser, vtable) == 0x00, "nummNutParser.vtable");
static_assert(offsetof(nummNutParser, field_0x18) == 0x18, "nummNutParser.field_0x18");
static_assert(offsetof(nummNutParser, field_0x20) == 0x20, "nummNutParser.field_0x20");
static_assert(offsetof(nummNutParser, field_0x28) == 0x28, "nummNutParser.field_0x28");

/* ============================================================
 * nummNutPictureParser
 * Polymorphic class. No standalone ctor found in s1.
 * Dtor at RVA 0x476D50. Vtable: PTR_FUN_140735a50 (dtor sets it before cleanup).
 * Initialize at 0x477B30 uses param_1 + -8 (embedded/offset layout).
 * Accesses param_1[0xc] (0x60), param_1[0xd] (0x68), param_1[10] (0x50).
 * Size proven >= 0x70.
 * ============================================================ */
typedef struct __attribute__((packed)) nummNutPictureParser {
    void    *vtable;            /* 0x00 — PTR_FUN_140735a50 (set in dtor) */
    void    *secondary_vtbl;    /* 0x08 — PTR_FUN_140735a78 (set in dtor) */
    uint8_t  _pad_0x10[0x40];   /* 0x10 */
    void    *field_0x50;        /* 0x50 — param_1[10], checked in dtor */
    uint8_t  _pad_0x58[0x08];   /* 0x58 */
    void    *field_0x60;        /* 0x60 — param_1[0xc], used in dtor ChangeGlobalIndex */
    void    *field_0x68;        /* 0x68 — param_1[0xd], used in dtor ChangeGlobalIndex */
} nummNutPictureParser;
/* size unknown, >= 0x70 */
static_assert(offsetof(nummNutPictureParser, vtable) == 0x00, "nummNutPictureParser.vtable");
static_assert(offsetof(nummNutPictureParser, secondary_vtbl) == 0x08, "nummNutPictureParser.secondary_vtbl");
static_assert(offsetof(nummNutPictureParser, field_0x50) == 0x50, "nummNutPictureParser.field_0x50");
static_assert(offsetof(nummNutPictureParser, field_0x60) == 0x60, "nummNutPictureParser.field_0x60");
static_assert(offsetof(nummNutPictureParser, field_0x68) == 0x68, "nummNutPictureParser.field_0x68");

#endif /* CMN76_S1_H */