.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_7_2_person_0

ow_script_map_7_2_person_0:
loadpointer 0x0 str_0x8df230
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8df230:
    .string "Einer Legende nach ruht im\nSilvania-Wald ein Pokémon, das\ldurch die Zeit reisen kann.\pSpannend, nicht?"


.elseif LANG_EN

.endif