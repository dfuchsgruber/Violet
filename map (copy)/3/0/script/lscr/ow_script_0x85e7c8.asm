.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89bd95
ow_script_movs_0x89bd95:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x85e7c8
ow_script_0x85e7c8:
lockall
call ow_script_0x89ba6e
loadpointer 0x0 str_0x899e90
callstd MSG
special 0x7
applymovement 0x3 ow_script_movs_0x89bd95
waitmovement 0x0
hidesprite 0x3
setflag ANOMIA_RIVAL_OUTSIDE_PLAYER_HOUSE
setvar STORY_PROGRESS 0x3
releaseall
end


.global ow_script_0x89ba6e
ow_script_0x89ba6e:
setvar 0x8000 0x1
setvar 0x8001 0x6
setvar 0x8002 0xe
special 0x6
return

.global str_0x899e90

str_0x899e90:
    .string "Na los! Wir sind sowieso schon\nviel zu spät! Beeilung!"
        
        