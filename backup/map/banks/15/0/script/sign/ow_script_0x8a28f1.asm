.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a28f1
ow_script_0x8a28f1:
loadpointer 0x0 str_0x8f7189
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8f7189

str_0x8f7189:
    .string "Pokemonzucht an der alten Mühle\pBetreiber: Nick und Rick"
        
        
.elseif LANG_EN

.endif
