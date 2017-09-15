.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84002b
ow_script_0x84002b:
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
sethealingplace 0x1
compare STORY_PROGRESS 0x0
gotoif EQUAL ow_script_0x84003e
end


.global ow_script_0x84003e
ow_script_0x84003e:
playsong2 0xffff
end
