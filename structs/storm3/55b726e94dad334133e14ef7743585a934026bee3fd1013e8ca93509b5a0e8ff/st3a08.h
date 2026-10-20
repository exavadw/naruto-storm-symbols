#ifndef ST3A08_H
#define ST3A08_H
#include <assert.h>
#include <stdint.h>
#include <stddef.h>
/* Story struct group st3a08 for build s3 (NSUNS3.exe 64-bit) */
/* All layouts INFERRED from static analysis, not CONFIRMED */
/* PC offsets only from x64 decompile, base 0x140000000 */

#pragma pack(push, 1)
struct ns3_ccAdvBaseMob {
    uint64_t vtable_ptr; /* 0x0 [PRES] conf=high ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0x8[136];
    uint64_t clump; /* 0x90 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint64_t anm; /* 0x98 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t list_0xa0; /* 0xa0 [UNKNOWN] conf=low ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0xa1[15];
    uint64_t field_0xb0; /* 0xb0 [SIM] conf=high ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t list_0xb8; /* 0xb8 [UNKNOWN] conf=low ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0xb9[7];
    uint64_t field_0xc0; /* 0xc0 [SIM] conf=high ev=ccAdvBaseMob::ccAdvBaseMob */
    uint64_t field_0xc8; /* 0xc8 [SIM] conf=high ev=ccAdvBaseMob::ccAdvBaseMob */
    uint64_t field_0xd0; /* 0xd0 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint64_t field_0xd8; /* 0xd8 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t block_allocator; /* 0xe0 [UNKNOWN] conf=low ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0xe1[15];
    uint64_t field_0xf0; /* 0xf0 [SIM] conf=medium ev=ccAdvBaseMob::~ccAdvBaseMob */
    uint64_t field_0xf8; /* 0xf8 [SIM] conf=medium ev=ccAdvBaseMob::~ccAdvBaseMob */
    uint64_t field_0x100; /* 0x100 [SIM] conf=low ev=ccAdvBaseMob::~ccAdvBaseMob */
    uint8_t _pad_0x108[16];
    uint64_t nucc_anm; /* 0x118 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint32_t field_0x120; /* 0x120 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0x124[4];
    uint64_t nucc_anm2; /* 0x128 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint32_t field_0x130; /* 0x130 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    float field_0x134; /* 0x134 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    float field_0x138; /* 0x138 [SIM] conf=medium ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0x13c[4];
    uint8_t head_ctrl; /* 0x140 [UNKNOWN] conf=low ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_0x141[183];
    uint8_t tail_data; /* 0x1f8 [UNKNOWN] conf=low ev=ccAdvBaseMob::ccAdvBaseMob */
    uint8_t _pad_trailing[311];
};
#pragma pack(pop)
static_assert(sizeof(struct ns3_ccAdvBaseMob) == 0x330, "ns3_ccAdvBaseMob size");
static_assert(offsetof(struct ns3_ccAdvBaseMob, vtable_ptr) == 0x0, "ccAdvBaseMob.vtable_ptr offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, clump) == 0x90, "ccAdvBaseMob.clump offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, anm) == 0x98, "ccAdvBaseMob.anm offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, list_0xa0) == 0xa0, "ccAdvBaseMob.list_0xa0 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xb0) == 0xb0, "ccAdvBaseMob.field_0xb0 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, list_0xb8) == 0xb8, "ccAdvBaseMob.list_0xb8 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xc0) == 0xc0, "ccAdvBaseMob.field_0xc0 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xc8) == 0xc8, "ccAdvBaseMob.field_0xc8 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xd0) == 0xd0, "ccAdvBaseMob.field_0xd0 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xd8) == 0xd8, "ccAdvBaseMob.field_0xd8 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, block_allocator) == 0xe0, "ccAdvBaseMob.block_allocator offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xf0) == 0xf0, "ccAdvBaseMob.field_0xf0 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0xf8) == 0xf8, "ccAdvBaseMob.field_0xf8 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0x100) == 0x100, "ccAdvBaseMob.field_0x100 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, nucc_anm) == 0x118, "ccAdvBaseMob.nucc_anm offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0x120) == 0x120, "ccAdvBaseMob.field_0x120 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, nucc_anm2) == 0x128, "ccAdvBaseMob.nucc_anm2 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0x130) == 0x130, "ccAdvBaseMob.field_0x130 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0x134) == 0x134, "ccAdvBaseMob.field_0x134 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, field_0x138) == 0x138, "ccAdvBaseMob.field_0x138 offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, head_ctrl) == 0x140, "ccAdvBaseMob.head_ctrl offset");
static_assert(offsetof(struct ns3_ccAdvBaseMob, tail_data) == 0x1f8, "ccAdvBaseMob.tail_data offset");

