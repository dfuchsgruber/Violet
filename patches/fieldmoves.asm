.org 0x08122A34
    ldr r3, =pokemenu_build_opt_by_pokemon | 1
    bx r3
    .pool

.org 0x8120FA8
    .word pokemenu_opts

.org 0x8121FF0
    .word pokemenu_opts

.org 0x8122D50
    .word pokemenu_opts

.org 0x8122D80
    .word pokemenu_opts

.org 0x08122208
    .word field_move_descriptions