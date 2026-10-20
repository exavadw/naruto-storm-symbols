/* cmn68.h — struct group cmn68 for build s3 (NSUNS3.exe, NARUTO STORM 3 Full Burst HD PC)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Build: s3 / NSUNS3.exe-a7124b / SHA256 55b726e94dad...
 * Sizes proven from allocator calls unless noted.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* nuccSprite                                                          */
/* Size: 0x80 (proven: ccFileLoadListForUi::LoadTh(0x80,...) in       */
/*   nuccSpriteAnm::SetAnm @0x6CADC0,                                */
/*   nuccChunkSprite::Create @0x6F3EC0)                                */
/* Vtable: PTR_FUN_1409e2df0 (ctor 0x6CA9D0 BlockAllocator variant)   */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSprite {
/* 0x00 */ void *vtable;              /* ctor sets PTR_FUN_1409e2df0 */
/* 0x08 */ uint8_t _pad_08[8];        /* alignment / base class padding */
/* 0x10 */ uint8_t _pad_10[8];        /* gap: no field evidence in s3 */
/* 0x18 */ void *chunk_ptr;           /* SetChunk writes, vcall+8 reads */
/* 0x20 */ uint64_t unknown_20;       /* ctor param_1[3]=0 (after Reset clears) */
/* 0x28 */ void *parts_data;          /* SetChunk allocates/frees via FreeCore */
/* 0x30 */ float pos_x;               /* Vector3 position.x — Reset sets via Vector3::zero */
/* 0x34 */ float pos_y;               /* Vector3 position.y */
/* 0x38 */ float pos_z;               /* Vector3 position.z */
/* 0x3C */ float scale_x;             /* Vector2 scale.x — Reset sets via Vector2::one */
/* 0x40 */ float scale_y;             /* Vector2 scale.y */
/* 0x44 */ float center_x;            /* Vector2 center.x — Reset sets via Vector2::zero */
/* 0x48 */ float center_y;            /* Vector2 center.y */
/* 0x4C */ uint8_t _pad_4c[4];        /* gap: no field evidence between center and color */
/* 0x50 */ float color_r;             /* RGBA color, Reset sets 1.0f */
/* 0x54 */ float color_g;             /* Reset sets 1.0f */
/* 0x58 */ float color_b;             /* Reset sets 1.0f */
/* 0x5C */ float alpha;               /* Reset sets 1.0f (written as undefined8 at +0x5c) */
/* 0x60 */ uint8_t _pad_60[4];        /* gap: no field evidence between alpha and draw_attr */
/* 0x64 */ uint32_t draw_attr;        /* Reset sets 0x3e60 (written as undefined8 at +100) */
/* 0x68 */ uint8_t _pad_68[8];        /* gap: no field evidence */
/* 0x70 */ uint64_t unknown_70;       /* ctor param_1[0xe]=0; SetChunk checks !=0 and frees */
/* 0x78 */ int32_t dirty_flag;        /* ctor sets 1; Reset sets 1 */
/* 0x7C */ uint8_t _pad_7c[4];        /* padding to 0x80 */
} nuccSprite;

