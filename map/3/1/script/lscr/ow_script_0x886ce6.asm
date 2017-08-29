.include "overworld_script.s"

.include "std.s"

.global ow_script_0x886ce6
ow_script_0x886ce6:
goto ow_script_0x88abb8


.global ow_script_movs_0x8a136f
ow_script_movs_0x8a136f:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a133b
ow_script_movs_0x8a133b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888e47
ow_script_movs_0x888e47:
.byte 0x0
.byte STOP


.global ow_script_movs_0x8a13a1
ow_script_movs_0x8a13a1:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x88abb8
ow_script_0x88abb8:
lockall
loadpointer 0x0 str_0x886d49
callstd MSG
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
applymovement 0x2 ow_script_movs_0x8a136f
applymovement 0xff ow_script_movs_0x8a133b
waitmovement 0x0
loadpointer 0x0 str_0x888a45
callstd MSG
applymovement 0x2 ow_script_movs_0x888e47
waitmovement 0x0
fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
loadpointer 0x0 str_0x888cd2
callstd MSG
applymovement 0x2 ow_script_movs_0x8a13a1
waitmovement 0x0
hidesprite 0x2
setvar STORY_PROGRESS 0xb
releaseall
end
