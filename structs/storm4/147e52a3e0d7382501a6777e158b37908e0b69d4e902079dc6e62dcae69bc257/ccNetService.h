/* ccNetService structs for NARUTO STORM 4 PC (s4, NSUNS4_release.exe)
 * Reconstructed from Ghidra decompilation of build s4 (sha 75912b).
 * All offsets are x64 PC offsets (image base 0x140000000).
 * All field names are own-game (Storm 4 symbols/strings only).
 * Static results are INFERRED, not CONFIRMED.
 */
#ifndef CC_NET_SERVICE_S4_H
#define CC_NET_SERVICE_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccNetOnlineStorage
 * Evidence: ctor (0x6ED270)
 * Vtable: set by base class (ccDownloadContentsManager called first)
 * Inner wrapper allocated at +0x88, size 0xc0.
 * Fields at +0x78/+0x7c set from param_2; +0x1b4 from global DAT_14163ead2.
 * Size >= 0x1B8.
 * ========================================================================= */
typedef struct ccNetOnlineStorage {
    uint8_t  pad_00[0x78];        /* 0x00  base class / vtable region */
    uint32_t field_78;            /* 0x78  set from ctor param_2 */
    uint32_t field_7c;            /* 0x7C  set from ctor param_2 */
    uint8_t  pad_80[8];           /* 0x80 */
    void    *wrapper;             /* 0x88  allocated (0xc0 bytes), FUN_140ae4230 */
    uint8_t  pad_90[0x124];       /* 0x90 */
    uint32_t global_flag;         /* 0x1B4  from DAT_14163ead2 */
} ccNetOnlineStorage;
static_assert(offsetof(ccNetOnlineStorage, field_78) == 0x78, "ccNetOnlineStorage.field_78");
static_assert(offsetof(ccNetOnlineStorage, field_7c) == 0x7C, "ccNetOnlineStorage.field_7c");
static_assert(offsetof(ccNetOnlineStorage, wrapper) == 0x88, "ccNetOnlineStorage.wrapper");
static_assert(offsetof(ccNetOnlineStorage, global_flag) == 0x1B4, "ccNetOnlineStorage.global_flag");
/* size >= 0x1B8 */

/* =========================================================================
 * ccNetFriendList
 * Evidence: IsAsyncComplete (0xAEB490), ReadRange (0xAEB480)
 * Impl pointer at +0x08; IsAsyncComplete reads *(impl+4).
 * ReadRange delegates to FUN_140aeb650(*(param_1+8)).
 * ========================================================================= */
typedef struct ccNetFriendList {
    void    *vtable;              /* 0x00 */
    void    *impl;                /* 0x08  pointer to impl */
} ccNetFriendList;
static_assert(offsetof(ccNetFriendList, vtable) == 0x00, "ccNetFriendList.vtable");
static_assert(offsetof(ccNetFriendList, impl) == 0x08, "ccNetFriendList.impl");
/* size >= 0x10 */

/* ccNetFriendList::Impl (inner)
 * Evidence: IsAsyncComplete reads *(impl+4) as undefined4.
 * No vtable evidence found for Impl; the "+4" access implies
 * async_status is at byte offset 4 from the impl pointer.
 */
typedef struct ccNetFriendList_Impl {
    uint32_t unk_00;              /* 0x00  unknown field or flags */
    uint32_t async_status;        /* 0x04  read by outer IsAsyncComplete as *(impl+4) */
} ccNetFriendList_Impl;
static_assert(offsetof(ccNetFriendList_Impl, async_status) == 0x04, "ccNetFriendList_Impl.async_status");
/* size unknown, >= 0x08 */

/* =========================================================================
 * ccNetRankingManager
 * Evidence: GetLeaderBoardHandle (0xAE4DB0), IsError (0x7571BC)
 * Size: unknown (no allocator found); layout covers proven fields only.
 * Same field pattern as s3 at +0x00, +0x08, +0x10.
 * ========================================================================= */
