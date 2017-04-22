.org 0x080C04BC
    .word gfx_worldmapPal

.org 0x080C2EC0
    .word gfx_worldmapPal

.org 0x080C052C
    .word gfx_worldmapMap

.org 0x080C0500
    .word gfx_worldmapTiles

//patch to abort overwriting of unneccessary pal entries (grit can not deal with those)
.org 0x80C0486
    //copy transparent backdrop color at color 0xCF (BEWEGEN cursor)
    ldr r0, =gfx_worldmapPal
    mov r1, #0xCF
    mov r2, #2
    ldr r3, =0x80C04B6 | 1
    bx r3
    .pool

//worldmap as 256 color img
.org 0x83F12A8
    .word 0x29E0 //bg setup config with colmode = 1
    .word 0x30F9 //bg setup config with charbase at 0x06008000 (=2)


.org 0x080C434C
    .word worldmap0_position_data

.org 0x080C3EF4
    .word worldmap0_namespace_position_assoc
