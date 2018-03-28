.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95aa88
ow_script_0x95aa88:
special 0x31
pause 0x1
showpokepic POKEMON_AERODACTYL 0x4 0x4
loadpointer 0x0 str_0x95a692
callstd MSG_SIGN
setvar 0x8004 0x8e
special 0x163
hidepokepic
end


.ifdef LANG_GER
.global str_0x95a692

str_0x95a692:
    .string "Das Skelett des fossilen Pokémons\nAerodactyl.\pEs breitet seine Schwingen mit\neiner beängstigenden Anmut aus."
        
        
.elseif LANG_EN

.endif
