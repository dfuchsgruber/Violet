.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fe4ff
ow_script_0x8fe4ff:
loadpointer 0x0 str_0x8ffff2
callstd MSG_SIGN
end

.global str_0x8ffff2

str_0x8ffff2:
    .string "Küstenberg"
        
        