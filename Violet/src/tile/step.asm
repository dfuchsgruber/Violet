.include "constants/vars.s"

.align 2
.thumb

.global on_step

.thumb_func
on_step:

bl egg_warm_update
@bl update_a_vector

ldr r0, =WONDERTRADE_STEPS_TO_ENABLE
bl var_access
ldrh r1, [r0]
cmp r1, #250
bge skip_inc
add r1, #1
strh r1, [r0]
skip_inc:

bl do_fata_morgana

bl player_step_force_on_cloud
@ cmp r0, #0
@ bne ret_1

bl player_step_on_behavior
cmp r0, #0
beq behavior_no_script_init
bl script_init
b ret_1

behavior_no_script_init:

bl pokeradar_step
cmp r0, #0
bne ret_1

@bl dungeon_crash
bl dungeon2_step_is_collapsing
cmp r0, #0
bne ret_1

end_main:

bl safari_do_step
lsl r0, #0x18
lsr r0, #0x18
ldr r1, =0x0806d68d
bx r1



ret_1:
ldr r0, =0x00806D695
bx r0

script_init:
ldr r1, =0x08069AD5
bx r1

checkflag:
ldr r1, =0x0806E635
bx r1

safari_do_step:
ldr r0, =0x080A0ff9
call_via_r0:
bx r0


var_access:
ldr r1, =0x0806E3B9
bx r1

spawn_big_cb:
ldr r2, =0x08077381
bx r2

check_detector:
ldr r2, =0x0813EEC5
bx r2

playsong:
ldr r1, =0x081E138D
bx r1

remove_big_cb:
ldr r1, =0x0807746D
bx r1



get_current_tile_position:
ldr r2, =0x0805C539
bx r2

get_tiles_attribute:
ldr r3, =0x08058f49
bx r3

