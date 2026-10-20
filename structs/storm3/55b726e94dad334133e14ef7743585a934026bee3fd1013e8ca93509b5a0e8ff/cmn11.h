/*
 * cmn11.h — ccUiFont group struct layouts for NARUTO STORM 3 Full Burst HD PC (s3)
 *
 * INFERRED from static decompilation of NSUNS3.exe (sha 55b726e94dad).
 * NOT CONFIRMED at runtime. All offsets derived from s3 x64 pseudocode.
 * Field names carried from s2 where semantics match; all offsets re-derived.
 * Own-game names only (ns3:: namespace for s3).
 *
 * Object sizes proven from allocator calls:
 * ccUiFont::_Command: LoadTh(0xa0) in ccUiFont ctor → size = 0xA0
 * ccUiFontCustom: LoadTh(0x180) in ccUiFont::Initialize → size = 0x180
 * ccUiFontCustomApp: inherits ccUiFontCustom base (0x180), extends to >= 0x1C8
 * ccUiFont: unproven (allocated via ccGetUiObjectChunk factory), last field at 0x1E4
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiFont::_Command — inner command struct used by the font renderer.
 * param_1 in _Command::Clear is uint*, so index N = byte offset N*4.
 * Size proven: LoadTh(0xa0) in ccUiFont ctor pool allocation.
 * Vtable: PTR_FUN_1409edf38 (set in ctor after BlockAllocator init)
 */
