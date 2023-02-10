#include <gbdk/platform.h>
#include <stdint.h>

#include "musicmanager.h"
#include "sfxplayer.h"

typedef struct {
    uint8_t bank;
    const uint8_t * data;
    uint8_t mute_mask;
} advanced_instr_t;

BANKREF_EXTERN(kick)
extern const uint8_t kick[];
extern void __mute_mask_kick;

BANKREF_EXTERN(kick_75)
extern const uint8_t kick_75[];
extern void __mute_mask_kick_75;

BANKREF_EXTERN(kick_50)
extern const uint8_t kick_50[];
extern void __mute_mask_kick_50;

BANKREF_EXTERN(snare)
extern const uint8_t snare[];
extern void __mute_mask_snare;

BANKREF_EXTERN(snare_75)
extern const uint8_t snare_75[];
extern void __mute_mask_snare_75;

BANKREF_EXTERN(snare_50)
extern const uint8_t snare_50[];
extern void __mute_mask_snare_50;

const advanced_instr_t instruments[] = {
    { BANK(kick),     kick,     SFX_MUTE_MASK(kick)     },
    { BANK(snare),    snare ,   SFX_MUTE_MASK(snare)    },
    { BANK(kick_75),  kick_75,  SFX_MUTE_MASK(kick_75)  },
    { BANK(snare_75), snare_75, SFX_MUTE_MASK(snare_75) },
    { BANK(kick_50),  kick_50,  SFX_MUTE_MASK(kick_50)  },
    { BANK(snare_50), snare_50, SFX_MUTE_MASK(snare_50) },
};

void hUGETrackerRoutine(unsigned char tick, unsigned int param) NONBANKED {
    if (tick) return;
    const advanced_instr_t * instrument = instruments + ((unsigned char)(param) >> 4);
    music_play_sfx(instrument->bank, instrument->data, instrument->mute_mask, MUSIC_SFX_PRIORITY_MINIMAL);
}

const hUGERoutine_t routines[] = {
    hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine,
    hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine,
    hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine,
    hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine, hUGETrackerRoutine
};
