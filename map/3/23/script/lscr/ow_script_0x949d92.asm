.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949d92
ow_script_0x949d92:
lockall
fadesong MUS_0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d7a4
callstd MSG
special 0x7
playsong MUS_ROUTE_3_10_AND_ROUTE_16_22 0x0
addvar STORY_PROGRESS 0x1
releaseall
end