typedef struct __attribute__((packed)) ccUiFont_Command {
    uint32_t flags;             /* 0x00: bitfield, Clear sets & 0xffffff9e | 0x1e */
    float pos_x;                /* 0x04: Vector3.x from zAxis() default */
    float pos_y;                /* 0x08: Vector3.y */
    float pos_z;                /* 0x0C: Vector3.z */
    float scale_x;              /* 0x10: Vector3.x from zero() default */
    float scale_y;              /* 0x14: Vector3.y */
    float scale_z;              /* 0x18: Vector3.z */
    float pivot_x;              /* 0x1C: Vector2.x from one() default */
    float pivot_y;              /* 0x20: Vector2.y */
    float offset_x;             /* 0x24: Vector2.x from zero() default */
    float offset_y;             /* 0x28: Vector2.y */
    uint8_t color_r;            /* 0x2C: 0xff default (param_1[0xd] as uint*) */
    uint8_t color_g;            /* 0x2D */
    uint8_t color_b;            /* 0x2E */
    uint8_t color_a;            /* 0x2F: 0xff default (param_1[0xe] as uint*) */
    uint32_t text_id;           /* 0x30: 0xffffffff default (param_1[0x20]) */
    uint32_t draw_attr;         /* 0x34: 0 default (param_1[0x21]) */
    uint32_t fence_mode;        /* 0x38: 0 default (param_1[0x22]) */
    uint32_t layer_id;          /* 0x3C: 3 default (param_1[0x24]) */
    uint32_t kerning;           /* 0x40: conditional 0xc0000000 (param_1[5]) */
    uint32_t _pad_44;           /* 0x44: padding */
    uint32_t _pad_48;           /* 0x48: padding */
    uint32_t _pad_4C;           /* 0x4C: padding to std::string */
    uint8_t text[0x20];         /* 0x50: std::basic_string<char>, 0x20 bytes (opaque) */
    uint32_t char_skip_num;     /* 0x70: param_1[0x1c] in Clear */
    uint32_t draw_char_length;  /* 0x74: param_1[0x1d] in Clear */
    uint32_t bg_layer;          /* 0x78: param_1[0x1e] = 0 in Clear */
    uint32_t reserve;           /* 0x7C: param_1[0x1f] in Clear */
    uint32_t draw_icon;         /* 0x80: param_1[0x20] in Clear */
    uint32_t alpha_font;        /* 0x84: param_1[0x21] in Clear */
    uint32_t ruby_height;       /* 0x88: param_1[0x22] in Clear */
    uint8_t _pad_8C[0x14];      /* 0x8C: gap to reach proven size 0xA0 */
} ccUiFont_Command;
static_assert(offsetof(ccUiFont_Command, flags) == 0x00, "ccUiFont_Command.flags");
static_assert(offsetof(ccUiFont_Command, pos_x) == 0x04, "ccUiFont_Command.pos_x");
static_assert(offsetof(ccUiFont_Command, pos_y) == 0x08, "ccUiFont_Command.pos_y");
static_assert(offsetof(ccUiFont_Command, pos_z) == 0x0C, "ccUiFont_Command.pos_z");
static_assert(offsetof(ccUiFont_Command, scale_x) == 0x10, "ccUiFont_Command.scale_x");
static_assert(offsetof(ccUiFont_Command, scale_y) == 0x14, "ccUiFont_Command.scale_y");
static_assert(offsetof(ccUiFont_Command, scale_z) == 0x18, "ccUiFont_Command.scale_z");
static_assert(offsetof(ccUiFont_Command, pivot_x) == 0x1C, "ccUiFont_Command.pivot_x");
static_assert(offsetof(ccUiFont_Command, pivot_y) == 0x20, "ccUiFont_Command.pivot_y");
static_assert(offsetof(ccUiFont_Command, offset_x) == 0x24, "ccUiFont_Command.offset_x");
static_assert(offsetof(ccUiFont_Command, offset_y) == 0x28, "ccUiFont_Command.offset_y");
static_assert(offsetof(ccUiFont_Command, color_r) == 0x2C, "ccUiFont_Command.color_r");
static_assert(offsetof(ccUiFont_Command, color_g) == 0x2D, "ccUiFont_Command.color_g");
static_assert(offsetof(ccUiFont_Command, color_b) == 0x2E, "ccUiFont_Command.color_b");
static_assert(offsetof(ccUiFont_Command, color_a) == 0x2F, "ccUiFont_Command.color_a");
static_assert(offsetof(ccUiFont_Command, text_id) == 0x30, "ccUiFont_Command.text_id");
static_assert(offsetof(ccUiFont_Command, draw_attr) == 0x34, "ccUiFont_Command.draw_attr");
static_assert(offsetof(ccUiFont_Command, fence_mode) == 0x38, "ccUiFont_Command.fence_mode");
static_assert(offsetof(ccUiFont_Command, layer_id) == 0x3C, "ccUiFont_Command.layer_id");
static_assert(offsetof(ccUiFont_Command, kerning) == 0x40, "ccUiFont_Command.kerning");
static_assert(offsetof(ccUiFont_Command, text) == 0x50, "ccUiFont_Command.text");
static_assert(offsetof(ccUiFont_Command, char_skip_num) == 0x70, "ccUiFont_Command.char_skip_num");
static_assert(offsetof(ccUiFont_Command, draw_char_length) == 0x74, "ccUiFont_Command.draw_char_length");
static_assert(offsetof(ccUiFont_Command, bg_layer) == 0x78, "ccUiFont_Command.bg_layer");
static_assert(offsetof(ccUiFont_Command, reserve) == 0x7C, "ccUiFont_Command.reserve");
static_assert(offsetof(ccUiFont_Command, draw_icon) == 0x80, "ccUiFont_Command.draw_icon");
static_assert(offsetof(ccUiFont_Command, alpha_font) == 0x84, "ccUiFont_Command.alpha_font");
static_assert(offsetof(ccUiFont_Command, ruby_height) == 0x88, "ccUiFont_Command.ruby_height");
static_assert(sizeof(ccUiFont_Command) == 0xA0, "ccUiFont_Command size == 0xA0");

/*
 * ccUiFontCustom — custom font tag handler.
 * Inherits from nuccFontTag (ctor calls FUN_1406beb70 = nuccFontTag::nuccFontTag).
 * Size proven: LoadTh(0x180) in ccUiFont::Initialize.
 * Vtable: PTR_FUN_1409ef738
 *
 * Ctor (undefined8* param_1): sets vtable, *(uint32*)(param_1+0x2c)=5,
 * param_1[0x2e]=0 (byte 0x170 data_ptr), *(longlong*)(param_1+0x164)=1.
 * Dtor: frees param_1[0x2e] (byte 0x170), restores vtable.
 */
