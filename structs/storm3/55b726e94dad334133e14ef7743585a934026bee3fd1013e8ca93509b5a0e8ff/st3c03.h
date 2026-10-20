/* st3c03.h -- Story cutscene/event structs for NSUNS3 (s3) */
/* INFERRED from static analysis. Not CONFIRMED. */
/* Build: s3 (NSUNS3.exe-a7124b, sha 55b726e94dad) */
#ifndef ST3C03_H
#define ST3C03_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccEventCameraState */
/* vtable: 0x1409838e0 */
/* proven size: 0x1A0 (416) */
typedef struct __attribute__((packed)) ccEventCameraState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint8_t _pad2[0x68]; /* 0x0070 */
    uint32_t field_0x00D8; /* 0x00D8 */
    uint64_t field_0x00DC; /* 0x00DC */
    uint32_t field_0x00E4; /* 0x00E4 */
    uint8_t _pad3[0x18]; /* 0x00E8 */
    uint32_t field_0x0100; /* 0x0100 */
    uint8_t _pad4[0x14]; /* 0x0104 */
    uint64_t field_0x0118; /* 0x0118 */
    uint32_t field_0x0120; /* 0x0120 */
    uint64_t field_0x0124; /* 0x0124 */
    uint8_t _pad5[0x4]; /* 0x012C */
    uint64_t field_0x0130; /* 0x0130 */
    uint64_t field_0x0138; /* 0x0138 */
    uint64_t field_0x0140; /* 0x0140 */
    uint64_t field_0x0148; /* 0x0148 */
    uint8_t _pad6[0x10]; /* 0x0150 */
    uint64_t field_0x0160; /* 0x0160 */
    uint64_t field_0x0168; /* 0x0168 */
    uint64_t field_0x0170; /* 0x0170 */
    uint64_t field_0x0178; /* 0x0178 */
    uint8_t _pad7[0x10]; /* 0x0180 */
    uint64_t field_0x0190; /* 0x0190 */
    uint32_t field_0x0198; /* 0x0198 */
    uint8_t _pad_end[0x4]; /* 0x019C */
} ccEventCameraState_t;
static_assert(sizeof(ccEventCameraState_t) == 0x1A0, "ccEventCameraState size mismatch");
static_assert(offsetof(ccEventCameraState_t, field_0x0054) == 0x0054, "ccEventCameraState.field_0x0054 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x005C) == 0x005C, "ccEventCameraState.field_0x005C offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0060) == 0x0060, "ccEventCameraState.field_0x0060 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0068) == 0x0068, "ccEventCameraState.field_0x0068 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x00D8) == 0x00D8, "ccEventCameraState.field_0x00D8 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x00DC) == 0x00DC, "ccEventCameraState.field_0x00DC offset");
static_assert(offsetof(ccEventCameraState_t, field_0x00E4) == 0x00E4, "ccEventCameraState.field_0x00E4 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0100) == 0x0100, "ccEventCameraState.field_0x0100 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0118) == 0x0118, "ccEventCameraState.field_0x0118 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0120) == 0x0120, "ccEventCameraState.field_0x0120 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0124) == 0x0124, "ccEventCameraState.field_0x0124 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0130) == 0x0130, "ccEventCameraState.field_0x0130 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0138) == 0x0138, "ccEventCameraState.field_0x0138 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0140) == 0x0140, "ccEventCameraState.field_0x0140 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0148) == 0x0148, "ccEventCameraState.field_0x0148 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0160) == 0x0160, "ccEventCameraState.field_0x0160 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0168) == 0x0168, "ccEventCameraState.field_0x0168 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0170) == 0x0170, "ccEventCameraState.field_0x0170 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0178) == 0x0178, "ccEventCameraState.field_0x0178 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0190) == 0x0190, "ccEventCameraState.field_0x0190 offset");
static_assert(offsetof(ccEventCameraState_t, field_0x0198) == 0x0198, "ccEventCameraState.field_0x0198 offset");

