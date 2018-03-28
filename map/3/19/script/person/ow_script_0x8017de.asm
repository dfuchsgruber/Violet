.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8017de
ow_script_0x8017de:
trainerbattlestd 0x0 0x2 0x0 str_0x804181 str_0x8041dd
loadpointer 0x0 str_0x8041dd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x804181

str_0x804181:
    .string "Mit einem Pokeball kannst du wilde\nPokémon fangen, sodass sie dir\lgehorchen. Toll nicht?"
        
        
.global str_0x8041dd

str_0x8041dd:
    .string "Ich habe mein Pokémon auch mit\neinem Pokeball gefangen."
        
        
.elseif LANG_EN

.endif
