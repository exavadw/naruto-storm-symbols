/*
 * libLua s2 - Lua 5.1.4 struct layouts for NSUNS2.exe (Storm 2 PC)
 * Build: s2 / sha 697488011750 / image base 0x140000000
 * All offsets INFERRED from x64 MSVC decompilation of s2 binary.
 * Sizes proven from allocator arguments in lua_newstate, luaH_new,
 * luaF_newproto, luaS_newlstr.
 * LUA_NUMBER = double (8 bytes). x64 MSVC layout with natural alignment.
 */
#ifndef LIBLUA_S2_H
#define LIBLUA_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct GCObject GCObject;
typedef struct lua_State lua_State;
typedef struct global_State global_State;
typedef struct CallInfo CallInfo;
typedef struct Table Table;
typedef struct Proto Proto;
typedef struct UpVal UpVal;
typedef struct CClosure CClosure;
typedef struct LClosure LClosure;
typedef struct TString TString;
typedef struct Udata Udata;
typedef struct Node Node;
typedef union TKey TKey;
typedef struct stringtable stringtable;
typedef struct Mbuffer Mbuffer;
typedef struct LocVar LocVar;
typedef struct lua_Debug lua_Debug;

typedef double lua_Number;
typedef int32_t lu_int32;
typedef size_t lu_mem;
typedef uint8_t lu_byte;
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);
typedef int (*lua_CFunction)(lua_State *L);

#define LUA_NUMTAGS 9

/* TValue - tagged value (16 bytes on x64) */
typedef struct TValue {
    union {
        GCObject *gc;
        void *p;
        lua_Number n;
        int b;
    } value; /* 0x00 */
    int tt;      /* 0x08 */
    uint8_t _pad[4]; /* 0x0C */
} __attribute__((packed)) TValue;

static_assert(sizeof(TValue) == 0x10, "TValue must be 16 bytes");
static_assert(offsetof(TValue, value) == 0x00, "TValue.value @ 0x00");
static_assert(offsetof(TValue, tt) == 0x08, "TValue.tt @ 0x08");

/* GCheader - common header for all GC objects (16 bytes) */
typedef struct GCheader {
    GCObject *next; /* 0x00 */
    lu_byte tt;     /* 0x08 */
    lu_byte marked; /* 0x09 */
    uint8_t _pad[6]; /* 0x0A */
} __attribute__((packed)) GCheader;

static_assert(sizeof(GCheader) == 0x10, "GCheader must be 16 bytes");
static_assert(offsetof(GCheader, next) == 0x00, "GCheader.next @ 0x00");
static_assert(offsetof(GCheader, tt) == 0x08, "GCheader.tt @ 0x08");
static_assert(offsetof(GCheader, marked) == 0x09, "GCheader.marked @ 0x09");

/* TString - interned string, data starts at 0x18 */
typedef struct TString {
    GCObject *next;   /* 0x00 */
    lu_byte tt;       /* 0x08 */
    lu_byte marked;   /* 0x09 */
    lu_byte reserved; /* 0x0A */
    uint8_t _pad0;    /* 0x0B */
    uint32_t hash;    /* 0x0C */
    size_t len;       /* 0x10 */
} __attribute__((packed)) TString;

static_assert(offsetof(TString, next) == 0x00, "TString.next @ 0x00");
static_assert(offsetof(TString, tt) == 0x08, "TString.tt @ 0x08");
static_assert(offsetof(TString, marked) == 0x09, "TString.marked @ 0x09");
static_assert(offsetof(TString, reserved) == 0x0A, "TString.reserved @ 0x0A");
static_assert(offsetof(TString, hash) == 0x0C, "TString.hash @ 0x0C");
static_assert(offsetof(TString, len) == 0x10, "TString.len @ 0x10");

/* Udata - userdata object, user data follows at 0x28 */
typedef struct Udata {
    GCObject *next;     /* 0x00 */
    lu_byte tt;         /* 0x08 */
    lu_byte marked;     /* 0x09 */
    uint8_t _pad0[6];   /* 0x0A */
    Table *metatable;   /* 0x10 */
    Table *env;         /* 0x18 */
    size_t len;         /* 0x20 */
} __attribute__((packed)) Udata;

