.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c80d2
ow_script_0x8c80d2:
loadpointer 0x0 str_0x8c83c5
callstd MSG
end


.ifdef LANG_GER
.global str_0x8c83c5

str_0x8c83c5:
    .string "Ja, diese Lieferung sieht gut aus.\nWir Revolutionäre können derartige\lDinge immer gebrauchenDOTS"
        
        
.elseif LANG_EN

.endif
