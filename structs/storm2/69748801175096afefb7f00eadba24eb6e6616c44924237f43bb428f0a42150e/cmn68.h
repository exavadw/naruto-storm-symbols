/* cmn68.h — struct group cmn68 for build s2 (NSUNS2.exe, NARUTO STORM 2 PC)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Build: s2 / NSUNS2.exe-abf2b6 / SHA256 697488011750...
 * Sizes proven from allocator calls unless noted.
 */

#include <stdint.h>
#include <stddef.h>

/* ------------------------------------------------------------------ */
/* nuccSprite                                                          */
/* Size: 0x80 (proven: ccFileLoadListForUi::LoadTh(0x80,...) in       */
/*   ccScenePauseDuel::Initialize @0x469888,                           */
/*   nuccSpriteAnm::SetAnm @0x5C6850,                                  */
/*   nuccChunkSprite::Create @0x5E78F0)                                */
/* Vtable: PTR_FUN_1408936a8 (ctor 0x5C3280 BlockAllocator variant)   */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSprite {
/* 0x00 */ void *vtable;              /* ctor sets PTR_FUN_1408936a8 */
/* 0x08 */ uint8_t _pad_08[8];        /* alignment / base class padding */
/* 0x10 */ uint8_t _pad_10[8];        /* gap: no field evidence in s2 */
/* 0x18 */ void *chunk_ptr;           /* SetChunk writes, _TransformVertex reads */
/* 0x20 */ uint64_t unknown_20;       /* ctor param_1[4]=0 */
/* 0x28 */ void *parts_data;          /* SetChunk allocates/frees via FreeCore */
/* 0x30 */ float pos_x;               /* Vector3 position.x — SetPos writes, GetPos returns &0x30 */
/* 0x34 */ float pos_y;               /* Vector3 position.y */
/* 0x38 */ float pos_z;               /* Vector3 position.z */
/* 0x3C */ float scale_x;             /* Vector2 scale.x — SetScale checks, GetScaleX reads */
/* 0x40 */ float scale_y;             /* Vector2 scale.y — SetScale checks, GetScaleY reads */
/* 0x44 */ float center_x;            /* Vector2 center.x — GetCenter returns &0x44 */
/* 0x48 */ float center_y;            /* Vector2 center.y */
/* 0x4C */ uint8_t _pad_4c[4];        /* gap: no field evidence between center and color */
/* 0x50 */ float color_r;             /* RGBA color, Reset sets 1.0f */
/* 0x54 */ float color_g;             /* Reset sets 1.0f */
/* 0x58 */ float color_b;             /* Reset sets 1.0f */
/* 0x5C */ float alpha;               /* SetAlpha writes, GetAlpha reads, Reset sets 1.0f */
/* 0x60 */ uint8_t _pad_60[4];        /* gap: no field evidence between alpha and draw_attr */
/* 0x64 */ uint32_t draw_attr;        /* AddDrawAttr ORs into this, Reset sets 0x3e60 */
/* 0x68 */ uint8_t _pad_68[8];        /* gap: no field evidence */
/* 0x70 */ uint64_t unknown_70;       /* ctor param_1[0xe]=0 */
/* 0x78 */ int32_t dirty_flag;        /* SetScale/Reset set 1; _TransformVertex checks != 0 */
/* 0x7C */ uint8_t _pad_7c[4];        /* padding to 0x80 */
} nuccSprite;

_Static_assert(offsetof(nuccSprite, vtable) == 0x00, "nuccSprite.vtable");
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
_Static_assert(offsetof(nuccSprite, draw_attr) == 0x64, "nuccSprite.draw_attr");
_Static_assert(offsetof(nuccSprite, unknown_70) == 0x70, "nuccSprite.unknown_70");
_Static_assert(offsetof(nuccSprite, dirty_flag) == 0x78, "nuccSprite.dirty_flag");
_Static_assert(sizeof(nuccSprite) == 0x80, "nuccSprite size 0x80");

/* ------------------------------------------------------------------ */
/* nuccSpriteAnm                                                       */
/* Size: 0x48 (proven: ccFileLoadListForUi::LoadTh(0x48,...) in       */
/*   nuccChunkSpriteAnm::Create @0x5E7F00)                             */
/* Does NOT embed nuccSprite; holds a pointer to one at +0x28.         */
/* Vtable: PTR_FUN_140894670 (ctor 0x5C6360)                          */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSpriteAnm {
/* 0x00 */ void *vtable;              /* ctor 0x5C6360 sets PTR_FUN_140894670 */
/* 0x08 */ uint8_t _pad_08[8];        /* alignment */
/* 0x10 */ uint8_t _pad_10[8];        /* gap: no field evidence */
/* 0x18 */ void *anm_chunk;           /* Animate reads, SetAnm writes, dtor checks */
/* 0x20 */ uint8_t _pad_20[8];        /* gap: no field evidence */
/* 0x28 */ void *sprite;              /* Draw delegates to nuccSprite::Draw(*(ptr+0x28)) */
/* 0x30 */ int32_t frame_counter;     /* Elapse increments by delta, Animate divides by 100 */
/* 0x34 */ int32_t total_frames;      /* Elapse bounds-checks against this */
/* 0x38 */ uint16_t flags;            /* bit0=loop (Elapse &1), bit1=owns_sprite (dtor &2) */
/* 0x3A */ uint8_t _pad_3a[6];        /* padding to 0x40 */
/* 0x40 */ uint64_t sprite_ref;       /* SetAnm checks == 0 before creating sprite */
} nuccSpriteAnm;

_Static_assert(offsetof(nuccSpriteAnm, vtable) == 0x00, "nuccSpriteAnm.vtable");
_Static_assert(offsetof(nuccSpriteAnm, anm_chunk) == 0x18, "nuccSpriteAnm.anm_chunk");
_Static_assert(offsetof(nuccSpriteAnm, sprite) == 0x28, "nuccSpriteAnm.sprite");
_Static_assert(offsetof(nuccSpriteAnm, frame_counter) == 0x30, "nuccSpriteAnm.frame_counter");
_Static_assert(offsetof(nuccSpriteAnm, total_frames) == 0x34, "nuccSpriteAnm.total_frames");
_Static_assert(offsetof(nuccSpriteAnm, flags) == 0x38, "nuccSpriteAnm.flags");
_Static_assert(offsetof(nuccSpriteAnm, sprite_ref) == 0x40, "nuccSpriteAnm.sprite_ref");
_Static_assert(sizeof(nuccSpriteAnm) == 0x48, "nuccSpriteAnm size 0x48");

/* ------------------------------------------------------------------ */
/* nuccStreamFile                                                      */
/* ABSENT FROM s2: no valid methods found. The 6 symbols named         */
/* nuccStreamFile::* in the s2 DB are misnamed CRI middleware and      */
/* UI classes (criVdec, criAtomAwbToc, ccUiObject, nuccCamera,         */
/* ccTaskBase). nummFileRead does not exist in s2. storm_map from      */
/* s1 gives only low-confidence wrong targets.                         */
/* This class was present in s1 (size >= 0x818) but appears to have    */
/* been removed or heavily refactored in s2.                            */
/* No struct definition provided.                                      */
/* ------------------------------------------------------------------ */