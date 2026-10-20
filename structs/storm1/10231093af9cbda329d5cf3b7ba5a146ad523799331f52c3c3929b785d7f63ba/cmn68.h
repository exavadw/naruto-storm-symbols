/* cmn68.h — struct group cmn68 for build s1 (NSUNS1.exe, NARUTO STORM 1 PC)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Build: s1 / NSUNS1.exe-a9fe00 / SHA256 10231093af9c...
 * Sizes proven from allocator calls unless noted.
 */

#include <stdint.h>
#include <stddef.h>

/* ------------------------------------------------------------------ */
/* nuccSprite                                                         */
/* Size: 0x90 (proven: ccFileLoadListForUi::LoadTh(0x90,...) in       */
/*   ccDispSprite::Create @0x19F838, ccDuelChangeModeDisp::Init       */
/*   @0x19FFD8, ccDispSprite::CreateDuelNamePlate @0x1A00A8)         */
/* Vtable: PTR_FUN_14065f2c8 (ctor 0x4AE930 variant)                 */
/*         PTR_FUN_140739760 (ctor 0x19E6DC variant)                  */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSprite {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[8];          /* alignment / unused */
    /* 0x10 */ uint16_t id;                 /* ctor param, set in 0x19E6DC */
    /* 0x12 */ uint8_t _pad_12[6];          /* padding to 0x18 */
    /* 0x18 */ void *chunk_ptr;             /* longlong*, SetChunk/_DrawType2 deref via vcall+8 */
    /* 0x20 */ uint64_t unknown_20;         /* set to 0 in ctor 0x4AE930 */
    /* 0x28 */ void *parts_data;            /* SetChunk allocates/frees, _DrawType2 iterates */
    /* 0x30 */ float pos_x;                 /* Vector3 position.x — SetPos writes */
    /* 0x34 */ float pos_y;                 /* Vector3 position.y */
    /* 0x38 */ float pos_z;                 /* Vector3 position.z */
    /* 0x3C */ float scale_x;               /* Vector2 scale.x — SetScale checks */
    /* 0x40 */ float scale_y;               /* Vector2 scale.y */
    /* 0x44 */ float center_x;              /* Vector2 center.x — SetCenter checks */
    /* 0x48 */ float center_y;              /* Vector2 center.y */
    /* 0x4C */ uint8_t _pad_4c[4];          /* padding to 0x50 */
    /* 0x50 */ float color_r;               /* RGBA color, Reset sets 1.0f */
    /* 0x54 */ float color_g;
    /* 0x58 */ float color_b;
    /* 0x5C */ float alpha;                 /* SetAlpha writes, Reset sets 1.0f */
    /* 0x60 */ int32_t rotate_fixed;        /* radians * 65536 / 2pi — SetRotate */
    /* 0x64 */ uint8_t _pad_64[12];         /* padding to 0x70 */
    /* 0x70 */ void *core_ptr;              /* freed via FreeCore in SetChunk */
    /* 0x78 */ int32_t dirty_flag;          /* SetScale/SetCenter/Reset set 1; _TransformVertex checks */
    /* 0x7C */ uint8_t _pad_7c[4];          /* padding to 0x80 */
    /* 0x80 */ uint16_t unknown_80;         /* ctor 0x19E6DC sets to 0 */
    /* 0x82 */ uint8_t _pad_82[2];          /* padding */
    /* 0x84 */ uint32_t unknown_84;         /* ctor 0x19E6DC sets to 1 */
    /* 0x88 */ uint8_t _pad_88[8];          /* padding to 0x90 */
} nuccSprite;

_Static_assert(offsetof(nuccSprite, vtable) == 0x00, "nuccSprite.vtable");
_Static_assert(offsetof(nuccSprite, id) == 0x10, "nuccSprite.id");
_Static_assert(offsetof(nuccSprite, chunk_ptr) == 0x18, "nuccSprite.chunk_ptr");
_Static_assert(offsetof(nuccSprite, unknown_20) == 0x20, "nuccSprite.unknown_20");
_Static_assert(offsetof(nuccSprite, parts_data) == 0x28, "nuccSprite.parts_data");
_Static_assert(offsetof(nuccSprite, pos_x) == 0x30, "nuccSprite.pos_x");
_Static_assert(offsetof(nuccSprite, pos_y) == 0x34, "nuccSprite.pos_y");
_Static_assert(offsetof(nuccSprite, pos_z) == 0x38, "nuccSprite.pos_z");
_Static_assert(offsetof(nuccSprite, scale_x) == 0x3C, "nuccSprite.scale_x");
_Static_assert(offsetof(nuccSprite, scale_y) == 0x40, "nuccSprite.scale_y");
_Static_assert(offsetof(nuccSprite, center_x) == 0x44, "nuccSprite.center_x");
_Static_assert(offsetof(nuccSprite, center_y) == 0x48, "nuccSprite.center_y");
_Static_assert(offsetof(nuccSprite, color_r) == 0x50, "nuccSprite.color_r");
_Static_assert(offsetof(nuccSprite, color_g) == 0x54, "nuccSprite.color_g");
_Static_assert(offsetof(nuccSprite, color_b) == 0x58, "nuccSprite.color_b");
_Static_assert(offsetof(nuccSprite, alpha) == 0x5C, "nuccSprite.alpha");
_Static_assert(offsetof(nuccSprite, rotate_fixed) == 0x60, "nuccSprite.rotate_fixed");
_Static_assert(offsetof(nuccSprite, core_ptr) == 0x70, "nuccSprite.core_ptr");
_Static_assert(offsetof(nuccSprite, dirty_flag) == 0x78, "nuccSprite.dirty_flag");
_Static_assert(offsetof(nuccSprite, unknown_80) == 0x80, "nuccSprite.unknown_80");
_Static_assert(offsetof(nuccSprite, unknown_84) == 0x84, "nuccSprite.unknown_84");
_Static_assert(sizeof(nuccSprite) == 0x90, "nuccSprite size 0x90");

