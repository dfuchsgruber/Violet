.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x948f71
ow_script_0x948f71:
trainerbattlestd 0x0 0x8b 0x0 str_0x94c37e str_0x949d71
loadpointer 0x0 str_0x949d71
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94c37e

str_0x94c37e:
    .string "Hast du schon deine Typentabelle\nauswendig gelernt?\pIch für meinen Teil kenne alle\nTypverhältnisse aus dem Stegreif!"
        
        
.global str_0x949d71

str_0x949d71:
    .string "Was? Hast du überhaupt gelernt?"
        
        
.elseif LANG_EN

.endif
