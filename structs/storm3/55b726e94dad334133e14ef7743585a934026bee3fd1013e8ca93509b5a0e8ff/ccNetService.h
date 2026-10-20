/* ccNetService structs for NARUTO STORM 3 PC (s3, NSUNS3.exe)
 * Reconstructed from Ghidra decompilation of build s3 (sha 55b726e94dad).
 * All offsets are x64 PC offsets (image base 0x140000000).
 * All field names are own-game (ns3:: / Storm 3 strings/code only).
 * Static results are INFERRED, not CONFIRMED.
 */
#ifndef CC_NET_SERVICE_S3_H
#define CC_NET_SERVICE_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccNetRankingManager
 * Evidence: GetLeaderBoardHandle (0x7881B0), IsError (0x4EA750)
 * Size: unknown (no allocator found); layout covers proven fields only.
 * Same layout as s2 — identical field accesses at +0x00, +0x08, +0x10.
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

/* =========================================================================
 * ccNetRankingReader
 * Evidence: IsAsyncComplete (0x783520), Impl dtor (0x76A280).
 * Reads impl at offset +0x08; impl has async status at +0x34, flag at +0x38.
 * Allocation size: unknown in s3 (s2 was 0x12f8; s3 ctor not yet found).
 * Vtable: unknown (not resolved in decompiled functions).
 * ========================================================================= */
typedef struct ccNetRankingReader {
    void    *vtable;              /* 0x00 */
    void    *impl;                /* 0x08  pointer to Impl, used in IsAsyncComplete */
    uint8_t  pad_10[0x12E8];      /* 0x10  placeholder to match s2 size until s3 allocator found */
} ccNetRankingReader;
static_assert(offsetof(ccNetRankingReader, vtable) == 0x00, "ccNetRankingReader.vtable");
static_assert(offsetof(ccNetRankingReader, impl) == 0x08, "ccNetRankingReader.impl");
/* size >= 0x10 confirmed; exact size pending s3 allocator discovery */

/* =========================================================================
 * ccNetRankingReader::Impl
 * Evidence: dtor (0x76A280), IsAsyncComplete (0x519650).
 * Vtable: PTR_FUN_1409ede20 (set in dtor before cleanup).
 * Field at +0x08: returned by Impl::IsAsyncComplete (async handle/ptr).
 * Field at +0x20 (index 4): freed in dtor if non-null.
 * Fields at +0x34, +0x38: read by outer IsAsyncComplete via impl ptr.
 * ========================================================================= */
typedef struct ccNetRankingReader_Impl {
    void    *vtable;              /* 0x00  &PTR_FUN_1409ede20 */
    void    *async_handle;        /* 0x08  returned by IsAsyncComplete */
    uint8_t  pad_10[0x10];        /* 0x10 */
    void    *unk_20;              /* 0x20  index 4, freed in dtor if non-null */
    uint8_t  pad_28[0xC];         /* 0x28 */
    uint32_t async_status;        /* 0x34  read by outer IsAsyncComplete */
    uint32_t async_complete_flag; /* 0x38  if non-zero, forces IsAsyncComplete=1 */
} ccNetRankingReader_Impl;
static_assert(offsetof(ccNetRankingReader_Impl, vtable) == 0x00, "ccNetRankingReader_Impl.vtable");
static_assert(offsetof(ccNetRankingReader_Impl, async_handle) == 0x08, "ccNetRankingReader_Impl.async_handle");
static_assert(offsetof(ccNetRankingReader_Impl, unk_20) == 0x20, "ccNetRankingReader_Impl.unk_20");
static_assert(offsetof(ccNetRankingReader_Impl, async_status) == 0x34, "ccNetRankingReader_Impl.async_status");
static_assert(offsetof(ccNetRankingReader_Impl, async_complete_flag) == 0x38, "ccNetRankingReader_Impl.async_complete_flag");
/* size unknown, >= 0x3C */

