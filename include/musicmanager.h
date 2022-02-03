#ifndef __MUSICMANAGER_H_INCLUDE__
#define __MUSICMANAGER_H_INCLUDE__

#include "sfxplayer.h"
#include "hUGEDriver.h"

#define MUSIC_STOP_BANK 0xffu
//#define FORCE_CUT_SFX                                   // don't cut by default 

extern uint8_t music_current_track_bank;
extern uint8_t music_mute_mask;
extern const hUGESong_t * music_next_track;

#define MUSIC_CH_RETRIGGER  0b11000000
#define MUSIC_CH_ENABLE     0b10000000

inline void music_setup_timer() {
    TMA_REG = ((_cpu == CGB_TYPE) && (*(UBYTE *)0x0143 & 0x80)) ? 0x80u : 0xC0u;
    TAC_REG = 0x07u;
}

inline void music_init() {
    NR52_REG = MUSIC_CH_ENABLE, NR51_REG = 0xFF, NR50_REG = 0x77;  // enable sound
}

inline void music_sound_cut() {
    NR12_REG = NR22_REG = NR32_REG = NR42_REG = 0;
    NR14_REG = NR24_REG = NR44_REG = MUSIC_CH_RETRIGGER;
}

#define MUSIC_CH_1 1
#define MUSIC_CH_2 2
#define MUSIC_CH_3 4
#define MUSIC_CH_4 8

inline void music_sound_cut_mask(uint8_t mask) {
    if (mask & MUSIC_CH_1) NR12_REG = 0, NR14_REG = MUSIC_CH_RETRIGGER; 
    if (mask & MUSIC_CH_2) NR22_REG = 0, NR24_REG = MUSIC_CH_RETRIGGER; 
    if (mask & MUSIC_CH_3) NR32_REG = 0; 
    if (mask & MUSIC_CH_4) NR42_REG = 0, NR44_REG = MUSIC_CH_RETRIGGER;
}

void music_play_isr();

inline void music_load(uint8_t bank, const hUGESong_t * data) CRITICAL {
    music_next_track = data; music_current_track_bank = bank;
}

void music_pause(uint8_t pause);

inline void music_stop() {
    music_current_track_bank = MUSIC_STOP_BANK, music_sound_cut();
}

#define MUTE_MASK_WAVE MUSIC_CH_3

inline void music_play_sfx(uint8_t bank, const uint8_t * sample, uint8_t mute_mask) {
    music_mute_mask |= mute_mask;
    sfx_set_sample(bank, sample);
}

#endif