/* ccEventCameraVibration */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventCameraVibration {
    /* no fields detected; size unproven */
} ccEventCameraVibration_t;

/* ccEventChara */
/* vtable: 0x1408b6738 */
/* proven size: 0x238 (568) */
typedef struct __attribute__((packed)) ccEventChara {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0xA8]; /* 0x0008 */
    uint64_t field_0x00B0; /* 0x00B0 */
    uint64_t field_0x00B8; /* 0x00B8 */
    uint64_t field_0x00C0; /* 0x00C0 */
    uint64_t field_0x00C8; /* 0x00C8 */
    uint64_t field_0x00D0; /* 0x00D0 */
    uint64_t field_0x00D8; /* 0x00D8 */
    uint8_t _pad1[0x78]; /* 0x00E0 */
    uint64_t field_0x0158; /* 0x0158 */
    uint64_t field_0x0160; /* 0x0160 */
    uint64_t field_0x0168; /* 0x0168 */
    uint64_t field_0x0170; /* 0x0170 */
    uint64_t field_0x0178; /* 0x0178 */
    uint64_t field_0x0180; /* 0x0180 */
    uint64_t field_0x0188; /* 0x0188 */
    uint64_t field_0x0190; /* 0x0190 */
    uint64_t field_0x0198; /* 0x0198 */
    uint64_t field_0x01A0; /* 0x01A0 */
    uint32_t field_0x01A8; /* 0x01A8 */
    uint8_t _pad2[0x4]; /* 0x01AC */
    uint64_t field_0x01B0; /* 0x01B0 */
    uint64_t field_0x01B8; /* 0x01B8 */
    uint64_t field_0x01C0; /* 0x01C0 */
    uint64_t field_0x01C8; /* 0x01C8 */
    uint32_t field_0x01D0; /* 0x01D0 */
    uint8_t _pad3[0x4]; /* 0x01D4 */
    uint64_t field_0x01D8; /* 0x01D8 */
    uint64_t field_0x01E0; /* 0x01E0 */
    uint64_t field_0x01E8; /* 0x01E8 */
    uint64_t field_0x01F0; /* 0x01F0 */
    uint8_t _pad4[0x10]; /* 0x01F8 */
    uint64_t field_0x0208; /* 0x0208 */
    uint64_t field_0x0210; /* 0x0210 */
    uint64_t field_0x0218; /* 0x0218 */
    uint64_t field_0x0220; /* 0x0220 */
    uint8_t _pad_end[0x10]; /* 0x0228 */
} ccEventChara_t;
static_assert(sizeof(ccEventChara_t) == 0x238, "ccEventChara size mismatch");
static_assert(offsetof(ccEventChara_t, field_0x00B0) == 0x00B0, "ccEventChara.field_0x00B0 offset");
static_assert(offsetof(ccEventChara_t, field_0x00B8) == 0x00B8, "ccEventChara.field_0x00B8 offset");
static_assert(offsetof(ccEventChara_t, field_0x00C0) == 0x00C0, "ccEventChara.field_0x00C0 offset");
static_assert(offsetof(ccEventChara_t, field_0x00C8) == 0x00C8, "ccEventChara.field_0x00C8 offset");
static_assert(offsetof(ccEventChara_t, field_0x00D0) == 0x00D0, "ccEventChara.field_0x00D0 offset");
static_assert(offsetof(ccEventChara_t, field_0x00D8) == 0x00D8, "ccEventChara.field_0x00D8 offset");
static_assert(offsetof(ccEventChara_t, field_0x0158) == 0x0158, "ccEventChara.field_0x0158 offset");
static_assert(offsetof(ccEventChara_t, field_0x0160) == 0x0160, "ccEventChara.field_0x0160 offset");
static_assert(offsetof(ccEventChara_t, field_0x0168) == 0x0168, "ccEventChara.field_0x0168 offset");
static_assert(offsetof(ccEventChara_t, field_0x0170) == 0x0170, "ccEventChara.field_0x0170 offset");
static_assert(offsetof(ccEventChara_t, field_0x0178) == 0x0178, "ccEventChara.field_0x0178 offset");
static_assert(offsetof(ccEventChara_t, field_0x0180) == 0x0180, "ccEventChara.field_0x0180 offset");
static_assert(offsetof(ccEventChara_t, field_0x0188) == 0x0188, "ccEventChara.field_0x0188 offset");
static_assert(offsetof(ccEventChara_t, field_0x0190) == 0x0190, "ccEventChara.field_0x0190 offset");
static_assert(offsetof(ccEventChara_t, field_0x0198) == 0x0198, "ccEventChara.field_0x0198 offset");
static_assert(offsetof(ccEventChara_t, field_0x01A0) == 0x01A0, "ccEventChara.field_0x01A0 offset");
static_assert(offsetof(ccEventChara_t, field_0x01A8) == 0x01A8, "ccEventChara.field_0x01A8 offset");
static_assert(offsetof(ccEventChara_t, field_0x01B0) == 0x01B0, "ccEventChara.field_0x01B0 offset");
static_assert(offsetof(ccEventChara_t, field_0x01B8) == 0x01B8, "ccEventChara.field_0x01B8 offset");
static_assert(offsetof(ccEventChara_t, field_0x01C0) == 0x01C0, "ccEventChara.field_0x01C0 offset");
static_assert(offsetof(ccEventChara_t, field_0x01C8) == 0x01C8, "ccEventChara.field_0x01C8 offset");
static_assert(offsetof(ccEventChara_t, field_0x01D0) == 0x01D0, "ccEventChara.field_0x01D0 offset");
static_assert(offsetof(ccEventChara_t, field_0x01D8) == 0x01D8, "ccEventChara.field_0x01D8 offset");
static_assert(offsetof(ccEventChara_t, field_0x01E0) == 0x01E0, "ccEventChara.field_0x01E0 offset");
static_assert(offsetof(ccEventChara_t, field_0x01E8) == 0x01E8, "ccEventChara.field_0x01E8 offset");
static_assert(offsetof(ccEventChara_t, field_0x01F0) == 0x01F0, "ccEventChara.field_0x01F0 offset");
static_assert(offsetof(ccEventChara_t, field_0x0208) == 0x0208, "ccEventChara.field_0x0208 offset");
static_assert(offsetof(ccEventChara_t, field_0x0210) == 0x0210, "ccEventChara.field_0x0210 offset");
static_assert(offsetof(ccEventChara_t, field_0x0218) == 0x0218, "ccEventChara.field_0x0218 offset");
static_assert(offsetof(ccEventChara_t, field_0x0220) == 0x0220, "ccEventChara.field_0x0220 offset");