typedef struct ccNetRankingManager {
    int32_t  error_code;          /* 0x00  IsError returns -1 < *param_1 */
    uint8_t  pad_04[4];           /* 0x04 */
    void    *leaderboard_array;   /* 0x08  pointer to array of handles */
    uint32_t leaderboard_count;   /* 0x10  count checked in GetLeaderBoardHandle */
    uint8_t  pad_14[4];           /* 0x14 */
} ccNetRankingManager;
static_assert(offsetof(ccNetRankingManager, error_code) == 0x00, "ccNetRankingManager.error_code");
static_assert(offsetof(ccNetRankingManager, leaderboard_array) == 0x08, "ccNetRankingManager.leaderboard_array");
static_assert(offsetof(ccNetRankingManager, leaderboard_count) == 0x10, "ccNetRankingManager.leaderboard_count");
/* size >= 0x18 */

/* =========================================================================
 * ccNetRankingReader
 * Evidence: ctor (0x691DA0), IsAsyncComplete (0xAE4F70)
 * Vtable: PTR_FUN_14107d180 (set in ctor after base init).
 * Impl pointer at +0x08; IsAsyncComplete reads impl+0x34 and impl+0x38.
 * Ctor zeroes indices 9, 10, 0xd, 0xe (offsets 0x48, 0x50, 0x68, 0x70).
 * Size >= 0x78 (index 0xe = offset 0x70, 8-byte slot).
 * ========================================================================= */
typedef struct ccNetRankingReader {
    void    *vtable;              /* 0x00  &PTR_FUN_14107d180 */
    void    *impl;                /* 0x08  pointer to Impl */
    uint8_t  pad_10[0x38];        /* 0x10 */
    uint64_t field_48;            /* 0x48  zeroed in ctor (index 9) */
    uint64_t field_50;            /* 0x50  zeroed in ctor (index 10) */
    uint8_t  pad_58[0x10];        /* 0x58 */
    uint64_t field_68;            /* 0x68  zeroed in ctor (index 0xd) */
    uint64_t field_70;            /* 0x70  zeroed in ctor (index 0xe) */
} ccNetRankingReader;
static_assert(offsetof(ccNetRankingReader, vtable) == 0x00, "ccNetRankingReader.vtable");
static_assert(offsetof(ccNetRankingReader, impl) == 0x08, "ccNetRankingReader.impl");
static_assert(offsetof(ccNetRankingReader, field_48) == 0x48, "ccNetRankingReader.field_48");
static_assert(offsetof(ccNetRankingReader, field_50) == 0x50, "ccNetRankingReader.field_50");
static_assert(offsetof(ccNetRankingReader, field_68) == 0x68, "ccNetRankingReader.field_68");
static_assert(offsetof(ccNetRankingReader, field_70) == 0x70, "ccNetRankingReader.field_70");
/* size >= 0x78 */

/* =========================================================================
 * ccNetRankingReader::Impl (variant A — ccUiNetBattleBase derived)
 * Evidence: dtor (0x2F9620), IsAsyncComplete (0x78508C)
 * Vtable: PTR_FUN_140f6d588 (set in dtor before ccUiNetBattleBase cleanup).
 * Field at +0x18: async handle pointer (returned by IsAsyncComplete if non-null).
 * param_1[9] checked in dtor => offset 0x48.
 * ========================================================================= */
typedef struct ccNetRankingReader_Impl_A {
    void    *vtable;              /* 0x00  &PTR_FUN_140f6d588 */
    uint8_t  pad_08[0x10];        /* 0x08 */
    void    *async_handle;        /* 0x18  returned by IsAsyncComplete */
    uint8_t  pad_20[0x28];        /* 0x20 */
    uint64_t field_48;            /* 0x48  index 9, checked in dtor */
} ccNetRankingReader_Impl_A;
static_assert(offsetof(ccNetRankingReader_Impl_A, vtable) == 0x00, "ccNetRankingReader_Impl_A.vtable");
static_assert(offsetof(ccNetRankingReader_Impl_A, async_handle) == 0x18, "ccNetRankingReader_Impl_A.async_handle");
static_assert(offsetof(ccNetRankingReader_Impl_A, field_48) == 0x48, "ccNetRankingReader_Impl_A.field_48");
/* size >= 0x50 */

