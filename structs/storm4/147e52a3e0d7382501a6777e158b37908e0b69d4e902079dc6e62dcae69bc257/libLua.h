/*
 * libLua s4 - Lua 5.1.4 + tolua++ struct layouts for NSUNS4_release.exe (Storm 4 PC 1.09)
 * Build: s4 / NSUNS4_release.exe-75912b / sha 147e52a3e0d7
 * Image base: 0x140000000
 * All layouts INFERRED from x64 MSVC decompilation, NOT CONFIRMED at runtime.
 * Sizes proven from allocator arguments in game code.
 */

#ifndef LIBLUA_S4_H
#define LIBLUA_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef uint8_t lu_byte;
typedef size_t lu_mem;
typedef double lua_Number;
typedef int lua_Integer;

typedef union GCObject GCObject;
typedef struct lua_State lua_State;
typedef struct global_State global_State;
typedef struct CallInfo CallInfo;
typedef struct lua_TValue TValue;
typedef TValue *StkId;
typedef int (*lua_CFunction)(lua_State *L);
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);
typedef void (*lua_Hook)(lua_State *L, void *ar);

/* GCheader: 0x10 (proven: embedded in every GC object) */
typedef struct GCheader {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    uint8_t _pad[6];      /* 0x0A */
} __attribute__((packed)) GCheader;
static_assert(offsetof(GCheader, next) == 0x00, "GCheader.next");
static_assert(offsetof(GCheader, tt) == 0x08, "GCheader.tt");
static_assert(offsetof(GCheader, marked) == 0x09, "GCheader.marked");
static_assert(sizeof(GCheader) == 0x10, "GCheader size");

/* TValue: 0x10 (proven: CClosure upvalue stride 0x10, stack_init 0x2d0/0x2d=0x10) */
typedef union Value {
    GCObject *gc;
    void *p;
    lua_Number n;
    int b;
} Value;
typedef struct lua_TValue {
    Value value;          /* 0x00 */
    int tt;               /* 0x08 */
    uint8_t _pad[4];      /* 0x0C */
} __attribute__((packed)) TValue;
static_assert(offsetof(TValue, value) == 0x00, "TValue.value");
static_assert(offsetof(TValue, tt) == 0x08, "TValue.tt");
static_assert(sizeof(TValue) == 0x10, "TValue size");

/* TKey: 0x18 */
struct Node;
typedef union TKey {
    struct {
        Value value;      /* 0x00 */
        int tt;           /* 0x08 */
        uint8_t _pad0[4]; /* 0x0C */
        struct Node *next;/* 0x10 */
    } nk;
    TValue tvk;
} TKey;
static_assert(sizeof(TKey) == 0x18, "TKey size");

/* Node: 0x28 (proven: TValue 0x10 + TKey 0x18) */
typedef struct Node {
    TValue i_val;         /* 0x00 */
    TKey i_key;           /* 0x10 */
} __attribute__((packed)) Node;
static_assert(offsetof(Node, i_val) == 0x00, "Node.i_val");
static_assert(offsetof(Node, i_key) == 0x10, "Node.i_key");
static_assert(sizeof(Node) == 0x28, "Node size");

/* stringtable: 0x10 (from Lua 5.1.4 source; hash ptr + nuse + size) */
typedef struct stringtable {
    GCObject **hash;      /* 0x00 */
    int32_t nuse;         /* 0x08 */
    int32_t size;         /* 0x0C */
} __attribute__((packed)) stringtable;
static_assert(offsetof(stringtable, hash) == 0x00, "stringtable.hash");
static_assert(offsetof(stringtable, nuse) == 0x08, "stringtable.nuse");
static_assert(offsetof(stringtable, size) == 0x0C, "stringtable.size");
static_assert(sizeof(stringtable) == 0x10, "stringtable size");