/* =========================================================================
 * ccNetRankingReaderAdapter
 * Evidence: IsAsyncComplete (0x47EF78).
 * Dense inline buffer of ranking entries starting at +0x18.
 * Entry stride 0x30 (from puVar14 increment by 0xc uint32s = 0x30 bytes).
 * Count pointer at +0x17E0, output buffer pointer at +0x17D8.
 * Reader pointer at +0x10.
 * Total inline buffer: up to ~100 entries * 0x30 = 0x12C0, matching s2 layout.
 * ========================================================================= */
typedef struct ccNetRankingReaderAdapter {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[8];           /* 0x08 */
    ccNetRankingReader *reader;   /* 0x10  checked via IsAsyncComplete */
    uint8_t  inline_entries[0x17C0]; /* 0x18  dense ranking entry buffer, stride 0x30 */
    void    *output_buffer;       /* 0x17D8  destination for copied entries */
    int32_t *entry_count_ptr;     /* 0x17E0  pointer to count of valid entries */
    uint8_t  pad_17E8[8];         /* 0x17E8 */
} ccNetRankingReaderAdapter;
static_assert(offsetof(ccNetRankingReaderAdapter, reader) == 0x10, "ccNetRankingReaderAdapter.reader");
static_assert(offsetof(ccNetRankingReaderAdapter, inline_entries) == 0x18, "ccNetRankingReaderAdapter.inline_entries");
static_assert(offsetof(ccNetRankingReaderAdapter, output_buffer) == 0x17D8, "ccNetRankingReaderAdapter.output_buffer");
static_assert(offsetof(ccNetRankingReaderAdapter, entry_count_ptr) == 0x17E0, "ccNetRankingReaderAdapter.entry_count_ptr");
/* size >= 0x17F0 */

/* =========================================================================
 * ccNetRankingWriter::Impl
 * Evidence: Ctrl (0x783660), BeginWriteScore (0x783F20).
 * param_1 is longlong*; byte offsets computed as index*8 or explicit casts.
 * Steam callback registration at +0x78..+0x9F (0x28 bytes).
 * Score buffers allocated and memcpy'd in BeginWriteScore.
 *
 * Layout note: after total_scores at 0x70 (4 bytes), 4 bytes padding
 * brings steam_callback to 0x78. steam_callback is 0x28 bytes ending
 * at 0xA0 where callback_self sits.
 * ========================================================================= */