/* =========================================================================
 * ccNetRankingReader::Impl (variant B — ccUiLayoutParts derived)
 * Evidence: dtor (0xB037F0)
 * Vtable: PTR_FUN_141118ad8 (set in dtor before ccUiLayoutParts::ReleaseObject).
 * Field at index 4 (+0x20): freed via FreeCore() if non-null, then zeroed.
 * ========================================================================= */
typedef struct ccNetRankingReader_Impl_B {
    void    *vtable;              /* 0x00  &PTR_FUN_141118ad8 */
    uint8_t  pad_08[0x18];        /* 0x08 */
    void    *layout_parts;        /* 0x20  index 4, freed in dtor if non-null */
} ccNetRankingReader_Impl_B;
static_assert(offsetof(ccNetRankingReader_Impl_B, vtable) == 0x00, "ccNetRankingReader_Impl_B.vtable");
static_assert(offsetof(ccNetRankingReader_Impl_B, layout_parts) == 0x20, "ccNetRankingReader_Impl_B.layout_parts");
/* size >= 0x28 */

/* =========================================================================
 * ccNetRankingReaderAdapter
 * Evidence: ctor (0x476538)
 * Allocates inner ccNetRankingReader (size 0x78) stored at +0x40.
 * Ctor receives param_2 forwarded to reader construction.
 * Size >= 0x48.
 * ========================================================================= */
typedef struct ccNetRankingReaderAdapter {
    uint8_t  pad_00[0x40];        /* 0x00 */
    ccNetRankingReader *reader;   /* 0x40  allocated ccNetRankingReader, size 0x78 */
} ccNetRankingReaderAdapter;
static_assert(offsetof(ccNetRankingReaderAdapter, reader) == 0x40, "ccNetRankingReaderAdapter.reader");
/* size >= 0x48 */

/* =========================================================================
 * ccNetRankingWriter::Impl
 * Evidence: Ctrl (0xAE50B0), BeginWriteScore (0xAE5970)
 * param_1 is longlong*; byte offsets computed as index*8 or explicit casts.
 * Steam callback registration at +0x78..+0x9F (0x28 bytes).
 * Score buffers allocated and memcpy'd in BeginWriteScore.
 * ========================================================================= */
