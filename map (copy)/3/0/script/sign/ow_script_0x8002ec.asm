.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8002ec
ow_script_0x8002ec:
loadpointer 0x0 str_0x80062f
callstd MSG_SIGN
end

.global str_0x80062f

str_0x80062f:
    .string "Amonia - Das Dorf der Ruhe."
        
        