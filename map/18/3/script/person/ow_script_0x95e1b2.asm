.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e1b2
ow_script_0x95e1b2:
trainerbattlestd 0x0 0x93 0x0 str_0x95e1ca str_0x95e223
loadpointer 0x0 str_0x95e223
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e1ca

str_0x95e1ca:
    .string "Von Zeit zu Zeit fliegt ein\nbrennendes Pokémon über diese\lGegend.\pIch werde es fangen!"
        
        
.global str_0x95e223

str_0x95e223:
    .string "Wenn du ein brennendes\nFlug-Pokémon findest, sag mir\lbescheid, ja?"
        
        
.elseif LANG_EN

.endif
