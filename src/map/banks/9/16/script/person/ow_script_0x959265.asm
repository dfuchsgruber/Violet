.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x959265
ow_script_0x959265:
trainerbattlestd 0x0 0x90 0x0 str_0x9592b0 str_0x95927d
loadpointer 0x0 str_0x95927d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9592b0

str_0x9592b0:
    .string "Ursprünglich war ich Teil von Rins\nDivision, habe mich aber dann für\lden vielverprechenden Mistral\lentschieden.\pEr wird uns Ruhm und Macht\nbescheren, bestimmt!"
        
        
.global str_0x95927d

str_0x95927d:
    .string "Hmpf...\nAber gegen Mistral hast du keine\lChance!"
        
        
.elseif LANG_EN

.endif
