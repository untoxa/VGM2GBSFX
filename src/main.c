#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>

#include "sfxplayer.h"
#include "hUGEDriver.h"

#include "music_track_0__Data.h" 
#include "music_track_1__Data.h"

#include "sfx_00.h"         // generated from VGM
#include "sfx_00_2.h"       // generated from VGM

#include "icq_message.h"    // generated from WAV
#include "quang2.h"         // generated from WAV

// #define FORCE_CUT_SFX    // don't cut by default 

void hUGETrackerRoutine(unsigned char ch, unsigned char param, unsigned char tick) NONBANKED {
    ch; param; tick;
}

uint8_t current_track_bank = 255;
uint8_t mute_flag = 0, sound_mask = 0;
const hUGESong_t * next_track;
uint8_t play_isr_counter = 0;
void play_isr() NONBANKED {
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
    if (current_track_bank == 255) return;
    play_isr_counter++;
    if (play_isr_counter &= 3) return;
    uint8_t save_bank = _current_bank;
    SWITCH_ROM(current_track_bank);
    if (next_track) {
        NR12_REG = NR22_REG = NR32_REG = NR42_REG = 0;  // shut channels
        NR14_REG = NR24_REG = NR44_REG = 0xff;          // retrigger channels
        hUGE_init(next_track);
        next_track = 0;
    } else hUGE_dosound();
    SWITCH_ROM(save_bank);
}
inline void load_music(uint8_t bank, const hUGESong_t * data) CRITICAL {
    next_track = data; current_track_bank = bank;
}

void main() {
    NR52_REG = 0x80, NR51_REG = 0xFF, NR50_REG = 0x77; // enable sound
    
    CRITICAL {
        TMA_REG = 0xC0u, TAC_REG = 0x07u;
        add_TIM(play_isr);    
        set_interrupts(VBL_IFLAG | TIM_IFLAG);
    }

    puts("A     - module 1\nB     - module 2\nUP    - sound 1\nDOWN  - sound 2\nLEFT  - WAVE 1\nRIGHT - WAVE 2");

    while (TRUE) {
        uint8_t joy = joypad();
        if (joy & J_A)     load_music(BANK(music_track_0__Data), &music_track_0__Data);
        if (joy & J_B)     load_music(BANK(music_track_1__Data), &music_track_1__Data);
        if (joy & J_UP)    sound_mask |= MUTE_MASK_sfx_00,   sfx_set_sample(BANK(sfx_00), sfx_00);
        if (joy & J_DOWN)  sound_mask |= MUTE_MASK_sfx_00_2, sfx_set_sample(BANK(sfx_00_2), sfx_00_2);
        if (joy & J_LEFT)  sound_mask |= 0b00000100,         sfx_set_sample(BANK(icq_message), icq_message);
        if (joy & J_RIGHT) sound_mask |= 0b00000100,         sfx_set_sample(BANK(quang2), quang2);
        if (joy) waitpadup();
        wait_vbl_done();
    }
}
