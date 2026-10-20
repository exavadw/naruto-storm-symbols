#ifndef S2_BOSS08_H
#define S2_BOSS08_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s2Boss08 struct layout for Storm 2 (NSUNS2.exe, build s2)
 * INFERRED from static analysis (state_surface + decomp). Not CONFIRMED.
 * Object size: unknown, >= 0x28FE8 (last proven field ends at 0x28FE8)
 * Fields: 81 (all unnamed/unk_*)
 */

#pragma pack(push, 1)
typedef struct ccBoss0800 {
    uint64_t * vtable;                      /* 0x0000 */
    uint8_t pad_0008[184];                  /* 0x0008 padding */
    uint32_t unk_00C0;                      /* 0x00C0 */
    uint8_t pad_00C4[316];                  /* 0x00C4 padding */
    uint32_t unk_0200;                      /* 0x0200 */
    uint8_t pad_0204[20];                   /* 0x0204 padding */
    uint64_t unk_0218;                      /* 0x0218 */
    uint8_t pad_0220[32];                   /* 0x0220 padding */
    uint32_t unk_0240;                      /* 0x0240 */
    uint8_t pad_0244[316];                  /* 0x0244 padding */
    uint32_t unk_0380;                      /* 0x0380 */
    uint8_t pad_0384[636];                  /* 0x0384 padding */
    uint32_t unk_0600;                      /* 0x0600 */
    uint8_t pad_0604[5948];                 /* 0x0604 padding */
    uint32_t unk_1D40;                      /* 0x1D40 */
    uint8_t pad_1D44[60];                   /* 0x1D44 padding */
    uint32_t unk_1D80;                      /* 0x1D80 */
    uint8_t pad_1D84[1980];                 /* 0x1D84 padding */
    uint32_t unk_2540;                      /* 0x2540 */
    uint8_t pad_2544[14636];                /* 0x2544 padding */
    uint32_t unk_5E70;                      /* 0x5E70 */
    uint8_t pad_5E74[84];                   /* 0x5E74 padding */
    uint64_t unk_5EC8;                      /* 0x5EC8 */
    uint64_t unk_5ED0;                      /* 0x5ED0 */
    uint8_t pad_5ED8[24];                   /* 0x5ED8 padding */
    uint32_t unk_5EF0;                      /* 0x5EF0 */
    uint8_t pad_5EF4[92];                   /* 0x5EF4 padding */
    uint64_t unk_5F50;                      /* 0x5F50 */
    uint64_t unk_5F58;                      /* 0x5F58 */
    uint8_t pad_5F60[24];                   /* 0x5F60 padding */
    uint32_t unk_5F78;                      /* 0x5F78 */
    uint8_t pad_5F7C[92];                   /* 0x5F7C padding */
    uint64_t unk_5FD8;                      /* 0x5FD8 */
    uint64_t unk_5FE0;                      /* 0x5FE0 */
    uint8_t pad_5FE8[80];                   /* 0x5FE8 padding */
    uint32_t unk_6038;                      /* 0x6038 */
    uint8_t pad_603C[3884];                 /* 0x603C padding */
    uint32_t unk_6F68;                      /* 0x6F68 */
    uint8_t pad_6F6C[308];                  /* 0x6F6C padding */
    uint64_t unk_70A0;                      /* 0x70A0 */
    uint64_t unk_70A8;                      /* 0x70A8 */
    uint64_t unk_70B0;                      /* 0x70B0 */
    uint64_t unk_70B8;                      /* 0x70B8 */
    uint64_t unk_70C0;                      /* 0x70C0 */
    uint32_t unk_70C8;                      /* 0x70C8 */
    uint64_t unk_70CC;                      /* 0x70CC */
    uint64_t unk_70D4;                      /* 0x70D4 */
    uint64_t unk_70DC;                      /* 0x70DC */
    uint64_t unk_70E4;                      /* 0x70E4 */
    uint64_t unk_70EC;                      /* 0x70EC */
    uint64_t unk_70F4;                      /* 0x70F4 */
    uint64_t unk_70FC;                      /* 0x70FC */
    uint64_t unk_7104;                      /* 0x7104 */
    uint64_t unk_710C;                      /* 0x710C */
    uint64_t unk_7114;                      /* 0x7114 */
    uint32_t unk_711C;                      /* 0x711C */
    uint32_t unk_7120;                      /* 0x7120 */
    uint64_t unk_7124;                      /* 0x7124 */
    uint64_t unk_712C;                      /* 0x712C */
    uint32_t unk_7134;                      /* 0x7134 */
    uint32_t unk_7138;                      /* 0x7138 */
    uint8_t pad_713C[8];                    /* 0x713C padding */
    uint32_t unk_7144;                      /* 0x7144 */
    uint8_t pad_7148[8];                    /* 0x7148 padding */
    uint32_t unk_7150;                      /* 0x7150 */
    uint8_t pad_7154[16];                   /* 0x7154 padding */
    uint32_t unk_7164;                      /* 0x7164 */
    uint8_t pad_7168[64];                   /* 0x7168 padding */
    uint32_t unk_71A8;                      /* 0x71A8 */
    uint8_t pad_71AC[76];                   /* 0x71AC padding */
    uint64_t unk_71F8;                      /* 0x71F8 */
    uint8_t pad_7200[8];                    /* 0x7200 padding */
    uint32_t unk_7208;                      /* 0x7208 */
    uint8_t pad_720C[10516];                /* 0x720C padding */
    uint64_t unk_9B20;                      /* 0x9B20 */
    uint8_t pad_9B28[5320];                 /* 0x9B28 padding */
    uint64_t unk_AFF0;                      /* 0xAFF0 */
    uint8_t pad_AFF8[5320];                 /* 0xAFF8 padding */
    uint64_t unk_C4C0;                      /* 0xC4C0 */
    uint8_t pad_C4C8[5328];                 /* 0xC4C8 padding */
    uint64_t unk_D998;                      /* 0xD998 */
    uint8_t pad_D9A0[5328];                 /* 0xD9A0 padding */
    uint64_t unk_EE70;                      /* 0xEE70 */
    uint8_t pad_EE78[5344];                 /* 0xEE78 padding */
    uint64_t unk_10358;                     /* 0x10358 */
    uint8_t pad_10360[5328];                /* 0x10360 padding */
    uint64_t unk_11830;                     /* 0x11830 */
    uint8_t pad_11838[5352];                /* 0x11838 padding */
    uint64_t unk_12D20;                     /* 0x12D20 */
    uint8_t pad_12D28[5320];                /* 0x12D28 padding */
    uint64_t unk_141F0;                     /* 0x141F0 */
    uint8_t pad_141F8[5336];                /* 0x141F8 padding */
    uint64_t unk_156D0;                     /* 0x156D0 */
    uint8_t pad_156D8[5320];                /* 0x156D8 padding */
    uint64_t unk_16BA0;                     /* 0x16BA0 */
    uint8_t pad_16BA8[5328];                /* 0x16BA8 padding */
    uint64_t unk_18078;                     /* 0x18078 */
    uint8_t pad_18080[5328];                /* 0x18080 padding */
    uint64_t unk_19550;                     /* 0x19550 */
    uint8_t pad_19558[5328];                /* 0x19558 padding */
    uint64_t unk_1AA28;                     /* 0x1AA28 */
    uint8_t pad_1AA30[8];                   /* 0x1AA30 padding */
    uint32_t unk_1AA38;                     /* 0x1AA38 */
    uint8_t pad_1AA3C[76];                  /* 0x1AA3C padding */
    uint64_t unk_1AA88;                     /* 0x1AA88 */
    uint8_t pad_1AA90[8];                   /* 0x1AA90 padding */
    uint32_t unk_1AA98;                     /* 0x1AA98 */
    uint8_t pad_1AA9C[10516];               /* 0x1AA9C padding */
    uint64_t unk_1D3B0;                     /* 0x1D3B0 */
    uint8_t pad_1D3B8[5328];                /* 0x1D3B8 padding */
    uint64_t unk_1E888;                     /* 0x1E888 */
    uint8_t pad_1E890[5352];                /* 0x1E890 padding */
    uint64_t unk_1FD78;                     /* 0x1FD78 */
    uint8_t pad_1FD80[5344];                /* 0x1FD80 padding */
    uint64_t unk_21260;                     /* 0x21260 */
    uint8_t pad_21268[5360];                /* 0x21268 padding */
    uint64_t unk_22758;                     /* 0x22758 */
    uint8_t pad_22760[5328];                /* 0x22760 padding */
    uint64_t unk_23C30;                     /* 0x23C30 */
    uint8_t pad_23C38[5328];                /* 0x23C38 padding */
    uint64_t unk_25108;                     /* 0x25108 */
    uint8_t pad_25110[16];                  /* 0x25110 padding */
    uint32_t unk_25120;                     /* 0x25120 */
    uint8_t pad_25124[10612];               /* 0x25124 padding */
    uint64_t unk_27A98;                     /* 0x27A98 */
    uint8_t pad_27AA0[5320];                /* 0x27AA0 padding */
    uint64_t unk_28F68;                     /* 0x28F68 */
    uint8_t pad_28F70[24];                  /* 0x28F70 padding */
    uint32_t unk_28F88;                     /* 0x28F88 */
    uint8_t pad_28F8C[60];                  /* 0x28F8C padding */
    uint64_t unk_28FC8;                     /* 0x28FC8 */
    uint64_t unk_28FD0;                     /* 0x28FD0 */
    uint64_t unk_28FD8;                     /* 0x28FD8 */
    uint64_t unk_28FE0;                     /* 0x28FE0 */
} ccBoss0800;
#pragma pack(pop)

