.include "overworld_script.s"

.include "std.s"

.global ow_script_0xb00881
ow_script_0xb00881:
lock
faceplayer
checkflag FRBADGE_1
gotoif EQUAL ow_script_0xb00a0f
trainerbattlecont 0x1 0x19e 0x0 str_0xb008a0 str_0xb00982 ow_script_0xb009d9


.global ow_script_0xb009d9
ow_script_0xb009d9:
loadpointer 0x0 str_0xb00b22
callstd MSG
fanfare 0x104
loadpointer 0x0 str_0xb00a3a
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0xb00a65
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM39
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
loadpointer 0x0 str_0xb00bba
callstd MSG
setflag FRBADGE_1
release
end


.global ow_script_0xb00a0f
ow_script_0xb00a0f:
loadpointer 0x0 str_0xb00a1a
callstd MSG
release
end
