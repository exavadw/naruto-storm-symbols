/* cmn41.h — Nucc::Vector4_MathGeo, nuccAABBCulling (AABB), nuccAmbient, nuccAnm::ApplyClumpData
 * Build: s2 (NSUNS2.exe, PC x64, sha 697488011750)
 * All layouts INFERRED from static decompilation of s2 binary.
 * Sizes proven from game code where noted; otherwise "size unknown, >= 0x<N>".
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Vector4_MathGeo — 4-component float vector (MathGeoLib-style)
 * Size: 0x10 (proven: ctor at 0x5859F0 copies 4 x uint32 from param_2;
 *        Cross3 at 0x58AB50 writes w=1.0f at +0xC)
 * Vtable: none (value type, no virtual calls)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Vector4_MathGeo {
    float x;                    /* 0x00 */
    float y;                    /* 0x04 */
    float z;                    /* 0x08 */
    float w;                    /* 0x0C */
} Nucc_Vector4_MathGeo;

static_assert(sizeof(Nucc_Vector4_MathGeo) == 0x10, "Nucc_Vector4_MathGeo size");
static_assert(offsetof(Nucc_Vector4_MathGeo, x) == 0x00, "Nucc_Vector4_MathGeo.x");
static_assert(offsetof(Nucc_Vector4_MathGeo, y) == 0x04, "Nucc_Vector4_MathGeo.y");
static_assert(offsetof(Nucc_Vector4_MathGeo, z) == 0x08, "Nucc_Vector4_MathGeo.z");
static_assert(offsetof(Nucc_Vector4_MathGeo, w) == 0x0C, "Nucc_Vector4_MathGeo.w");

/* ========================================================================
 * nuccAABBCulling::AABB — axis-aligned bounding box (min/max Vector3 pair)
 * Used as parameter to nuccAABBCulling::IsInFrustum (not a class with methods).
 * Size: 0x18 (proven: IsInFrustum at 0x59BDE0 reads param_1+0x00 and
 *        param_1+0x0C as two Vector3s, iterates i=0..2)
 * Vtable: none (plain struct)
 * Note: nuccAABBCulling itself has only one method (IsInFrustum) which is
 *       effectively a free function taking an AABB*; the class is a namespace wrapper.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAABBCulling_AABB {
    float min_x;                /* 0x00 */
    float min_y;                /* 0x04 */
    float min_z;                /* 0x08 */
    float max_x;                /* 0x0C */
    float max_y;                /* 0x10 */
    float max_z;                /* 0x14 */
} nuccAABBCulling_AABB;

static_assert(sizeof(nuccAABBCulling_AABB) == 0x18, "nuccAABBCulling_AABB size");
static_assert(offsetof(nuccAABBCulling_AABB, min_x) == 0x00, "nuccAABBCulling_AABB.min_x");
static_assert(offsetof(nuccAABBCulling_AABB, min_y) == 0x04, "nuccAABBCulling_AABB.min_y");
static_assert(offsetof(nuccAABBCulling_AABB, min_z) == 0x08, "nuccAABBCulling_AABB.min_z");
static_assert(offsetof(nuccAABBCulling_AABB, max_x) == 0x0C, "nuccAABBCulling_AABB.max_x");
static_assert(offsetof(nuccAABBCulling_AABB, max_y) == 0x10, "nuccAABBCulling_AABB.max_y");
static_assert(offsetof(nuccAABBCulling_AABB, max_z) == 0x14, "nuccAABBCulling_AABB.max_z");

