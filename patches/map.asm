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


//@Namespace

.org 0x80c0e64
	.word map_namespaces

.org 0x80c4f70
	.word map_namespaces


//**************TEST FOR SCRIPTS AND MAPS ! REMOVE!!! 
.org 0x081656C4
    .byte 0x5
    .word script_test

.org 0x080551B4
    .word mapfooters

.org 0x805526C
    .word mapbanks

//start position of player
.org 0x08054A20
    mov r0, #5
    str r0, [sp] //y
    mov r0, #4 //bank
    mov r1, #1 //map
    mov r3, #8 //x

//enable running shoes everywhere
.org 0x080BD584
    mov r0, #0

.org 0x080BFF50
    .word healing_places

.org 0x080BFF74
    .word healing_places

.org 0x080BFFE4
    .word healing_place_target_persons
