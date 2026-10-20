/* rbRNG s1 — RNG state structs for NARUTO STORM 1 PC (NSUNS1.exe)
 * Build: s1 · SHA prefix: 10231093af9c · Image base: 0x140000000
 * All layouts INFERRED from static analysis of this PC x64 build.
 */

#ifndef RBRNG_S1_H
#define RBRNG_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* Global RVAs (offset from image base 0x140000000)                   */
/* ------------------------------------------------------------------ */

/* MT19937 */
#define S1_MT19937_STATE_RVA   0x8C9640u  /* uint32_t[624]            */
#define S1_MT19937_INDEX_RVA   0x853D10u  /* int32_t mti              */
#define S1_MT19937_TWIST_RVA   0x853D18u  /* uint32_t[2] (constant)   */

/* PartRand – u64 LCG (×0x343FD + 0x269EC3) */
#define S1_PARTRAND_STATE_RVA  0x884E70u  /* uint64_t                 */

/* AsyncRand – u64 LCG (×0x343FD + 0x269EC3) */
#define S1_ASYNCRAND_STATE_RVA 0x8C53C0u  /* uint64_t                 */

/* ------------------------------------------------------------------ */
/* RNG state structs                                                   */
/* ------------------------------------------------------------------ */

/* MT19937 full state (state table + index).
 * Twist table at 0x853D18 is constant and excluded.
 * Snapshot size: sizeof(s1_mt19937_state) == 0x9C4 bytes.
 * NOT required for rollback (only consumed at init). */
typedef struct s1_mt19937_state {
    uint32_t mt[624];   /* 0x000 – state table               */
    int32_t  mti;       /* 0x9C0 – index into mt[]           */
} s1_mt19937_state;

static_assert(sizeof(s1_mt19937_state) == 0x9C4,
              "s1_mt19937_state must be 0x9C4 bytes");
static_assert(offsetof(s1_mt19937_state, mt) == 0x0,
              "mt must start at offset 0");
static_assert(offsetof(s1_mt19937_state, mti) == 0x9C0,
              "mti must be at offset 0x9C0");

/* PartRand – single u64 LCG state.
 * Snapshot size: 8 bytes. REQUIRED for rollback. */
typedef struct s1_partrand_state {
    uint64_t state;     /* LCG state at RVA 0x884E70 */
} s1_partrand_state;

static_assert(sizeof(s1_partrand_state) == 8,
              "s1_partrand_state must be 8 bytes");
static_assert(offsetof(s1_partrand_state, state) == 0,
              "state must be at offset 0");

/* AsyncRand – single u64 LCG state.
 * Snapshot size: 8 bytes. REQUIRED for rollback. */
typedef struct s1_asyncrand_state {
    uint64_t state;     /* LCG state at RVA 0x8C53C0 */
} s1_asyncrand_state;

static_assert(sizeof(s1_asyncrand_state) == 8,
              "s1_asyncrand_state must be 8 bytes");
static_assert(offsetof(s1_asyncrand_state, state) == 0,
              "state must be at offset 0");

/* Combined minimal rollback RNG snapshot (PartRand + AsyncRand).
 * Total: 16 bytes. */
typedef struct s1_rng_snapshot {
    s1_partrand_state  partrand;   /* 0x0 */
    s1_asyncrand_state asyncrand;  /* 0x8 */
} s1_rng_snapshot;

static_assert(sizeof(s1_rng_snapshot) == 16,
              "s1_rng_snapshot must be 16 bytes");
static_assert(offsetof(s1_rng_snapshot, partrand) == 0,
              "partrand must be at offset 0");
static_assert(offsetof(s1_rng_snapshot, asyncrand) == 8,
              "asyncrand must be at offset 8");

#endif /* RBRNG_S1_H */