/* ccEventCharaKeepParam_ccCharaParam */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventCharaKeepParam_ccCharaParam {
    /* no fields detected; size unproven */
} ccEventCharaKeepParam_ccCharaParam_t;

/* ccEventCharaState */
/* vtable: 0x140983f80 */
/* proven size: 0x958 (2392) */
typedef struct __attribute__((packed)) ccEventCharaState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint64_t field_0x0070; /* 0x0070 */
    uint64_t field_0x0078; /* 0x0078 */
    uint8_t _pad2[0x38]; /* 0x0080 */
    uint32_t field_0x00B8; /* 0x00B8 */
    uint8_t _pad3[0x30]; /* 0x00BC */
    uint64_t field_0x00EC; /* 0x00EC */
    uint64_t field_0x00F4; /* 0x00F4 */
    uint8_t _pad4[0x3C4]; /* 0x00FC */
    uint64_t field_0x04C0; /* 0x04C0 */
    uint64_t field_0x04C8; /* 0x04C8 */
    uint64_t field_0x04D0; /* 0x04D0 */
    uint8_t _pad5[0x440]; /* 0x04D8 */
    uint64_t field_0x0918; /* 0x0918 */
    uint64_t field_0x0920; /* 0x0920 */
    uint64_t field_0x0928; /* 0x0928 */
    uint64_t field_0x0930; /* 0x0930 */
    uint8_t _pad6[0x10]; /* 0x0938 */
    uint64_t field_0x0948; /* 0x0948 */
    uint64_t field_0x0950; /* 0x0950 */
} ccEventCharaState_t;
static_assert(sizeof(ccEventCharaState_t) == 0x958, "ccEventCharaState size mismatch");
static_assert(offsetof(ccEventCharaState_t, field_0x0054) == 0x0054, "ccEventCharaState.field_0x0054 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x005C) == 0x005C, "ccEventCharaState.field_0x005C offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0060) == 0x0060, "ccEventCharaState.field_0x0060 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0068) == 0x0068, "ccEventCharaState.field_0x0068 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0070) == 0x0070, "ccEventCharaState.field_0x0070 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0078) == 0x0078, "ccEventCharaState.field_0x0078 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x00B8) == 0x00B8, "ccEventCharaState.field_0x00B8 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x00EC) == 0x00EC, "ccEventCharaState.field_0x00EC offset");
static_assert(offsetof(ccEventCharaState_t, field_0x00F4) == 0x00F4, "ccEventCharaState.field_0x00F4 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x04C0) == 0x04C0, "ccEventCharaState.field_0x04C0 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x04C8) == 0x04C8, "ccEventCharaState.field_0x04C8 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x04D0) == 0x04D0, "ccEventCharaState.field_0x04D0 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0918) == 0x0918, "ccEventCharaState.field_0x0918 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0920) == 0x0920, "ccEventCharaState.field_0x0920 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0928) == 0x0928, "ccEventCharaState.field_0x0928 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0930) == 0x0930, "ccEventCharaState.field_0x0930 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0948) == 0x0948, "ccEventCharaState.field_0x0948 offset");
static_assert(offsetof(ccEventCharaState_t, field_0x0950) == 0x0950, "ccEventCharaState.field_0x0950 offset");

