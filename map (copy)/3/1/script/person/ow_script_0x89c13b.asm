.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89c13b
ow_script_0x89c13b:
loadpointer 0x0 str_0x8a2b06
callstd MSG_FACE
end

.global str_0x8a2b06

str_0x8a2b06:
    .string "Es heißt, die Kampf-Angriffe von\nManus\ Pokémon könnten Felsen\lzertrümmern. Ob das wohl wahr ist?"
        
        