.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1b9e
ow_script_0x8e1b9e:
loadpointer 0x0 str_0x8f4254
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f4254

str_0x8f4254:
    .string "Wenn man immer weiter westwärts\nläuft, erreicht man irgendwann\leine Wüstenregion.\pNur einige Wegstunden entfernt\naber erreicht man Kaskada, die\lStadt der reinen Wasserquellen."
        
        
.elseif LANG_EN

.endif
