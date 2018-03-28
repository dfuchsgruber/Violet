.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93c1c8
ow_script_0x93c1c8:
loadpointer 0x0 str_0x93c8b8
callstd MSG_FACE
end

.global str_0x93c8b8

str_0x93c8b8:
    .string "Diese Zeichen werden Katakana-\nZeichen genannt.\lIm Gegensatz zu den Hiragana-\lZeichen sind diese eckiger."
        
        