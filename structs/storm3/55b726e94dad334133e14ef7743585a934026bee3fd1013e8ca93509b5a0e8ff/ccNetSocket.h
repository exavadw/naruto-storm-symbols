/* Auto-generated ccNetSocket structs for NARUTO STORM 3 Full Burst HD (s3 / NSUNS3.exe 64-bit)
 * Classes: ccNetUDPSocket, ccNetUDPSocket::Impl, ccNetTCPSocket, ccNetTCPSocket::Impl,
 *          ccNetDataSharingTCPSocketAdapter, ccNetShareLimiter, ccNetFreeBattleSync
 * All INFERRED from static decompilation, not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */
#ifndef CCNETSOCKET_S3_H
#define CCNETSOCKET_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ========================================================================
 * ccNetUDPSocket::Impl - Steam P2P socket implementation
 * Size unknown (>= 0x20); accessed via pointer at ccNetUDPSocket+0x18
 * Fields inferred from ~Impl (0x7A6220), Stop (0x7A6390), Send (0x7A6160)
 * ======================================================================== */
typedef struct ccNetUDPSocket_Impl {
    uint32_t channel;           /* +0x0000 Initialize: **(uint32_t**)(sock+0x18)=chan writes here */
    uint32_t steam_p2p_handle;  /* +0x0004 Stop/CloseP2P: (**(vtable+0x28))(steam_net, *(impl+4), 6) */
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
 * Vtable dtor: PTR_FUN_1409f0548, base vtable: PTR_FUN_1409ec308
 * Size: unknown in s3; >= 0xB8 (s2 size used as lower bound)
 * Embedded in ccNetFreeBattleSync at +0xa8
 * Only fields proven by UDPSocket-specific methods (Initialize, Start, Stop, Send, ~dtor)
 * are listed here. DispatchPacket fields belong to ccNetFreeBattleSync, not this struct.
 * ======================================================================== */
typedef struct ccNetUDPSocket {
    void    *vtable;            /* +0x0000 dtor sets &PTR_FUN_1409f0548, base &PTR_FUN_1409ec308 */
    uint8_t  pad_0008[16];      /* +0x0008 */
    ccNetUDPSocket_Impl *impl;  /* +0x0018 Stop/Send deref; Initialize writes through */
    uint8_t  pad_0020[168];     /* +0x0020 fill to 0xC8 (conservative; s2 was 0xB8) */
} ccNetUDPSocket;
static_assert(offsetof(ccNetUDPSocket, impl) == 0x18, "impl must be at +0x18");
/* Size unknown in s3. No static_assert on sizeof. */

/* ========================================================================
 * ccNetFreeBattleSync - rollback sync container holding ccNetUDPSocket at +0xa8
 * Allocated at 0x258 (600) bytes (from operator new in s3 code)
 * DispatchPacket (0x789E80) operates on THIS object, not on ccNetUDPSocket directly.
 * Fields at +0x60..+0x250 come from DispatchPacket analysis.
 * ======================================================================== */
typedef struct ccNetFreeBattleSync {
    void    *vtable;            /* +0x0000 */
    uint8_t  pad_0008[88];      /* +0x0008 gap to queue region */
    void    *dispatch_queue_ptr;/* +0x0060 DispatchPacket: synchronized queue structure ptr */
    uint64_t queue_buffer_ptr;  /* +0x0068 buffer array base */
    uint64_t queue_capacity;    /* +0x0070 capacity/mask */
    uint64_t queue_head;        /* +0x0078 head index */
    uint64_t queue_size;        /* +0x0080 element count */
    uint64_t owner_handle;      /* +0x0088 GameActor::Component::GetOwnerHandle target */
    uint64_t sync_point_arg;    /* +0x0090 nummThreadSyncPointCreate param */
    uint8_t  pad_0098[16];      /* +0x0098 */
    ccNetUDPSocket udp_socket;  /* +0x00A8 embedded UDP socket (s2 offset confirmed in s3) */
    /* After udp_socket: remaining space in 0x258-byte allocation holds frame sync state,
     * callbacks, and other sync machinery accessed by DispatchPacket at high offsets.
     * These offsets (+0x238, +0x23C, +0x248, +0x250) are relative to ccNetFreeBattleSync base,
     * NOT relative to udp_socket. They are documented here but not laid out as named fields
     * because the exact sub-object boundaries within FreeBattleSync are unclear. */
    uint8_t  pad_after_udp[264];/* +0x0158 fills to 0x258 total (0x258 - 0xA8 - 0xB0 = 0x100... adjusted) */
} ccNetFreeBattleSync;
static_assert(offsetof(ccNetFreeBattleSync, dispatch_queue_ptr) == 0x60, "dispatch_queue_ptr at +0x60");
static_assert(offsetof(ccNetFreeBattleSync, queue_buffer_ptr) == 0x68, "queue_buffer_ptr at +0x68");
static_assert(offsetof(ccNetFreeBattleSync, queue_capacity) == 0x70, "queue_capacity at +0x70");
static_assert(offsetof(ccNetFreeBattleSync, queue_head) == 0x78, "queue_head at +0x78");
static_assert(offsetof(ccNetFreeBattleSync, queue_size) == 0x80, "queue_size at +0x80");
static_assert(offsetof(ccNetFreeBattleSync, owner_handle) == 0x88, "owner_handle at +0x88");
static_assert(offsetof(ccNetFreeBattleSync, sync_point_arg) == 0x90, "sync_point_arg at +0x90");
static_assert(offsetof(ccNetFreeBattleSync, udp_socket) == 0xA8, "udp_socket at +0xA8");
/* Note: sizeof(ccNetFreeBattleSync) depends on sizeof(ccNetUDPSocket) which is unknown.
 * The 0x258 allocation size is from game code. No static_assert on sizeof until udp size is proven. */

/* ========================================================================
 * ccNetTCPSocket::Impl - TCP socket implementation via Steam Networking
 * Accessed at ccNetTCPSocket+0x18
 * Fields from IsConnected (0x781CE0), GetSocketNum (0x781D60), Impl::Receive (0x781F80)
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
    void    *vtable;            /* +0x0000 */
    uint8_t  pad_0008[16];      /* +0x0008 */
    ccNetTCPSocket_Impl *impl;  /* +0x0018 Send checks *(int*)(*(param_1+0x18)+0x10) */
    uint8_t  pad_0020[21472];   /* +0x0020 gap to ring buffer (0x5400-0x20 = 0x53E0 = 21472) */
    int32_t  ring_head;         /* +0x5400 PopFront/Receive head index */
    int32_t  ring_tail;         /* +0x5404 Receive tail index check */
    uint8_t  pad_5408[24];      /* +0x5408 */
    uint32_t ring_double_buf_idx;/* +0x5420 CtrlEstablished double-buffer toggle */
    uint8_t  pad_5424[2058];    /* +0x5424 fill to 0x5C2E minimum observed access */
} ccNetTCPSocket;
static_assert(offsetof(ccNetTCPSocket, impl) == 0x18, "impl must be at +0x18");
static_assert(offsetof(ccNetTCPSocket, ring_head) == 0x5400, "ring_head must be at +0x5400");
static_assert(offsetof(ccNetTCPSocket, ring_tail) == 0x5404, "ring_tail must be at +0x5404");
static_assert(offsetof(ccNetTCPSocket, ring_double_buf_idx) == 0x5420, "ring_double_buf_idx at +0x5420");
/* Size unknown; >= 0x5C2E from highest observed access. No static_assert on sizeof. */

