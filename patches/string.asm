//Various strings
.include "patches/string/zurueck.asm"
.include "patches/string/menu.asm"
.include "patches/string/battle.asm"


.org 0x84021ec
    .word str_item_pc_item_lager
.org 0x84021f4
    .word str_item_pc_briefbox
.org 0x84021fc
    .word str_item_pc_ausschalten

.org 0x840220c
    .word str_item_pc_nehmen
.org 0x8402214
    .word str_item_pc_ablegen

.org 0x80ebb5c
    .word str_item_pc_no_mail
.org 0x80ebbd4
    .word str_item_pc_no_mail