/* Mbuffer: 0x18 (temp string buffer) */
typedef struct Mbuffer {
    char *buffer;         /* 0x00 */
    size_t n;             /* 0x08 */
    size_t buffsize;      /* 0x10 */
} __attribute__((packed)) Mbuffer;
static_assert(offsetof(Mbuffer, buffer) == 0x00, "Mbuffer.buffer");
static_assert(offsetof(Mbuffer, n) == 0x08, "Mbuffer.n");
static_assert(offsetof(Mbuffer, buffsize) == 0x10, "Mbuffer.buffsize");
static_assert(sizeof(Mbuffer) == 0x18, "Mbuffer size");

/* TString_body: 0x18 header before char data (proven: luaS_newlstr alloc len+0x19) */
typedef struct TString_body {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    lu_byte reserved;     /* 0x0A */
    uint8_t _pad0;        /* 0x0B */
    uint32_t hash;        /* 0x0C */
    size_t len;           /* 0x10 */
} __attribute__((packed)) TString_body;
static_assert(offsetof(TString_body, next) == 0x00, "TString_body.next");
static_assert(offsetof(TString_body, tt) == 0x08, "TString_body.tt");
static_assert(offsetof(TString_body, marked) == 0x09, "TString_body.marked");
static_assert(offsetof(TString_body, reserved) == 0x0A, "TString_body.reserved");
static_assert(offsetof(TString_body, hash) == 0x0C, "TString_body.hash");
static_assert(offsetof(TString_body, len) == 0x10, "TString_body.len");
static_assert(sizeof(TString_body) == 0x18, "TString_body size");

/* Udata_body: 0x28 header before user data (proven: luaS_newudata alloc param_2+0x28) */
typedef struct Udata_body {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    uint8_t _pad0[6];     /* 0x0A */
    struct Table *metatable; /* 0x10 */
    struct Table *env;    /* 0x18 */
    size_t len;           /* 0x20 */
} __attribute__((packed)) Udata_body;
static_assert(offsetof(Udata_body, next) == 0x00, "Udata_body.next");
static_assert(offsetof(Udata_body, metatable) == 0x10, "Udata_body.metatable");
static_assert(offsetof(Udata_body, env) == 0x18, "Udata_body.env");
static_assert(offsetof(Udata_body, len) == 0x20, "Udata_body.len");
static_assert(sizeof(Udata_body) == 0x28, "Udata_body size");

/* LocVar: 0x10 (debug info) */
typedef struct LocVar {
    TString_body *varname; /* 0x00 */
    int32_t startpc;      /* 0x08 */
    int32_t endpc;        /* 0x0C */
} __attribute__((packed)) LocVar;
static_assert(offsetof(LocVar, varname) == 0x00, "LocVar.varname");
static_assert(offsetof(LocVar, startpc) == 0x08, "LocVar.startpc");
static_assert(offsetof(LocVar, endpc) == 0x0C, "LocVar.endpc");
static_assert(sizeof(LocVar) == 0x10, "LocVar size");

