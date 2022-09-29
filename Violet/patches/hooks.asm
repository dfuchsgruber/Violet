.include "patches/mega.asm"
.include "patches/tm.asm"
.include "patches/transparency.asm"
.include "patches/tile.asm"
.include "patches/flash.asm"
.include "patches/trainer.asm"
.include "patches/evolution.asm"
.include "patches/wild_poke.asm"
.include "patches/fp_menu.asm"
.include "patches/abilities_and_items.asm"
.include "patches/attack_split.asm"
.include "patches/dungeon.asm"
.include "patches/specials.asm"
.include "patches/dns.asm"
.include "patches/music_code.asm"
.include "patches/gfx.asm"
.include "patches/fieldmoves.asm"
.include "patches/item.asm"
.include "patches/pokepad.asm"
.include "patches/pokemon.asm"
.include "patches/extensions.asm"
.include "patches/battle.asm"
.include "patches/map.asm"
.include "patches/attack.asm"
.include "patches/save.asm"
.include "patches/titlescreen.asm"
.include "patches/intro.asm"
.include "patches/worldmap.asm"
.include "patches/types.asm"
.include "patches/string.asm"
.include "patches/color.asm"
.include "patches/present.asm"
.include "patches/start_menu.asm"
.include "patches/pc.asm"
.include "patches/summary.asm"
.include "patches/oam.asm"
.include "patches/new_game.asm"

//Memleak debug
.org 0x0800296C
    ldr r2, =malloc_hook | 1
    bx r2
    .pool

.org 0x08002A04
    ldr r2, =free_hook | 1
    bx r2
   .pool

//Remove Help-System
.org 0x0813B90C
    mov r0, #0
    bx lr

// No questlog logging
.org 0x08113614
    bx lr
.org 0x08112514
    bx lr

//PRNG xorshift
.org 0x08044DCC
    ldr r0, =rnd16 | 1
    bx r0
    .pool

.org 0x08044DEC
    ldr r1, =rnd_main_set_seed | 1
    bx r1
    .pool

.org 0x08000418
    ldr r0, =hook_main_initialize | 1
    bx r0
    .pool

.org 0x080008a0 // Improved vblank wait
    swi 0x5
    bx lr