/* ccEventColorConv */
/* vtable: 0x140984258 */
/* proven size: 0xF8 (248) */
typedef struct __attribute__((packed)) ccEventColorConv {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint64_t field_0x0070; /* 0x0070 */
    uint64_t field_0x0078; /* 0x0078 */
    uint64_t field_0x0080; /* 0x0080 */
    uint64_t field_0x0088; /* 0x0088 */
    uint32_t field_0x0090; /* 0x0090 */
    uint32_t field_0x0094; /* 0x0094 */
    uint32_t field_0x0098; /* 0x0098 */
    uint8_t _pad2[0x4]; /* 0x009C */
    uint64_t field_0x00A0; /* 0x00A0 */
    uint8_t _pad3[0x28]; /* 0x00A8 */
    uint64_t field_0x00D0; /* 0x00D0 */
    uint64_t field_0x00D8; /* 0x00D8 */
    uint64_t field_0x00E0; /* 0x00E0 */
    uint8_t _pad_end[0x10]; /* 0x00E8 */
} ccEventColorConv_t;
static_assert(sizeof(ccEventColorConv_t) == 0xF8, "ccEventColorConv size mismatch");
static_assert(offsetof(ccEventColorConv_t, field_0x0054) == 0x0054, "ccEventColorConv.field_0x0054 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x005C) == 0x005C, "ccEventColorConv.field_0x005C offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0060) == 0x0060, "ccEventColorConv.field_0x0060 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0068) == 0x0068, "ccEventColorConv.field_0x0068 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0070) == 0x0070, "ccEventColorConv.field_0x0070 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0078) == 0x0078, "ccEventColorConv.field_0x0078 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0080) == 0x0080, "ccEventColorConv.field_0x0080 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0088) == 0x0088, "ccEventColorConv.field_0x0088 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0090) == 0x0090, "ccEventColorConv.field_0x0090 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0094) == 0x0094, "ccEventColorConv.field_0x0094 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x0098) == 0x0098, "ccEventColorConv.field_0x0098 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x00A0) == 0x00A0, "ccEventColorConv.field_0x00A0 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x00D0) == 0x00D0, "ccEventColorConv.field_0x00D0 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x00D8) == 0x00D8, "ccEventColorConv.field_0x00D8 offset");
static_assert(offsetof(ccEventColorConv_t, field_0x00E0) == 0x00E0, "ccEventColorConv.field_0x00E0 offset");

