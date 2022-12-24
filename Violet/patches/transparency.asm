.org 0x0814fb70
        ldr r3, = tbox_frame_std_load_gfx_and_pal | 1
        bx r3
        .pool


.org 0x080693b4
        ldr r1, = overworld_tbox_load_gfx | 1
        bl _blxr1
        b 0x080693d2
        .pool

.org 0x080694e4
        ldr r0, =overworld_tbox_delete | 1
        bx r0
        .pool

// Nickname, player, rival naming bg
.org 0x0809F9EC
        .word gfx_text_naming_palPal

.org 0x083E1BE4
        .word gfx_text_naming_palPal

.org 0x0814FA2C
        .word gfx_text_std_borderTiles

.org 0x0814FBAC
        .word gfx_text_std_borderTiles

.org 0x08150114
        .word gfx_text_stdPal