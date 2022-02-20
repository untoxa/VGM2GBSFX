#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>

#include "musicmanager.h"

#include "music_track_0__Data.h" 
#include "DEMOSONG.h"

#include "sound_effect1.h"          // generated from VGM
#include "sound_effect2.h"          // generated from VGM
#include "sound_effect3.h"          // generated from VGM

#include "wave_icq_message.h"       // generated from WAV
#include "wave_asobitech.h"         // generated from WAV

#include "hammered.h"               // generated from SAV

void main() {
    static uint8_t music_paused = FALSE;

    music_init();
    
    CRITICAL {
        music_setup_timer();
        add_low_priority_TIM(music_play_isr);    
    }
    set_interrupts(VBL_IFLAG | TIM_IFLAG);

    puts("A     - module 1\nB     - module 2\nUP    - sound 1\nDOWN  - sound 2\nLEFT  - WAVE 1\nRIGHT - WAVE 2\nSELECT- music STOP\nSTART - music START");

    while (TRUE) {
        uint8_t joy = joypad();
        if (joy & J_A)      music_load(BANK(music_track_0__Data), &music_track_0__Data), music_pause(music_paused = FALSE);
        if (joy & J_B)      music_load(BANK(DEMOSONG), &DEMOSONG), music_pause(music_paused = FALSE);
        if (joy & J_UP)     music_play_sfx(BANK(sound_effect1), sound_effect1, SFX_MUTE_MASK(sound_effect1), 1);
//        if (joy & J_UP)     music_play_sfx(BANK(sound_effect3), sound_effect3, SFX_MUTE_MASK(sound_effect3), 1);
        if (joy & J_DOWN)   music_play_sfx(BANK(hammered_01), hammered_01, SFX_MUTE_MASK(hammered_01), 1);
        if (joy & J_LEFT)   music_play_sfx(BANK(wave_icq_message), wave_icq_message, SFX_MUTE_MASK(wave_icq_message), 1);    
        if (joy & J_RIGHT)  music_play_sfx(BANK(wave_asobitech), wave_asobitech, SFX_MUTE_MASK(wave_asobitech), 1);
        if (joy & J_SELECT) music_stop(), music_pause(music_paused = FALSE);
        if (joy & J_START)  music_pause(music_paused = (!music_paused));
        if (joy) waitpadup();
        wait_vbl_done();
    }
}
