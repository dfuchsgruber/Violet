

.org 0x080805A4
ldr r1, =get_encounter_music_by_trainer_id | 1
bl do_r1
ldr r1, =0x08080617
do_r1:
bx r1
.pool

.org 0x08043ED4
ldr r0, =battle_get_music | 1
bx r0
.pool

//@Always enable stereo as desired sound
.org 0x080ECA76
    mov r0, #0x1
.org 0x08088C82
    mov r0, #0x1

.org 0x08055DAC
    ldr r0, =current_map_get_song | 1
    bx r0
    .pool