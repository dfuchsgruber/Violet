.include "overworld_script.s"


.global ow_script_0x9455fa
ow_script_0x9455fa:
settrainerflag 0xa7
trainerbattlestd 0x0 0xa7 0x0 str_0x94560d str_0x94560d
end


.ifdef LANG_GER
.global str_0x94560d

str_0x94560d:
    .string "a"
        
        
.elseif LANG_EN

.endif