static_assert(offsetof(Udata, next) == 0x00, "Udata.next @ 0x00");
static_assert(offsetof(Udata, tt) == 0x08, "Udata.tt @ 0x08");
static_assert(offsetof(Udata, metatable) == 0x10, "Udata.metatable @ 0x10");
static_assert(offsetof(Udata, env) == 0x18, "Udata.env @ 0x18");
static_assert(offsetof(Udata, len) == 0x20, "Udata.len @ 0x20");

/* Table - hash table, size proven 0x40 from luaH_new */
typedef struct Table {
    GCObject *next;     /* 0x00 */
    lu_byte tt;         /* 0x08 */
    lu_byte marked;     /* 0x09 */
    uint8_t _pad0[6];   /* 0x0A */
    lu_byte flags;      /* 0x10 */
    lu_byte lsizenode;  /* 0x11 */
    uint8_t _pad1[6];   /* 0x12 */
    Table *metatable;   /* 0x18 */
    TValue *array;      /* 0x20 */
    Node *node;         /* 0x28 */
    Node *lastfree;     /* 0x30 */
    int32_t sizearray;  /* 0x38 */
    uint8_t _pad2[4];   /* 0x3C */
} __attribute__((packed)) Table;

static_assert(sizeof(Table) == 0x40, "Table must be 0x40 bytes");
static_assert(offsetof(Table, next) == 0x00, "Table.next @ 0x00");
static_assert(offsetof(Table, tt) == 0x08, "Table.tt @ 0x08");
static_assert(offsetof(Table, flags) == 0x10, "Table.flags @ 0x10");
static_assert(offsetof(Table, lsizenode) == 0x11, "Table.lsizenode @ 0x11");
static_assert(offsetof(Table, metatable) == 0x18, "Table.metatable @ 0x18");
static_assert(offsetof(Table, array) == 0x20, "Table.array @ 0x20");
static_assert(offsetof(Table, node) == 0x28, "Table.node @ 0x28");
static_assert(offsetof(Table, lastfree) == 0x30, "Table.lastfree @ 0x30");
static_assert(offsetof(Table, sizearray) == 0x38, "Table.sizearray @ 0x38");

/* TKey / Node - hash table node, Node = 0x28 */
typedef union TKey {
    struct {
        TValue tv;  /* 0x00 */
        Node *next; /* 0x10 */
    } nk;
    TValue tvk;
} __attribute__((packed)) TKey;

static_assert(sizeof(TKey) == 0x18, "TKey must be 24 bytes");
static_assert(offsetof(TKey, nk.tv) == 0x00, "TKey.nk.tv @ 0x00");
static_assert(offsetof(TKey, nk.next) == 0x10, "TKey.nk.next @ 0x10");

typedef struct Node {
    TValue i_val; /* 0x00 */
    TKey i_key;   /* 0x10 */
} __attribute__((packed)) Node;

static_assert(sizeof(Node) == 0x28, "Node must be 40 bytes");
static_assert(offsetof(Node, i_val) == 0x00, "Node.i_val @ 0x00");
static_assert(offsetof(Node, i_key) == 0x10, "Node.i_key @ 0x10");

/* LocVar - local variable debug info */
typedef struct LocVar {
    TString *varname; /* 0x00 */
    int32_t startpc;  /* 0x08 */
    int32_t endpc;    /* 0x0C */
} __attribute__((packed)) LocVar;

static_assert(sizeof(LocVar) == 0x10, "LocVar must be 16 bytes");
static_assert(offsetof(LocVar, varname) == 0x00, "LocVar.varname @ 0x00");
static_assert(offsetof(LocVar, startpc) == 0x08, "LocVar.startpc @ 0x08");
static_assert(offsetof(LocVar, endpc) == 0x0C, "LocVar.endpc @ 0x0C");

/* Proto - function prototype, size proven 0x78 from luaF_newproto */
typedef struct Proto {
    GCObject *next;        /* 0x00 */
    lu_byte tt;            /* 0x08 */
    lu_byte marked;        /* 0x09 */
    uint8_t _pad0[6];      /* 0x0A */
    TValue *k;             /* 0x10 */
    uint32_t *code;        /* 0x18 */
    Proto **p;             /* 0x20 */
    int32_t *lineinfo;     /* 0x28 */
    LocVar *locvars;       /* 0x30 */
    TString **upvalues;    /* 0x38 */
    TString *source;       /* 0x40 */
    int32_t sizeupvalues;  /* 0x48 */
    int32_t sizek;         /* 0x4C */
    int32_t sizecode;      /* 0x50 */
    int32_t sizelineinfo;  /* 0x54 */
    int32_t sizep;         /* 0x58 */
    int32_t sizelocvars;   /* 0x5C */
    int32_t linedefined;   /* 0x60 */
    int32_t lastlinedefined; /* 0x64 */
    GCObject *gclist;      /* 0x68 */
    lu_byte nups;          /* 0x70 */
    lu_byte numparams;     /* 0x71 */
    lu_byte is_vararg;     /* 0x72 */
    lu_byte maxstacksize;  /* 0x73 */
    uint8_t _pad1[4];      /* 0x74 */
} __attribute__((packed)) Proto;

