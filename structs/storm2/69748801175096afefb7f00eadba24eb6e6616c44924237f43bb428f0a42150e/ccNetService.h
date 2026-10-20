/* ccNetService structs for NARUTO STORM 2 PC (s2, NSUNS2.exe)
 * Reconstructed from Ghidra decompilation of build s2 (sha 697488011750).
 * All offsets are x64 PC offsets (image base 0x140000000).
 * All field names are own-game (ns2:: / Storm 2 strings/code only).
 * Static results are INFERRED, not CONFIRMED.
 */
#ifndef CC_NET_SERVICE_S2_H
#define CC_NET_SERVICE_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccNetRankingManager
 * Evidence: GetLeaderBoardHandle (0x36E640), IsError (0x3177C4)
 * Size: unknown (no allocator found); layout covers proven fields only.
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
 * ccNetRankingManagerAdapter
 * Evidence: Initialize (0x66F8F0) — empty body, static singleton.
 * No instance fields found in s2.
 * ========================================================================= */
typedef struct ccNetRankingManagerAdapter {
    uint8_t placeholder;          /* no instance fields proven in s2 */
} ccNetRankingManagerAdapter;

/* =========================================================================
 * ccNetRankingReader
 * Evidence: ctor (0x3658DC), called from ccNetRankingReaderAdapter ctor.
 * Allocation size: 0x12f8 (from FUN_140580190(0x12f8,...) in adapter ctor 0x4FAB28).
 * Vtable: PTR_FUN_1408004c0
 * ========================================================================= */
typedef struct ccNetRankingReader {
    void    *vtable;              /* 0x00  &PTR_FUN_1408004c0 */
    uint8_t  pad_08[16];          /* 0x08 */
    void    *impl;                /* 0x18  Impl pointer (param_1[3]) */
    uint32_t unk_20;              /* 0x20  set to 0 in ctor */
    uint8_t  data[0x12D4];        /* 0x24  memset covers 0x12c0; remaining 0x14 pad to allocator size 0x12f8 */
} ccNetRankingReader;
static_assert(sizeof(ccNetRankingReader) == 0x12F8, "ccNetRankingReader size from allocator");
static_assert(offsetof(ccNetRankingReader, vtable) == 0x00, "ccNetRankingReader.vtable");
static_assert(offsetof(ccNetRankingReader, impl) == 0x18, "ccNetRankingReader.impl");
static_assert(offsetof(ccNetRankingReader, unk_20) == 0x20, "ccNetRankingReader.unk_20");
static_assert(offsetof(ccNetRankingReader, data) == 0x24, "ccNetRankingReader.data");

/* =========================================================================
 * ccNetRankingReader::Impl
 * Evidence: dtor (0x29AE10).
 * Vtable: PTR_FUN_1407dc190
 * Size: unknown; last proven field at 0x148 (pointer).
 * ========================================================================= */
typedef struct ccNetRankingReader_Impl {
    void    *vtable;              /* 0x00  &PTR_FUN_1407dc190 */
    uint8_t  pad_08[0x140];       /* 0x08 */
    void    *unk_148;             /* 0x148  freed in dtor if non-null */
} ccNetRankingReader_Impl;
static_assert(offsetof(ccNetRankingReader_Impl, vtable) == 0x00, "ccNetRankingReader_Impl.vtable");
static_assert(offsetof(ccNetRankingReader_Impl, unk_148) == 0x148, "ccNetRankingReader_Impl.unk_148");
/* size unknown, >= 0x150 */

/* =========================================================================
 * ccNetRankingReaderAdapter
 * Evidence: ctor (0x4FAB28).
 * Inherits from a base class (virtual calls at vtable+8 and vtable+0x10).
 * Fields derived from ctor pseudocode.
 * ========================================================================= */
typedef struct ccNetRankingReaderAdapter {
    void    *vtable;              /* 0x00  inherited base vtable */
    uint8_t  pad_08[0x78];        /* 0x08 */
    ccNetRankingReader *reader;   /* 0x80  param_1[0x10], allocated in ctor */
    uint8_t  pad_88[0x9C];        /* 0x88 */
    uint32_t read_range_type;     /* 0x124  param_1[0x14], selects ReadRange variant */
    uint8_t  pad_128[12];         /* 0x128 */
    uint32_t unk_134;             /* 0x134  set to 0 in ctor */
} ccNetRankingReaderAdapter;
static_assert(offsetof(ccNetRankingReaderAdapter, reader) == 0x80, "ccNetRankingReaderAdapter.reader");
static_assert(offsetof(ccNetRankingReaderAdapter, read_range_type) == 0x124, "ccNetRankingReaderAdapter.read_range_type");
static_assert(offsetof(ccNetRankingReaderAdapter, unk_134) == 0x134, "ccNetRankingReaderAdapter.unk_134");
/* size unknown, >= 0x138 */

/* =========================================================================
 * ccNetRankingWriter
 * Evidence: IsAsyncComplete (0x66E920).
 * Reads *(undefined4 *)(*param_1 + 0x18) — async status from base/impl.
 * Size: unknown; minimal layout from proven fields.
 * ========================================================================= */
