
.org 0x08043ED4
ldr r0, =battle_get_song | 1
bx r0
.pool

//@Always enable stereo as desired sound
.org 0x080ECA76
    mov r0, #0x1
.org 0x08088C82
    mov r0, #0x1

.org 0x08055DAC
    ldr r0, =map_get_song | 1
    bx r0
    .pool

//Ipatix sound stuff
.org 0x080007C4
    .word  0x0203E000   // new PCM work area

.org 0x081E134C
    .word  main_mixer   // new mixer ROM location
    .word  0x03005E40   // new mixer RAM location (used for loading)
    .halfword mixer_size
    .halfword 0x400        // CpuSet, copy code by 32 bit units
    .word  0x0203E000   // new PCM work area

.org 0x081E1360
    // set correct sound driver operation mode
    // 12 channels at 13379 Hz samplerate
    .byte  0x00, 0xCC, 0x94, 0x00

.org 0x081E032C
    .word  0x03005E40+1 // new mixer RAM location (used for branch)

// Midi trace repoint (enable up to 14 traces at once)
.org 0x084A18C4
    .word 0x03002BB0
    .word 14 // Num traces
