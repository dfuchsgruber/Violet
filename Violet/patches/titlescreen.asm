/*

 */

.org 0x08078EF4
    .word gfx_ts_deoxys_0Pal

.org 0x08079428
    .word gfx_ts_start_lowerPal

.org 0x8079480
    .word gfx_ts_start_lowerPal

//load the start symbol
.org 0x08078954
    ldr r0, =ts_setup_bg | 1
    bl blxr0
    ldr r0, =0x80789F3 | 1
    blxr0:
    bx r0
    .pool

.org 0x80795C8
    ldr r0, =ts_setup_pal | 1
    bl blxr0_2
    ldr r0, =0x80795F4 | 1
    blxr0_2:
    bx r0
    .pool

//anim injection
.org 0x8079474
    ldr r0, =ts_anim_hook | 1
    bx r0
    .pool

.org 0x8079154
    ldr r0, =ts_cry_hook | 1
    bx r0
    .pool

//frames the titlescreen lasts till reset
.org 0x08078B80
    .word 0x1800

.org 0x083BF9E8
    .word gfx_ts_flamesTiles