/* cmn41.h — Nucc::Vector4_MathGeo, nuccAABBCulling (AABB), nuccAmbient, nuccAnm::ApplyClumpData
 * Build: s1 (NSUNS1.exe, PC x64)
 * All layouts INFERRED from static decompilation of s1 binary.
 * Sizes proven from game code where noted; otherwise "size unknown, >= 0x<N>".
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Vector4_MathGeo — 4-component float vector (MathGeoLib-style)
 * Size: 0x10 (proven: ctor writes 4 floats at offsets 0,4,8,C; Cross3 writes w=1.0f at +0xC)
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
 * Size: 0x18 (proven: IsInFrustum reads param_1+0x00 and param_1+0x0C as two Vector3s,
 *   iterates i=0..2 accessing min[i] and max[i] via thunk_FUN_140144610/140144630)
 * Vtable: none (plain struct)
 * Note: nuccAABBCulling itself has only one method (IsInFrustum) which is effectively
 *   a free function taking an AABB*; the class is a namespace wrapper.
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
 * Size: 0x70 (proven: nuccChunkAmbient::Create allocates 0x70 via FUN_14047ed10(0x70,...))
 * Vtable: at offset 0x00 (set to PTR_FUN_1406895f8 in ctor)
 * Base: nuccLight (ctor calls FUN_14048bf10 = nuccLight::nuccLight)
 * Fields from ctor (0x4B4450): vtable@0x00, base fields through 0x58,
 *   then copies two qwords from source at +0x10,+0x18 into self[10],self[0xb]
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAmbient {
    void *vtable;               /* 0x00 — set to PTR_FUN_1406895f8 */
    uint32_t base_type;         /* 0x08 — written by nuccLight ctor (param_2 arg) */
    uint32_t _pad_0C;           /* 0x0C — padding / base field */
    uint64_t base_field_10;     /* 0x10 — base class field */
    uint64_t base_field_18;     /* 0x18 — base class field */
    uint64_t base_field_20;     /* 0x20 — base class field */
    uint64_t base_field_28;     /* 0x28 — base class field */
    uint64_t base_field_30;     /* 0x30 — base class field */
    uint64_t base_field_38;     /* 0x38 — base class field */
    uint64_t base_field_40;     /* 0x40 — base class field */
    uint64_t base_field_48;     /* 0x48 — base class field */
    uint64_t ambient_param_a;   /* 0x50 — copied from source+0x10 in ctor */
    uint64_t ambient_param_b;   /* 0x58 — copied from source+0x18 in ctor */
    uint64_t _unknown_60;       /* 0x60 — within allocation, purpose unknown */
    uint64_t _unknown_68;       /* 0x68 — within allocation, purpose unknown */
} nuccAmbient;

static_assert(sizeof(nuccAmbient) == 0x70, "nuccAmbient size");
static_assert(offsetof(nuccAmbient, vtable) == 0x00, "nuccAmbient.vtable");
static_assert(offsetof(nuccAmbient, base_type) == 0x08, "nuccAmbient.base_type");
static_assert(offsetof(nuccAmbient, ambient_param_a) == 0x50, "nuccAmbient.ambient_param_a");
static_assert(offsetof(nuccAmbient, ambient_param_b) == 0x58, "nuccAmbient.ambient_param_b");
static_assert(offsetof(nuccAmbient, _unknown_60) == 0x60, "nuccAmbient._unknown_60");
static_assert(offsetof(nuccAmbient, _unknown_68) == 0x68, "nuccAmbient._unknown_68");

/* ========================================================================
 * nuccAnm::ApplyClumpData — animation clump substitution data (linked list node)
 * Size: unknown, >= 0x32 (last proven field is refcount short at 0x30)
 *   Embedded at offset 0x138 in parent object (from AddSubstitutionKey).
 *   Linked list stride 0xB8 (node->next at node+0xB8, seen in operator=).
 *   Three std::string-like fields (SSO threshold 0xf) at 0x00, 0x20, 0x40.
 *   Pointer fields at 0x18, 0x20 (list node ptrs from operator=).
 * Vtable: none observed (no virtual calls in dtor or operator=)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnm_ApplyClumpData {
    /* std::string-like field 0 (SSO: buf[16] + size@+0x10 + cap@+0x18) */
    uint8_t str0_buf[16];      /* 0x00 */
    uint64_t str0_size;        /* 0x10 */
    uint64_t str0_cap_or_ptr;  /* 0x18 — also used as list node ptr in operator= */

    /* std::string-like field 1 */
    uint8_t str1_buf[16];      /* 0x20 */
    uint64_t str1_size;        /* 0x30 — but operator= writes short refcount here */
    uint64_t str1_cap_or_ptr;  /* 0x38 */

    /* std::string-like field 2 */
    uint8_t str2_buf[16];      /* 0x40 */
    uint64_t str2_size;        /* 0x50 */
    uint64_t str2_cap_or_ptr;  /* 0x58 */
} nuccAnm_ApplyClumpData;
/* size unknown, >= 0x60 (three std::strings); last field access at 0x58 in dtor */

static_assert(offsetof(nuccAnm_ApplyClumpData, str0_buf) == 0x00, "ApplyClumpData.str0_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_size) == 0x10, "ApplyClumpData.str0_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_cap_or_ptr) == 0x18, "ApplyClumpData.str0_cap_or_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_buf) == 0x20, "ApplyClumpData.str1_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_size) == 0x30, "ApplyClumpData.str1_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_cap_or_ptr) == 0x38, "ApplyClumpData.str1_cap_or_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_buf) == 0x40, "ApplyClumpData.str2_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_size) == 0x50, "ApplyClumpData.str2_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_cap_or_ptr) == 0x58, "ApplyClumpData.str2_cap_or_ptr");