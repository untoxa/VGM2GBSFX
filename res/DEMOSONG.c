#pragma bank 255

#include "hUGEDriver.h"

extern const hUGERoutine_t routines[];

static const unsigned char order_cnt = 6;

static const unsigned char P0[] = {
    DN(C_5,1,0x000),
    DN(___,0,0x446),
    DN(G_4,1,0x000),
    DN(C_4,1,0xC04),
    DN(E_5,1,0x000),
    DN(F_5,1,0x000),
    DN(C_5,1,0xC07),
    DN(G_5,1,0x000),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(C_5,1,0x000),
    DN(G_5,0,0x320),
    DN(___,0,0x446),
    DN(C_5,1,0xC07),
    DN(As5,1,0x000),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(A_5,1,0x000),
    DN(G_5,1,0x000),
    DN(F_5,1,0x000),
    DN(G_5,0,0x305),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(F_5,1,0x000),
    DN(E_5,1,0x000),
    DN(___,0,0x446),
    DN(C_5,1,0x000),
    DN(___,0,0x446),
    DN(G_4,1,0x000),
    DN(C_4,1,0x000),
    DN(E_5,1,0x000),
    DN(F_5,1,0x000),
    DN(___,0,0x446),
    DN(G_5,1,0x303),
    DN(___,0,0x303),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(C_5,1,0x000),
    DN(G_5,0,0x350),
    DN(C_5,1,0x446),
    DN(___,0,0x446),
    DN(As5,1,0x000),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(A_5,1,0x000),
    DN(G_5,1,0x000),
    DN(F_5,1,0x000),
    DN(C_6,0,0x315),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(___,0,0x446),
    DN(As5,1,0x000),
    DN(A_5,1,0x000),
    DN(G_5,1,0x000),
};
static const unsigned char P1[] = {
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(As5,2,0x047),
    DN(___,0,0x047),
    DN(As5,3,0x047),
    DN(___,0,0x047),
    DN(As5,2,0x047),
    DN(___,0,0x047),
    DN(As5,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(As5,2,0x047),
    DN(___,0,0x047),
    DN(As5,3,0x047),
    DN(___,0,0x047),
    DN(As5,2,0x047),
    DN(___,0,0x047),
    DN(As5,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
    DN(C_6,2,0x047),
    DN(___,0,0x047),
    DN(C_6,3,0x047),
    DN(___,0,0x047),
};
static const unsigned char P2[] = {
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(C_5,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(C_5,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x600),
    DN(As3,1,0x000),
    DN(As4,1,0x000),
    DN(As3,1,0x000),
    DN(___,0,0x610),
    DN(As3,2,0x000),
    DN(As4,2,0x000),
    DN(As3,2,0x000),
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(C_5,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(C_5,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(C_5,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x600),
    DN(As3,1,0x000),
    DN(As4,1,0x000),
    DN(As3,1,0x000),
    DN(___,0,0x610),
    DN(As3,2,0x000),
    DN(As4,2,0x000),
    DN(As3,2,0x000),
    DN(___,0,0x600),
    DN(C_4,1,0x000),
    DN(C_5,1,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x610),
    DN(C_4,2,0x000),
    DN(___,0,0x610),
    DN(___,0,0x610),
};
static const unsigned char P3[] = {
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,2,0xF0C),
    DN(___,0,0xF07),
    DN(C_8,1,0xF0C),
    DN(C_8,1,0xF07),
    DN(C_8,2,0xF0C),
    DN(C_8,1,0xF07),
    DN(Ds7,3,0xF0C),
    DN(___,0,0xF07),
    DN(Ds7,3,0xF0C),
    DN(Ds7,3,0xF07),
};
static const unsigned char P4[] = {
    DN(C_5,1,0x000),
    DN(___,0,0x446),
    DN(C_4,0,0x30F),
    DN(C_5,1,0xC07),
    DN(___,0,0x446),
    DN(C_4,0,0x30F),
    DN(C_5,1,0xC06),
    DN(___,0,0x446),
    DN(C_4,0,0x30F),
    DN(C_5,1,0xC05),
    DN(___,0,0x446),
    DN(C_4,0,0x30F),
    DN(C_5,1,0xC04),
    DN(___,0,0x446),
    DN(C_4,0,0x30F),
    DN(C_5,1,0xC03),
    DN(As4,0,0x446),
    DN(As3,0,0x30F),
    DN(As4,1,0xC02),
    DN(___,0,0x446),
    DN(As3,0,0x30F),
    DN(As4,1,0xC01),
    DN(___,0,0x446),
    DN(As3,0,0x30F),
    DN(C_4,1,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As5,1,0xC02),
    DN(As5,1,0xC03),
    DN(As5,1,0xC04),
    DN(As5,1,0xC05),
    DN(C_6,1,0x000),
    DN(___,0,0x446),
    DN(C_5,0,0x30F),
    DN(C_6,1,0xC07),
    DN(___,0,0x446),
    DN(C_5,0,0x30F),
    DN(C_6,1,0xC06),
    DN(___,0,0x446),
    DN(C_5,0,0x30F),
    DN(C_6,1,0xC05),
    DN(___,0,0x446),
    DN(C_5,0,0x30F),
    DN(C_6,1,0xC04),
    DN(___,0,0x446),
    DN(C_5,0,0x30F),
    DN(C_6,1,0xC03),
    DN(As5,0,0x446),
    DN(As4,0,0x30F),
    DN(As5,1,0xC02),
    DN(___,0,0x446),
    DN(As4,0,0x30F),
    DN(As5,1,0xC01),
    DN(___,0,0x446),
    DN(As4,0,0x30F),
    DN(C_5,1,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0xC02),
    DN(As4,1,0xC03),
    DN(As4,1,0xC04),
    DN(As4,1,0xC05),
};

static const unsigned char* const order1[] = {P4,P0,P0};
static const unsigned char* const order2[] = {P1,P1,P1};
static const unsigned char* const order3[] = {P2,P2,P2};
static const unsigned char* const order4[] = {P3,P3,P3};

static const unsigned char duty_instruments[] = {
8,128,128,128,
8,64,48,128,
8,64,131,128,
8,192,240,128,
8,0,241,128,
8,64,241,128,
8,128,241,128,
8,192,241,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
};
static const unsigned char wave_instruments[] = {
0,32,0,128,
0,32,1,128,
0,32,2,128,
0,32,3,128,
0,32,4,128,
0,32,5,128,
0,32,6,128,
0,32,7,128,
0,32,8,128,
0,32,9,128,
0,32,10,128,
0,32,11,128,
0,32,12,128,
0,32,13,128,
0,32,14,128,
};
static const unsigned char noise_instruments[] = {
81,0,0,0,0,0,0,0,
116,0,0,0,0,0,0,0,
100,0,244,12,244,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
};

static const unsigned char waves[] = {
    34,34,34,35,52,69,86,119,137,154,171,188,204,204,204,207,
    34,34,34,35,52,69,86,119,137,154,171,188,204,204,204,207,
    0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,
    0,1,18,35,52,69,86,103,120,137,154,171,188,205,222,239,
    254,220,186,152,118,84,50,16,18,52,86,120,154,188,222,255,
    122,205,219,117,33,19,104,189,220,151,65,1,71,156,221,184,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    254,252,250,248,246,244,242,240,242,244,246,248,250,252,254,255,
    254,221,204,187,170,153,136,119,138,189,241,36,87,138,189,238,
    132,17,97,237,87,71,90,173,206,163,23,121,221,32,3,71,
    1,38,217,8,22,234,118,53,52,177,26,189,163,113,8,120,
    1,125,65,192,90,66,225,89,12,155,164,147,206,17,121,103,
    33,210,186,66,134,109,59,209,218,121,77,29,187,198,124,193,
    232,136,136,123,112,86,12,113,2,172,155,231,133,72,202,124,
    1,46,171,165,133,148,229,232,178,238,174,205,106,71,155,46,
};

const void __at(255) __bank_DEMOSONG;
const hUGESong_t DEMOSONG = {9, &order_cnt, order1, order2, order3,order4, duty_instruments, wave_instruments, noise_instruments, routines, waves};
