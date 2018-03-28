.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8644e6
ow_script_0x8644e6:
trainerbattlestd 0x0 0xa7 0x0 str_0x96612f str_0x9661bb
loadpointer 0x0 str_0x9661bb
callstd MSG_FACE
end

.global str_0x96612f

str_0x96612f:
    .string "Ich habe gehört, dass hier ein\nmächtiges Pokémon schläft.\pWenn wir unsere Mission erfüllt\nhaben, werde ich es mir unter den\lNagel reißen!"
        
        
.global str_0x9661bb

str_0x9661bb:
    .string "Hey! Finger weg von dem legendären\nPokémon!"
        
        