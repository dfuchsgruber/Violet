
.org 0x0806ef80
    ldr r0, = start_menu_initilize | 1
    bx r0
    .pool

.org 0x0806ee7c
    ldr r0, = start_menu_clear_additional_box | 1
    bx r0
    .pool

.org 0x0806f324
    .word start_menu_call_save_and_clear_additional_box | 1

.org 0x083a71b4
    .word start_menu_call_save_and_clear_additional_box | 1
  

.org 0x083a71bc
    .word start_menu_options_initialize | 1