.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f21df
ow_script_0x8f21df:
loadpointer 0x0 str_0x926e0c
callstd MSG
end


.ifdef LANG_GER
.global str_0x926e0c

str_0x926e0c:
    .string "Ich vermisse die alten ZeitenDOTS\pVor den Top VierDOTS\pAls die Welt noch voller Abenteuer\nwarDOTS\pJetzt bleibt mir noch das Rauschen\nder WasserfälleDOTS\pUnd die ErinnerungenDOTS"
        
        
.elseif LANG_EN

.endif