/* ccEventColorFilterState */
/* vtable: 0x140984340 */
/* proven size: 0x180 (384) */
typedef struct __attribute__((packed)) ccEventColorFilterState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad_end[0x178]; /* 0x0008 */
} ccEventColorFilterState_t;
static_assert(sizeof(ccEventColorFilterState_t) == 0x180, "ccEventColorFilterState size mismatch");

/* ccEventColorParaffinState */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventColorParaffinState {
    /* no fields detected; size unproven */
} ccEventColorParaffinState_t;

/* ccEventDofState */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventDofState {
    /* no fields detected; size unproven */
} ccEventDofState_t;

/* ccEventFCVEffectState */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventFCVEffectState {
    /* no fields detected; size unproven */
} ccEventFCVEffectState_t;

/* ccEventFogState */
/* vtable: 0x1409a76e0 */
/* proven size: 0x140 (320) */
typedef struct __attribute__((packed)) ccEventFogState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint32_t field_0x0070; /* 0x0070 */
    uint64_t field_0x0074; /* 0x0074 */
    uint64_t field_0x007C; /* 0x007C */
    uint32_t field_0x0084; /* 0x0084 */
    uint32_t field_0x0088; /* 0x0088 */
    uint64_t field_0x008C; /* 0x008C */
    uint64_t field_0x0094; /* 0x0094 */
    uint64_t field_0x009C; /* 0x009C */
    uint32_t field_0x00A4; /* 0x00A4 */
    uint8_t _pad2[0x10]; /* 0x00A8 */
    uint64_t field_0x00B8; /* 0x00B8 */
    uint64_t field_0x00C0; /* 0x00C0 */
    uint8_t _pad3[0x50]; /* 0x00C8 */
    uint64_t field_0x0118; /* 0x0118 */
    uint64_t field_0x0120; /* 0x0120 */
    uint64_t field_0x0128; /* 0x0128 */
    uint64_t field_0x0130; /* 0x0130 */
    uint64_t field_0x0138; /* 0x0138 */
} ccEventFogState_t;
static_assert(sizeof(ccEventFogState_t) == 0x140, "ccEventFogState size mismatch");
static_assert(offsetof(ccEventFogState_t, field_0x0054) == 0x0054, "ccEventFogState.field_0x0054 offset");
static_assert(offsetof(ccEventFogState_t, field_0x005C) == 0x005C, "ccEventFogState.field_0x005C offset");
static_assert(offsetof(ccEventFogState_t, field_0x0060) == 0x0060, "ccEventFogState.field_0x0060 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0068) == 0x0068, "ccEventFogState.field_0x0068 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0070) == 0x0070, "ccEventFogState.field_0x0070 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0074) == 0x0074, "ccEventFogState.field_0x0074 offset");
static_assert(offsetof(ccEventFogState_t, field_0x007C) == 0x007C, "ccEventFogState.field_0x007C offset");
static_assert(offsetof(ccEventFogState_t, field_0x0084) == 0x0084, "ccEventFogState.field_0x0084 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0088) == 0x0088, "ccEventFogState.field_0x0088 offset");
static_assert(offsetof(ccEventFogState_t, field_0x008C) == 0x008C, "ccEventFogState.field_0x008C offset");
static_assert(offsetof(ccEventFogState_t, field_0x0094) == 0x0094, "ccEventFogState.field_0x0094 offset");
static_assert(offsetof(ccEventFogState_t, field_0x009C) == 0x009C, "ccEventFogState.field_0x009C offset");
static_assert(offsetof(ccEventFogState_t, field_0x00A4) == 0x00A4, "ccEventFogState.field_0x00A4 offset");
static_assert(offsetof(ccEventFogState_t, field_0x00B8) == 0x00B8, "ccEventFogState.field_0x00B8 offset");
static_assert(offsetof(ccEventFogState_t, field_0x00C0) == 0x00C0, "ccEventFogState.field_0x00C0 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0118) == 0x0118, "ccEventFogState.field_0x0118 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0120) == 0x0120, "ccEventFogState.field_0x0120 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0128) == 0x0128, "ccEventFogState.field_0x0128 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0130) == 0x0130, "ccEventFogState.field_0x0130 offset");
static_assert(offsetof(ccEventFogState_t, field_0x0138) == 0x0138, "ccEventFogState.field_0x0138 offset");

