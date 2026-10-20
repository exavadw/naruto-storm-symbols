/* st2c05.h - Story cutscene/event struct layouts for NSUNS2.exe (build s2)
 * Generated from static analysis. All layouts are INFERRED, not CONFIRMED.
 * Sizes are unproven unless noted; no sizeof asserts for unproven sizes.
 */
#ifndef ST2C05_H
#define ST2C05_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccScriptNS2 - inherits ccScript. Size unknown, >= 0x6C. */
struct ccScriptNS2 {
    uint8_t base_ccScript[0x68]; /* ccScript base, size unproven */
    uint32_t field_0x68;         /* ctor sets to 0 */
};
static_assert(offsetof(struct ccScriptNS2, field_0x68) == 0x68, "ccScriptNS2.field_0x68");

/* ccScriptParam - Lua thread wrapper. Size unknown, >= 0xC. */
struct ccScriptParam {
    void *lua_thread;  /* lua_State* from lua_newthread */
    int32_t lua_ref;   /* luaL_ref result, init -1 */
};
static_assert(offsetof(struct ccScriptParam, lua_thread) == 0x0, "ccScriptParam.lua_thread");
static_assert(offsetof(struct ccScriptParam, lua_ref) == 0x8, "ccScriptParam.lua_ref");

/* ccScriptUiPair - contains embedded ccScriptResource at +0x10.
 * Vtable: PTR_FUN_1408437d8. Size unknown. */
struct ccScriptUiPair {
    void *vtable;                /* 0x1408437d8 */
    uint64_t field_0x8;          /* set to 0 in ctor */
    uint8_t script_resource[0x200]; /* ccScriptResource at +0x10, size unproven */
};
static_assert(offsetof(struct ccScriptUiPair, vtable) == 0x0, "ccScriptUiPair.vtable");
static_assert(offsetof(struct ccScriptUiPair, field_0x8) == 0x8, "ccScriptUiPair.field_0x8");
static_assert(offsetof(struct ccScriptUiPair, script_resource) == 0x10, "ccScriptUiPair.script_resource");

/* ccSimpleScriptDataBin - large fixed array container. Size unknown, >= 0x6940. */
struct ccSimpleScriptDataBin_entry {
    uint32_t values[14]; /* 0x38 bytes per entry */
};

struct ccSimpleScriptDataBin {
    uint64_t field_0x0;          /* unknown */
    uint32_t entry_count;        /* count from input data */
    uint32_t pad_0xC;            /* alignment */
    uint32_t *entries;           /* allocated array of uint32 */
    uint8_t gap_0x18[0x28];      /* padding to 0x40 */
    struct ccSimpleScriptDataBin_entry data_array[480]; /* 480 x 0x38 = 0x6900 */
};
static_assert(offsetof(struct ccSimpleScriptDataBin, entry_count) == 0x8, "entry_count");
static_assert(offsetof(struct ccSimpleScriptDataBin, entries) == 0x10, "entries");
static_assert(offsetof(struct ccSimpleScriptDataBin, data_array) == 0x40, "data_array");
static_assert(sizeof(struct ccSimpleScriptDataBin_entry) == 0x38, "entry_size");

/* ccUiAdvMenuHelpMessage - help message UI. Size unknown, >= 0xC8.
 * Base class occupies 0x00-0x4F.
 * std::string at +0x68 uses MSVC layout: char[16] buf + size_t size + size_t cap (but
 * decompile shows text_size at +0x80 with SSO check >0xf, and font at +0xa0).
 * Layout: +0x68 sso_buf[16], +0x78 capacity(8), +0x80 size(8), +0x88 gap[24], +0xa0 font.
 */
struct ccUiAdvMenuHelpMessage {
    uint8_t base[0x50];          /* base class, size unproven */
    uint32_t field_0x50;         /* set to 0 */
    uint32_t help_msg_id;        /* from Initialize param_2 */
    uint32_t field_0x58;         /* set to 0 */
    uint32_t pad_0x5C;           /* alignment */
    uint64_t field_0x5c;         /* global DAT_140a4f390 */
    char text_sso_buf[16];       /* std::string SSO inline buffer at +0x68 */
    uint64_t text_capacity;      /* std::string capacity at +0x78 */
    uint64_t text_size;          /* std::string size at +0x80, SSO threshold >0xf */
    uint8_t gap_0x88[0x18];      /* padding from +0x88 to +0xa0 */
    void *font;                  /* ccUiFontNS2 from xfgame_cmn.fnt.xfbin at +0xa0 */
    void *sprite_task;           /* ccTaskBase entry for xbattle_help01 at +0xa8 */
    uint8_t ui_objects_vec[24];  /* std::vector<ccUiObject*> begin/end/cap at +0xb0 */
};
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, field_0x50) == 0x50, "field_0x50");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, help_msg_id) == 0x54, "help_msg_id");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, field_0x58) == 0x58, "field_0x58");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, field_0x5c) == 0x60, "field_0x5c");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, text_sso_buf) == 0x68, "text_sso_buf");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, text_capacity) == 0x78, "text_capacity");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, text_size) == 0x80, "text_size");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, font) == 0xA0, "font");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, sprite_task) == 0xA8, "sprite_task");
static_assert(offsetof(struct ccUiAdvMenuHelpMessage, ui_objects_vec) == 0xB0, "ui_objects_vec");

/* ccScriptUi - owns ccScriptNS2*. Size unknown, >= 0x10. */
struct ccScriptUi {
    uint64_t field_0x0;          /* unknown (possibly vtable or base) */
    void *script;                /* ccScriptNS2*, created/freed in Do() */
};
static_assert(offsetof(struct ccScriptUi, script) == 0x8, "script");

#endif /* ST2C05_H */