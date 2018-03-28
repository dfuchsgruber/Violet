.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a3c07
ow_script_0x8a3c07:
loadpointer 0x0 str_0x8a3c11
callstd MSG_SIGN
end

.global str_0x8a3c11

str_0x8a3c11:
    .string "Westen: Route 2"
        
        