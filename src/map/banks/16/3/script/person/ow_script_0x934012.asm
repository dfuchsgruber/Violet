.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x934012
ow_script_0x934012:
trainerbattlestd 0x0 0x79 0x0 str_0x936e16 str_0x936e78
loadpointer 0x0 str_0x936e78
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x936e16

str_0x936e16:
    .string "Die Arena von Meriana City ist\neine Pilgerstätte für Kämpfer.\lIch bin auf direktem Weg dorthin!"
        
        
.global str_0x936e78

str_0x936e78:
    .string "Was? Wie konnte ich gegen einen\nNicht-Kämpfer verlieren?"
        
        
.elseif LANG_EN

.endif
