.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a875c
ow_script_0x8a875c:
trainerbattlestd 0x0 0xd 0x0 str_0x8a9ce9 str_0x8a9d56
loadpointer 0x0 str_0x8a9d56
callstd MSG_FACE
end

.global str_0x8a9ce9

str_0x8a9ce9:
    .string "Ich bin eine Grazie. Meine\nSchönheit kann blenden. Sieh mich\lan und lass mich dein Herz\lergreifen!"
        
        
.global str_0x8a9d56

str_0x8a9d56:
    .string "Du kannst meiner Schönheit\nwiderstehen?"
        
        