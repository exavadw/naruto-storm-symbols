/* Auto-generated ccNetSocket structs for NARUTO STORM 2 (s2 / NSUNS2.exe)
 * Classes: ccNetUDPSocket, ccNetUDPSocket::Impl, ccNetTCPSocket, ccNetTCPSocket::Impl,
 *          ccNetPersistentTCPSocketAdapter, ccNetPersistentTCPSocketAdapter::BufferQueue,
 *          ccNetFreeBattleSyncEX (contains ccNetUDPSocket at +0xa8, size 0x290)
 * All INFERRED from static decompilation, not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */
#ifndef CCNETSOCKET_S2_H
#define CCNETSOCKET_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/*
 * ccNetUDPSocket::Impl - Steam P2P socket implementation
 * Size unknown; accessed via pointer at ccNetUDPSocket+0x18
 * Fields inferred from ccNetUDPSocket::Impl::Stop (0x69b970), ~Impl (0x69b800)
 */
typedef struct ccNetUDPSocket_Impl {
    uint32_t unk_0000;            /* +0x0000 */
    uint32_t steam_p2p_handle;    /* +0x0004 used in Stop/CloseSteamP2P */
    uint8_t  pad_0008[8];         /* +0x0008 */
    uint32_t connection_state;    /* +0x0010 checked in IsConnected */
    uint8_t  pad_0014[4];         /* +0x0014 */
    uint64_t peer_steam_id;       /* +0x0018 */
    uint8_t  pad_0020[8];         /* +0x0020 */
} ccNetUDPSocket_Impl;

/*
 * ccNetUDPSocket - UDP socket wrapper using Steam Networking P2P
 * Size: 0xb8 (184 bytes) derived from container layout
 * Embedded in ccNetFreeBattleSyncEX at +0xa8
 * Vtable: PTR_FUN_1408a2760 (dtor), PTR_FUN_14089c1b8 (base)
 */
typedef struct ccNetUDPSocket {
    void    *vtable;              /* +0x0000 */
    uint8_t  pad_0008[16];        /* +0x0008 */
    ccNetUDPSocket_Impl *impl;    /* +0x0018 Impl pointer */
    uint8_t  pad_0020[8];         /* +0x0020 */
    uint32_t channel;             /* +0x0028 Initialize param_2 */
    uint8_t  pad_002c[4];         /* +0x002C */
    uint64_t local_steam_id;      /* +0x0030 */
    uint8_t  pad_0038[112];       /* +0x0038 */
    uint64_t dispatch_target;     /* +0x00A8 DispatchPacket reads this */
    uint8_t  pad_00B0[8];         /* +0x00B0 */
} ccNetUDPSocket;
static_assert(sizeof(ccNetUDPSocket) == 0xB8, "ccNetUDPSocket size must be 0xB8");

/*
 * ccNetTCPSocket::Impl - TCP socket implementation via Steam Networking
 * Accessed at ccNetTCPSocket+0x18
 */
typedef struct ccNetTCPSocket_Impl {
    uint8_t  pad_0000[16];        /* +0x0000 */
    uint32_t is_connected;        /* +0x0010 checked in IsConnected */
    uint8_t  pad_0014[4];         /* +0x0014 */
    uint64_t peer_steam_id;       /* +0x0018 */
    uint64_t recv_buffer_start;   /* +0x0020 GetSocketNum uses this */
    uint64_t recv_buffer_end;     /* +0x0028 GetSocketNum uses this */
} ccNetTCPSocket_Impl;

/*
 * ccNetTCPSocket - TCP socket wrapper
 * Contains ring buffer at +0x5400 (head), +0x5404 (tail), slots of 0x400 bytes
 * Size unknown (>= 0x5c2e); large unexplored region +0x20..+0x5400
 */
typedef struct ccNetTCPSocket {
    void    *vtable;              /* +0x0000 */
    uint8_t  pad_0008[16];        /* +0x0008 */
    ccNetTCPSocket_Impl *impl;    /* +0x0018 Impl pointer */
    uint8_t  pad_0020[21472];     /* +0x0020 padding to ring buffer area (0x5400-0x20) */
    int32_t  ring_head;           /* +0x5400 PopFront/Receive head index */
    int32_t  ring_tail;           /* +0x5404 PopFront/Receive tail index */
    uint8_t  pad_5408[24];        /* +0x5408 */
    uint32_t ring_double_buf_idx; /* +0x5420 CtrlEstablished double-buffer toggle */
    int32_t  pending_bytes;       /* +0x5424 bytes pending in current slot */
    uint8_t  pad_5428[2048];      /* +0x5428 ring buffer data area (partial) */
    uint32_t active_slot_idx;     /* +0x5C28 current slot being filled */
    uint16_t slot_offset;         /* +0x5C2C offset within current slot */
    uint8_t  pad_5c2e[2];         /* +0x5C2E */
} ccNetTCPSocket;

/*
 * ccNetPersistentTCPSocketAdapter::BufferQueue
 * Ring buffer queue with 0x14 (20) slots embedded in adapter
 */
typedef struct ccNetPersistentTCPSocketAdapter_BufferQueue {
    int32_t head;                 /* +0x0000 (adapter+0x5400) PopFront head */
    int32_t tail;                 /* +0x0004 (adapter+0x5404) Receive tail */
} ccNetPersistentTCPSocketAdapter_BufferQueue;

/*
 * ccNetPersistentTCPSocketAdapter
 * Wraps ccNetTCPSocket at +0x20, adds state machine at +0x14
 * Size unknown; inner TCP socket fields extend beyond adapter boundary
 */
typedef struct ccNetPersistentTCPSocketAdapter {
    void    *vtable;              /* +0x0000 */
    uint8_t  pad_0008[8];         /* +0x0008 */
    uint64_t tcp_socket_ptr;      /* +0x0010 checked in CtrlEstablished */
    uint32_t adapter_state;       /* +0x0014 Ctrl state machine (1->3->0, 4->0) */
    uint8_t  pad_0018[8];         /* +0x0018 */
    /* ccNetTCPSocket inner_tcp at +0x0020 -- see ccNetTCPSocket above */
} ccNetPersistentTCPSocketAdapter;

/*
 * ccNetFreeBattleSyncEX - network sync task containing ccNetUDPSocket
 * Allocation size: 0x290 (656 bytes) from FUN_140580190(0x290,...)
 * Constructor: FUN_140367f6c (ccNetFreeBattleSyncEX::ccNetFreeBattleSyncEX)
 * Source: source\ccNetworkGameSyncTask.cpp
 * Layout: vtable(8) + parent_fields(0xa0) + udp_socket(0xb8) + trailing(0x130) = 0x290
 */
typedef struct ccNetFreeBattleSyncEX {
    void          *vtable;        /* +0x0000 PTR_FUN_140800a40 */
    uint8_t        pad_0008[160]; /* +0x0008 parent class fields (to +0xa8) */
    ccNetUDPSocket udp_socket;    /* +0x00A8 embedded UDP socket (0xb8 bytes) */
    uint8_t        pad_0160[304]; /* +0x0160 remaining fields to 0x290 */
} ccNetFreeBattleSyncEX;
static_assert(offsetof(ccNetFreeBattleSyncEX, udp_socket) == 0xA8, "udp_socket must be at +0xa8");
static_assert(sizeof(ccNetFreeBattleSyncEX) == 0x290, "ccNetFreeBattleSyncEX size must be 0x290");

#pragma pack(pop)

#endif /* CCNETSOCKET_S2_H */