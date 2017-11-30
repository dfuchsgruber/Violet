.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x897e33
ow_script_movs_0x897e33:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x83093d
ow_script_movs_0x83093d:
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x830940
ow_script_movs_0x830940:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x830943
ow_script_movs_0x830943:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x89472b
ow_script_0x89472b:
special 0x113
applymovement 0x7f ow_script_movs_0x897e33
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x83093d
waitmovement 0x0
loadpointer 0x0 str_0x8cae89
callstd MSG
applymovement 0x1 ow_script_movs_0x830940
applymovement 0xff ow_script_movs_0x830943
waitmovement 0x0
call ow_script_0x893aca
trainerbattlecont 0x1 0x19e 0x0 str_0x8cafb5 str_0x8cb08b ow_script_0x8947e3


.global ow_script_0x8947e3
ow_script_0x8947e3:
call ow_script_0x893aca
loadpointer 0x0 str_0x8cb101
callstd MSG
special 0x7
fanfare 0x104
loadpointer 0x0 str_0x897c8a
callstd MSG
waitfanfare
call ow_script_0x893aca
loadpointer 0x0 str_0x8cb1cc
callstd MSG
special 0x7
copyvarifnotzero 0x8000 ITEM_TM39
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
call ow_script_0x893aca
goto ow_script_0x899429


.global ow_script_0x899429
ow_script_0x899429:
loadpointer 0x0 str_0x8cb281
callstd MSG
special 0x7
setflag FRBADGE_1
setvar STORY_PROGRESS 0x14
warpmuted 0x3 0x2 0x4 0x2d 0x22
release
end


.global ow_script_0x893aca
ow_script_0x893aca:
setvar 0x8000 0x0
setvar 0x8001 0xd
setvar 0x8002 0xf
special 0x6
return
