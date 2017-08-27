.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89a12b
ow_script_0x89a12b:
special 0x187
compare LASTRESULT 0x2
callif EQUAL ow_script_0x89a168
lockall
setvar 0x8004 0x20
special 0x17d
setvar 0x8004 0x1
special 0xd6
sound 0x4
loadpointer 0x0 str_0x1a8124
callstd MSG_KEEPOPEN
special 0xf9
waitstate
special 0x120
releaseall
end


.global ow_script_0x89a168
ow_script_0x89a168:
clearflag TRANS_DISABLE
release
end
