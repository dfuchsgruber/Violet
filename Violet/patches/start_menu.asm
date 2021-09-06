
.org 0x0806ef80
    ldr r0, = start_menu_initilize | 1
    bx r0
    .pool

.org 0x0806ee7c
    ldr r0, = start_menu_clear_additional_box | 1
    bx r0
    .pool

.org 0x0806f324
    .word start_menu_save_initialize_and_clear_additional_box | 1

.org 0x083a71b4
    .word start_menu_save_initialize_and_clear_additional_box | 1
  

.org 0x083a71bc
    .word start_menu_options_initialize | 1

.org 0x0806ecb8
    ldr r0, = start_menu_build | 1
    bx r0
    .pool

.org 0x0806ef00
    .word start_menu_items
.org 0x0806f2d8
    .word start_menu_items
.org 0x0806f35c
    .word start_menu_items

.org 0x0806f09c
    .word start_menu_item_descriptions
.org 0x0806f2cc
    .word start_menu_item_descriptions
