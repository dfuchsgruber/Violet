
// Flag extension
.org 0x806E53A
        ldr r0, =flag_ext | 1
        bx r0
.org 0x806E550
        .pool
    
// Var extension
.org 0x806E3C0
        ldr r0, =var_ext | 1
        bx r0
        .pool


.org 0x0806E5E4
        ldr r1, =setflag | 1
        bx r1
        .pool

.org 0x0806E60C
        ldr r1, =clearflag | 1
        bx r1
        .pool

.org 0x0806E634
        ldr r1, =checkflag | 1
        bx r1
        .pool