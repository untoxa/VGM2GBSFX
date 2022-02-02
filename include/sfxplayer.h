#ifndef __SFX_PLAYER_H_INCLUDE__
#define __SFX_PLAYER_H_INCLUDE__

#include <gbdk/platform.h>
#include <stdint.h>

void sfx_set_sample(UINT8 bank, const UINT8 * sample); 
uint8_t sfx_play_isr() OLDCALL;

#endif