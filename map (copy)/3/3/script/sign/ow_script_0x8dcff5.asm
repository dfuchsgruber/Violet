.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8dcff5
ow_script_0x8dcff5:
loadpointer 0x0 str_0x8de321
callstd MSG_SIGN
end

.global str_0x8de321

str_0x8de321:
    .string "Beerenladen"
        
        