static_assert(offsetof(ccBoss0800, vtable) == 0x0000, "ccBoss0800.vtable offset mismatch");
static_assert(offsetof(ccBoss0800, unk_00C0) == 0x00C0, "ccBoss0800.unk_00C0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_0200) == 0x0200, "ccBoss0800.unk_0200 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_0218) == 0x0218, "ccBoss0800.unk_0218 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_0240) == 0x0240, "ccBoss0800.unk_0240 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_0380) == 0x0380, "ccBoss0800.unk_0380 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_0600) == 0x0600, "ccBoss0800.unk_0600 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1D40) == 0x1D40, "ccBoss0800.unk_1D40 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1D80) == 0x1D80, "ccBoss0800.unk_1D80 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_2540) == 0x2540, "ccBoss0800.unk_2540 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5E70) == 0x5E70, "ccBoss0800.unk_5E70 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5EC8) == 0x5EC8, "ccBoss0800.unk_5EC8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5ED0) == 0x5ED0, "ccBoss0800.unk_5ED0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5EF0) == 0x5EF0, "ccBoss0800.unk_5EF0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5F50) == 0x5F50, "ccBoss0800.unk_5F50 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5F58) == 0x5F58, "ccBoss0800.unk_5F58 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5F78) == 0x5F78, "ccBoss0800.unk_5F78 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5FD8) == 0x5FD8, "ccBoss0800.unk_5FD8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_5FE0) == 0x5FE0, "ccBoss0800.unk_5FE0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_6038) == 0x6038, "ccBoss0800.unk_6038 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_6F68) == 0x6F68, "ccBoss0800.unk_6F68 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70A0) == 0x70A0, "ccBoss0800.unk_70A0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70A8) == 0x70A8, "ccBoss0800.unk_70A8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70B0) == 0x70B0, "ccBoss0800.unk_70B0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70B8) == 0x70B8, "ccBoss0800.unk_70B8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70C0) == 0x70C0, "ccBoss0800.unk_70C0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70C8) == 0x70C8, "ccBoss0800.unk_70C8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70CC) == 0x70CC, "ccBoss0800.unk_70CC offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70D4) == 0x70D4, "ccBoss0800.unk_70D4 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70DC) == 0x70DC, "ccBoss0800.unk_70DC offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70E4) == 0x70E4, "ccBoss0800.unk_70E4 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70EC) == 0x70EC, "ccBoss0800.unk_70EC offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70F4) == 0x70F4, "ccBoss0800.unk_70F4 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_70FC) == 0x70FC, "ccBoss0800.unk_70FC offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7104) == 0x7104, "ccBoss0800.unk_7104 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_710C) == 0x710C, "ccBoss0800.unk_710C offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7114) == 0x7114, "ccBoss0800.unk_7114 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_711C) == 0x711C, "ccBoss0800.unk_711C offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7120) == 0x7120, "ccBoss0800.unk_7120 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7124) == 0x7124, "ccBoss0800.unk_7124 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_712C) == 0x712C, "ccBoss0800.unk_712C offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7134) == 0x7134, "ccBoss0800.unk_7134 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7138) == 0x7138, "ccBoss0800.unk_7138 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7144) == 0x7144, "ccBoss0800.unk_7144 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7150) == 0x7150, "ccBoss0800.unk_7150 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7164) == 0x7164, "ccBoss0800.unk_7164 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_71A8) == 0x71A8, "ccBoss0800.unk_71A8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_71F8) == 0x71F8, "ccBoss0800.unk_71F8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_7208) == 0x7208, "ccBoss0800.unk_7208 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_9B20) == 0x9B20, "ccBoss0800.unk_9B20 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_AFF0) == 0xAFF0, "ccBoss0800.unk_AFF0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_C4C0) == 0xC4C0, "ccBoss0800.unk_C4C0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_D998) == 0xD998, "ccBoss0800.unk_D998 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_EE70) == 0xEE70, "ccBoss0800.unk_EE70 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_10358) == 0x10358, "ccBoss0800.unk_10358 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_11830) == 0x11830, "ccBoss0800.unk_11830 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_12D20) == 0x12D20, "ccBoss0800.unk_12D20 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_141F0) == 0x141F0, "ccBoss0800.unk_141F0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_156D0) == 0x156D0, "ccBoss0800.unk_156D0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_16BA0) == 0x16BA0, "ccBoss0800.unk_16BA0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_18078) == 0x18078, "ccBoss0800.unk_18078 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_19550) == 0x19550, "ccBoss0800.unk_19550 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1AA28) == 0x1AA28, "ccBoss0800.unk_1AA28 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1AA38) == 0x1AA38, "ccBoss0800.unk_1AA38 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1AA88) == 0x1AA88, "ccBoss0800.unk_1AA88 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1AA98) == 0x1AA98, "ccBoss0800.unk_1AA98 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1D3B0) == 0x1D3B0, "ccBoss0800.unk_1D3B0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1E888) == 0x1E888, "ccBoss0800.unk_1E888 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_1FD78) == 0x1FD78, "ccBoss0800.unk_1FD78 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_21260) == 0x21260, "ccBoss0800.unk_21260 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_22758) == 0x22758, "ccBoss0800.unk_22758 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_23C30) == 0x23C30, "ccBoss0800.unk_23C30 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_25108) == 0x25108, "ccBoss0800.unk_25108 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_25120) == 0x25120, "ccBoss0800.unk_25120 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_27A98) == 0x27A98, "ccBoss0800.unk_27A98 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28F68) == 0x28F68, "ccBoss0800.unk_28F68 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28F88) == 0x28F88, "ccBoss0800.unk_28F88 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28FC8) == 0x28FC8, "ccBoss0800.unk_28FC8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28FD0) == 0x28FD0, "ccBoss0800.unk_28FD0 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28FD8) == 0x28FD8, "ccBoss0800.unk_28FD8 offset mismatch");
static_assert(offsetof(ccBoss0800, unk_28FE0) == 0x28FE0, "ccBoss0800.unk_28FE0 offset mismatch");


