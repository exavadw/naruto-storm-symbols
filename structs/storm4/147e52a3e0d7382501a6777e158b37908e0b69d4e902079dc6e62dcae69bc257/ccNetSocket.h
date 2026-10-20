/* Auto-generated ccNetSocket structs for NARUTO STORM 4 (s4 / NSUNS4_release.exe 64-bit)
 * Classes: ccNetUDPSocket, ccNetUDPSocket::Impl, ccNetTCPSocket, ccNetTCPSocket::Impl,
 *          ccNetDataSharingTCPSocketAdapter, ccNetFreeBattleSync
 * All INFERRED from static decompilation, not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */
#ifndef CCNETSOCKET_S4_H
#define CCNETSOCKET_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ========================================================================
 * ccNetUDPSocket::Impl - Steam P2P socket implementation
 * Size unknown (>= 0x20); accessed via pointer at ccNetUDPSocket+0x18
 * Fields inferred from ~Impl (0xAF25A0), Stop (0xAF2668)
 * ======================================================================== */
typedef struct ccNetUDPSocket_Impl {
    uint32_t channel;           /* +0x0000 Initialize writes through sock+0x18 */
    uint32_t steam_p2p_handle;  /* +0x0004 Stop/CloseP2P uses *(impl+4) */
    uint8_t  pad_0008[8];       /* +0x0008 */
    uint32_t connection_state;  /* +0x0010 checked in IsConnected paths */
    uint8_t  pad_0014[4];       /* +0x0014 */
    uint64_t peer_steam_id;     /* +0x0018 populated by GetP2PSessionState */
} ccNetUDPSocket_Impl;
static_assert(offsetof(ccNetUDPSocket_Impl, channel) == 0x00, "channel at +0x00");
static_assert(offsetof(ccNetUDPSocket_Impl, steam_p2p_handle) == 0x04, "steam_p2p_handle at +0x04");
static_assert(offsetof(ccNetUDPSocket_Impl, connection_state) == 0x10, "connection_state at +0x10");
static_assert(offsetof(ccNetUDPSocket_Impl, peer_steam_id) == 0x18, "peer_steam_id at +0x18");

/* ========================================================================
 * ccNetUDPSocket - UDP socket wrapper using Steam Networking P2P
 * Vtable dtor: set in ~ccNetUDPSocket (0xAF2300)
 * Size: unknown in s4; >= 0xB8 (s2 size used as lower bound)
 * Embedded in ccNetFreeBattleSync at +0xB0
 * Only fields proven by UDPSocket-specific methods are listed here.
 * DispatchPacket fields belong to ccNetFreeBattleSync, not this struct.
 * ======================================================================== */
typedef struct ccNetUDPSocket {
    void                *vtable;    /* +0x0000 dtor sets vtable */
    uint8_t              pad_0008[16]; /* +0x0008 */
    ccNetUDPSocket_Impl *impl;      /* +0x0018 Stop/Send deref; Initialize writes through */
    uint8_t              pad_0020[168]; /* +0x0020 fill to 0xC8 conservative */
} ccNetUDPSocket;
static_assert(offsetof(ccNetUDPSocket, impl) == 0x18, "impl must be at +0x18");
/* Size unknown in s4. No static_assert on sizeof. */

/* ========================================================================
 * ccNetFreeBattleSync - rollback sync container holding ccNetUDPSocket at +0xB0
 * Allocated at 600 (0x258) bytes from FUN_140a017f0 in ccSceneNetworkBattleBase (0x6F6E04)
 * Internal heap buffer of 0x7080 bytes allocated at +0xF0 via FUN_140a01b70
 * DispatchPacket is ccNetUDPSocket::DispatchPacket (0xAF4440), operates on this object
 * Fields from ctor (0xAF2820), CtrlFighting (0xAF2A60), SendDataToWatcherFromFighter (0xAF2ED0),
 * DispatchPacket (0xAF4440), state_surface analysis
 *
 * NOTE: Fields at +0xF0,+0xF8,+0xFC,+0x100 are proven by state_surface but their exact
 * position relative to udp_socket depends on sizeof(ccNetUDPSocket) which is unknown in s4.
 * They are documented in ccNetSocket-fields.tsv but omitted from the C struct body to avoid
 * false overlap assertions. See REPORT.md Known Gaps #3.
 *
 * Layout verified with #pragma pack(push,1): all fields packed without implicit alignment.
 * frame_counter_a is uint32_t (not uint64_t) because frame_counter_b is proven at +0x44,
 * only 4 bytes after frame_counter_a at +0x40. The state_surface "param_1[0x10]" notation
 * uses dword indexing, confirming 4-byte width.
 * ======================================================================== */