typedef struct __attribute__((packed)) ccUiFontCustom {
    void *vtable;               /* 0x00: PTR_FUN_1409ef738 */
    uint8_t _base_08[0x24];     /* 0x08: nuccFontTag base fields */
    uint32_t custom_type;       /* 0x2C: initialized to 5 */
    uint16_t _pad_30;           /* 0x30: padding */
    uint8_t _gap_32[0x2A];      /* 0x32: nuccFontTag internal data → ends 0x5C */
    float alpha_rate;           /* 0x5C: DrawCustom reads *(float*)(param_1+0x5c) */
    uint8_t _gap_60[0x08];      /* 0x60: padding → ends 0x68 */
    uint32_t field_68;          /* 0x68: DrawCustom reads *(uint*)(param_1+0x68) */
    uint8_t _gap_6C[0x08];      /* 0x6C: padding → ends 0x74 */
    float vec2_74_x;            /* 0x74: Nucc::Vector2 X component */
    float field_78;             /* 0x78: DrawCustom reads *(float*)(param_1+0x78) */
    uint8_t _gap_7C[0xE8];      /* 0x7C: large gap in nuccFontTag base → ends 0x164 */
    uint32_t flag_164;          /* 0x164: initialized to 1, checked in DrawCustom */
    uint32_t field_168;         /* 0x168: DrawCustom checks *(int*)(param_1+0x168)==0 */
    uint8_t _pad_16C[0x04];     /* 0x16C: padding → ends 0x170 */
    void *data_ptr;             /* 0x170: ptr at index 0x2E, freed in dtor */
    uint8_t _tail_178[0x08];    /* 0x178: tail to reach proven size 0x180 */
} ccUiFontCustom;
static_assert(offsetof(ccUiFontCustom, vtable) == 0x00, "ccUiFontCustom.vtable");
static_assert(offsetof(ccUiFontCustom, custom_type) == 0x2C, "ccUiFontCustom.custom_type");
static_assert(offsetof(ccUiFontCustom, alpha_rate) == 0x5C, "ccUiFontCustom.alpha_rate");
static_assert(offsetof(ccUiFontCustom, field_68) == 0x68, "ccUiFontCustom.field_68");
static_assert(offsetof(ccUiFontCustom, vec2_74_x) == 0x74, "ccUiFontCustom.vec2_74_x");
static_assert(offsetof(ccUiFontCustom, field_78) == 0x78, "ccUiFontCustom.field_78");
static_assert(offsetof(ccUiFontCustom, flag_164) == 0x164, "ccUiFontCustom.flag_164");
static_assert(offsetof(ccUiFontCustom, field_168) == 0x168, "ccUiFontCustom.field_168");
static_assert(offsetof(ccUiFontCustom, data_ptr) == 0x170, "ccUiFontCustom.data_ptr");
static_assert(sizeof(ccUiFontCustom) == 0x180, "ccUiFontCustom size == 0x180");

/*
 * ccUiFontCustomApp — application-specific font custom handler.
 * Inherits from ccUiFontCustom (ctor calls nuccFontTag::nuccFontTag).
 * Vtable: PTR_FUN_1409cf538
 * Size: >= 0x1C8 (last proven field moji_tm_hash at 0x1C4 + 4)
 *
 * Ctor uses undefined8* param_1 with mixed addressing:
 *   param_1 + N (in cast expr) = byte offset N*8 (pointer arithmetic)
 *   (longlong)param_1 + N      = byte offset N (explicit byte cast)
 *   param_1[N]                 = byte offset N*8 (array index)
 *
 * Derived byte offsets:
 *   *(param_1 + 0x2c) → 0x2c*8 = 0x160  custom_type = 5
 *   *(param_1 + 0x2d) → 0x2d*8 = 0x168  field_168 = 0
 *   *(param_1 + 0x2e) → 0x2e*8 = 0x170  field_170 = 0xffffffff
 *   (longlong)+0x164           → 0x164   flag_164 = 1
 *   (longlong)+0x16c           → 0x16C   field_16C = 1
 *   param_1[0x2f]     → 0x2f*8 = 0x178  field_178 = 0
 *   param_1[0x30]     → 0x30*8 = 0x180  vec_begin = 0
 *   param_1[0x31]     → 0x31*8 = 0x188  vec_end = 0
 *   param_1[0x32]     → 0x32*8 = 0x190  vec_capacity = 0
 *   param_1+0x33 / [0x33] → 0x33*8 = 0x198  block_alloc/tag_vec
 *   *(param_1 + 0x36) → 0x36*8 = 0x1B0  right_signw_hash
 *   (longlong)+0x1b4           → 0x1B4   tm_signw_hash
 *   *(param_1 + 0x37) → 0x37*8 = 0x1B8  chi_hiru_hash
 *   (longlong)+0x1bc           → 0x1BC   chi_mnote_hash
 *   *(param_1 + 0x38) → 0x38*8 = 0x1C0  chi_registered_hash
 *   (longlong)+0x1c4           → 0x1C4   moji_tm_hash
 */
