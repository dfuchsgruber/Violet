.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8de722
ow_script_0x8de722:
loadpointer 0x0 str_0x8df230
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8df230

str_0x8df230:
    .string "Einer Legende nach ruht im\nSilvania-Wald ein Pokémon, das\ldurch die Zeit reisen kann.\pSpannend, nicht?"
        
        
.elseif LANG_EN

.endif
