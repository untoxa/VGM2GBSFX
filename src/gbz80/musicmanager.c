#include <gbdk/platform.h>
#include <stdint.h>

#include "musicmanager.h"
#include "sfxplayer.h"

#include "hUGEDriver.h"

uint8_t music_current_track_bank = MUSIC_STOP_BANK;
uint8_t music_mute_flag = 0, music_mute_mask = 0;
const hUGESong_t * music_next_track;
uint8_t music_play_isr_counter = 0;
uint8_t music_play_isr_pause = FALSE;

void music_play_isr() NONBANKED {
    if (sfx_play_isr()) {
        hUGE_mute_mask = music_mute_mask, music_mute_flag = TRUE; 
    } else {
        if (music_mute_flag) {
            hUGE_mute_mask = 0, hUGE_reset_wave(), music_mute_flag = FALSE;
            #ifdef FORCE_CUT_SFX
            music_sound_cut_mask(music_mute_mask);
            #endif
            music_mute_mask = 0; 
        }
    }
    if (music_play_isr_pause) return;
    if (music_current_track_bank == MUSIC_STOP_BANK) return;
    if (++music_play_isr_counter & 3) return;
    uint8_t save_bank = _current_bank;
    SWITCH_ROM(music_current_track_bank);
    if (music_next_track) {
        music_sound_cut();
        hUGE_init(music_next_track);
        music_next_track = 0;
    } else hUGE_dosound();
    SWITCH_ROM(save_bank);
}

void music_pause(uint8_t pause) {
    if (music_play_isr_pause = pause) music_sound_cut();
}