/* ccEventGlareState */
/* vtable: 0x140984648 */
/* proven size: 0xD8 (216) */
typedef struct __attribute__((packed)) ccEventGlareState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint64_t field_0x0070; /* 0x0070 */
    uint64_t field_0x0078; /* 0x0078 */
    uint32_t field_0x0080; /* 0x0080 */
    uint8_t _pad2[0x4]; /* 0x0084 */
    uint64_t field_0x0088; /* 0x0088 */
    uint64_t field_0x0090; /* 0x0090 */
    uint64_t field_0x0098; /* 0x0098 */
    uint64_t field_0x00A0; /* 0x00A0 */
    uint8_t _pad3[0x8]; /* 0x00A8 */
    uint64_t field_0x00B0; /* 0x00B0 */
    uint64_t field_0x00B8; /* 0x00B8 */
    uint64_t field_0x00C0; /* 0x00C0 */
    uint8_t _pad_end[0x10]; /* 0x00C8 */
} ccEventGlareState_t;
static_assert(sizeof(ccEventGlareState_t) == 0xD8, "ccEventGlareState size mismatch");
static_assert(offsetof(ccEventGlareState_t, field_0x0054) == 0x0054, "ccEventGlareState.field_0x0054 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x005C) == 0x005C, "ccEventGlareState.field_0x005C offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0060) == 0x0060, "ccEventGlareState.field_0x0060 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0068) == 0x0068, "ccEventGlareState.field_0x0068 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0070) == 0x0070, "ccEventGlareState.field_0x0070 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0078) == 0x0078, "ccEventGlareState.field_0x0078 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0080) == 0x0080, "ccEventGlareState.field_0x0080 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0088) == 0x0088, "ccEventGlareState.field_0x0088 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0090) == 0x0090, "ccEventGlareState.field_0x0090 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x0098) == 0x0098, "ccEventGlareState.field_0x0098 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x00A0) == 0x00A0, "ccEventGlareState.field_0x00A0 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x00B0) == 0x00B0, "ccEventGlareState.field_0x00B0 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x00B8) == 0x00B8, "ccEventGlareState.field_0x00B8 offset");
static_assert(offsetof(ccEventGlareState_t, field_0x00C0) == 0x00C0, "ccEventGlareState.field_0x00C0 offset");