/*
 * ccBoss0800ObjectBase — INFERRED from state_surface (23 seeds, 18 fields)
 * Object size: unknown, >= 0x3C8
 */
#pragma pack(push, 1)
typedef struct ccBoss0800ObjectBase {
    uint8_t pad_0000[152];             /* 0x0000 padding */
    uint64_t unk_0098;                 /* 0x0098 */
    uint64_t unk_00A0;                 /* 0x00A0 */
    uint8_t pad_00A8[4];               /* 0x00A8 padding */
    uint64_t unk_00AC;                 /* 0x00AC */
    uint8_t pad_00B4[4];               /* 0x00B4 padding */
    uint64_t unk_00B8;                 /* 0x00B8 */
    uint8_t pad_00C0[4];               /* 0x00C0 padding */
    uint64_t unk_00C4;                 /* 0x00C4 */
    uint8_t pad_00CC[4];               /* 0x00CC padding */
    uint64_t unk_00D0;                 /* 0x00D0 */
    uint8_t pad_00D8[4];               /* 0x00D8 padding */
    uint64_t unk_00DC;                 /* 0x00DC */
    uint32_t unk_00E4;                 /* 0x00E4 */
    uint32_t unk_00E8;                 /* 0x00E8 */
    uint64_t unk_00EC;                 /* 0x00EC */
    uint64_t unk_00F4;                 /* 0x00F4 */
    uint64_t unk_00FC;                 /* 0x00FC */
    uint32_t unk_0104;                 /* 0x0104 */
    uint8_t pad_0108[8];               /* 0x0108 padding */
    uint64_t unk_0110;                 /* 0x0110 */
    uint8_t pad_0118[424];             /* 0x0118 padding */
    uint64_t unk_02C0;                 /* 0x02C0 */
    uint8_t pad_02C8[56];              /* 0x02C8 padding */
    uint64_t unk_0300;                 /* 0x0300 */
    uint8_t pad_0308[120];             /* 0x0308 padding */
    uint64_t unk_0380;                 /* 0x0380 */
    uint8_t pad_0388[56];              /* 0x0388 padding */
    uint64_t unk_03C0;                 /* 0x03C0 */
} ccBoss0800ObjectBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss0800ObjectBase, unk_0098) == 0x0098, "ccBoss0800ObjectBase.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00A0) == 0x00A0, "ccBoss0800ObjectBase.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00AC) == 0x00AC, "ccBoss0800ObjectBase.unk_00AC offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00B8) == 0x00B8, "ccBoss0800ObjectBase.unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00C4) == 0x00C4, "ccBoss0800ObjectBase.unk_00C4 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00D0) == 0x00D0, "ccBoss0800ObjectBase.unk_00D0 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00DC) == 0x00DC, "ccBoss0800ObjectBase.unk_00DC offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00E4) == 0x00E4, "ccBoss0800ObjectBase.unk_00E4 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00E8) == 0x00E8, "ccBoss0800ObjectBase.unk_00E8 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00EC) == 0x00EC, "ccBoss0800ObjectBase.unk_00EC offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00F4) == 0x00F4, "ccBoss0800ObjectBase.unk_00F4 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_00FC) == 0x00FC, "ccBoss0800ObjectBase.unk_00FC offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_0104) == 0x0104, "ccBoss0800ObjectBase.unk_0104 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_0110) == 0x0110, "ccBoss0800ObjectBase.unk_0110 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_02C0) == 0x02C0, "ccBoss0800ObjectBase.unk_02C0 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_0300) == 0x0300, "ccBoss0800ObjectBase.unk_0300 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_0380) == 0x0380, "ccBoss0800ObjectBase.unk_0380 offset mismatch");
static_assert(offsetof(ccBoss0800ObjectBase, unk_03C0) == 0x03C0, "ccBoss0800ObjectBase.unk_03C0 offset mismatch");


/*
 * ccBoss0800BirdAttackRush — INFERRED from state_surface (20 seeds, 2 fields)
 * Object size: unknown, >= 0x14C8
 */
#pragma pack(push, 1)
typedef struct ccBoss0800BirdAttackRush {
    uint8_t pad_0000[5304];            /* 0x0000 padding */
    uint64_t unk_14B8;                 /* 0x14B8 */
    uint64_t unk_14C0;                 /* 0x14C0 */
} ccBoss0800BirdAttackRush;
#pragma pack(pop)

static_assert(offsetof(ccBoss0800BirdAttackRush, unk_14B8) == 0x14B8, "ccBoss0800BirdAttackRush.unk_14B8 offset mismatch");
static_assert(offsetof(ccBoss0800BirdAttackRush, unk_14C0) == 0x14C0, "ccBoss0800BirdAttackRush.unk_14C0 offset mismatch");


/*
 * ccBoss0800DamageObject — INFERRED from state_surface (18 seeds, 24 fields)
 * Object size: unknown, >= 0x348
 */
