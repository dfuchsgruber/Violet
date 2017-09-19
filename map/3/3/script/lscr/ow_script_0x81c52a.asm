.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c52a
ow_script_0x81c52a:
compare STORY_PROGRESS 0x1c
callif LESS ow_script_0x81c537
end


.global ow_script_0x81c537
ow_script_0x81c537:
setmaptile 0x1d 0x1a 0x300 0x1
return
