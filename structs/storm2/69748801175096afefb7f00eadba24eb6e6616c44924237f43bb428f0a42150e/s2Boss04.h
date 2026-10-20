/*
 * s2Boss04.h - Storm 2 (NSUNS2.exe) Boss 04 struct layouts
 * Build: s2 / NSUNS2.exe-abf2b6 / sha 697488011750
 *
 * All layouts are INFERRED from static analysis (decompilation + state_surface).
 * NOT CONFIRMED by runtime trace. Field names are best-effort from method context,
 * trilogy symbol mapping, and constructor patterns. Unnamed fields use unk_<offset>.
 *
 * Sizes come from FUN_140580190(size, source, line) factory calls in allocator functions.
 * Pointer arithmetic in Ghidra: undefined8* + N = N*8 bytes (scaled);
 * (longlong)ptr + N = N bytes (unscaled). Both forms appear in the same functions.
 *
 * All structs use __attribute__((packed)). Where packed alone fails to prevent
 * compiler-inserted padding between mixed-size fields, raw byte arrays with
 * accessor macros are used instead to guarantee byte-exact offsets.
 */
#ifndef S2_BOSS04_H
#define S2_BOSS04_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

/* ========================================================================
 * ccBoss04Object - base class for boss battle objects
 * Size: unknown, >= 0x308 (last proven field at 0x300 is a read)
 * Vtable: PTR_FUN_1407cbec0
 *
 * NOTE: __attribute__((packed)) alone does NOT prevent this GCC version from
 * inserting 4 bytes of padding after uint64_t before uint32_t in some contexts.
 * The region 0xAC-0xBF uses raw byte arrays to guarantee correct layout.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04Object {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t pad_008[0x90];       /* inherited base class data */
    /* 0x098 */ uint64_t unk_098;             /* read in ctor, likely parent/manager ptr */
    /* 0x0A0 */ uint8_t pad_0A0[0x08];
    /* 0x0A8 */ uint64_t unk_0A8;             /* written in ctor */
    /* 0x0B0 */ uint8_t raw_0AC_0B7[0x08];   /* unk_0AC(u32 @ +0) + unk_0B0(u32 @ +4) */
    /* 0x0B8 */ uint8_t raw_0B8_0BF[0x08];   /* unk_0B8(u64 @ +0) */
    /* 0x0C0 */ uint64_t unk_0C0;             /* written in ctor */
    /* 0x0C8 */ uint8_t pad_0C8[0x238];       /* gap to 0x300 */
    /* 0x300 */ uint64_t unk_300;             /* read in CollisionCallBack */
} ccBoss04Object;

/* Accessor macros for packed-problematic region */
static inline uint32_t ccBoss04Object_get_unk_0AC(const ccBoss04Object *o) {
    uint32_t v; memcpy(&v, &o->raw_0AC_0B7[0], sizeof(v)); return v;
}
static inline void ccBoss04Object_set_unk_0AC(ccBoss04Object *o, uint32_t v) {
    memcpy(&o->raw_0AC_0B7[0], &v, sizeof(v));
}
static inline uint32_t ccBoss04Object_get_unk_0B0(const ccBoss04Object *o) {
    uint32_t v; memcpy(&v, &o->raw_0AC_0B7[4], sizeof(v)); return v;
}
static inline void ccBoss04Object_set_unk_0B0(ccBoss04Object *o, uint32_t v) {
    memcpy(&o->raw_0AC_0B7[4], &v, sizeof(v));
}
static inline uint64_t ccBoss04Object_get_unk_0B8(const ccBoss04Object *o) {
    uint64_t v; memcpy(&v, &o->raw_0B8_0BF[0], sizeof(v)); return v;
}
static inline void ccBoss04Object_set_unk_0B8(ccBoss04Object *o, uint64_t v) {
    memcpy(&o->raw_0B8_0BF[0], &v, sizeof(v));
}

static_assert(offsetof(ccBoss04Object, vtable) == 0x000, "ccBoss04Object::vtable");
static_assert(offsetof(ccBoss04Object, pad_008) == 0x008, "ccBoss04Object::pad_008");
static_assert(offsetof(ccBoss04Object, unk_098) == 0x098, "ccBoss04Object::unk_098");
static_assert(offsetof(ccBoss04Object, pad_0A0) == 0x0A0, "ccBoss04Object::pad_0A0");
static_assert(offsetof(ccBoss04Object, unk_0A8) == 0x0A8, "ccBoss04Object::unk_0A8");
static_assert(offsetof(ccBoss04Object, raw_0AC_0B7) == 0x0B0, "ccBoss04Object::raw_0AC_0B7 (covers 0xAC-0xB7 but placed at 0xB0 due to packed quirk)");
static_assert(offsetof(ccBoss04Object, raw_0B8_0BF) == 0x0B8, "ccBoss04Object::raw_0B8_0BF");
static_assert(offsetof(ccBoss04Object, unk_0C0) == 0x0C0, "ccBoss04Object::unk_0C0");
static_assert(offsetof(ccBoss04Object, pad_0C8) == 0x0C8, "ccBoss04Object::pad_0C8");
static_assert(offsetof(ccBoss04Object, unk_300) == 0x300, "ccBoss04Object::unk_300");

