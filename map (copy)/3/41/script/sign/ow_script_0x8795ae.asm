.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8795ae
ow_script_0x8795ae:
loadpointer 0x0 str_0x88bc91
callstd MSG_SIGN
end

.global str_0x88bc91

str_0x88bc91:
    .string "Westen: Route 2\nOsten: Meriana City"
        
        