#pragma pack(push, 1)
typedef struct ccBoss0800DamageObject {
    uint8_t pad_0000[152];             /* 0x0000 padding */
    uint64_t unk_0098;                 /* 0x0098 */
    uint64_t unk_00A0;                 /* 0x00A0 */
    uint64_t unk_00A8;                 /* 0x00A8 */
    uint64_t unk_00B0;                 /* 0x00B0 */
    uint64_t unk_00B8;                 /* 0x00B8 */
    uint8_t pad_00C0[4];               /* 0x00C0 padding */
    uint64_t unk_00C4;                 /* 0x00C4 */
    uint8_t pad_00CC[4];               /* 0x00CC padding */
    uint64_t unk_00D0;                 /* 0x00D0 */
    uint8_t pad_00D8[4];               /* 0x00D8 padding */
    uint64_t unk_00DC;                 /* 0x00DC */
    uint8_t pad_00E4[4];               /* 0x00E4 padding */
    uint64_t unk_00E8;                 /* 0x00E8 */
    uint8_t pad_00F0[4];               /* 0x00F0 padding */
    uint64_t unk_00F4;                 /* 0x00F4 */
    uint8_t pad_00FC[4];               /* 0x00FC padding */
    uint64_t unk_0100;                 /* 0x0100 */
    uint8_t pad_0108[4];               /* 0x0108 padding */
    uint64_t unk_010C;                 /* 0x010C */
    uint32_t unk_0114;                 /* 0x0114 */
    uint32_t unk_0118;                 /* 0x0118 */
    uint32_t unk_011C;                 /* 0x011C */
    uint32_t unk_0120;                 /* 0x0120 */
    uint32_t unk_0124;                 /* 0x0124 */
    uint8_t pad_0128[8];               /* 0x0128 padding */
    uint32_t unk_0130;                 /* 0x0130 */
    uint32_t unk_0134;                 /* 0x0134 */
    uint64_t unk_0138;                 /* 0x0138 */
    uint64_t unk_0140;                 /* 0x0140 */
    uint32_t unk_0148;                 /* 0x0148 */
    uint8_t pad_014C[244];             /* 0x014C padding */
    uint64_t unk_0240;                 /* 0x0240 */
    uint8_t pad_0248[248];             /* 0x0248 padding */
    uint64_t unk_0340;                 /* 0x0340 */
} ccBoss0800DamageObject;
#pragma pack(pop)

static_assert(offsetof(ccBoss0800DamageObject, unk_0098) == 0x0098, "ccBoss0800DamageObject.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00A0) == 0x00A0, "ccBoss0800DamageObject.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00A8) == 0x00A8, "ccBoss0800DamageObject.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00B0) == 0x00B0, "ccBoss0800DamageObject.unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00B8) == 0x00B8, "ccBoss0800DamageObject.unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00C4) == 0x00C4, "ccBoss0800DamageObject.unk_00C4 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00D0) == 0x00D0, "ccBoss0800DamageObject.unk_00D0 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00DC) == 0x00DC, "ccBoss0800DamageObject.unk_00DC offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00E8) == 0x00E8, "ccBoss0800DamageObject.unk_00E8 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_00F4) == 0x00F4, "ccBoss0800DamageObject.unk_00F4 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0100) == 0x0100, "ccBoss0800DamageObject.unk_0100 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_010C) == 0x010C, "ccBoss0800DamageObject.unk_010C offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0114) == 0x0114, "ccBoss0800DamageObject.unk_0114 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0118) == 0x0118, "ccBoss0800DamageObject.unk_0118 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_011C) == 0x011C, "ccBoss0800DamageObject.unk_011C offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0120) == 0x0120, "ccBoss0800DamageObject.unk_0120 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0124) == 0x0124, "ccBoss0800DamageObject.unk_0124 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0130) == 0x0130, "ccBoss0800DamageObject.unk_0130 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0134) == 0x0134, "ccBoss0800DamageObject.unk_0134 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0138) == 0x0138, "ccBoss0800DamageObject.unk_0138 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0140) == 0x0140, "ccBoss0800DamageObject.unk_0140 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0148) == 0x0148, "ccBoss0800DamageObject.unk_0148 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0240) == 0x0240, "ccBoss0800DamageObject.unk_0240 offset mismatch");
static_assert(offsetof(ccBoss0800DamageObject, unk_0340) == 0x0340, "ccBoss0800DamageObject.unk_0340 offset mismatch");


/*
 * ccBoss0801JiraiyaOption — INFERRED from state_surface (18 seeds, 13 fields)
 * Object size: unknown, >= 0x118
 */
#pragma pack(push, 1)
typedef struct ccBoss0801JiraiyaOption {
    uint8_t pad_0000[152];             /* 0x0000 padding */
    uint64_t unk_0098;                 /* 0x0098 */
    uint32_t unk_00A0;                 /* 0x00A0 */
    uint64_t unk_00A4;                 /* 0x00A4 */
    uint32_t unk_00AC;                 /* 0x00AC */
    uint64_t unk_00B0;                 /* 0x00B0 */
    uint32_t unk_00B8;                 /* 0x00B8 */
    uint64_t unk_00BC;                 /* 0x00BC */
    uint32_t unk_00C4;                 /* 0x00C4 */
    uint64_t unk_00C8;                 /* 0x00C8 */
    uint32_t unk_00D0;                 /* 0x00D0 */
    uint8_t pad_00D4[4];               /* 0x00D4 padding */
    uint64_t unk_00D8;                 /* 0x00D8 */
    uint8_t pad_00E0[16];              /* 0x00E0 padding */
    uint64_t unk_00F0;                 /* 0x00F0 */
    uint8_t pad_00F8[28];              /* 0x00F8 padding */
    uint32_t unk_0114;                 /* 0x0114 */
} ccBoss0801JiraiyaOption;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801JiraiyaOption, unk_0098) == 0x0098, "ccBoss0801JiraiyaOption.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00A0) == 0x00A0, "ccBoss0801JiraiyaOption.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00A4) == 0x00A4, "ccBoss0801JiraiyaOption.unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00AC) == 0x00AC, "ccBoss0801JiraiyaOption.unk_00AC offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00B0) == 0x00B0, "ccBoss0801JiraiyaOption.unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00B8) == 0x00B8, "ccBoss0801JiraiyaOption.unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00BC) == 0x00BC, "ccBoss0801JiraiyaOption.unk_00BC offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00C4) == 0x00C4, "ccBoss0801JiraiyaOption.unk_00C4 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00C8) == 0x00C8, "ccBoss0801JiraiyaOption.unk_00C8 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00D0) == 0x00D0, "ccBoss0801JiraiyaOption.unk_00D0 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00D8) == 0x00D8, "ccBoss0801JiraiyaOption.unk_00D8 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_00F0) == 0x00F0, "ccBoss0801JiraiyaOption.unk_00F0 offset mismatch");
static_assert(offsetof(ccBoss0801JiraiyaOption, unk_0114) == 0x0114, "ccBoss0801JiraiyaOption.unk_0114 offset mismatch");


/*
 * ccBoss0801EventPeinActionState — INFERRED from state_surface (17 seeds, 6 fields)
 * Object size: unknown, >= 0x14E0
 */
#pragma pack(push, 1)
typedef struct ccBoss0801EventPeinActionState {
    uint8_t pad_0000[5304];            /* 0x0000 padding */
    uint32_t unk_14B8;                 /* 0x14B8 */
    uint32_t unk_14BC;                 /* 0x14BC */
    uint32_t unk_14C0;                 /* 0x14C0 */
    uint8_t pad_14C4[4];               /* 0x14C4 padding */
    uint32_t unk_14C8;                 /* 0x14C8 */
    uint8_t pad_14CC[4];               /* 0x14CC padding */
    uint64_t unk_14D0;                 /* 0x14D0 */
    uint64_t unk_14D8;                 /* 0x14D8 */
} ccBoss0801EventPeinActionState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14B8) == 0x14B8, "ccBoss0801EventPeinActionState.unk_14B8 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14BC) == 0x14BC, "ccBoss0801EventPeinActionState.unk_14BC offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14C0) == 0x14C0, "ccBoss0801EventPeinActionState.unk_14C0 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14C8) == 0x14C8, "ccBoss0801EventPeinActionState.unk_14C8 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14D0) == 0x14D0, "ccBoss0801EventPeinActionState.unk_14D0 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinActionState, unk_14D8) == 0x14D8, "ccBoss0801EventPeinActionState.unk_14D8 offset mismatch");


