.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81c5c6
ow_script_0x81c5c6:
trainerbattlestd 0x0 0x3c 0x0 str_0x8774d7 str_0x88adf9
loadpointer 0x0 str_0x88adf9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8774d7

str_0x8774d7:
    .string "Es heißt, dass es in der Wüste\ngoldene Kateen geben soll.\lOb das stimmt?"
        
        
.global str_0x88adf9

str_0x88adf9:
    .string "Vielleicht werde ich nach goldenen\nKakteen suchenDOTS"
        
        
.elseif LANG_EN

.endif
