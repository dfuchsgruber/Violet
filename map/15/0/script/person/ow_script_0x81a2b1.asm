.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81a2b1
ow_script_0x81a2b1:
trainerbattlestd 0x0 0x1d 0x0 str_0x81a2c9 str_0x81a2ee
loadpointer 0x0 str_0x81a2ee
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81a2c9

str_0x81a2c9:
    .string "Angeln ist nicht das Spannendste..."
        
        
.global str_0x81a2ee

str_0x81a2ee:
    .string "Aber ich habe zu nichts anderem\nTalent."
        
        
.elseif LANG_EN

.endif