typedef struct ccNetRankingWriter_Impl {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[0x10];        /* 0x08 */
    uint32_t async_complete_flag; /* 0x18  set to 1 when write completes */
    uint8_t  pad_1C[4];           /* 0x1C */
    uint32_t state;               /* 0x20  switch dispatch (< 3) */
    uint32_t score_id_base;       /* 0x24  from param_6[0] */
    uint32_t score_id_0;          /* 0x28  from param_6[1] */
    uint32_t score_id_1;          /* 0x2C  from param_6[2] */
    uint32_t score_id_2;          /* 0x30  from param_6[3] */
    uint32_t score_id_3;          /* 0x34  from param_6[4] */
    uint32_t score_id_4;          /* 0x38  from param_6[5] */
    uint32_t score_id_5;          /* 0x3C  from param_6[6] */
    uint32_t score_id_6;          /* 0x40  from param_6[7] */
    uint32_t score_id_7;          /* 0x44  from param_6[8] */
    uint8_t  pad_48[8];           /* 0x48 */
    void    *score_buffer_1;      /* 0x50  allocated, memcpy target (index 10) */
    uint32_t score_count_1;       /* 0x58  param_3 (index 0xb) */
    uint8_t  pad_5C[4];           /* 0x5C */
    void    *score_buffer_2;      /* 0x60  allocated, memcpy target (index 0xc) */
    uint32_t score_count_2;       /* 0x68  param_5 (index 0xd) */
    uint32_t current_index;       /* 0x6C  incremented in Ctrl case 1 */
    uint32_t total_scores;        /* 0x70  compared against current_index */
    uint8_t  pad_74[4];           /* 0x74  alignment padding before steam_callback */
    uint8_t  steam_callback[0x28]; /* 0x78  SteamAPI callback struct (RegisterCallResult) */
    void    *callback_self;       /* 0xA0  set to self in Ctrl */
    void    *callback_fn;         /* 0xA8  set to FUN_140784380 in Ctrl */
} ccNetRankingWriter_Impl;
static_assert(offsetof(ccNetRankingWriter_Impl, vtable) == 0x00, "ccNetRankingWriter_Impl.vtable");
static_assert(offsetof(ccNetRankingWriter_Impl, async_complete_flag) == 0x18, "ccNetRankingWriter_Impl.async_complete_flag");
static_assert(offsetof(ccNetRankingWriter_Impl, state) == 0x20, "ccNetRankingWriter_Impl.state");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_base) == 0x24, "ccNetRankingWriter_Impl.score_id_base");
static_assert(offsetof(ccNetRankingWriter_Impl, score_buffer_1) == 0x50, "ccNetRankingWriter_Impl.score_buffer_1");
static_assert(offsetof(ccNetRankingWriter_Impl, score_count_1) == 0x58, "ccNetRankingWriter_Impl.score_count_1");
static_assert(offsetof(ccNetRankingWriter_Impl, score_buffer_2) == 0x60, "ccNetRankingWriter_Impl.score_buffer_2");
static_assert(offsetof(ccNetRankingWriter_Impl, score_count_2) == 0x68, "ccNetRankingWriter_Impl.score_count_2");
static_assert(offsetof(ccNetRankingWriter_Impl, current_index) == 0x6C, "ccNetRankingWriter_Impl.current_index");
static_assert(offsetof(ccNetRankingWriter_Impl, total_scores) == 0x70, "ccNetRankingWriter_Impl.total_scores");
static_assert(offsetof(ccNetRankingWriter_Impl, steam_callback) == 0x78, "ccNetRankingWriter_Impl.steam_callback");
static_assert(offsetof(ccNetRankingWriter_Impl, callback_self) == 0xA0, "ccNetRankingWriter_Impl.callback_self");
static_assert(offsetof(ccNetRankingWriter_Impl, callback_fn) == 0xA8, "ccNetRankingWriter_Impl.callback_fn");
/* size >= 0xB0 */

/* =========================================================================
 * ccNetRankParamManager
 * Evidence: ctor (0x568E24), Create (0x56926C), IsHighestRank (0x56968C)
 * Vtable: PTR_FUN_14101c980 (inherits Nucc::Memory::BlockAllocator).
 * Three parallel arrays loaded from 'data/network/netRankParam.bin.xfbin':
 *   rank_table at +0x18/+0x20 (0x28-byte entries)
 *   rank_point at +0x28/+0x30 (0xc-byte entries)
 *   rank_point_offset at +0x38/+0x40 (0xc-byte entries)
 * Size >= 0x48.
 * ========================================================================= */
typedef struct ccNetRankParamManager {
    void    *vtable;              /* 0x00  &PTR_FUN_14101c980 */
    uint8_t  pad_08[0x10];        /* 0x08  BlockAllocator base */
    void    *rank_table;          /* 0x18  array of 0x28-byte entries */
    uint32_t rank_table_count;    /* 0x20 */
    uint8_t  pad_24[4];           /* 0x24 */
    void    *rank_point;          /* 0x28  array of 0xc-byte entries */
    uint32_t rank_point_count;    /* 0x30 */
    uint8_t  pad_34[4];           /* 0x34 */
    void    *rank_point_offset;   /* 0x38  array of 0xc-byte entries */
    uint32_t rank_point_offset_count; /* 0x40 */
    uint8_t  pad_44[4];           /* 0x44 */
} ccNetRankParamManager;
static_assert(offsetof(ccNetRankParamManager, vtable) == 0x00, "ccNetRankParamManager.vtable");
static_assert(offsetof(ccNetRankParamManager, rank_table) == 0x18, "ccNetRankParamManager.rank_table");
static_assert(offsetof(ccNetRankParamManager, rank_table_count) == 0x20, "ccNetRankParamManager.rank_table_count");
static_assert(offsetof(ccNetRankParamManager, rank_point) == 0x28, "ccNetRankParamManager.rank_point");
static_assert(offsetof(ccNetRankParamManager, rank_point_count) == 0x30, "ccNetRankParamManager.rank_point_count");
static_assert(offsetof(ccNetRankParamManager, rank_point_offset) == 0x38, "ccNetRankParamManager.rank_point_offset");
static_assert(offsetof(ccNetRankParamManager, rank_point_offset_count) == 0x40, "ccNetRankParamManager.rank_point_offset_count");
/* size >= 0x48 */