typedef struct ccNetFreeBattleSync {
    /* +0x0000 */ void    *vtable;            /* ctor sets *param_1 = 2 (index/type tag) */
    /* +0x0008 */ uint8_t  pad_0008[36];      /* gap to player_index at 0x2C */
    /* +0x002C */ int32_t  player_index;      /* param_1[0xb] ctor: param_2 */
    /* +0x0030 */ int32_t  alt_player_index;  /* param_1[0xc] ctor: conditional on param_2==-1 */
    /* +0x0034 */ uint8_t  config_bytes[8];   /* param_1[0xd..0xe], byte offsets 0x35-0x3b, ctor: from param_4 */
    /* +0x003C */ uint8_t  pad_003C[4];       /* gap to frame_counter_a at 0x40 */
    /* +0x0040 */ uint32_t frame_counter_a;   /* state_surface offset 0x40, param_1[0x10] rw high */
    /* +0x0044 */ uint32_t frame_counter_b;   /* state_surface offset 0x44, param_1[0x11] rw high */
    /* +0x0048 */ uint32_t unk_0048;          /* state_surface offset 0x48, param_1[0x12] r medium */
    /* +0x004C */ uint8_t  pad_004C[4];       /* gap to unk_0050 at 0x50 */
    /* +0x0050 */ uint32_t unk_0050;          /* state_surface offset 0x50, param_1[0x14] */
    /* +0x0054 */ uint8_t  pad_0054[12];      /* gap to sub_obj_0060 at 0x60 */
    /* +0x0060 */ void    *sub_obj_0060;      /* param_1+0x18, ctor: FUN_140aee3e0 initializes */
    /* +0x0068 */ uint32_t unk_0068;          /* state_surface offset 0x68, param_1[0x1a] rw high */
    /* +0x006C */ uint32_t sync_frame_delta;  /* state_surface offset 0x6C, param_1[0x1b] rw high */
    /* +0x0070 */ uint32_t frame_check_val;   /* state_surface offset 0x70, param_1[0x1c] r medium */
    /* +0x0074 */ uint32_t unk_0074;          /* state_surface offset 0x74, param_1[0x1d] w high */
    /* +0x0078 */ uint32_t unk_0078;          /* state_surface offset 0x78, param_1[0x1e] r medium */
    /* +0x007C */ uint32_t unk_007C;          /* state_surface offset 0x7C, param_1[0x1f] w medium */
    /* +0x0080 */ uint32_t unk_0080;          /* state_surface offset 0x80, param_1[0x20] r medium */
    /* +0x0084 */ uint32_t unk_0084;          /* state_surface offset 0x84, param_1[0x21] w medium */
    /* +0x0088 */ uint32_t unk_0088;          /* state_surface offset 0x88, param_1[0x22] w high */
    /* +0x008C */ uint8_t  pad_008C[4];       /* gap to sub_obj_ptr_0090 at 0x90 */
    /* +0x0090 */ uint64_t sub_obj_ptr_0090;  /* state_surface offset 0x90, param_1+0x24 r medium */
    /* +0x0098 */ uint8_t  pad_0098[8];       /* gap to queue_related_00A0 at 0xA0 */
    /* +0x00A0 */ uint64_t queue_related_00A0;/* state_surface offset 0xA0, param_1+0x28 */
    /* +0x00A8 */ uint64_t ptr_00A8;          /* ctor: set to 0xFFFFFFFFFFFFFFFF */
    /* +0x00B0 */ ccNetUDPSocket udp_socket;  /* param_1+0x2a -> offset 0xB0, Initialize calls Start */
    /* udp_socket occupies +0xB0..+0x177 (0xC8 bytes based on s2 lower bound; true s4 size unknown) */
    /* +0x0178 */ uint8_t  pad_after_udp[208];/* gap to scene_network_ptr at 0x248 (0x248-0x178=0xD0=208) */
    /* +0x0248 */ void    *scene_network_ptr; /* DAT_14160bb10+0x248, caller sets param_1+0x92 */
    /* +0x0250 */ void    *send_callback;     /* DAT_14160bb10+0x250, caller sets DAT_14160bb20 */
    /* Total alloc = 0x258 = 600 bytes */
} ccNetFreeBattleSync;
static_assert(offsetof(ccNetFreeBattleSync, player_index) == 0x2C, "player_index at +0x2C");
static_assert(offsetof(ccNetFreeBattleSync, alt_player_index) == 0x30, "alt_player_index at +0x30");
static_assert(offsetof(ccNetFreeBattleSync, config_bytes) == 0x34, "config_bytes at +0x34");
static_assert(offsetof(ccNetFreeBattleSync, frame_counter_a) == 0x40, "frame_counter_a at +0x40");
static_assert(offsetof(ccNetFreeBattleSync, frame_counter_b) == 0x44, "frame_counter_b at +0x44");
static_assert(offsetof(ccNetFreeBattleSync, unk_0048) == 0x48, "unk_0048 at +0x48");
static_assert(offsetof(ccNetFreeBattleSync, unk_0050) == 0x50, "unk_0050 at +0x50");
static_assert(offsetof(ccNetFreeBattleSync, sub_obj_0060) == 0x60, "sub_obj_0060 at +0x60");
static_assert(offsetof(ccNetFreeBattleSync, unk_0068) == 0x68, "unk_0068 at +0x68");
static_assert(offsetof(ccNetFreeBattleSync, sync_frame_delta) == 0x6C, "sync_frame_delta at +0x6C");
static_assert(offsetof(ccNetFreeBattleSync, frame_check_val) == 0x70, "frame_check_val at +0x70");
static_assert(offsetof(ccNetFreeBattleSync, unk_0074) == 0x74, "unk_0074 at +0x74");
static_assert(offsetof(ccNetFreeBattleSync, unk_0078) == 0x78, "unk_0078 at +0x78");
static_assert(offsetof(ccNetFreeBattleSync, unk_007C) == 0x7C, "unk_007C at +0x7C");
static_assert(offsetof(ccNetFreeBattleSync, unk_0080) == 0x80, "unk_0080 at +0x80");
static_assert(offsetof(ccNetFreeBattleSync, unk_0084) == 0x84, "unk_0084 at +0x84");
static_assert(offsetof(ccNetFreeBattleSync, unk_0088) == 0x88, "unk_0088 at +0x88");
static_assert(offsetof(ccNetFreeBattleSync, sub_obj_ptr_0090) == 0x90, "sub_obj_ptr_0090 at +0x90");
static_assert(offsetof(ccNetFreeBattleSync, queue_related_00A0) == 0xA0, "queue_related_00A0 at +0xA0");
static_assert(offsetof(ccNetFreeBattleSync, ptr_00A8) == 0xA8, "ptr_00A8 at +0xA8");
static_assert(offsetof(ccNetFreeBattleSync, udp_socket) == 0xB0, "udp_socket at +0xB0");
static_assert(offsetof(ccNetFreeBattleSync, scene_network_ptr) == 0x248, "scene_network_ptr at +0x248");
static_assert(offsetof(ccNetFreeBattleSync, send_callback) == 0x250, "send_callback at +0x250");
/* Total allocation size = 0x258 (600) from FUN_140a017f0(600,...) in ccSceneNetworkBattleBase.
 * Note: udp_socket at +0xB0 in s4 (was +0xA8 in s3). Layout shifted due to new fields.
 * pad_after_udp assumes sizeof(ccNetUDPSocket)==0xC8 (s2 lower bound). If s4 udp_socket is larger,
 * the gap shrinks; fields at +0xF0,+0xF8,+0xFC,+0x100 (documented in TSV) may then reside inside
 * udp_socket's interior rather than in FreeBattleSync proper. */

