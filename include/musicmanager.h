#ifndef __MUSICMANAGER_H_INCLUDE__
#define __MUSICMANAGER_H_INCLUDE__

#include "sfxplayer.h"
#include "hUGEDriver.h"

#define MUSIC_SFX_PRIORITY_MINIMAL  0
#define MUSIC_SFX_PRIORITY_NORMAL   1
#define MUSIC_SFX_PRIORITY_HIGH     2

#define MUSIC_STOP_BANK 0xffu

//#define FORCE_CUT_SFX                                   // don't cut by default 

extern volatile uint8_t music_current_track_bank;
extern uint8_t music_mute_mask;
extern const hUGESong_t * music_next_track;
extern uint8_t music_sfx_priority;

inline void music_setup_timer() {
    TMA_REG = ((_cpu == CGB_TYPE) && (*(UBYTE *)0x0143 & 0x80)) ? 0x80u : 0xC0u;
    TAC_REG = 0x07u;
}

inline void music_init() {
    sfx_sound_init();
}

inline void music_sound_cut() {
    sfx_sound_cut();
}

#define MUSIC_CH_1 SFX_CH_1
#define MUSIC_CH_2 SFX_CH_2
#define MUSIC_CH_3 SFX_CH_3
#define MUSIC_CH_4 SFX_CH_4

inline void music_sound_cut_mask(uint8_t mask) {
    sfx_sound_cut_mask(mask);
}

void music_play_isr();

inline void music_load(uint8_t bank, const hUGESong_t * data) {
    music_current_track_bank = MUSIC_STOP_BANK, music_next_track = data; music_current_track_bank = bank;
}

void music_pause(uint8_t pause);

inline void music_stop() {
    music_current_track_bank = MUSIC_STOP_BANK, music_sound_cut();
}

#define MUTE_MASK_NONE 0
#define MUTE_MASK_WAVE MUSIC_CH_3

inline void music_play_sfx(uint8_t bank, const uint8_t * sample, uint8_t mute_mask, uint8_t priority) {
    if (priority < music_sfx_priority) return;
    sfx_play_bank = SFX_STOP_BANK;
    music_sfx_priority = priority;
    music_sound_cut_mask(music_mute_mask);
    music_mute_mask = mute_mask;
    sfx_set_sample(bank, sample);
}

#endif