/*
 * ccBoss0801EventPeinManager — INFERRED from state_surface (16 seeds, 4 fields)
 * Object size: unknown, >= 0x9C
 */
#pragma pack(push, 1)
typedef struct ccBoss0801EventPeinManager {
    uint8_t pad_0000[88];              /* 0x0000 padding */
    uint64_t unk_0058;                 /* 0x0058 */
    uint8_t pad_0060[24];              /* 0x0060 padding */
    uint64_t unk_0078;                 /* 0x0078 */
    uint8_t pad_0080[12];              /* 0x0080 padding */
    uint64_t unk_008C;                 /* 0x008C */
    uint8_t pad_0094[4];               /* 0x0094 padding */
    uint32_t unk_0098;                 /* 0x0098 */
} ccBoss0801EventPeinManager;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801EventPeinManager, unk_0058) == 0x0058, "ccBoss0801EventPeinManager.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinManager, unk_0078) == 0x0078, "ccBoss0801EventPeinManager.unk_0078 offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinManager, unk_008C) == 0x008C, "ccBoss0801EventPeinManager.unk_008C offset mismatch");
static_assert(offsetof(ccBoss0801EventPeinManager, unk_0098) == 0x0098, "ccBoss0801EventPeinManager.unk_0098 offset mismatch");


/* ccBoss0800CrabGroundAttackClaws: no instance state (14 seeds, 0 fields) */


/*
 * ccBoss0801SupportFukasaku — INFERRED from state_surface (12 seeds, 23 fields)
 * Object size: unknown, >= 0x8C7C
 */
#pragma pack(push, 1)
typedef struct ccBoss0801SupportFukasaku {
    uint8_t pad_0000[2104];            /* 0x0000 padding */
    uint32_t unk_0838;                 /* 0x0838 */
    uint8_t pad_083C[12356];           /* 0x083C padding */
    uint64_t unk_3880;                 /* 0x3880 */
    uint8_t pad_3888[14560];           /* 0x3888 padding */
    uint32_t unk_7168;                 /* 0x7168 */
    uint8_t pad_716C[4];               /* 0x716C padding */
    uint64_t unk_7170;                 /* 0x7170 */
    uint8_t pad_7178[76];              /* 0x7178 padding */
    uint32_t unk_71C4;                 /* 0x71C4 */
    uint8_t pad_71C8[8];               /* 0x71C8 padding */
    uint32_t unk_71D0;                 /* 0x71D0 */
    uint8_t pad_71D4[5204];            /* 0x71D4 padding */
    uint64_t unk_8628;                 /* 0x8628 */
    uint8_t pad_8630[968];             /* 0x8630 padding */
    uint64_t unk_89F8;                 /* 0x89F8 */
    uint8_t pad_8A00[80];              /* 0x8A00 padding */
    uint64_t unk_8A50;                 /* 0x8A50 */
    uint64_t unk_8A58;                 /* 0x8A58 */
    uint32_t unk_8A60;                 /* 0x8A60 */
    uint64_t unk_8A64;                 /* 0x8A64 */
    uint32_t unk_8A6C;                 /* 0x8A6C */
    uint64_t unk_8A70;                 /* 0x8A70 */
    uint8_t pad_8A78[12];              /* 0x8A78 padding */
    uint64_t unk_8A84;                 /* 0x8A84 */
    uint8_t pad_8A8C[60];              /* 0x8A8C padding */
    uint32_t unk_8AC8;                 /* 0x8AC8 */
    uint32_t unk_8ACC;                 /* 0x8ACC */
    uint64_t unk_8AD0;                 /* 0x8AD0 */
    uint64_t unk_8AD8;                 /* 0x8AD8 */
    uint32_t unk_8AE0;                 /* 0x8AE0 */
    uint8_t pad_8AE4[4];               /* 0x8AE4 padding */
    uint64_t unk_8AE8;                 /* 0x8AE8 */
    uint8_t pad_8AF0[152];             /* 0x8AF0 padding */
    uint64_t unk_8B88;                 /* 0x8B88 */
    uint8_t pad_8B90[232];             /* 0x8B90 padding */
    uint32_t unk_8C78;                 /* 0x8C78 */
} ccBoss0801SupportFukasaku;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801SupportFukasaku, unk_0838) == 0x0838, "ccBoss0801SupportFukasaku.unk_0838 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_3880) == 0x3880, "ccBoss0801SupportFukasaku.unk_3880 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_7168) == 0x7168, "ccBoss0801SupportFukasaku.unk_7168 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_7170) == 0x7170, "ccBoss0801SupportFukasaku.unk_7170 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_71C4) == 0x71C4, "ccBoss0801SupportFukasaku.unk_71C4 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_71D0) == 0x71D0, "ccBoss0801SupportFukasaku.unk_71D0 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8628) == 0x8628, "ccBoss0801SupportFukasaku.unk_8628 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_89F8) == 0x89F8, "ccBoss0801SupportFukasaku.unk_89F8 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A50) == 0x8A50, "ccBoss0801SupportFukasaku.unk_8A50 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A58) == 0x8A58, "ccBoss0801SupportFukasaku.unk_8A58 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A60) == 0x8A60, "ccBoss0801SupportFukasaku.unk_8A60 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A64) == 0x8A64, "ccBoss0801SupportFukasaku.unk_8A64 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A6C) == 0x8A6C, "ccBoss0801SupportFukasaku.unk_8A6C offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A70) == 0x8A70, "ccBoss0801SupportFukasaku.unk_8A70 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8A84) == 0x8A84, "ccBoss0801SupportFukasaku.unk_8A84 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8AC8) == 0x8AC8, "ccBoss0801SupportFukasaku.unk_8AC8 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8ACC) == 0x8ACC, "ccBoss0801SupportFukasaku.unk_8ACC offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8AD0) == 0x8AD0, "ccBoss0801SupportFukasaku.unk_8AD0 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8AD8) == 0x8AD8, "ccBoss0801SupportFukasaku.unk_8AD8 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8AE0) == 0x8AE0, "ccBoss0801SupportFukasaku.unk_8AE0 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8AE8) == 0x8AE8, "ccBoss0801SupportFukasaku.unk_8AE8 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8B88) == 0x8B88, "ccBoss0801SupportFukasaku.unk_8B88 offset mismatch");
static_assert(offsetof(ccBoss0801SupportFukasaku, unk_8C78) == 0x8C78, "ccBoss0801SupportFukasaku.unk_8C78 offset mismatch");


/*
 * ccBoss0801SupportShima — INFERRED from state_surface (11 seeds, 4 fields)
 * Object size: unknown, >= 0x7178
 */