/* Proto: 0x78 (proven: luaF_newproto alloc 0x78) */
typedef struct Proto {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    uint8_t _pad0[6];     /* 0x0A */
    TValue *k;            /* 0x10 */
    uint32_t *code;       /* 0x18 */
    struct Proto **p;     /* 0x20 */
    int32_t *lineinfo;    /* 0x28 */
    LocVar *locvars;      /* 0x30 */
    TString_body **upvalues; /* 0x38 */
    TString_body *source; /* 0x40 */
    int32_t sizeupvalues; /* 0x48 */
    int32_t sizek;        /* 0x4C */
    int32_t sizecode;     /* 0x50 */
    int32_t sizelineinfo; /* 0x54 */
    int32_t sizep;        /* 0x58 */
    int32_t sizelocvars;  /* 0x5C */
    int32_t linedefined;  /* 0x60 */
    int32_t lastlinedefined; /* 0x64 */
    GCObject *gclist;     /* 0x68 */
    lu_byte nups;         /* 0x70 */
    lu_byte numparams;    /* 0x71 */
    lu_byte is_vararg;    /* 0x72 */
    lu_byte maxstacksize; /* 0x73 */
    uint8_t _pad1[4];     /* 0x74 */
} __attribute__((packed)) Proto;
static_assert(offsetof(Proto, k) == 0x10, "Proto.k");
static_assert(offsetof(Proto, code) == 0x18, "Proto.code");
static_assert(offsetof(Proto, p) == 0x20, "Proto.p");
static_assert(offsetof(Proto, lineinfo) == 0x28, "Proto.lineinfo");
static_assert(offsetof(Proto, locvars) == 0x30, "Proto.locvars");
static_assert(offsetof(Proto, upvalues) == 0x38, "Proto.upvalues");
static_assert(offsetof(Proto, source) == 0x40, "Proto.source");
static_assert(offsetof(Proto, sizeupvalues) == 0x48, "Proto.sizeupvalues");
static_assert(offsetof(Proto, sizek) == 0x4C, "Proto.sizek");
static_assert(offsetof(Proto, sizecode) == 0x50, "Proto.sizecode");
static_assert(offsetof(Proto, sizelineinfo) == 0x54, "Proto.sizelineinfo");
static_assert(offsetof(Proto, sizep) == 0x58, "Proto.sizep");
static_assert(offsetof(Proto, sizelocvars) == 0x5C, "Proto.sizelocvars");
static_assert(offsetof(Proto, linedefined) == 0x60, "Proto.linedefined");
static_assert(offsetof(Proto, lastlinedefined) == 0x64, "Proto.lastlinedefined");
static_assert(offsetof(Proto, gclist) == 0x68, "Proto.gclist");
static_assert(offsetof(Proto, nups) == 0x70, "Proto.nups");
static_assert(offsetof(Proto, numparams) == 0x71, "Proto.numparams");
static_assert(offsetof(Proto, is_vararg) == 0x72, "Proto.is_vararg");
static_assert(offsetof(Proto, maxstacksize) == 0x73, "Proto.maxstacksize");
static_assert(sizeof(Proto) == 0x78, "Proto size");

/* UpVal: 0x28 (proven: luaF_newupval alloc 0x28) */
typedef struct UpVal {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    uint8_t _pad0[6];     /* 0x0A */
    TValue *v;            /* 0x10 */
    union {
        TValue value;     /* when closed */
        struct {
            struct UpVal *prev;
            struct UpVal *next;
        } l;              /* when open (in lua_State.openupval list) */
    } u;                  /* 0x18 */
} __attribute__((packed)) UpVal;
static_assert(offsetof(UpVal, next) == 0x00, "UpVal.next");
static_assert(offsetof(UpVal, v) == 0x10, "UpVal.v");
static_assert(offsetof(UpVal, u) == 0x18, "UpVal.u");
static_assert(sizeof(UpVal) == 0x28, "UpVal size");

/* CClosure: base 0x28 + nup*0x10 (proven: luaF_newCclosure alloc nup*0x10+0x28) */
typedef struct CClosure {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    lu_byte isC;          /* 0x0A */
    lu_byte nupvalues;    /* 0x0B */
    uint8_t _pad0[4];     /* 0x0C */
    GCObject *gclist;     /* 0x10 */
    lua_CFunction f;      /* 0x18 */
    uint8_t _pad1[8];     /* 0x20 */
    TValue upvalue[1];    /* 0x28 flexible array */
} __attribute__((packed)) CClosure;
static_assert(offsetof(CClosure, next) == 0x00, "CClosure.next");
static_assert(offsetof(CClosure, isC) == 0x0A, "CClosure.isC");
static_assert(offsetof(CClosure, nupvalues) == 0x0B, "CClosure.nupvalues");
static_assert(offsetof(CClosure, gclist) == 0x10, "CClosure.gclist");
static_assert(offsetof(CClosure, f) == 0x18, "CClosure.f");
static_assert(offsetof(CClosure, upvalue) == 0x28, "CClosure.upvalue");

