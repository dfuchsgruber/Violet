.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f6149
ow_script_0x8f6149:
compare STORY_PROGRESS 0x1c
callif LESS ow_script_0x8f63f6
loadpointer 0x0 str_0x8f615e
callstd MSG_SIGN
end


.global ow_script_0x8f63f6
ow_script_0x8f63f6:
loadpointer 0x0 str_0x8f6400
callstd MSG_SIGN
end
