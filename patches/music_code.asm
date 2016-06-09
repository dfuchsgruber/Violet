

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