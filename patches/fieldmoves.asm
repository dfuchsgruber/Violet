.org 0x08122A34
    ldr r3, =pokemon_party_menu_opt_build | 1
    bx r3
    .pool

.org 0x8120FA8
    .word pokemon_party_menu_opts

.org 0x8121FF0
    .word pokemon_party_menu_opts

.org 0x8122D50
    .word pokemon_party_menu_opts

.org 0x8122D80
    .word pokemon_party_menu_opts

.org 0x08122208
    .word field_move_descriptions

.org 0x081245F4
    ldr r1, =pokemon_party_menu_opt_outdoor_move | 1
    bx r1
    .pool

.org 0x0805621C
	ldr r1, =map_type_enables_fly_or_teleport | 1
	bx r1
	.pool
