.include "overworld_script.s"

.include "std.s"



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
setvar LASTTALKED 0x6
setvar 0x8004 0x6
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8c0738
callstd MSG
special 0x7
applymovement 0x6 ow_script_movs_0x8bfd27
waitmovement 0x0
hidesprite 0x6
releaseall
setvar STORY_PROGRESS 0x12
end
