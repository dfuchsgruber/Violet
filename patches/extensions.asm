
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