#pragma pack(push, 1)
struct ns3_ccAdvBaseAnm {
    uint64_t vtable_ptr; /* 0x0 [PRES] conf=high ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint64_t field_0x08; /* 0x8 [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint8_t position; /* 0x10 [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint8_t _pad_0x11[11];
    uint8_t matrix; /* 0x1c [UNKNOWN] conf=low ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint8_t _pad_0x1d[63];
    uint8_t scale; /* 0x5c [UNKNOWN] conf=low ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint8_t _pad_0x5d[11];
    uint32_t field_0x68; /* 0x68 [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint32_t field_0x6c; /* 0x6c [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint32_t field_0x70; /* 0x70 [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
    uint32_t field_0x74; /* 0x74 [SIM] conf=medium ev=ccAdvBaseAnm::ccAdvBaseAnm */
};
#pragma pack(pop)
static_assert(sizeof(struct ns3_ccAdvBaseAnm) == 0x78, "ns3_ccAdvBaseAnm size");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, vtable_ptr) == 0x0, "ccAdvBaseAnm.vtable_ptr offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, field_0x08) == 0x8, "ccAdvBaseAnm.field_0x08 offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, position) == 0x10, "ccAdvBaseAnm.position offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, matrix) == 0x1c, "ccAdvBaseAnm.matrix offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, scale) == 0x5c, "ccAdvBaseAnm.scale offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, field_0x68) == 0x68, "ccAdvBaseAnm.field_0x68 offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, field_0x6c) == 0x6c, "ccAdvBaseAnm.field_0x6c offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, field_0x70) == 0x70, "ccAdvBaseAnm.field_0x70 offset");
static_assert(offsetof(struct ns3_ccAdvBaseAnm, field_0x74) == 0x74, "ccAdvBaseAnm.field_0x74 offset");

#pragma pack(push, 1)
struct ns3_ccAdv3dCameraCtrl {
    uint64_t vtable_ptr; /* 0x0 [PRES] conf=high ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x8[56];
    uint32_t state_id; /* 0x40 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x44[4];
    uint64_t state_name; /* 0x48 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint32_t field_0x50; /* 0x50 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint64_t field_0x54; /* 0x54 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint32_t field_0x5c; /* 0x5c [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint32_t field_0x60; /* 0x60 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x64[4];
    uint64_t field_0x68; /* 0x68 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t input_manager; /* 0x70 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x71[215];
    uint8_t calc_camera_pos; /* 0x148 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x149[87];
    uint64_t field_0x1a0; /* 0x1a0 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint64_t field_0x1a8; /* 0x1a8 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint64_t field_0x1b0; /* 0x1b0 [SIM] conf=medium ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t block_allocator; /* 0x1b8 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x1b9[47];
    uint8_t vec3_0x1e8; /* 0x1e8 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x1e9[23];
    uint8_t vec3_0x200; /* 0x200 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x201[15];
    uint8_t vec3_0x210; /* 0x210 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x211[11];
    uint8_t vec3_0x21c; /* 0x21c [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x21d[11];
    uint8_t vec3_0x228; /* 0x228 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
    uint8_t _pad_0x229[11];
    uint8_t tail_0x234; /* 0x234 [UNKNOWN] conf=low ev=ccAdv3dCameraCtrl::ccAdv3dCameraCtrl */
};
#pragma pack(pop)
/* size unknown, >= 0x23c */
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vtable_ptr) == 0x0, "ccAdv3dCameraCtrl.vtable_ptr offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, state_id) == 0x40, "ccAdv3dCameraCtrl.state_id offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, state_name) == 0x48, "ccAdv3dCameraCtrl.state_name offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x50) == 0x50, "ccAdv3dCameraCtrl.field_0x50 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x54) == 0x54, "ccAdv3dCameraCtrl.field_0x54 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x5c) == 0x5c, "ccAdv3dCameraCtrl.field_0x5c offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x60) == 0x60, "ccAdv3dCameraCtrl.field_0x60 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x68) == 0x68, "ccAdv3dCameraCtrl.field_0x68 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, input_manager) == 0x70, "ccAdv3dCameraCtrl.input_manager offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, calc_camera_pos) == 0x148, "ccAdv3dCameraCtrl.calc_camera_pos offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x1a0) == 0x1a0, "ccAdv3dCameraCtrl.field_0x1a0 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x1a8) == 0x1a8, "ccAdv3dCameraCtrl.field_0x1a8 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, field_0x1b0) == 0x1b0, "ccAdv3dCameraCtrl.field_0x1b0 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, block_allocator) == 0x1b8, "ccAdv3dCameraCtrl.block_allocator offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vec3_0x1e8) == 0x1e8, "ccAdv3dCameraCtrl.vec3_0x1e8 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vec3_0x200) == 0x200, "ccAdv3dCameraCtrl.vec3_0x200 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vec3_0x210) == 0x210, "ccAdv3dCameraCtrl.vec3_0x210 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vec3_0x21c) == 0x21c, "ccAdv3dCameraCtrl.vec3_0x21c offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, vec3_0x228) == 0x228, "ccAdv3dCameraCtrl.vec3_0x228 offset");
static_assert(offsetof(struct ns3_ccAdv3dCameraCtrl, tail_0x234) == 0x234, "ccAdv3dCameraCtrl.tail_0x234 offset");

