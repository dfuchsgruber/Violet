.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


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
loadpointer 0x0 str_0x899e90
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x3 ow_script_movs_0x89bd95
waitmovement 0x0
hidesprite 0x3
setflag ANOMIA_RIVAL_OUTSIDE_PLAYER_HOUSE
setvar STORY_PROGRESS 0x3
releaseall
end


.ifdef LANG_GER
.global str_0x899e90

str_0x899e90:
    .string "Na los! Wir sind sowieso schon\nviel zu spät! Beeilung!"
        
        
.elseif LANG_EN

.endif
