#pragma bank 255

#include "hUGEDriver.h"
#include <stddef.h>
#include "hUGEDriverRoutines.h"

static const unsigned char order_cnt = 10;
static const unsigned char song_pattern_0[] = {
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
};
static const unsigned char song_pattern_1[] = {
    DN(C_5, 8, 0xC02),
    DN(G_4, 8, 0xC04),
    DN(G_4, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(As4, 8, 0xC04),
    DN(As4, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xC04),
    DN(C_5, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xE04),
    DN(C_5, 8, 0xE04),
    DN(C_6, 8, 0xE04),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
};
static const unsigned char song_pattern_2[] = {
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_4, 2, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x220),
    DN(___, 0, 0x220),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
};
static const unsigned char song_pattern_3[] = {
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0xB02),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
};
static const unsigned char song_pattern_4[] = {
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xE06),
    DN(Ds5, 8, 0x441),
    DN(___, 0, 0x208),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0x441),
    DN(___, 0, 0x441),
    DN(C_6, 8, 0x441),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xE06),
    DN(C_6, 8, 0xE06),
    DN(C_5, 8, 0xE06),
    DN(C_5, 8, 0xC02),
    DN(As5, 8, 0x441),
    DN(As4, 8, 0xE06),
    DN(As5, 8, 0xE06),
    DN(C_5, 8, 0xC02),
    DN(Ds5, 8, 0x441),
    DN(___, 0, 0x203),
    DN(___, 0, 0x208),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xE04),
    DN(C_5, 8, 0xE04),
    DN(As5, 8, 0xE04),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0x441),
    DN(___, 0, 0x441),
    DN(___, 0, 0x441),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0x441),
    DN(G_5, 8, 0x441),
    DN(C_6, 8, 0x441),
    DN(C_5, 8, 0xC02),
    DN(Cs5, 8, 0x441),
    DN(Cs6, 8, 0x441),
    DN(Cs5, 8, 0x441),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0x441),
    DN(C_6, 8, 0x441),
    DN(C_5, 8, 0x441),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0x441),
    DN(As5, 8, 0x441),
    DN(G_5, 8, 0x441),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xC04),
    DN(C_5, 8, 0xC08),
    DN(___, 0, 0x441),
    DN(C_5, 8, 0xC02),
    DN(G_4, 8, 0xC04),
    DN(G_4, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(As4, 8, 0xC04),
    DN(As4, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xC04),
    DN(C_5, 8, 0x0C0),
    DN(___, 0, 0x0C0),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xE04),
    DN(C_5, 8, 0xE04),
    DN(C_6, 8, 0xE04),
};
static const unsigned char song_pattern_5[] = {
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xE06),
    DN(Ds4, 2, 0x000),
    DN(___, 0, 0x216),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 2, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xE06),
    DN(C_5, 2, 0xE06),
    DN(C_4, 2, 0xE06),
    DN(Ds6, 1, 0x280),
    DN(As4, 2, 0x000),
    DN(As3, 2, 0xE06),
    DN(As4, 2, 0xE06),
    DN(Ds6, 1, 0x280),
    DN(Ds4, 2, 0x000),
    DN(___, 0, 0x203),
    DN(___, 0, 0x216),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xE04),
    DN(C_4, 2, 0xE04),
    DN(As4, 2, 0xE04),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0x000),
    DN(G_4, 2, 0x000),
    DN(C_5, 2, 0x000),
    DN(Ds6, 1, 0x280),
    DN(Cs4, 2, 0x000),
    DN(Cs5, 2, 0x000),
    DN(Cs4, 2, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0x000),
    DN(C_5, 2, 0x000),
    DN(C_4, 2, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0x000),
    DN(As4, 2, 0x000),
    DN(G_4, 2, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xC08),
    DN(C_4, 2, 0xC0F),
    DN(___, 0, 0x000),
    DN(Ds6, 1, 0x280),
    DN(G_3, 2, 0xC08),
    DN(G_3, 2, 0xC0F),
    DN(___, 0, 0x000),
    DN(Ds6, 1, 0x280),
    DN(As3, 2, 0xC08),
    DN(As3, 2, 0xC0F),
    DN(___, 0, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xC08),
    DN(C_4, 2, 0xC0F),
    DN(___, 0, 0x000),
    DN(Ds6, 1, 0x280),
    DN(C_4, 2, 0xE04),
    DN(C_4, 2, 0xE04),
    DN(C_5, 2, 0xE04),
};
static const unsigned char song_pattern_6[] = {
    DN(C_5, 9, 0x600),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x601),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x607),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x601),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x600),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x601),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x607),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x601),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x600),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x601),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x607),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x607),
    DN(D_4, 5, 0x607),
};
static const unsigned char song_pattern_7[] = {
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(Cs6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(Cs6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(G_5, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(G_5, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(As5, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(As5, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 6, 0x0C7),
    DN(___, 0, 0x0C7),
    DN(C_6, 7, 0x0C7),
    DN(___, 0, 0x0C7),
};
static const unsigned char song_pattern_8[] = {
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 9, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
};
static const unsigned char song_pattern_9[] = {
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(___, 0, 0x000),
    DN(C_5, 8, 0xC02),
    DN(C_5, 8, 0xC03),
    DN(C_5, 8, 0xC04),
    DN(C_5, 8, 0xC05),
    DN(As4, 8, 0x444),
    DN(___, 0, 0x444),
    DN(___, 0, 0x102),
    DN(___, 0, 0x100),
};
static const unsigned char song_pattern_10[] = {
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(C_5, 3, 0x603),
    DN(C_5, 3, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0x000),
    DN(D_4, 5, 0x608),
    DN(___, 0, 0x000),
    DN(C_5, 4, 0x601),
    DN(___, 0, 0xB03),
};
static const unsigned char* const order1[] = {song_pattern_0, song_pattern_0, song_pattern_7, song_pattern_7, song_pattern_7};
static const unsigned char* const order2[] = {song_pattern_1, song_pattern_4, song_pattern_4, song_pattern_4, song_pattern_9};
static const unsigned char* const order3[] = {song_pattern_2, song_pattern_5, song_pattern_5, song_pattern_5, song_pattern_5};
static const unsigned char* const order4[] = {song_pattern_3, song_pattern_6, song_pattern_8, song_pattern_8, song_pattern_10};
static const unsigned char duty_instruments[] = {
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0x10, 0x80,
    0x00, 0x80, 0x64, 0x80,
    0x00, 0x00, 0x70, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
    0x00, 0x80, 0xF0, 0x80,
};
static const unsigned char wave_instruments[] = {
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x01, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
    0x00, 0x20, 0x00, 0x80,
};
static const unsigned char noise_instruments[] = {
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0x41, 0x00, 0, 0, 0, 0, 0, 0,
    0x73, 0x00, 0, 0, 0, 0, 0, 0,
    0x62, 0x5D, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0x70, 0x7E, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
    0xF0, 0x00, 0, 0, 0, 0, 0, 0,
};
static const unsigned char waves[] = {
    0x76, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x7B, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCB, 0xA8,
    0x23, 0x35, 0x22, 0x22, 0x25, 0x42, 0x22, 0x22, 0xD9, 0xAD, 0xDD, 0xAD, 0xDD, 0xCB, 0xA9, 0x87,
    0xFF, 0xFF, 0x3A, 0x7E, 0xDC, 0xE0, 0x41, 0x54, 0xB8, 0x26, 0x99, 0xE9, 0x80, 0x3D, 0x20, 0xE6,
    0xA5, 0x0B, 0x17, 0x64, 0xE4, 0x4D, 0xE5, 0xE3, 0x0B, 0x33, 0x8A, 0x86, 0x04, 0x88, 0x25, 0x52,
    0xD4, 0x43, 0x66, 0x9C, 0x7C, 0x29, 0x29, 0xE8, 0x00, 0x62, 0x19, 0x0A, 0x48, 0x4C, 0xDB, 0xD7,
    0xB9, 0x1E, 0xB9, 0xA5, 0x55, 0x60, 0xC6, 0xA2, 0xEA, 0x42, 0xCE, 0x2C, 0x29, 0xC0, 0x29, 0xD5,
    0x1E, 0xCD, 0xB2, 0x19, 0xE0, 0x0B, 0x5D, 0x36, 0x93, 0x8A, 0x3A, 0xC5, 0xED, 0x7B, 0xD1, 0xCB,
    0xE2, 0xCC, 0x08, 0x0B, 0x43, 0x33, 0x66, 0x64, 0x71, 0x78, 0x1B, 0x72, 0x23, 0xC6, 0x7D, 0xD7,
    0x4B, 0x72, 0xD4, 0x6E, 0x0A, 0xDB, 0xB9, 0x39, 0xCC, 0xD8, 0xE2, 0xD0, 0x76, 0x5C, 0x23, 0x97,
    0x37, 0xA3, 0x1C, 0x57, 0x71, 0xD4, 0x52, 0x86, 0xD5, 0xAB, 0x89, 0x4A, 0x64, 0xA0, 0x00, 0x88,
    0xB2, 0xC7, 0x69, 0x06, 0xE3, 0x65, 0x73, 0x39, 0x51, 0xC0, 0xEE, 0x09, 0x52, 0x2B, 0x3E, 0x39,
    0xB7, 0xC8, 0x0A, 0x35, 0x84, 0xDD, 0x7A, 0x32, 0xA5, 0x70, 0x12, 0x20, 0x56, 0xA3, 0xE9, 0xD8,
    0xC8, 0xB9, 0xE6, 0x27, 0xD6, 0x38, 0x6B, 0x6E, 0xA6, 0x35, 0x90, 0xDA, 0x01, 0xEC, 0xA7, 0x90,
    0x64, 0x23, 0x97, 0x8D, 0x34, 0x9D, 0x69, 0x8A, 0x8C, 0x3C, 0x4E, 0xC7, 0x05, 0xEE, 0x9C, 0x55,
    0x6B, 0xE1, 0x88, 0x5E, 0xC1, 0x27, 0xBA, 0x74, 0xE9, 0x5D, 0x88, 0x2C, 0xA2, 0x7D, 0xB5, 0xAE,
    0x38, 0x23, 0xD4, 0x8B, 0x7A, 0xCA, 0x89, 0x96, 0x25, 0x0A, 0x07, 0x4A, 0x87, 0xE5, 0xEB, 0x9D,
};

const void __at(255) __bank_music_track_1__Data;
const hUGESong_t music_track_1__Data = {
    7,
    &order_cnt,
    order1, order2, order3, order4,
    duty_instruments, wave_instruments, noise_instruments,
    routines,
    waves
};
