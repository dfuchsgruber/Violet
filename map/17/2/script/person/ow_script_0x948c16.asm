.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948c16
ow_script_0x948c16:
trainerbattlestd 0x0 0x89 0x0 str_0x94bffc str_0x94c063
loadpointer 0x0 str_0x94c063
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94bffc

str_0x94bffc:
    .string "Du bist das erste Mal auf einer\nWolke unterwegs?\pDann wird es Zeit, dass du auf\neiner Wolke kämpfst!"
        
        
.global str_0x94c063

str_0x94c063:
    .string "Du hast eindeutig Talent, wenn es\num Wolkenreiten geht!"
        
        
.elseif LANG_EN

.endif