static_assert(offsetof(nuccSprite, vtable) == 0x00, "nuccSprite.vtable");
static_assert(offsetof(nuccSprite, chunk_ptr) == 0x18, "nuccSprite.chunk_ptr");
static_assert(offsetof(nuccSprite, unknown_20) == 0x20, "nuccSprite.unknown_20");
static_assert(offsetof(nuccSprite, parts_data) == 0x28, "nuccSprite.parts_data");
static_assert(offsetof(nuccSprite, pos_x) == 0x30, "nuccSprite.pos_x");
static_assert(offsetof(nuccSprite, pos_y) == 0x34, "nuccSprite.pos_y");
static_assert(offsetof(nuccSprite, pos_z) == 0x38, "nuccSprite.pos_z");
static_assert(offsetof(nuccSprite, scale_x) == 0x3C, "nuccSprite.scale_x");
static_assert(offsetof(nuccSprite, scale_y) == 0x40, "nuccSprite.scale_y");
static_assert(offsetof(nuccSprite, center_x) == 0x44, "nuccSprite.center_x");
static_assert(offsetof(nuccSprite, center_y) == 0x48, "nuccSprite.center_y");
static_assert(offsetof(nuccSprite, color_r) == 0x50, "nuccSprite.color_r");
static_assert(offsetof(nuccSprite, color_g) == 0x54, "nuccSprite.color_g");
static_assert(offsetof(nuccSprite, color_b) == 0x58, "nuccSprite.color_b");
static_assert(offsetof(nuccSprite, alpha) == 0x5C, "nuccSprite.alpha");
static_assert(offsetof(nuccSprite, draw_attr) == 0x64, "nuccSprite.draw_attr");
static_assert(offsetof(nuccSprite, unknown_70) == 0x70, "nuccSprite.unknown_70");
static_assert(offsetof(nuccSprite, dirty_flag) == 0x78, "nuccSprite.dirty_flag");
static_assert(sizeof(nuccSprite) == 0x80, "nuccSprite size 0x80");

/* ------------------------------------------------------------------ */
/* nuccSpriteAnm                                                       */
/* Size: unknown, >= 0x50 (ctor2 @0x8126D0 writes at offset 0x4c;     */
/*   no LoadTh size argument found for nuccSpriteAnm allocation in s3) */
/* Does NOT embed nuccSprite; holds a pointer to one at +0x28.         */
/* Vtable: PTR_FUN_1409e2e38 (ctor 0x6CAD00); subclass vtable         */
/*   PTR_FUN_140a0b770 (ctor2 0x8126D0)                               */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccSpriteAnm {
/* 0x00 */ void *vtable;              /* ctor 0x6CAD00 sets PTR_FUN_1409e2e38 */
/* 0x08 */ uint8_t _pad_08[8];        /* alignment */
/* 0x10 */ uint8_t _pad_10[8];        /* gap: no field evidence */
/* 0x18 */ void *anm_chunk;           /* SetAnm writes, Draw reads (lua_gc call) */
/* 0x20 */ uint8_t _pad_20[8];        /* gap: no field evidence */
/* 0x28 */ void *sprite;              /* SetAnm creates/assigns; dtor deletes if owns */
/* 0x30 */ int32_t frame_counter;     /* SetAnm resets to 0 */
/* 0x34 */ int32_t total_frames;      /* SetAnm copies from chunk+0x4c */
/* 0x38 */ uint16_t flags;            /* bit1=owns_sprite (dtor &2, SetAnm sets/clears) */
/* 0x3A */ uint8_t _pad_3a[6];        /* padding to 0x40 */
/* 0x40 */ uint64_t sprite_ref;       /* SetAnm checks ==0 before creating sprite */
/* 0x48 */ uint8_t _pad_48[8];        /* gap: ctor2 accesses 0x4a,0x4c but semantics unknown */
} nuccSpriteAnm;

static_assert(offsetof(nuccSpriteAnm, vtable) == 0x00, "nuccSpriteAnm.vtable");
static_assert(offsetof(nuccSpriteAnm, anm_chunk) == 0x18, "nuccSpriteAnm.anm_chunk");
static_assert(offsetof(nuccSpriteAnm, sprite) == 0x28, "nuccSpriteAnm.sprite");
static_assert(offsetof(nuccSpriteAnm, frame_counter) == 0x30, "nuccSpriteAnm.frame_counter");
static_assert(offsetof(nuccSpriteAnm, total_frames) == 0x34, "nuccSpriteAnm.total_frames");
static_assert(offsetof(nuccSpriteAnm, flags) == 0x38, "nuccSpriteAnm.flags");
static_assert(offsetof(nuccSpriteAnm, sprite_ref) == 0x40, "nuccSpriteAnm.sprite_ref");
/* No sizeof assert: size unproven, >= 0x50 */

