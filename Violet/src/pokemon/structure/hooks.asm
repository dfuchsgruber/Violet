.align 2
.thumb

.global pokemon_new_pid_hook

.thumb_func
pokemon_new_pid_hook:
bl pokemon_new_pid
mov r4, r0
ldr r0, =0x0803DA12 | 1
bx r0


.align 2
.global box_pokemon_get_attribute_pokeball_hook

.thumb_func
box_pokemon_get_attribute_pokeball_hook:
    mov r0, r5
    bl box_pokemon_get_pokeball_in_substructure
    mov r4, r0
    ldr r1, =0x0804025c | 1
    bx r1

.align 2
.global box_pokemon_get_attribute_game_hook

.thumb_func
box_pokemon_get_attribute_game_hook:
    mov r0, r5
    bl box_pokemon_get_game_in_substructure
    mov r4, r0
    ldr r1, =0x0804025c | 1
    bx r1