/* ------------------------------------------------------------------ */
/* nuccSpriteAnm                                                      */
/* Inherits nuccSprite. Allocation size 0x50 proven:                  */
/*   ccFileLoadListForUi::LoadTh(0x50,...) in ccDispSpriteAnm::Create */
/*   @0x19F918. This is SMALLER than nuccSprite (0x90), meaning       */
/*   nuccSpriteAnm does NOT embed a full nuccSprite — it uses a       */
/*   separate, smaller layout with a sprite pointer at +0x28.         */
/* Vtable: PTR_FUN_14065f2e8                                          */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSpriteAnm {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[8];          /* alignment */
    /* 0x10 */ uint16_t id;                 /* inherited pattern from nuccSprite */
    /* 0x12 */ uint8_t _pad_12[6];
    /* 0x18 */ void *anm_chunk;             /* animation chunk data */
    /* 0x20 */ uint8_t _pad_20[8];
    /* 0x28 */ nuccSprite *sprite;          /* ApplySprite stores, Animate passes to SetParts* */
    /* 0x30 */ int32_t frame_counter;       /* Elapse increments by delta */
    /* 0x34 */ int32_t total_frames;        /* Elapse bounds-checks against */
    /* 0x38 */ uint16_t flags;              /* bit0=loop, bit1=owns_sprite */
    /* 0x3A */ uint8_t _pad_3a[6];
    /* 0x40 */ uint64_t sprite_ref;         /* ApplySprite stores */
    /* 0x48 */ uint8_t _pad_48[4];
    /* 0x4C */ uint32_t unknown_4c;         /* ctor 0x19E724 sets to 1 */
} nuccSpriteAnm;

_Static_assert(offsetof(nuccSpriteAnm, vtable) == 0x00, "nuccSpriteAnm.vtable");
_Static_assert(offsetof(nuccSpriteAnm, id) == 0x10, "nuccSpriteAnm.id");
_Static_assert(offsetof(nuccSpriteAnm, anm_chunk) == 0x18, "nuccSpriteAnm.anm_chunk");
_Static_assert(offsetof(nuccSpriteAnm, sprite) == 0x28, "nuccSpriteAnm.sprite");
_Static_assert(offsetof(nuccSpriteAnm, frame_counter) == 0x30, "nuccSpriteAnm.frame_counter");
_Static_assert(offsetof(nuccSpriteAnm, total_frames) == 0x34, "nuccSpriteAnm.total_frames");
_Static_assert(offsetof(nuccSpriteAnm, flags) == 0x38, "nuccSpriteAnm.flags");
_Static_assert(offsetof(nuccSpriteAnm, sprite_ref) == 0x40, "nuccSpriteAnm.sprite_ref");
_Static_assert(offsetof(nuccSpriteAnm, unknown_4c) == 0x4C, "nuccSpriteAnm.unknown_4c");
_Static_assert(sizeof(nuccSpriteAnm) == 0x50, "nuccSpriteAnm size 0x50");

/* ------------------------------------------------------------------ */
/* nuccStreamFile                                                     */
/* Size unknown, >= 0x818 (last proven field buffer_pos at 0x814,     */
/*   4 bytes). No standalone operator new found; embedded at +0x48    */
/*   in nuccParticleGenerator. Buffer is hardcoded 0x800 bytes.       */
/* Vtable: PTR_FUN_140743eb0 (active), PTR_FUN_14073df60 (alt),      */
/*         PTR_FUN_1407393c0 (dtor-set), PTR_FUN_140739320 (final)   */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccStreamFile {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint32_t file_handle;       /* nummFileRead/Write/Close/Seek use this */
    /* 0x00C */ int32_t mode_flags;         /* Close/Seek check != 0 before buffer flush */
    /* 0x010 */ uint8_t buffer[0x800];      /* memcpy source/dest in Read/Close/Write */
    /* 0x810 */ int32_t buffered_size;      /* Read stores nummFileRead result */
    /* 0x814 */ int32_t buffer_pos;         /* Read/Seek/Close/Write read and update */
    /* 0x818 */ /* size unknown beyond this point */
} nuccStreamFile;

_Static_assert(offsetof(nuccStreamFile, vtable) == 0x000, "nuccStreamFile.vtable");
_Static_assert(offsetof(nuccStreamFile, file_handle) == 0x008, "nuccStreamFile.file_handle");
_Static_assert(offsetof(nuccStreamFile, mode_flags) == 0x00C, "nuccStreamFile.mode_flags");
_Static_assert(offsetof(nuccStreamFile, buffer) == 0x010, "nuccStreamFile.buffer");
_Static_assert(offsetof(nuccStreamFile, buffered_size) == 0x810, "nuccStreamFile.buffered_size");
_Static_assert(offsetof(nuccStreamFile, buffer_pos) == 0x814, "nuccStreamFile.buffer_pos");
/* No sizeof assert — size unproven beyond 0x818 */