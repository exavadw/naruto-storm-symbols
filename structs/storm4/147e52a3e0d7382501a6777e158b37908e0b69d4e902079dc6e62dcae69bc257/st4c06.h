/*
 * st4c06.h — Story / cutscene / event / script struct layouts for Storm 4 (s4, PC 1.09)
 *
 * All offsets INFERRED from static decompilation of NSUNS4_release.exe (image base 0x140000000).
 * No runtime confirmation. Sizes proven from operator_new__ / ctor loops where noted;
 * otherwise "size unknown, >= 0x<N>".
 *
 * Build: s4 (NSUNS4_release.exe, SHA prefix in the decompiler cache db)
 * Group: ccNarutoRootObjManagerSearchMessage, ccSceneAdvR2bStartMenuEvent,
 *        ccSceneDemo, ccSceneDemoState, ccSceneNetworkEventBattleBegin,
 *        ccSceneNetworkEventBattleEnd, ccSceneOpeningMovie, ccSceneTitleMovie,
 *        ccScript, ccScriptParam, ccScriptResource, ccSimpleScript,
 *        ccSimpleScriptDataBin, ccStateNetworkEventCharacterSelect
 */

#ifndef ST4C06_H
#define ST4C06_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccScriptResource                                                    */
/* Embedded in ccScript at +0x18. Load/Clear prove layout.             */
/* Size: at least 0x50 (last access at +0x48).                         */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccScriptResource {
    void       *vtable;              /* +0x00 */
    uint8_t     _pad_08[0x30];       /* +0x08 — std::basic_string<char> name (SSO) */
    uint32_t    data_size;           /* +0x38 — *(uint32*)(param_1+0x38) in Load/Clear */
    uint32_t    _pad_3c;             /* +0x3C */
    void       *data_ptr;            /* +0x40 — *(void**)(param_1+0x40), freed via FreeCore */
    int32_t     load_state;          /* +0x48 — 1 = owned/allocated, checked before free */
    uint32_t    _pad_4c;             /* +0x4C */
} ccScriptResource;
static_assert(offsetof(ccScriptResource, data_size)   == 0x38, "ccScriptResource.data_size");
static_assert(offsetof(ccScriptResource, data_ptr)    == 0x40, "ccScriptResource.data_ptr");
static_assert(offsetof(ccScriptResource, load_state)  == 0x48, "ccScriptResource.load_state");

/* ------------------------------------------------------------------ */
/* ccScript                                                            */
/* Lua script wrapper. ~ccScript, Clear, Resume, CallFunc, CreateCore. */
/* Contains ccScriptResource at +0x18.                                 */
/* Size: at least 0x68 (0x18 + sizeof(ccScriptResource)=0x50).         */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccScript {
    void              *vtable;       /* +0x00 */
    int32_t            state;        /* +0x08 — 0=idle,1=loaded,2=suspended,3=finished */
    uint32_t           _pad_0c;      /* +0x0C */
    void              *lua_core;     /* +0x10 — lua_State**, dereferenced twice */
    ccScriptResource   resource;     /* +0x18 — embedded, confirmed by Clear/~dtor */
    /* end of proven fields at +0x68 */
    uint8_t            _unknown_68[0x08]; /* +0x68 — possible padding to 0x70 */
} ccScript;
static_assert(offsetof(ccScript, state)      == 0x08, "ccScript.state");
static_assert(offsetof(ccScript, lua_core)   == 0x10, "ccScript.lua_core");
static_assert(offsetof(ccScript, resource)   == 0x18, "ccScript.resource");

/* ------------------------------------------------------------------ */
/* ccSimpleScriptDataBin                                               */
/* Binary data array for simple scripts. Create allocates entries.      */
/* Each entry is 0x10 bytes (GetData: param_2 * 0x10 + data_ptr).      */
/* Object layout: vtable(8) + count(4) + pad(4) + data_ptr(8) = 0x18. */
/* Size: 0x18 (proven by GetData stride and Create field writes).      */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccSimpleScriptDataBin {
    void       *vtable;              /* +0x00 */
    uint32_t    entry_count;         /* +0x08 — *(uint*)(param_1+8) in GetData */
    uint32_t    _pad_0c;             /* +0x0C */
    void       *data_ptr;            /* +0x10 — allocated array, entry_count * 0x10 bytes */
} ccSimpleScriptDataBin;
static_assert(offsetof(ccSimpleScriptDataBin, entry_count) == 0x08, "ccSimpleScriptDataBin.entry_count");
static_assert(offsetof(ccSimpleScriptDataBin, data_ptr)    == 0x10, "ccSimpleScriptDataBin.data_ptr");

