.org 0x08094a3c
    ldr r0, =pc_context_menu_build_context_on_pokemon | 1
    bx r0
    .pool

.org 0x08094f60
    .word pc_context_menu_item_strings

.org 0x0808d570
    .word pc_handle_context_on_pokemon_consider_new_modes | 1

.org 0x0808fce0
    .word pc_context_texts

.org 0x0808fdfc
    .word pc_context_texts

.org 0x0808c8cc
    ldr r1, =pc_exit | 1
    bx r1
    .pool