.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8296e4
ow_script_0x8296e4:
compare STORY_PROGRESS 0x12
callif HIGHER ow_script_0x8296fe
loadpointer 0x0 str_0x8bf87b
callstd MSG_FACE
singlemovement 0x6 0x2
end


.global ow_script_0x8296fe
ow_script_0x8296fe:
loadpointer 0x0 str_0x8bf80e
callstd MSG_FACE
end