typedef struct ccNetRankingWriter {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[16];          /* 0x08 */
    uint32_t async_status;        /* 0x18  read by IsAsyncComplete */
    uint8_t  pad_1C[4];           /* 0x1C */
} ccNetRankingWriter;
static_assert(offsetof(ccNetRankingWriter, vtable) == 0x00, "ccNetRankingWriter.vtable");
static_assert(offsetof(ccNetRankingWriter, async_status) == 0x18, "ccNetRankingWriter.async_status");
/* size unknown, >= 0x20 */

/* =========================================================================
 * ccNetRankingWriter::Impl
 * Evidence: BeginWriteScore (0x66F200).
 * Dense field layout from BeginWriteScore parameter storage.
 * param_1 is longlong*; byte offsets computed as index*8 or explicit casts.
 * Size: unknown; last proven field at 0x70.
 * ========================================================================= */
typedef struct ccNetRankingWriter_Impl {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[16];          /* 0x08 */
    uint32_t async_complete_flag; /* 0x18  read by IsAsyncComplete via parent ptr */
    uint8_t  pad_1C[8];           /* 0x1C */
    uint32_t state;               /* 0x24  switch dispatch (< 3) */
    uint32_t score_id_base;       /* 0x28  from param_6[0] */
    uint32_t score_id_0;          /* 0x2C  from param_6[1] */
    uint32_t score_id_1;          /* 0x30  from param_6[2] */
    uint32_t score_id_2;          /* 0x34  from param_6[3] */
    uint32_t score_id_3;          /* 0x38  from param_6[4] */
    uint32_t score_id_4;          /* 0x3C  from param_6[5] */
    uint32_t score_id_5;          /* 0x40  from param_6[6] */
    uint32_t score_id_6;          /* 0x44  from param_6[7] */
    uint32_t score_id_7;          /* 0x48  from param_6[8] */
    uint8_t  pad_4C[4];           /* 0x4C */
    void    *score_buffer_1;      /* 0x50  allocated, memcpy target */
    uint32_t score_count_1;       /* 0x58  param_3 */
    uint8_t  pad_5C[4];           /* 0x5C */
    void    *score_buffer_2;      /* 0x60  allocated, memcpy target */
    uint32_t score_count_2;       /* 0x68  param_5 */
    uint8_t  pad_6C[4];           /* 0x6C */
    uint32_t unk_70;              /* 0x70  param_7 */
} ccNetRankingWriter_Impl;
static_assert(offsetof(ccNetRankingWriter_Impl, vtable) == 0x00, "ccNetRankingWriter_Impl.vtable");
static_assert(offsetof(ccNetRankingWriter_Impl, async_complete_flag) == 0x18, "ccNetRankingWriter_Impl.async_complete_flag");
static_assert(offsetof(ccNetRankingWriter_Impl, state) == 0x24, "ccNetRankingWriter_Impl.state");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_base) == 0x28, "ccNetRankingWriter_Impl.score_id_base");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_0) == 0x2C, "ccNetRankingWriter_Impl.score_id_0");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_1) == 0x30, "ccNetRankingWriter_Impl.score_id_1");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_2) == 0x34, "ccNetRankingWriter_Impl.score_id_2");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_3) == 0x38, "ccNetRankingWriter_Impl.score_id_3");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_4) == 0x3C, "ccNetRankingWriter_Impl.score_id_4");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_5) == 0x40, "ccNetRankingWriter_Impl.score_id_5");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_6) == 0x44, "ccNetRankingWriter_Impl.score_id_6");
static_assert(offsetof(ccNetRankingWriter_Impl, score_id_7) == 0x48, "ccNetRankingWriter_Impl.score_id_7");
static_assert(offsetof(ccNetRankingWriter_Impl, score_buffer_1) == 0x50, "ccNetRankingWriter_Impl.score_buffer_1");
static_assert(offsetof(ccNetRankingWriter_Impl, score_count_1) == 0x58, "ccNetRankingWriter_Impl.score_count_1");
static_assert(offsetof(ccNetRankingWriter_Impl, score_buffer_2) == 0x60, "ccNetRankingWriter_Impl.score_buffer_2");
static_assert(offsetof(ccNetRankingWriter_Impl, score_count_2) == 0x68, "ccNetRankingWriter_Impl.score_count_2");
static_assert(offsetof(ccNetRankingWriter_Impl, unk_70) == 0x70, "ccNetRankingWriter_Impl.unk_70");
/* size unknown, >= 0x74 */

/* =========================================================================
 * ccNetFriendList
 * Evidence: ReadRange (0x66C850) — delegates to impl at offset 0x08.
 * Size: unknown; minimal layout.
 * ========================================================================= */
typedef struct ccNetFriendList {
    void    *vtable;              /* 0x00 */
    void    *impl;                /* 0x08  pointer to impl, used in ReadRange */
} ccNetFriendList;
static_assert(offsetof(ccNetFriendList, vtable) == 0x00, "ccNetFriendList.vtable");
static_assert(offsetof(ccNetFriendList, impl) == 0x08, "ccNetFriendList.impl");
/* size unknown, >= 0x10 */

