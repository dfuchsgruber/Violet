item_table equ 0x083DA518
field_usage equ 0x1C

.org item_table + 0x2C*0x70 + field_usage
    .word item_field_nature_stone | 1