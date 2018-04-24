.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x914bf0
ow_script_0x914bf0:
trainerbattlestd 0x0 0x70 0x0 str_0x92d16d str_0x92dd6f
loadpointer 0x0 str_0x92dd6f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x92d16d

str_0x92d16d:
    .string "Was ist eine schönere Szenerie für\neinen Kampf als eine Klippe am\lMeer?"
        
        
.global str_0x92dd6f

str_0x92dd6f:
    .string "Es wäre hilfreich gewesen, weniger\nder Landschaft die Aufmerksamkeit\lzu schenken und mehr dem Kampf..."
        
        
.elseif LANG_EN

.endif
