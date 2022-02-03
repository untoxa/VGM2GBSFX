#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>

#include "sfxplayer.h"
#include "musicmanager.h"

#include "music_track_0__Data.h" 
#include "music_track_1__Data.h"

#include "sfx_00.h"         // generated from VGM
#include "sfx_00_2.h"       // generated from VGM

#include "icq_message.h"    // generated from WAV
#include "quang2.h"         // generated from WAV

void hUGETrackerRoutine(unsigned char ch, unsigned char param, unsigned char tick) NONBANKED OLDCALL {
    ch; param; tick;
}

void main() {
    static uint8_t music_paused = FALSE;

    sound_init();
    
    CRITICAL {
        TMA_REG = 0xC0u, TAC_REG = 0x07u;
        add_TIM(music_play_isr);    
        set_interrupts(VBL_IFLAG | TIM_IFLAG);
    }

    puts("A     - module 1\nB     - module 2\nUP    - sound 1\nDOWN  - sound 2\nLEFT  - WAVE 1\nRIGHT - WAVE 2\nSELECT- music STOP\nSTART - music START");

    while (TRUE) {
        uint8_t joy = joypad();
        if (joy & J_A)      music_load(BANK(music_track_0__Data), &music_track_0__Data), music_pause(music_paused = FALSE);
        if (joy & J_B)      music_load(BANK(music_track_1__Data), &music_track_1__Data), music_pause(music_paused = FALSE);
        if (joy & J_UP)     sound_mask |= MUTE_MASK_sfx_00,   sfx_set_sample(BANK(sfx_00), sfx_00);
        if (joy & J_DOWN)   sound_mask |= MUTE_MASK_sfx_00_2, sfx_set_sample(BANK(sfx_00_2), sfx_00_2);
        if (joy & J_LEFT)   sound_mask |= 0b00000100,         sfx_set_sample(BANK(icq_message), icq_message);
        if (joy & J_RIGHT)  sound_mask |= 0b00000100,         sfx_set_sample(BANK(quang2), quang2);
        if (joy & J_SELECT) music_stop(), music_pause(music_paused = FALSE);
        if (joy & J_START)  music_pause(music_paused = (!music_paused));
        if (joy) waitpadup();
        wait_vbl_done();
    }
}
