.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95538f
ow_script_0x95538f:
loadpointer 0x0 str_0x9553f8
callstd MSG_SIGN
end

.global str_0x9553f8

str_0x9553f8:
    .string "Orina City Museum"
        
        