/* ========================================================================
 * nuccAmbient — ambient light chunk (inherits nuccLight base)
 * Size: 0x70 (proven: factory FUN_1405e67b0 calls allocator FUN_140580190(0x70,
 *        "..\\source\\render\\nuccChunkAmbient.cpp"))
 * Vtable: at offset 0x00 (set to PTR_FUN_140894c38 in ctor at 0x5CC470)
 * Base class: nuccLight (ctor calls FUN_140601720 = nuccLight::nuccLight)
 * Fields from base ctor (FUN_140601720): vtable@0x00 (PTR_FUN_140898a70 initially,
 *   overridden by nuccAmbient ctor), type@0x08, pad@0x0C (set to 1.0f),
 *   qwords at 0x18,0x20,0x28,0x30,0x38,0x40,0x48, int at 0x64 (-1).
 * Ambient ctor (0x5CC470) overrides vtable to PTR_FUN_140894c38, copies
 *   base_field_18 from source+0x08, and copies two qwords from source+0x10,+0x18
 *   into self[10] (0x50) and self[0xb] (0x58).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAmbient {
    void     *vtable;           /* 0x00 — set to PTR_FUN_140894c38 by ambient ctor */
    uint32_t  base_type;        /* 0x08 — written by nuccLight ctor (param_2 arg) */
    uint32_t  _pad_0C;          /* 0x0C — set to 0x3f800000 (1.0f) by base ctor */
    uint64_t  base_field_10;    /* 0x10 — set to 0 by base ctor */
    uint64_t  base_field_18;    /* 0x18 — copied from source+0x08 in ambient ctor */
    uint64_t  base_field_20;    /* 0x20 — base class field (param_1[5]=0) */
    uint64_t  base_field_28;    /* 0x28 — base class field (param_1[6]=0) */
    uint64_t  base_field_30;    /* 0x30 — base class field (param_1[7]=0) */
    uint64_t  base_field_38;    /* 0x38 — within allocation, not directly set in ctors */
    uint64_t  base_field_40;    /* 0x40 — within allocation, not directly set in ctors */
    uint64_t  base_field_48;    /* 0x48 — within allocation, not directly set in ctors */
    uint64_t  ambient_param_a;  /* 0x50 — copied from source+0x10 in ambient ctor */
    uint64_t  ambient_param_b;  /* 0x58 — copied from source+0x18 in ambient ctor */
    uint32_t  base_field_60;    /* 0x60 — within allocation */
    uint32_t  base_field_64;    /* 0x64 — set to 0xffffffff (-1) by base ctor */
    uint64_t  _unknown_68;      /* 0x68 — within 0x70 allocation, purpose unknown */
} nuccAmbient;

static_assert(sizeof(nuccAmbient) == 0x70, "nuccAmbient size");
static_assert(offsetof(nuccAmbient, vtable)         == 0x00, "nuccAmbient.vtable");
static_assert(offsetof(nuccAmbient, base_type)       == 0x08, "nuccAmbient.base_type");
static_assert(offsetof(nuccAmbient, _pad_0C)         == 0x0C, "nuccAmbient._pad_0C");
static_assert(offsetof(nuccAmbient, base_field_10)   == 0x10, "nuccAmbient.base_field_10");
static_assert(offsetof(nuccAmbient, base_field_18)   == 0x18, "nuccAmbient.base_field_18");
static_assert(offsetof(nuccAmbient, base_field_20)   == 0x20, "nuccAmbient.base_field_20");
static_assert(offsetof(nuccAmbient, base_field_28)   == 0x28, "nuccAmbient.base_field_28");
static_assert(offsetof(nuccAmbient, base_field_30)   == 0x30, "nuccAmbient.base_field_30");
static_assert(offsetof(nuccAmbient, base_field_38)   == 0x38, "nuccAmbient.base_field_38");
static_assert(offsetof(nuccAmbient, base_field_40)   == 0x40, "nuccAmbient.base_field_40");
static_assert(offsetof(nuccAmbient, base_field_48)   == 0x48, "nuccAmbient.base_field_48");
static_assert(offsetof(nuccAmbient, ambient_param_a) == 0x50, "nuccAmbient.ambient_param_a");
static_assert(offsetof(nuccAmbient, ambient_param_b) == 0x58, "nuccAmbient.ambient_param_b");
static_assert(offsetof(nuccAmbient, base_field_60)   == 0x60, "nuccAmbient.base_field_60");
static_assert(offsetof(nuccAmbient, base_field_64)   == 0x64, "nuccAmbient.base_field_64");
static_assert(offsetof(nuccAmbient, _unknown_68)     == 0x68, "nuccAmbient._unknown_68");

