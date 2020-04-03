.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_map_3_19_trigger_1
.global ow_script_map_3_19_trigger_0
.global ow_script_0x8f6de3

ow_script_movs_0x89bf97:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x89bf9b:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


ow_script_map_3_19_trigger_0:
lockall
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
pause 0x20
sound 0x15
applymovement 0x6 ow_script_movs_0x89bf97
waitmovement 0x0
loadpointer 0x0 str_0x89bf76
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x6 ow_script_movs_0x89bf9b
waitmovement 0x0
fadesong MUS_ROUTE_1_AND_TUNNELPFAD
hidesprite 0x6
goto ow_script_0x8f6de3


ow_script_0x8f6de3:
setflag ROUTE_1_RIVAL
setvar STORY_PROGRESS 0x4
end


.ifdef LANG_GER

str_0x89bf76:
    .string "Wo bleibst du denn?!\nBeeilung!"


.elseif LANG_EN

.endif


ow_script_movs_0x8a09c6:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a09c9:
.byte STEP_LEFT
.byte STOP


ow_script_map_3_19_trigger_1:
lockall
sound 0x15
applymovement 0xff ow_script_movs_0x8a09c6
waitmovement 0x0
loadpointer 0x0 str_0x8a0956
show_mugshot MUGSHOT_PLAYER
applymovement 0xff ow_script_movs_0x8a09c9
waitmovement 0x0
end


.ifdef LANG_GER

str_0x8a0956:
    .string "Die Trainerschule liegt westlich\nvon Route 1. Ich sollte mich\lbeeilen, sonst verpasse ich noch\ldie Prüfungen!"


.elseif LANG_EN

.endif