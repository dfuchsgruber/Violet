.include "overworld_script.s"

.include "std.s"

.global ow_script_0x802a96
ow_script_0x802a96:
loadpointer 0x0 str_0x80eaf8
callstd MSG_SIGN
end

.global str_0x80eaf8

str_0x80eaf8:
    .string "Ein Bücherregal. Ich fasse es\nbesser nicht an."
        
        