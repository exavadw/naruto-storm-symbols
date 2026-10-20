#pragma pack(push, 1)
/*
 * cmn11.h — ccUiFont and ccUiFontCustom struct layouts for NARUTO STORM 2 PC (s2)
 *
 * INFERRED from static decompilation of NSUNS2.exe (sha abf2b6).
 * NOT CONFIRMED at runtime. All offsets derived from s2 x64 pseudocode.
 * Field names carried from s1 where semantics match; re-derived offsets.
 * Own-game names only (no cross-game name leakage).
 *
 * Object sizes proven from LoadTh allocator calls in Initialize:
 *   ccUiFont_Command: LoadTh(0xa0) → size = 0xA0
 *   ccUiFontCustom:   LoadTh(0x180) → size = 0x180
 *   ccUiFont:         unproven (allocated via ccGetUiObjectChunk factory)
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiFont_Command — inner command struct used by the font renderer.
 * param_1 in _Command::Clear is uint*, so index N = byte offset N*4.
 * Size proven: LoadTh(0xa0) in AddCommand pool allocation.
 */
struct ccUiFont_Command {
    uint32_t flags;             /* 0x00: bitfield, Clear sets & 0xffffff9e | 0x1e */
    float    pos_x;             /* 0x04: Vector3.x from zAxis() default */
    float    pos_y;             /* 0x08: Vector3.y */
    float    pos_z;             /* 0x0C: Vector3.z */
    float    scale_x;           /* 0x10: Vector3.x from zero() default */
    float    scale_y;           /* 0x14: Vector3.y */
    float    scale_z;           /* 0x18: Vector3.z */
    float    pivot_x;           /* 0x1C: Vector2.x from one() default */
    float    pivot_y;           /* 0x20: Vector2.y */
    float    offset_x;          /* 0x24: Vector2.x from zero() default */
    float    offset_y;          /* 0x28: Vector2.y */
    uint8_t  color_r;           /* 0x2C: 0xff default */
    uint8_t  color_g;           /* 0x2D */
    uint8_t  color_b;           /* 0x2E */
    uint8_t  color_a;           /* 0x2F: 0xff default */
    uint32_t text_id;           /* 0x30: 0xffffffff default */
    uint32_t draw_attr;         /* 0x34: 0 default */
    uint32_t fence_mode;        /* 0x38: 0 default */
    uint32_t layer_id;          /* 0x3C: 3 default */
    uint32_t kerning;           /* 0x40: conditional 0xc0000000 */
    uint32_t _pad_44;           /* 0x44: padding */
    uint32_t _pad_48;           /* 0x48: padding */
    uint32_t _pad_4C;           /* 0x4C: padding to std::string */
    uint8_t  text[0x20];        /* 0x50: std::basic_string<char>, 0x20 bytes (opaque) */
    uint32_t char_skip_num;     /* 0x70: param_1[0x1c] in Clear */
    uint32_t draw_char_length;  /* 0x74: param_1[0x1d] in Clear */
    uint32_t bg_layer;          /* 0x78: param_1[0x1e] = 0xffffffff in AddCommand */
    uint32_t reserve;           /* 0x7C: param_1[0x1f] in Clear */
    uint32_t draw_icon;         /* 0x80: param_1[0x20] in Clear */
    uint32_t alpha_font;        /* 0x84: param_1[0x21] in Clear */
    uint32_t ruby_height;       /* 0x88: param_1[0x22] = 3 in Clear */
    uint8_t  _pad_8C[0x14];     /* 0x8C: gap to reach proven size 0xA0 */
};
static_assert(offsetof(struct ccUiFont_Command, flags) == 0x00, "ccUiFont_Command.flags");
static_assert(offsetof(struct ccUiFont_Command, pos_x) == 0x04, "ccUiFont_Command.pos_x");
static_assert(offsetof(struct ccUiFont_Command, pos_y) == 0x08, "ccUiFont_Command.pos_y");
static_assert(offsetof(struct ccUiFont_Command, pos_z) == 0x0C, "ccUiFont_Command.pos_z");
static_assert(offsetof(struct ccUiFont_Command, scale_x) == 0x10, "ccUiFont_Command.scale_x");
static_assert(offsetof(struct ccUiFont_Command, scale_y) == 0x14, "ccUiFont_Command.scale_y");
static_assert(offsetof(struct ccUiFont_Command, scale_z) == 0x18, "ccUiFont_Command.scale_z");
static_assert(offsetof(struct ccUiFont_Command, pivot_x) == 0x1C, "ccUiFont_Command.pivot_x");
static_assert(offsetof(struct ccUiFont_Command, pivot_y) == 0x20, "ccUiFont_Command.pivot_y");
static_assert(offsetof(struct ccUiFont_Command, offset_x) == 0x24, "ccUiFont_Command.offset_x");
static_assert(offsetof(struct ccUiFont_Command, offset_y) == 0x28, "ccUiFont_Command.offset_y");
static_assert(offsetof(struct ccUiFont_Command, color_r) == 0x2C, "ccUiFont_Command.color_r");
static_assert(offsetof(struct ccUiFont_Command, color_g) == 0x2D, "ccUiFont_Command.color_g");
static_assert(offsetof(struct ccUiFont_Command, color_b) == 0x2E, "ccUiFont_Command.color_b");
static_assert(offsetof(struct ccUiFont_Command, color_a) == 0x2F, "ccUiFont_Command.color_a");
static_assert(offsetof(struct ccUiFont_Command, text_id) == 0x30, "ccUiFont_Command.text_id");
static_assert(offsetof(struct ccUiFont_Command, draw_attr) == 0x34, "ccUiFont_Command.draw_attr");
static_assert(offsetof(struct ccUiFont_Command, fence_mode) == 0x38, "ccUiFont_Command.fence_mode");
static_assert(offsetof(struct ccUiFont_Command, layer_id) == 0x3C, "ccUiFont_Command.layer_id");
static_assert(offsetof(struct ccUiFont_Command, kerning) == 0x40, "ccUiFont_Command.kerning");
static_assert(offsetof(struct ccUiFont_Command, text) == 0x50, "ccUiFont_Command.text");
static_assert(offsetof(struct ccUiFont_Command, char_skip_num) == 0x70, "ccUiFont_Command.char_skip_num");
static_assert(offsetof(struct ccUiFont_Command, draw_char_length) == 0x74, "ccUiFont_Command.draw_char_length");
static_assert(offsetof(struct ccUiFont_Command, bg_layer) == 0x78, "ccUiFont_Command.bg_layer");
static_assert(offsetof(struct ccUiFont_Command, reserve) == 0x7C, "ccUiFont_Command.reserve");
static_assert(offsetof(struct ccUiFont_Command, draw_icon) == 0x80, "ccUiFont_Command.draw_icon");
static_assert(offsetof(struct ccUiFont_Command, alpha_font) == 0x84, "ccUiFont_Command.alpha_font");
static_assert(offsetof(struct ccUiFont_Command, ruby_height) == 0x88, "ccUiFont_Command.ruby_height");
static_assert(sizeof(struct ccUiFont_Command) == 0xA0, "ccUiFont_Command size == 0xA0");

