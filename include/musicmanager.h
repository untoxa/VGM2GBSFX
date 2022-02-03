#ifndef __MUSICMANAGER_H_INCLUDE__
#define __MUSICMANAGER_H_INCLUDE__

#include "hUGEDriver.h"

#define MUSIC_STOP_BANK 0xffu
//#define FORCE_CUT_SFX                                   // don't cut by default 

extern uint8_t current_track_bank;
extern uint8_t mute_flag, sound_mask;
extern const hUGESong_t * next_track;
extern uint8_t play_isr_pause;

inline void sound_init() {
    NR52_REG = 0x80, NR51_REG = 0xFF, NR50_REG = 0x77;  // enable sound
}
inline void sound_cut() {
    NR12_REG = NR22_REG = NR32_REG = NR42_REG = 0;      // shut channels
    NR14_REG = NR24_REG = NR44_REG = 0b11000000;        // retrigger channels
}

void music_play_isr();

inline void music_load(uint8_t bank, const hUGESong_t * data) CRITICAL {
    next_track = data; current_track_bank = bank;
}
void music_pause(uint8_t pause);
inline void music_stop() {
    current_track_bank = MUSIC_STOP_BANK, sound_cut();
}

#endif