/* LClosure: base 0x28 + nup*8 (proven: luaF_newLclosure alloc nup*8+0x28) */
typedef struct LClosure {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    lu_byte isC;          /* 0x0A */
    lu_byte nupvalues;    /* 0x0B */
    uint8_t _pad0[4];     /* 0x0C */
    GCObject *gclist;     /* 0x10 */
    Proto *p;             /* 0x18 */
    uint8_t _pad1[8];     /* 0x20 */
    UpVal *upvals[1];     /* 0x28 flexible array */
} __attribute__((packed)) LClosure;
static_assert(offsetof(LClosure, next) == 0x00, "LClosure.next");
static_assert(offsetof(LClosure, isC) == 0x0A, "LClosure.isC");
static_assert(offsetof(LClosure, nupvalues) == 0x0B, "LClosure.nupvalues");
static_assert(offsetof(LClosure, gclist) == 0x10, "LClosure.gclist");
static_assert(offsetof(LClosure, p) == 0x18, "LClosure.p");
static_assert(offsetof(LClosure, upvals) == 0x28, "LClosure.upvals");

/* CallInfo: 0x28 (proven: luaD_reallocCI stride 0x28, stack_init 0x140/8=0x28)
 * Standard Lua 5.1 uses an array of CallInfo (not a linked list); prev is not present.
 * Fields derived from luaD_precall/luaD_reallocCI decompilation accesses. */
typedef struct CallInfo {
    StkId base;           /* 0x00 */
    StkId func;           /* 0x08 */
    StkId top;            /* 0x10 */
    const uint32_t *savedpc; /* 0x18 */
    int32_t nresults;     /* 0x20 */
    int32_t tailcalls;    /* 0x24 */
} __attribute__((packed)) CallInfo;
static_assert(offsetof(CallInfo, base) == 0x00, "CallInfo.base");
static_assert(offsetof(CallInfo, func) == 0x08, "CallInfo.func");
static_assert(offsetof(CallInfo, top) == 0x10, "CallInfo.top");
static_assert(offsetof(CallInfo, savedpc) == 0x18, "CallInfo.savedpc");
static_assert(offsetof(CallInfo, nresults) == 0x20, "CallInfo.nresults");
static_assert(offsetof(CallInfo, tailcalls) == 0x24, "CallInfo.tailcalls");
static_assert(sizeof(CallInfo) == 0x28, "CallInfo size");

/* Table: 0x40 (proven: luaH_new alloc 0x40) */
typedef struct Table {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    lu_byte flags;        /* 0x0A */
    lu_byte lsizenode;    /* 0x0B */
    uint8_t _pad0[4];     /* 0x0C */
    struct Table *metatable; /* 0x10 */
    TValue *array;        /* 0x18 */
    Node *node;           /* 0x20 */
    Node *lastfree;       /* 0x28 */
    GCObject *gclist;     /* 0x30 */
    int32_t sizearray;    /* 0x38 */
    uint8_t _pad1[4];     /* 0x3C */
} __attribute__((packed)) Table;
static_assert(offsetof(Table, flags) == 0x0A, "Table.flags");
static_assert(offsetof(Table, lsizenode) == 0x0B, "Table.lsizenode");
static_assert(offsetof(Table, metatable) == 0x10, "Table.metatable");
static_assert(offsetof(Table, array) == 0x18, "Table.array");
static_assert(offsetof(Table, node) == 0x20, "Table.node");
static_assert(offsetof(Table, lastfree) == 0x28, "Table.lastfree");
static_assert(offsetof(Table, gclist) == 0x30, "Table.gclist");
static_assert(offsetof(Table, sizearray) == 0x38, "Table.sizearray");
static_assert(sizeof(Table) == 0x40, "Table size");

