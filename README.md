# VGM2GBSFX
Convert DMG VGM files (and a few other formats) for using them as SFX in homebrew

![example rom](/screenshot.png)

Project requires GBDK-2020 v4.1.1: http://gbdk-2020.github.io and GNU make. A few tools are compiled into executables for windows, but you may get the linux versions (or whatever else targets) from the original repositories. Main data conversion tools are written in python.

1. music in UGE format is made with hUGETracker (standalone, or embedded into GBStudio), those are converted into C source with uge2source tool (shipped with the desktop version of hUGETracker)
2. VGM files may be exported from Deflemask or you may download some ripped sounds from games: https://vgmrips.net/packs/chip/game-boy-dmg (you may need to tweak the vgm2data.py a bit, because not all dumps may be converted as is). VGZ is simply compressed VGM, unzip those to get VGM.
3. dump2vgm.py is used to make VGM files from sound register dumps, created with https://github.com/mmitch/gbsplay tool from GBS files which may be found here: https://www.zophar.net/music/gameboy-gbs
4. wav2data.py is used to convert 8KHz mono PCM WAV files
5. fxhammer2data.py is used to convert FXHammer https://www.pouet.net/prod.php?which=17337 (native game boy tool) sound effects in SAV format which is produced by almost any game boy emulator and is simply a SRAM dump

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
