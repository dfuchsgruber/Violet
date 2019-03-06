.align 2
.thumb

.global npc_player_walk_tile_accessable_hook
@//0805BBD0 via r1
@//this is responsible for telling the game that it has to check the diagonal block for transition of tiles

.thumb_func:

npc_player_walk_tile_accessable_hook:
mov r1, r10
str r1, [sp] @direction as 5th param
mov r1, r5
mov r2, r4
mov r3, r6
bl block_triggers_diagnoal_move
cmp r0, #0x80
bge enables
ldr r1, =0x805BBD9
bx r1


enables:
ldr r1, =0x805BC51
bx r1


.align 2
.thumb

.global npc_player_init_move_hook
@//0805B9E4 via r1
@//this is responsible for telling the game that it has to check the diagonal block for transition of tiles


npc_player_init_move_hook:
    mov r6, r0  @safe r0
    bl npc_side_stairway_init_if_possible
    cmp r0, #0
    beq std
    pop {r4-r6}
    pop {r0}
    bx r0


    std:
    mov r0, r6
    mov r1, r0
    cmp r0, #0
    beq valid
    ldr r1, =0x0805B9ED
    bx r1

    valid:
    ldr r1, =0x805BA19
    bx r1


.global npc_player_init_bike_hook
@//80BD3F4 via x1
@//this is responsible for telling the game that it has to check the diagonal block for transition of tiles

npc_player_init_bike_hook:
    lsr r0, #0x18
    mov r5, r0
    bl npc_side_stairway_init_if_possible
    cmp r0, #0
    beq std_bike
    pop {r4-r6}
    pop {r0}
    bx r0

    std_bike:
    mov r1, r5
    sub r0, r1, #1
    ldr r2, =0x80BD3FD
    bx r2