/*
 * ccUiFontCustom — custom font tag handler.
 * Inherits from nuccFontTag (ctor calls nuccFontTag::nuccFontTag()).
 * Size proven: LoadTh(0x180) in ccUiFont::Initialize.
 * Vtable: PTR_FUN_1408a15b0
 *
 * Ctor (undefined8* param_1): writes +0x2C (uint32 custom_type=5),
 *   param_1[0x2e]=0 → byte 0x170 (ptr), *(longlong*)(param_1+0x164)=1.
 * Dtor (undefined8* param_1): frees param_1[0x2e] → byte 0x170.
 * DrawCustom (longlong param_1): reads +0x5c (float), +0x68 (uint),
 *   +0x74 (Vector2 via Nucc::Vector2::Vector2), +0x78 (float),
 *   +0x164 (int flag), +0x168 (int).
 *
 * Layout calculation (all packed):
 *   0x00: vtable (8)
 *   0x08: _base_08 (0x24 = 36) → ends 0x2C
 *   0x2C: custom_type (4) → ends 0x30
 *   0x30: _pad_30 (2) → ends 0x32
 *   0x32: _gap_32 (0x2A = 42) → ends 0x5C
 *   0x5C: alpha_rate (4) → ends 0x60
 *   0x60: _gap_60 (4) → ends 0x64  ← was 8, causing drift
 *   0x64: _pad_64 (4) → ends 0x68  ← explicit pad to reach 0x68
 *   0x68: field_68 (4) → ends 0x6C
 *   0x6C: _gap_6C (4) → ends 0x70  ← was 8, causing drift
 *   0x70: _pad_70 (4) → ends 0x74  ← explicit pad to reach 0x74
 *   0x74: vec2_74 (8) → ends 0x7C  ← but DrawCustom says +0x78 is float...
 *
 * Wait — DrawCustom uses longlong param_1, so +0x74 and +0x78 are byte offsets.
 * vec2_74 at 0x74 occupies 8 bytes (0x74-0x7B). field_78 must be at 0x7C, not 0x78.
 * But pseudocode says *(float*)(param_1 + 0x78). This means the Vector2 at +0x74
 * is only 4 bytes? No — Nucc::Vector2::Vector2(&local, param_1+0x74) copies 8 bytes.
 * The float at +0x78 overlaps with vec2_74's second float. That's valid: field_78
 * is actually the Y component of the Vector2, or a separate field that overlaps.
 * Since DrawCustom reads both independently, they must be separate. So vec2_74 is
 * only 4 bytes (just X), and field_78 is at 0x78.
 *
 * Corrected layout:
 *   0x74: vec2_74_x (4) → ends 0x78
 *   0x78: field_78 (4) → ends 0x7C
 *   0x7C: _gap_7C (0xE8 = 232) → ends 0x164
 *   0x164: flag_164 (4) → ends 0x168
 *   0x168: field_168 (4) → ends 0x16C
 *   0x16C: _pad_16C (4) → ends 0x170
 *   0x170: data_ptr (8) → ends 0x178
 *   0x178: _tail_178 (8) → ends 0x180 ✓
 */