static_assert(sizeof(Proto) == 0x78, "Proto must be 0x78 bytes");
static_assert(offsetof(Proto, next) == 0x00, "Proto.next @ 0x00");
static_assert(offsetof(Proto, k) == 0x10, "Proto.k @ 0x10");
static_assert(offsetof(Proto, code) == 0x18, "Proto.code @ 0x18");
static_assert(offsetof(Proto, p) == 0x20, "Proto.p @ 0x20");
static_assert(offsetof(Proto, lineinfo) == 0x28, "Proto.lineinfo @ 0x28");
static_assert(offsetof(Proto, locvars) == 0x30, "Proto.locvars @ 0x30");
static_assert(offsetof(Proto, upvalues) == 0x38, "Proto.upvalues @ 0x38");
static_assert(offsetof(Proto, source) == 0x40, "Proto.source @ 0x40");
static_assert(offsetof(Proto, sizeupvalues) == 0x48, "Proto.sizeupvalues @ 0x48");
static_assert(offsetof(Proto, sizek) == 0x4C, "Proto.sizek @ 0x4C");
static_assert(offsetof(Proto, sizecode) == 0x50, "Proto.sizecode @ 0x50");
static_assert(offsetof(Proto, sizelineinfo) == 0x54, "Proto.sizelineinfo @ 0x54");
static_assert(offsetof(Proto, sizep) == 0x58, "Proto.sizep @ 0x58");
static_assert(offsetof(Proto, sizelocvars) == 0x5C, "Proto.sizelocvars @ 0x5C");
static_assert(offsetof(Proto, linedefined) == 0x60, "Proto.linedefined @ 0x60");
static_assert(offsetof(Proto, lastlinedefined) == 0x64, "Proto.lastlinedefined @ 0x64");
static_assert(offsetof(Proto, gclist) == 0x68, "Proto.gclist @ 0x68");
static_assert(offsetof(Proto, nups) == 0x70, "Proto.nups @ 0x70");
static_assert(offsetof(Proto, numparams) == 0x71, "Proto.numparams @ 0x71");
static_assert(offsetof(Proto, is_vararg) == 0x72, "Proto.is_vararg @ 0x72");
static_assert(offsetof(Proto, maxstacksize) == 0x73, "Proto.maxstacksize @ 0x73");

/* UpVal - upvalue, size 0x28 inferred */
typedef struct UpVal {
    GCObject *next;   /* 0x00 */
    lu_byte tt;       /* 0x08 */
    lu_byte marked;   /* 0x09 */
    uint8_t _pad0[6]; /* 0x0A */
    TValue *v;        /* 0x10 */
    union {
        TValue value; /* 0x18 when closed */
        struct {
            UpVal *prev; /* 0x18 */
            UpVal *next; /* 0x20 */
        } l;
    } u; /* 0x18 */
} __attribute__((packed)) UpVal;

static_assert(sizeof(UpVal) == 0x28, "UpVal must be 0x28 bytes");
static_assert(offsetof(UpVal, next) == 0x00, "UpVal.next @ 0x00");
static_assert(offsetof(UpVal, v) == 0x10, "UpVal.v @ 0x10");
static_assert(offsetof(UpVal, u) == 0x18, "UpVal.u @ 0x18");

/* CClosure - C closure, variable length: base 0x18 + nupvalues*sizeof(TValue) */
typedef struct CClosure {
    GCObject *next;     /* 0x00 */
    lu_byte tt;         /* 0x08 */
    lu_byte marked;     /* 0x09 */
    lu_byte isC;        /* 0x0A = 1 */
    lu_byte nupvalues;  /* 0x0B */
    uint8_t _pad0[4];   /* 0x0C */
    lua_CFunction f;    /* 0x10 */
} __attribute__((packed)) CClosure;

