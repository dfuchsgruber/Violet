.global berry_pouch_get_context_menu_options_standard_hook
.global berry_pouch_toss_hook_print_string_how_many
.global berry_pouch_toss_hook_get_string_confirm_quantity_to_toss

.align 4
.thumb

.thumb_func
berry_pouch_get_context_menu_options_standard_hook:
    bl berry_pouch_get_context_menu_options_standard
    ldr r1, =berry_pouch_context_menu_options_count
    ldrb r0, [r1]
    ldr r2, =0x0813dd24 | 1
    bx r2

.align 4
.thumb

.thumb_func
berry_pouch_toss_hook_print_string_how_many:
    mov r0, r5 // self-reference
    bl berry_pouch_toss_print_string_how_many
    ldr r0, =0x0813dfd0 | 1
    bx r0


.align 4
.thumb

.thumb_func
berry_pouch_toss_hook_get_string_confirm_quantity_to_toss:
    bl berry_pouch_toss_get_string_confirm_quantity_to_toss
    mov r0, #7 // Overwritten old code
    ldr r1, =0x0813e028 | 1
    bx r1