#pragma pack(push, 1)
struct ns3_ccAdv3DMapCamera {
    uint64_t vtable_ptr; /* 0x0 [PRES] conf=high ev=ccAdv3DMapCamera::ccAdv3DMapCamera */
    uint8_t cmn_camera_op_base; /* 0x8 [UNKNOWN] conf=low ev=ccAdv3DMapCamera::ccAdv3DMapCamera */
    uint8_t _pad_0x9[423];
    uint8_t camera_ctrl; /* 0x1b0 [PRES] conf=high ev=ccAdv3DMapCamera::ccAdv3DMapCamera */
    uint8_t _pad_trailing[591];
};
#pragma pack(pop)
static_assert(sizeof(struct ns3_ccAdv3DMapCamera) == 0x400, "ns3_ccAdv3DMapCamera size");
static_assert(offsetof(struct ns3_ccAdv3DMapCamera, vtable_ptr) == 0x0, "ccAdv3DMapCamera.vtable_ptr offset");
static_assert(offsetof(struct ns3_ccAdv3DMapCamera, cmn_camera_op_base) == 0x8, "ccAdv3DMapCamera.cmn_camera_op_base offset");
static_assert(offsetof(struct ns3_ccAdv3DMapCamera, camera_ctrl) == 0x1b0, "ccAdv3DMapCamera.camera_ctrl offset");

#pragma pack(push, 1)
struct ns3_ccAdvBaseDraw {
    uint64_t vtable_ptr; /* 0x0 [PRES] conf=high ev=ccAdvBaseDraw::ccAdvBaseDraw */
    uint8_t _pad_0x8[312];
    uint8_t field_0x140; /* 0x140 [UNKNOWN] conf=low ev=surface */
    uint8_t _pad_0x141[63];
    uint8_t field_0x180; /* 0x180 [UNKNOWN] conf=low ev=surface */
};
#pragma pack(pop)
/* size unknown, >= 0x188 */
static_assert(offsetof(struct ns3_ccAdvBaseDraw, vtable_ptr) == 0x0, "ccAdvBaseDraw.vtable_ptr offset");
static_assert(offsetof(struct ns3_ccAdvBaseDraw, field_0x140) == 0x140, "ccAdvBaseDraw.field_0x140 offset");
static_assert(offsetof(struct ns3_ccAdvBaseDraw, field_0x180) == 0x180, "ccAdvBaseDraw.field_0x180 offset");

/* ccAdvBaseCoord: insufficient surface data for layout reconstruction */

/* ccAdvCalc3dMapCameraPos: insufficient surface data for layout reconstruction */

/* ccAdvCalc3dNormalCameraPos: insufficient surface data for layout reconstruction */

/* ccAdvBattleLoader: insufficient surface data for layout reconstruction */

/* ccAdvBossBattleSaveData: insufficient surface data for layout reconstruction */

/* ccAdvBtlMemberSelectState: insufficient surface data for layout reconstruction */

#endif /* ST3A08_H */
