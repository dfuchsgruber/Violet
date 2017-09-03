.include "overworld_script.s"

.include "std.s"

.global ow_script_0x83ff26
ow_script_0x83ff26:
compare STORY_PROGRESS 0x1
gotoif EQUAL ow_script_0x8400be
end


.global ow_script_0x8400be
ow_script_0x8400be:
movesprite2 0x1 0x6 0x6
spritebehave 0x1 0x7
end