typedef struct __attribute__((packed)) ccUiFontCustomApp {
    void *vtable;               /* 0x00: PTR_FUN_1409cf538 */
    uint8_t _base_08[0x24];     /* 0x08: nuccFontTag base fields */
    uint32_t custom_type_base;  /* 0x2C: base class custom_type (overwritten by App) */
    uint8_t _gap_30[0x130];     /* 0x30: nuccFontTag internals → ends 0x160 */
    uint32_t custom_type;       /* 0x160: initialized to 5 (index 0x2c, byte 0x160) */
    uint32_t flag_164;          /* 0x164: initialized to 1 (byte offset 0x164) */
    uint32_t field_168;         /* 0x168: initialized to 0 (index 0x2d, byte 0x168) */
    uint32_t field_16C;         /* 0x16C: initialized to 1 (byte offset 0x16c) */
    uint32_t field_170;         /* 0x170: initialized to 0xffffffff (index 0x2e, byte 0x170) */
    uint32_t field_174;         /* 0x174: padding/gap */
    uint32_t field_178;         /* 0x178: initialized to 0 (index 0x2f, byte 0x178) */
    uint32_t _pad_17C;          /* 0x17C: padding → ends 0x180 */
    void **vec_begin;           /* 0x180: index 0x30, vector begin */
    void **vec_end;             /* 0x188: index 0x31, vector end */
    void **vec_capacity;        /* 0x190: index 0x32, vector capacity */
    uint8_t _block_alloc_198[0x18]; /* 0x198: BlockAllocator + tag vec (index 0x33) → ends 0x1B0 */
    uint32_t right_signw_hash;  /* 0x1B0: hash of "right_signw />" (index 0x36) */
    uint32_t tm_signw_hash;     /* 0x1B4: hash of "tm_signw />" (byte offset 0x1b4) */
    uint32_t chi_hiru_hash;     /* 0x1B8: hash of "chi_hiru />" (index 0x37) */
    uint32_t chi_mnote_hash;    /* 0x1BC: hash of "chi_mnote />" (byte offset 0x1bc) */
    uint32_t chi_registered_hash;/* 0x1C0: hash of "chi_registered />" (index 0x38) */
    uint32_t moji_tm_hash;      /* 0x1C4: hash of "moji_tm />" (byte offset 0x1c4) */
} ccUiFontCustomApp;
static_assert(offsetof(ccUiFontCustomApp, vtable) == 0x00, "ccUiFontCustomApp.vtable");
static_assert(offsetof(ccUiFontCustomApp, custom_type_base) == 0x2C, "ccUiFontCustomApp.custom_type_base");
static_assert(offsetof(ccUiFontCustomApp, custom_type) == 0x160, "ccUiFontCustomApp.custom_type");
static_assert(offsetof(ccUiFontCustomApp, flag_164) == 0x164, "ccUiFontCustomApp.flag_164");
static_assert(offsetof(ccUiFontCustomApp, field_168) == 0x168, "ccUiFontCustomApp.field_168");
static_assert(offsetof(ccUiFontCustomApp, field_16C) == 0x16C, "ccUiFontCustomApp.field_16C");
static_assert(offsetof(ccUiFontCustomApp, field_170) == 0x170, "ccUiFontCustomApp.field_170");
static_assert(offsetof(ccUiFontCustomApp, field_178) == 0x178, "ccUiFontCustomApp.field_178");
static_assert(offsetof(ccUiFontCustomApp, vec_begin) == 0x180, "ccUiFontCustomApp.vec_begin");
static_assert(offsetof(ccUiFontCustomApp, vec_end) == 0x188, "ccUiFontCustomApp.vec_end");
static_assert(offsetof(ccUiFontCustomApp, vec_capacity) == 0x190, "ccUiFontCustomApp.vec_capacity");
static_assert(offsetof(ccUiFontCustomApp, _block_alloc_198) == 0x198, "ccUiFontCustomApp._block_alloc_198");
static_assert(offsetof(ccUiFontCustomApp, right_signw_hash) == 0x1B0, "ccUiFontCustomApp.right_signw_hash");
static_assert(offsetof(ccUiFontCustomApp, tm_signw_hash) == 0x1B4, "ccUiFontCustomApp.tm_signw_hash");
static_assert(offsetof(ccUiFontCustomApp, chi_hiru_hash) == 0x1B8, "ccUiFontCustomApp.chi_hiru_hash");
static_assert(offsetof(ccUiFontCustomApp, chi_mnote_hash) == 0x1BC, "ccUiFontCustomApp.chi_mnote_hash");
static_assert(offsetof(ccUiFontCustomApp, chi_registered_hash) == 0x1C0, "ccUiFontCustomApp.chi_registered_hash");
static_assert(offsetof(ccUiFontCustomApp, moji_tm_hash) == 0x1C4, "ccUiFontCustomApp.moji_tm_hash");

