.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fc588
ow_script_0x8fc588:
trainerbattlestd 0x0 0x5a 0x0 str_0x8fec28 str_0x8fec89
loadpointer 0x0 str_0x8fec89
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fec28

str_0x8fec28:
    .string "Wieso sollte man seine Pokémon\ntrainieren, wenn man sie einfach\landeren Trainern stehlen kann?"
        
        
.global str_0x8fec89

str_0x8fec89:
    .string "Hätte ich meine Pokémon selbst\ntrainiert, wäre ich vielleicht in\lder Lage gewesen, dich zu\lbesiegen!"
        
        
.elseif LANG_EN

.endif
