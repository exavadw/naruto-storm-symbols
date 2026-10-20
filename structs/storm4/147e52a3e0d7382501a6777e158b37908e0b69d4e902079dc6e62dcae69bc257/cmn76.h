/* cmn76.h — Storm 4 (s4) struct group cmn76
 * INFERRED from static analysis of NSUNS4_release.exe (PC x64, image base 0x140000000).
 * Not runtime-confirmed. All fields tagged PRES (presentation/render state).
 * OWN-GAME NAMES only: derived from s4 symbols/strings or carried from s3 (same engine).
 */
#ifndef CMN76_S4_H
#define CMN76_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── nummRender ───────────────────────────────────────────────────────
 * Global singleton render manager. Size proven >= 0x140 from Init loop
 * zeroing 8 uints at offsets 0x120..0x13C (RVA 0x9E12C0).
 * No operator_new found; actual size may be larger.
 */
typedef struct __attribute__((packed)) nummRender {
    uint8_t pad_0x00[8];          /* 0x00: vtable or padding */
    float   viewport_x;           /* 0x08: SysClear writes TLS+0x08 */
    float   viewport_y;           /* 0x0C */
    float   viewport_w;           /* 0x10 */
    float   viewport_h;           /* 0x14 */
    uint8_t pad_0x18[0x68];       /* 0x18..0x7F */
    uint8_t vsync_thread[0x28];   /* 0x80: embedded VSyncCallbackThread */
    int32_t field_0xA8;           /* 0xA8: zeroed in Exit */
    uint8_t pad_0xAC[4];          /* 0xAC */
    void   *cmd_list_begin;       /* 0xB0: WaitVSync reads/writes */
    void   *cmd_list_end;         /* 0xB8 */
    uint8_t pad_0xC0[0x10];       /* 0xC0..0xCF */
    int32_t frame_counter;        /* 0xD0: incremented in WaitVSync */
    int32_t field_0xD4;           /* 0xD4: zeroed under critsec in Init */
    uint32_t field_0xD8;          /* 0xD8: stores Init param_6 */
    uint8_t pad_0xDC[4];          /* 0xDC */
    int64_t frame_timing_delta;   /* 0xE0: WaitVSync GPU timing */
    int64_t gpu_timing_delta;     /* 0xE8 */
    uint8_t pad_0xF0[0x10];       /* 0xF0..0xFF */
    void   *event_handle;         /* 0x100: CreateEventA in Init */
    uint8_t critsec[0x10];        /* 0x108: CRITICAL_SECTION */
    int32_t flip_fail_flag;       /* 0x118: set to 1 on flip failure */
    uint8_t pad_0x11C[4];         /* 0x11C */
    uint32_t init_slots[8];       /* 0x120..0x13C: zeroed in Init loop */
} nummRender;

static_assert(offsetof(nummRender, viewport_x) == 0x08, "nummRender.viewport_x");
static_assert(offsetof(nummRender, viewport_y) == 0x0C, "nummRender.viewport_y");
static_assert(offsetof(nummRender, viewport_w) == 0x10, "nummRender.viewport_w");
static_assert(offsetof(nummRender, viewport_h) == 0x14, "nummRender.viewport_h");
static_assert(offsetof(nummRender, vsync_thread) == 0x80, "nummRender.vsync_thread");
static_assert(offsetof(nummRender, field_0xA8) == 0xA8, "nummRender.field_0xA8");
static_assert(offsetof(nummRender, cmd_list_begin) == 0xB0, "nummRender.cmd_list_begin");
static_assert(offsetof(nummRender, cmd_list_end) == 0xB8, "nummRender.cmd_list_end");
static_assert(offsetof(nummRender, frame_counter) == 0xD0, "nummRender.frame_counter");
static_assert(offsetof(nummRender, field_0xD4) == 0xD4, "nummRender.field_0xD4");
static_assert(offsetof(nummRender, field_0xD8) == 0xD8, "nummRender.field_0xD8");
static_assert(offsetof(nummRender, frame_timing_delta) == 0xE0, "nummRender.frame_timing_delta");
static_assert(offsetof(nummRender, gpu_timing_delta) == 0xE8, "nummRender.gpu_timing_delta");
static_assert(offsetof(nummRender, event_handle) == 0x100, "nummRender.event_handle");
static_assert(offsetof(nummRender, critsec) == 0x108, "nummRender.critsec");
static_assert(offsetof(nummRender, flip_fail_flag) == 0x118, "nummRender.flip_fail_flag");
static_assert(offsetof(nummRender, init_slots) == 0x120, "nummRender.init_slots");

/* ─── nummRender::TLS ──────────────────────────────────────────────────
 * Per-thread render state. Size proven >= 0x28 from TLS ctor (RVA 0x9E0320)
 * writing float@0x14, byte@0x1C, int@0x24. GetSceneID reads +0x20.
 * SysClear reads viewport floats at TLS+0x08..0x14, byte+0x1C, int+0x18.
 */
