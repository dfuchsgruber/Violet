.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8df2e1
ow_script_0x8df2e1:
trainerbattlestd 0x0 0x2d 0x0 str_0x8e101d str_0x8e1060
loadpointer 0x0 str_0x8e1060
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e101d

str_0x8e101d:
    .string "Dieser Weg führt ostwärts in eine\nWüste. Halte dich lieber fern!"
        
        
.global str_0x8e1060

str_0x8e1060:
    .string "Wüsten sind trocken und heißDOTS"
        
        
.elseif LANG_EN

.endif
