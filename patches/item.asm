item_table equ 0x083DA518
description equ 0x14
field_usage equ 0x1C
item_resource equ 0x83D3BE8
ITEM_SIZE equ 0x2C

.org 0x0815F914 + (0x88*4)
    .word script_cmd_x88_pokemart3 | 1

.org item_table + ITEM_SIZE*0x70 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x71 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x72 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x73 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x74 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x75 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x76 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x77 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*0x78 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE*105 + field_usage
    .word item_field_nature_stone | 1

.org item_table + ITEM_SIZE * 0xDA + description
    .word str_item_desc_up_grade

.org item_table + ITEM_SIZE * 0x10B + description
    .word str_item_desc_wolkenherz

.org item_table + ITEM_SIZE * 0x15D + description
    .word str_item_desc_zugangskarte

.org item_table + ITEM_SIZE * 0x168 + description
    .word str_item_desc_wolke

.org item_table + ITEM_SIZE * 270 + field_usage
    .word item_ashbag_field | 1





.org item_resource + 0x10B * 8
    .word gfx_item_wolkenherzTiles
    .word gfx_item_wolkenherzPal

.org item_resource + 0x168 * 8
    .word gfx_item_wolkeTiles
    .word gfx_item_wolkePal

//@Bike sound := 195
.org 0x080A1402
    mov r0, #195