/* ========================================================================
 * ccNetTCPSocket::Impl - TCP socket implementation via Steam Networking
 * Accessed at ccNetTCPSocket+0x18
 * Fields from IsConnected (0x42D608), GetSocketNum (0x42D736), Impl::Receive (0x42D928)
 * ======================================================================== */
typedef struct ccNetTCPSocket_Impl {
    uint8_t  pad_0000[4];       /* +0x0000 */
    uint32_t steam_connection;  /* +0x0004 SteamNetworking vtable calls */
    uint8_t  pad_0008[8];       /* +0x0008 */
    uint32_t is_connected;      /* +0x0010 IsConnected: *(int*)(impl+0x10)==0 */
    uint8_t  pad_0014[4];       /* +0x0014 */
    uint64_t peer_steam_id;     /* +0x0018 GetP2PSessionState */
    uint64_t recv_buffer_start; /* +0x0020 GetSocketNum reads */
    uint64_t recv_buffer_end;   /* +0x0028 GetSocketNum reads */
} ccNetTCPSocket_Impl;
static_assert(offsetof(ccNetTCPSocket_Impl, steam_connection) == 0x04, "steam_connection at +0x04");
static_assert(offsetof(ccNetTCPSocket_Impl, is_connected) == 0x10, "is_connected at +0x10");
static_assert(offsetof(ccNetTCPSocket_Impl, peer_steam_id) == 0x18, "peer_steam_id at +0x18");
static_assert(offsetof(ccNetTCPSocket_Impl, recv_buffer_start) == 0x20, "recv_buffer_start at +0x20");
static_assert(offsetof(ccNetTCPSocket_Impl, recv_buffer_end) == 0x28, "recv_buffer_end at +0x28");

