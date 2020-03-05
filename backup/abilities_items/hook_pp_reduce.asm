@0801E2C0
.global hook_pp_reduce

.align 2
.thumb

.thumb_func
hook_pp_reduce:
    mov r0, r6
    bl pp_reduce
    ldr r0, =0x0801E2E6 | 1
    bx r0