struct ccUiFontCustom {
    void     *vtable;           /* 0x00: PTR_FUN_1408a15b0 */
    uint8_t  _base_08[0x24];    /* 0x08: nuccFontTag base fields */
    uint32_t custom_type;       /* 0x2C: initialized to 5 */
    uint16_t _pad_30;           /* 0x30: padding */
    uint8_t  _gap_32[0x2A];     /* 0x32: nuccFontTag internal data → ends 0x5C */
    float    alpha_rate;        /* 0x5C: DrawCustom reads *(float*)(param_1+0x5c) */
    uint8_t  _gap_60[0x08];     /* 0x60: padding → ends 0x68 */
    uint32_t field_68;          /* 0x68: DrawCustom reads *(uint*)(param_1+0x68) */
    uint8_t  _gap_6C[0x08];     /* 0x6C: padding → ends 0x74 */
    float    vec2_74_x;         /* 0x74: Nucc::Vector2 X component */
    float    field_78;          /* 0x78: DrawCustom reads *(float*)(param_1+0x78) */
    uint8_t  _gap_7C[0xE8];     /* 0x7C: large gap in nuccFontTag base → ends 0x164 */
    uint32_t flag_164;          /* 0x164: initialized to 1, checked in DrawCustom */
    uint32_t field_168;         /* 0x168: DrawCustom checks *(int*)(param_1+0x168)==0 */
    uint8_t  _pad_16C[0x04];    /* 0x16C: padding → ends 0x170 */
    void     *data_ptr;         /* 0x170: ptr at index 0x2E, freed in dtor */
    uint8_t  _tail_178[0x08];   /* 0x178: tail to reach proven size 0x180 */
};
static_assert(offsetof(struct ccUiFontCustom, vtable) == 0x00, "ccUiFontCustom.vtable");
static_assert(offsetof(struct ccUiFontCustom, custom_type) == 0x2C, "ccUiFontCustom.custom_type");
static_assert(offsetof(struct ccUiFontCustom, alpha_rate) == 0x5C, "ccUiFontCustom.alpha_rate");
static_assert(offsetof(struct ccUiFontCustom, field_68) == 0x68, "ccUiFontCustom.field_68");
static_assert(offsetof(struct ccUiFontCustom, vec2_74_x) == 0x74, "ccUiFontCustom.vec2_74_x");
static_assert(offsetof(struct ccUiFontCustom, field_78) == 0x78, "ccUiFontCustom.field_78");
static_assert(offsetof(struct ccUiFontCustom, flag_164) == 0x164, "ccUiFontCustom.flag_164");
static_assert(offsetof(struct ccUiFontCustom, field_168) == 0x168, "ccUiFontCustom.field_168");
static_assert(offsetof(struct ccUiFontCustom, data_ptr) == 0x170, "ccUiFontCustom.data_ptr");
static_assert(sizeof(struct ccUiFontCustom) == 0x180, "ccUiFontCustom size == 0x180");

