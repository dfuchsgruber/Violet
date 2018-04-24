.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x955dd9
ow_script_0x955dd9:
loadpointer 0x0 str_0x9586a8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9586a8

str_0x9586a8:
    .string "Hey, du Pimpf! Bist du uns etwa\nvon Route 2 bis hierher gefolgt?\pVerschwinde, ehe unser Anführer\nmit dir den Boden aufwischt!"
        
        
.elseif LANG_EN

.endif
