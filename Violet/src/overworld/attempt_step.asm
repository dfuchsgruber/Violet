.include "overworld/overworld_collisions.s"

// This hook creates an edge case for creating the "blocked" sound when a collision is happening, if the collision type is a stair
// Hook at 0x5ba06 via r0

.global npc_player_initialize_step_movement_hook

npc_player_initialize_step_movement_hook:
    sub r0, r1, #5
    cmp r0, #COLLISION_SIDEWAY_STAIRS
    beq end_func

    lsl r0, #0x18
    lsr r0, #0x18
    cmp r0, #3
    bls end_func
    ldr r0, =0x0805ba10 | 1
    bx r0

end_func:
    ldr r0, =0x0805baa4 | 1
    bx r0

