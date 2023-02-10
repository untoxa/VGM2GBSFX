#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>

#include "musicmanager.h"

#include "song1.h"
#include "song2.h"

#include "sound_effect1.h"          // generated from VGM
#include "sound_effect2.h"          // generated from VGM
#include "sound_effect3.h"          // generated from VGM

#include "wave_icq_message.h"       // generated from WAV
#include "wave_asobitech.h"         // generated from WAV

#include "hammered.h"               // generated from SAV

void main(void) {
    static uint8_t music_paused = FALSE;

    // initialize the music and SFX driver
    music_init();

    CRITICAL {
        // set up the game boy timer
        music_setup_timer();
        // add music and SFX driver ISR to the low priority timer chain
        add_low_priority_TIM(music_play_isr);
    }
    // enable the timer interrupt
    set_interrupts(IE_REG | TIM_IFLAG);

    // print instructions to screen
    puts("A     - module 1\nB     - module 2\nUP    - sound 1\nDOWN  - sound 2\nLEFT  - WAVE 1\nRIGHT - WAVE 2\nSELECT- music STOP\nSTART - music PAUSE");

    while (TRUE) {
        // read joypad
        uint8_t joy = joypad();
        // play sound or music, depending on the pressed key
        if (joy & J_A)      music_load(BANK(song1), &song1), music_pause(music_paused = FALSE);
        if (joy & J_B)      music_load(BANK(song2), &song2), music_pause(music_paused = FALSE);
//        if (joy & J_UP)     music_play_sfx(BANK(sound_effect1), sound_effect1, SFX_MUTE_MASK(sound_effect1), MUSIC_SFX_PRIORITY_NORMAL);
        if (joy & J_UP)     music_play_sfx(BANK(sound_effect3), sound_effect3, SFX_MUTE_MASK(sound_effect3), MUSIC_SFX_PRIORITY_NORMAL);
        if (joy & J_DOWN)   music_play_sfx(BANK(hammered_08), hammered_08, SFX_MUTE_MASK(hammered_08), MUSIC_SFX_PRIORITY_NORMAL);
        if (joy & J_LEFT)   music_play_sfx(BANK(wave_icq_message), wave_icq_message, SFX_MUTE_MASK(wave_icq_message), MUSIC_SFX_PRIORITY_NORMAL);
        if (joy & J_RIGHT)  music_play_sfx(BANK(wave_asobitech), wave_asobitech, SFX_MUTE_MASK(wave_asobitech), MUSIC_SFX_PRIORITY_NORMAL);
        if (joy & J_SELECT) music_stop(), music_pause(music_paused = FALSE);
        if (joy & J_START)  music_pause(music_paused = (!music_paused));
        // wait until the key is released
        if (joy) waitpadup();
        // synchronize with the screen refresh
        wait_vbl_done();
    }
}
