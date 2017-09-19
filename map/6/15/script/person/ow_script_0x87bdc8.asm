.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87bdc8
ow_script_0x87bdc8:
lock
faceplayer
checkflag AKTANIA_GEODUDE_DONE
gotoif EQUAL ow_script_0x87c2db
checkflag AKTANIA_GEODUDE_ACCEPTED
gotoif EQUAL ow_script_0x87c2b9
loadpointer 0x0 str_0x87c7c7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87c774
loadpointer 0x0 str_0x87c738
callstd MSG_FACE
setflag AKTANIA_GEODUDE_ACCEPTED
release
end


.global ow_script_0x87c774
ow_script_0x87c774:
loadpointer 0x0 str_0x87c77f
callstd MSG_FACE
release
end


.global ow_script_0x87c2b9
ow_script_0x87c2b9:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x87c2cd
loadpointer 0x0 str_0x87c738
callstd MSG_FACE
release
end


.global ow_script_0x87c2cd
ow_script_0x87c2cd:
loadpointer 0x0 str_0x87c5fa
callstd MSG_FACE
setflag AKTANIA_GEODUDE_DONE
release
end


.global ow_script_0x87c2db
ow_script_0x87c2db:
loadpointer 0x0 str_0x87c492
callstd MSG_FACE
release
end
