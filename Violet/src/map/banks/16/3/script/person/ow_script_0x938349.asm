.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x938349
ow_script_0x938349:
trainerbattlestd 0x0 0x7e 0x0 str_0x93bb9e str_0x93bbf6
loadpointer 0x0 str_0x93bbf6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93bb9e

str_0x93bb9e:
    .string "Merk dir meinen Namen, Bursche!\nEines Tages werde ich die ganze\lWelt umwandert haben!"
        
        
.global str_0x93bbf6

str_0x93bbf6:
    .string "Merke dir diesen Triumph über\nmich, den Weltumwanderer!"
        
        
.elseif LANG_EN

.endif
