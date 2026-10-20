/* cmn87.h — nuccCriFsStdio, nuccCriSofdec2Manager, nuccCriSofdec2Work
 * Build: s1 (NSUNS1.exe, PC x64)
 * All layouts INFERRED from static analysis. Not CONFIRMED at runtime.
 * Own-game names only (ns1:: / Switch Trilogy Storm 1 strings).
 * PC offsets only (image base 0x140000000).
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::Memory::BlockAllocator base class.
 * Size: 0x18 (vtable + two pointer-sized fields).
 * Proven by: nuccCriSofdec2Work ctor calls BlockAllocator::BlockAllocator()
 * then writes param_1[3] at +0x18, so base occupies [0x00..0x17]. */
typedef struct __attribute__((packed)) Nucc_Memory_BlockAllocator {
    uint64_t vtable;            /* +0x00 */
    uint64_t field_08;          /* +0x08 */
    uint64_t field_10;          /* +0x10 */
} Nucc_Memory_BlockAllocator;
static_assert(sizeof(Nucc_Memory_BlockAllocator) == 0x18, "BlockAllocator size");

/* nuccCriTextureBuffer: embedded sub-object.
 * Size: 0x68 (proven by stride: instances at +0x398, +0x400, +0x468, +0x4D0;
 * 0x400 - 0x398 = 0x68). Internal layout not reconstructed here. */
typedef struct __attribute__((packed)) nuccCriTextureBuffer {
    uint8_t data[0x68];
} nuccCriTextureBuffer;
static_assert(sizeof(nuccCriTextureBuffer) == 0x68, "nuccCriTextureBuffer size");

/* Nucc::Vector2: two floats. */
typedef struct __attribute__((packed)) Nucc_Vector2 {
    float x;                    /* +0x00 */
    float y;                    /* +0x04 */
} Nucc_Vector2;
static_assert(sizeof(Nucc_Vector2) == 0x08, "Nucc::Vector2 size");

/* =========================================================================
 * nuccCriFsStdio
 * Static/utility class wrapping CRI filesystem stdio callbacks.
 * Size: 0x10. Proven by: ctor writes param_1[1]=0, *param_1=vtable.
 * Vtable RVA: 0x739310.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccCriFsStdio {
    uint64_t vtable;            /* +0x00  RVA 0x739310 */
    uint64_t field_08;          /* +0x08  initialized to 0 in ctor */
} nuccCriFsStdio;
static_assert(offsetof(nuccCriFsStdio, vtable)   == 0x00, "nuccCriFsStdio::vtable");
static_assert(offsetof(nuccCriFsStdio, field_08) == 0x08, "nuccCriFsStdio::field_08");
static_assert(sizeof(nuccCriFsStdio) == 0x10, "nuccCriFsStdio size");

/* =========================================================================
 * nuccCriSofdec2Manager
 * Singleton manager wrapping an embedded nuccCriSofdec2Work.
 * Inherits Nucc::Memory::BlockAllocator.
 * Size: 0x580. Proven by: CreateInstance calls LoadTh(0x580,...).
 * Vtable RVA: 0x73b2b8. Embedded nuccCriSofdec2Work at +0x18.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccCriSofdec2Manager {
    Nucc_Memory_BlockAllocator base;    /* +0x000 */
    uint8_t work[0x568];                /* +0x018  nuccCriSofdec2Work embedded */
} nuccCriSofdec2Manager;
static_assert(offsetof(nuccCriSofdec2Manager, base) == 0x000, "nuccCriSofdec2Manager::base");
static_assert(offsetof(nuccCriSofdec2Manager, work) == 0x018, "nuccCriSofdec2Manager::work");
static_assert(sizeof(nuccCriSofdec2Manager) == 0x580, "nuccCriSofdec2Manager size");

