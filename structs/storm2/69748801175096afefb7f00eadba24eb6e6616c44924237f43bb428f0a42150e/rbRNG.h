/* rbRNG s2 — RNG state structs for NARUTO STORM 2 PC (NSUNS2.exe)
 * Build: s2 · SHA prefix: 697488011750 · Image base: 0x140000000
 * All layouts INFERRED from static analysis of this PC x64 build.
 */

#ifndef RBRNG_S2_H
#define RBRNG_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* Global RVAs (offset from image base 0x140000000)                   */
/* ------------------------------------------------------------------ */

/* MT19937 */
#define S2_MT19937_STATE_RVA   0xAA2010u  /* uint32_t[624]            */
#define S2_MT19937_INDEX_RVA   0x99B2F8u  /* int32_t mti              */
#define S2_MT19937_TWIST_RVA   0x99B300u  /* uint32_t[2] (constant)   */

/* PartRand – u64 LCG (×0x343FD + 0x269EC3) */
#define S2_PARTRAND_STATE_RVA  0xAA3D40u  /* uint64_t                 */

/* AsyncRand – u64 LCG (×0x343FD + 0x269EC3) */
#define S2_ASYNCRAND_STATE_RVA 0xA5D9A0u  /* uint64_t                 */

/* ------------------------------------------------------------------ */
/* RNG state structs                                                   */
/* ------------------------------------------------------------------ */

/* MT19937 full state (state table + index).
 * Twist table at 0x99B300 is constant and excluded.
 * Snapshot size: sizeof(s2_mt19937_state) == 0x9C4 bytes.
 * NOT required for rollback (only consumed at init). */
typedef struct s2_mt19937_state {
    uint32_t mt[624];   /* 0x000 – state table               */
    int32_t  mti;       /* 0x9C0 – index into mt[]           */
} s2_mt19937_state;

static_assert(sizeof(s2_mt19937_state) == 0x9C4,
              "s2_mt19937_state must be 0x9C4 bytes");
static_assert(offsetof(s2_mt19937_state, mt) == 0x0,
              "mt must start at offset 0");
static_assert(offsetof(s2_mt19937_state, mti) == 0x9C0,
              "mti must be at offset 0x9C0");

/* PartRand – single u64 LCG state.
 * Snapshot size: 8 bytes. REQUIRED for rollback. */
typedef struct s2_partrand_state {
    uint64_t state;     /* LCG state at RVA 0xAA3D40 */
} s2_partrand_state;

static_assert(sizeof(s2_partrand_state) == 8,
              "s2_partrand_state must be 8 bytes");
static_assert(offsetof(s2_partrand_state, state) == 0,
              "state must be at offset 0");

/* AsyncRand – single u64 LCG state.
 * Snapshot size: 8 bytes. REQUIRED for rollback. */
typedef struct s2_asyncrand_state {
    uint64_t state;     /* LCG state at RVA 0xA5D9A0 */
} s2_asyncrand_state;

static_assert(sizeof(s2_asyncrand_state) == 8,
              "s2_asyncrand_state must be 8 bytes");
static_assert(offsetof(s2_asyncrand_state, state) == 0,
              "state must be at offset 0");

/* Combined minimal rollback RNG snapshot (PartRand + AsyncRand).
 * Total: 16 bytes. */
typedef struct s2_rng_snapshot {
    s2_partrand_state  partrand;   /* 0x0 */
    s2_asyncrand_state asyncrand;  /* 0x8 */
} s2_rng_snapshot;

static_assert(sizeof(s2_rng_snapshot) == 16,
              "s2_rng_snapshot must be 16 bytes");
static_assert(offsetof(s2_rng_snapshot, partrand) == 0,
              "partrand must be at offset 0");
static_assert(offsetof(s2_rng_snapshot, asyncrand) == 8,
              "asyncrand must be at offset 8");

#endif /* RBRNG_S2_H */