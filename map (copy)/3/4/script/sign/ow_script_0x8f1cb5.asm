.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1cb5
ow_script_0x8f1cb5:
loadpointer 0x0 str_0x8f1cbf
callstd MSG_SIGN
end

.global str_0x8f1cbf

str_0x8f1cbf:
    .string "Ein ganz gewöhnliches Haus"
        
        