#pragma pack(push, 1)
typedef struct ccBoss0801SupportShima {
    uint8_t pad_0000[2104];            /* 0x0000 padding */
    uint32_t unk_0838;                 /* 0x0838 */
    uint8_t pad_083C[12356];           /* 0x083C padding */
    uint64_t unk_3880;                 /* 0x3880 */
    uint8_t pad_3888[14560];           /* 0x3888 padding */
    uint8_t unk_7168;                  /* 0x7168 */
    uint8_t pad_7169[7];               /* 0x7169 padding */
    uint64_t unk_7170;                 /* 0x7170 */
} ccBoss0801SupportShima;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801SupportShima, unk_0838) == 0x0838, "ccBoss0801SupportShima.unk_0838 offset mismatch");
static_assert(offsetof(ccBoss0801SupportShima, unk_3880) == 0x3880, "ccBoss0801SupportShima.unk_3880 offset mismatch");
static_assert(offsetof(ccBoss0801SupportShima, unk_7168) == 0x7168, "ccBoss0801SupportShima.unk_7168 offset mismatch");
static_assert(offsetof(ccBoss0801SupportShima, unk_7170) == 0x7170, "ccBoss0801SupportShima.unk_7170 offset mismatch");


/*
 * ccBoss0802Jiraiya — INFERRED from state_surface (10 seeds, 13 fields)
 * Object size: unknown, >= 0x72A0
 */
#pragma pack(push, 1)
typedef struct ccBoss0802Jiraiya {
    uint8_t pad_0000[536];             /* 0x0000 padding */
    uint64_t unk_0218;                 /* 0x0218 */
    uint8_t pad_0220[352];             /* 0x0220 padding */
    uint64_t unk_0380;                 /* 0x0380 */
    uint8_t pad_0388[14968];           /* 0x0388 padding */
    uint64_t unk_3E00;                 /* 0x3E00 */
    uint8_t pad_3E08[12952];           /* 0x3E08 padding */
    uint64_t unk_70A0;                 /* 0x70A0 */
    uint8_t pad_70A8[16];              /* 0x70A8 padding */
    uint64_t unk_70B8;                 /* 0x70B8 */
    uint32_t unk_70C0;                 /* 0x70C0 */
    uint64_t unk_70C4;                 /* 0x70C4 */
    uint32_t unk_70CC;                 /* 0x70CC */
    uint8_t pad_70D0[8];               /* 0x70D0 padding */
    uint64_t unk_70D8;                 /* 0x70D8 */
    uint8_t pad_70E0[12];              /* 0x70E0 padding */
    uint64_t unk_70EC;                 /* 0x70EC */
    uint8_t pad_70F4[60];              /* 0x70F4 padding */
    uint32_t unk_7130;                 /* 0x7130 */
    uint8_t pad_7134[324];             /* 0x7134 padding */
    uint64_t unk_7278;                 /* 0x7278 */
    uint8_t pad_7280[24];              /* 0x7280 padding */
    uint64_t unk_7298;                 /* 0x7298 */
} ccBoss0802Jiraiya;
#pragma pack(pop)

static_assert(offsetof(ccBoss0802Jiraiya, unk_0218) == 0x0218, "ccBoss0802Jiraiya.unk_0218 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_0380) == 0x0380, "ccBoss0802Jiraiya.unk_0380 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_3E00) == 0x3E00, "ccBoss0802Jiraiya.unk_3E00 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70A0) == 0x70A0, "ccBoss0802Jiraiya.unk_70A0 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70B8) == 0x70B8, "ccBoss0802Jiraiya.unk_70B8 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70C0) == 0x70C0, "ccBoss0802Jiraiya.unk_70C0 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70C4) == 0x70C4, "ccBoss0802Jiraiya.unk_70C4 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70CC) == 0x70CC, "ccBoss0802Jiraiya.unk_70CC offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70D8) == 0x70D8, "ccBoss0802Jiraiya.unk_70D8 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_70EC) == 0x70EC, "ccBoss0802Jiraiya.unk_70EC offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_7130) == 0x7130, "ccBoss0802Jiraiya.unk_7130 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_7278) == 0x7278, "ccBoss0802Jiraiya.unk_7278 offset mismatch");
static_assert(offsetof(ccBoss0802Jiraiya, unk_7298) == 0x7298, "ccBoss0802Jiraiya.unk_7298 offset mismatch");


/*
 * ccBoss0802Pein — INFERRED from state_surface (10 seeds, 32 fields)
 * Object size: unknown, >= 0x72B0
 */
#pragma pack(push, 1)
typedef struct ccBoss0802Pein {
    uint8_t pad_0000[536];             /* 0x0000 padding */
    uint64_t unk_0218;                 /* 0x0218 */
    uint8_t pad_0220[9224];            /* 0x0220 padding */
    uint64_t unk_2628;                 /* 0x2628 */
    uint8_t pad_2630[6032];            /* 0x2630 padding */
    uint64_t unk_3DC0;                 /* 0x3DC0 */
    uint8_t pad_3DC8[56];              /* 0x3DC8 padding */
    uint64_t unk_3E00;                 /* 0x3E00 */
    uint8_t pad_3E08[8296];            /* 0x3E08 padding */
    uint64_t unk_5E70;                 /* 0x5E70 */
    uint8_t pad_5E78[80];              /* 0x5E78 padding */
    uint64_t unk_5EC8;                 /* 0x5EC8 */
    uint64_t unk_5ED0;                 /* 0x5ED0 */
    uint8_t pad_5ED8[24];              /* 0x5ED8 padding */
    uint64_t unk_5EF0;                 /* 0x5EF0 */
    uint8_t pad_5EF8[88];              /* 0x5EF8 padding */
    uint64_t unk_5F50;                 /* 0x5F50 */
    uint64_t unk_5F58;                 /* 0x5F58 */
    uint8_t pad_5F60[24];              /* 0x5F60 padding */
    uint64_t unk_5F78;                 /* 0x5F78 */
    uint8_t pad_5F80[88];              /* 0x5F80 padding */
    uint64_t unk_5FD8;                 /* 0x5FD8 */
    uint64_t unk_5FE0;                 /* 0x5FE0 */
    uint8_t pad_5FE8[4280];            /* 0x5FE8 padding */
    uint64_t unk_70A0;                 /* 0x70A0 */
    uint32_t unk_70A8;                 /* 0x70A8 */
    uint8_t pad_70AC[12];              /* 0x70AC padding */
    uint64_t unk_70B8;                 /* 0x70B8 */
    uint32_t unk_70C0;                 /* 0x70C0 */
    uint64_t unk_70C4;                 /* 0x70C4 */
    uint32_t unk_70CC;                 /* 0x70CC */
    uint8_t pad_70D0[8];               /* 0x70D0 padding */
    uint64_t unk_70D8;                 /* 0x70D8 */
    uint8_t pad_70E0[12];              /* 0x70E0 padding */
    uint64_t unk_70EC;                 /* 0x70EC */
    uint8_t pad_70F4[60];              /* 0x70F4 padding */
    uint32_t unk_7130;                 /* 0x7130 */
    uint8_t pad_7134[324];             /* 0x7134 padding */
    uint64_t unk_7278;                 /* 0x7278 */
    uint64_t unk_7280;                 /* 0x7280 */
    uint32_t unk_7288;                 /* 0x7288 */
    uint32_t unk_728C;                 /* 0x728C */
    uint64_t unk_7290;                 /* 0x7290 */
    uint32_t unk_7298;                 /* 0x7298 */
    uint32_t unk_729C;                 /* 0x729C */
    uint32_t unk_72A0;                 /* 0x72A0 */
    uint32_t unk_72A4;                 /* 0x72A4 */
    uint64_t unk_72A8;                 /* 0x72A8 */
} ccBoss0802Pein;
#pragma pack(pop)

