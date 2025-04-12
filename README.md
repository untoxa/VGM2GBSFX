# VGM2GBSFX
Convert DMG VGM files (and a few other formats) for using them as SFX in homebrew

![example rom](/screenshot.png)

This project requires GBDK-2020 v4.1.1: http://gbdk-2020.github.io and GNU make. A few tools are compiled into executables for windows, but you may get the linux versions (or whatever else targets) from the original repositories. The main data conversion tools are written in python.

# Importing your music and sound effects

VGM2GBSFX supports the following music and sound formats.  Each format has a tool to convert your file into a .c file that you can compile into your code.

* **.uge music** - Created from hUGETracker (either standalone or from GBStudio).  Use the `utils/uge2source` tool. which is also included with hUGETracker itself.
* **.vgm music and sound effects** - Exported from hUGETracker or Deflemask, or ripped from existing games (such as https://vgmrips.net/packs/chip/game-boy-dmg).  Use `utils/vgm2data.py`.
  * For existing game rips, you may need to tweak the util, because not all dumps may be converted as is.
* **.vgz compressed files** - unzip, then use `utils/vgm2data.py`.
* **.gbs module dumps** - convert to .vgm using `utils/dump2vgm.py`, then use `utils/vgm2data.py`.
* **.wav sound effects** - use `utils/wav2data.py`.  Only 8KHz mono PCM WAV files are supported.
* **.sav file from FXHammer** - use `utils/fxhammer2data.py`.  FXHammer is a sound effect editor available at https://www.pouet.net/prod.php?which=17337 and can be run in almost any Game Boy emulator; the .sav file is the output of its SRAM save file.
  * To play sound effects at the same speed as they are within FXHammer, add the `-d 4` parameter to `fxhammer2data`.
  * `--no-pan` may be necessary to mute the correct channels.

# Integration into GBDK

Please follow these steps to add VGM2GBSFX into a GBDK project:

## Initialization

1. If you haven't already, set up hUGEDriver according to the [quick start guide](https://github.com/SuperDisk/hUGEDriver?tab=readme-ov-file#quick-start-gbdk).
1. Copy musicmanager.c and sfxplayer.c from the src/sm83 folder of this project into your codebase.
1. Copy musicmanager.h and sfxplayer.h from the include folder of this project into your codebase.
1. At the start of your game, add the following:
  ```
    #include "musicmanager.h"

    set_interrupts(IE_REG | TIM_IFLAG); // add any other interrupts as you need
    music_init();

    CRITICAL {
      music_setup_timer();
      add_low_priority_TIM(music_play_isr);
    }
  ```

## Playing Music

First, `#include` the compiled .h file of your song.  The .h file will include a const and a bank; import them using something like this:

```
extern const hUGESong_t songname;
BANKREF_EXTERN(songname)
```

Then, play the song using this code.  This must be run from bank 0 to prevent crashes.
```
music_load(BANK(songname), &songname);
```

## Playing Sound Effects

`#include` the .h file exported from your sound effect file.  Then play the sound effect using this:
```
music_play_sfx(
  BANK(sfx_id),
  sfx_id,
  SFX_MUTE_MASK(sfx_id),
  priority_number, // a priority number; higher priority sound effects interrupt lower priority sound effects
);
```

# Data format description:

`ROW: [COUNT][[[COMMAND][[REG]...]]...]`

`COUNT: DDDDCCCC` 

- `DDDD` is a delay
- `CCCC` is a data packet count

on each call of sfx_play_isr() the next row of data is processed. if delay = N is specified, then N calls will be skipped before proceeding to the next row

`COMMAND: RRRRRCCC` 

- `RRRRR` is a register bit mask, each bit represents the presence of a sound register in the packet, MSB is the least address: `0b10000000` means load NR10 only. registers are loaded from lower to higher addresses. for example, for NR1X that means, if the only two registers, say, NR12 and NR14 are present in the packet, then NR12 always goes first, then NR14. if you need reverse order, just make two packets.
- `CCC` is a command:

  - `000` - load NR1X registers
  - `001` - load NR2X registers
  - `010` - load NR3X registers
  - `011` - load NR4X registers
  - `100` - load NR5X registers
  - `101` - load 16-byte wave sample (RRRRR bits are not used, always followed with 16 bytes of the waveform)
  - `110` - load 16-byte wave sample and play it (RRRRR bits are not used, always followed with 16 bytes of the waveform)
  - `111` - terminator  

`REG: XXXXXXXX`

- `XXXXXXXX` - 8-bit raw sound register value

# EXAMPLE

`0x12,0b01111001,0x20,0xf8,0xc4,0x86,0b01111011,0x2a,0xf8,0x50,0x80`

two packets of data plus skip one next interrupt:
- channel 2: NR21 = 0x20, NR22 = 0xf8, NR23 = 0xc4, NR24 = 0x86
- channel 4: NR41 = 0x2a, NR42 = 0xf8, NR43 = 0x50, NR44 = 0x80

`0x02,0b01000100,0xff,0b00000111`

two packets of data:
- NR5X: NR51 = 0xff (PAN: all channels centered)
- terminate sequence
