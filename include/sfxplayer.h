#ifndef __SFX_PLAYER_H_INCLUDE__
#define __SFX_PLAYER_H_INCLUDE__

#include <gbdk/platform.h>
#include <stdint.h>

extern uint8_t sfx_play_bank; 
extern const uint8_t * sfx_play_sample;

inline void sfx_sound_init() {
    NR52_REG = 0x80, NR51_REG = 0xFF, NR50_REG = 0x77;  // enable sound
}
inline void sfx_set_sample(uint8_t bank, const uint8_t * sample) CRITICAL {
    sfx_play_bank = bank, sfx_play_sample = sample;
}
uint8_t sfx_play_isr() OLDCALL;

#endif