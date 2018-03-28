.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d43a1
ow_script_0x8d43a1:
trainerbattlestd 0x0 0x27 0x0 str_0x8d441f str_0x8d43b9
loadpointer 0x0 str_0x8d43b9
callstd MSG_FACE
end

.global str_0x8d441f

str_0x8d441f:
    .string "Bist du auch gekommen, um\nVogelpokemon zu fangen?"
        
        
.global str_0x8d43b9

str_0x8d43b9:
    .string "Hier in dieser Mühle leben sehr\nviele Flug-Pokémon. Als\lVogelfänger ist das für mich sehr\lnützlich."
        
        