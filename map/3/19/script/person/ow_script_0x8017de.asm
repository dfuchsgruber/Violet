.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8017de
ow_script_0x8017de:
trainerbattlestd 0x0 0x2 0x0 str_0x804181 str_0x8041dd
loadpointer 0x0 str_0x8041dd
callstd MSG_FACE
end
