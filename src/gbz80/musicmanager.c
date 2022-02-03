#include <gbdk/platform.h>
#include <stdint.h>

#include "musicmanager.h"
#include "sfxplayer.h"

#include "hUGEDriver.h"

uint8_t current_track_bank = MUSIC_STOP_BANK;
uint8_t mute_flag = 0, sound_mask = 0;
const hUGESong_t * next_track;
uint8_t play_isr_counter = 0;
uint8_t play_isr_pause = FALSE;

void music_play_isr() NONBANKED {
    if (sfx_play_isr()) {
        hUGE_mute_mask = sound_mask, mute_flag = TRUE; 
    } else {
        if (mute_flag) {
            hUGE_mute_mask = 0, hUGE_current_wave = 255, mute_flag = FALSE;
            #ifdef FORCE_CUT_SFX
            if (sound_mask & 1) NR12_REG = 0, NR14_REG = 0b11000000; 
            if (sound_mask & 2) NR22_REG = 0, NR24_REG = 0b11000000; 
            if (sound_mask & 4) NR32_REG = 0; 
            if (sound_mask & 8) NR42_REG = 0, NR44_REG = 0b11000000;
            #endif
            sound_mask = 0; 
        }
    }
    if (play_isr_pause) return;
    if (current_track_bank == MUSIC_STOP_BANK) return;
    if (++play_isr_counter & 3) return;
    uint8_t save_bank = _current_bank;
    SWITCH_ROM(current_track_bank);
    if (next_track) {
        sound_cut();
        hUGE_init(next_track);
        next_track = 0;
    } else hUGE_dosound();
    SWITCH_ROM(save_bank);
}

void music_pause(uint8_t pause) {
    if (play_isr_pause = pause) sound_cut();
}
