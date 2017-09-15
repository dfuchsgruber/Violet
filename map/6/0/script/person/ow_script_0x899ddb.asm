.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899ddb
ow_script_0x899ddb:
lock
faceplayer
checkflag 0x90a
gotoif EQUAL ow_script_0x899e4b
loadpointer 0x0 str_0x89a9bb
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x89a97b
special 0x9f
waitstate
lock
faceplayer
copyvar 0x800a 0x8004
special2 0x800d 0x84
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x89a97b
special2 0x8005 0xba
setvar 0x8004 0x5e
comparevars 0x8005 0x8004
gotoif EQUAL ow_script_0x87f879
goto ow_script_0x89a97b


.global ow_script_0x89a97b
ow_script_0x89a97b:
loadpointer 0x0 str_0x89a986
callstd MSG
release
end


.global ow_script_0x87f879
ow_script_0x87f879:
loadpointer 0x0 str_0x89a91d
callstd MSG
bufferitem 0x0 ITEM_GENGARNIT
copyvarifnotzero 0x8000 0xec
copyvarifnotzero 0x8001 0x1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
setflag 0x90a
goto ow_script_0x899e4b


.global ow_script_0x899e4b
ow_script_0x899e4b:
loadpointer 0x0 str_0x89a88b
callstd MSG_FACE
end
