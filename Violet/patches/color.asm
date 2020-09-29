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

.org 0x0807a1f8
    ldr r3, =pal_gamma_shift | 1
    bx r3
    .pool

.org 0x080703d8
    ldr r0, =pal_proceed | 1
    bx r0 
    .pool

.org 0x080705e6
    bl 0x080703d8

.org 0x0811585c // initially this was a questlog function, but I don't keep questlog arround
    ldr r0, =pal_filters_apply | 1
    bx r0
    .pool
