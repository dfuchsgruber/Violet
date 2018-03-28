.include "overworld_script.s"

.include "std.s"

.global ow_script_0x892f82
ow_script_0x892f82:
loadpointer 0x0 str_0x8a0b9e
callstd MSG_FACE
end

.global str_0x8a0b9e

str_0x8a0b9e:
    .string "Hier im hohen Gras tauchen auf\nverschiedenen Routen verschiedene\lPokémon auf. Man kann sich also\lnie sicher sein, alle Pokémon\lgesehen zu haben. Spannend, nicht?"
        
        