//Pal loading routines

.org 0x0807030C
    ldr r3, =_pal_load_comp | 1
    bx r3
    .pool

.org 0x08070350
    ldr r3, =_pal_copy | 1
    bx r3
    .pool

// Dynamically determine the gamma type 
.org 0x0807a38c
    ldr r1, [0x0807a3bc]
    mov r0, r4 // Pal idx
    bl blxr1 // Should call palette_get_gamma_type
.org 0x0807a3bc
    .word palette_get_gamma_type | 1 // target for ldr r0, = ... at 0x0x0807a38c


.org 0x0807a232
    ldr r1, [0x0807a264]
    mov r0, r4 // Pal idx
    bl blxr1 // Should call palette_get_gamma_type
.org 0x0807a264
    .word palette_get_gamma_type | 1 // target for ldr r0, = ... at 0x0807a232

.org 0x0807a4a8
    ldr r1, [0x0807a4d0]
    mov r0, r4 // Pal idx
    bl blxr1 // Should call palette_get_gamma_type
.org 0x0807a4d0
    .word palette_get_gamma_type | 1 // target for ldr r0, = ... at 0x0807a4a8
