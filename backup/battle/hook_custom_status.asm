.global hook_clear_temporary_effects

.align 2
.thumb

.thumb_func
hook_clear_temporary_effects:
    mov r0, r9
    bl battle_clear_temporary_custom_effects
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0