/* ========================================================================
 * ccNetTCPSocket - TCP socket wrapper with ring buffer
 * Ring buffer at +0x5400 (head), +0x5404 (tail), slots of 0x400 bytes
 * Size unknown (>= 0x5424); large unexplored region +0x20..+0x5400
 * Embedded inside ccNetDataSharingTCPSocketAdapter at +0xa0a8
 * ======================================================================== */
typedef struct ccNetTCPSocket {
    void               *vtable;             /* +0x0000 */
    uint8_t             pad_0008[16];       /* +0x0008 */
    ccNetTCPSocket_Impl *impl;              /* +0x0018 Send checks *(int*)(*(param_1+0x18)+0x10) */
    uint8_t             pad_0020[21472];    /* +0x0020 gap to ring buffer (0x5400-0x20 = 0x53E0) */
    int32_t             ring_head;          /* +0x5400 PopFront/Receive head index */
    int32_t             ring_tail;          /* +0x5404 Receive tail index check */
    uint8_t             pad_5408[24];       /* +0x5408 */
    uint32_t            ring_double_buf_idx;/* +0x5420 CtrlEstablished double-buffer toggle */
    uint8_t             pad_5424[2058];     /* +0x5424 fill to 0x5C2E minimum observed access */
} ccNetTCPSocket;
static_assert(offsetof(ccNetTCPSocket, impl) == 0x18, "impl must be at +0x18");
static_assert(offsetof(ccNetTCPSocket, ring_head) == 0x5400, "ring_head must be at +0x5400");
static_assert(offsetof(ccNetTCPSocket, ring_tail) == 0x5404, "ring_tail must be at +0x5404");
static_assert(offsetof(ccNetTCPSocket, ring_double_buf_idx) == 0x5420, "ring_double_buf_idx at +0x5420");
/* Size unknown; >= 0x5C2E from highest observed access. No static_assert on sizeof. */

/* ========================================================================
 * ccNetDataSharingTCPSocketAdapter - wraps ccNetTCPSocket for character select/sync
 * Contains ccNetTCPSocket at +0xa0a8 (carried from s3, re-verify needed)
 * 2 methods found in s4 symbol table: ApplyRecvData, CtrlSocketRecv
 * Size unknown; must be >= 0xa0a8 + sizeof(ccNetTCPSocket)
 * ======================================================================== */
typedef struct ccNetDataSharingTCPSocketAdapter {
    void           *vtable;         /* +0x0000 */
    uint8_t         pad_0008[41120];/* +0x0008 gap to embedded TCP socket (0xA0A8-0x08) */
    ccNetTCPSocket  tcp_socket;     /* +0xA0A8 embedded TCP socket */
    uint8_t         pad_after_tcp[8]; /* placeholder after tcp_socket */
} ccNetDataSharingTCPSocketAdapter;
static_assert(offsetof(ccNetDataSharingTCPSocketAdapter, tcp_socket) == 0xA0A8, "tcp_socket must be at +0xA0A8");
/* Size unknown. No static_assert on sizeof. */

/* Classes ABSENT in s4 (present in s2/s3):
 * - ccNetPersistentTCPSocketAdapter (absent since s3)
 * - ccNetPersistentTCPSocketAdapter::BufferQueue (absent since s3)
 * - ccNetShareLimiter (present in s3, absent in s4)
 * These have no symbols in the s4 build and are omitted. */

#pragma pack(pop)

#endif /* CCNETSOCKET_S4_H */