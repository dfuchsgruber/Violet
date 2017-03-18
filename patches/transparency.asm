//transparency
.org 0x08069848
	ldr r0, =transparency_script_handler | 1
	bx r0
	.pool
	
//tbox pal
.org 0x0815010C
        ldr r1, =transparency_load_textbox_pal | 1
        bx r1
        .pool

//styled borders
.org 0x0814FCB4
        ldr r1, =transparency_load_styled_border_pal | 1
        bx r1
        .pool

//std borders
.org 0x0814FA2C
        .word gfx_text_std_borderTiles

.org 0x0814FBAC
        .word gfx_text_std_borderTiles

//Nickname, player, rival naming bg
.org 0x0809F9EC
        .word gfx_text_naming_palPal

.org 0x083E1BE4
        .word gfx_text_naming_palPal