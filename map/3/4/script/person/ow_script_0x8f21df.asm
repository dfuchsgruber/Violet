.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f21df
ow_script_0x8f21df:
loadpointer 0x0 str_0x926e0c
callstd MSG
end


.ifdef LANG_GER
.global str_0x926e0c

str_0x926e0c:
    .string "Ich vermisse die alten Zeiten...\pVor den Top Vier...\pAls die Welt noch voller Abenteuer\nwar...\pJetzt bleibt mir noch das Rauschen\nder Wasserfälle...\pUnd die Erinnerungen..."
        
        
.elseif LANG_EN

.endif
