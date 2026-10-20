/*
 * cmn11.h — ccUiFont and ccUiFontCustom struct layouts for NARUTO STORM 1 PC (s1)
 *
 * INFERRED from static decompilation of NSUNS1.exe (sha 10231093af9c).
 * NOT CONFIRMED at runtime. All offsets derived from s1 x64 pseudocode.
 * Field names from s1 method names and code context only (no cross-game names).
 *
 * Object sizes are unproven from allocator calls (ctor allocates sub-objects,
 * not the ccUiFont itself directly). Sizes marked as lower bounds.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiFont_Command — inner command struct used by the font renderer.
 * param_1 in _Command::Clear is uint*, so index N = byte offset N*4.
 * Size proven: Clear writes up to param_1[0x24] (byte 0x90), plus the string
 * at +0x50 which is a std::string (0x20 bytes on MSVC x64).
 * Total >= 0xA0. Exact size unknown.
 */
struct __attribute__((packed)) ccUiFont_Command {
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
    uint8_t color_r;            /* 0x2C: 0xff default */
    uint8_t color_g;            /* 0x2D */
    uint8_t color_b;            /* 0x2E */
    uint8_t color_a;            /* 0x2F: 0xff default */
    uint32_t text_id;           /* 0x30: 0xffffffff default */
    uint32_t draw_attr;         /* 0x34: 0 default */
    uint32_t fence_mode;        /* 0x38: 0 default */
    uint32_t layer_id;          /* 0x3C: 3 default */
    uint32_t kerning;           /* 0x40: conditional 0xc0000000 */
    uint32_t _pad_44;           /* 0x44: padding */
    uint32_t _pad_48;           /* 0x48: padding */
    uint32_t _pad_4C;           /* 0x4C: padding to std::string */
    uint8_t text[0x20];         /* 0x50: std::basic_string<char>, 0x20 bytes (opaque) */
    uint32_t char_skip_num;     /* 0x70: param_1[0x1c] in Clear (0x70/4=0x1c) */
    uint32_t draw_char_length;  /* 0x74: param_1[0x1d] in Clear */
    uint32_t bg_layer;          /* 0x78: param_1[0x1e] = 0xffffffff in AddCommand */
    uint32_t reserve;           /* 0x7C: param_1[0x1f] in Clear */
    uint32_t draw_icon;         /* 0x80: param_1[0x20] in Clear */
    uint32_t alpha_font;        /* 0x84: param_1[0x21] in Clear */
    uint32_t ruby_height;       /* 0x88: param_1[0x22] = 3 in Clear */
    uint8_t _pad_8C[0x14];      /* 0x8C: gap to reach known end at 0xA0 */
};
static_assert(offsetof(struct ccUiFont_Command, flags) == 0x00, "ccUiFont_Command.flags");
static_assert(offsetof(struct ccUiFont_Command, pos_x) == 0x04, "ccUiFont_Command.pos_x");
static_assert(offsetof(struct ccUiFont_Command, scale_x) == 0x10, "ccUiFont_Command.scale_x");
static_assert(offsetof(struct ccUiFont_Command, pivot_x) == 0x1C, "ccUiFont_Command.pivot_x");
static_assert(offsetof(struct ccUiFont_Command, offset_x) == 0x24, "ccUiFont_Command.offset_x");
static_assert(offsetof(struct ccUiFont_Command, color_r) == 0x2C, "ccUiFont_Command.color_r");
static_assert(offsetof(struct ccUiFont_Command, text_id) == 0x30, "ccUiFont_Command.text_id");
static_assert(offsetof(struct ccUiFont_Command, text) == 0x50, "ccUiFont_Command.text");
static_assert(offsetof(struct ccUiFont_Command, char_skip_num) == 0x70, "ccUiFont_Command.char_skip_num");
static_assert(offsetof(struct ccUiFont_Command, ruby_height) == 0x88, "ccUiFont_Command.ruby_height");

/*
 * ccUiFontCustom — custom font tag handler.
 * Inherits from nuccFontTag (ctor calls nuccFontTag::nuccFontTag()).
 * Size: ctor writes at +0x2c, +0x2e, +0x164, +0x170. Last proven field at 0x170 (ptr).
 * Size unknown, >= 0x178.
 */
struct __attribute__((packed)) ccUiFontCustom {
    void *vtable;               /* 0x00: PTR_FUN_1407483d8 */
    uint8_t _base_08[0x24];     /* 0x08: nuccFontTag base fields */
    uint32_t custom_type;       /* 0x2C: initialized to 5 */
    uint16_t _pad_30;           /* 0x30 */
    void *icon_handle;          /* 0x32: inferred from GetIcon/dtor */
    uint8_t _gap_3A[0x12A];     /* 0x3A: large gap in nuccFontTag base */
    uint64_t flag_164;          /* 0x164: initialized to 1 */
    uint8_t _pad_16C[4];        /* 0x16C */
    void *data_ptr;             /* 0x170: checked for null in GetIcon/dtor */
};
static_assert(offsetof(struct ccUiFontCustom, vtable) == 0x00, "ccUiFontCustom.vtable");
static_assert(offsetof(struct ccUiFontCustom, custom_type) == 0x2C, "ccUiFontCustom.custom_type");
static_assert(offsetof(struct ccUiFontCustom, flag_164) == 0x164, "ccUiFontCustom.flag_164");
static_assert(offsetof(struct ccUiFontCustom, data_ptr) == 0x170, "ccUiFontCustom.data_ptr");