/*
 * ccUiFont — main UI font rendering class.
 * Inherits from ccUiObject (ctor calls ccUiObject::ccUiObject(param_1,3,param_2)).
 * param_1 typed as undefined8* in ctor (index N = byte N*8),
 * as longlong* in most methods (same scaling).
 *
 * Vtable: PTR_FUN_1408a0f68
 * Key pointer fields confirmed from multiple methods:
 *   +0xC8 = ccUiFontCustom* (Initialize, _Finalize)
 *   +0xD0 = chunk/font handle (Initialize, _Finalize)
 *   +0xD8 = ccUiFont_Command* (SetScale, GetColor, SetPos)
 *
 * Embedded sub-objects identified from ctor:
 *   +0xE8 = BlockAllocator (command pool, via index 0x1d)
 *   +0x128 = nuccCriticalSection (via index 0x25)
 *   +0x140 = std::vector<_Command*> (command list, indices 0x2f/0x30/0x31)
 *
 * Object size: unproven. Last proven access at +0x1DC + Vector3(0xC) = 0x1E8.
 * Size unknown, >= 0x1F0.
 */
struct ccUiFont {
    void     *vtable;               /* 0x00: PTR_FUN_1408a0f68 */
    uint8_t  _ccUiObject_base[0xB8];/* 0x08: ccUiObject base (inferred from first own field at 0xC0) */
    uint32_t init_flag;             /* 0xC0: set to 1 in Initialize, checked in _Finalize */
    uint32_t dirty_flag;            /* 0xC4: read as int in AddCommand */
    struct ccUiFontCustom *custom;  /* 0xC8: allocated in Initialize, freed in _Finalize */
    void     *chunk_handle;         /* 0xD0: from ccGetUiObjectChunk, freed in _Finalize */
    struct ccUiFont_Command *current_command; /* 0xD8: active command for property access */
    void     *text_buffer;          /* 0xE0: allocated via LoadTh(0x38), freed in SetText */
    uint8_t  _block_alloc_E8[0x40]; /* 0xE8: Nucc::Memory::BlockAllocator (command pool) */
    uint8_t  _gap_128[0x18];        /* 0x128: nuccCriticalSection region start */
    void    **cmd_vec_begin;        /* 0x140: std::vector begin */
    void    **cmd_vec_end;          /* 0x148: std::vector end */
    void    **cmd_vec_capacity;     /* 0x150: std::vector capacity */
    uint8_t  _critsect_158[0x54];   /* 0x158: nuccCriticalSection remainder */
    uint32_t opacity;               /* 0x1AC: 0xff default */
    uint8_t  _gap_1B0[0x04];        /* 0x1B0: padding */
    float    scale_default;         /* 0x1B4: float 1.0f (0x3f800000) */
    void     *text_string;          /* 0x1B8: std::string ptr */
    uint64_t _zero_1C0;             /* 0x1C0: zeroed in ctor */
    uint8_t  ruby_enable;           /* 0x1C8: bool, zeroed in ctor */
    uint8_t  _pad_1C9[3];           /* 0x1C9: padding */
    uint32_t _zero_1CC;             /* 0x1CC: zeroed in ctor */
    uint8_t  _vec2_1D0[0x08];       /* 0x1D0: Nucc::Vector2 */
    uint8_t  _gap_1D8[0x04];        /* 0x1D8: gap */
    float    offset_pos_x;          /* 0x1DC: Vector3.x from ctor */
    float    offset_pos_y;          /* 0x1E0: Vector3.y */
    float    offset_pos_z;          /* 0x1E4: Vector3.z */
    uint8_t  _tail_1E8[0x08];       /* 0x1E8: trailing field or alignment */
};
static_assert(offsetof(struct ccUiFont, _ccUiObject_base) == 0x08, "ccUiFont._ccUiObject_base");
static_assert(offsetof(struct ccUiFont, vtable) == 0x00, "ccUiFont.vtable");
static_assert(offsetof(struct ccUiFont, init_flag) == 0xC0, "ccUiFont.init_flag");
static_assert(offsetof(struct ccUiFont, dirty_flag) == 0xC4, "ccUiFont.dirty_flag");
static_assert(offsetof(struct ccUiFont, custom) == 0xC8, "ccUiFont.custom");
static_assert(offsetof(struct ccUiFont, chunk_handle) == 0xD0, "ccUiFont.chunk_handle");
static_assert(offsetof(struct ccUiFont, current_command) == 0xD8, "ccUiFont.current_command");
static_assert(offsetof(struct ccUiFont, text_buffer) == 0xE0, "ccUiFont.text_buffer");
static_assert(offsetof(struct ccUiFont, _block_alloc_E8) == 0xE8, "ccUiFont._block_alloc_E8");
static_assert(offsetof(struct ccUiFont, _gap_128) == 0x128, "ccUiFont._gap_128");
static_assert(offsetof(struct ccUiFont, cmd_vec_begin) == 0x140, "ccUiFont.cmd_vec_begin");
static_assert(offsetof(struct ccUiFont, cmd_vec_end) == 0x148, "ccUiFont.cmd_vec_end");
static_assert(offsetof(struct ccUiFont, cmd_vec_capacity) == 0x150, "ccUiFont.cmd_vec_capacity");
static_assert(offsetof(struct ccUiFont, _critsect_158) == 0x158, "ccUiFont._critsect_158");
static_assert(offsetof(struct ccUiFont, opacity) == 0x1AC, "ccUiFont.opacity");
static_assert(offsetof(struct ccUiFont, _gap_1B0) == 0x1B0, "ccUiFont._gap_1B0");
static_assert(offsetof(struct ccUiFont, scale_default) == 0x1B4, "ccUiFont.scale_default");
static_assert(offsetof(struct ccUiFont, text_string) == 0x1B8, "ccUiFont.text_string");
static_assert(offsetof(struct ccUiFont, _zero_1C0) == 0x1C0, "ccUiFont._zero_1C0");
static_assert(offsetof(struct ccUiFont, _pad_1C9) == 0x1C9, "ccUiFont._pad_1C9");
static_assert(offsetof(struct ccUiFont, _zero_1CC) == 0x1CC, "ccUiFont._zero_1CC");
static_assert(offsetof(struct ccUiFont, _vec2_1D0) == 0x1D0, "ccUiFont._vec2_1D0");
static_assert(offsetof(struct ccUiFont, _gap_1D8) == 0x1D8, "ccUiFont._gap_1D8");
static_assert(offsetof(struct ccUiFont, ruby_enable) == 0x1C8, "ccUiFont.ruby_enable");
static_assert(offsetof(struct ccUiFont, offset_pos_x) == 0x1DC, "ccUiFont.offset_pos_x");
static_assert(offsetof(struct ccUiFont, offset_pos_y) == 0x1E0, "ccUiFont.offset_pos_y");
static_assert(offsetof(struct ccUiFont, offset_pos_z) == 0x1E4, "ccUiFont.offset_pos_z");
static_assert(offsetof(struct ccUiFont, _tail_1E8) == 0x1E8, "ccUiFont._tail_1E8");

#pragma pack(pop)