static_assert(offsetof(CClosure, next) == 0x00, "CClosure.next @ 0x00");
static_assert(offsetof(CClosure, isC) == 0x0A, "CClosure.isC @ 0x0A");
static_assert(offsetof(CClosure, nupvalues) == 0x0B, "CClosure.nupvalues @ 0x0B");
static_assert(offsetof(CClosure, f) == 0x10, "CClosure.f @ 0x10");

/* LClosure - Lua closure, variable length: base 0x20 + nupvalues*sizeof(UpVal*) */
typedef struct LClosure {
    GCObject *next;     /* 0x00 */
    lu_byte tt;         /* 0x08 */
    lu_byte marked;     /* 0x09 */
    lu_byte isC;        /* 0x0A = 0 */
    lu_byte nupvalues;  /* 0x0B */
    uint8_t _pad0[4];   /* 0x0C */
    Proto *p;           /* 0x10 */
    GCObject *gclist;   /* 0x18 */
} __attribute__((packed)) LClosure;

static_assert(offsetof(LClosure, next) == 0x00, "LClosure.next @ 0x00");
static_assert(offsetof(LClosure, isC) == 0x0A, "LClosure.isC @ 0x0A");
static_assert(offsetof(LClosure, nupvalues) == 0x0B, "LClosure.nupvalues @ 0x0B");
static_assert(offsetof(LClosure, p) == 0x10, "LClosure.p @ 0x10");
static_assert(offsetof(LClosure, gclist) == 0x18, "LClosure.gclist @ 0x18");

/* CallInfo - call frame, doubly-linked list node */
typedef struct CallInfo {
    TValue *func;       /* 0x00 */
    TValue *base;       /* 0x08 */
    TValue *top;        /* 0x10 */
    CallInfo *prev;     /* 0x18 */
    CallInfo *next;     /* 0x20 */
    int32_t nresults;   /* 0x28 */
    int32_t tailcalls;  /* 0x2C */
    uint32_t *savedpc;  /* 0x30 */
    uint8_t _pad[4];    /* 0x34 */
} __attribute__((packed)) CallInfo;

static_assert(sizeof(CallInfo) == 0x3C, "CallInfo must be 0x3C bytes");
static_assert(offsetof(CallInfo, func) == 0x00, "CallInfo.func @ 0x00");
static_assert(offsetof(CallInfo, base) == 0x08, "CallInfo.base @ 0x08");
static_assert(offsetof(CallInfo, top) == 0x10, "CallInfo.top @ 0x10");
static_assert(offsetof(CallInfo, prev) == 0x18, "CallInfo.prev @ 0x18");
static_assert(offsetof(CallInfo, next) == 0x20, "CallInfo.next @ 0x20");
static_assert(offsetof(CallInfo, nresults) == 0x28, "CallInfo.nresults @ 0x28");
static_assert(offsetof(CallInfo, tailcalls) == 0x2C, "CallInfo.tailcalls @ 0x2C");
static_assert(offsetof(CallInfo, savedpc) == 0x30, "CallInfo.savedpc @ 0x30");

/* stringtable - interned string hash table */
typedef struct stringtable {
    TString **hash; /* 0x00 */
    int32_t nuse;   /* 0x08 */
    int32_t size;   /* 0x0C */
} __attribute__((packed)) stringtable;

static_assert(sizeof(stringtable) == 0x10, "stringtable must be 0x10 bytes");
static_assert(offsetof(stringtable, hash) == 0x00, "stringtable.hash @ 0x00");
static_assert(offsetof(stringtable, nuse) == 0x08, "stringtable.nuse @ 0x08");
static_assert(offsetof(stringtable, size) == 0x0C, "stringtable.size @ 0x0C");

/* Mbuffer - temporary string buffer */
typedef struct Mbuffer {
    char *buffer;   /* 0x00 */
    size_t n;       /* 0x08 */
    size_t buffsize;/* 0x10 */
} __attribute__((packed)) Mbuffer;

static_assert(sizeof(Mbuffer) == 0x18, "Mbuffer must be 0x18 bytes");
static_assert(offsetof(Mbuffer, buffer) == 0x00, "Mbuffer.buffer @ 0x00");
static_assert(offsetof(Mbuffer, n) == 0x08, "Mbuffer.n @ 0x08");
static_assert(offsetof(Mbuffer, buffsize) == 0x10, "Mbuffer.buffsize @ 0x10");

/* global_State - per-interpreter global state
 * Key fields from lua_newstate init. Tail is placeholder.
 */
