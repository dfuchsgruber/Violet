.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x830eef
ow_script_movs_0x830eef:
.byte LOOK_UP
.byte FACE_DOWN
.byte LOOK_LEFT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x830eb6
ow_script_0x830eb6:
lock
faceplayer
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x830ee4
loadpointer 0x0 str_0x8f078d
callstd MSG
applymovement 0x3 ow_script_movs_0x830eef
waitmovement 0x0
hidesprite 0x3
warp 0x7 0xa 0x0 0x14 0xf
release
end


.global ow_script_0x830ee4
ow_script_0x830ee4:
loadpointer 0x0 str_0x8f08c4
callstd MSG
release
end
