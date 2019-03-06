.global pokemon_hatch_decrement_hook

.align 2
.thumb

.thumb_func
pokemon_hatch_decrement_hook:
    mov r0, r4
    bl pokemon_hatch_decrement
    ldr r0, = 0x80462A2 | 1
    bx r0
