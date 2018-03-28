.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c1269
ow_script_0x8c1269:
loadpointer 0x0 str_0x8cee15
callstd MSG_SIGN
end

.global str_0x8cee15

str_0x8cee15:
    .string "Aktania - die Stadt des ewigen\nSonnenscheins\p...\p...\pDer Text ist durchgestrichen..."
        
        