/* =========================================================================
 * nuccCriSofdec2Work
 * Core CRI Sofdec2 video playback work object.
 * Inherits Nucc::Memory::BlockAllocator.
 * Size: unknown, >= 0x568. Bounded by Manager embedding (0x580 - 0x18 = 0x568).
 * Last proven field ends at 0x568. No standalone allocation proof.
 * Vtable RVA: 0x73b3f8.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccCriSofdec2Work {
    /* --- Nucc::Memory::BlockAllocator base (+0x00..+0x17) --- */
    uint64_t vtable;                    /* +0x000  RVA 0x73b3f8 */
    uint64_t block_alloc_field_08;      /* +0x008 */
    uint64_t block_alloc_field_10;      /* +0x010 */

    /* --- Own fields --- */
    uint64_t lib_work_buf;              /* +0x018  param_1[3]: freed in Finalize */
    uint32_t lib_work_size;             /* +0x020  param_1[4]: criMana_CalculateLibWorkSize */
    uint32_t pad_024;                   /* +0x024 */
    uint64_t lib_work_ptr;              /* +0x028  param_1[5]: MallocCore'd buffer */
    uint64_t mana_player;               /* +0x030  param_1[6]: CriManaPlayer handle */
    uint32_t movie_info_ready;          /* +0x038  param_1[7]: set after GetMovieInfo */
    uint32_t pad_03c;                   /* +0x03C */

    /* +0x040..+0x357: unobserved region (movie info written here by
     * criManaPlayer_GetMovieInfo via element offset 0x3C = byte 0x1E0) */
    uint8_t gap_040[0x318];             /* +0x040 */

    /* --- YUV frame buffer pointers (Exec/DestroyYUVTextureBuffer) --- */
    uint64_t yuv_buf_y_ptr;             /* +0x358  param_1[0x6b] */
    uint64_t yuv_buf_y_size;            /* +0x360  param_1[0x6c] */
    uint64_t yuv_buf_u_ptr;             /* +0x368  param_1[0x6d] */
    uint64_t yuv_buf_u_size;            /* +0x370  param_1[0x6e] */
    uint64_t yuv_buf_v_ptr;             /* +0x378  param_1[0x6f] */
    uint64_t yuv_buf_v_size;            /* +0x380  param_1[0x70] */

    uint8_t pad_388[0x10];              /* +0x388  align to tex buffers */

    /* --- Texture buffers (4x nuccCriTextureBuffer, stride 0x68) --- */
    nuccCriTextureBuffer tex_buf_0;     /* +0x398  param_1+0x73 */
    nuccCriTextureBuffer tex_buf_1;     /* +0x400  param_1+0x80 */
    nuccCriTextureBuffer tex_buf_2;     /* +0x468  param_1+0x8d */
    nuccCriTextureBuffer tex_buf_3;     /* +0x4D0  param_1+0x9a */

    /* --- Presentation / playback state --- */
    Nucc_Vector2 uv_scale;              /* +0x538  param_1+0xa7: ctor sets (0,0) */
    float playback_rate;                /* +0x540  param_1+0xa8: default 1.0f */
    uint32_t pad_544;                   /* +0x544 */

    /* Subtitle state (Exec: GetSubtitleOnTime writes 4 ptrs here) */
    uint64_t subtitle_ptrs[4];          /* +0x548  byte offsets 0x544..0x563 per ctor zero-init */
    uint32_t subtitle_track;            /* +0x568  init 0xffffffff (-1 = none) */
    uint32_t pad_56c;                   /* +0x56C */
} nuccCriSofdec2Work;

static_assert(offsetof(nuccCriSofdec2Work, vtable)              == 0x000, "vtable");
static_assert(offsetof(nuccCriSofdec2Work, block_alloc_field_08)== 0x008, "block_alloc_field_08");
static_assert(offsetof(nuccCriSofdec2Work, block_alloc_field_10)== 0x010, "block_alloc_field_10");
static_assert(offsetof(nuccCriSofdec2Work, lib_work_buf)        == 0x018, "lib_work_buf");
static_assert(offsetof(nuccCriSofdec2Work, lib_work_size)       == 0x020, "lib_work_size");
static_assert(offsetof(nuccCriSofdec2Work, lib_work_ptr)        == 0x028, "lib_work_ptr");
static_assert(offsetof(nuccCriSofdec2Work, mana_player)         == 0x030, "mana_player");
static_assert(offsetof(nuccCriSofdec2Work, movie_info_ready)    == 0x038, "movie_info_ready");
static_assert(offsetof(nuccCriSofdec2Work, gap_040)             == 0x040, "gap_040");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_y_ptr)       == 0x358, "yuv_buf_y_ptr");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_y_size)      == 0x360, "yuv_buf_y_size");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_u_ptr)       == 0x368, "yuv_buf_u_ptr");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_u_size)      == 0x370, "yuv_buf_u_size");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_v_ptr)       == 0x378, "yuv_buf_v_ptr");
static_assert(offsetof(nuccCriSofdec2Work, yuv_buf_v_size)      == 0x380, "yuv_buf_v_size");
static_assert(offsetof(nuccCriSofdec2Work, tex_buf_0)           == 0x398, "tex_buf_0");
static_assert(offsetof(nuccCriSofdec2Work, tex_buf_1)           == 0x400, "tex_buf_1");
static_assert(offsetof(nuccCriSofdec2Work, tex_buf_2)           == 0x468, "tex_buf_2");
static_assert(offsetof(nuccCriSofdec2Work, tex_buf_3)           == 0x4D0, "tex_buf_3");
static_assert(offsetof(nuccCriSofdec2Work, uv_scale)            == 0x538, "uv_scale");
static_assert(offsetof(nuccCriSofdec2Work, playback_rate)       == 0x540, "playback_rate");
static_assert(offsetof(nuccCriSofdec2Work, subtitle_ptrs)       == 0x548, "subtitle_ptrs");
static_assert(offsetof(nuccCriSofdec2Work, subtitle_track)      == 0x568, "subtitle_track");
/* No sizeof assert: standalone size unproven. Bounded <= 0x568 by Manager. */