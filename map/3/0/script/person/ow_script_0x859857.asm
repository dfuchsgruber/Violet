.include "overworld_script.s"

.include "std.s"

.global ow_script_0x859857
ow_script_0x859857:
sound 0x2
checksound
loadpointer 0x0 str_0x85ef91
callstd MSG_KEEPOPEN
goto ow_script_0x85fcb8


.global ow_script_0x85fcb8
ow_script_0x85fcb8:
multichoice 0x20 0x0 0x3e 0x1
end
