/*
 * cmn11.h -- ccUiFont group struct layouts for NARUTO STORM 4 PC 1.09 (s4)
 *
 * INFERRED from static decompilation of NSUNS4_release.exe (sha 75912b).
 * NOT CONFIRMED at runtime. All offsets derived from s4 x64 pseudocode.
 * Field names carried from s3 where semantics match; all offsets re-derived.
 * Storm 4 has no Trilogy namespace; own-game symbols/strings only.
 *
 * Object sizes proven from allocator calls:
 *   ccUiFont::_Command: operator_new(0xa0) in ccUiFont ctor -> size = 0xA0
 *   ccUiFontCustom:     operator_new(0x180) in ccUiFont::Initialize -> size = 0x180
 *   ccUiFont:           unproven (allocated via ccGetUiObjectChunk factory),
 *                       last field at 0x1E4, size >= 0x1F0
 *
 * Classes with < 3 methods in s4 (listed in report, not reconstructed):
 *   ccUiFontCustomApp (1 method: GetCustomDataKey)
 *   ccUiFontCustomNS2 (1 method: ctor)
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccUiFont::_Command -- inner command struct used by the font renderer.
 * param_1 in _Command::Clear is uint*, so index N = byte offset N*4.
 * Size proven: operator_new(0xa0) in ccUiFont ctor pool allocation.
 * Not polymorphic (no vtable).
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint32_t flags;             /* 0x00: bitfield, Clear sets & 0xffffff9e | 0x1e */
    float    pos_x;             /* 0x04: Vector3.x from zAxis() default */
    float    pos_y;             /* 0x08 */
    float    pos_z;             /* 0x0C */
    float    scale_x;           /* 0x10: Vector3.x from zero() default */
    float    scale_y;           /* 0x14 */
    float    scale_z;           /* 0x18 */
    float    pivot_scale_x;     /* 0x1C: Vector2.x, zeroed in Clear */
    float    pivot_scale_y;     /* 0x20 */
    float    pivot_x;           /* 0x24: Vector2.x from one() default */
    float    pivot_y;           /* 0x28 */
    float    offset_x;          /* 0x2C: Vector2.x from zero() default */
    float    offset_y;          /* 0x30 */
    uint32_t color_r;           /* 0x34: 0xff default (param_1[0xd]) */
    uint32_t color_a;           /* 0x38: 0xff default (param_1[0xe]) */
    uint8_t  _text_buf_3C[0x04];/* 0x3C: padding/gap before string data */
    uint8_t  text[0x20];        /* 0x40: std::basic_string<char>, opaque */
    uint32_t char_skip_num;     /* 0x60: inferred from s3 mapping */
    uint32_t draw_char_length;  /* 0x64 */
    uint32_t bg_layer;          /* 0x68: param_1[0x1e] = 0 in Clear */
    uint32_t reserve;           /* 0x6C: param_1[0x1f] in Clear */
    uint32_t text_id;           /* 0x70: 0xffffffff default (param_1[0x20]) */
    uint32_t draw_attr;         /* 0x74: 0 default (param_1[0x21]) */
    uint32_t fence_mode;        /* 0x78: 0 default (param_1[0x22]) */
    uint32_t layer_id;          /* 0x7C: 3 default (param_1[0x24]) */
    uint32_t kerning;           /* 0x80: conditional 0xc0000000 */
    uint8_t  _block_alloc_84[0x1C]; /* 0x84: BlockAllocator region -> ends 0xA0 */
} ccUiFont_Command;
static_assert(offsetof(ccUiFont_Command, flags) == 0x00, "ccUiFont_Command.flags");
static_assert(offsetof(ccUiFont_Command, pos_x) == 0x04, "ccUiFont_Command.pos_x");
static_assert(offsetof(ccUiFont_Command, pos_y) == 0x08, "ccUiFont_Command.pos_y");
static_assert(offsetof(ccUiFont_Command, pos_z) == 0x0C, "ccUiFont_Command.pos_z");
static_assert(offsetof(ccUiFont_Command, scale_x) == 0x10, "ccUiFont_Command.scale_x");
static_assert(offsetof(ccUiFont_Command, scale_y) == 0x14, "ccUiFont_Command.scale_y");
static_assert(offsetof(ccUiFont_Command, scale_z) == 0x18, "ccUiFont_Command.scale_z");
static_assert(offsetof(ccUiFont_Command, pivot_scale_x) == 0x1C, "ccUiFont_Command.pivot_scale_x");
static_assert(offsetof(ccUiFont_Command, pivot_scale_y) == 0x20, "ccUiFont_Command.pivot_scale_y");
static_assert(offsetof(ccUiFont_Command, pivot_x) == 0x24, "ccUiFont_Command.pivot_x");
static_assert(offsetof(ccUiFont_Command, pivot_y) == 0x28, "ccUiFont_Command.pivot_y");
static_assert(offsetof(ccUiFont_Command, offset_x) == 0x2C, "ccUiFont_Command.offset_x");
static_assert(offsetof(ccUiFont_Command, offset_y) == 0x30, "ccUiFont_Command.offset_y");
static_assert(offsetof(ccUiFont_Command, color_r) == 0x34, "ccUiFont_Command.color_r");
static_assert(offsetof(ccUiFont_Command, color_a) == 0x38, "ccUiFont_Command.color_a");
static_assert(offsetof(ccUiFont_Command, text) == 0x40, "ccUiFont_Command.text");
static_assert(offsetof(ccUiFont_Command, char_skip_num) == 0x60, "ccUiFont_Command.char_skip_num");
static_assert(offsetof(ccUiFont_Command, draw_char_length) == 0x64, "ccUiFont_Command.draw_char_length");
static_assert(offsetof(ccUiFont_Command, bg_layer) == 0x68, "ccUiFont_Command.bg_layer");
static_assert(offsetof(ccUiFont_Command, reserve) == 0x6C, "ccUiFont_Command.reserve");
static_assert(offsetof(ccUiFont_Command, text_id) == 0x70, "ccUiFont_Command.text_id");
static_assert(offsetof(ccUiFont_Command, draw_attr) == 0x74, "ccUiFont_Command.draw_attr");
static_assert(offsetof(ccUiFont_Command, fence_mode) == 0x78, "ccUiFont_Command.fence_mode");
static_assert(offsetof(ccUiFont_Command, layer_id) == 0x7C, "ccUiFont_Command.layer_id");
static_assert(offsetof(ccUiFont_Command, kerning) == 0x80, "ccUiFont_Command.kerning");
static_assert(sizeof(ccUiFont_Command) == 0xA0, "ccUiFont_Command size == 0xA0");

