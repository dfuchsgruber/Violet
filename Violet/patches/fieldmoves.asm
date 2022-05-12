

.org 0x08122208
    .word field_move_descriptions

.org 0x081245F4
    ldr r1, =pokemon_party_menu_option_outdoor_move | 1
    bx r1
    .pool

.org 0x0805621C
	ldr r1, =map_type_enables_fly_or_teleport | 1
	bx r1
	.pool

// Teleport from anywhere
.org 0x080f698a
    b 0x080f69a0