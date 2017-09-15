.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9270c4
ow_script_0x9270c4:
checkflag 0x249
gotoif EQUAL ow_script_0x8aaf95
lock
faceplayer
loadpointer 0x0 str_0x8abe1c
callstd MSG
copyvarifnotzero 0x8000 0x63
copyvarifnotzero 0x8001 0x1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8ab77f
callstd MSG
setflag 0x249
release
end


.global ow_script_0x8aaf95
ow_script_0x8aaf95:
loadpointer 0x0 str_0x8ab6bf
callstd MSG_FACE
end
