.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x93c1c8
ow_script_0x93c1c8:
loadpointer 0x0 str_0x93c8b8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93c8b8

str_0x93c8b8:
    .string "Diese Zeichen werden Katakana-\nZeichen genannt.\lIm Gegensatz zu den Hiragana-\lZeichen sind diese eckiger."
        
        
.elseif LANG_EN

.endif
