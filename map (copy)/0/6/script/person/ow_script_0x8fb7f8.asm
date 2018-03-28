.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb7f8
ow_script_0x8fb7f8:
trainerbattlestd 0x0 0x55 0x0 str_0x8feb10 str_0x8feb72
loadpointer 0x0 str_0x8feb72
callstd MSG_FACE
end

.global str_0x8feb10

str_0x8feb10:
    .string "Meine Pflanzen-Pokémon können sich\nmit der Trockenheit einer Wüste\lnicht wirklich anfreunden..."
        
        
.global str_0x8feb72

str_0x8feb72:
    .string "Vielleicht sollte ich einfach hier\nunten bleiben, wo es schön kühl\lund feucht ist."
        
        