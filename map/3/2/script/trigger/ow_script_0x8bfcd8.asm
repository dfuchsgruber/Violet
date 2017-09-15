.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8c09cf
ow_script_movs_0x8c09cf:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8bfd27
ow_script_movs_0x8bfd27:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8bfcd8
ow_script_0x8bfcd8:
lockall
clearflag PKMNMENU
showsprite 0x6
getplayerpos 0x8000 0x8001
compare 0x8001 0x17
callif EQUAL ow_script_0x8bfd82
compare 0x8001 0x15
callif EQUAL ow_script_0x8bfdda
applymovement 0x6 ow_script_movs_0x8c09cf
waitmovement 0x0
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8c0738
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x8bfd27
waitmovement 0x0
hidesprite 0x6
goto ow_script_0x8fb3f8


.global ow_script_0x8fb3f8
ow_script_0x8fb3f8:
setvar STORY_PROGRESS 0x12
end


.global ow_script_0x8bfdda
ow_script_0x8bfdda:
singlemovement 0x6 0x11
waitmovement 0x0
return


.global ow_script_0x8bfd82
ow_script_0x8bfd82:
singlemovement 0x6 0x10
waitmovement 0x0
return