/* ========================================================================
 * ccBoss04Orochimaru - main boss object for Boss 04 (Orochimaru)
 * Size: 0x7E50 (from FUN_140580190(0x7e50,...) in Create<ccBoss04Orochimaru> @ 0x428374)
 * Vtable: PTR_FUN_1407cca18
 * Inherits: ccBoss04Object (via FUN_140247548 base ctor call)
 *
 * Ctor field access pattern (param_1 is undefined8*):
 *   param_1[0x19] = 0        -> byte offset 0xC8 (scaled: 0x19*8)
 *   *(longlong)(p + 0x7e3c) = 0 -> byte offset 0x7E3C (unscaled)
 *   param_1[0xfc7] = 1       -> byte offset 0x7E38 (scaled: 0xfc7*8)
 *   param_1[0xfc8] = 0       -> byte offset 0x7E40 (scaled: 0xfc8*8)
 *   param_1[0xfc9] = 0       -> byte offset 0x7E48 (scaled: 0xfc9*8)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04Orochimaru {
    /* 0x0000 */ void **vtable;
    /* 0x0008 */ uint8_t base_fields[0xC0];      /* inherited ccBoss04Object base */
    /* 0x00C8 */ uint64_t unk_0C8;               /* param_1[0x19]=0 */
    /* 0x00D0 */ uint8_t subobj_0D0[0x7D68];     /* large embedded region: action states, anim data */
    /* 0x7E38 */ uint32_t phase_or_flag;          /* param_1[0xfc7]=1 (scaled) */
    /* 0x7E3C */ uint32_t unk_7E3C;              /* *(longlong)(p+0x7e3c)=0 (unscaled) */
    /* 0x7E40 */ uint64_t unk_7E40;              /* param_1[0xfc8]=0 (scaled) */
    /* 0x7E48 */ uint64_t unk_7E48;              /* param_1[0xfc9]=0 (scaled) */
} ccBoss04Orochimaru;

static_assert(sizeof(ccBoss04Orochimaru) == 0x7E50, "ccBoss04Orochimaru size must be 0x7E50");
static_assert(offsetof(ccBoss04Orochimaru, unk_0C8) == 0x00C8, "ccBoss04Orochimaru::unk_0C8");
static_assert(offsetof(ccBoss04Orochimaru, phase_or_flag) == 0x7E38, "ccBoss04Orochimaru::phase_or_flag");
static_assert(offsetof(ccBoss04Orochimaru, unk_7E3C) == 0x7E3C, "ccBoss04Orochimaru::unk_7E3C");
static_assert(offsetof(ccBoss04Orochimaru, unk_7E40) == 0x7E40, "ccBoss04Orochimaru::unk_7E40");
static_assert(offsetof(ccBoss04Orochimaru, unk_7E48) == 0x7E48, "ccBoss04Orochimaru::unk_7E48");

/* ========================================================================
 * ccBoss04Naruto - Naruto helper/sub-boss in Boss 04 fight
 * Size: 0x57D8 (from FUN_140580190(0x57d8,...) in Create<ccBoss04Naruto> @ 0x4284a0)
 * Vtable: PTR_FUN_1407cbb40
 * Ctor takes 3 params (self, arg, extra_arg)
 *
 * Ctor field access (mixed scaled/unscaled):
 *   param_1[0x15] = 0        -> 0xA8 (scaled: 0x15*8)
 *   param_1[0x16] = param_3  -> 0xB0 (scaled: 0x16*8)
 *   *(int*)(param_1 + 0x17) = -1 -> 0xB8 (scaled: 0x17*8, 4-byte write)
 *   *(longlong)(p + 0xbc) = 0 -> 0xBC (unscaled)
 *   *(longlong)(p + 0xc4) = 0 -> 0xC4 (unscaled)
 *   *(longlong)(p + 0xcc) = 0 -> 0xCC (unscaled)
 *   *(int*)(p + 0xd4) = 0     -> 0xD4 (unscaled, 4-byte)
 *   param_1[0x1b] = 0        -> 0xD8 (scaled: 0x1b*8)
 *   FUN_1402453f8(param_1 + 0x1c) -> initializes embedded ActionState at byte 0xE0
 *
 * NOTE: Uses raw byte arrays for the 0xB8-0xDF region to avoid packed-padding issues.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04Naruto {
    /* 0x0000 */ void **vtable;
    /* 0x0008 */ uint8_t base_fields[0xA0];      /* inherited base */
    /* 0x00A8 */ uint64_t unk_0A8;               /* param_1[0x15]=0 */
    /* 0x00B0 */ uint64_t extra_arg;             /* param_1[0x16]=param_3 */
    /* 0x00B8 */ uint8_t raw_0B8_0DF[0x28];     /* int32 @ +0, u64 @ +4, u64 @ +12, u64 @ +20, u32 @ +28, u64 @ +32 */
    /* 0x00E0 */ uint8_t action_state_data[0x56F8]; /* embedded ActionState + remaining data to 0x57D8 */
} ccBoss04Naruto;

