// ccGameManager (NSUNS3.exe, build s3) — reconstructed from Ghidra decompilation
// Singleton manager; size = 0x90 bytes (from allocator argument in InitInstances #1)
// Contains 3 × 0x30-byte sub-objects with vtables at +0x18, +0x48, +0x78
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19
// Source string in ctor: 'source\\sys\\ccBindCpkManager.cpp'

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

// Opaque 0x30-byte sub-object used 3× within ccGameManager.
// Each has a vtable pointer at relative offset +0x18 within the sub-object.
// Constructor pattern: zero first 3 qwords, set vtable, call FUN_140684c60/FUN_140684bc0.
// Destructor cleans up via FUN_14020e3a0 and resets vtable.
typedef struct ccBindCpkSubObject {
    uint64_t field_0;           // 0x00 zeroed in ctor
    uint64_t field_8;           // 0x08 zeroed in ctor
    uint64_t field_10;          // 0x10 zeroed in ctor
    void*    vtable;            // 0x18 PTR_FUN_1409ec308
    uint8_t  _pad_20[0x10];     // 0x20 unknown (part of sub-object body)
} ccBindCpkSubObject;

struct ccGameManager {
    // --- Sub-object 0 at +0x00 ---
    ccBindCpkSubObject subObj_0;    // 0x00 (vtable at +0x18)

    // --- Sub-object 1 at +0x30 ---
    ccBindCpkSubObject subObj_1;    // 0x30 (vtable at +0x48)

    // --- Sub-object 2 at +0x60 ---
    ccBindCpkSubObject subObj_2;    // 0x60 (vtable at +0x78)
};

// Compile-time layout checks (INFERRED from decompiler output)
_Static_assert(sizeof(ccBindCpkSubObject) == 0x30, "sizeof_ccBindCpkSubObject");
_Static_assert(offsetof(struct ccGameManager, subObj_0) == 0x00, "subObj_0");
_Static_assert(offsetof(struct ccGameManager, subObj_1) == 0x30, "subObj_1");
_Static_assert(offsetof(struct ccGameManager, subObj_2) == 0x60, "subObj_2");
_Static_assert(offsetof(struct ccGameManager, subObj_0.vtable) == 0x18, "subObj_0_vtable");
_Static_assert(offsetof(struct ccGameManager, subObj_1.vtable) == 0x48, "subObj_1_vtable");
_Static_assert(offsetof(struct ccGameManager, subObj_2.vtable) == 0x78, "subObj_2_vtable");
_Static_assert(sizeof(struct ccGameManager) == 0x90, "sizeof_ccGameManager");