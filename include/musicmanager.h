#ifndef __MUSICMANAGER_H_INCLUDE__
#define __MUSICMANAGER_H_INCLUDE__

#include "sfxplayer.h"
#include "hUGEDriver.h"

#define MUSIC_STOP_BANK 0xffu
//#define FORCE_CUT_SFX                                   // don't cut by default 

extern uint8_t music_current_track_bank;
extern uint8_t music_mute_mask;
extern const hUGESong_t * music_next_track;

inline void sound_init() {
    NR52_REG = 0x80, NR51_REG = 0xFF, NR50_REG = 0x77;  // enable sound
}
inline void sound_cut() {
    NR12_REG = NR22_REG = NR32_REG = NR42_REG = 0;      // shut channels
    NR14_REG = NR24_REG = NR44_REG = 0b11000000;        // retrigger channels
}

void music_play_isr();

inline void music_load(uint8_t bank, const hUGESong_t * data) CRITICAL {
    music_next_track = data; music_current_track_bank = bank;
}
void music_pause(uint8_t pause);
inline void music_stop() {
    music_current_track_bank = MUSIC_STOP_BANK, sound_cut();
}

#define MUTE_MASK_WAVE 0b00000100

inline void music_play_sfx(uint8_t bank, const uint8_t * sample, uint8_t mute_mask) {
    music_mute_mask |= mute_mask;
    sfx_set_sample(bank, sample);
}

#endif