/* ========================================================================
 * ccUiFontCustom -- custom font tag handler.
 * Inherits from nuccFontTag (ctor calls nuccFontTag::nuccFontTag).
 * Size proven: operator_new(0x180) in ccUiFont::Initialize.
 * Vtable: PTR_FUN_141119020
 *
 * Ctor (undefined8* param_1):
 *   *param_1 = &PTR_FUN_141119020 (vtable)
 *   *(uint32*)(param_1 + 0x2c) = 5 -> byte 0x160
 *   param_1[0x2e] = 0 -> byte 0x170 (data_ptr)
 *   *(longlong*)((longlong)param_1 + 0x164) = 1 -> byte 0x164
 *
 * Initialize accesses custom fields at:
 *   +0x18 (chunk handle), +0x94, +0x90, +0x144, +0x140, +0x7c, +0x128, +0x148
 * AddCommand accesses: +0x160 (custom_type copy from parent 0xAC)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    void     *vtable;           /* 0x00: PTR_FUN_141119020 */
    uint8_t  _base_08[0x10];    /* 0x08: nuccFontTag base fields -> ends 0x18 */
    void     *chunk_handle;     /* 0x18: set in Initialize */
    uint8_t  _gap_20[0x5C];     /* 0x20: nuccFontTag internals -> ends 0x7C */
    float    vec2_7c_x;         /* 0x7C: Vector2 X */
    float    vec2_7c_y;         /* 0x80: Vector2 Y -> ends 0x84 */
    uint8_t  _gap_84[0x0C];     /* 0x84: padding -> ends 0x90 */
    uint32_t flags_90;          /* 0x90: bitfield */
    uint32_t field_94;          /* 0x94: set to 1 in Initialize -> ends 0x98 */
    uint8_t  _gap_98[0xA8];     /* 0x98: padding -> ends 0x140 */
    uint32_t flags_copy_140;    /* 0x140: copy of flags_90 */
    uint32_t field_144;         /* 0x144: copy of field_94 -> ends 0x148 */
    float    vec2_148_x;        /* 0x148: Vector2 */
    float    vec2_148_y;        /* 0x14C -> ends 0x150 */
    uint8_t  _gap_150[0x10];    /* 0x150: padding -> ends 0x160 */
    uint32_t custom_type;       /* 0x160: initialized to 5 in ctor */
    uint32_t flag_164;          /* 0x164: initialized to 1 in ctor -> ends 0x168 */
    uint8_t  _pad_168[0x08];    /* 0x168: padding -> ends 0x170 */
    void     *data_ptr;         /* 0x170: ptr at index 0x2E, freed in dtor -> ends 0x178 */
    uint8_t  _tail_178[0x08];   /* 0x178: tail to reach proven size 0x180 */
} ccUiFontCustom;
static_assert(offsetof(ccUiFontCustom, vtable) == 0x00, "ccUiFontCustom.vtable");
static_assert(offsetof(ccUiFontCustom, chunk_handle) == 0x18, "ccUiFontCustom.chunk_handle");
static_assert(offsetof(ccUiFontCustom, vec2_7c_x) == 0x7C, "ccUiFontCustom.vec2_7c_x");
static_assert(offsetof(ccUiFontCustom, vec2_7c_y) == 0x80, "ccUiFontCustom.vec2_7c_y");
static_assert(offsetof(ccUiFontCustom, flags_90) == 0x90, "ccUiFontCustom.flags_90");
static_assert(offsetof(ccUiFontCustom, field_94) == 0x94, "ccUiFontCustom.field_94");
static_assert(offsetof(ccUiFontCustom, flags_copy_140) == 0x140, "ccUiFontCustom.flags_copy_140");
static_assert(offsetof(ccUiFontCustom, field_144) == 0x144, "ccUiFontCustom.field_144");
static_assert(offsetof(ccUiFontCustom, vec2_148_x) == 0x148, "ccUiFontCustom.vec2_148_x");
static_assert(offsetof(ccUiFontCustom, vec2_148_y) == 0x14C, "ccUiFontCustom.vec2_148_y");
static_assert(offsetof(ccUiFontCustom, custom_type) == 0x160, "ccUiFontCustom.custom_type");
static_assert(offsetof(ccUiFontCustom, flag_164) == 0x164, "ccUiFontCustom.flag_164");
static_assert(offsetof(ccUiFontCustom, data_ptr) == 0x170, "ccUiFontCustom.data_ptr");
static_assert(sizeof(ccUiFontCustom) == 0x180, "ccUiFontCustom size == 0x180");

