/* cmn41.h - Nucc::Vector4_MathGeo, nuccAABBCulling::AABB, nuccAmbient, nuccAnm::ApplyClumpData
 * Build: s4 (NSUNS4_release.exe, PC x64, sha 147e52a3e0d7)
 * All layouts INFERRED from static decompilation of s4 binary.
 * Sizes proven from game code where noted; otherwise size unknown, >= 0xNN.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Vector4_MathGeo - 4-component float vector (MathGeoLib-style)
 * Size: 0x10 (proven: copy ctor at 0xA30A80 copies 4 x uint32)
 * Vtable: none (value type)
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
 * nuccAABBCulling::AABB - axis-aligned bounding box (min/max Vector3 pair)
 * Size: 0x18 (proven: IsInFrustum at 0xA25A50 reads param_1+0x00 and
 * param_1+0x0C as two Vector3s, loop i=0..2)
 * Vtable: none (plain struct)
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
 * nuccAmbient - ambient light chunk (inherits nuccLight base)
 * Size: 0x70 (proven: operator_new(0x70) in nuccChunkAmbient::Create at 0xA7CFE0)
 * Vtable: at offset 0x00
 * ctor (0xA562E0): PTR_FUN_14110b228
 * base nuccLight (0xA4ADB0): PTR_FUN_141109838
 * s3 had size 0x88 with trailing gaps; s4 is compact at 0x70.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAmbient {
    void     *vtable;           /* 0x00 - PTR_FUN_14110b228 */
    uint32_t  base_type;        /* 0x08 - written by base ctor param_2 */
    uint32_t  pad_0C;           /* 0x0C - alignment / 1.0f */
    uint64_t  base_field_10;    /* 0x10 - copied from src+0x10 in nuccLight ctor */
    uint64_t  base_field_18;    /* 0x18 - copied from src+0x08 in nuccAmbient ctor */
    uint64_t  base_field_20;    /* 0x20 - zeroed by nuccLight ctor (param_1[3]) */
    uint64_t  base_field_28;    /* 0x28 - zeroed by nuccLight ctor (param_1[4]) */
    uint64_t  base_field_30;    /* 0x30 - zeroed by nuccLight ctor (param_1[5]) */
    uint64_t  base_field_38;    /* 0x38 - zeroed by nuccLight ctor (param_1[6]) */
    uint64_t  ambient_param_0;  /* 0x40 - copied from src+0x10 in nuccAmbient ctor */
    uint64_t  ambient_param_1;  /* 0x48 - copied from src+0x18 in nuccAmbient ctor */
    uint64_t  base_field_50;    /* 0x50 - written by nuccAmbient ctor (param_1[10]) */
    uint64_t  base_field_58;    /* 0x58 - written by nuccAmbient ctor (param_1[0xb]) */
    uint64_t  base_field_60;    /* 0x60 - zeroed by nuccLight ctor (param_1[5]) */
    uint64_t  base_field_68;    /* 0x68 - zeroed by nuccLight ctor (param_1[6]) */
} nuccAmbient;

static_assert(sizeof(nuccAmbient) == 0x70, "nuccAmbient size");
static_assert(offsetof(nuccAmbient, vtable)          == 0x00, "nuccAmbient.vtable");
static_assert(offsetof(nuccAmbient, base_type)       == 0x08, "nuccAmbient.base_type");
static_assert(offsetof(nuccAmbient, pad_0C)          == 0x0C, "nuccAmbient.pad_0C");
static_assert(offsetof(nuccAmbient, base_field_10)   == 0x10, "nuccAmbient.base_field_10");
static_assert(offsetof(nuccAmbient, base_field_18)   == 0x18, "nuccAmbient.base_field_18");
static_assert(offsetof(nuccAmbient, base_field_20)   == 0x20, "nuccAmbient.base_field_20");
static_assert(offsetof(nuccAmbient, base_field_28)   == 0x28, "nuccAmbient.base_field_28");
static_assert(offsetof(nuccAmbient, base_field_30)   == 0x30, "nuccAmbient.base_field_30");
static_assert(offsetof(nuccAmbient, base_field_38)   == 0x38, "nuccAmbient.base_field_38");
static_assert(offsetof(nuccAmbient, ambient_param_0) == 0x40, "nuccAmbient.ambient_param_0");
static_assert(offsetof(nuccAmbient, ambient_param_1) == 0x48, "nuccAmbient.ambient_param_1");
static_assert(offsetof(nuccAmbient, base_field_50)   == 0x50, "nuccAmbient.base_field_50");
static_assert(offsetof(nuccAmbient, base_field_58)   == 0x58, "nuccAmbient.base_field_58");
static_assert(offsetof(nuccAmbient, base_field_60)   == 0x60, "nuccAmbient.base_field_60");
static_assert(offsetof(nuccAmbient, base_field_68)   == 0x68, "nuccAmbient.base_field_68");

