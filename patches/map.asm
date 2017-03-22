.org 0x08069C8C
    ldr r0, =map_init_levelscript_4 | 1
    bx r0
    .pool

//@disable prescreens
.org 0x80F8378
    mov r0, #0x1C
    bx lr

//@dns at whiteout
.org 0x080566C4
    ldr r0, =whiteout_hook | 1
    bx r0
    .pool

//@remove previously on quest
.org 0x08111002
    mov r0, #0 //0 events to be loaded


//test map2agb 3.0 map
.org 0x8352218
    .word mapheader_03_00

.org 0x0834EBE4
    .word mapfooter_03_00
