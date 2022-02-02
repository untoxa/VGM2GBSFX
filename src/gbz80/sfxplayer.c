#include <gbdk/platform.h>
#include <stdint.h>

uint8_t sfx_play_bank;
const uint8_t * sfx_play_sample = 0;
uint16_t sfx_frame_count = 0;

uint8_t sfx_play_isr() NONBANKED NAKED OLDCALL {
__asm
.macro copy_reg ?lbl
        sla b
        jr nc, lbl
        ld a, (hl+)
        ldh (c), a
lbl:
        inc c
.endm

        ld hl, #_sfx_play_sample
        ld a, (hl+)
        ld e, a
        or (hl)
        ret z
        ld h, (hl)
        ld l, e                     ; HL = current position inside the sample

        ld a, (#__current_bank)     ; save bank and switch
        ld e, a
        ld a, (#_sfx_play_bank)
        ld (_rROMB0), a

        ld a, (hl+)
        or a
        ld d, a                     ; d = frame channel count
        jr z, 6$
2$:
        ld a, (hl+)
        ld b, a                     ; a = b = channel no + register mask

        and #0b00000111
        cp #5
        jr c, 3$
        jr nz, 5$                   ; terminator

        ld c, #__AUD3WAVERAM
        .rept 16
            ld a, (hl+)
            ldh (c), a
            inc c
        .endm
        jr 4$
5$:
        ld hl, #0
        ld d, l
        jr 0$
3$:
        ld  c, a
        add a
        add a
        add c
        add #_NR10_REG
        ld c, a                     ; c = NR10_REG + (a & 7) * 5
        
        .rept 5
            copy_reg
        .endm

4$:
        dec d
        jr nz, 2$
6$:
        inc d                       ; return 1 if still playing
0$:
        ld a, l                     ; save current position
        ld (#_sfx_play_sample), a
        ld a, h
        ld (#_sfx_play_sample + 1), a

        ld a, e                     ; restore bank
        ld (_rROMB0), a

        ld e, d                     ; result in e

        ret
__endasm;
}

void sfx_set_sample(uint8_t bank, const uint8_t * sample) CRITICAL {
    sfx_play_bank = bank, sfx_play_sample = sample;
}
