.include "overworld_script.s"
.include "movements.s"
.include "pathfinding.s"

.global ow_script_map_3_66_trigger_0
.global ow_script_0x8a5ca9

ow_script_map_3_66_trigger_0:
lockall
goto ow_script_0x8a5ca9


ow_script_movs_0x8a5fc7:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x8ab113:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_0x8a5ca9: 
npc_move_to 2 7 11
applymovement 2 mov_fd
applymovement 0xFF faceup
waitmovement 0
call ow_script_0x8a7343
npc_move_to 2 1 4
applymovement 2 mov_fl
waitmovement 0
end

faceup:
.byte 1, 0xFE