/* lua_State: 0xB8 (proven: luaE_newthread alloc 0xB8) */
struct lua_State {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 */
    lu_byte marked;       /* 0x09 */
    lu_byte status;       /* 0x0A */
    uint8_t _pad0[5];     /* 0x0B */
    StkId top;            /* 0x10 */
    StkId base;           /* 0x18 */
    global_State *l_G;    /* 0x20 */
    CallInfo *ci;         /* 0x28 */
    const uint32_t *savedpc; /* 0x30 */
    StkId stack_last;     /* 0x38 */
    StkId stack;          /* 0x40 */
    CallInfo *end_ci;     /* 0x48 */
    CallInfo *base_ci;    /* 0x50 */
    int32_t stacksize;    /* 0x58 */
    int32_t size_ci;      /* 0x5C */
    uint16_t nCcalls;     /* 0x60 */
    uint16_t baseCcalls;  /* 0x62 */
    lu_byte hookmask;     /* 0x64 */
    lu_byte allowhook;    /* 0x65 */
    uint8_t _pad1[2];     /* 0x66 */
    int32_t basehookcount;/* 0x68 */
    int32_t hookcount;    /* 0x6C */
    lua_Hook hook;        /* 0x70 */
    TValue l_gt;          /* 0x78 */
    TValue env;           /* 0x88 */
    GCObject *openupval;  /* 0x98 */
    GCObject *gclist;     /* 0xA0 */
    void *errorJmp;       /* 0xA8 */
    ptrdiff_t errfunc;    /* 0xB0 */
} __attribute__((packed));
static_assert(offsetof(lua_State, top) == 0x10, "lua_State.top");
static_assert(offsetof(lua_State, base) == 0x18, "lua_State.base");
static_assert(offsetof(lua_State, l_G) == 0x20, "lua_State.l_G");
static_assert(offsetof(lua_State, ci) == 0x28, "lua_State.ci");
static_assert(offsetof(lua_State, savedpc) == 0x30, "lua_State.savedpc");
static_assert(offsetof(lua_State, stack_last) == 0x38, "lua_State.stack_last");
static_assert(offsetof(lua_State, stack) == 0x40, "lua_State.stack");
static_assert(offsetof(lua_State, end_ci) == 0x48, "lua_State.end_ci");
static_assert(offsetof(lua_State, base_ci) == 0x50, "lua_State.base_ci");
static_assert(offsetof(lua_State, stacksize) == 0x58, "lua_State.stacksize");
static_assert(offsetof(lua_State, size_ci) == 0x5C, "lua_State.size_ci");
static_assert(offsetof(lua_State, nCcalls) == 0x60, "lua_State.nCcalls");
static_assert(offsetof(lua_State, baseCcalls) == 0x62, "lua_State.baseCcalls");
static_assert(offsetof(lua_State, hookmask) == 0x64, "lua_State.hookmask");
static_assert(offsetof(lua_State, allowhook) == 0x65, "lua_State.allowhook");
static_assert(offsetof(lua_State, basehookcount) == 0x68, "lua_State.basehookcount");
static_assert(offsetof(lua_State, hookcount) == 0x6C, "lua_State.hookcount");
static_assert(offsetof(lua_State, hook) == 0x70, "lua_State.hook");
static_assert(offsetof(lua_State, l_gt) == 0x78, "lua_State.l_gt");
static_assert(offsetof(lua_State, env) == 0x88, "lua_State.env");
static_assert(offsetof(lua_State, openupval) == 0x98, "lua_State.openupval");
static_assert(offsetof(lua_State, gclist) == 0xA0, "lua_State.gclist");
static_assert(offsetof(lua_State, errorJmp) == 0xA8, "lua_State.errorJmp");
static_assert(offsetof(lua_State, errfunc) == 0xB0, "lua_State.errfunc");
static_assert(sizeof(lua_State) == 0xB8, "lua_State size");

