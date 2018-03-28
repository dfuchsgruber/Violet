.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8de722
ow_script_0x8de722:
loadpointer 0x0 str_0x8df230
callstd MSG_FACE
end

.global str_0x8df230

str_0x8df230:
    .string "Einer Legende nach ruht im\nSilvania-Wald ein Pokémon, das\ldurch die Zeit reisen kann.\pSpannend, nicht?"
        
        