/* ========================================================================
 * ccUiFont -- main UI font rendering class.
 * Inherits from ccUiObject (ctor calls ccUiObject::ccUiObject(param_1,3,param_2)).
 * param_1 typed as undefined8* in ctor (index N = byte N*8),
 * as longlong* in most methods (same scaling).
 *
 * Vtable: PTR_FUN_141118300
 * Key pointer fields confirmed from multiple methods:
 *   +0xC0 = init_flag (int, set to 1 in Initialize, checked in _Finalize)
 *   +0xC4 = dirty_flag (int, checked in AddCommand)
 *   +0xC8 = ccUiFontCustom* (param_1[0x19], allocated in Initialize, freed in _Finalize)
 *   +0xD0 = chunk/font handle (param_1[0x1a], from ccGetUiObjectChunk)
 *   +0xD8 = ccUiFont_Command* (param_1[0x1b], active command)
 *   +0xE0 = text_buffer ptr (param_1[0x1c], allocated via operator_new(0x38))
 *
 * Embedded sub-objects identified from ctor:
 *   +0xE8  = BlockAllocator (param_1+0x1d, command pool)
 *   +0x128 = nuccCriticalSection (param_1+0x25)
 *   +0x178 = std::vector<_Command*> (param_1[0x2f]/[0x30]/[0x31], command list)
 *   +0x1AC = Vector2 (opacity/scale default area)
 *   +0x1B4 = float scale_default (0x3f800000 = 1.0f)
 *   +0x1B8 = text_string (param_1[0x37], std::string ptr)
 *   +0x1D0 = Vector3 (param_1+0x3a)
 *   +0x1DC = Vector3 (offset_pos)
 *
 * Object size: unproven. Last proven access at +0x1DC + Vector3(0xC) = 0x1E8.
 * Padded to 0x1F0 for alignment consistency with s3 reconstruction.
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    void     *vtable;               /* 0x00: PTR_FUN_141118300 */
    uint8_t  _ccUiObject_base[0xB8];/* 0x08: ccUiObject base -> ends 0xC0 */
    uint32_t init_flag;             /* 0xC0: param_1[0x18], set to 1 in Initialize */
    uint32_t dirty_flag;            /* 0xC4: *(int*)((longlong)param_1+0xc4) */
    ccUiFontCustom *custom;  /* 0xC8: param_1[0x19], allocated in Initialize */
    void     *chunk_handle;         /* 0xD0: param_1[0x1a], from ccGetUiObjectChunk */
    ccUiFont_Command *current_command; /* 0xD8: param_1[0x1b] */
    void     *text_buffer;          /* 0xE0: param_1[0x1c], allocated via operator_new(0x38) */
    uint8_t  _block_alloc_E8[0x40]; /* 0xE8: BlockAllocator (param_1+0x1d) -> ends 0x128 */
    uint8_t  _critsect_128[0x50];   /* 0x128: nuccCriticalSection (param_1+0x25) -> ends 0x178 */
    void     **cmd_vec_begin;       /* 0x178: param_1[0x2f], std::vector begin */
    void     **cmd_vec_end;         /* 0x180: param_1[0x30], std::vector end */
    void     **cmd_vec_capacity;    /* 0x188: param_1[0x31], std::vector capacity */
    void     *_alloc_vtable_190;    /* 0x190: allocator vtable (param_1[0x32]) -> ends 0x198 */
    uint8_t  _gap_198[0x10];        /* 0x198: padding -> ends 0x1A8 */
    uint32_t opacity;               /* 0x1A8: *(undefined4*)(param_1+0x35)=0xff */
    float    _vec2_1AC_x;           /* 0x1AC: Nucc::Vector2 x */
    float    _vec2_1AC_y;           /* 0x1B0: Nucc::Vector2 y -> ends 0x1B4 */
    float    scale_default;         /* 0x1B4: float 1.0f (0x3f800000) */
    void     *text_string;          /* 0x1B8: param_1[0x37], std::string ptr -> ends 0x1C0 */
    uint64_t _zero_1C0;             /* 0x1C0: param_1[0x38], zeroed in ctor -> ends 0x1C8 */
    uint8_t  ruby_enable;           /* 0x1C8: *(undefined1*)(param_1+0x39), bool */
    uint8_t  _pad_1C9[3];           /* 0x1C9: padding -> ends 0x1CC */
    uint32_t _zero_1CC;             /* 0x1CC: zeroed in ctor -> ends 0x1D0 */
    float    _vec3_1D0_x;           /* 0x1D0: Nucc::Vector3 x (param_1+0x3a) */
    float    _vec3_1D0_y;           /* 0x1D4 */
    float    _vec3_1D0_z;           /* 0x1D8 -> ends 0x1DC */
    float    offset_pos_x;          /* 0x1DC: Vector3 x */
    float    offset_pos_y;          /* 0x1E0 */
    float    offset_pos_z;          /* 0x1E4 -> ends 0x1E8 */
    uint8_t  _tail_1E8[0x08];       /* 0x1E8: trailing pad -> ends 0x1F0 */
} ccUiFont;
static_assert(offsetof(ccUiFont, vtable) == 0x00, "ccUiFont.vtable");
static_assert(offsetof(ccUiFont, init_flag) == 0xC0, "ccUiFont.init_flag");
static_assert(offsetof(ccUiFont, dirty_flag) == 0xC4, "ccUiFont.dirty_flag");
static_assert(offsetof(ccUiFont, custom) == 0xC8, "ccUiFont.custom");
static_assert(offsetof(ccUiFont, chunk_handle) == 0xD0, "ccUiFont.chunk_handle");
static_assert(offsetof(ccUiFont, current_command) == 0xD8, "ccUiFont.current_command");
static_assert(offsetof(ccUiFont, text_buffer) == 0xE0, "ccUiFont.text_buffer");
static_assert(offsetof(ccUiFont, cmd_vec_begin) == 0x178, "ccUiFont.cmd_vec_begin");
static_assert(offsetof(ccUiFont, cmd_vec_end) == 0x180, "ccUiFont.cmd_vec_end");
static_assert(offsetof(ccUiFont, cmd_vec_capacity) == 0x188, "ccUiFont.cmd_vec_capacity");
static_assert(offsetof(ccUiFont, opacity) == 0x1A8, "ccUiFont.opacity");
static_assert(offsetof(ccUiFont, scale_default) == 0x1B4, "ccUiFont.scale_default");
static_assert(offsetof(ccUiFont, text_string) == 0x1B8, "ccUiFont.text_string");
static_assert(offsetof(ccUiFont, ruby_enable) == 0x1C8, "ccUiFont.ruby_enable");
static_assert(offsetof(ccUiFont, offset_pos_x) == 0x1DC, "ccUiFont.offset_pos_x");
static_assert(offsetof(ccUiFont, offset_pos_y) == 0x1E0, "ccUiFont.offset_pos_y");
static_assert(offsetof(ccUiFont, offset_pos_z) == 0x1E4, "ccUiFont.offset_pos_z");
static_assert(offsetof(ccUiFont, _ccUiObject_base) == 0x08, "ccUiFont._ccUiObject_base");
static_assert(offsetof(ccUiFont, _block_alloc_E8) == 0xE8, "ccUiFont._block_alloc_E8");
static_assert(offsetof(ccUiFont, _critsect_128) == 0x128, "ccUiFont._critsect_128");
static_assert(offsetof(ccUiFont, _alloc_vtable_190) == 0x190, "ccUiFont._alloc_vtable_190");
static_assert(offsetof(ccUiFont, _gap_198) == 0x198, "ccUiFont._gap_198");
static_assert(offsetof(ccUiFont, _vec2_1AC_x) == 0x1AC, "ccUiFont._vec2_1AC_x");
static_assert(offsetof(ccUiFont, _vec2_1AC_y) == 0x1B0, "ccUiFont._vec2_1AC_y");
static_assert(offsetof(ccUiFont, _zero_1C0) == 0x1C0, "ccUiFont._zero_1C0");
static_assert(offsetof(ccUiFont, _pad_1C9) == 0x1C9, "ccUiFont._pad_1C9");
static_assert(offsetof(ccUiFont, _zero_1CC) == 0x1CC, "ccUiFont._zero_1CC");
static_assert(offsetof(ccUiFont, _vec3_1D0_x) == 0x1D0, "ccUiFont._vec3_1D0_x");
static_assert(offsetof(ccUiFont, _vec3_1D0_y) == 0x1D4, "ccUiFont._vec3_1D0_y");
static_assert(offsetof(ccUiFont, _vec3_1D0_z) == 0x1D8, "ccUiFont._vec3_1D0_z");
static_assert(offsetof(ccUiFont, _tail_1E8) == 0x1E8, "ccUiFont._tail_1E8");
static_assert(sizeof(ccUiFont) == 0x1F0, "ccUiFont size == 0x1F0");