typedef struct __attribute__((packed)) nummRender_TLS {
    uint8_t pad_0x00[8];          /* 0x00 */
    float   tls_viewport_x;       /* 0x08: SysClear reads */
    float   tls_viewport_y;       /* 0x0C */
    float   tls_viewport_w;       /* 0x10 */
    float   tls_viewport_h;       /* 0x14: also set to 1.0f in ctor */
    int32_t field_0x18;           /* 0x18: SysClear reads int here */
    uint8_t byte_0x1C;            /* 0x1C: set to 0 in ctor */
    uint8_t pad_0x1D[3];          /* 0x1D..0x1F */
    int32_t scene_id;             /* 0x20: GetSceneID reads TLS+0xe0->+0x20 */
    int32_t field_0x24;           /* 0x24: set to 1 in ctor */
} nummRender_TLS;

static_assert(offsetof(nummRender_TLS, tls_viewport_x) == 0x08, "nummRender_TLS.tls_viewport_x");
static_assert(offsetof(nummRender_TLS, tls_viewport_y) == 0x0C, "nummRender_TLS.tls_viewport_y");
static_assert(offsetof(nummRender_TLS, tls_viewport_w) == 0x10, "nummRender_TLS.tls_viewport_w");
static_assert(offsetof(nummRender_TLS, tls_viewport_h) == 0x14, "nummRender_TLS.tls_viewport_h");
static_assert(offsetof(nummRender_TLS, field_0x18) == 0x18, "nummRender_TLS.field_0x18");
static_assert(offsetof(nummRender_TLS, byte_0x1C) == 0x1C, "nummRender_TLS.byte_0x1C");
static_assert(offsetof(nummRender_TLS, scene_id) == 0x20, "nummRender_TLS.scene_id");
static_assert(offsetof(nummRender_TLS, field_0x24) == 0x24, "nummRender_TLS.field_0x24");

/* ─── nummNutParser ────────────────────────────────────────────────────
 * NUT texture archive parser. Size proven >= 0x30 from ctor (RVA 0x9F68F0)
 * zeroing qword fields [3],[4],[5] (= +0x18,+0x20,+0x28).
 * Release (0x9F8270) iterates linked list from +0x18 to +0x20, stride 0xA0.
 * Vtable: PTR_FUN_141102ea0.
 */
typedef struct __attribute__((packed)) nummNutParser {
    void   *vtable;               /* 0x00: PTR_FUN_141102ea0 */
    uint8_t pad_0x08[0x10];       /* 0x08..0x17 */
    void   *list_begin;           /* 0x18: linked list head */
    void   *list_end;             /* 0x20: linked list tail sentinel */
    void   *field_0x28;           /* 0x28: zeroed in ctor */
} nummNutParser;

static_assert(offsetof(nummNutParser, vtable) == 0x00, "nummNutParser.vtable");
static_assert(offsetof(nummNutParser, list_begin) == 0x18, "nummNutParser.list_begin");
static_assert(offsetof(nummNutParser, list_end) == 0x20, "nummNutParser.list_end");
static_assert(offsetof(nummNutParser, field_0x28) == 0x28, "nummNutParser.field_0x28");

/* ─── nummNutPictureParser ─────────────────────────────────────────────
 * Picture/texture parser extending nummNutParser. Size proven >= 0x70 from
 * dtor (RVA 0x9F6D60) accessing fields at +0x50, +0x60, +0x68.
 * Vtable: PTR_FUN_141102e70, secondary vtable PTR_FUN_141102e98 at +0x08.
 * Note: Initialize at 0x76A30 accesses param_1+0x1198 (criVdec handle) --
 * this likely belongs to an enclosing video decoder class, not the base parser.
 */
typedef struct __attribute__((packed)) nummNutPictureParser {
    void   *vtable;               /* 0x00: PTR_FUN_141102e70 */
    void   *secondary_vtable;     /* 0x08: PTR_FUN_141102e98 */
    uint8_t pad_0x10[0x13];       /* 0x10..0x22 */
    uint8_t flag_0x23;            /* 0x23: byte field seen in dtor */
    uint8_t pad_0x24[0x2C];       /* 0x24..0x4F */
    void   *field_0x50;           /* 0x50: checked/freed in dtor */
    uint8_t pad_0x58[8];          /* 0x58..0x5F */
    void   *shader_index_0x60;    /* 0x60: used with ChangeGlobalIndex */
    void   *shader_index_0x68;    /* 0x68: same usage */
} nummNutPictureParser;

static_assert(offsetof(nummNutPictureParser, vtable) == 0x00, "nummNutPictureParser.vtable");
static_assert(offsetof(nummNutPictureParser, secondary_vtable) == 0x08, "nummNutPictureParser.secondary_vtable");
static_assert(offsetof(nummNutPictureParser, flag_0x23) == 0x23, "nummNutPictureParser.flag_0x23");
static_assert(offsetof(nummNutPictureParser, field_0x50) == 0x50, "nummNutPictureParser.field_0x50");
static_assert(offsetof(nummNutPictureParser, shader_index_0x60) == 0x60, "nummNutPictureParser.shader_index_0x60");
static_assert(offsetof(nummNutPictureParser, shader_index_0x68) == 0x68, "nummNutPictureParser.shader_index_0x68");

