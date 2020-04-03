.include "vars.s"

.global lscr_0x71a510

lscr_0x71a510:
	.byte 0x3
.word ow_script_0x8012d1
	.byte 0x2
.word lscr_0x71a51b
	.byte 0x0




.align 4
.global lscr_0x71a51b

lscr_0x71a51b:
	.hword STORY_PROGRESS, 0x2
	.word ow_script_0x85e7c8
	.hword 0x0
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_0x8012d1
.global ow_script_0x85e7c8

ow_script_0x8012d1:
setworldmapflag WM_AMONIA
end


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

str_0x899e90:
    .string "Na los! Wir sind sowieso schon\nviel zu spät! Beeilung!"


.elseif LANG_EN

.endif