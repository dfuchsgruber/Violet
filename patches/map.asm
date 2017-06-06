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



//**************TEST FOR SCRIPTS AND MAPS ! REMOVE!!! 
.org 0x081656C4
    .byte 0x5
    .word script_test

.org 0x082DD3F4
    .word maptileset0
