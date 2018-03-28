.include "overworld_script.s"

.include "std.s"

.global ow_script_0x938384
ow_script_0x938384:
loadpointer 0x0 str_0x93c0e4
callstd MSG_FACE
end

.global str_0x93c0e4

str_0x93c0e4:
    .string "Manus legt großen Wert auf\nDisziplin.\lNur wer sich im griff hat, wird\lgewinnen."
        
        