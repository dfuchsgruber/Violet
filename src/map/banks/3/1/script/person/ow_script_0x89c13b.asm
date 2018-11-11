.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x89c13b
ow_script_0x89c13b:
loadpointer 0x0 str_0x8a2b06
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a2b06

str_0x8a2b06:
    .string "Es heißt, die Kampf-Angriffe von\nManus\' Pokémon könnten Felsen\lzertrümmern. Ob das wohl wahr ist?"
        
        
.elseif LANG_EN

.endif