typedef struct global_State {
    GCObject *rootgc;     /* 0x00 */
    GCObject **sweepgc;   /* 0x08 */
    GCObject *gray;       /* 0x10 */
    GCObject *grayagain;  /* 0x18 */
    GCObject *weak;       /* 0x20 */
    GCObject *tmudata;    /* 0x28 */
    Mbuffer buff;         /* 0x30 (0x18 bytes) */
    lu_mem GCthreshold;   /* 0x48 */
    lu_mem totalbytes;    /* 0x50 */
    lu_mem estimate;      /* 0x58 */
    lu_mem gcdept;        /* 0x60 */
    int32_t gcpause;      /* 0x68 */
    int32_t gcstepmul;    /* 0x6C */
    lu_byte gcstate;      /* 0x70 */
    lu_byte currentwhite; /* 0x71 */
    lu_byte markbits;     /* 0x72 */
    uint8_t _pad0;        /* 0x73 */
    int32_t sweepstrgc;   /* 0x74 */
    uint8_t _pad1[4];     /* 0x78 */
    stringtable strt;     /* 0x7C (0x10 bytes packed -> ends 0x8C) */
    lua_CFunction panic;  /* 0x8C */
    uint8_t _pad2[4];     /* 0x94 */
    lua_State *mainthread;/* 0x98 */
    TString **tmname;     /* 0xA0 */
    Table *mt[LUA_NUMTAGS]; /* 0xA8, 9 entries * 8 = 0x48 -> ends 0xF0 */
    uint8_t _remaining[0x100]; /* unverified tail */
} __attribute__((packed)) global_State;

static_assert(offsetof(global_State, rootgc) == 0x00, "global_State.rootgc @ 0x00");
static_assert(offsetof(global_State, sweepgc) == 0x08, "global_State.sweepgc @ 0x08");
static_assert(offsetof(global_State, gray) == 0x10, "global_State.gray @ 0x10");
static_assert(offsetof(global_State, grayagain) == 0x18, "global_State.grayagain @ 0x18");
static_assert(offsetof(global_State, weak) == 0x20, "global_State.weak @ 0x20");
static_assert(offsetof(global_State, tmudata) == 0x28, "global_State.tmudata @ 0x28");
static_assert(offsetof(global_State, buff) == 0x30, "global_State.buff @ 0x30");
static_assert(offsetof(global_State, GCthreshold) == 0x48, "global_State.GCthreshold @ 0x48");
static_assert(offsetof(global_State, totalbytes) == 0x50, "global_State.totalbytes @ 0x50");
static_assert(offsetof(global_State, estimate) == 0x58, "global_State.estimate @ 0x58");
static_assert(offsetof(global_State, gcdept) == 0x60, "global_State.gcdept @ 0x60");
static_assert(offsetof(global_State, gcpause) == 0x68, "global_State.gcpause @ 0x68");
static_assert(offsetof(global_State, gcstepmul) == 0x6C, "global_State.gcstepmul @ 0x6C");
static_assert(offsetof(global_State, gcstate) == 0x70, "global_State.gcstate @ 0x70");
static_assert(offsetof(global_State, currentwhite) == 0x71, "global_State.currentwhite @ 0x71");
static_assert(offsetof(global_State, strt) == 0x7C, "global_State.strt @ 0x7C");
static_assert(offsetof(global_State, panic) == 0x8C, "global_State.panic @ 0x8C");
static_assert(offsetof(global_State, mainthread) == 0x98, "global_State.mainthread @ 0x98");
static_assert(offsetof(global_State, tmname) == 0xA0, "global_State.tmname @ 0xA0");
static_assert(offsetof(global_State, mt) == 0xA8, "global_State.mt @ 0xA8");

typedef TValue *StkId;
typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);

/* lua_State - per-thread state
 * Size NOT fully proven; key fields from lua_newstate/lua_newthread init.
 */
typedef struct lua_State {
    GCObject *next;       /* 0x00 */
    lu_byte tt;           /* 0x08 = LUA_TTHREAD (8) */
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
    TValue l_gt;          /* 0x78 (0x10 bytes) */
    TValue env;           /* 0x88 (0x10 bytes) */
    GCObject *openupval;  /* 0x98 */
    GCObject *gclist;     /* 0xA0 */
    struct lua_longjmp *errorJmp; /* 0xA8 */
    ptrdiff_t errfunc;    /* 0xB0 */
    uint8_t _remaining[0x40]; /* unverified tail */
} __attribute__((packed)) lua_State;