/* =========================================================================
 * ccNetRankParam
 * Evidence: CalcBp (0x568F78)
 * Operated on by CalcBp which reads three parallel arrays and writes
 * a calculated BP value (ushort) at +0x44.
 * Arrays: rank_entries (0x28 stride) at +0x18/+0x20,
 *         bp_thresholds (0xc stride) at +0x28/+0x30,
 *         character_bp (0xc stride) at +0x38/+0x40.
 * Size >= 0x48.
 * ========================================================================= */
typedef struct ccNetRankParam {
    uint8_t  pad_00[0x18];        /* 0x00 */
    void    *rank_entries;        /* 0x18  array of 0x28-byte entries */
    uint32_t rank_entry_count;    /* 0x20 */
    uint8_t  pad_24[4];           /* 0x24 */
    void    *bp_thresholds;       /* 0x28  array of 0xc-byte entries */
    uint32_t bp_threshold_count;  /* 0x30 */
    uint8_t  pad_34[4];           /* 0x34 */
    void    *character_bp;        /* 0x38  array of 0xc-byte entries */
    uint32_t character_bp_count;  /* 0x40 */
    uint16_t calculated_bp;       /* 0x44  written by CalcBp */
    uint8_t  pad_46[2];           /* 0x46 */
} ccNetRankParam;
static_assert(offsetof(ccNetRankParam, rank_entries) == 0x18, "ccNetRankParam.rank_entries");
static_assert(offsetof(ccNetRankParam, rank_entry_count) == 0x20, "ccNetRankParam.rank_entry_count");
static_assert(offsetof(ccNetRankParam, bp_thresholds) == 0x28, "ccNetRankParam.bp_thresholds");
static_assert(offsetof(ccNetRankParam, bp_threshold_count) == 0x30, "ccNetRankParam.bp_threshold_count");
static_assert(offsetof(ccNetRankParam, character_bp) == 0x38, "ccNetRankParam.character_bp");
static_assert(offsetof(ccNetRankParam, character_bp_count) == 0x40, "ccNetRankParam.character_bp_count");
static_assert(offsetof(ccNetRankParam, calculated_bp) == 0x44, "ccNetRankParam.calculated_bp");
/* size >= 0x48 */

/* =========================================================================
 * ccNetVoicechat
 * Evidence: ReceiveThread (0xB277A0)
 * Thread param at +0x68 passed to thread create function.
 * Thread started flag at +0xA8 set to 1 after successful start.
 * Init flag at +0xAC initialized to 0 in ReceiveThread prologue.
 * Size >= 0xB0.
 * ========================================================================= */
typedef struct ccNetVoicechat {
    uint8_t  pad_00[0x68];        /* 0x00 */
    void    *thread_param;        /* 0x68  passed as arg to thread create */
    uint8_t  pad_70[0x38];        /* 0x70 */
    uint32_t thread_started;      /* 0xA8  set to 1 after thread creation */
    uint32_t init_flag;           /* 0xAC  initialized to 0 */
} ccNetVoicechat;
static_assert(offsetof(ccNetVoicechat, thread_param) == 0x68, "ccNetVoicechat.thread_param");
static_assert(offsetof(ccNetVoicechat, thread_started) == 0xA8, "ccNetVoicechat.thread_started");
static_assert(offsetof(ccNetVoicechat, init_flag) == 0xAC, "ccNetVoicechat.init_flag");
/* size >= 0xB0 */

#endif /* CC_NET_SERVICE_S4_H */