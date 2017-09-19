.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8f5c79
ow_script_movs_0x8f5c79:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x87f942
ow_script_0x87f942:
lock
faceplayer
loadpointer 0x0 str_0x8f6003
callstd MSG
sound 0x15
applymovement 0x800f ow_script_movs_0x8f5c79
waitmovement 0x0
loadpointer 0x0 str_0x8f5bee
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
lock
faceplayer
loadpointer 0x0 str_0x8f5bc3
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end