static_assert(offsetof(ccBoss0802Pein, unk_0218) == 0x0218, "ccBoss0802Pein.unk_0218 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_2628) == 0x2628, "ccBoss0802Pein.unk_2628 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_3DC0) == 0x3DC0, "ccBoss0802Pein.unk_3DC0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_3E00) == 0x3E00, "ccBoss0802Pein.unk_3E00 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5E70) == 0x5E70, "ccBoss0802Pein.unk_5E70 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5EC8) == 0x5EC8, "ccBoss0802Pein.unk_5EC8 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5ED0) == 0x5ED0, "ccBoss0802Pein.unk_5ED0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5EF0) == 0x5EF0, "ccBoss0802Pein.unk_5EF0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5F50) == 0x5F50, "ccBoss0802Pein.unk_5F50 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5F58) == 0x5F58, "ccBoss0802Pein.unk_5F58 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5F78) == 0x5F78, "ccBoss0802Pein.unk_5F78 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5FD8) == 0x5FD8, "ccBoss0802Pein.unk_5FD8 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_5FE0) == 0x5FE0, "ccBoss0802Pein.unk_5FE0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70A0) == 0x70A0, "ccBoss0802Pein.unk_70A0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70A8) == 0x70A8, "ccBoss0802Pein.unk_70A8 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70B8) == 0x70B8, "ccBoss0802Pein.unk_70B8 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70C0) == 0x70C0, "ccBoss0802Pein.unk_70C0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70C4) == 0x70C4, "ccBoss0802Pein.unk_70C4 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70CC) == 0x70CC, "ccBoss0802Pein.unk_70CC offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70D8) == 0x70D8, "ccBoss0802Pein.unk_70D8 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_70EC) == 0x70EC, "ccBoss0802Pein.unk_70EC offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7130) == 0x7130, "ccBoss0802Pein.unk_7130 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7278) == 0x7278, "ccBoss0802Pein.unk_7278 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7280) == 0x7280, "ccBoss0802Pein.unk_7280 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7288) == 0x7288, "ccBoss0802Pein.unk_7288 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_728C) == 0x728C, "ccBoss0802Pein.unk_728C offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7290) == 0x7290, "ccBoss0802Pein.unk_7290 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_7298) == 0x7298, "ccBoss0802Pein.unk_7298 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_729C) == 0x729C, "ccBoss0802Pein.unk_729C offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_72A0) == 0x72A0, "ccBoss0802Pein.unk_72A0 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_72A4) == 0x72A4, "ccBoss0802Pein.unk_72A4 offset mismatch");
static_assert(offsetof(ccBoss0802Pein, unk_72A8) == 0x72A8, "ccBoss0802Pein.unk_72A8 offset mismatch");


/*
 * ccBoss0800Bird — INFERRED from state_surface (9 seeds, 7 fields)
 * Object size: unknown, >= 0x208
 */
#pragma pack(push, 1)
typedef struct ccBoss0800Bird {
    uint8_t pad_0000[152];             /* 0x0000 padding */
    uint64_t unk_0098;                 /* 0x0098 */
    uint8_t pad_00A0[144];             /* 0x00A0 padding */
    uint32_t unk_0130;                 /* 0x0130 */
    uint16_t unk_0134;                 /* 0x0134 */
    uint8_t pad_0136[2];               /* 0x0136 padding */
    uint64_t unk_0138;                 /* 0x0138 */
    uint64_t unk_0140;                 /* 0x0140 */
    uint64_t unk_0148;                 /* 0x0148 */
    uint8_t pad_0150[176];             /* 0x0150 padding */
    uint64_t unk_0200;                 /* 0x0200 */
} ccBoss0800Bird;
#pragma pack(pop)

static_assert(offsetof(ccBoss0800Bird, unk_0098) == 0x0098, "ccBoss0800Bird.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0130) == 0x0130, "ccBoss0800Bird.unk_0130 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0134) == 0x0134, "ccBoss0800Bird.unk_0134 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0138) == 0x0138, "ccBoss0800Bird.unk_0138 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0140) == 0x0140, "ccBoss0800Bird.unk_0140 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0148) == 0x0148, "ccBoss0800Bird.unk_0148 offset mismatch");
static_assert(offsetof(ccBoss0800Bird, unk_0200) == 0x0200, "ccBoss0800Bird.unk_0200 offset mismatch");


/*
 * ccBoss0800BirdAttackRushDirecSuccess — INFERRED from state_surface (9 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * This class likely operates entirely through a parent pointer or has no persistent state.
 */

/*
 * ccBoss0800CrabAquaticBodyPress — INFERRED from state_surface (8 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * This class likely operates entirely through a parent pointer or has no persistent state.
 */

/*
 * ccSceneBoss08Phase01 — INFERRED from state_surface (8 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Scene phase controller with no direct member access detected.
 */

/*
 * ccSceneBoss08Phase03 — INFERRED from state_surface (8 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Scene phase controller with no direct member access detected.
 */

/*
 * ccBoss0800CrabGroundChangeAquatic — INFERRED from state_surface (7 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * State transition handler with no persistent member data.
 */

/*
 * ccBoss0801EventJiraiyaEx — INFERRED from state_surface (7 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Event/demo controller with no direct member access detected.
 */

/*
 * ccSceneBoss08PhaseDrama — INFERRED from state_surface (7 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Drama/cutscene phase controller with no direct member access detected.
 */

/*
 * ccBoss0802JiraiyaProstrateAction — INFERRED from state_surface (6 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Prostrate action handler with no persistent member data.
 */

/*
 * ccBoss0800CrabAquaticBreath — INFERRED from state_surface (5 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Breath attack effect handler with no persistent member data.
 */

/*
 * ccBoss0802JiraiyaActionState — INFERRED from state_surface (8 seeds, 2 fields)
 * Object size: unknown, >= 0x1890
 */
#pragma pack(push, 1)
typedef struct ccBoss0802JiraiyaActionState {
    uint8_t pad_0000[5304];            /* 0x0000 padding */
    uint64_t unk_14B8;                 /* 0x14B8 rw */
    uint8_t pad_14C0[968];             /* 0x14C0 padding */
    uint64_t unk_1888;                 /* 0x1888 r (size unknown) */
} ccBoss0802JiraiyaActionState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0802JiraiyaActionState, unk_14B8) == 0x14B8, "ccBoss0802JiraiyaActionState.unk_14B8 offset mismatch");
static_assert(offsetof(ccBoss0802JiraiyaActionState, unk_1888) == 0x1888, "ccBoss0802JiraiyaActionState.unk_1888 offset mismatch");


/*
 * ccBoss0802PeinActionState — INFERRED from state_surface (7 seeds, 3 fields)
 * Object size: unknown, >= 0x14C8
 */