/* ========================================================================
 * nuccAnm::ApplyClumpData — animation clump substitution data (linked list node)
 *
 * Size: unknown, >= 0xA0 (dtor at 0x5A0940 accesses fields up to offset 0x98)
 *
 * S2 STRING LAYOUT (from dtor at 0x5A0940):
 *   Each std::string-like field uses a non-standard MSVC STL layout:
 *     SSO buf[8]  @ base+0x00  (only first byte cleared on destroy)
 *     ptr         @ base+0x08  (heap ptr when size > 0xf; freed by dtor)
 *     size        @ base+0x20  (string length; dtor resets to 0xf = SSO threshold)
 *     extra       @ base+0x28  (allocator/capacity; dtor sets to PTR_FUN_14089c1b8)
 *   Three such strings at offsets 0x00, 0x38, 0x70.
 *
 * LINKED-LIST OVERLAY (from operator= at 0x5A30F0):
 *   +0x18 and +0x20 serve dual purpose as linked-list node pointers:
 *     +0x18 = head pointer (checked for NULL; if null, new node allocated)
 *     +0x20 = tail/current pointer (node->next written at *(tail + 0xB8))
 *   These overlap with what would normally be string0's size field region.
 *   This is possible because the linked-list metadata lives in the gap between
 *   string0's ptr (+0x08) and its size (+0x20), using +0x10..+0x1F.
 *   Refcount short at +0x30 incremented/decremented in operator=.
 *
 * Vtable: none observed (no virtual calls in dtor or operator=)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnm_ApplyClumpData {
    /* --- String 0 (SSO layout: buf[8] + ptr@+0x08 + gap + size@+0x20 + extra@+0x28) --- */
    uint8_t  str0_sso_buf[8];   /* 0x00 — SSO inline buffer (8 bytes); dtor clears byte at +0x08 */
    uint64_t str0_ptr;          /* 0x08 — heap ptr when len > 0xf; freed by dtor via FUN_140580440 */
    uint64_t list_head;         /* 0x10 — SIM: linked-list head ptr (operator= checks for NULL) */
    uint64_t list_tail_or_size; /* 0x18 — SIM: linked-list tail ptr OR string size (dual-use) */
    uint64_t str0_size;         /* 0x20 — string length; dtor resets to 0xf; also list current ptr */
    uint64_t str0_extra;        /* 0x28 — allocator/capacity; dtor sets to PTR_FUN_14089c1b8 */

    /* --- Refcount + padding --- */
    uint16_t refcount;          /* 0x30 — incremented in operator=, returned as short */
    uint8_t  _pad_32[6];        /* 0x32 — alignment padding to next string at 0x38 */

    /* --- String 1 (same SSO layout at base+0x38) --- */
    uint8_t  str1_sso_buf[8];   /* 0x38 — SSO inline buffer; dtor clears byte at +0x40 */
    uint64_t str1_ptr;          /* 0x40 — heap ptr when len > 0xf; freed by dtor */
    uint64_t _gap_48;           /* 0x48 — unused gap (8 bytes between ptr and size) */
    uint64_t str1_size;         /* 0x50 — string length; dtor resets to 0xf */
    uint64_t str1_extra;        /* 0x58 — allocator/capacity; dtor sets to PTR_FUN_14089c1b8 */
    uint64_t _unknown_60;       /* 0x60 — within object, not accessed in dtor/operator= */

    /* --- String 2 (same SSO layout at base+0x70) --- */
    uint8_t  _pad_68[8];        /* 0x68 — padding/gap before string 2 */
    uint8_t  str2_sso_buf[8];   /* 0x70 — SSO inline buffer; dtor clears byte at +0x78 */
    uint64_t str2_ptr;          /* 0x78 — heap ptr when len > 0xf; freed by dtor */
    uint64_t _gap_80;           /* 0x80 — unused gap */
    uint64_t str2_size;         /* 0x88 — string length; dtor resets to 0xf */
    uint64_t str2_extra;        /* 0x90 — allocator/capacity; dtor sets to PTR_FUN_14089c1b8 */
    uint64_t str2_allocator;    /* 0x98 — dtor reads this as ptr to pass to FUN_140585990 */
} nuccAnm_ApplyClumpData;
/* size unknown, >= 0xA0 (last dtor access at +0x98; linked-list stride 0xB8 suggests
 * total node size may be larger but unproven beyond 0xA0) */

static_assert(offsetof(nuccAnm_ApplyClumpData, str0_sso_buf)    == 0x00, "ApplyClumpData.str0_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_ptr)        == 0x08, "ApplyClumpData.str0_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, list_head)       == 0x10, "ApplyClumpData.list_head");
static_assert(offsetof(nuccAnm_ApplyClumpData, list_tail_or_size) == 0x18, "ApplyClumpData.list_tail_or_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_size)       == 0x20, "ApplyClumpData.str0_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_extra)      == 0x28, "ApplyClumpData.str0_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, refcount)        == 0x30, "ApplyClumpData.refcount");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_32)         == 0x32, "ApplyClumpData._pad_32");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_sso_buf)    == 0x38, "ApplyClumpData.str1_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_ptr)        == 0x40, "ApplyClumpData.str1_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_48)         == 0x48, "ApplyClumpData._gap_48");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_size)       == 0x50, "ApplyClumpData.str1_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_extra)      == 0x58, "ApplyClumpData.str1_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, _unknown_60)     == 0x60, "ApplyClumpData._unknown_60");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_68)         == 0x68, "ApplyClumpData._pad_68");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_sso_buf)    == 0x70, "ApplyClumpData.str2_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_ptr)        == 0x78, "ApplyClumpData.str2_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_80)         == 0x80, "ApplyClumpData._gap_80");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_size)       == 0x88, "ApplyClumpData.str2_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_extra)      == 0x90, "ApplyClumpData.str2_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_allocator)  == 0x98, "ApplyClumpData.str2_allocator");