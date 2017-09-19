.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8c8e03
ow_script_movs_0x8c8e03:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8c8db9
ow_script_0x8c8db9:
call ow_script_0x8f4d04
loadpointer 0x0 str_0x931867
callstd MSG
special 0x7
sound 0x15
applymovement 0x800f ow_script_movs_0x8c8e03
waitmovement 0x0
faceplayer
call ow_script_0x8f4d04
loadpointer 0x0 str_0x931636
callstd MSG
special 0x7
lockall
setvar 0x8004 0xe
setvar 0x8005 0x1c
setvar 0x8006 0x2a
special 0x24
waitmovement 0x0
hidesprite 0x800f
releaseall
end