#pragma pack(push, 1)
typedef struct ccBoss0802PeinActionState {
    uint8_t pad_0000[5304];            /* 0x0000 padding */
    uint32_t unk_14B8;                 /* 0x14B8 w */
    uint32_t unk_14BC;                 /* 0x14BC w */
    uint64_t unk_14C0;                 /* 0x14C0 r (size unknown) */
} ccBoss0802PeinActionState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0802PeinActionState, unk_14B8) == 0x14B8, "ccBoss0802PeinActionState.unk_14B8 offset mismatch");
static_assert(offsetof(ccBoss0802PeinActionState, unk_14BC) == 0x14BC, "ccBoss0802PeinActionState.unk_14BC offset mismatch");
static_assert(offsetof(ccBoss0802PeinActionState, unk_14C0) == 0x14C0, "ccBoss0802PeinActionState.unk_14C0 offset mismatch");


/*
 * ccBoss0801CamOpeType01 — INFERRED from state_surface (5 seeds, 7 fields)
 * Object size: unknown, >= 0x218
 */
#pragma pack(push, 1)
typedef struct ccBoss0801CamOpeType01 {
    uint8_t pad_0000[176];             /* 0x0000 padding */
    uint8_t unk_00B0;                  /* 0x00B0 r (size unknown, placeholder) */
    uint8_t pad_00B1[79];              /* 0x00B1 padding */
    uint8_t unk_0100;                  /* 0x0100 r (size unknown, placeholder) */
    uint8_t pad_0101[175];             /* 0x0101 padding */
    uint8_t unk_01B0;                  /* 0x01B0 r (size unknown, placeholder) */
    uint8_t pad_01B1[87];              /* 0x01B1 padding */
    uint32_t unk_0208;                 /* 0x0208 w (float or uint32) */
    uint32_t unk_020C;                 /* 0x020C w */
    uint32_t unk_0210;                 /* 0x0210 rw */
    uint32_t unk_0214;                 /* 0x0214 rw */
} ccBoss0801CamOpeType01;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801CamOpeType01, unk_00B0) == 0x00B0, "ccBoss0801CamOpeType01.unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_0100) == 0x0100, "ccBoss0801CamOpeType01.unk_0100 offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_01B0) == 0x01B0, "ccBoss0801CamOpeType01.unk_01B0 offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_0208) == 0x0208, "ccBoss0801CamOpeType01.unk_0208 offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_020C) == 0x020C, "ccBoss0801CamOpeType01.unk_020C offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_0210) == 0x0210, "ccBoss0801CamOpeType01.unk_0210 offset mismatch");
static_assert(offsetof(ccBoss0801CamOpeType01, unk_0214) == 0x0214, "ccBoss0801CamOpeType01.unk_0214 offset mismatch");


/*
 * ccBoss0801PeinStunCommand — INFERRED from state_surface (5 seeds, 7 fields)
 * Object size: unknown, >= 0x100
 */
#pragma pack(push, 1)
typedef struct ccBoss0801PeinStunCommand {
    uint8_t pad_0000[152];             /* 0x0000 padding */
    uint64_t unk_0098;                 /* 0x0098 w */
    uint64_t unk_00A0;                 /* 0x00A0 w */
    uint64_t unk_00A8;                 /* 0x00A8 w */
    uint64_t unk_00B0;                 /* 0x00B0 w */
    uint8_t unk_00B8;                  /* 0x00B8 r (size unknown, placeholder) */
    uint8_t pad_00B9[55];              /* 0x00B9 padding */
    uint64_t unk_00F0;                 /* 0x00F0 w */
    uint32_t unk_00F8;                 /* 0x00F8 w */
} ccBoss0801PeinStunCommand;
#pragma pack(pop)

static_assert(offsetof(ccBoss0801PeinStunCommand, unk_0098) == 0x0098, "ccBoss0801PeinStunCommand.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00A0) == 0x00A0, "ccBoss0801PeinStunCommand.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00A8) == 0x00A8, "ccBoss0801PeinStunCommand.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00B0) == 0x00B0, "ccBoss0801PeinStunCommand.unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00B8) == 0x00B8, "ccBoss0801PeinStunCommand.unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00F0) == 0x00F0, "ccBoss0801PeinStunCommand.unk_00F0 offset mismatch");
static_assert(offsetof(ccBoss0801PeinStunCommand, unk_00F8) == 0x00F8, "ccBoss0801PeinStunCommand.unk_00F8 offset mismatch");


/*
 * ccBoss0802PeinWaitBackward — INFERRED from state_surface (5 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Wait-backward action handler with no persistent member data.
 */

/*
 * ccSceneBoss08PhaseDramaIA — INFERRED from state_surface (5 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Drama/cutscene IA phase controller with no persistent member data.
 */

/*
 * ccUiBoss08Gauge — INFERRED from state_surface (5 seeds, 9 fields)
 * Object size: unknown, >= 0x8B0
 */
#pragma pack(push, 1)
typedef struct ccUiBoss08Gauge {
    uint8_t pad_0000[2104];            /* 0x0000 padding */
    uint8_t unk_0838;                  /* 0x0838 r (size unknown, placeholder) */
    uint8_t pad_0839[55];              /* 0x0839 padding */
    uint32_t unk_0870;                 /* 0x0870 w */
    uint8_t unk_0874;                  /* 0x0874 r (size unknown, placeholder) */
    uint8_t pad_0875[11];              /* 0x0875 padding */
    uint8_t unk_0880;                  /* 0x0880 r (size unknown, placeholder) */
    uint8_t pad_0881[11];              /* 0x0881 padding */
    uint32_t unk_088C;                 /* 0x088C w */
    uint64_t unk_0890;                 /* 0x0890 w */
    uint64_t unk_0898;                 /* 0x0898 w */
    uint64_t unk_08A0;                 /* 0x08A0 w */
    uint64_t unk_08A8;                 /* 0x08A8 w */
} ccUiBoss08Gauge;
#pragma pack(pop)

static_assert(offsetof(ccUiBoss08Gauge, unk_0838) == 0x0838, "ccUiBoss08Gauge.unk_0838 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_0870) == 0x0870, "ccUiBoss08Gauge.unk_0870 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_0874) == 0x0874, "ccUiBoss08Gauge.unk_0874 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_0880) == 0x0880, "ccUiBoss08Gauge.unk_0880 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_088C) == 0x088C, "ccUiBoss08Gauge.unk_088C offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_0890) == 0x0890, "ccUiBoss08Gauge.unk_0890 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_0898) == 0x0898, "ccUiBoss08Gauge.unk_0898 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_08A0) == 0x08A0, "ccUiBoss08Gauge.unk_08A0 offset mismatch");
static_assert(offsetof(ccUiBoss08Gauge, unk_08A8) == 0x08A8, "ccUiBoss08Gauge.unk_08A8 offset mismatch");

/* ccBoss0800CamOpeType13: no instance state (4 methods, all byte-cast accesses only) */

/*
 * ccBoss0802JiraiyaActionBase — INFERRED from state_surface (4 seeds, 0 fields)
 * No instance state found; all methods use only byte-cast accesses on param_1.
 * Jiraiya action base class with no persistent member data.
 */

#endif /* S2_BOSS08_H */
