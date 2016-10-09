item_table equ 0x083DA518
description equ 0x14
field_usage equ 0x1C
item_resource equ 0x83D3BE8



.org item_table + 0x2C*0x70 + field_usage
    .word item_field_nature_stone | 1



.org item_table + 0x2C * 0x10B + description
    .word str_item_desc_wolkenherz

.org item_resource + 0x10B * 8
    .word gfx_item_wolkenherzTiles
    .word gfx_item_wolkenherzPal