/*
 * ccUiFont — main UI font rendering class.
 * Inherits from ccUiObject (ctor calls ccUiObject::ccUiObject(param_1,3,param_2)).
 * param_1 typed as undefined8* in ctor (index N = byte N*8),
 * as longlong* in most methods (same scaling).
 *
 * Vtable: PTR_FUN_1409edf50
 * Key pointer fields confirmed from multiple methods:
 * +0xC8 = ccUiFontCustom* (Initialize, _Finalize)
 * +0xD0 = chunk/font handle (Initialize, _Finalize)
 * +0xD8 = ccUiFont_Command* (SetScale, GetColor, SetPos)
 *
 * Embedded sub-objects identified from ctor:
 * +0xE8 = BlockAllocator (command pool, via index 0x1d)
 * +0x128 = nuccCriticalSection (via index 0x25)
 * +0x140 = std::vector<_Command*> (command list, indices 0x2f/0x30/0x31)
 *
 * Object size: unproven. Last proven access at +0x1DC + Vector3(0xC) = 0x1E8.
 * Size unknown, >= 0x1F0.
 */
typedef struct __attribute__((packed)) ccUiFont {
    void *vtable;                       /* 0x00: PTR_FUN_1409edf50 */
    uint8_t _ccUiObject_base[0xB8];     /* 0x08: ccUiObject base (inferred from first own field at 0xC0) */
    uint32_t init_flag;                 /* 0xC0: set to 1 in Initialize, checked in _Finalize */
    uint32_t dirty_flag;                /* 0xC4: read as int in AddCommand */
    struct ccUiFontCustom *custom;      /* 0xC8: allocated in Initialize, freed in _Finalize */
    void *chunk_handle;                 /* 0xD0: from ccGetUiObjectChunk, freed in _Finalize */
    struct ccUiFont_Command *current_command; /* 0xD8: active command for property access */
    void *text_buffer;                  /* 0xE0: allocated via LoadTh(0x38), freed in SetText */
    uint8_t _block_alloc_E8[0x40];      /* 0xE8: Nucc::Memory::BlockAllocator (command pool) */
    uint8_t _gap_128[0x18];             /* 0x128: nuccCriticalSection region start */
    void **cmd_vec_begin;               /* 0x140: std::vector begin */
    void **cmd_vec_end;                 /* 0x148: std::vector end */
    void **cmd_vec_capacity;            /* 0x150: std::vector capacity */
    uint8_t _critsect_158[0x54];        /* 0x158: nuccCriticalSection remainder */
    uint32_t opacity;                   /* 0x1AC: 0xff default */
    uint8_t _gap_1B0[0x04];             /* 0x1B0: padding */
    float scale_default;                /* 0x1B4: float 1.0f (0x3f800000) */
    void *text_string;                  /* 0x1B8: std::string ptr */
    uint64_t _zero_1C0;                 /* 0x1C0: zeroed in ctor */
    uint8_t ruby_enable;                /* 0x1C8: bool, zeroed in ctor */
    uint8_t _pad_1C9[3];                /* 0x1C9: padding */
    uint32_t _zero_1CC;                 /* 0x1CC: zeroed in ctor */
    uint8_t _vec2_1D0[0x08];            /* 0x1D0: Nucc::Vector2 */
    uint8_t _gap_1D8[0x04];             /* 0x1D8: gap */
    float offset_pos_x;                 /* 0x1DC: Vector3.x from ctor */
    float offset_pos_y;                 /* 0x1E0: Vector3.y */
    float offset_pos_z;                 /* 0x1E4: Vector3.z */
    uint8_t _tail_1E8[0x08];            /* 0x1E8: trailing field or alignment */
} ccUiFont;
static_assert(offsetof(ccUiFont, vtable) == 0x00, "ccUiFont.vtable");
static_assert(offsetof(ccUiFont, init_flag) == 0xC0, "ccUiFont.init_flag");
static_assert(offsetof(ccUiFont, dirty_flag) == 0xC4, "ccUiFont.dirty_flag");
static_assert(offsetof(ccUiFont, custom) == 0xC8, "ccUiFont.custom");
static_assert(offsetof(ccUiFont, chunk_handle) == 0xD0, "ccUiFont.chunk_handle");
static_assert(offsetof(ccUiFont, current_command) == 0xD8, "ccUiFont.current_command");
static_assert(offsetof(ccUiFont, text_buffer) == 0xE0, "ccUiFont.text_buffer");
static_assert(offsetof(ccUiFont, cmd_vec_begin) == 0x140, "ccUiFont.cmd_vec_begin");
static_assert(offsetof(ccUiFont, cmd_vec_end) == 0x148, "ccUiFont.cmd_vec_end");
static_assert(offsetof(ccUiFont, cmd_vec_capacity) == 0x150, "ccUiFont.cmd_vec_capacity");
static_assert(offsetof(ccUiFont, text_string) == 0x1B8, "ccUiFont.text_string");
static_assert(offsetof(ccUiFont, ruby_enable) == 0x1C8, "ccUiFont.ruby_enable");
static_assert(offsetof(ccUiFont, offset_pos_x) == 0x1DC, "ccUiFont.offset_pos_x");
static_assert(offsetof(ccUiFont, offset_pos_y) == 0x1E0, "ccUiFont.offset_pos_y");
static_assert(offsetof(ccUiFont, offset_pos_z) == 0x1E4, "ccUiFont.offset_pos_z");
static_assert(offsetof(ccUiFont, _ccUiObject_base) == 0x08, "ccUiFont._ccUiObject_base");
static_assert(offsetof(ccUiFont, _block_alloc_E8) == 0xE8, "ccUiFont._block_alloc_E8");
static_assert(offsetof(ccUiFont, _gap_128) == 0x128, "ccUiFont._gap_128");
static_assert(offsetof(ccUiFont, _critsect_158) == 0x158, "ccUiFont._critsect_158");
static_assert(offsetof(ccUiFont, opacity) == 0x1AC, "ccUiFont.opacity");
static_assert(offsetof(ccUiFont, _gap_1B0) == 0x1B0, "ccUiFont._gap_1B0");
static_assert(offsetof(ccUiFont, scale_default) == 0x1B4, "ccUiFont.scale_default");
static_assert(offsetof(ccUiFont, _zero_1C0) == 0x1C0, "ccUiFont._zero_1C0");
static_assert(offsetof(ccUiFont, _pad_1C9) == 0x1C9, "ccUiFont._pad_1C9");
static_assert(offsetof(ccUiFont, _zero_1CC) == 0x1CC, "ccUiFont._zero_1CC");
static_assert(offsetof(ccUiFont, _vec2_1D0) == 0x1D0, "ccUiFont._vec2_1D0");
static_assert(offsetof(ccUiFont, _gap_1D8) == 0x1D8, "ccUiFont._gap_1D8");
static_assert(offsetof(ccUiFont, _tail_1E8) == 0x1E8, "ccUiFont._tail_1E8");
/* pathspec-fix-v2 2026-10-20T05:06:43Z */

/* pathspec-fix-v2 2026-10-20T05:07:18Z */
