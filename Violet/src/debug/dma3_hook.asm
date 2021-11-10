.global hook_dma3_copy

.align 4

.thumb
.thumb_func
hook_dma3_copy:
    mov r4, r0
    mov r0, r12
    mov r1, r8
    mov r2, r7
    bl dma3_debug
    mov r0, r4
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r1}
    bx r1


