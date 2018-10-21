.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x82a1a8
ow_script_0x82a1a8:
settrainerflag 0x2a
trainerbattlecont 0x1 0x2a 0x0 str_0x8bf9ef str_0x8bf9ef ow_script_0x8bf158
loadpointer 0x0 str_0x8bf9ef
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8bf9ef

str_0x8bf9ef:
    .string "Die Arbeit auf der Farm ist\nKnochenarbeit. Aber sie befreit\lden Geist und bringt einen in\lEinklang mit der Natur. Vor allem\lzu den Voltilamm habe ich eine\lenge Beziehung aufgebaut."
        
        
.elseif LANG_EN

.endif
