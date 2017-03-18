//@better battery saving idle loop by interrupt
.org 0x080008B6
    bne end_idle
    mov r3, #1
idle_loop:
    swi #2
    ldrh r1, [r2, #0x1C]
    mov r0, r3
    and r0, r1
    cmp r0, #0
    beq idle_loop
end_idle:
    pop {pc}
