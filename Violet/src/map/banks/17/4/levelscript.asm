.include "overworld_script.s"
.include "levelscript_types.s"
.include "constants/overworld/step_callback.s"
.include "movements.s"

.global route_5_cave_2f_levelscripts

route_5_cave_2f_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_RESUME
    .word set_on_step_callback
    .byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
    .word lscr_on_frame_table
    .byte 0

lscr_on_frame_table:
    .hword 0x4001, 1
    .word fall_through_hole
    .hword 0

set_on_step_callback:
    setonstepcallback OVERWORLD_STEP_CALLBACK_ROUTE_5_CAVE
    end

fall_through_hole:
    lockall
	pause 20
	applymovement 0xFF, mov_set_invisible
	waitmovement 0
	sound 37
	pause 60
	warphole 17 1
	waitstate
	releaseall
	end

mov_set_invisible:
    .byte HIDE_SPRITE, STOP
