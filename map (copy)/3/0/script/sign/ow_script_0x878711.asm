.include "overworld_script.s"

.include "std.s"

.global ow_script_0x878711
ow_script_0x878711:
loadpointer 0x0 str_0x87aafc
callstd MSG_SIGN
end

.global str_0x87aafc

str_0x87aafc:
    .string "RIVALs Haus"
        
        