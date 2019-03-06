//Pal loading routines

.org 0x0807030C
    ldr r3, =_pal_load_comp | 1
    bx r3
    .pool

.org 0x08070350
    ldr r3, =_pal_copy | 1
    bx r3
    .pool