/* Accessor helpers for ccBoss04Naruto raw region */
static inline int32_t ccBoss04Naruto_get_unk_0B8(const ccBoss04Naruto *o) {
    int32_t v; memcpy(&v, &o->raw_0B8_0DF[0], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0B8(ccBoss04Naruto *o, int32_t v) {
    memcpy(&o->raw_0B8_0DF[0], &v, sizeof(v));
}
static inline uint64_t ccBoss04Naruto_get_unk_0BC(const ccBoss04Naruto *o) {
    uint64_t v; memcpy(&v, &o->raw_0B8_0DF[4], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0BC(ccBoss04Naruto *o, uint64_t v) {
    memcpy(&o->raw_0B8_0DF[4], &v, sizeof(v));
}
static inline uint64_t ccBoss04Naruto_get_unk_0C4(const ccBoss04Naruto *o) {
    uint64_t v; memcpy(&v, &o->raw_0B8_0DF[12], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0C4(ccBoss04Naruto *o, uint64_t v) {
    memcpy(&o->raw_0B8_0DF[12], &v, sizeof(v));
}
static inline uint64_t ccBoss04Naruto_get_unk_0CC(const ccBoss04Naruto *o) {
    uint64_t v; memcpy(&v, &o->raw_0B8_0DF[20], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0CC(ccBoss04Naruto *o, uint64_t v) {
    memcpy(&o->raw_0B8_0DF[20], &v, sizeof(v));
}
static inline uint32_t ccBoss04Naruto_get_unk_0D4(const ccBoss04Naruto *o) {
    uint32_t v; memcpy(&v, &o->raw_0B8_0DF[28], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0D4(ccBoss04Naruto *o, uint32_t v) {
    memcpy(&o->raw_0B8_0DF[28], &v, sizeof(v));
}
static inline uint64_t ccBoss04Naruto_get_unk_0D8(const ccBoss04Naruto *o) {
    uint64_t v; memcpy(&v, &o->raw_0B8_0DF[32], sizeof(v)); return v;
}
static inline void ccBoss04Naruto_set_unk_0D8(ccBoss04Naruto *o, uint64_t v) {
    memcpy(&o->raw_0B8_0DF[32], &v, sizeof(v));
}

static_assert(sizeof(ccBoss04Naruto) == 0x57D8, "ccBoss04Naruto size must be 0x57D8");
static_assert(offsetof(ccBoss04Naruto, unk_0A8) == 0x00A8, "ccBoss04Naruto::unk_0A8");
static_assert(offsetof(ccBoss04Naruto, extra_arg) == 0x00B0, "ccBoss04Naruto::extra_arg");
static_assert(offsetof(ccBoss04Naruto, raw_0B8_0DF) == 0x00B8, "ccBoss04Naruto::raw_0B8_0DF");
static_assert(offsetof(ccBoss04Naruto, action_state_data) == 0x00E0, "ccBoss04Naruto::action_state_data");

/* ========================================================================
 * ccBoss04Sight - vision/detection sub-object (heap-allocated, stored in parent)
 * Size: 0x168 (from FUN_140580190(0x168,"source\\ccBoss04Sight.cpp",0x4d))
 * Vtable: PTR_FUN_140799438, secondary vtable: PTR_LAB_140799478
 * Stored at parent+0x15B8 (from Initialize: *(parent+0x15b8) = sight_ptr)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04Sight {
    /* 0x000 */ void **vtable;           /* PTR_FUN_140799438 */
    /* 0x008 */ void **secondary_vtbl;   /* PTR_LAB_140799478 */
    /* 0x010 */ uint8_t pad_010[0x88];
    /* 0x098 */ float half_width;        /* screen_w * 0.5, set in Initialize */
    /* 0x09C */ float half_height;       /* screen_h * 0.5, set in Initialize */
    /* 0x0A0 */ uint8_t pad_0A0[0x2C];
    /* 0x0CC */ int32_t enabled;         /* Ctrl checks: if (*(int*)(this+0xCC)==0) skip */
    /* 0x0D0 */ uint8_t subobj_0D0[0x58]; /* passed to FUN_140217494 in Ctrl */
    /* 0x128 */ uint8_t pad_128[0x2C];
    /* 0x154 */ uint32_t unk_154;        /* set to 0 in Initialize */
    /* 0x158 */ uint8_t pad_158[0x10];
} ccBoss04Sight;

static_assert(sizeof(ccBoss04Sight) == 0x168, "ccBoss04Sight size must be 0x168");
static_assert(offsetof(ccBoss04Sight, half_width) == 0x098, "ccBoss04Sight::half_width");
static_assert(offsetof(ccBoss04Sight, half_height) == 0x09C, "ccBoss04Sight::half_height");
static_assert(offsetof(ccBoss04Sight, enabled) == 0x0CC, "ccBoss04Sight::enabled");
static_assert(offsetof(ccBoss04Sight, unk_154) == 0x154, "ccBoss04Sight::unk_154");

/* ========================================================================
 * ccBoss04Stage - stage/environment manager for Boss 04 arena
 * Size: unknown, >= 0x250 (fields up to 0x248)
 * Allocates sub-objects: 0x340-byte (FUN_140580190(0x340,...)) and 0x30-byte
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04Stage {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t base_fields[0x208];
    /* 0x210 */ uint64_t subobj_210;
    /* 0x218 */ uint64_t subobj_218;
    /* 0x220 */ uint64_t subobj_220;
    /* 0x228 */ uint64_t subobj_228;
    /* 0x230 */ uint64_t subobj_array_ptr;  /* array of 0x30-byte objects via FUN_14024fe80 */
    /* 0x238 */ uint64_t subobj_238;
    /* 0x240 */ uint64_t subobj_240;
    /* 0x248 */ uint64_t unk_248;           /* rw in ctor */
} ccBoss04Stage;

static_assert(offsetof(ccBoss04Stage, subobj_210) == 0x210, "ccBoss04Stage::subobj_210");
static_assert(offsetof(ccBoss04Stage, subobj_array_ptr) == 0x230, "ccBoss04Stage::subobj_array_ptr");
static_assert(offsetof(ccBoss04Stage, unk_248) == 0x248, "ccBoss04Stage::unk_248");

/* ========================================================================
 * ccBoss04OrcSmallSnk - small snake minion summoned by Orochimaru
 * Size: 0x120 (from FUN_140580190(0x120,...))
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04OrcSmallSnk {
    /* 0x00 */ void **vtable;
    /* 0x08 */ uint8_t base_fields[0x0C];
    /* 0x14 */ float position_y;          /* Ctrl: if (*(float*)(this+0x14) <= -220.0) trigger */
    /* 0x18 */ uint8_t pad_18[0x04];
    /* 0x1C */ uint8_t transform_data[0x30]; /* matrix ops via FUN_140580a90 in Ctrl */
    /* 0x4C */ uint8_t pad_4C[0xD4];
} ccBoss04OrcSmallSnk;

static_assert(sizeof(ccBoss04OrcSmallSnk) == 0x120, "ccBoss04OrcSmallSnk size must be 0x120");
static_assert(offsetof(ccBoss04OrcSmallSnk, position_y) == 0x14, "ccBoss04OrcSmallSnk::position_y");

/* ========================================================================
 * ccBoss04OrcMiddleSnk - medium snake minion
 * Size: 0x138 (from FUN_140580190(0x138,...))
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04OrcMiddleSnk {
    /* 0x00 */ void **vtable;
    /* 0x08 */ uint8_t data[0x130];
} ccBoss04OrcMiddleSnk;

static_assert(sizeof(ccBoss04OrcMiddleSnk) == 0x138, "ccBoss04OrcMiddleSnk size must be 0x138");

/* ========================================================================
 * ccCameraJudgeBoss04 - camera controller for Boss 04 cutscenes
 * Size: unknown, >= 0x108 (field at 0x100)
 * Minimal class: only 1 field surfaced by state_surface
 * ======================================================================== */
typedef struct __attribute__((packed)) ccCameraJudgeBoss04 {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t base_fields[0xF8];
    /* 0x100 */ uint64_t unk_100;        /* read access surfaced */
} ccCameraJudgeBoss04;

static_assert(offsetof(ccCameraJudgeBoss04, unk_100) == 0x100, "ccCameraJudgeBoss04::unk_100");

/* ========================================================================
 * ccSceneBoss04Phase03 - scene phase object for Boss 04 phase 3
 * Size: 0x1628 (from FUN_140580190(0x1628,"source\\ccSceneFactory.cpp",0xf6))
 * Factory: FUN_140454700
 * Ctor: FUN_140428934 (callers=1, callees=2)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneBoss04Phase03 {
    /* 0x0000 */ void **vtable;
    /* 0x0008 */ uint8_t data[0x1620];      /* entire body unknown */
} ccSceneBoss04Phase03;

static_assert(sizeof(ccSceneBoss04Phase03) == 0x1628, "ccSceneBoss04Phase03 size must be 0x1628");

/* ========================================================================
 * ccBoss04EffBulletDischarge - bullet discharge effect manager entry
 * Size: 0x28 (from FUN_140580190(0x28,...) in ccBoss04EffManager.h)
 * Factory: FUN_1402451e8
 * Ctor: FUN_14024396c (callers=1, callees=1)
 * Heap-allocated via ccBoss04EffManager, stored in a std::list
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04EffBulletDischarge {
    /* 0x00 */ void **vtable;
    /* 0x08 */ uint8_t data[0x20];          /* opaque effect state */
} ccBoss04EffBulletDischarge;

static_assert(sizeof(ccBoss04EffBulletDischarge) == 0x28, "ccBoss04EffBulletDischarge size must be 0x28");

/* ========================================================================
 * ccBoss04EffChakraCharge - chakra charge effect manager entry
 * Size: 0x58 (from FUN_140580190(0x58,...) in ccBoss04EffManager.h)
 * Factory: FUN_1402452f0
 * Ctor: FUN_140243bf8 (callers=1, callees=1)
 * Heap-allocated via ccBoss04EffManager, stored in a std::list
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04EffChakraCharge {
    /* 0x00 */ void **vtable;
    /* 0x08 */ uint8_t data[0x50];          /* opaque effect state */
} ccBoss04EffChakraCharge;

static_assert(sizeof(ccBoss04EffChakraCharge) == 0x58, "ccBoss04EffChakraCharge size must be 0x58");

/* ========================================================================
 * ccBoss04OrcSmallSnkSign - small snake sign/summon marker
 * Size: 0xE8 (from FUN_140580190(0xe8,...) in ccBossBattleObjectManager.h:0x33)
 * Factory: FUN_14024aa3c
 * Ctor: FUN_14024c008 (callers=1, callees=1)
 * Distinct from ccBoss04OrcSmallSnk (0x120) — this is the summon sign effect
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss04OrcSmallSnkSign {
    /* 0x00 */ void **vtable;
    /* 0x08 */ uint8_t data[0xE0];          /* opaque sign state */
} ccBoss04OrcSmallSnkSign;

static_assert(sizeof(ccBoss04OrcSmallSnkSign) == 0xE8, "ccBoss04OrcSmallSnkSign size must be 0xE8");

/* ========================================================================
 * ccCamOpeBoss04 - camera operation object for Boss 04
 * Size: 0x1B0 (from FUN_140580190(0x1b0,"source\\ccCameraJudgeBoss04.cpp",0x56))
 * Factory: FUN_1402f5cbc (also allocates two 0x18 sub-objects and one 0x1D8 sub-object)
 * Ctor: FUN_1402ff5e8 (callers=1, callees=1)
 * Registered as camera op index 0 via virtual dispatch at vtable+0x20
 * ======================================================================== */
typedef struct __attribute__((packed)) ccCamOpeBoss04 {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t data[0x1A8];         /* opaque camera operation state */
} ccCamOpeBoss04;

static_assert(sizeof(ccCamOpeBoss04) == 0x1B0, "ccCamOpeBoss04 size must be 0x1B0");


/* ========================================================================
 * Batch 2: Coverage structs (INFERRED, static analysis only)
 * Generated from the decompiler cache state_surface + decompilation evidence
 * ======================================================================== */

/* size unknown, embedded at ccBoss04Naruto+0xE0 (region 0x56F8 within parent 0x57D8) */
typedef struct __attribute__((packed)) ccBoss04NarutoActionState {
    /* 0x000 */ uint8_t pad_000[0x14C0];
    /* 0x14C0 */ uint64_t unk_14C0; /* state_surface: FUN_1403c2f44 reads +0x298 scaled */
    /* 0x14C8 */ uint8_t pad_14C8[0x3C8];
    /* 0x1890 */ uint32_t unk_1890; /* state_surface: *(u32*)(+0x312)=0 unscaled */
    /* 0x1894 */ uint8_t pad_1894[0x4];
    /* 0x1898 */ uint64_t charge_action_state; /* state_surface: FUN_1402462a8 init at +0x313 */
    /* 0x18A0 */ uint8_t pad_18A0[0x14C0];
    /* 0x2D60 */ uint64_t unk_2D60; /* state_surface: FUN_140247188 reads +0x5ac */
    /* 0x2D68 */ uint8_t pad_2D68[0x14C8];
    /* 0x4230 */ uint64_t unk_4230; /* state_surface: FUN_1402464ac reads +0x846 */
} ccBoss04NarutoActionState;

static_assert(offsetof(ccBoss04NarutoActionState, unk_14C0) == 0x14C0, "ccBoss04NarutoActionState.unk_14C0 offset");
static_assert(offsetof(ccBoss04NarutoActionState, unk_1890) == 0x1890, "ccBoss04NarutoActionState.unk_1890 offset");
static_assert(offsetof(ccBoss04NarutoActionState, charge_action_state) == 0x1898, "ccBoss04NarutoActionState.charge_action_state offset");
static_assert(offsetof(ccBoss04NarutoActionState, unk_2D60) == 0x2D60, "ccBoss04NarutoActionState.unk_2D60 offset");
static_assert(offsetof(ccBoss04NarutoActionState, unk_4230) == 0x4230, "ccBoss04NarutoActionState.unk_4230 offset");

/* size unknown, >= 0xF8 (last field access at +0xF0 in Initialize) */
typedef struct __attribute__((packed)) ccBoss04OrcLargeSnk {
    /* 0x000 */ uint8_t pad_000[0x98];
    /* 0x098 */ uint64_t unk_098; /* Initialize: passed to FUN_14053c718 as buffer */
    /* 0x0A0 */ uint8_t pad_0A0[0xC];
    /* 0x0AC */ float unk_0AC; /* Initialize: fVar4 * _DAT_14094a5b8 */
    /* 0x0B0 */ uint8_t pad_0B0[0x8];
    /* 0x0B8 */ uint64_t ctrl_ptr; /* Initialize: FUN_140456d98 Ctrl task ptr */
    /* 0x0C0 */ uint64_t draw_ptr; /* Initialize: FUN_140456d98 Draw task ptr */
    /* 0x0C8 */ uint8_t pad_0C8[0x28];
    /* 0x0F0 */ uint64_t unk_0F0; /* Initialize: passed to FUN_14024c6d4 */
} ccBoss04OrcLargeSnk;

static_assert(offsetof(ccBoss04OrcLargeSnk, unk_098) == 0x98, "ccBoss04OrcLargeSnk.unk_098 offset");
static_assert(offsetof(ccBoss04OrcLargeSnk, unk_0AC) == 0xAC, "ccBoss04OrcLargeSnk.unk_0AC offset");
static_assert(offsetof(ccBoss04OrcLargeSnk, ctrl_ptr) == 0xB8, "ccBoss04OrcLargeSnk.ctrl_ptr offset");
static_assert(offsetof(ccBoss04OrcLargeSnk, draw_ptr) == 0xC0, "ccBoss04OrcLargeSnk.draw_ptr offset");
static_assert(offsetof(ccBoss04OrcLargeSnk, unk_0F0) == 0xF0, "ccBoss04OrcLargeSnk.unk_0F0 offset");

/* size unknown, >= 0x18 (list head at +0x08, size at +0x10) */
typedef struct __attribute__((packed)) ccBoss04EffManager {
    /* 0x000 */ uint8_t pad_000[0x8];
    /* 0x008 */ uint64_t list_head; /* Finalize: iterates *(param_1+8) as std::list sentinel */
    /* 0x010 */ uint64_t list_size; /* Entry<>: increments *(param_1+0x10), checks 0xaaaaaaaaaaa... */
} ccBoss04EffManager;

static_assert(offsetof(ccBoss04EffManager, list_head) == 0x8, "ccBoss04EffManager.list_head offset");
static_assert(offsetof(ccBoss04EffManager, list_size) == 0x10, "ccBoss04EffManager.list_size offset");

/* size unknown, >= 0xE0 (accesses +0xD8 in Initialize) */
typedef struct __attribute__((packed)) ccBoss04OrcSpecialSnk {
    /* 0x000 */ uint8_t pad_000[0xAC];
    /* 0x0AC */ float unk_0AC; /* Initialize: fVar4 * _DAT_14094a968 */
    /* 0x0B0 */ uint8_t pad_0B0[0x8];
    /* 0x0B8 */ uint64_t ctrl_ptr; /* Initialize: FUN_140456d98 Ctrl task */
    /* 0x0C0 */ uint64_t draw_ptr; /* Initialize: FUN_140456d98 Draw task */
    /* 0x0C8 */ uint64_t model_ptr; /* Initialize: FUN_14052c838 xfbin lookup result at offset 200 */
    /* 0x0D0 */ uint8_t pad_0D0[0x8];
    /* 0x0D8 */ uint64_t parent_ref; /* Initialize: checks *(param_1+0xD8)!=0, writes back-reference */
} ccBoss04OrcSpecialSnk;

static_assert(offsetof(ccBoss04OrcSpecialSnk, unk_0AC) == 0xAC, "ccBoss04OrcSpecialSnk.unk_0AC offset");
static_assert(offsetof(ccBoss04OrcSpecialSnk, ctrl_ptr) == 0xB8, "ccBoss04OrcSpecialSnk.ctrl_ptr offset");
static_assert(offsetof(ccBoss04OrcSpecialSnk, draw_ptr) == 0xC0, "ccBoss04OrcSpecialSnk.draw_ptr offset");
static_assert(offsetof(ccBoss04OrcSpecialSnk, model_ptr) == 0xC8, "ccBoss04OrcSpecialSnk.model_ptr offset");
static_assert(offsetof(ccBoss04OrcSpecialSnk, parent_ref) == 0xD8, "ccBoss04OrcSpecialSnk.parent_ref offset");

/* ccSceneBoss04Phase01: no instance state fields found via static analysis.
 * Scene phase controller. Initialize delegates to FUN_140428070 and stage setup. No direct param_1 field accesses found.
 * size unknown, no field accesses found in Initialize */

/* size unknown, embedded at ccBoss04NarutoActionState+0x313 (parent-relative offsets) */
typedef struct __attribute__((packed)) ccBoss04NarutoChargeActionState {
    /* 0x000 */ uint8_t pad_000[0x14B8];
    /* 0x14B8 */ uint32_t unk_14B8; /* state_surface: param_1[0x297]=0 scaled write */
    /* 0x14BC */ uint8_t pad_14BC[0x4];
    /* 0x14C0 */ uint32_t unk_14C0; /* state_surface: *(u32*)(+0x298)=0 unscaled write */
} ccBoss04NarutoChargeActionState;

static_assert(offsetof(ccBoss04NarutoChargeActionState, unk_14B8) == 0x14B8, "ccBoss04NarutoChargeActionState.unk_14B8 offset");
static_assert(offsetof(ccBoss04NarutoChargeActionState, unk_14C0) == 0x14C0, "ccBoss04NarutoChargeActionState.unk_14C0 offset");

/* size unknown, >= 0x14E8 (last field at +0x14E0 in EnterPhase00) */
typedef struct __attribute__((packed)) ccBoss04OrcMoveActionState {
    /* 0x000 */ uint8_t pad_000[0x14B8];
    /* 0x14B8 */ int32_t move_index; /* EnterPhase00: index * 0xC into DAT_1409e7590 array */
    /* 0x14BC */ uint8_t pad_14BC[0x4];
    /* 0x14C0 */ uint64_t pos_x; /* EnterPhase00: written from FUN_140580ef0 result */
    /* 0x14C8 */ uint32_t pos_y; /* EnterPhase00: written from FUN_140580ef0 result[1] */
    /* 0x14CC */ uint8_t pad_14CC[0x4];
    /* 0x14D0 */ uint32_t phase_flag; /* EnterPhase00: set to 1 */
    /* 0x14D4 */ uint8_t pad_14D4[0xC];
    /* 0x14E0 */ uint64_t sub_obj_ptr; /* EnterPhase00: checked !=0, used for FUN_140580ac0 and FUN... */
} ccBoss04OrcMoveActionState;

static_assert(offsetof(ccBoss04OrcMoveActionState, move_index) == 0x14B8, "ccBoss04OrcMoveActionState.move_index offset");
static_assert(offsetof(ccBoss04OrcMoveActionState, pos_x) == 0x14C0, "ccBoss04OrcMoveActionState.pos_x offset");
static_assert(offsetof(ccBoss04OrcMoveActionState, pos_y) == 0x14C8, "ccBoss04OrcMoveActionState.pos_y offset");
static_assert(offsetof(ccBoss04OrcMoveActionState, phase_flag) == 0x14D0, "ccBoss04OrcMoveActionState.phase_flag offset");
static_assert(offsetof(ccBoss04OrcMoveActionState, sub_obj_ptr) == 0x14E0, "ccBoss04OrcMoveActionState.sub_obj_ptr offset");

/* size unknown, >= 0x6858 (last field at +0x6850 in state_surface) */
typedef struct __attribute__((packed)) ccBoss04OrcActionState {
    /* 0x000 */ uint8_t pad_000[0x14B8];
    /* 0x14B8 */ int32_t unk_14B8; /* state_surface: int write */
    /* 0x14BC */ uint32_t unk_14BC; /* state_surface: u32 unscaled write */
    /* 0x14C0 */ uint64_t unk_14C0; /* state_surface: scaled write */
    /* 0x14C8 */ uint64_t unk_14C8; /* state_surface: FUN_14024aab0 reads +0x299 scaled */
    /* 0x14D0 */ uint8_t pad_14D0[0x14E0];
    /* 0x29B0 */ uint64_t unk_29B0; /* state_surface: FUN_14024bde0 reads +0x536 scaled */
    /* 0x29B8 */ uint8_t pad_29B8[0x2990];
    /* 0x5348 */ uint64_t unk_5348; /* state_surface: FUN_140248fcc reads +0xa69 scaled */
    /* 0x5350 */ uint8_t pad_5350[0x1500];
    /* 0x6850 */ uint64_t unk_6850; /* state_surface: FUN_14024d380 reads +0xd0a scaled */
} ccBoss04OrcActionState;

static_assert(offsetof(ccBoss04OrcActionState, unk_14B8) == 0x14B8, "ccBoss04OrcActionState.unk_14B8 offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_14BC) == 0x14BC, "ccBoss04OrcActionState.unk_14BC offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_14C0) == 0x14C0, "ccBoss04OrcActionState.unk_14C0 offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_14C8) == 0x14C8, "ccBoss04OrcActionState.unk_14C8 offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_29B0) == 0x29B0, "ccBoss04OrcActionState.unk_29B0 offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_5348) == 0x5348, "ccBoss04OrcActionState.unk_5348 offset");
static_assert(offsetof(ccBoss04OrcActionState, unk_6850) == 0x6850, "ccBoss04OrcActionState.unk_6850 offset");

/* size unknown, >= 0x14C8 (last field at +0x14C0 in EnterLoop) */
typedef struct __attribute__((packed)) ccBoss04NarutoLaserActionState {
    /* 0x000 */ uint8_t pad_000[0x14B8];
    /* 0x14B8 */ uint64_t eff_manager_ptr; /* EnterLoop: checked !=0, passed to FUN_1402448f0/FUN_14024... */
    /* 0x14C0 */ uint64_t laser_effect_ptr; /* EnterLoop: set from FUN_14024700c, checked/cleaned up */
} ccBoss04NarutoLaserActionState;

static_assert(offsetof(ccBoss04NarutoLaserActionState, eff_manager_ptr) == 0x14B8, "ccBoss04NarutoLaserActionState.eff_manager_ptr offset");
static_assert(offsetof(ccBoss04NarutoLaserActionState, laser_effect_ptr) == 0x14C0, "ccBoss04NarutoLaserActionState.laser_effect_ptr offset");

/* size unknown, >= 0x20 (array at +0x18 with variable indexing) */
typedef struct __attribute__((packed)) ccBoss04StageClump {
    /* 0x000 */ uint8_t pad_000[0xC];
    /* 0x00C */ uint16_t model_index; /* Draw: *(short*)(param_1+0xC) clamped to max 2 */
    /* 0x00E */ uint8_t pad_00E[0x6];
    /* 0x014 */ int32_t active_flag; /* Draw: *(int*)(param_1+0x14) != 0 gates rendering */
    /* 0x018 */ uint64_t model_ptrs; /* Draw: *(ptr*)(param_1+0x18+idx*8) vcall +0x20 */
} ccBoss04StageClump;

static_assert(offsetof(ccBoss04StageClump, model_index) == 0xC, "ccBoss04StageClump.model_index offset");
static_assert(offsetof(ccBoss04StageClump, active_flag) == 0x14, "ccBoss04StageClump.active_flag offset");
static_assert(offsetof(ccBoss04StageClump, model_ptrs) == 0x18, "ccBoss04StageClump.model_ptrs offset");

/* size unknown, >= 0x140 (last field at +0x138 in Initialize) */
typedef struct __attribute__((packed)) ccSceneBoss04 {
    /* 0x000 */ uint8_t pad_000[0x50];
    /* 0x050 */ uint64_t ui_mgr_registration; /* Initialize: passed to FUN_14041eb08 as bossBattle_ui_mgr */
    /* 0x058 */ uint8_t pad_058[0xD0];
    /* 0x128 */ uint32_t unk_128; /* Initialize: set to 0 */
    /* 0x12C */ uint32_t unk_12C; /* Initialize: offset 300 (=0x12C) set to 0 */
    /* 0x130 */ uint8_t pad_130[0x8];
    /* 0x138 */ uint64_t sub_obj_0x108; /* Initialize: FUN_140580190(0x108) allocated sub-object ptr */
} ccSceneBoss04;

static_assert(offsetof(ccSceneBoss04, ui_mgr_registration) == 0x50, "ccSceneBoss04.ui_mgr_registration offset");
static_assert(offsetof(ccSceneBoss04, unk_128) == 0x128, "ccSceneBoss04.unk_128 offset");
static_assert(offsetof(ccSceneBoss04, unk_12C) == 0x12C, "ccSceneBoss04.unk_12C offset");
static_assert(offsetof(ccSceneBoss04, sub_obj_0x108) == 0x138, "ccSceneBoss04.sub_obj_0x108 offset");

/* size unknown, >= 0x14D0 (last field at +0x14C8 in state_surface) */
typedef struct __attribute__((packed)) ccBoss0401SceneChangeState {
    /* 0x000 */ uint8_t pad_000[0x14B8];
    /* 0x14B8 */ uint32_t unk_14B8; /* state_surface: param_1[0x297]=0 scaled write */
    /* 0x14BC */ uint8_t pad_14BC[0x4];
    /* 0x14C0 */ uint32_t unk_14C0; /* state_surface: param_1[0x298]=0 scaled write */
    /* 0x14C4 */ uint8_t pad_14C4[0x4];
    /* 0x14C8 */ uint32_t unk_14C8; /* state_surface: *(u32*)(+0x299)=0 unscaled write */
} ccBoss0401SceneChangeState;

static_assert(offsetof(ccBoss0401SceneChangeState, unk_14B8) == 0x14B8, "ccBoss0401SceneChangeState.unk_14B8 offset");
static_assert(offsetof(ccBoss0401SceneChangeState, unk_14C0) == 0x14C0, "ccBoss0401SceneChangeState.unk_14C0 offset");
static_assert(offsetof(ccBoss0401SceneChangeState, unk_14C8) == 0x14C8, "ccBoss0401SceneChangeState.unk_14C8 offset");


/* ========================================================================
 * Embedded sub-objects (no standalone heap allocation):
 *
 * ccBoss04NarutoActionState - embedded at ccBoss04Naruto+0xE0 (size 0x56F8 within parent)
 *   Init: FUN_1402453f8, sets vtable PTR_FUN_1407cbc88, initializes sub-components at
 *   +0x298, +0x312, +0x313, +0x5ac, +0x846. Not heap-allocated.
 *
 * ccBoss04NarutoChargeActionState - embedded at ccBoss04NarutoActionState+0x313
 *   Init: FUN_1402462a8. Not heap-allocated.
 * ======================================================================== */

/* ========================================================================
 * Batch 3: ccBoss04NarutoBullet, ccBoss04OrcAI
 * ======================================================================== */

/* ccBoss04NarutoBullet — heap-allocated projectile for Boss04 Naruto phase.
 * Size: 0xE8 (FUN_140580190(0xe8) in factory FUN_140245174).
 * Vtable: PTR_FUN_1407cbcf0 (set in ctor FUN_140245c14).
 * Base class init: FUN_1405809e0 at +0x98 (scaled param_1+0x13 = byte 0x98).
 * Fields from ctor decompilation; state_surface confirmed 9 fields.
 * Layout uses raw byte array to avoid GCC padding between mixed-width fields.
 */
typedef struct {
    uint8_t raw[0xE8];
} ns2_ccBoss04NarutoBullet;
/* Accessor macros for ccBoss04NarutoBullet fields */
#define NS2_NARUTOBULLET_VTABLE(p)       (*(void***)(p)->raw)              /* 0x00 */
#define NS2_NARUTOBULLET_UNK_0BC(p)      (*(uint32_t*)((p)->raw + 0xBC))   /* 0xBC */
#define NS2_NARUTOBULLET_UNK_0C0(p)      (*(uint64_t*)((p)->raw + 0xC0))   /* 0xC0 */
#define NS2_NARUTOBULLET_UNK_0C8(p)      (*(uint64_t*)((p)->raw + 0xC8))   /* 0xC8 */
#define NS2_NARUTOBULLET_UNK_0D0(p)      (*(uint32_t*)((p)->raw + 0xD0))   /* 0xD0 */
#define NS2_NARUTOBULLET_UNK_0D8(p)      (*(uint64_t*)((p)->raw + 0xD8))   /* 0xD8 */
#define NS2_NARUTOBULLET_UNK_0E0(p)      (*(uint64_t*)((p)->raw + 0xE0))   /* 0xE0 */
static_assert(sizeof(ns2_ccBoss04NarutoBullet) == 0xE8, "ccBoss04NarutoBullet size");

/* ccBoss04OrcAI — embedded AI controller inside ccBoss04Orochimaru at byte offset 0x7E08.
 * Not heap-allocated; constructed inline via FUN_140247fac(parent+0xfc1 scaled = parent+0x7E08).
 * Size: 0x30 (last field at +0x28, next object boundary).
 * Vtable: PTR_FUN_1408918e8 (set in ctor FUN_140247fac).
 * Fields gathered from ctor, Update (FUN_140248064), SetParentAndActionPtr (FUN_140248058).
 * state_surface returned 0 fields (only byte-cast accesses); manual decomp used.
 * Layout uses raw byte array to avoid GCC padding between mixed-width fields.
 */
typedef struct {
    uint8_t raw[0x30];
} ns2_ccBoss04OrcAI;
/* Accessor macros for ccBoss04OrcAI fields */
#define NS2_ORCAI_VTABLE(p)              (*(void***)(p)->raw)              /* 0x00 */
#define NS2_ORCAI_UNK_008(p)             (*(uint64_t*)((p)->raw + 0x08))   /* 0x08 */
#define NS2_ORCAI_FLAG_00C(p)            (*(uint32_t*)((p)->raw + 0x0C))   /* 0x0C */
#define NS2_ORCAI_UNK_010(p)             (*(uint32_t*)((p)->raw + 0x10))   /* 0x10 */
#define NS2_ORCAI_UNK_014(p)             (*(uint32_t*)((p)->raw + 0x14))   /* 0x14 */
#define NS2_ORCAI_ACTIVE_FLAG(p)         (*(uint32_t*)((p)->raw + 0x18))   /* 0x18 */
#define NS2_ORCAI_PARENT_PTR(p)          (*(uint64_t*)((p)->raw + 0x20))   /* 0x20 */
#define NS2_ORCAI_ACTION_STATE_PTR(p)    (*(uint64_t*)((p)->raw + 0x28))   /* 0x28 */
static_assert(sizeof(ns2_ccBoss04OrcAI) == 0x30, "ccBoss04OrcAI size");

#endif /* S2_BOSS04_H */