/* =========================================================================
 * ccNetFriendListAdapter
 * Evidence: ReadRange (0x364A7C).
 * Reads friend list pointer from offset 0x18.
 * Size: unknown; layout covers proven fields.
 * ========================================================================= */
typedef struct ccNetFriendListAdapter {
    void    *vtable;              /* 0x00 */
    uint8_t  pad_08[16];          /* 0x08 */
    ccNetFriendList *friend_list; /* 0x18  pointer, read in ReadRange */
} ccNetFriendListAdapter;
static_assert(offsetof(ccNetFriendListAdapter, vtable) == 0x00, "ccNetFriendListAdapter.vtable");
static_assert(offsetof(ccNetFriendListAdapter, friend_list) == 0x18, "ccNetFriendListAdapter.friend_list");
/* size unknown, >= 0x20 */

/* =========================================================================
 * ccNetBlockList
 * Evidence: DeleteInstance (0x6729A0) — static, operates on global DAT_140ab6560.
 * No instance fields found in s2; appears to be a singleton manager.
 * ========================================================================= */
typedef struct ccNetBlockList {
    uint8_t placeholder;          /* no instance fields proven in s2 */
} ccNetBlockList;

/* =========================================================================
 * ccNetVoicechat
 * Evidence: ReceiveThread (0x6A4F60), init function (0x6A3A60).
 * Fields from both functions combined.
 * Size: unknown; last proven access at 0x100 (buffer passed to Steam API).
 * ========================================================================= */
typedef struct ccNetVoicechat {
    uint8_t  pad_00[0x18];        /* 0x00 */
    uint8_t  voice_session[0x50]; /* 0x18  passed to FUN_1405ac110 */
    uint8_t  thread_arg[0x40];    /* 0x68  passed as thread arg to FUN_14055c130 */
    uint32_t thread_started;      /* 0xA8  flag checked/set in ReceiveThread */
    uint8_t  pad_AC[0x2C];        /* 0xAC */
    uint64_t steam_user_id;       /* 0xD8  from SteamUser()->GetSteamID() */
    uint8_t  pad_E0[0x20];        /* 0xE0 */
    uint8_t  steam_buffer[0x40];  /* 0x100  passed to Steam API call at vtable+0x50 */
} ccNetVoicechat;
static_assert(offsetof(ccNetVoicechat, voice_session) == 0x18, "ccNetVoicechat.voice_session");
static_assert(offsetof(ccNetVoicechat, thread_arg) == 0x68, "ccNetVoicechat.thread_arg");
static_assert(offsetof(ccNetVoicechat, thread_started) == 0xA8, "ccNetVoicechat.thread_started");
static_assert(offsetof(ccNetVoicechat, steam_user_id) == 0xD8, "ccNetVoicechat.steam_user_id");
static_assert(offsetof(ccNetVoicechat, steam_buffer) == 0x100, "ccNetVoicechat.steam_buffer");
/* size unknown, >= 0x140 */

/* =========================================================================
 * ccNetVoiceChatDeter
 * Evidence: getNetSession (0x10648) — static, reads global DAT_140a5c190.
 * No instance fields found in s2.
 * ========================================================================= */
typedef struct ccNetVoiceChatDeter {
    uint8_t placeholder;          /* no instance fields proven in s2 */
} ccNetVoiceChatDeter;

/* =========================================================================
 * ccNetOnlineStorage
 * Evidence: ctor (0x365214), factory (0x3652DC).
 * Allocation size: 0x38 (from FUN_140580190(0x38,...) in factory).
 * Vtable: PTR_FUN_140800380
 * ========================================================================= */
typedef struct ccNetOnlineStorage {
    void    *vtable;              /* 0x00  &PTR_FUN_140800380 */
    uint8_t  pad_08[0x20];        /* 0x08 */
    void    *impl;                /* 0x28  param_1[5], allocated in ctor */
    uint32_t unk_30;              /* 0x30  param_1+6, set to 0 in ctor */
    uint8_t  pad_34[4];           /* 0x34 */
} ccNetOnlineStorage;
static_assert(sizeof(ccNetOnlineStorage) == 0x38, "ccNetOnlineStorage size from allocator");
static_assert(offsetof(ccNetOnlineStorage, vtable) == 0x00, "ccNetOnlineStorage.vtable");
static_assert(offsetof(ccNetOnlineStorage, impl) == 0x28, "ccNetOnlineStorage.impl");
static_assert(offsetof(ccNetOnlineStorage, unk_30) == 0x30, "ccNetOnlineStorage.unk_30");

/* =========================================================================
 * Absent classes in s2 (listed in GROUP but no methods found):
 *   ccNetItemParamManager
 *   ccNetRankParamManager
 *   ccNetRankParam
 *   ccNetLoginBonusParamManager
 * These classes first appear in later builds (s3/s4).
 * ========================================================================= */

#endif /* CC_NET_SERVICE_S2_H */