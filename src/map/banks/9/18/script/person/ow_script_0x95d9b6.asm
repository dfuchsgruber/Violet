.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95d9b6
ow_script_0x95d9b6:
loadpointer 0x0 str_0x95d9c0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95d9c0

str_0x95d9c0:
    .string "Die Königin der Finsternis ist die\ngrößte aller Hexen.\pIhre Magie hat hunderte\nverfluchte Seelen an ein\lmächtiges Pokémon gebunden, so die\lLegendeDOTS"
        
        
.elseif LANG_EN

.endif