typedef struct ccNetRankingWriter_Impl {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[0x10];        /* 0x08 */
    uint32_t async_complete_flag; /* 0x18  set to 1 when write completes */
    uint8_t  pad_1C[4];           /* 0x1C */
    uint32_t state;               /* 0x20  switch dispatch (< 3) -- NOTE: adjusted from 0x24 */
    uint32_t score_id_base;       /* 0x24  from param_6[0] -- adjusted */
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
 * ccNetFriendList
 * Evidence: ReadRange (0x782B20), IsAsyncComplete (0x782B30).
 * Impl pointer at +0x08; IsAsyncComplete reads *(impl+4).
 * ReadRange delegates to FUN_140782cf0(*(param_1+8)).
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
 * Without a vtable, uint32_t at offset 4 requires packed layout
 * or a preceding 4-byte field. Using a leading uint32_t pad.
 */
typedef struct ccNetFriendList_Impl {
    uint32_t unk_00;              /* 0x00  unknown field or flags */
    uint32_t async_status;        /* 0x04  read by outer IsAsyncComplete as *(impl+4) */
} ccNetFriendList_Impl;
static_assert(offsetof(ccNetFriendList_Impl, async_status) == 0x04, "ccNetFriendList_Impl.async_status");
/* size unknown, >= 0x08 */

/* =========================================================================
 * ccNetFriendListAdapter
 * Evidence: ReadRange (0x47ED08), IsFriendListEntry (0x47ED00).
 * Friend list pointer dereferenced from *param_1 (offset 0x00 of adapter).
 * ReadRange copies entries with stride 0x24 from local buffer to output.
 * Entry layout: 8+8+8+8+4 = 0x24 bytes per friend entry.
 * ========================================================================= */
typedef struct ccNetFriendListAdapter {
    ccNetFriendList *friend_list; /* 0x00  pointer, dereferenced in ReadRange/IsFriendListEntry */
} ccNetFriendListAdapter;
static_assert(offsetof(ccNetFriendListAdapter, friend_list) == 0x00, "ccNetFriendListAdapter.friend_list");
/* size >= 0x08 */

/* =========================================================================
 * ccNetBlockList
 * Evidence: DeleteInstance (0x78C650).
 * Static singleton: operates on global DAT_140c7f180.
 * No instance fields found in s3 decompilations.
 * ========================================================================= */
/* ccNetBlockList: no instance state proven in s3.
 * All methods operate on the global singleton at DAT_140c7f180.
 * DeleteInstance (0x78C650) checks and clears the global pointer.
 * No constructor allocates per-instance memory. */

/* =========================================================================
 * ccNetItemParamManager
 * Evidence: ctor (0x3F8B00), Create (0x3F8C70), AddSaveData (0x3F8BCC),
 *           GetIndexNo (0x3F8D98), IsEffectApplying (0x3F9200).
 * Vtable: PTR_FUN_1409552f0 (set in ctor).
 * Inner data container at +0x08 (FUN_1403f8a98 initializes it).
 * IsEffectApplying checks *(param_1+0x30) != 0.
 * Create loads 'data/network/netItemParam.bin.xfbin'.
 * ========================================================================= */
typedef struct ccNetItemParamManager {
    void    *vtable;              /* 0x00  &PTR_FUN_1409552f0 */
    void    *item_data;           /* 0x08  inner container, initialized by FUN_1403f8a98 */
    uint8_t  pad_10[0x20];        /* 0x10 */
    void    *effect_state;        /* 0x30  checked non-null in IsEffectApplying */
} ccNetItemParamManager;
static_assert(offsetof(ccNetItemParamManager, vtable) == 0x00, "ccNetItemParamManager.vtable");
static_assert(offsetof(ccNetItemParamManager, item_data) == 0x08, "ccNetItemParamManager.item_data");
static_assert(offsetof(ccNetItemParamManager, effect_state) == 0x30, "ccNetItemParamManager.effect_state");
/* size >= 0x38 */

/* =========================================================================
 * ccNetLoginBonusParamManager
 * Evidence: Create (0x3F9518), CheckBonus (0x3F9414).
 * Array pointer at +0x08, count at +0x10.
 * Each entry is 0x18 bytes (allocated as count * 0x18).
 * Entry layout from Create copy loop: uint32[4] + uint64 = 0x18.
 * Source: 'data/network/NetLoginBonusParam.bin.xfbin'.
 * ========================================================================= */
typedef struct ccNetLoginBonusParam_Entry {
    uint32_t field_0;             /* 0x00  copied from xfbin */
    uint32_t field_4;             /* 0x04 */
    uint32_t field_8;             /* 0x08 */
    uint32_t field_C;             /* 0x0C */
    uint64_t field_10;            /* 0x10  copied as uint64 */
} ccNetLoginBonusParam_Entry;
static_assert(sizeof(ccNetLoginBonusParam_Entry) == 0x18, "ccNetLoginBonusParam_Entry size");

typedef struct ccNetLoginBonusParamManager {
    void    *vtable;              /* 0x00 */
    ccNetLoginBonusParam_Entry *entries; /* 0x08  allocated array */
    uint32_t entry_count;         /* 0x10  number of entries */
    uint8_t  pad_14[4];           /* 0x14 */
} ccNetLoginBonusParamManager;
static_assert(offsetof(ccNetLoginBonusParamManager, entries) == 0x08, "ccNetLoginBonusParamManager.entries");
static_assert(offsetof(ccNetLoginBonusParamManager, entry_count) == 0x10, "ccNetLoginBonusParamManager.entry_count");
/* size >= 0x18 */

/* =========================================================================
 * ccNetOnlineStorage
 * Evidence: ctor (0x4839BC).
 * Vtable: PTR_FUN_14096cbc8 (set in ctor).
 * Wrapper pointer at +0x18 (index 3), allocated via FUN_140683f70(0xc0,...).
 * Status field at +0x20 (index 4, set to 0 in ctor).
 * Allocation size for wrapper: 0xc0.
 * ========================================================================= */
typedef struct ccNetOnlineStorage {
    void    *vtable;              /* 0x00  &PTR_FUN_14096cbc8 */
    uint8_t  pad_08[0x10];        /* 0x08 */
    void    *wrapper;             /* 0x18  allocated (0xc0 bytes), from FUN_14078b8c0 */
    uint32_t status;              /* 0x20  set to 0 in ctor */
    uint8_t  pad_24[4];           /* 0x24 */
} ccNetOnlineStorage;
static_assert(offsetof(ccNetOnlineStorage, vtable) == 0x00, "ccNetOnlineStorage.vtable");
static_assert(offsetof(ccNetOnlineStorage, wrapper) == 0x18, "ccNetOnlineStorage.wrapper");
static_assert(offsetof(ccNetOnlineStorage, status) == 0x20, "ccNetOnlineStorage.status");
/* size >= 0x28 */

/* =========================================================================
 * ccNetRankParamManager
 * Evidence: ctor (0x3F9BB8), Create (0x3F9CD0), GetRankName (0x3F9E28),
 *           GetRewardId (0x3F9E84), IsHighestRank (0x3F9EA0), CalcRank (0x3F9CB4).
 * Vtable: PTR_FUN_140955470 (set in ctor).
 * Array pointer at +0x08, count at +0x10.
 * Each entry is 0x20 bytes (allocated as count << 5).
 * Entry layout: string hash at +0x00, name string ptr at +0x08, reward_id at +0x10.
 * Source: 'data/network/netRankParam.bin.xfbin'.
 * ========================================================================= */
typedef struct ccNetRankParam_Entry {
    uint32_t rank_hash;           /* 0x00  copied from xfbin first uint32 */
    uint32_t pad_04;              /* 0x04 */
    void    *name_string;         /* 0x08  string pointer, resolved via FUN_14075d8d0 */
    uint32_t reward_id;           /* 0x10  returned by GetRewardId */
    uint8_t  pad_14[0xC];         /* 0x14 */
} ccNetRankParam_Entry;
static_assert(sizeof(ccNetRankParam_Entry) == 0x20, "ccNetRankParam_Entry size");

typedef struct ccNetRankParamManager {
    void    *vtable;              /* 0x00  &PTR_FUN_140955470 */
    ccNetRankParam_Entry *entries; /* 0x08  allocated array */
    uint32_t entry_count;         /* 0x10  number of entries */
    uint8_t  pad_14[4];           /* 0x14 */
} ccNetRankParamManager;
static_assert(offsetof(ccNetRankParamManager, entries) == 0x08, "ccNetRankParamManager.entries");
static_assert(offsetof(ccNetRankParamManager, entry_count) == 0x10, "ccNetRankParamManager.entry_count");
/* size >= 0x18 */

/* =========================================================================
 * ccNetVoicechat
 * Evidence: ReceiveThread (0x7ABB10).
 * Thread handle/state at +0x68 (passed to FUN_14065ea10 as thread param).
 * Thread started flag at +0xA8 (set to 1 after successful start).
 * Thread stack size: 0x4000 (passed to create function).
 * Init function (0x7AA610) not yet decompiled; size unknown.
 * ========================================================================= */
typedef struct ccNetVoicechat {
    uint8_t  pad_00[0x68];        /* 0x00 */
    void    *thread_param;        /* 0x68  passed as arg to thread create */
    uint8_t  pad_70[0x38];        /* 0x70 */
    uint32_t thread_started;      /* 0xA8  set to 1 after thread creation */
    uint8_t  pad_AC[4];           /* 0xAC */
} ccNetVoicechat;
static_assert(offsetof(ccNetVoicechat, thread_param) == 0x68, "ccNetVoicechat.thread_param");
static_assert(offsetof(ccNetVoicechat, thread_started) == 0xA8, "ccNetVoicechat.thread_started");
/* size >= 0xB0; full layout pending init function decompilation */

#endif /* CC_NET_SERVICE_S3_H */