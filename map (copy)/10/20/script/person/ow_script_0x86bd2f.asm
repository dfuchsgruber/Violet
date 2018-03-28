.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bd2f
ow_script_0x86bd2f:
loadpointer 0x0 str_0x965b49
callstd MSG_FACE
end

.global str_0x965b49

str_0x965b49:
    .string "Feuerpokémon haben in diesem Haus\nkeinen Zutritt.\pWas soll sonst aus der\nHolzmöblierung werden?"
        
        