/* ========================================================================
 * nuccAnm::ApplyClumpData - animation clump substitution data
 * Size: unknown, >= 0xA0 (dtor at 0xA14E60 accesses up to +0x98;
 * operator= at 0xA17A60 uses linked-list stride 0xB8)
 * Vtable: none observed
 * Layout: Three MSVC-style SSO strings at base offsets 0x00, 0x38, 0x70;
 * linked list head at +0x10/tail at +0x18 with next stride 0xB8;
 * refcount uint16 at +0x30
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnm_ApplyClumpData {
    /* String 0 region */
    uint8_t  str0_sso_buf[8];   /* 0x00 */
    void    *str0_ptr;          /* 0x08 */
    void    *list_head;         /* 0x10 - FUN_140a182c0 result when first node */
    void    *list_tail;         /* 0x18 - updated on append (stride 0xB8) */
    uint64_t str0_size;         /* 0x20 - dtor resets to 0xf */
    uint64_t str0_extra;        /* 0x28 - allocator field */
    uint16_t refcount;          /* 0x30 - incremented in operator= */
    uint8_t  _pad_32[6];        /* 0x32 */

    /* String 1 region */
    uint8_t  str1_sso_buf[8];   /* 0x38 */
    void    *str1_ptr;          /* 0x40 */
    uint64_t _gap_48;           /* 0x48 */
    uint64_t str1_size;         /* 0x50 - dtor resets to 0xf */
    uint64_t str1_extra;        /* 0x58 - allocator field */
    uint64_t _unknown_60;       /* 0x60 - accessed by dtor */
    uint64_t _pad_68;           /* 0x68 */

    /* String 2 region */
    uint8_t  str2_sso_buf[8];   /* 0x70 */
    void    *str2_ptr;          /* 0x78 */
    uint64_t _gap_80;           /* 0x80 */
    uint64_t str2_size;         /* 0x88 - dtor resets to 0xf */
    uint64_t str2_extra;        /* 0x90 - allocator field */
    uint64_t str2_allocator;    /* 0x98 - dtor passes to GameActor::Component::GetOwnerHandle */
} nuccAnm_ApplyClumpData;
/* size unknown, >= 0xA0 */

static_assert(offsetof(nuccAnm_ApplyClumpData, str0_sso_buf)  == 0x00, "ACD.str0_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_ptr)      == 0x08, "ACD.str0_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, list_head)     == 0x10, "ACD.list_head");
static_assert(offsetof(nuccAnm_ApplyClumpData, list_tail)     == 0x18, "ACD.list_tail");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_size)     == 0x20, "ACD.str0_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_extra)    == 0x28, "ACD.str0_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, refcount)      == 0x30, "ACD.refcount");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_32)       == 0x32, "ACD._pad_32");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_sso_buf)  == 0x38, "ACD.str1_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_ptr)      == 0x40, "ACD.str1_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_48)       == 0x48, "ACD._gap_48");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_size)     == 0x50, "ACD.str1_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_extra)    == 0x58, "ACD.str1_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, _unknown_60)   == 0x60, "ACD._unknown_60");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_68)       == 0x68, "ACD._pad_68");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_sso_buf)  == 0x70, "ACD.str2_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_ptr)      == 0x78, "ACD.str2_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_80)       == 0x80, "ACD._gap_80");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_size)     == 0x88, "ACD.str2_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_extra)    == 0x90, "ACD.str2_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_allocator)== 0x98, "ACD.str2_allocator");