.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bb30
ow_script_0x94bb30:
lockall
fadesong MUS_0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d460
callstd MSG
fadescreen 0x1
sound 0x64
checksound
callasm cmdx2D_force_pals_to_black
addvar STORY_PROGRESS 0x1
goto ow_script_0x94c3f4


.global ow_script_0x94c3f4
ow_script_0x94c3f4:
getplayerpos 0x8008 0x8009
special2 0x800a 0x1aa
warpmuted 0x11 0x3 0x0 0x0 0x0
waitstate
end