/* ─── nummPrimitiveManager ─────────────────────────────────────────────
 * Draw call / vertex semantic manager. Size proven >= 0x18 from Initialize
 * (RVA 0x9ED8B0) writing +0x08 and +0x10. Finalize (0x9ED6D0) confirms both.
 * Sub-object at +0x10 is heap-allocated (operator_new(0x20)) with its own
 * vtable (PTR_FUN_141102050) containing mmMutex.
 */
typedef struct __attribute__((packed)) nummPrimitiveManager {
    uint8_t pad_0x00[8];          /* 0x00 */
    void   *semantic_array;       /* 0x08: allocated via mmEngineMalloc */
    void   *render_state_wrap;    /* 0x10: heap sub-object (0x20 bytes) */
} nummPrimitiveManager;

static_assert(offsetof(nummPrimitiveManager, semantic_array) == 0x08, "nummPrimitiveManager.semantic_array");
static_assert(offsetof(nummPrimitiveManager, render_state_wrap) == 0x10, "nummPrimitiveManager.render_state_wrap");

/* ─── nummPrimitiveMaterial ────────────────────────────────────────────
 * Material/shader binding wrapper. Size proven >= 0x28 from ctor
 * (RVA 0x946AE0): qword-indexed [0..2]=0, mmMutex embedded, then
 * *(uint32_t*)(param_1+4)=0xffffff00 which is offset 0x20.
 * BindParameter uses critsec at param_1+0x10 (the embedded mutex).
 */
typedef struct __attribute__((packed)) nummPrimitiveMaterial {
    uint64_t field_0x00;          /* 0x00: zeroed in ctor */
    uint64_t field_0x08;          /* 0x08: zeroed in ctor */
    uint8_t  mutex[0x10];         /* 0x10: embedded mmMutex (ctor calls mmMutex::mmMutex) */
    uint32_t field_0x20;          /* 0x20: set to 0xffffff00 in ctor */
    uint8_t  pad_0x24[4];         /* 0x24 */
} nummPrimitiveMaterial;

static_assert(offsetof(nummPrimitiveMaterial, field_0x00) == 0x00, "nummPrimitiveMaterial.field_0x00");
static_assert(offsetof(nummPrimitiveMaterial, field_0x08) == 0x08, "nummPrimitiveMaterial.field_0x08");
static_assert(offsetof(nummPrimitiveMaterial, mutex) == 0x10, "nummPrimitiveMaterial.mutex");
static_assert(offsetof(nummPrimitiveMaterial, field_0x20) == 0x20, "nummPrimitiveMaterial.field_0x20");

/* ─── nummRenderTextureManager::TLS ────────────────────────────────────
 * Per-thread texture manager state. Size proven >= 0xE0 from TLS ctor
 * (RVA 0x9DC2E0): qword-indexed access spans indices 0 through 0x1b
 * (0x1b * 8 = 0xD8, plus 8 bytes = 0xE0). Self-pointers at [3]/[4],
 * [9]/[10], [0xf]/[0x10]. state_surface found 16 fields +0x58..+0xD8.
 */
typedef struct __attribute__((packed)) nummRenderTextureManager_TLS {
    uint8_t pad_0x00[0x18];       /* 0x00..0x17: indices [0],[1],[2] */
    void   *self_ptr_0x18;        /* 0x18: index [3], self-pointer */
    void   *self_ptr_0x20;        /* 0x20: index [4], self-pointer */
    uint8_t pad_0x28[0x30];       /* 0x28..0x57: indices [5]..[10] partial */
    void   *field_0x58;           /* 0x58: state_surface field */
    void   *field_0x60;           /* 0x60 */
    void   *field_0x68;           /* 0x68 */
    void   *field_0x70;           /* 0x70 */
    void   *field_0x78;           /* 0x78: self-pointer pair [0xf] */
    void   *field_0x80;           /* 0x80: self-pointer pair [0x10] */
    void   *field_0x88;           /* 0x88 */
    void   *field_0x90;           /* 0x90 */
    void   *field_0x98;           /* 0x98 */
    void   *field_0xA0;           /* 0xA0 */
    void   *field_0xA8;           /* 0xA8 */
    void   *field_0xB0;           /* 0xB0 */
    void   *field_0xB8;           /* 0xB8 */
    void   *field_0xC0;           /* 0xC0 */
    void   *field_0xC8;           /* 0xC8 */
    void   *field_0xD0;           /* 0xD0 */
    void   *field_0xD8;           /* 0xD8: last written field */
} nummRenderTextureManager_TLS;

static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x18) == 0x18, "RTM_TLS.self_ptr_0x18");
static_assert(offsetof(nummRenderTextureManager_TLS, self_ptr_0x20) == 0x20, "RTM_TLS.self_ptr_0x20");
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

#endif /* CMN76_S4_H */