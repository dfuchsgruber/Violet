.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84bc8c
ow_script_0x84bc8c:
loadpointer 0x0 str_0x8601de
callstd MSG_SIGN
end

.global str_0x8601de

str_0x8601de:
    .string "Der Volcano - das Herz des Feuers"
        
        