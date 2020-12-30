.global hook_pokemon_evolution_attempt_learning_moves

.thumb
.align 4

.thumb_func
hook_pokemon_evolution_attempt_learning_moves:
    ldrb r1, [r4, #0x10] // Is-first move to learn ?
    mov r0, r9
    bl pokemon_attempt_learning_move_consider_evolution_moves
    ldr r1, = 0x080cef7c | 1
    bx r1