/* ========================================================================
 * ccNetDataSharingTCPSocketAdapter - wraps ccNetTCPSocket for character select/sync
 * Contains ccNetTCPSocket at +0xa0a8 (from s3 decomp)
 * 8 methods found in s3 symbol table
 * Size unknown; must be >= 0xa0a8 + sizeof(ccNetTCPSocket)
 * ======================================================================== */
typedef struct ccNetDataSharingTCPSocketAdapter {
    void    *vtable;            /* +0x0000 */
    uint8_t  pad_0008[41120];   /* +0x0008 gap to embedded TCP socket (0xA0A8-0x08 = 0xA0A0 = 41120) */
    ccNetTCPSocket tcp_socket;  /* +0xA0A8 embedded TCP socket */
    uint8_t  pad_after_tcp[8];  /* placeholder after tcp_socket */
} ccNetDataSharingTCPSocketAdapter;
static_assert(offsetof(ccNetDataSharingTCPSocketAdapter, tcp_socket) == 0xA0A8, "tcp_socket must be at +0xA0A8");
/* Size unknown. No static_assert on sizeof. */

/* ========================================================================
 * ccNetShareLimiter - manages dialog close state with indexed queue access
 * Only IsClosedDialog method found in s3
 * Size unknown; minimal struct placeholder
 * ======================================================================== */
typedef struct ccNetShareLimiter {
    void    *vtable;            /* +0x0000 */
    uint8_t  pad_0008[56];      /* +0x0008 placeholder; no field evidence beyond vtable */
} ccNetShareLimiter;
/* Size unknown. No static_assert on sizeof. */

/* Classes ABSENT in s3 (present in s2):
 * - ccNetPersistentTCPSocketAdapter
 * - ccNetPersistentTCPSocketAdapter::BufferQueue
 * These have no symbols in the s3 build and are omitted. */

#pragma pack(pop)

#endif /* CCNETSOCKET_S3_H */