/* ccEventLipSyncState */
/* vtable: 0x140984028 */
/* proven size: 0x170 (368) */
typedef struct __attribute__((packed)) ccEventLipSyncState {
    uint64_t vtable; /* 0x0000 */
    uint8_t _pad0[0x4C]; /* 0x0008 */
    uint64_t field_0x0054; /* 0x0054 */
    uint32_t field_0x005C; /* 0x005C */
    uint32_t field_0x0060; /* 0x0060 */
    uint8_t _pad1[0x4]; /* 0x0064 */
    uint64_t field_0x0068; /* 0x0068 */
    uint64_t field_0x0070; /* 0x0070 */
    uint8_t _pad2[0x10]; /* 0x0078 */
    uint8_t field_0x0088; /* 0x0088 */
    uint8_t _pad3[0xF]; /* 0x0089 */
    uint64_t field_0x0098; /* 0x0098 */
    uint64_t field_0x00A0; /* 0x00A0 */
    uint64_t field_0x00A8; /* 0x00A8 */
    uint8_t _pad4[0x10]; /* 0x00B0 */
    uint8_t field_0x00C0; /* 0x00C0 */
    uint8_t _pad5[0xF]; /* 0x00C1 */
    uint64_t field_0x00D0; /* 0x00D0 */
    uint64_t field_0x00D8; /* 0x00D8 */
    uint64_t field_0x00E0; /* 0x00E0 */
    uint8_t _pad6[0x10]; /* 0x00E8 */
    uint8_t field_0x00F8; /* 0x00F8 */
    uint8_t _pad7[0xF]; /* 0x00F9 */
    uint64_t field_0x0108; /* 0x0108 */
    uint64_t field_0x0110; /* 0x0110 */
    uint64_t field_0x0118; /* 0x0118 */
    uint8_t _pad8[0x10]; /* 0x0120 */
    uint8_t field_0x0130; /* 0x0130 */
    uint8_t _pad9[0xF]; /* 0x0131 */
    uint64_t field_0x0140; /* 0x0140 */
    uint64_t field_0x0148; /* 0x0148 */
    uint64_t field_0x0150; /* 0x0150 */
    uint8_t _pad_end[0x18]; /* 0x0158 */
} ccEventLipSyncState_t;
static_assert(sizeof(ccEventLipSyncState_t) == 0x170, "ccEventLipSyncState size mismatch");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0054) == 0x0054, "ccEventLipSyncState.field_0x0054 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x005C) == 0x005C, "ccEventLipSyncState.field_0x005C offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0060) == 0x0060, "ccEventLipSyncState.field_0x0060 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0068) == 0x0068, "ccEventLipSyncState.field_0x0068 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0070) == 0x0070, "ccEventLipSyncState.field_0x0070 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0088) == 0x0088, "ccEventLipSyncState.field_0x0088 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0098) == 0x0098, "ccEventLipSyncState.field_0x0098 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00A0) == 0x00A0, "ccEventLipSyncState.field_0x00A0 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00A8) == 0x00A8, "ccEventLipSyncState.field_0x00A8 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00C0) == 0x00C0, "ccEventLipSyncState.field_0x00C0 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00D0) == 0x00D0, "ccEventLipSyncState.field_0x00D0 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00D8) == 0x00D8, "ccEventLipSyncState.field_0x00D8 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00E0) == 0x00E0, "ccEventLipSyncState.field_0x00E0 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x00F8) == 0x00F8, "ccEventLipSyncState.field_0x00F8 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0108) == 0x0108, "ccEventLipSyncState.field_0x0108 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0110) == 0x0110, "ccEventLipSyncState.field_0x0110 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0118) == 0x0118, "ccEventLipSyncState.field_0x0118 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0130) == 0x0130, "ccEventLipSyncState.field_0x0130 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0140) == 0x0140, "ccEventLipSyncState.field_0x0140 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0148) == 0x0148, "ccEventLipSyncState.field_0x0148 offset");
static_assert(offsetof(ccEventLipSyncState_t, field_0x0150) == 0x0150, "ccEventLipSyncState.field_0x0150 offset");

/* ccEventManager */
/* size unknown -- no factory allocation found */
typedef struct __attribute__((packed)) ccEventManager {
    /* no fields detected; size unproven */
} ccEventManager_t;

#endif /* ST3C03_H */
