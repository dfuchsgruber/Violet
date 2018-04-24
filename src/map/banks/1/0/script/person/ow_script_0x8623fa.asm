.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8623fa
ow_script_0x8623fa:
loadpointer 0x0 str_0x8f2b00
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f2b00

str_0x8f2b00:
    .string "Viele sind der Meinung, es gäbe\nverschiedene Zeitlinien.\lCelebi, das Zeitpokemon, soll\ljedoch über ihnen existieren und\lsie alle kennen."
        
        
.elseif LANG_EN

.endif
