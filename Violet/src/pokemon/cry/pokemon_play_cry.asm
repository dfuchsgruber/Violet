.global pokemon_play_cry_hook

.align 4
.thumb

.thumb_func
pokemon_play_cry_hook:
    add r0, r7, #1
    lsl r0, #0x10
    lsr r0, #0x10
    mov r1, #0xC
    mul r0, r1     @species * 0xC
    mov r1, r9
    cmp r1, #0
    bne load_backward
    ldr r1, =pokemon_cries_forward
    b table_loaded
    load_backward:
    ldr r1, =pokemon_cries_backward
    table_loaded:
    ldr r2, =0x80720E1
    bx r2