/* global_State: exact size unknown; allocated as part of lua_newstate 0x268 block.
 * lua_State occupies first 0xB8 bytes; global_State follows at offset 0xB8.
 * Field order from Lua 5.1.4 source; offsets are INFERRED not confirmed by decomp.
 * Only fields with decomp evidence get asserts. */
#define NUM_TAGS 9
#define TM_N 18
struct global_State {
    GCObject *rootgc;     /* 0x00 */
    GCObject **sweepgc;   /* 0x08 */
    GCObject *gray;       /* 0x10 */
    GCObject *grayagain;  /* 0x18 */
    GCObject *weak;       /* 0x20 */
    GCObject *tmudata;    /* 0x28 */
    Mbuffer buff;         /* 0x30 */
    lu_mem GCthreshold;   /* 0x48 */
    lu_mem totalbytes;    /* 0x50 */
    lu_mem estimate;      /* 0x58 */
    lu_mem gcdept;        /* 0x60 */
    int32_t gcpause;      /* 0x68 */
    int32_t gcstepmul;    /* 0x6C */
    lu_byte gcstate;      /* 0x70 */
    lu_byte currentwhite; /* 0x71 */
    uint8_t _pad0[6];     /* 0x72 */
    stringtable strt;     /* 0x78 */
    lua_CFunction panic;  /* 0x88 */
    lua_State *mainthread;/* 0x90 */
    TValue l_registry;    /* 0x98 */
    UpVal uvhead;         /* 0xA8 */
    uint8_t _pad1[8];     /* 0xD0 - alignment before mt array */
    Table *mt[NUM_TAGS];  /* 0xD8 */
    TString_body *tmname[TM_N]; /* 0x120 */
    lua_Alloc frealloc;   /* 0x1B0 */
    void *ud;             /* 0x1B8 */
};
/* global_State size unknown; only fields up to ud at 0x1B8 have source-level evidence */

/* lua_Debug: reconstructed from Lua 5.1.4 source; size unproven in s4 */
typedef struct lua_Debug {
    int32_t event;        /* 0x00 */
    uint8_t _pad0[4];     /* 0x04 */
    const char *name;     /* 0x08 */
    const char *namewhat; /* 0x10 */
    const char *what;     /* 0x18 */
    const char *source;   /* 0x20 */
    int32_t currentline;  /* 0x28 */
    int32_t nups;         /* 0x2C */
    int32_t linedefined;  /* 0x30 */
    int32_t lastlinedefined; /* 0x34 */
    char short_src[60];   /* 0x38 */
    int32_t i_ci;         /* 0x74 */
    uint8_t _pad1[4];     /* 0x78 */
} __attribute__((packed)) lua_Debug;
static_assert(offsetof(lua_Debug, event) == 0x00, "lua_Debug.event");
static_assert(offsetof(lua_Debug, name) == 0x08, "lua_Debug.name");
static_assert(offsetof(lua_Debug, namewhat) == 0x10, "lua_Debug.namewhat");
static_assert(offsetof(lua_Debug, what) == 0x18, "lua_Debug.what");
static_assert(offsetof(lua_Debug, source) == 0x20, "lua_Debug.source");
static_assert(offsetof(lua_Debug, currentline) == 0x28, "lua_Debug.currentline");
static_assert(offsetof(lua_Debug, nups) == 0x2C, "lua_Debug.nups");
static_assert(offsetof(lua_Debug, linedefined) == 0x30, "lua_Debug.linedefined");
static_assert(offsetof(lua_Debug, lastlinedefined) == 0x34, "lua_Debug.lastlinedefined");
static_assert(offsetof(lua_Debug, short_src) == 0x38, "lua_Debug.short_src");
static_assert(offsetof(lua_Debug, i_ci) == 0x74, "lua_Debug.i_ci");

#endif /* LIBLUA_S4_H */