/*
 * ccUiFont — main UI font rendering class.
 * Inherits from ccUiObject (ctor calls ccUiObject::ccUiObject(param_1,3,param_2)).
 * param_1 typed as longlong* in most methods (index N = byte N*8),
 * but as undefined8* in ctor (same scaling).
 *
 * Key pointer fields confirmed from multiple methods:
 *   +0xC8 = ccUiFontCustom* (Initialize, _Finalize)
 *   +0xD0 = chunk/font handle (Initialize, _Finalize)
 *   +0xD8 = ccUiFont_Command* (SetScale, GetColor, SetPos)
 *
 * Embedded sub-objects identified from ctor:
 *   +0xE8 = BlockAllocator (command pool)
 *   +0x140 = std::vector<_Command*> (command list, 3 pointers = 0x18)
 *   +0x158 = nuccCriticalSection
 *   +0x1B8 = text string pointer
 *   +0x1DC = Nucc::Vector3 (offset position)
 *
 * Object size: unproven. Last proven access at +0x1DC + Vector3(0xC) = 0x1E8.
 * Size unknown, >= 0x1F0.
 */
struct __attribute__((packed)) ccUiFont {
    void *vtable;                       /* 0x00: PTR_FUN_1407458c0 */
    uint8_t _ccUiObject_base[0xB8];     /* 0x08: ccUiObject base (inferred from first own field at 0xC0) */
    uint32_t init_flag;                 /* 0xC0: set to 1 in Initialize, checked in _Finalize */
    uint32_t _pad_C4;                   /* 0xC4: also read as int in AddCommand (dirty flag?) */
    struct ccUiFontCustom *custom;      /* 0xC8: allocated in Initialize, freed in _Finalize */
    void *chunk_handle;                 /* 0xD0: from ccGetUiObjectChunk, freed in _Finalize */
    struct ccUiFont_Command *current_command; /* 0xD8: active command for property access */
    void *text_buffer;                  /* 0xE0: allocated via LoadTh(0x38), freed in SetText */
    uint8_t _block_alloc_E8[0x58];      /* 0xE8: Nucc::Memory::BlockAllocator (command pool) */
    void **cmd_vec_begin;               /* 0x140: std::vector begin */
    void **cmd_vec_end;                 /* 0x148: std::vector end */
    void **cmd_vec_capacity;            /* 0x150: std::vector capacity */
    uint8_t _critsect_158[0x58];        /* 0x158: nuccCriticalSection */
    uint32_t opacity;                   /* 0x1B0: 0xff default */
    uint32_t _pad_B4;                   /* 0x1B4: float 1.0f (0x3f800000) — scale default? */
    void *text_string;                  /* 0x1B8: std::string ptr, allocated in SetText */
    uint64_t _zero_1C0;                 /* 0x1C0: zeroed in ctor */
    uint8_t ruby_enable;                /* 0x1C8: bool, zeroed in ctor */
    uint8_t _pad_1C9[3];                /* 0x1C9 */
    uint32_t _zero_1CC;                 /* 0x1CC: zeroed in ctor */
    uint8_t _vec2_1D0[0x8];             /* 0x1D0: Nucc::Vector2 */
    uint8_t _gap_1D8[4];                /* 0x1D8 */
    float offset_pos_x;                 /* 0x1DC: Vector3.x from ctor */
    float offset_pos_y;                 /* 0x1E0: Vector3.y */
    float offset_pos_z;                 /* 0x1E4: Vector3.z */
    uint8_t _tail_1E8[0x8];             /* 0x1E8: possible trailing field or alignment */
};
static_assert(offsetof(struct ccUiFont, vtable) == 0x00, "ccUiFont.vtable");
static_assert(offsetof(struct ccUiFont, init_flag) == 0xC0, "ccUiFont.init_flag");
static_assert(offsetof(struct ccUiFont, custom) == 0xC8, "ccUiFont.custom");
static_assert(offsetof(struct ccUiFont, chunk_handle) == 0xD0, "ccUiFont.chunk_handle");
static_assert(offsetof(struct ccUiFont, current_command) == 0xD8, "ccUiFont.current_command");
static_assert(offsetof(struct ccUiFont, text_buffer) == 0xE0, "ccUiFont.text_buffer");
static_assert(offsetof(struct ccUiFont, cmd_vec_begin) == 0x140, "ccUiFont.cmd_vec_begin");
static_assert(offsetof(struct ccUiFont, cmd_vec_end) == 0x148, "ccUiFont.cmd_vec_end");
static_assert(offsetof(struct ccUiFont, cmd_vec_capacity) == 0x150, "ccUiFont.cmd_vec_capacity");
static_assert(offsetof(struct ccUiFont, opacity) == 0x1B0, "ccUiFont.opacity");
static_assert(offsetof(struct ccUiFont, text_string) == 0x1B8, "ccUiFont.text_string");
static_assert(offsetof(struct ccUiFont, ruby_enable) == 0x1C8, "ccUiFont.ruby_enable");
static_assert(offsetof(struct ccUiFont, offset_pos_x) == 0x1DC, "ccUiFont.offset_pos_x");