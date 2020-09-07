.include "specials.s"
.include "overworld/npc_pathfinding_speeds.s"
.include "vars.s"

.macro npc_move_to person:req x:req y:req speed=A_STAR_SPEED_NORMAL waitmovement=0 ignore_collisions=0 
    .if \person == LASTTALKED
        copyvar 0x8004 LASTTALKED
    .else
        setvar 0x8004 \person
    .endif
    .if \x != 0xFFFF
        setvar 0x8005 \x
    .endif
    .if \y != 0xFFFF
        setvar 0x8006 \y
    .endif
    .if \speed != 0xFF
        setvar 0x8007 \speed
    .endif
    .if \ignore_collisions != 0xFF
        setvar 0x8008 \ignore_collisions
    .endif
    special SPECIAL_NPC_MOVE_TO
    waitstate
    .if \waitmovement != 0
        waitmovement 0
    .endif
.endm

.macro npc_move_to_player person:req speed=A_STAR_SPEED_NORMAL waitmovement=1 ignore_collisions=0
    .if \person == LASTTALKED
        copyvar 0x8004 LASTTALKED
    .else
        setvar 0x8004 \person
    .endif
    .if \speed != 0xFF
        setvar 0x8005 \speed
    .endif
    .if \ignore_collisions != 0xFF
        setvar 0x8006 \ignore_collisions
    .endif
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitstate
    .if \waitmovement != 0
        waitmovement 0
    .endif
.endm

