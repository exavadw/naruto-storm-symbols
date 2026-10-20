/*
 * rbFighter struct group — NARUTO STORM 3 Full Burst HD (s3, NSUNS3.exe x64)
 *
 * All fields INFERRED from static analysis (state_surface + decompilation),
 * not CONFIRMED by runtime tracing.
 *
 * Base class: ccPlayer_t (size 0xAFB8) — see ccPlayer.h
 * Subclasses ccPlayerLeader, ccPlayerSupport, ccPlayerPartner share the same
 * allocation size as ccPlayerMain (0xAFB8); no extension fields proven.
 * Differentiation is via vtable dispatch, not additional instance state.
 *
 * ccPlayerGrp: standalone container, allocated at 0x40 bytes.
 * ccPlayerTeamMng: absent from s3 (zero symbols).
 *
 * Allocation evidence:
 *   ccPlayerMain: CreatePlayer04<ccPlayerMain> → FUN_140683f70(0xAFB8, ...)
 *   ccPlayerGrp:  CreateInstance → FUN_140683f70(0x40, "source\\Battle\\Player\\ccPlayerGrp.cpp", 0x2FC)
 *   Leader/Support/Partner: no separate allocation; created as ccPlayerMain (0xAFB8)
 */

#ifndef RBFIGHTER_S3_H
#define RBFIGHTER_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declaration — full definition in ccPlayer.h */
#ifndef CCPLAYER_S3_H
typedef struct ccPlayer_t ccPlayer_t;
#endif

/* ============================================================
 * ccPlayerLeader — leader player subclass
 * Size: 0xAFB8 (same as base ccPlayer)
 * Proven: CreatePlayer04<ccPlayerMain> → FUN_140683f70(0xAFB8, ...)
 *         No CreatePlayer04<ccPlayerLeader> instantiation exists.
 *         state_surface max offset = 0xAFB4 (within base range).
 *
 * NO INSTANCE STATE beyond base ccPlayer.
 * Evidence: (a) allocation size 0xAFB8 == base ccPlayer exactly,
 *           (b) all 322 state_surface fields fall within 0x70..0xAFB4,
 *           (c) no subclass-specific named fields discovered,
 *           (d) matches s2 pattern where Leader also had no extension.
 * Subclass behavior differentiated by vtable dispatch only.
 * ============================================================ */
typedef struct __attribute__((packed)) ccPlayerLeader_t {
    uint8_t ccPlayer_base[0xAFB8]; /* 0x0000 - base ccPlayer state */
} ccPlayerLeader_t;

static_assert(sizeof(ccPlayerLeader_t) == 0xAFB8,
              "ccPlayerLeader size must be 0xAFB8");

/* ============================================================
 * ccPlayerSupport — support player subclass
 * Size: 0xAFB8 (same as base ccPlayer)
 * Inferred: ccPlayerSupport::Create (0x568184) receives pre-allocated ptr;
 *           no separate allocator call found.
 *           state_surface max offset = 0xAE24 (within base range).
 *
 * NO INSTANCE STATE beyond base ccPlayer.
 * Evidence: (a) no separate allocation found; Create receives pre-allocated ptr,
 *           (b) all 128 state_surface fields fall within 0x70..0xAE24,
 *           (c) no subclass-specific named fields discovered,
 *           (d) matches s2 pattern where Support also had no extension.
 * Subclass behavior differentiated by vtable dispatch only.
 * ============================================================ */
typedef struct __attribute__((packed)) ccPlayerSupport_t {
    uint8_t ccPlayer_base[0xAFB8]; /* 0x0000 - base ccPlayer state */
} ccPlayerSupport_t;

static_assert(sizeof(ccPlayerSupport_t) == 0xAFB8,
              "ccPlayerSupport size must be 0xAFB8");

/* ============================================================
 * ccPlayerPartner — partner player subclass
 * Size: 0xAFB8 (same as base ccPlayer)
 * Inferred: ccPlayerPartner::Create (0x570E2C) receives pre-allocated ptr;
 *           no separate allocator call found.
 *           state_surface max offset = 0xAD70 (within base range).
 *
 * NO INSTANCE STATE beyond base ccPlayer.
 * Evidence: (a) no separate allocation found; Create receives pre-allocated ptr,
 *           (b) all 121 state_surface fields fall within 0x70..0xAD70,
 *           (c) no subclass-specific named fields discovered,
 *           (d) matches s2 pattern where Partner also had no extension.
 * Subclass behavior differentiated by vtable dispatch only.
 * ============================================================ */
typedef struct __attribute__((packed)) ccPlayerPartner_t {
    uint8_t ccPlayer_base[0xAFB8]; /* 0x0000 - base ccPlayer state */
} ccPlayerPartner_t;

static_assert(sizeof(ccPlayerPartner_t) == 0xAFB8,
              "ccPlayerPartner size must be 0xAFB8");

/* ============================================================
 * ccPlayerGrp — player group container (standalone, NOT a ccPlayer subclass)
 * Size: 0x40 (64 bytes)
 * Proven: CreateInstance → FUN_140683f70(0x40, "source\\Battle\\Player\\ccPlayerGrp.cpp", 0x2FC)
 *         Singleton pattern via DAT_140bd8e10.
 *
 * NO INSTANCE STATE (opaque container).
 * Evidence: (a) allocation size proven at 0x40 bytes,
 *           (b) state_surface found only 2 read-only fields at 0xA04 and 0x6080
 *               which exceed allocation size — these are indirect accesses through
 *               embedded pointers, not direct struct member offsets,
 *           (c) internal layout unknown; treat as opaque blob for rollback.
 * ============================================================ */
typedef struct __attribute__((packed)) ccPlayerGrp_t {
    uint8_t data[0x40]; /* 0x0000 - opaque container data */
} ccPlayerGrp_t;

static_assert(sizeof(ccPlayerGrp_t) == 0x40,
              "ccPlayerGrp size must be 0x40");

/* ============================================================
 * ccPlayerTeamMng — ABSENT from s3
 * Zero symbols found in the decompiler cache.db for build alias 's3'.
 * Also absent from s2. May have been removed after Storm 1 or
 * merged into another manager class.
 *
 * NO INSTANCE STATE — class does not exist in this build.
 * ============================================================ */

#endif /* RBFIGHTER_S3_H */