/* ------------------------------------------------------------------ */
/* ccSimpleScript                                                      */
/* Bytecode-driven state machine. Init, Ctrl, CtrlProcess prove layout. */
/* Init loop: 8 iterations clearing 4-byte ints at +0x28..+0x44 and    */
/*   2-byte shorts at +0x48..+0x56.                                     */
/* Ctrl reads +0x14 (ip), +0x10 (code_len), +0x1c (done flag).         */
/* CtrlProcess reads +0x08 (code_ptr), dispatches on opcode at ip*0x24. */
/* Size: at least 0x58 (last write at +0x56 in Init).                  */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccSimpleScript {
    void       *vtable;              /* +0x00 */
    void       *code_ptr;            /* +0x08 — bytecode buffer base */
    int32_t     code_len;            /* +0x10 — number of instructions */
    int32_t     ip;                  /* +0x14 — instruction pointer */
    int32_t     result;              /* +0x18 — return value from Ctrl (param_1[4] when longlong*) */
    int32_t     done_flag;           /* +0x1C — set to 1 by CtrlProcess when done */
    int32_t     resume_flag;         /* +0x20 — set to 1 alongside done_flag */
    int32_t     step_counter;        /* +0x24 — incremented in Ctrl, capped at 0xFFFFFFFE */
    /* Init clears 8 x int32 at offsets +0x28, +0x2C, ..., +0x44 */
    int32_t     regs[8];             /* +0x28 — general-purpose register file */
    /* Init clears 8 x int16 at offsets +0x48, +0x4A, ..., +0x56 */
    int16_t     short_regs[8];       /* +0x48 — short register file */
    /* end of proven fields at +0x58 */
} ccSimpleScript;
static_assert(offsetof(ccSimpleScript, code_ptr)     == 0x08, "ccSimpleScript.code_ptr");
static_assert(offsetof(ccSimpleScript, code_len)     == 0x10, "ccSimpleScript.code_len");
static_assert(offsetof(ccSimpleScript, ip)           == 0x14, "ccSimpleScript.ip");
static_assert(offsetof(ccSimpleScript, result)       == 0x18, "ccSimpleScript.result");
static_assert(offsetof(ccSimpleScript, done_flag)    == 0x1C, "ccSimpleScript.done_flag");
static_assert(offsetof(ccSimpleScript, resume_flag)  == 0x20, "ccSimpleScript.resume_flag");
static_assert(offsetof(ccSimpleScript, step_counter) == 0x24, "ccSimpleScript.step_counter");
static_assert(offsetof(ccSimpleScript, regs)         == 0x28, "ccSimpleScript.regs");
static_assert(offsetof(ccSimpleScript, short_regs)   == 0x48, "ccSimpleScript.short_regs");

/* ------------------------------------------------------------------ */
/* Placeholder structs for classes with < 3 methods or no decomp      */
/* evidence in this build. Listed per TASK.md requirement.             */
/* ------------------------------------------------------------------ */

/* ccScriptParam — only referenced as heap-allocated ptr in ccScript::~ccScript.
 * No methods decompiled for this class in s4. Size unknown. */
typedef struct ccScriptParam {
    uint8_t _unknown[1]; /* size unknown, >= 0x1 */
} ccScriptParam;

/* ccNarutoRootObjManagerSearchMessage — no methods found in s4 symbol table. */
/* ccSceneAdvR2bStartMenuEvent — no methods found in s4 symbol table. */
/* ccSceneDemo — no methods found in s4 symbol table. */
/* ccSceneDemoState — no methods found in s4 symbol table. */
/* ccSceneNetworkEventBattleBegin — no methods found in s4 symbol table. */
/* ccSceneNetworkEventBattleEnd — no methods found in s4 symbol table. */
/* ccSceneOpeningMovie — no methods found in s4 symbol table. */
/* ccSceneTitleMovie — no methods found in s4 symbol table. */
/* ccStateNetworkEventCharacterSelect — no methods found in s4 symbol table. */

#endif /* ST4C06_H */