static_assert(offsetof(lua_State, next) == 0x00, "lua_State.next @ 0x00");
static_assert(offsetof(lua_State, tt) == 0x08, "lua_State.tt @ 0x08");
static_assert(offsetof(lua_State, marked) == 0x09, "lua_State.marked @ 0x09");
static_assert(offsetof(lua_State, status) == 0x0A, "lua_State.status @ 0x0A");
static_assert(offsetof(lua_State, top) == 0x10, "lua_State.top @ 0x10");
static_assert(offsetof(lua_State, base) == 0x18, "lua_State.base @ 0x18");
static_assert(offsetof(lua_State, l_G) == 0x20, "lua_State.l_G @ 0x20");
static_assert(offsetof(lua_State, ci) == 0x28, "lua_State.ci @ 0x28");
static_assert(offsetof(lua_State, savedpc) == 0x30, "lua_State.savedpc @ 0x30");
static_assert(offsetof(lua_State, stack_last) == 0x38, "lua_State.stack_last @ 0x38");
static_assert(offsetof(lua_State, stack) == 0x40, "lua_State.stack @ 0x40");
static_assert(offsetof(lua_State, end_ci) == 0x48, "lua_State.end_ci @ 0x48");
static_assert(offsetof(lua_State, base_ci) == 0x50, "lua_State.base_ci @ 0x50");
static_assert(offsetof(lua_State, stacksize) == 0x58, "lua_State.stacksize @ 0x58");
static_assert(offsetof(lua_State, size_ci) == 0x5C, "lua_State.size_ci @ 0x5C");
static_assert(offsetof(lua_State, nCcalls) == 0x60, "lua_State.nCcalls @ 0x60");
static_assert(offsetof(lua_State, baseCcalls) == 0x62, "lua_State.baseCcalls @ 0x62");
static_assert(offsetof(lua_State, hookmask) == 0x64, "lua_State.hookmask @ 0x64");
static_assert(offsetof(lua_State, allowhook) == 0x65, "lua_State.allowhook @ 0x65");
static_assert(offsetof(lua_State, basehookcount) == 0x68, "lua_State.basehookcount @ 0x68");
static_assert(offsetof(lua_State, hookcount) == 0x6C, "lua_State.hookcount @ 0x6C");
static_assert(offsetof(lua_State, hook) == 0x70, "lua_State.hook @ 0x70");
static_assert(offsetof(lua_State, l_gt) == 0x78, "lua_State.l_gt @ 0x78");
static_assert(offsetof(lua_State, env) == 0x88, "lua_State.env @ 0x88");
static_assert(offsetof(lua_State, openupval) == 0x98, "lua_State.openupval @ 0x98");
static_assert(offsetof(lua_State, gclist) == 0xA0, "lua_State.gclist @ 0xA0");
static_assert(offsetof(lua_State, errorJmp) == 0xA8, "lua_State.errorJmp @ 0xA8");
static_assert(offsetof(lua_State, errfunc) == 0xB0, "lua_State.errfunc @ 0xB0");

/* lua_Debug - debug info structure */
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

static_assert(offsetof(lua_Debug, event) == 0x00, "lua_Debug.event @ 0x00");
static_assert(offsetof(lua_Debug, name) == 0x08, "lua_Debug.name @ 0x08");
static_assert(offsetof(lua_Debug, namewhat) == 0x10, "lua_Debug.namewhat @ 0x10");
static_assert(offsetof(lua_Debug, what) == 0x18, "lua_Debug.what @ 0x18");
static_assert(offsetof(lua_Debug, source) == 0x20, "lua_Debug.source @ 0x20");
static_assert(offsetof(lua_Debug, currentline) == 0x28, "lua_Debug.currentline @ 0x28");
static_assert(offsetof(lua_Debug, nups) == 0x2C, "lua_Debug.nups @ 0x2C");
static_assert(offsetof(lua_Debug, linedefined) == 0x30, "lua_Debug.linedefined @ 0x30");
static_assert(offsetof(lua_Debug, lastlinedefined) == 0x34, "lua_Debug.lastlinedefined @ 0x34");
static_assert(offsetof(lua_Debug, short_src) == 0x38, "lua_Debug.short_src @ 0x38");
static_assert(offsetof(lua_Debug, i_ci) == 0x74, "lua_Debug.i_ci @ 0x74");

#endif /* LIBLUA_S2_H */