/* ------------------------------------------------------------------ */
/* nuccStreamFile                                                      */
/* Size: unknown, >= 0x1218 (Flush @0x73580 accesses field at 0x1210) */
/* Only 2 valid methods found: ctor @0x729290 and Flush @0x73580.     */
/* Other DB symbols named nuccStreamFile::* are misnamed CRI/UI classes */
/* (criVdec, criAtomAwbToc, ccTaskBase, nuccCamera wrappers).         */
/* Vtable: PTR_FUN_1409ea4a8 (ctor 0x729290)                          */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) nuccStreamFile {
/* 0x00 */ void *vtable;              /* ctor sets PTR_FUN_1409ea4a8 */
/* 0x08 */ uint8_t _pad_08[12];       /* gap: no field evidence */
/* 0x14 */ uint32_t unknown_14;       /* ctor sets 0 */
/* 0x18 */ uint8_t _pad_18[8];        /* gap: Flush@0x248344 (misnamed?) writes +0x18 */
/* 0x20 */ void *cri_handle;          /* Flush reads for criVdec_DecodeFrame/criDelegate_EndInvoke */
/* 0x28 */ uint8_t _pad_28[0x95C];    /* gap: fields between 0x28 and 0x984 not individually mapped */
/* 0x984 */ int32_t buffer_size_base; /* Flush reads, adds 0x800 */
/* 0x988 */ uint8_t _pad_988[0x380];  /* gap: sparse accesses at 0x998,0x9cc..0xd38,0xd64,0xd78,0xd88 */
/* 0xD08 */ uint8_t _pad_d08[0x400];  /* gap to 0x1108 */
/* 0x1108 */ void *awb_toc_handle_1;  /* Flush: criAtomAwbToc_GetBinderHandle */
/* 0x1110 */ void *awb_toc_handle_2;  /* Flush: criAtomAwbToc_GetBinderHandle */
/* 0x1118 */ uint8_t _pad_1118[0x60]; /* gap to 0x1178 */
/* 0x1178 */ void *write_buffer;      /* Flush: nummFileWrite 2nd arg */
/* 0x1180 */ uint8_t _pad_1180[0x88]; /* gap to 0x1208 */
/* 0x1208 */ uint8_t _pad_1208[4];    /* gap */
/* 0x120C */ int32_t computed_size;   /* Flush accumulates total size here */
/* 0x1210 */ void *decode_flag;       /* Flush checks !=0 before decode calls */
/* 0x1218 */ uint8_t _pad_1218[0];    /* end marker; size >= 0x1218 */
} nuccStreamFile;

static_assert(offsetof(nuccStreamFile, vtable) == 0x00, "nuccStreamFile.vtable");
static_assert(offsetof(nuccStreamFile, unknown_14) == 0x14, "nuccStreamFile.unknown_14");
static_assert(offsetof(nuccStreamFile, cri_handle) == 0x20, "nuccStreamFile.cri_handle");
static_assert(offsetof(nuccStreamFile, buffer_size_base) == 0x984, "nuccStreamFile.buffer_size_base");
static_assert(offsetof(nuccStreamFile, awb_toc_handle_1) == 0x1108, "nuccStreamFile.awb_toc_handle_1");
static_assert(offsetof(nuccStreamFile, awb_toc_handle_2) == 0x1110, "nuccStreamFile.awb_toc_handle_2");
static_assert(offsetof(nuccStreamFile, write_buffer) == 0x1178, "nuccStreamFile.write_buffer");
static_assert(offsetof(nuccStreamFile, computed_size) == 0x120C, "nuccStreamFile.computed_size");
static_assert(offsetof(nuccStreamFile, decode_flag) == 0x1210, "nuccStreamFile.decode_flag");
/* No sizeof assert: size unproven, >= 0x1218 */